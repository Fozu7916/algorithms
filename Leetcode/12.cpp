class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int last = digits.size() - 1;
            bool isComplete = false;
    
            while (!isComplete and last > 0) {
                if (digits[last] != 9) {
                    digits[last]++;
                    isComplete = true;
                }
                else {
                    digits[last] = 0;
                    last--;
                }
            }
    
            if (last  == 0) {
                if (digits[last] == 9) {
                    digits.erase(digits.begin() + last);
                    digits.insert(digits.begin(), 0);
                    digits.insert(digits.begin(), 1);
                }
                else {
                    digits[last]++;
                }
            }
    
            return digits;
        }
    };
    