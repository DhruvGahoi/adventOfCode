// Have some error, always return zero

// --------------------------------------------------WILL FIX LATER---------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

int solve(int row, int col, const string& word1, const string& word2, const vector<string>& matrix) {
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  
    };
    
    // string a = "Dhruv"; // can be iterated through string 
    // char b[] = {D, h, r, u, v}  // similarly this too
    // STRING always ends at NULL character..............................................................................

    int count = 0;
    for (auto dir : directions) {
        int nRow = row, nCol = col;
        bool isMAS = true;
        bool isSAM = true;

        for (int i = 0; i < word1.length(); i++) {
            if (nRow < 0 || nRow >= matrix.size() || nCol < 0 || nCol >= matrix[0].size() || matrix[nRow][nCol] != word1[i]) {
                isMAS = false;
                break;
            }
            nRow += dir.first;
            nCol += dir.second;
        }

        nRow = row;
        nCol = col;

        for (int i = 0; i < word2.length(); i++) {
            if (nRow < 0 || nRow >= matrix.size() || nCol < 0 || nCol >= matrix[0].size() || matrix[nRow][nCol] != word2[i]) {
                isSAM = false;
                break;
            }
            nRow -= dir.first;
            nCol -= dir.second;
        }

        if (isSAM && isMAS) count++;
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

    string word1 = "MAS";
    string word2 = "SAM";

    int count = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 'M') { 
                count += solve(i, j, word1, word2, matrix);
            }
        }
    }
    cout << count;

    return 0;
}


// --------------------------------------------------BHAVI's CODE-------------------------------------------------------
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;


int x_mas(int x, int y, vector<string> m){


    bool f = (y >= 1) && 
             (y <= m.size() - 2) && 
             (x >= 1) && 
             (x <= m[x].size() - 2);  

    int numX_mas = 0;

    
    
    // M.S
    // .A.
    // M.S
    if(f && m[x][y]     == 'A' &&
            m[x-1][y-1] == 'M' &&
            m[x+1][y-1] == 'S' &&
            m[x-1][y+1] == 'M' &&
            m[x+1][y+1] == 'S' ) numX_mas++;

    // S.M
    // .A.
    // S.M
    if(f && m[x][y]     == 'A' &&
            m[x-1][y-1] == 'S' &&
            m[x+1][y-1] == 'M' &&
            m[x-1][y+1] == 'S' &&
            m[x+1][y+1] == 'M' ) numX_mas++;
    // M.M
    // .A.
    // S.S
    if(f && m[x][y]     == 'A' &&
            m[x-1][y-1] == 'M' &&
            m[x+1][y-1] == 'M' &&
            m[x-1][y+1] == 'S' &&
            m[x+1][y+1] == 'S' ) numX_mas++;

    // S.S
    // .A.
    // M.M
    if(f && m[x][y]     == 'A' &&
            m[x-1][y-1] == 'S' &&
            m[x+1][y-1] == 'S' &&
            m[x-1][y+1] == 'M' &&
            m[x+1][y+1] == 'M' ) numX_mas++;
    
    return numX_mas;
    


}



int main() {

    fstream file("input4");
    vector<string> matrix;
    string line;
    int xmases = 0;
    while (getline(file, line)){
        matrix.push_back(line);
    }
        
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 'A'){
                xmases += x_mas(i, j, matrix);
                cout << xmases;
                cout << matrix[i][j];
            } else cout << '.';
        }
        cout << '\n';
    }
    
    cout << xmases; 
}