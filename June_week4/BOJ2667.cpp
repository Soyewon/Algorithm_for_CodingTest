#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 26

int n; // 지도의 크기
int cnt = 0; // 단지 수 세기용
int map[MAX][MAX];
int visit[MAX][MAX]={0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0}; // 상하좌우 탐색
vector<int> res; // 단지 하나당 집 개수 저장용 vector
queue<pair<int, int>> que; // (x,y) 값 저장용 큐

void bfs() {

    int cnt = 0; // 한 단지 당 집 개수 세기

    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        cnt += 1; // 단지 내 집 개수 추가

        que.pop();

        for(int i=0; i<4; i++) {
            int next_x = x+dx[i];
            int next_y = y+dy[i];

            if(next_x<0 || next_x>=n || next_y<0 || next_y>=n) // 지도 밖을 벗어나는 경우
                continue;

            if(visit[next_x][next_y] == 1) // 이미 방문했을 시
                continue;
            else if(map[next_x][next_y] == 1) { // 방문하지 않았고, 집이 존재할 때
                que.push({next_x, next_y}); // que에 넣기
                visit[next_x][next_y] = 1; // 방문처리
            } 
        }
    }
    res.push_back(cnt);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0 ; j< n; j++)
        {
            map[i][j] = tmp[j]-'0';
        }
    }   

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // 아직 방문하지 않고, 집이 있는 곳부터 시작
            if(map[i][j]==1 && visit[i][j]==0) {
                cnt ++; // 처음 시작하는 곳이므로 cnt+1 해주고 시작
                que.push({i,j}); // 큐에 시작 위치 넣기
                visit[i][j] = 1; // 방문처리
                bfs(); // 시작위치를 기준으로 bfs
            }
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << '\n';

    for(int i=0; i<res.size(); i++) {
        cout << res[i] << '\n';
    }

}

