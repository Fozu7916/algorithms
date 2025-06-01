class Solution {
public:
    int lengthOfLastWord(string s) {
        s = " " + s;
        int count = 0;
        bool wordStarted = false;

        for (int i = s.size() - 1; i > 0;i--) {

            if (s[i] != ' ' and !wordStarted) {
                wordStarted = true;
            }

            if (wordStarted) {
                count++;
                if (s[i - 1] == ' ') {
                    return count;
                }
            }

        }
        return 0;
        
    }
};

//Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

//A word is a maximal substring consisting of non-space characters only.