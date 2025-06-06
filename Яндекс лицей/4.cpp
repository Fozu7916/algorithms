#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    double stamina = 1000;
    double totalHeight = 0;

    for (int i = 1; i <= n; ++i) {
        double height;
        int difficulty;
        cin >> height >> difficulty;

        if (difficulty == 10) {
            cout << "Уровень " << i << " слишком сложный. Пропускаем." << endl;
            continue;
        }

        stamina -= difficulty * 10;

        if (stamina < 0) {
            cout << "Восхождение прервано на уровне " << i << "." << endl;
            cout << "Пройдено высоты: " << fixed << setprecision(2) << totalHeight << " м" << endl;
            return 0;
        }

        totalHeight += height;
    }

    cout << "Поздравляем! Вы достигли вершины!" << endl;
    cout << "Общая высота: " << fixed << setprecision(2) << totalHeight << " м" << endl;
    cout << "Остаток выносливости: " << (int)stamina << " единиц" << endl;

    return 0;
}
