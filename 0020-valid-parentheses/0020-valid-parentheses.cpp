class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        int n = s.length();
        
        // start inserting brackets into stack 
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(!st.empty()) {
                    if(ch == ')' && st.top() == '(') {
                        st.pop();
                    } else if(ch == '}' && st.top() == '{') {
                        st.pop();
                    } else  if(ch == ']' && st.top() == '[') {
                        st.pop();
                    } else {
                        st.push(ch);
                    }
                } else {
                    st.push(ch);
                }
            }  
        }
        
        if(st.empty()) return true;
        
        return false;
    }
};

// tc -> O(n)
// sc -> O(n)