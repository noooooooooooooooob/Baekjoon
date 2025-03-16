#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


int main() {
	vector<pair<long long, long long>> arr;
	long long t;
	cin >> t;
	if (t == 0)
	{
		cout << "1\n";
		cout << "0 0";
		return 0;
	}
	if (t % 4763)
	{
		cout << "0";
		return 0;
	}
	t = t / 4763;
	for(long long i=0;i<=200;i++)
		for (long long j = 0; j <= 200; j++)
		{
			if (
				(i * 508 + j * 212 == t)
				|| (i * 508 + j * 305 == t)
				|| (i * 108 + j * 212 == t)
				|| (i * 108 + j * 305 == t)
				)
				arr.push_back(make_pair(i, j));
			
		}
	if (!arr.size())
	{
		cout << 0;
		return 0;
	}
	sort(arr.begin(), arr.end());
	cout << arr.size() << endl;
	for (auto& i : arr)
	{
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}
