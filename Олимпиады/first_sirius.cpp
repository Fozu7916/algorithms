#include <iostream>
#include <algorithm>
#include <climits>


long long findNearestKioskDistance(long long point, long long d) {
    long long remainder = ((point % d) + d) % d;
    return std::min(remainder, d - remainder);
}

int main() {
    long long A = 0, B = 0, d = 0;
    std::cin >> A >> B >> d;

    long long currentPoint = 0;
    long long max = std::max(A, B);
    long long min = (A + B) - max;
    long long distance = max - min;
    long long result = 0;

    if (distance % 2 == 0) {
        currentPoint = (distance / 2) + min;
        result = findNearestKioskDistance(currentPoint, d);
    } else {
        long long currentPoint1 = (distance / 2) + min;
        long long currentPoint2 = currentPoint1 + 1;
        
        long long dist1 = findNearestKioskDistance(currentPoint1, d);
        long long dist2 = findNearestKioskDistance(currentPoint2, d);
        
        if (dist1 < dist2) {
            currentPoint = currentPoint1;
            result = dist1;
        } else {
            currentPoint = currentPoint2;
            result = dist2;
        }
    }

    std::cout << currentPoint << " " << result;
    return 0;
}