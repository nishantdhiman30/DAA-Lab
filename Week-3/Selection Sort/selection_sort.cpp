#include <iostream>
using namespace std;

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* selection_sort(int* arr, int n){
    int i, j, min, swaps=0, comp=0;
    int* ret = new int[2];
    for(i=0; i<n-1; ++i){
        min = i;
        for(j=i+1; j<n; ++j){
            if(arr[j]<arr[min]){
                ++comp;
                min=j;
            }
        }
        swap(&arr[i], &arr[min]);
        ++swaps;
    }
    ret[0]=swaps, ret[1]=comp;
    return ret;
}

int main(){
    int t, n, i, swaps, comp;
    cin >> t;
    while(t){
        cin >> n;
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            cin >> arr[i];
        }
        int* ret = selection_sort(arr, n);
        swaps = ret[0];
        comp = ret[1];
        for(i=0; i<n; ++i){
            cout << arr[i] << " ";
        }
        cout << "\nComparisons = " << comp << "\nSwaps = " << swaps << endl;
        free(ret);
        free(arr);
        --t;
    }
    return 0;
}