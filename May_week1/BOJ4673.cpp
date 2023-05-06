// BOJ 4673 - 셀프 넘버

#include <iostream>
#include <cstring>

using namespace std;

# define MAX 10001

int find_selfNum(int num){ //1234 4 3 2 1

    int res = num;

    while(num!=0){
        res += num % 10;

        num /= 10;
    }

    return res;
}

int main(){

    bool check[MAX];
    memset(check, false, sizeof(check)); // false로 초기화

    for(int i=1; i<MAX; i++){
        int n = find_selfNum(i);

        if(n<MAX){
            check[n] = true;
        }
    }

    for(int j=1; j<MAX; j++){
        if(!check[j])
            cout << j << '\n';
    }

    return 0;

}