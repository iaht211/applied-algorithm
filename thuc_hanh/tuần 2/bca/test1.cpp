#include<bits/stdc++.h>
using namespace std;

const int maxn = 31;

int m, n;
int course[maxn];
int theTeacherChoose[maxn];
vector<vector<int>> listOfCourse;
vector<vector<int>> listOfPairsOfConflicting;
int theLoadOfTeacher[maxn];
int theLoadMaxOfTeacher=0;
int minAll = 1e9+7;

void enter() {
    cin >> m >> n;
    int k;
    listOfCourse.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            listOfCourse[i].push_back(tmp);
        }
    }

    cin >> k;
    listOfPairsOfConflicting.resize(n+1);
    for(int i = 0; i < k; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        listOfPairsOfConflicting[tmp1].push_back(tmp2);
        listOfPairsOfConflicting[tmp2].push_back(tmp1);
    }
}

bool check(int a, int i) { // mon hoc a gan cho thay giao i
    int tick = 0;
    for(int j = 0; j < listOfCourse[i].size(); j++) {
        if(listOfCourse[i].at(j) == a) {
            tick++;
        }
    }
    if(tick == 0) return false;
    for(int j = 0; j < listOfPairsOfConflicting[a].size(); j++) {
        if(course[listOfPairsOfConflicting[a].at(j)] == i && listOfPairsOfConflicting[a].at(j) < a)
            return false;
    }
    return true;

}

void solution() {
    minAll = min(minAll, theLoadMaxOfTeacher);
}

void Try(int a) {
    for(int i = 0; i < m; i++) {
        if(check(a, i)) {
            course[a] = i;
            theLoadOfTeacher[i]++;
            int pre = theLoadMaxOfTeacher;
            theLoadMaxOfTeacher = max(theLoadMaxOfTeacher, theLoadOfTeacher[i]);
            if(a==n) solution();
            else{
                if(theLoadMaxOfTeacher < minAll) Try(a+1);
            }
            theLoadOfTeacher[i]--;
            theLoadMaxOfTeacher = pre;
        }
    }
}

int main() {
    enter();
    Try(1);
    cout << minAll;
}