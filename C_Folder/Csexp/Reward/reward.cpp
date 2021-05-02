#include <iostream>

using namespace std;

void sum_set(int, int);
void insert(int**, int, int);
int search(int**, int, int);
void visual(void);

int number;
int** relation;
int** stor;
int** child;
int* level;
int* cost_time;
int* cost_sum;

int main(void) {

    cin >> number;

    level = new int[number];
    cost_time = new int[number];
    cost_sum = new int[number];
    relation = new int* [number];
    stor = new int* [number];
    child = new int* [number];

    for (int i = 0; i < number; i++) {
        relation[i] = new int[number];
        stor[i] = new int[number];
        child[i] = new int[number];
    }

    for (int i = 0; i < number; i++) {
        cost_sum[i] = 0;
        for (int j = 0; j < number; j++) {
            relation[i][j] = 0;
            if (j == 0) {
                stor[i][j] = i;
                child[i][j] = i;
            }
            else {
                stor[i][j] = -1;
                child[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < number; i++) {
        int i_superior;
        cin >> i_superior >> level[i] >> cost_time[i];

        if (i_superior == -1) {
            relation[i][i] = -1;
        }
        else {
            relation[i][i_superior - 1] = 1;
        }
    }
    
    for (int j = 0; j < number; j++) {
        sum_set(j, j);
    }

    visual();

    for (int i = 0; i < number; i++) {
        for (int j = 1; j < number; j++) {
            if (child[i][j] != -1) {
                if (level[i] > level[child[i][j]]) {
                    cost_sum[i] += cost_time[child[i][j]];
                }
            }
        }
    }

    for (int i = 0; i < number; i++) {
        cout << cost_sum[i] << endl;
    }

    return 0;
}

void insert(int** array, int i, int temp) {
    int j = 0;
    while (array[i][j] != -1) {
        j++;
        if (j >= number) {
            break;
        }
    }
    if (j == number) {
        return;
    }
    array[i][j] = temp;
}

void sum_set(int start, int i) {
    int temp = 0;

    while (relation[start][temp] == 0) {
        temp++;
        if (temp == number) {
            break;
        }
    }
    
    if (temp >= number) {
        return;
    }
    if (relation[start][temp] == -1) {
        return;
    }
    else {
        insert(stor, i, temp);
        start = temp;
        sum_set(start, i);
    }
}

int search(int** array, int i_temp, int temp) {
    for (int j = 0; j < number; j++) {
        if (array[i_temp][j] == temp) {
            return j;
        }
    }
    return -1;
}

void visual(void) {
    for (int i = 0; i < number; i++) {
        for (int i_temp = 0; i_temp < number; i_temp++) {
            int flag = search(stor, i_temp, i);
            if (flag != -1) {
                if (flag != 0) {
                    for (int j_temp = 0; j_temp <= flag; j_temp++) {
                        if (search(child, i, stor[i_temp][j_temp]) == -1) {
                            insert(child, i, stor[i_temp][j_temp]);
                        }
                    }
                }
            }
        }
    }
}