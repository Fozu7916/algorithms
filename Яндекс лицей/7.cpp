#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0) return false;

    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}


void digitIsNaturalPoly(int a, int b) {
    bool isNoZero = true;
    for (int i = a;i <= b;i++) {
        int current = i;
        bool isPrime1 = true;
        while (current > 0) {
            if (isPrime(current)) {
                current /= 10;
            }
            else {
                isPrime1 = false;
                break;
            }
        }
        if (isPrime1) {
            cout << i << " ";
            isNoZero = false;
        }
    }
    if (isNoZero) {
        cout << "0";
    }

}


int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    digitIsNaturalPoly(a, b);
    return 0;
}
