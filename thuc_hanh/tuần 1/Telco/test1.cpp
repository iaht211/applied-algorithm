#include<bits/stdc++.h>
using namespace std;
int check_p = 1;
map<string, int> cnt;
map<string, long long> time_call;
int total_cnt = 0;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string order;
    cin >> order;
    while(order[0] != '#') {
        string from_num, to_num, date, from_time, to_time ;
        cin >> from_num >> to_num >> date >> from_time >> to_time >> order;
        int valid = 1;
        for(int i = 0; i < 10; i++) {
            if(!isdigit(from_num[i])) {
                check_p = 0;
                valid = 0;
            }
            if(!isdigit(to_num[i])) {
                check_p = 0;
                valid = 0;
            }
        }
        if(!valid) continue;
        
        // ham chuyen thoi gian
        long long time_diff = (long long) (to_time[0] - from_time[0]) * 10 + 
                                            (to_time[1] - from_time[1]);
                   time_diff = time_diff*60 + (to_time[3] - from_time[3]) * 10 + 
                                            (to_time[4] - from_time[4]); 
                    time_diff = time_diff*60 + (to_time[6] - from_time[6]) * 10 + 
                                            (to_time[7] - from_time[7]); 
        time_call[from_num] += time_diff;
        cnt[from_num]++;
        total_cnt++;
    }
    
    cin >> order;
    while(order[0] != '#') {
        if(order[1] == 'c' && order[2] == 'h') {
            cout << check_p << '\n';
            cin >> order;
            continue;
        }
        if(order[8] == 'c') {
            string q_num;
            cin >> q_num;
            cout << cnt[q_num] << '\n';
            cin >> order;
            continue;
        }
        if(order[8] == 't') {
            cout << total_cnt << '\n';
            cin >> order;
            continue;
        }

        string q_num;
        cin >> q_num;
        cout << time_call[q_num] << '\n';
        cin >> order;

    }

    return 0;
}