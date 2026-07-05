class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }

                char x = stack.top();
                if ((c == ')' && x == '(') || 
                    (c == '}' && x == '{') || 
                    (c == ']' && x == '['))
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};
