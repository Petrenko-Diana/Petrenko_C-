#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string inPath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task2_in.txt";
    string outPath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task2_out.txt";

    ifstream inFile(inPath);
    ofstream outFile(outPath);
    
    if (!inFile.is_open()) {
        cerr << "Error opening input file: " << inPath << endl;
        return 1;
    }

    string word;
    bool capitalizeNext = false;

    while (inFile >> word) {
        if (capitalizeNext && !word.empty()) {
            word[0] = toupper(word[0]);
            capitalizeNext = false;
        }

        outFile << word << " ";

        string lowerWord = word;
        for (char& c : lowerWord) c = tolower(c);
        
        if (lowerWord == "die" || lowerWord == "der" || lowerWord == "das") {
            capitalizeNext = true;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Done. Check task2_out.txt in your folder." << endl;

    return 0;
}