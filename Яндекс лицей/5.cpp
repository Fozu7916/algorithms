#include <iostream>

using namespace std;

const int INF = 1000000000;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << "0 0 0\n";
        return 0;
    }

    int** dist = new int*[N];
    for (int i = 0; i < N; ++i)
        dist[i] = new int[N];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int w;
            cin >> w;
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = (w == 0 ? INF : w);
        }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j && dist[i][j] == INF) {
                cout << "0 0 0\n";
                for (int x = 0; x < N; ++x) delete[] dist[x];
                delete[] dist;
                return 0;
            }

    int maxDist = -1;
    int cityA = -1, cityB = -1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j && dist[i][j] > maxDist) {
                maxDist = dist[i][j];
                cityA = i;
                cityB = j;
            }

    cout << cityA + 1 << " " << cityB + 1 << " " << maxDist << "\n";

    for (int i = 0; i < N; ++i)
        delete[] dist[i];
    delete[] dist;

    return 0;
}
