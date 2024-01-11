#include<bits/stdc++.h>
using namespace std;
const int maxn = 40;
int m, n;
vector<vector<int>> listOfCourse;
vector<vector<int>> listOfPairConflicting;
int course[maxn];
int theLoadOfTeacher[maxn];
int theTeacherChoose[maxn];
int theLoadMaxOfTeacher = 0;
int minAll = 1e9+7;

void input() {
    int k;
    cin >> m >> n;
    listOfCourse.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            listOfCourse[i].push_back(tmp);
        }
    }
    listOfPairConflicting.resize(n+1);
    cin >> k;
    for(int i = 0; i < k; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        listOfPairConflicting[tmp1].push_back(tmp2);
        listOfPairConflicting[tmp2].push_back(tmp1);
    }
}

void solution() {
    minAll = min(minAll, theLoadMaxOfTeacher);
}

bool check(int a, int v) {
    int tick = 0;
    for(int j = 0; j < listOfCourse[v].size(); j++) {
        if(listOfCourse[v].at(j) == a)  tick++;
    }

    if(!tick) return false;

    for(int j = 0; j < listOfPairConflicting[a].size(); j++) {
        if(course[listOfPairConflicting[a].at(j)] == v && listOfPairConflicting[a].at(j) < a) 
            return false;
    }
}

void Try(int a) {
    for(int v = 0; v < m; v++) {
        if(check(a, v)) {
            course[a] = v;
            theLoadOfTeacher[v]++;
            int pre = theLoadMaxOfTeacher;
            theLoadMaxOfTeacher = max(theLoadMaxOfTeacher, theLoadOfTeacher[v]);
            if(a == n) {
                solution();
            }
            else{
                if(theLoadMaxOfTeacher < minAll) Try(a+1);
            }
            theLoadOfTeacher[v]--;
            theLoadMaxOfTeacher = pre;

        }
    }
}

int main() {
    input();
    Try(1);
    cout << minAll;
}