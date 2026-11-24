#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <string>

// Перевіряємо, чи файл успішно відкрився
bool check_file(const std::ofstream& f, const std::string& name) {
    if (!f.is_open()) {
        std::cerr << "Error: cannot open " << name << " for writing.\n";
        return false;
    }
    return true;
}

int main() {
    // Нам потрібно використати std::ios::binary бо ми хочемо зьерегти все без змін. Без цього, 
    // у звичайному текстовому режимі деякі символи видозмінилися б, що зіпсувало б дані
    std::ifstream in("input.txt", std::ios::binary);
    
    // Якщо файлу немаєто він не відкриється, тому робимо булеву перевірку 
    if (!in.is_open()) {
        std::cerr << "Error: cannot open input.txt\n";
        return 1;
    }

    std::vector<uint8_t> payload;
    char ch; 
    //На відміну від оператора >>, метод get() не пропускає пробіли .
    while (in.get(ch)) {
        payload.push_back(static_cast<uint8_t>(ch));
        if (payload.size() > 1048576) { // 1 MiB
            std::cerr << "Error: input.txt is too large (max 1 MiB).\n";
            return 1;
        }
    }
    in.close(); 

    uint32_t length = static_cast<uint32_t>(payload.size());
    
    // Бінарний режим для запису
    // std::ofstream — це потік для виведення у файл, він пишить всі байти як є, без змін
 
    std::ofstream bin_out("data.bin", std::ios::binary);
    if (!check_file(bin_out, "data.bin")) return 1; //якщо файл не створився видає помилку

    // Метод write() призначений для бінарного запису, він приймає вказівник на дані та кількість байтів.
    bin_out.write("CSB1", 4); 
    
    // Далі потрібно записати розмір даних (length, 4 байти). 
    // Оскільки функція write() вміє працювати лише з текстом (char*), 
    // команда reinterpret_cast змушує програму тимчасово сприймати число 
    // як на набір із 4 байтів і записати їх у файл.
    bin_out.write(reinterpret_cast<const char*>(&length), sizeof(length));

    // XOR (^) — побітова операція. 
    // Кожен біт байта інвертується, якщо відповідний біт 0x5A (число ключ) дорівнює 1
    for (uint8_t b : payload) {
        uint8_t xored = b ^ 0x5A;
        bin_out.write(reinterpret_cast<const char*>(&xored), 1);
    }
    bin_out.close();
    std::cout << "data.bin created successfully.\n";
 
    // std::ifstream + std::ios::binary. Читаємо ті байти, які записали
    std::ifstream bin_in("data.bin", std::ios::binary);
    if (!bin_in.is_open()) {
        std::cerr << "Error: cannot open data.bin for reading.\n";
        return 1;
    }

    // Метод read() читає фіксовану кількість байтів у буфер
    char magic[4];
    bin_in.read(magic, 4);
    
    // Після read() потік може перейти в стан помилки, якщо файл 
    // закінчився раніше, ніж ми прочитали потрібну кількість байтів. 
    // Оператор ! перевіряє стан потоку
    if (!bin_in || std::string(magic, 4) != "CSB1") {
        std::cerr << "Error: invalid magic header.\n";
        return 1;
    }

    uint32_t read_length = 0;
    bin_in.read(reinterpret_cast<char*>(&read_length), sizeof(read_length));
    if (!bin_in) {
        std::cerr << "Error: cannot read length.\n";
        return 1;
    }
    
    if (read_length != payload.size()) {
        std::cerr << "Error: length mismatch (expected " << payload.size() 
                  << ", got " << read_length << ").\n";
        return 1;
    }

    // Читаємо payload та декодуємо
    std::vector<uint8_t> decoded_payload;
    for (uint32_t i = 0; i < read_length; ++i) {
        uint8_t b;
        // Перевіряємо результат кожного read(). 
        // Якщо read() повертає 1, це означає, що 
        // файл закінчився або сталася помилка читання.
        if (!bin_in.read(reinterpret_cast<char*>(&b), 1)) {
            std::cerr << "Error: incomplete payload.\n";
            return 1;
        }
        decoded_payload.push_back(b ^ 0x5A); // XOR працює в обидві сторони
    }

    // Перевіряємо на зайві дані. 
    // Ми прочитали рівно стільки байтів, скільки вказано в довжині. 
    // Але у файлі можуть бути ще байтиБ тому робимо спробу прочитати ще один байт. 
    // Якщо це вдається, то файл пошкоджений.
    char extra;
    if (bin_in.read(&extra, 1)) {
        std::cerr << "Error: extra data found at the end of the file.\n";
        return 1;
    }
    bin_in.close();
 
    // Використовуємо std::ofstream з std::ios::binary, щоб записати 
    // байти в текстовий файл, без зміни переносів рядків.
    std::ofstream out("output.txt", std::ios::binary);
    if (!check_file(out, "output.txt")) return 1;

    for (uint8_t b : decoded_payload) {
        out.write(reinterpret_cast<const char*>(&b), 1);
    }
    out.close();
    std::cout << "output.txt restored successfully.\n";

    return 0;
}