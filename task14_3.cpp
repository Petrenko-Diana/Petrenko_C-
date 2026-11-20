#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string inPath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task3_in.txt";
    string outPath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task3_out.txt";

    ifstream inFile(inPath);
    ofstream outFile(outPath);
    
    if (!inFile.is_open()) {
        cerr << "Error opening input file: " << inPath << endl;
        return 1;
    }

    string word;
    while (inFile >> word) {
        string cleanWord = "";
        string punct = "";
        
        for (char c : word) {
            if (isalpha(c) || isdigit(c)) {
                cleanWord += c;
            } else {
                punct += c;
            }
        }

        reverse(cleanWord.begin(), cleanWord.end());
        
        outFile << cleanWord << punct << " ";
    }

    inFile.close();
    outFile.close();

    cout << "Done. Check task3_out.txt in your folder." << endl;

    return 0;
}