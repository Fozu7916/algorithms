class Solution {
    public:
        int climbStairs(int n) {
            if (n <= 2) return n;
    
            int nMinusTwo = 1;  // F(n-2)
            int nMinusOne = 2;  // F(n-1)
            int N = 0;          // F(n)
    
            for (int i = 3;i <= n; i++) {
                N = nMinusTwo + nMinusOne;
    
                nMinusTwo = nMinusOne;
                nMinusOne = N;
            }
            return N;
        }
    };