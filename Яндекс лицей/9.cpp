#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool isMultiLayeredPrime(int n) {
    string s = to_string(n);
    while (!s.empty()) {
        int num = stoi(s);
        if (!isPrime(num)) {
            return false;
        }
        if (s.length() <= 1) break;
        s = s.substr(1, s.length() - 2);
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    bool found = false;
    for (int i = a; i <= b; ++i) {
        string s = to_string(i);
        if (s.length() % 2 != 0 && isMultiLayeredPrime(i)) {
            cout << i << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "0" << endl;
    }

    return 0;
}