#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text;
    vector<string> undo_stack;
    vector<string> redo_stack;
    int N;
    cin >> N;
    cin.ignore();
    
    for (int i = 0; i < N; ++i) {
        string command;
        getline(cin, command);
        
        if (command.substr(0, 4) == "TYPE") {
            // Сохраняем текущее состояние перед изменением
            undo_stack.push_back(text);
            // Очищаем историю REDO при новом вводе
            redo_stack.clear();
            // Добавляем символ
            text += command[5];
        }
        else if (command == "UNDO") {
            if (!undo_stack.empty()) {
                // Сохраняем текущее состояние для возможного REDO
                redo_stack.push_back(text);
                // Восстанавливаем предыдущее состояние
                text = undo_stack.back();
                undo_stack.pop_back();
            }
        }
        else if (command == "REDO") {
            if (!redo_stack.empty()) {
                // Сохраняем текущее состояние для возможного UNDO
                undo_stack.push_back(text);
                // Восстанавливаем отмененное состояние
                text = redo_stack.back();
                redo_stack.pop_back();
            }
        }
    }
    
    cout << text << endl;
    return 0;
}