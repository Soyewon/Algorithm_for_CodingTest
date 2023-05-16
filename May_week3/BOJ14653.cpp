// BOJ 14653 - 너의 이름은

// 마지막 읽은 사람은 무조건 읽은것
// 나(A)도 무조건 읽은것

/*
a가 읽고, b가 읽어서 안읽은사람 3명됨.
그러면...마지막에도 3명이니까 만약 c가 읽고 튀엇으면
위에 2명이되겟지

5 6 4
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n; // 사람 수
int k; // 총 메시지 개수
int q; // 정보를 알고 싶은 메시지 번호

char person[100];
vector<pair <int, char> > msg;

int main(){

    cin >> n >> k >> q;
    vector<char> person;

    for(int i=65; i<65+n; i++){
        char p = (char) i; // A, B 등으로 변환
        person.push_back(p);
    }

    int read;
    char p;
    for(int i=0; i<k; i++){
        cin >> read >> p;
        msg.push_back(make_pair(read, p));
    }

    //q번째=> 배열상 q-1번째,,,
    // q-1번째 => 배열상 q-2번째

    
    if(msg[q-1].first == 0){ // 모두 다 읽은 경우
        cout << "-1" << '\n';
    }
    else if(msg[q-1].first == n-1){ // 나만 읽은 경우
        for(int i=66; i<65+n; i++){
            cout << person[i] << ' ';
        }
    }
    else{

    }

    return 0;

}