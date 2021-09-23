#include <iostream>
using namespace std;

int c=0, inv=0;

void merge(int n1, int a[], int n2, int b[], int m[]){
    int p1=0, p2=0, i;
    for(i=0; i<(n1+n2); i++){
        if(p1>=n1){
            while(p2<n2){
                m[i++] = b[p2++];
            }
        }
        else if(p2>=n2){
            while(p1<n1){
                m[i++] = a[p1++];
            }
        }
        else if(a[p1] < b[p2]){
            m[i] = a[p1];
            p1++;
            ++c;
        }
        else{
            m[i] = b[p2];
            p2++;
            ++c;
            inv += (n1-p1);
        }
    }
}

void mergesort(int n, int a[]){
    if(n<2) return;
    int mid = n/2;
    int left[mid], right[n-mid], i;
    for(i=0; i<mid; i++){
        left[i] = a[i];
    }
    for(i=mid; i<n; i++){
        right[i-mid] = a[i];
    }
    mergesort(mid, left);
    mergesort(n-mid, right);
    merge(mid, left, n-mid, right, a);
}

int main(){
    int t;
    cin >> t;
    while(t>0){
        c=0, inv=0;
        int n;
        cin >> n;
        int a[n], i;
        for(i=0; i<n; i++) cin >> a[i];
        mergesort(n, a); 
        for(i=0; i<n; i++){
            cout << a[i] << ' ';
        }
        cout << "\nComparisons - " << c;
        cout << "\nInversions - " << inv << endl;
        --t;
    }
    return 0;
}