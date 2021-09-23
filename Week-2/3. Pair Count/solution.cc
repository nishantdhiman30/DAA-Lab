#include<iostream>
using namespace std;

int abs(int n){
    if(n<0) return -n;
    return n;
}

int pair_count(int *arr, int n, int k){
    int i, j, c=0;
    for(i=0; i<n-1; ++i){
        for(j=i+1; j<n; ++j){
            if(abs(arr[i]-arr[j])==k){
                ++c;
            }
        }
    }
    return c;
}

int main(){
    int t, n, i, k;
    cin >> t; // input number of testcases
    while(t>0){
        cin >> n; // input number of values in array
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            cin >> arr[i]; // input array values
        }
        cin >> k; // input element to search
        int res = pair_count(arr, n, k);
        cout << res << endl;
        --t;
    }
    return 0;
}