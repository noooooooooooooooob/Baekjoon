#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, input;
    vector<int> arr;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        arr.push_back(input);
    }

    // 중복 제거 및 정렬
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    map<int, int> rank;
    for (int i = 0; i < sorted.size(); i++)
        rank[sorted[i]] = i;

    // 결과 출력
    for (int i = 0; i < N; i++)
        cout << rank[arr[i]] << " ";
    return 0;
}
