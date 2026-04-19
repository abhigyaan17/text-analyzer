#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class TextAnalyzer {
private:
    unordered_map<string, int> freq;

    string normalize(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        return word;
    }

public:
    void processFile(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file\n";
            return;
        }

        string line, word;
        while (getline(file, line)) {
            istringstream iss(line);
            while (iss >> word) {
                word = normalize(word);
                if (!word.empty())
                    freq[word]++;
            }
        }
        file.close();
    }

    void totalWords() {
        int total = 0;
        for (auto &p : freq)
            total += p.second;
        cout << "Total Words: " << total << endl;
    }

    void wordFrequency() {
        cout << "\nWord Frequencies:\n";
        for (auto &p : freq)cout << p.first << " : " << p.second << endl;
    }

    void mostFrequent() {
        string word;
        int maxFreq = 0;

        for (auto &p : freq) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                word = p.first;
            }
        }
        cout << "\nMost Frequent Word: " << word << " (" << maxFreq << ")\n";
    }

    void uniqueWords() {
        int count = 0;
        for (auto &p : freq)
            if (p.second == 1)
                count++;
        cout << "Unique Words: " << count << endl;
    }

    void removeDuplicates(const string &inputFile, const string &outputFile) {
        ifstream file(inputFile);
        ofstream out(outputFile);
        if (!file.is_open() || !out.is_open()) {
            cout << "Error opening files\n";
            return;
        }
        unordered_map<string, bool> used;
        string line, word;
        
        while (getline(file, line)) {
            istringstream iss(line);
                while (iss >> word) {
                    string clean = normalize(word);
                    if (!clean.empty() && !used[clean]) {
                        out << clean << " ";
                        used[clean] = true;
                    }
                }
            out << endl;
        }
        file.close();
        out.close();
        cout << "Cleaned file written to: " << outputFile << endl;
    }
};

int main() {
    TextAnalyzer obj;

    string input = "../data/sample.txt";
    string output = "../output/cleaned.txt";

    obj.processFile(input);
    obj.totalWords();
    obj.wordFrequency();
    obj.mostFrequent();
    obj.uniqueWords();
    obj.removeDuplicates(input, output);

    return 0;
}