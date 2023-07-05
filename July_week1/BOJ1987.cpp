// 백준 1987 - 알파벳
// https://www.acmicpc.net/problem/1987
// dfs

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int r, c; // 세로r 가로c
int result = 0;
bool check[26]; // 지나온 알파벳 여부 검사
char board[21][21];

// 상하좌우 이동
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt)
{
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<r && ny>=0 && ny<c) 
        {
            if(!check[board[nx][ny]-'A'])
            {
                check[board[nx][ny]-'A'] = true;
                dfs(nx, ny, cnt+1);
                check[board[nx][ny]-'A'] = false;
            }
        }
    }
    result = max(result, cnt);
}

int main()
{
    cin >> r >> c;

    for(int i=0; i<r; i++) 
    {
        string arr;
        cin >> arr;

        for(int j=0; j<arr.length(); j++)
        {
            board[i][j] = arr[j];
        }
    }

    check[board[0][0]-'A'] = true;
    dfs(0,0,1);

    cout << result;
    return 0;
    
}
