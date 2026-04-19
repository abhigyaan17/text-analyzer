#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class textAnalyzer{
    public:
        unordered_map<string,int> mp;
        int totalWords(){
            ifstream file("../data/sample.txt");
            
            if (!file.is_open()) {
                cout << "Error opening file" << endl;
            }
            string line;
            string word;
            int count=0;
            while (getline(file, line)) {
                istringstream iss(line);
                while(iss>>word){
                    count++;
                }
            }
            file.close();
            return count;
        }
};

int main() {
    textAnalyzer obj;
    cout<<"Total Words : "<<obj.totalWords()<<endl;
    return 0;
}