#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filePath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task4.txt";
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    int balance = 0;
    bool isCorrect = true;
    
    size_t pos = 0;
    while ((pos = content.find('<', pos)) != string::npos) {
        if (content.compare(pos, 4, "<td>") == 0) {
            balance++;
            pos += 4;
        } else if (content.compare(pos, 5, "</td>") == 0) {
            balance--;
            if (balance < 0) {
                isCorrect = false;
                break;
            }
            pos += 5;
        } else {
            pos++;
        }
    }

    if (balance != 0) isCorrect = false;

    if (isCorrect) {
        cout << "Tags are correct." << endl;
    } else {
        cout << "Tags are incorrect." << endl;
    }

    return 0;
}