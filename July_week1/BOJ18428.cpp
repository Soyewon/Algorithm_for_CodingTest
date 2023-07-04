// 백준 18428 - 감시 피하기
// https://www.acmicpc.net/problem/18428
// dfs, 백트래킹, 브루트포스

#include <iostream>
#include <vector>
#include <algorithm>

// 선생님 T
// 학생 S
// 장애물 O
// 선생님은 대각선은 볼 수 x
using namespace std;

int n;
char map[6][6];
int dx[4] = {0, 0, -1, 1}; // 상하좌우 이동
int dy[4] = {1, -1, 0, 0};

bool flag; // 3개로 가능/불가능 여부
vector<pair<int,int>> teacher;
vector<pair<int,int>> corridor;

bool avoidTeacher(int x, int y, int dir) {

    while(1) {
        x += dx[dir];
        y += dy[dir];

        if(map[x][y] == 'O' || x<0 || x>n || y<0 || y>n)
            break;
        // 길목에 학생이 있다면 선생님의 감시를 피하지 못한 것
        if(map[x][y] == 'S')
            return false;
    }
    return true; // 길목에 학생이 없다면 감시 피하기 성공
}

bool isPossible() {

    for(int i=0; i<teacher.size(); i++) {
        int x = teacher[i].first;
        int y = teacher[i].second;

        for(int dir=0; dir<4; dir++) { // 상하좌우 4방향 탐색
            if(!avoidTeacher(x, y, dir)) // 감시를 피하지 못했다면
                return false;
        }
    }
    return true; // 감시를 피했다면
}

void dfs(int cnt) {

    if(cnt == 3) {
        if(isPossible()) // 감시를 피했을 때
            flag = true;
            return;
    }

    for(int i=0; i<corridor.size(); i++) {
        int x = corridor[i].first;
        int y = corridor[i].second;
        if(map[x][y] == 'X') {
            map[x][y] = 'O';
            dfs(cnt+1);
            map[x][y] = 'X';
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];

            if(map[i][j] == 'T')
                teacher.push_back({i, j});
            else if(map[i][j] == 'X')
                corridor.push_back({i, j});
        }
    }

    dfs(0);

    if(flag)
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}
