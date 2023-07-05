// 백준 15649 - N과 M(1)
// https://www.acmicpc.net/problem/15649
// 백트래킹

#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool check[9]; // check[i]에서 i 사용 여부 체크용 배열

void func(int k)
{
    if(k == m)
    {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!check[i])
        {
            arr[k] = i;
            check[k] = 1;
            func(k+1);
            check[k] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    func(0);
    return 0;
}