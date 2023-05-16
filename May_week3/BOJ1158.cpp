// BOJ 1158 - 요세푸스 문제

#include <iostream>
#include <queue>

using namespace std;

queue <int> yose;

// 1 2 3 4 5 6 7
// 4 5 6 7 1 2 / 3
// 7 1 2 4 5 / 3 6
// 4 5 7 1 / 3 6 2
// 1 4 5 / 3 6 2 7
// 1 4 / 3 6 2 7 5
// 4/ 3 6 2 7 

int main(){

    int n, k;

    cin >> n >> k;

    for(int i=1; i<n+1; i++){
        yose.push(i);
    }

    cout << '<';
   while(yose.size()>1){ 
        for(int cnt=1; cnt<k; cnt++){
            int front = yose.front();
            yose.pop();
            yose.push(front);
    }
    cout << yose.front() << ", ";
    yose.pop();
   }

    cout << yose.front() << '>';

   return 0;
}