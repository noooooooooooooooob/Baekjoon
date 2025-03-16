#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, M;
	int arr[50];
	int box[1000] = { 0, };
	int result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int boxIndex = 0;
	for (int i = 0; i < N; i++) {
		if (box[boxIndex] + arr[i] <= M)
			box[boxIndex] += arr[i];
		else {
			box[++boxIndex] = arr[i];
		}
	}
	if (N == 0)boxIndex = -1;
	cout << boxIndex+1;
	return 0;
}
