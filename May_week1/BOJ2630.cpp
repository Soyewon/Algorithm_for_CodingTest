// BOJ 2630 - 색종이 만들기

#include <iostream>

using namespace std;

int blue_cnt = 0;
int white_cnt = 0;
int color[129][129];

void find_color(int x, int y, int len){

    bool cut = false;
    int first_color = color[x][y]; // 왼쪽 상단 색깔

    for(int i=x; i<(x+len); i++){
        for(int j=y; j<(y+len); j++){
            if(color[i][j] != first_color){ // 색깔 다른 부분 한군데라도 있으면
                cut = true; // cut
                break;
            }                
        }
    }

    if(cut){
        find_color(x, y, len/2);
        find_color(x, y+len/2, len/2);
        find_color(x+len/2, y, len/2);
        find_color(x+len/2, y+len/2, len/2);
    }
    else{ // 더 이상 안 잘라도 될 때,
        if(first_color == 0)
            white_cnt++;
        else
            blue_cnt++;
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 종이 한 변 길이

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> color[i][j];
        }
    }

    find_color(0, 0, n);
    cout << white_cnt << '\n';
    cout << blue_cnt << '\n';

    return 0;
}