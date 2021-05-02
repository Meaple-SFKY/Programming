#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(void) {
    srand(time(NULL));

    vector <int> test;
    vector <int>::iterator it;

    for (int i = 0; i < 10; i++) {
        test.push_back(rand() % 100);
    }

    sort(test.begin(), test.end(), less<int>());

    for (it = test.begin(); it != test.end(); it++) {
        cout << * it << " ";
    }
    cout << endl;

    sort(test.begin(), test.end(), greater<int>());

    for (it = test.begin(); it != test.end(); it++) {
        cout << * it << " ";
    }
    cout << endl;

    it = find(test.begin(), test.end(), *max_element(test.begin(), test.end()));
    cout << * it << " ";
    it = find(test.begin(), test.end(), *min_element(test.begin(), test.end()));
    cout << * it << endl;

    return 0;
}