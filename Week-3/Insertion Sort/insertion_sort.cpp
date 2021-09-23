#include <iostream>
using namespace std;

int* insertion_sort(int* arr, int n){
    int i, j, tempval, shifts=0, comp=0;
    int* ret = new int[2];
    for(i=1; i<n; ++i){
        if(arr[i]<arr[i-1]){
            tempval=arr[i];
            j=i-1;
            while(j>=0 && arr[j]>tempval){
                arr[j+1]=arr[j];
                --j;
                ++shifts;
                ++comp;
            } 
            arr[j+1]=tempval;
            ++shifts;
        }
    }
    ret[0]=shifts, ret[1]=comp;
    return ret;
}

int main(){
    int t, n, i, shifts, comp;
    cin >> t;
    while(t){
        cin >> n;
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            cin >> arr[i];
        }
        int* ret = insertion_sort(arr, n);
        shifts = ret[0];
        comp = ret[1];
        for(i=0; i<n; ++i){
            cout << arr[i] << " ";
        }
        cout << "\nComparisons = " << comp << "\nShifts = " << shifts << endl;
        free(ret);
        free(arr);
        --t;
    }
    return 0;
}