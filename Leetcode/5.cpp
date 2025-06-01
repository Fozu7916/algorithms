class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c : s) 
        {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            }
            else if (c == ')' || c == '}' || c == ']') 
            {
                if (stack.empty()) return false;
                char top = stack.back();
                stack.pop_back();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.