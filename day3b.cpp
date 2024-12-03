#include<bits/stdc++.h>
using namespace std;

vector<string> extractingMuls(string s){
    vector<string> result;
    regex pattern(R"(do\(\)|mul\(\d+,\d+\)|don't\(\))");
    smatch matches;

    while(regex_search(s, matches, pattern)){
        result.push_back(matches[0]);
        s = matches.suffix().str();
    }

    return result;
}
// mul(445, 554)
int mul_to_int(string& str){
    int a;
    int b;
    string s = "";
    for(int i = 4; str[i] != ','; i++){
        s += str[i];
    }
    a = stoi(s);
    s = "";
    int index = str.find(',') + 1;
    for(int i = index; str[i] != ')'; i++){
        s += str[i];
    }
    b = stoi(s);
    s = "";

    return a * b;
}

int main(){

    fstream f("input.txt");
    string line;
    int sum = 0;
    bool flag = true;
    while (getline(f, line)){
        vector<string> result = extractingMuls(line);
        for(int i = 0; i < result.size(); i++){
            if(result[i] == "don't()"){
                flag  = false;
            } else if(result[i] == "do()"){
                flag = true;
            } else {
                if(flag){
                    sum += mul_to_int(result[i]);
                }
            }
            
        }
    }

    cout << sum;
    

    f.close();
    return 0;
}