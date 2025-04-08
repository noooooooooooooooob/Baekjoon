#include <iostream>
#include <vector>

using namespace std;

// DFS
// 그래프 선언
class Graph
{
public:
    int VerticeNum;
    int EdgeNum;
    vector<vector<int>> adjList;
    vector<bool> visited;
    int cnt = 0;
};

void DFS(int v, Graph &g)
{
    g.visited[v] = true;
    for (int i = 1; i <= g.VerticeNum; i++)
    {
        if (!g.visited[i] && g.adjList[v][i] == 1)
        {
            g.cnt++;
            DFS(i, g);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Graph g;
    cin >> g.VerticeNum;
    cin >> g.EdgeNum;

    g.adjList.resize(g.VerticeNum + 1, vector<int>(g.VerticeNum + 1, 0));
    g.visited.resize(g.VerticeNum + 1, false);

    for (int i = 0; i < g.EdgeNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.adjList[v1][v2] = 1;
        g.adjList[v2][v1] = 1;
    }

    DFS(1, g);
    cout << g.cnt << "\n";

    return 0;
}
