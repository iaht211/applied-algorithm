#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> num_call;
    map<string, int> time_call;
    int total_call = 0;
    int check = 1;
    
    string order;
    cin >> order;
    while(order[0] != '#') {
        string from_time, to_time, from_call, to_call, date;
        cin >> from_call >> to_call >> date >> from_time >> to_time >> order;
        for(int i = 0; i <= 9; i++) {
            if(isdigit(from_call[i]) == 0 || isdigit(to_call[i]) == 0){
                check = 0;
                continue;
            }
        }
        if(!check) continue;

        long long diff_time = (long long)(to_time[0] - from_time[0]) * 10 + (to_time[1]-from_time[1]);
        diff_time = diff_time*60 + (to_time[3] - from_time[3]) * 10 + (to_time[4]-from_time[4]);
        diff_time = diff_time*60 + (to_time[6] - from_time[6]) * 10 + (to_time[7]-from_time[7]);

        num_call[from_call]++;
        time_call[from_call] += diff_time;
        total_call++;
    }

    cin >> order;
    while(order[0] != '#') {
        if(order[2] == 'h') {
            cout << check << '\n';
            cin >> order;
            continue;
        }
        if(order[1] == 'n' && order[8] == 'c') {
            string tmp;
            cin >> tmp;
            cout << num_call[tmp] << '\n';
            cin >> order;
            continue;
        }
        if(order[1] == 'n' && order[8] == 't') {
            cout << total_call << '\n'; 
            cin >> order;
            continue;
        }
        string tmp;
        cin >> tmp;
        cout << time_call[tmp] << '\n';
        cin >> order;

    }
}