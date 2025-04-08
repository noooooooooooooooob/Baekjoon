#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// dynamic programming
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(N + 1);
    dp[1] = arr[0];
    dp[2] = arr[1] + arr[0];
    dp[3] = arr[2] + max(arr[0],arr[1]);

    for(int i = 4;i <= N; i++)
    {
        dp[i] = max(dp[i-2], dp[i-3] + arr[i-2]) + arr[i - 1];
    }
    cout << dp[N];
    return 0;
}
