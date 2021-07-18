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
		int c = 0, flag = 0;
		for (int i = 0; i < n; ++i)
		{
			++c;
			if(ar[i] == key){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			cout << "Present " << c << "\n";
		else 
			cout << "Not Present " << c << "\n";
	}
	return 0;
}