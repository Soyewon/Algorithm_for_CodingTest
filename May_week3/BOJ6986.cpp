// BOJ 6986 - 절사평균
// 왜 주석처리한 부분으로 출력하면 맞았습니다 뜨고, 내가 한 방법대로 하면 틀렸습니다 뜨는거지?
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double score[100001];
int n, k;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> score[i];
    }

    sort(score+1, score+n+1);

    double front = score[k+1];
    double back = score[n-k];

    double sum = 0;
    for(int i=k+1; i<=n-k; i++){
        sum += score[i];
    }
    sum /= (n-2*k);
    double cutted_mean = round(sum*100)/100.0;
    //printf("%.2lf\n",floor(sum*100+0.5)/100);

    cout << cutted_mean << '\n';
    sum = 0;
    for(int i=k+1; i<=n-k; i++){
        sum += score[i];
    }
    sum += front*k + back*k;

    sum /= n;
    double make_mean = round(sum*100) / 100.0;
    //printf("%.2lf",floor(sum*100+0.5)/100);
    cout << make_mean;

    return 0;

}

// 0 1 2 5 6 8/3 = 2.66666
// 1 1 2 5 5 14/5 = 2.8