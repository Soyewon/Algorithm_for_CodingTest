// BOJ 1316 - 그룹 단어 체커
/*
문자가 연속해서 나타날 때만 그룹 단어
ex. happy (O)
ex. abab (X)
*/

#include <iostream>
#include <cstring>

using namespace std;

int n; // 단어 개수
string word; // 입력 단어
int alphabet[26]; // 알파벳 중복 여부 확인 배열
int result = 0; // 결과값

int find_num(string word){

    alphabet[word[0]-'a'] = 1;

    for(int i=0; i<word.length()-1; i++){
        if(word[i] != word[i+1]){ //aaba 0123 1
            if(alphabet[word[i+1]-'a'] == 0)
                alphabet[word[i+1]-'a'] = 1;
            else{
                return 0; // 뒤 알파벳이 다른데 이미 이전에 한번 나온 경우
            }            
        }       
    }

    return 1;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> word;
        memset(alphabet, 0, sizeof(alphabet));
        result += find_num(word);
    }
    
    cout << result;
    return 0;

}