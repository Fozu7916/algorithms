class Solution {
public:
    int romanToInt(string s) {
        int result = 0;;
        char I = 'I';
        char V = 'V';
        char X = 'X';
        char L = 'L';
        char C = 'C';
        char D = 'D';
        char M = 'M';

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == I and s[i + 1] == V)
            {
                result += 4;
                ++i;
            }
            else if (s[i] == I and s[i + 1] == X)
            {
                result += 9;
                ++i;
            }
            else if (s[i] == X and s[i + 1] == L)
            {
                result += 40;
                ++i;
            }
            else if (s[i] == X and s[i + 1] == C)
            {
                result += 90;
                ++i;
            }
            else if (s[i] == C and s[i + 1] == D)
            {
                result += 400;
                ++i;
            }
            else if (s[i] == C and s[i + 1] == M)
            {
                result += 900;
                ++i;
            }
            else 
            {
                switch (s[i])
                {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
                }
            }
        }
        return result;
    }
};

// Roman to Integer