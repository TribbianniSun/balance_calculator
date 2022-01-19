#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>


using namespace std;


unordered_map<string, double> city_to_tax_rate({{"New Haven", 1.0635}, {"San Diego", 1.0775}});
string CURRENT_LOCATION = "New Haven";


double calculate_single_item(string single_item){
    if(single_item.size() == 0) return 0;
    bool should_pay_tax = single_item.back() == 'A' or single_item.back() == 'a';
    double price;
    if(should_pay_tax){
        single_item.pop_back();
        price = stod(single_item) * city_to_tax_rate[CURRENT_LOCATION];
    }
    else{
        price = stod(single_item);
    }
    return price;
}

void process(string str, unordered_map<string, double>& person_to_balance){
    if(str.size() == 0) return;
    istringstream ss(str);
  
    string word; // for storing each word
    vector<string> str_list;

    while (ss >> word) 
    {
        str_list.push_back(word);
    }

    double balance = calculate_single_item(str_list.back()) / (str_list.size() -  1);

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
    freopen("input.txt","r",stdin);
    unordered_map<string, double> person_to_balance;
    string line;
    while(getline(cin, line)){
        process(line, person_to_balance);
    }
    cout << "====================" << endl;
    double total_dif = 0;
    for(auto&& [person, balance]: person_to_balance){
        cout << person << " " << balance << endl;
        total_dif += balance;
    }
    cout << "total sum is " << total_dif << endl;
    cout << "====================" << endl;
    return 0;

}