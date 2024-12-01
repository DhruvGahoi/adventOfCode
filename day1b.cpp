#include<bits/stdc++.h>
#include <vector>
using namespace std;

// 1 st list ke har elem ka count check krege second list mee
// dist += arr1[i] * count[arr[1]];

int main (){
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    unordered_map<int, int> freq;
    
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        cin >> arr2[i];
    } 

    for(int i = 0; i < n; i++){
        freq[arr2[i]]++;
    }

    int distance = 0;

    for(int i = 0; i < 1000 ; i++){
	    distance += arr1[i] * freq[arr1[i]];
    }

    cout << distance ;


    return 0;
}