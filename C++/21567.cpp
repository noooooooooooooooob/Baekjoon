#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[10] = { 0, };

int main() {
	unsigned long long a, b, c;
	cin >> a >> b >> c;
	unsigned long long t = a * b * c;
	while (t >= 1)
	{
		arr[t % 10]++;
		t = t / 10;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	
	return 0;
}
