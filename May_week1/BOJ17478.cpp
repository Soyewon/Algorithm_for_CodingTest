// BOJ 17478 - 재귀함수가 뭔가요?

#include <iostream>

using namespace std;

int cnt = 0;

void print_(int n){ // 재귀에 따른 언더바 출력

    for(int i=0; i<n; i++){
        cout << "____";
    }
}

void recursion(int n){

    if (n == 0) {
        print_(cnt);
        cout << "\"재귀함수가 뭔가요?\"\n";
        print_(cnt);
        cout <<  "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        print_(cnt);
        cout << "라고 답변하였지.\n";
        cnt--;
        return;
    }
    else {
        print_(cnt);
        cout << "\"재귀함수가 뭔가요?\"" << '\n';
        print_(cnt);
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        print_(cnt);
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        print_(cnt);
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
        cnt++;

        recursion(n - 1);
        print_(cnt);
        cout << "라고 답변하였지.\n";
        cnt--;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 재귀 횟수

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    recursion(n);

    return 0;
}