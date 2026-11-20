#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TPair {
    unsigned key;
    char data[10];
};

void create_files(const char* sorted_filename, const char* unsorted_filename) {
    int i;
    struct TPair arr[10];
    struct TPair unsorted_arr[10];
    struct TPair temp;
    FILE* f;

    for (i = 0; i < 10; i++) {
        arr[i].key = (i + 1) * 10;
        sprintf(arr[i].data, "Data%d", i + 1);
    }

    f = fopen(sorted_filename, "wb");
    if (f) {
        fwrite(arr, sizeof(struct TPair), 10, f);
        fclose(f);
    }

    for (i = 0; i < 10; i++) {
        unsorted_arr[i] = arr[i];
    }

    temp = unsorted_arr[1];
    unsorted_arr[1] = unsorted_arr[5];
    unsorted_arr[5] = temp;

    temp = unsorted_arr[2];
    unsorted_arr[2] = unsorted_arr[8];
    unsorted_arr[8] = temp;

    f = fopen(unsorted_filename, "wb");
    if (f) {
        fwrite(unsorted_arr, sizeof(struct TPair), 10, f);
        fclose(f);
    }
}

long search_sorted(const char* filename, unsigned target_key) {
    FILE* f = fopen(filename, "rb");
    long left = 0, right, mid, num_records;
    struct TPair temp;

    if (!f) return -1;

    fseek(f, 0, SEEK_END);
    num_records = ftell(f) / sizeof(struct TPair);
    right = num_records - 1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        fseek(f, mid * sizeof(struct TPair), SEEK_SET);
        fread(&temp, sizeof(struct TPair), 1, f);

        if (temp.key == target_key) {
            fclose(f);
            return mid;
        }
        if (temp.key < target_key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    fclose(f);
    return -1;
}

long search_unsorted(const char* filename, unsigned target_key) {
    FILE* f = fopen(filename, "rb");
    struct TPair temp;
    long index = 0;

    if (!f) return -1;

    while (fread(&temp, sizeof(struct TPair), 1, f) == 1) {
        if (temp.key == target_key) {
            fclose(f);
            return index;
        }
        index++;
    }

    fclose(f);
    return -1;
}

void remove_from_sorted(const char* filename, unsigned target_key) {
    long pos = search_sorted(filename, target_key);
    FILE* in;
    FILE* out;
    struct TPair temp;
    long current_index = 0;

    if (pos == -1) {
        printf("Record with key %u not found.\n", target_key);
        return;
    }

    in = fopen(filename, "rb");
    out = fopen("temp.bin", "wb");

    if (in && out) {
        while (fread(&temp, sizeof(struct TPair), 1, in) == 1) {
            if (current_index != pos) {
                fwrite(&temp, sizeof(struct TPair), 1, out);
            }
            current_index++;
        }
        fclose(in);
        fclose(out);
        remove(filename);
        rename("temp.bin", filename);
        printf("Record removed from sorted file successfully.\n");
    }
}

void remove_from_unsorted(const char* filename, unsigned target_key) {
    long pos = search_unsorted(filename, target_key);
    FILE* in;
    FILE* out;
    struct TPair temp;
    long current_index = 0;

    if (pos == -1) {
        printf("Record with key %u not found.\n", target_key);
        return;
    }

    in = fopen(filename, "rb");
    out = fopen("temp.bin", "wb");

    if (in && out) {
        while (fread(&temp, sizeof(struct TPair), 1, in) == 1) {
            if (current_index != pos) {
                fwrite(&temp, sizeof(struct TPair), 1, out);
            }
            current_index++;
        }
        fclose(in);
        fclose(out);
        remove(filename);
        rename("temp.bin", filename);
        printf("Record removed from unsorted file successfully.\n");
    }
}

void print_record(const struct TPair* p) {
    printf("Key: %u, Data: %s\n", p->key, p->data);
}

int main() {
    const char* sorted_file = "sorted.dat";
    const char* unsorted_file = "unsorted.dat";
    FILE* f;
    struct TPair t;

    create_files(sorted_file, unsorted_file);

    printf("--- Testing Search ---\n");
    printf("Searching for key 40:\n");
    printf("In sorted file: index %ld\n", search_sorted(sorted_file, 40));
    printf("In unsorted file: index %ld\n", search_unsorted(unsorted_file, 40));

    printf("Searching for key 99:\n");
    printf("Sorted: %ld\n", search_sorted(sorted_file, 99));
    printf("Unsorted: %ld\n", search_unsorted(unsorted_file, 99));

    printf("\n--- Testing Delete ---\n");
    remove_from_sorted(sorted_file, 20);
    remove_from_unsorted(unsorted_file, 40);

    printf("\n--- Content of Sorted File ---\n");
    f = fopen(sorted_file, "rb");
    if (f) {
        while (fread(&t, sizeof(struct TPair), 1, f) == 1) {
            print_record(&t);
        }
        fclose(f);
    }

    printf("\n--- Content of Unsorted File ---\n");
    f = fopen(unsorted_file, "rb");
    if (f) {
        while (fread(&t, sizeof(struct TPair), 1, f) == 1) {
            print_record(&t);
        }
        fclose(f);
    }

    return 0;
}