#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
public:
    int** adjList;
    int* visited;
    int verticeNum;

    void initialize() {
        for (int i = 0; i <= verticeNum; i++)
            visited[i] = 0;
    }
};

Graph G;

void DFS(int v) {
    G.visited[v] = 1;
    cout << v << " ";
    for (int i = 1; i <= G.verticeNum; i++) {
        if (G.adjList[v][i] == 1 && G.visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    queue<int> q;
    G.visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 1; i <= G.verticeNum; i++) {
            if (G.adjList[current][i] == 1 && G.visited[i] == 0) {
                G.visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertice, edge, startVertice;
    cin >> vertice >> edge >> startVertice;

    G.verticeNum = vertice;

    // 인접 행렬 초기화
    G.adjList = new int* [vertice + 1];
    for (int i = 0; i <= vertice; i++) {
        G.adjList[i] = new int[vertice + 1];
        fill(G.adjList[i], G.adjList[i] + vertice + 1, 0); // 모두 0으로 초기화
    }

    G.visited = new int[vertice + 1];
    G.initialize();

    // 간선 입력
    int a, b;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b;
        G.adjList[a][b] = 1;
        G.adjList[b][a] = 1;
    }

    DFS(startVertice);
    cout << "\n";
    G.initialize();
    BFS(startVertice);
    cout << "\n";

    return 0;
}
