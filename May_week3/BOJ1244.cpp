// BOJ 1244 - 스위치 켜고 끄기

#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int s[101]; // 스위치 초기 상태 받는 vector

    cin >> n; // 스위치 개수
    int switch_num;
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }

    int student_n; // 학생 수
    int sex; // 성별
    int s_num; // 스위치 숫자
    cin >> student_n;
    for(int i=0; i<student_n; i++){
        cin >> sex >> s_num;
        
        if(sex == 1){
            int cnt = 1;
            int multi = s_num;

            while(multi <= n){
                if(s[multi]==1)
                    s[multi] = 0;
                else 
                    s[multi] = 1;

                cnt += 1;
                multi = s_num * cnt;
            }
        }

        if(sex == 2){
            if(s[s_num]==1)
                s[s_num] = 0;
            else
                s[s_num] = 1;
            
            if(s_num!=1 && s_num!=n){
                int front = s_num-1;
                int end = s_num+1;

                while(front>=1 && end<=n){
                    if(s[front]==s[end]){
                        if(s[front]==1){
                            s[front]=0;
                            s[end]=0;
                        }
                        else{
                            s[front]=1;
                            s[end]=1;
                        }

                        front -= 1;
                        end += 1;
                        continue;
                    }
                    else
                        break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << s[i] << ' ';
        if(i%20 == 0)
            cout << '\n';
    }

    return 0;

    // 0 1 0 1 0 0 0 1
    // 0 1 1 1 0 1 0 1
}
