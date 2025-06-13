#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue<int> main_queue;
    stack<int> defer_stack;
    int N;
    cin >> N;
    cin.ignore();
    
    for (int i = 0; i < N; ++i) {
        string command;
        getline(cin, command);
        
        if (command.substr(0, 6) == "ARRIVE") {
            int X = stoi(command.substr(7));
            main_queue.push(X);
        }
        else if (command == "DEFER") {
            if (!main_queue.empty()) {
                int task = main_queue.front();
                main_queue.pop();
                defer_stack.push(task);
            }
        }
        else if (command == "PROCESS") {
            if (!defer_stack.empty()) {
                cout << defer_stack.top() << '\n';
                defer_stack.pop();
            }
            else if (!main_queue.empty()) {
                cout << main_queue.front() << '\n';
                main_queue.pop();
            }
            else {
                cout << "IDLE\n";
            }
        }
    }
    
    return 0;
}