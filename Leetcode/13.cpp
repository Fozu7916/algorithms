class Solution {
    public:
        int mySqrt(int x) {
    
            int min = 1;
            int max = x;
            int currentMax = 0;
    
            while (min <= max) {
                long long middle = min + (max - min) / 2;
    
                if (middle * middle > x) {
    
                    max = middle - 1;
    
                } else if (middle * middle < x) {
                    min = middle + 1;
                    currentMax = middle;
                } else {
                    return middle;
                }
    
            }
            return currentMax;
        }
    };