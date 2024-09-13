#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int a = 1, b = 1;
	int colun = 2;
	int plus = 2;
	int firsta = 1;
	for (int i = 2; i <= N; i++) {
		if (colun == i) {
			firsta++;
			a = firsta;
			b = 1;
			colun += plus;
			plus++;
		}
		else {
			a--;
			b++;
		}
	}
	cout << a << " " << b;
	return 0;
}
