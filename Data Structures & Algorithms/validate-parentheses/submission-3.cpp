class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        if(s.size()%2) return false;
        for(const char c: s){
            if((c==')' || c=='}' || c==']') && brackets.empty()) return false;
            if(c == '(' || c == '{' || c == '[' || brackets.empty()){
                brackets.push(c);
                continue;
            }
            const char top = brackets.top();
            if(top == '(' && c != ')') return false;
            if(top == '{' && c != '}') return false;
            if(top == '[' && c != ']') return false;
            brackets.pop();
        }
        return brackets.empty();
    }
};
