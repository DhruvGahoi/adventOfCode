#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        cin >> arr2[i];
    } 

    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int distance = 0;

    for(int i = 0; i < 1000 ; i++){
	distance += abs(arr1[i] - arr2[i]);
    }

    cout << distance ;


    return 0;
}
