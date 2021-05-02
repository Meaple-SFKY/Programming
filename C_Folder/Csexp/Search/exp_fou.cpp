#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> bucket_size;
struct action {
    int from;
    int to;
    int water;
};

struct bucket_states {
    vector<int> states_vector;
    action ac;
    bucket_states(int a, int b, int c, int from, int to, int water) {
        states_vector.resize(3);
        states_vector[0] = a;
        states_vector[1] = b;
        states_vector[2] = c;
        ac.from = from;
        ac.to = to;
        ac.water = water;
    }
    bucket_states() {
        states_vector.resize(3);
    }
    void set_action(int dump_water, int from, int to) {
        ac.from = from;
        ac.to = to;
        ac.water = dump_water;
    }
    bool is_empty(int bucket_idx) {
        if(bucket_idx > 2) {
            return false;
        }
        return (states_vector[bucket_idx] == 0);
    }
    bool is_full(int bucket_idx) {
        return (states_vector[bucket_idx] >= bucket_size[bucket_idx]);
    }
    bool is_final() {
        return (states_vector[0] == 4 && states_vector[1] == 4);
    }
    bool dump_water(int from, int to, bucket_states& next) {
        vector<int> bucket_water(this->states_vector);
        
        int dump_water = bucket_size[to] - states_vector[to];
        
        if(bucket_water[from] >= dump_water) {
            bucket_water[to] += dump_water;
            bucket_water[from] -= dump_water;
        } else {
            dump_water = bucket_water[from];
            bucket_water[to] += dump_water;
            bucket_water[from] = 0;
        }
        if(dump_water > 0) {
            next.states_vector = bucket_water;
            next.set_action(dump_water, from, to);
            return true;
        }
        return false;
    }
};
 
void print_states(bucket_states& bucket){
    cout << "bucket_states:  " << bucket.states_vector[0] << " " << 
        bucket.states_vector[1] << " " << bucket.states_vector[2] <<
        " | from " << bucket.ac.from << '\t' << " to " << bucket.ac.to << 
        "  dump " << bucket.ac.water << "L water." << endl; 
}

bool is_action_valid(bucket_states& cur, int from, int to) {
    if((from != to) && !cur.is_empty(from) && !cur.is_full(to)) {
        return true;
	}
    return false;
}
 
bool is_loop(vector<bucket_states>& states, bucket_states& next) {
    for(int i = 0; i < states.size(); ++i) {
        if(equal(next.states_vector.begin(), next.states_vector.end(), 
            states[i].states_vector.begin()))
            return true;
    }
    return false;
}

void DFS(vector<bucket_states>& states, int& cnt, int& shortest) {
    bucket_states cur = states.back();
    if(cur.is_final()) {
        ++cnt;
        shortest = min(shortest, static_cast<int>(states.size()));
        for_each(states.begin(), states.end(), print_states);
        cout << endl << "*****************************************************" << endl << endl;
        return;
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(is_action_valid(cur, i, j)) {
                bucket_states next_states;
                bool is_dump = cur.dump_water(i, j, next_states);
                if(is_dump && !is_loop(states, next_states)) {
                    states.push_back(next_states);
                    DFS(states, cnt, shortest);
                    states.pop_back();
                }
            }
        }
	}
}
 
int main() {
    bucket_size.push_back(8);
    bucket_size.push_back(5);
    bucket_size.push_back(3);
    vector<bucket_states> states;
    bucket_states start(8, 0, 0, -1, 0, 8);
    states.push_back(start);
    int cnt = 0, shortest = INT_MAX;
    DFS(states, cnt, shortest);
	if (cnt == 0) {
		cout << "No Solution" << endl;
	}
	else {
		cout << "result size : " << cnt << " shortest : " << shortest <<endl;
	}
}