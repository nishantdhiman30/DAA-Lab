#include <iostream>
using namespace std;

void outputDuplicates(int n1, int arr1[], int n2, int arr2[]){
    int i, p1=0, p2=0;
    while(p1<n1 && p2<n2){
        if(arr1[p1]==arr2[p2]){
            cout << arr1[p1] << " ";
            ++p1;
            ++p2;
        }
        else if(arr1[p1]<arr2[p2]){
            ++p1;
        }
        else ++p2;
    }
}

int main(){
    int n1, n2, i;
    cin >> n1;
    int arr1[n1];
    for(i=0; i<n1; ++i){
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for(i=0; i<n2; ++i){
        cin >> arr2[i];
    }
    outputDuplicates(n1, arr1, n2, arr2);
    return 0;
}