#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;
int n, m;
int course[MAX];
int theTeacherChoose[MAX];
vector<vector<int>> listOfCourse;
vector<vector<int>> listOfPairsOfConflicting;
int theLoadOfTeacher[MAX];
int theLoadMaxOfTeacher = 0;
int minAll = 1e9+7;

void inputData() {
    cin >> m >> n;
    int k;
    listOfCourse.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            int temp;
            cin >> temp;
            listOfCourse[i].push_back(temp);
        }
    }

    cin >> k;
    listOfPairsOfConflicting.resize(n+1);
    for(int i = 0; i <k; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        listOfPairsOfConflicting[temp1].push_back(temp1);
        listOfPairsOfConflicting[temp2].push_back(temp2);
    }
}

bool check(int a, int i) {
    int tick = 0;

    for(int j=0; j <listOfCourse[i].size(); j++) {
        if(listOfCourse[i].at(j) == a) {
            tick++;
        }
    }

    if(tick == 0) return false;

    for(int j=0; j < listOfPairsOfConflicting[a].size(); j++) {
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

            if(a == n) {
                solution();
            }
            else 
                if(theLoadMaxOfTeacher < minAll) Try(a+1);

            theLoadOfTeacher[i]--;
            theLoadMaxOfTeacher = pre;
        }
    }
}

int main() {
    inputData();
    Try(1);
    cout << minAll;

}