#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int QUESTIONS_COUNT = 5;

void itogi(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    cout << "\n--- Results ---" << endl;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string name;
        ss >> name;
        
        string item;
        int total = 0;
        int correct = 0;
        
        while (ss >> item) {
            total++;
            size_t eqPos = item.find('=');
            if (eqPos != string::npos) {
                string question = item.substr(0, eqPos);
                string answerStr = item.substr(eqPos + 1);
                
                size_t xPos = question.find('x');
                if (xPos != string::npos) {
                    int i = stoi(question.substr(0, xPos));
                    int j = stoi(question.substr(xPos + 1));
                    
                    if (stoi(answerStr) == i * j) {
                        correct++;
                    }
                }
            }
        }
        
        double percentage = 0.0;
        if (total > 0) {
            percentage = (static_cast<double>(correct) / total) * 100.0;
        }
        
        cout << "Player: " << left << setw(10) << name 
             << " Correct: " << correct << "/" << total 
             << " (" << fixed << setprecision(1) << percentage << "%)" << endl;
    }
    file.close();
}

int main() {
    srand(time(0));
    
    string filename = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\game_results.txt";
    
    int m;
    cout << "Enter number of players (m): ";
    cin >> m;
    cin.ignore();

    vector<string> names(m);
    for (int i = 0; i < m; ++i) {
        cout << "Enter name for player " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error creating file. Check if folder 14_c+h exists at " << filename << endl;
        return 1;
    }

    for (int p = 0; p < m; ++p) {
        outFile << names[p] << " ";
        cout << "\n--- Player: " << names[p] << " ---" << endl;
        
        for (int q = 0; q < QUESTIONS_COUNT; ++q) {
            int i = rand() % 20 + 1;
            int j = rand() % 20 + 1;
            
            cout << i << " x " << j << " = ? ";
            int userAnswer;
            cin >> userAnswer;
            
            outFile << i << "x" << j << "=" << userAnswer << " ";
        }
        outFile << "\n";
    }
    outFile.close();

    itogi(filename);

    return 0;
}