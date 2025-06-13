#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int id;
    long long time;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    queue<Process> q;
    
    for (int i = 0; i < N; ++i) {
        int id;
        long long time;
        cin >> id >> time;
        q.push({id, time});
    }
    
    while (!q.empty()) {
        Process current = q.front();
        q.pop();
        
        if (current.time <= K) {
            cout << current.id << " ";
        } else {
            current.time -= K;
            q.push(current);
        }
    }
    
    return 0;
}