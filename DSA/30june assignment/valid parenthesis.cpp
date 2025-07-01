class Solution {
public:
    bool isValid(string s) {
        stack<char> st; char c;
        for(char c: s)
        {
            // c = s[i];
            if(c=='(' || c=='[' || c=='{')
            {
                st.push(c);
                continue;
            }
            else if(c==')' || c==']' || c=='}')
            {
                if(st.empty())
                    return false;
                if(c==')')
                {
                    if(st.top()!='(')
                        return false;
                }
                if(c==']')
                {
                    if(st.top()!='[')
                        return false;
                }
                if(c=='}')
                {
                    if(st.top()!='{')
                        return false;
                }
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};