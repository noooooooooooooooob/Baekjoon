#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    unordered_map<int, int> fruit_count;
    int left = 0, max_len = 0;

    for (int right = 0; right < N; right++)
    {
        fruit_count[arr[right]]++;

        while (fruit_count.size() > 2)
        {
            fruit_count[arr[left]]--;
            if (fruit_count[arr[left]] == 0)
                fruit_count.erase(arr[left]);
            left++;
        }

        max_len = max(max_len, right - left + 1);
    }

    cout << max_len;
    return 0;
}
