#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
//    ifstream in("top.01.in");
//    ofstream out("top.01.out");

    int n;
    cin >> n;
	int k = -1;
	int h;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		if (h < i) {
			k = i - 1;
			break;
		} 
	}

	if (k == -1)
		k = n;
		
    cout << k << '\n';
    

    return 0;
}
