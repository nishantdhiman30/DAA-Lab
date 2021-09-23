#include<iostream>
using namespace std;

void tri_some(int* arr, int n){
    int i, j, k;
    bool flag=false;
    for(i=0; i<n-2; ++i){
        if(flag) break; // element already found
        for(j=i+1; j<n-1; ++j){
            if(flag) break; // element already found
            for(k=j+1; k<n; ++k){
                if(arr[i] + arr[j] == arr[k]){
                    cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
                    flag=true;
                    break;
                }
                if(arr[k]>(arr[i]+arr[j]))
                    break; // since array is sorted, further elements will be larger as well
            }
        }
    }
    if(!flag){
        cout << "No sequence found\n";
    }
}

int main(){
    int t, n, i;
    cin >> t; // input number of testcases
    while(t>0){
        cin >> n; // input number of values in array
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            cin >> arr[i]; // input array values
        }
        tri_some(arr, n);
        --t;
    }
    return 0;
}