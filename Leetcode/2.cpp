class Solution {
public:
    bool isPalindrome(int x) {
       bool end = false;

       if(x>0)
       {
        end = true;
        vector<int> digits;
          int temp = x;
          while(temp > 0)
          {
            digits.push_back(temp % 10);
            temp /= 10;
          }
          int left = 0;
          int rigth = digits.size() - 1;

          while ( left <rigth )
          {
            if(digits[left] != digits[rigth])
            {
                end = false;
            }
            left ++;
            rigth --;
          }


       }

       if(x == 0)
       {
        end = true;
       }
       if(x < 0)
       {
        end = false;
       }
       return end;
    }
};

// Given an integer x, return true if x is a palindrome, and false otherwise.