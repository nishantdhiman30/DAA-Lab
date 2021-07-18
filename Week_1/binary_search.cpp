#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, key;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; ++i)
			cin >> ar[i];
		cin >> key;
		int l = 0, h = n - 1;
		int c = 0, flag = 0;
		while(l <= h){
			++c;
			int mid = l + (h - l)/2;
			if(ar[mid] == key){
				flag = 1;
				break;
			}
			else if(ar[mid] < key)
				l = mid + 1;
			else
				h = mid - 1;
		}
		if(flag == 1)
			cout << "Present " << c << "\n";
		else 
			cout << "Not Present " << c << "\n";
	}
	return 0;
}