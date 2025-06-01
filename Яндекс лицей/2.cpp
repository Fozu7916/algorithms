#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

const double PI = 3.14159;

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	double R = 0, r = 0, h = 0, d = 0;
	string name = "";

	cin >> R >> r >> h >> d;
	cin.ignore();
	getline(cin, name);


	double V = (1.0 / 3.0) * PI * h * (R * R + R * r + r * r);
	double l = sqrt(h * h + (R - r) * (R - r));
	double S = PI * (R + r) * l;
	long count = S / d;

	cout << fixed << setprecision(2);
	cout << "Горный склон:" << endl;
	cout << "- Объём: " << V << endl;
	cout << "- Площадь поверхности: " << S << endl;
	cout << "- Количество палаток: " << count << endl;
	cout << "- Гора: " << name << endl;



}