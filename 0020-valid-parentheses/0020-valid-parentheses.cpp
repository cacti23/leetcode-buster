#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            } 

            if(!st.empty()) {
                if(ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' || ch == ']' && st.top() == '[') {
                    st.pop();
                    continue;
                
                } else {
                    return false;
                }
            }

            // when stack is empty means close brackets are there to be inserted
            return false;


        }

        if(st.empty()) return true;

        return false;
        
    }
};