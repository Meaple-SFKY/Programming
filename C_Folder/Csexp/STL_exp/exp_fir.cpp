#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

using namespace std;

int main(void) {
    srand(time(NULL));

    vector <int> test_vec;
    vector <int>::iterator it_vec;
    list <int> test_list;
    list <int>::iterator it_list;

    //vector experiment
    for (int i = 0; i < 10; i++) {
        test_vec.push_back(rand() % (100));
    }

    for (it_vec = test_vec.begin(); it_vec != test_vec.end(); it_vec++) {
        cout << * it_vec << " ";
    }
    cout << endl;

    test_vec.insert(test_vec.begin(), rand() % 100);

    for (it_vec = test_vec.begin(); it_vec != test_vec.end(); it_vec++) {
        cout << * it_vec << " ";
    }
    cout << endl;

    int temp = rand() % 100;

    it_vec = find(test_vec.begin(), test_vec.end(), temp);

    if (it_vec != test_vec.end()) {
        cout << * it_vec << endl;
    }
    else {
        test_vec.insert(test_vec.end(), temp);
    }

    sort(test_vec.begin(), test_vec.end());

    for (it_vec = test_vec.begin(); it_vec != test_vec.end(); it_vec++) {
        cout << * it_vec << " ";
    }
    cout << endl;

    //list experiment
    for (int i = 0; i < 10; i++) {
        test_list.push_back(rand() % 100);
    }

    for (it_list = test_list.begin(); it_list != test_list.end(); it_list++) {
        cout << * it_list << " ";
    }
    cout << endl;

    test_list.push_front(rand() % 100);

    for (it_vec = test_vec.begin(); it_vec != test_vec.end(); it_vec++) {
        cout << * it_vec << " ";
    }
    cout << endl;

    temp = rand() % 100;

    it_list = find(test_list.begin(), test_list.end(), temp);

    if (it_list != test_list.end()) {
        cout << * it_list << endl;
    }
    else {
        test_list.push_front(temp);
    }

    test_list.sort();

    for (it_list = test_list.begin(); it_list != test_list.end(); it_list++) {
        cout << * it_list << " ";
    }
    cout << endl;

    return 0;
}