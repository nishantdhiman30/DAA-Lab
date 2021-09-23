#include <iostream>
#include <time.h>
using namespace std;

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int pivot(int arr[], int st, int en){
    srand(time(0));
    int pivot_index = st + rand()%(en-st);
    swap(arr+pivot_index, arr+en);
    int pos=st, i;
    for(i=st; i<en; ++i){
        if(arr[i]<=arr[en]){
            swap(arr+i, arr+pos);
            ++pos;
        }
    }
    swap(arr+pos, arr+en);
    return pos;
}

int quicksort(int arr[], int st, int en, int k){
    if(st<=en){
        int mid = pivot(arr, st, en);
        if(mid==k-1) return arr[mid];
        if(mid>k-1)
            return quicksort(arr, st, mid-1, k);
        else return quicksort(arr, mid+1, en, k);
    }
    cout << st << " " << en << "\n";
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        int n, k;
        cin >> n;
        int a[n], i;
        for(i=0; i<n; i++) cin >> a[i];
        cin >> k;
        int res = quicksort(a, 0, n-1, k);
        cout << res << endl;
        --t;
    }
    return 0;
}