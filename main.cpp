#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>


using namespace std;


void process(string str, unordered_map<string, double>& person_to_balance){
    istringstream ss(str);
  
    string word; // for storing each word
    vector<string> str_list;

    while (ss >> word) 
    {
        str_list.push_back(word);
    }

    double balance = stod(str_list.back()) / (str_list.size() -  1);

    for(int i = 0; i < str_list.size() - 1; i++){
        string person = str_list[i];
        if(person_to_balance.count(person)){
            person_to_balance[person] += balance;
        }
        else{
            person_to_balance[person] = balance;
        }
    }



}


int main(){
    unordered_map<string, double> person_to_balance;
    string line;
    while(getline(cin, line)){
        if (line == "end"){
            break;
        }
        else{
            process(line, person_to_balance);
        }
    }
    cout << "====================" << endl;
    for(auto&& [person, balance]: person_to_balance){
        cout << person << " " << balance << endl;
    }
    cout << "====================" << endl;
    return 0;

}