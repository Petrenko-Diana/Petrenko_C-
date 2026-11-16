#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define PASSING_GRADE 60

// Визначення типу запису для студента
typedef struct {
    char surname[MAX_NAME_LEN];
    int group;
    int grade_1;
    int grade_2;
    int grade_3;
} Student;

// Функція введення масиву студентів
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("  Surname: ");
        scanf("%49s", students[i].surname);
        printf("  Group number: ");
        scanf("%d", &students[i].group);
        printf("  Grade 1 (Subject 1): ");
        scanf("%d", &students[i].grade_1);
        printf("  Grade 2 (Subject 2): ");
        scanf("%d", &students[i].grade_2);
        printf("  Grade 3 (Subject 3): ");
        scanf("%d", &students[i].grade_3);
    }
}

// а) Пошук студентів, що мають заборгованості принаймні з одного з предметів
void findStudentsWithDebts(const Student students[], int n) {
    printf("\na) Students with academic debts (grades < %d):\n", PASSING_GRADE);
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        if (students[i].grade_1 < PASSING_GRADE || 
            students[i].grade_2 < PASSING_GRADE || 
            students[i].grade_3 < PASSING_GRADE) {
            
            printf("Student: %s | Group: %d | Grades: [%d, %d, %d]\n",
                   students[i].surname,
                   students[i].group,
                   students[i].grade_1,
                   students[i].grade_2,
                   students[i].grade_3);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No students with debts found.\n");
    }
}

// б) Bизначення предмета, складеного найгірше
void findWorstSubject(const Student students[], int n) {
    printf("\nb) Subject passed the worst\n");
    if (n <= 0) return;

    double sum_1 = 0, sum_2 = 0, sum_3 = 0;

    for (int i = 0; i < n; i++) {
        sum_1 += students[i].grade_1;
        sum_2 += students[i].grade_2;
        sum_3 += students[i].grade_3;
    }

    double avg_1 = sum_1 / n;
    double avg_2 = sum_2 / n;
    double avg_3 = sum_3 / n;

    printf("Average grades:\n");
    printf("  Subject 1: %.2f\n", avg_1);
    printf("  Subject 2: %.2f\n", avg_2);
    printf("  Subject 3: %.2f\n", avg_3);

    // Знаходимо мінімальне середнє значення
    double min_avg = avg_1;
    int worst_subject = 1;

    if (avg_2 < min_avg) {
        min_avg = avg_2;
        worst_subject = 2;
    }
    if (avg_3 < min_avg) {
        min_avg = avg_3;
        worst_subject = 3;
    }

    // Перевірка на випадок, якщо кілька предметів мають однакову найгіршу середню оцінку
    printf("Worst passed subject(s):\n");
    if (avg_1 == min_avg) printf("  -> Subject 1 (average: %.2f)\n", avg_1);
    if (avg_2 == min_avg) printf("  -> Subject 2 (average: %.2f)\n", avg_2);
    if (avg_3 == min_avg) printf("  -> Subject 3 (average: %.2f)\n", avg_3);
}

int main(void) {
    int n;
    printf("Enter number of students (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    inputStudents(students, n);
    findStudentsWithDebts(students, n);
    findWorstSubject(students, n);

    free(students);

    return 0;
}