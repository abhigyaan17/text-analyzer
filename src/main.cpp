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
        
        void wordsFreq(){
            ifstream file("../data/sample.txt");
            
            if (!file.is_open()) {
                cout << "Error opening file" << endl;
            }
            string line;
            string word;
            while (getline(file, line)) {
                istringstream iss(line);
                while(iss>>word){
                    mp[word]++;
                }
            }
            cout<<"Frequency of each word:"<<endl;
            for(auto it:mp){
                cout<<it.first<<" : "<<it.second<<endl;
            }
            file.close();
        }

        void maxFreq(){
            ifstream file("../data/sample.txt");
            
            if (!file.is_open()) {
                cout << "Error opening file" << endl;
            }
            string line;
            string word;
            while (getline(file, line)) {
                istringstream iss(line);
                while(iss>>word){
                    mp[word]++;
                }
            }
            int maxFreq=0;
            string mostFreqWord;
            cout<<"Most frequent word:"<<endl;
            for(auto it:mp){
                if(maxFreq<it.second) mostFreqWord=it.first;
                maxFreq=max(maxFreq,it.second);
            }
            cout<<mostFreqWord<<" : "<<maxFreq<<endl;
            file.close();
        }
};

int main() {
    textAnalyzer obj;
    // cout<<"Total Words : "<<obj.totalWords()<<endl;
    // obj.wordsFreq();
    obj.maxFreq();
    return 0;
}