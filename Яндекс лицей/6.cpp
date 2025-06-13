#include <iostream>

using namespace std;

const int INF = 1000000000;

int main() {
    int N;
    cin >> N;

    int** graph = new int*[N];
    for (int i = 0; i < N; ++i)
        graph[i] = new int[N];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int w;
            cin >> w;
            graph[i][j] = (w == 0 ? INF : w);
        }

    bool* used = new bool[N];
    int* minEdge = new int[N];

    for (int i = 0; i < N; ++i) {
        used[i] = false;
        minEdge[i] = INF;
    }

    minEdge[0] = 0;
    int totalWeight = 0;

    for (int i = 0; i < N; ++i) {
        int v = -1;

        for (int j = 0; j < N; ++j)
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v]))
                v = j;

        if (minEdge[v] == INF) {
            cout << -1 << "\n";
            for (int i = 0; i < N; ++i) delete[] graph[i];
            delete[] graph;
            delete[] used;
            delete[] minEdge;
            return 0;
        }

        used[v] = true;
        totalWeight += minEdge[v];

        for (int to = 0; to < N; ++to)
            if (graph[v][to] < minEdge[to])
                minEdge[to] = graph[v][to];
    }

    cout << totalWeight << "\n";

    for (int i = 0; i < N; ++i) delete[] graph[i];
    delete[] graph;
    delete[] used;
    delete[] minEdge;

    return 0;
}
