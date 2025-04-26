#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<bool> visited(200001, false);  // 위치 방문 체크
    queue<pair<int, int>> q;               // {현재 위치, 이동 횟수}
    
    q.push({N, 0});  // 시작 위치, 0번 이동
    visited[N] = true; // 시작 위치 방문 체크

    while (!q.empty())
    {
        auto [cur, cnt] = q.front();
        q.pop();

        if (cur == K)
        {
            cout << cnt;
            return 0;
        }

        if (cur + 1 <= 200000 && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            q.push({cur + 1, cnt + 1});
        }
        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            q.push({cur - 1, cnt + 1});
        }
        if (cur * 2 <= 200000 && !visited[cur * 2])
        {
            visited[cur * 2] = true;
            q.push({cur * 2, cnt + 1});
        }
    }
}
