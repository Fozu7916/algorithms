#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
const double PI = 3.14159;

int main()
{
    double r, h, d;
    string firma;

    cin >> r >> h >> d >> firma;

    double V = PI * r * r * h;
    int colchestvo = V / d;

    cout << fixed << setprecision(2);
    cout << "Объём бочки: " << V << ", фирмы: " << firma << endl;
    cout << "Количество бутылок: " << colchestvo;

    return 0;
}