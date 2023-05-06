// BOJ 1193 - 분수찾기

/*
짝수번째일때 : 오른쪽 위에서 시작 (1열에서)
홀수번째일때 : 왼쪽에서 시작 (1행에서)

n이 짝수면 홀수번째
n이 홀수면 짝수번째


n/1 => n(n-1)/2 +1 번째
*/

#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;

	int i = 1;
	while (x > i) {
		x -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - x << '/' << x << endl;
	else
		cout << x << '/' << i + 1 - x << endl;
}