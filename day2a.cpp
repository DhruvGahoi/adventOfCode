#include<bits/stdc++.h>
using namespace std;

int main(){

    fstream f("input.txt");

    string line;
    vector<vector<int>> data;

    while (getline(f, line) && !line.empty()) {    

        stringstream ss(line);
        vector<int> row;
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        data.push_back(row);

    }

    int safe = 0;
    for(auto &row : data){

        bool isIncreasing = true, isDecreasing = true;
        bool isSafe = true;
        for (size_t i = 1; i < row.size(); i++) {
            if (row[i] > row[i - 1]) {
                isDecreasing = false;
            } else if (row[i] < row[i - 1]) {
                isIncreasing = false;
            }
        }

        for(int i = 0; i < row.size() - 1; i++){
            if(!(abs(row[i] - row[i+1]) >= 1 && abs(row[i]-row[i+1]) <= 3)){
                isSafe = false;
                break;
            }
        }

        if(isSafe && (isDecreasing || isIncreasing)){
            safe++;
        }
        
    }

    cout << safe;

    return 0;
}

