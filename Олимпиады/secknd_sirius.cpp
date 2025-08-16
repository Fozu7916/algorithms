#include <iostream>

long long fast_pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        long long p, a;
        std::cin >> p >> a;
        
        // По малой теореме Ферма: a^(p-2) ≡ a^(-1) (mod p)
        long long b = fast_pow_mod(a, p - 2, p);
        std::cout << b << std::endl;
    }
    
    return 0;
}