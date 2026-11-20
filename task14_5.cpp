#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Student {
    string surname;
    int course;
    string group;
    vector<int> grades;
    double average;
};

int main() {
    string filePath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task5.txt";
    ifstream inFile(filePath);

    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    vector<Student> students;
    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        Student s;
        string gradesStr;
        
        ss >> s.surname >> s.course >> s.group;
        ss >> gradesStr;

        stringstream gs(gradesStr);
        string grade;
        int sum = 0, count = 0;
        while (getline(gs, grade, ',')) {
            int g = stoi(grade);
            s.grades.push_back(g);
            sum += g;
            count++;
        }
        s.average = (count > 0) ? (double)sum / count : 0.0;
        students.push_back(s);
    }
    inFile.close();

    if (students.empty()) return 0;

    Student worst = students[0];
    for (const auto& s : students) {
        if (s.average < worst.average) {
            worst = s;
        }
    }

    cout << "Student with worst average grade: " << worst.surname << endl;
    cout << "Average grade: " << worst.average << endl;

    return 0;
}