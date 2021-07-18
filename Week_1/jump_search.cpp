#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; ++i)
			cin>>ar[i];
		int key;
		cin >> key;
		int c = 0;
		int i, j, index, flag = 0;
		for(int i = 0; i < n; i += sqrt(n))
		{
			++c;
			if(ar[i] == key){
				flag = 1;
				break;
			}
			else if(ar[i] > key){
				j = i;
				index = i - sqrt(n) + 1;
				break;
			}
		}
		if(flag == 1)
			cout << "Present " << c << "\n";
		else{
			for (int k = index; k < j; ++k){
				++c;
				if(ar[k] == key){
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				cout << "Present " << c << "\n";
			else
				cout << "Not Present " << c << "\n";
		}
 	}
	return 0;
}