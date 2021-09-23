#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMid(int arr[], int st, int en){
    int pivot = arr[en];
    int pos=st, i;
    for(i=st; i<en; ++i){
        if(arr[i]<pivot){
            swap(&arr[i], &arr[pos++]);
        }
    }
    swap(&arr[pos], &arr[en]);
    return pos;
}

void quicksort(int arr[], int st, int en){
    if(st<en){
        int mid = findMid(arr, st, en);
        quicksort(arr, st, mid-1);
        quicksort(arr, mid+1, en);
    }
}

bool findDuplicate(int arr[], int st, int en){
    quicksort(arr, st, en);
    int i;
    for(i=0; i<en; ++i){
        if(arr[i]==arr[i+1]){
            return true;
        }
    }
    return false;
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
        bool x = findDuplicate(arr, 0, n-1);
        if(x) cout << "YES\n";
        else cout << "NO\n";
        free(arr);
        --t;
    }
    return 0;
}