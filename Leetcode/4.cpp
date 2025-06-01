class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
        {
            return "";
        }


        string result = strs[0];
        for (int i = 1; i < strs.size(); ++i)
         {
            int j = 0;
            while (j < result.size() && j < strs[i].size() && result[j] == strs[i][j]) 
            {
                j++;
            }
           result = result.substr(0, j);
        }
        return result;
    }
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".