class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openParentheses, wildcards;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') wildcards.push(i);
            else if (s[i] == '(') openParentheses.push(i);
            else if (s[i] == ')') 
                if (!openParentheses.empty()) openParentheses.pop();
                else if (!wildcards.empty()) wildcards.pop();
                else return false;
        }

        while (!openParentheses.empty() && !wildcards.empty()) {
            if (openParentheses.top() < wildcards.top())
                openParentheses.pop();
            wildcards.pop();
        }

        return openParentheses.empty();
    }
};