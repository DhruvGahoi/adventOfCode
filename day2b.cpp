#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &row) {
    bool isIncreasing = true, isDecreasing = true;

    for (size_t i = 1; i < row.size(); i++) {
        if (row[i] > row[i - 1]) {
            isDecreasing = false;
        } else if (row[i] < row[i - 1]) {
            isIncreasing = false;
        }
    }

    for (size_t i = 0; i < row.size() - 1; i++) {
        if (!(abs(row[i] - row[i + 1]) >= 1 && abs(row[i] - row[i + 1]) <= 3)) {
            return false;
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
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

    int safeReports = 0;

    for (auto &row : data) {
        if (isSafe(row)) {
            safeReports++;
        } else {
            bool madeSafe = false;
            for (size_t i = 0; i < row.size(); i++) {
                vector<int> modifiedRow = row;
                modifiedRow.erase(modifiedRow.begin() + i); // Remove the i-th level
                if (isSafe(modifiedRow)) {
                    madeSafe = true;
                    break;
                }
            }
            if (madeSafe) {
                safeReports++;
            }
        }
    }
    cout << safeReports << endl;

    return 0;
}
