#include <bits/stdc++.h>

using namespace std;

int solve(int row, int col, const string& word, const vector<string>& matrix) {
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},  {1, -1}, {1, 0}, {1, 1}  
    };

    int count = 0;
    for (auto dir : directions) {
        int nRow = row, nCol = col;
        bool isValid = true;

        for (int i = 0; i < word.length(); ++i) {
            if (nRow < 0 || nRow >= matrix.size() || nCol < 0 || nCol >= matrix[0].size() || matrix[nRow][nCol] != word[i]) {
                isValid = false;
                break;
            }
            nRow += dir.first;
            nCol += dir.second;
        }
        if (isValid) count++;
    }
    return count;
}

int main() {
    fstream file("input.txt");
    vector<string> matrix;
    string line;
    while (getline(file, line)) {
        matrix.push_back(line);
    }
    file.close();

    string word = "XMAS";

    int count = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 'X') { 
                count += solve(i, j, word, matrix);
            }
        }
    }
    cout << count;

    return 0;
}
