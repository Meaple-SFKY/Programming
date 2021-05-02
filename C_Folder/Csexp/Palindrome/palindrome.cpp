#include <iostream>

using namespace std;

int main(void) {
    int a[305], ans = 0;
    int t = 30;
    string s;

	cin >> s;

	int len = s.length();
	for (int i = 0; i < len; i++) {
		a[i + 1] = s[i] - 'a' + 1;
	}

	for (int i = 1; i <= len; i++) {
 	  	if (a[i] == a[i + 2]) {
 	  		if (a[i] == a[i - 1]) {
 	  			a[i] = t++;
 	  			ans++;
			}
			else {
                a[i + 2] = t++;
                ans++;
            }
		}
	}

	for (int i = 1; i <= len; i++) {
		if (a[i] == a[i + 1]) {
			a[i + 1] = t++;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

