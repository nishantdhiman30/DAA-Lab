#include <iostream>
using namespace std;

void maxDuplicate(char a[], int n){
    int i, count[26]={0}, max=0, pos=-1;
    for(i=0; i<n; ++i){
        ++count[a[i]-'a'];
    }
    for(i=0; i<26; ++i){
        if(count[i]>max){
            max=count[i];
            pos=i;
        }
    }
    if(max==1){
        cout << "No Duplicates Present\n";
    }
    else{
        cout << (char)(pos+'a') << " - " << max << endl;
    }
}

int main(){
    int t,n,i;
    cin >> t;
    while(t>0){
        cin >> n;
        char arr[n];
        for(i=0; i<n; ++i){
            cin >> arr[i];
        }
        maxDuplicate(arr, n);
        --t;
    }
    return 0;
}