// BOJ 11729 - 하노이 탑 쌓기

#include <iostream>

using namespace std;

int cnt = 0;

void hanoi(int n, int start, int to, int end){

    if(n==1){
        cout << start << " " << end << '\n';
    }
    else{
        hanoi(n-1, start, end, to);
        cout << start << " " << end << '\n';
        hanoi(n-1, to, start, end);
    }
}

int main(){

    int n; // 원판의 개수

    cin >> n;
    cout << (1<<n)-1 << '\n';
    hanoi(n, 1, 2, 3);

}