//(є)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    double price;
    int min_age;
    int max_age;
} Toy;

void create_test_file(const char* filename) {
    FILE* f = fopen(filename, "wb");
    Toy t[6] = {
        {"Constructor", 500.0, 5, 10},
        {"Doll", 300.0, 3, 8},
        {"Car", 250.0, 4, 7},
        {"Puzzle", 150.0, 6, 12},
        {"Robot", 1200.0, 8, 14},
        {"Ball", 100.0, 5, 12}
    };
    
    if (f != NULL) {
        fwrite(t, sizeof(Toy), 6, f);
        fclose(f);
    }
}

void process_toys(const char* filename, double Y, int x) {
    FILE* in = fopen(filename, "rb");
    FILE* out_txt;
    FILE* out_bin;
    Toy temp;
    Toy best_toy;
    Toy missing_toy;
    int found = 0;
    double min_diff = 999999.0;

    if (in == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&temp, sizeof(Toy), 1, in) == 1) {
        if (strcmp(temp.name, "Constructor") == 0) {
            if (temp.min_age <= x && temp.max_age <= 12 && temp.price <= Y) {
                double diff = Y - temp.price;
                if (diff < min_diff) {
                    min_diff = diff;
                    best_toy = temp;
                    found = 1;
                }
            }
        }
    }
    fclose(in);

    out_txt = fopen("result.txt", "w");
    if (out_txt == NULL) {
        printf("Error creating result file!\n");
        return;
    }

    if (found) {
        printf("Found constructor:\n");
        printf("Name: %s\n", best_toy.name);
        printf("Price: %.2f UAH\n", best_toy.price);
        printf("Age: from %d to %d years\n", best_toy.min_age, best_toy.max_age);

        fprintf(out_txt, "Found constructor:\n");
        fprintf(out_txt, "Name: %s\n", best_toy.name);
        fprintf(out_txt, "Price: %.2f UAH\n", best_toy.price);
        fprintf(out_txt, "Age: from %d to %d years\n", best_toy.min_age, best_toy.max_age);
    } else {
        printf("Constructor with such parameters not found.\n");
        fprintf(out_txt, "Constructor with such parameters not found.\n");
        
        strcpy(missing_toy.name, "Constructor (missing)");
        missing_toy.price = Y;
        missing_toy.min_age = x;
        missing_toy.max_age = 12;

        out_bin = fopen(filename, "ab");
        if (out_bin != NULL) {
            fwrite(&missing_toy, sizeof(Toy), 1, out_bin);
            fclose(out_bin);
            printf("Record about absence added to the binary file.\n");
        }
    }
    fclose(out_txt);
}

int main() {
    const char* filename = "toys.bin";
    
    create_test_file(filename);
    
    printf("--- Executing task (e) ---\n");
    process_toys(filename, 600.0, 6);
    
    printf("\n--- Test (requesting missing toy) ---\n");
    process_toys(filename, 50.0, 6);

    return 0;
}