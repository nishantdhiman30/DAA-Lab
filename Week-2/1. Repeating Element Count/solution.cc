#include<iostream>
using namespace std;

int binary_search(int *arr, int st, int en, int k){
    if(st>en){
        return -1;
    }
    int mid = (st+en)/2;
    if(arr[mid]==k){
        return mid;
    }
    if(arr[mid]<k){
        return binary_search(arr, mid+1, en, k);
    }
    else return binary_search(arr, st, mid-1, k);
}

int repeating_element_count(int *arr, int n,int k){
    int i, c=1;
    int pos = binary_search(arr, 0, n-1, k);
    if(pos==-1) return -1;
    for(i=pos-1; i>=0; --i){
        if(arr[i]==k) ++c;
        else break;
    }
    for(i=pos+1; i<n; ++i){
        if(arr[i]==k) ++c;
        else break;
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
        int res = repeating_element_count(arr, n, k);
        if(res!=-1){
            cout << k << " - " << res << '\n';
        }
        else{
            cout << "Not Present" << '\n';
        }
        --t;
    }
    return 0;
}