#include <bits/stdc++.h> 

using namespace std;

map<string, int> cnt;
map<string, long long> time_call;

int main() 
{ 
    int total_call = 0;
    int check_num = 1;
    int valid = 1;
    string order;
    cin >> order;
    while(order[0] != '#'){
        string from_num, to_num, date, from_time, to_time;
        cin >> from_num >> to_num >> date >> from_time >> to_time >> order;
        
        for(int i = 0; i <= 9; i++) {
            if(!isdigit(from_num[i])) {
                valid = 0;
                check_num = 0;
            }
        }
        
        for(int i = 0; i <= 9; i++) {
            if(!isdigit(to_num[i])) {
                valid = 0;
                check_num = 0;
            }
        }
        
        if(!valid) {
            continue;
        }
        
        long long diff_time = (long long) (to_time[0] - from_time[0]) * 10 + (to_time[1] - from_time[1]);
        diff_time = diff_time * 60 + (to_time[3] - from_time[3]) * 10 + (to_time[4] - from_time[4]);
        diff_time = diff_time * 60 + (to_time[6] - from_time[6]) * 10 + (to_time[7] - from_time[7]);
        cnt[from_num]++;
        time_call[from_num] += diff_time;
        total_call++;
    }
    
    cin >> order;
    
    while(order[0]!='#') {
        // check number
        if(order[1] == 'c' && order[2] == 'h') {
            cout << check_num << "\n";
            cin >> order;
            continue;
        }
        
        // count number call from 
        if(order[8] == 'c') {
            string q_num;
            cin >> q_num;
            cout << cnt[q_num] << "\n";
            cin >> order;
            continue;
        }
        
        // number total call 
        if(order[8] == 't') {
            cout << total_call << "\n";
            cin >> order;
            continue;
        }
        
        //count time call from 
        string q_num;
        cin >> q_num;
        cout << time_call[q_num] << "\n";
        cin >> order;
    }
}