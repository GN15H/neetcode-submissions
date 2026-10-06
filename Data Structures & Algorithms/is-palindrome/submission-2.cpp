class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0; 
        int j = s.size()-1;
        while(i<j){
            while(!isalnum(s[i]) && i < n-1) ++i;
            while(!isalnum(s[j]) && j > 0) --j;
            if(i>=j) break;
            if(((int) s[i]) >= 65 && ((int) s[j]) >= 65){
                if((((int) s[i]) - ((int) s[j])) != 0 && abs(((int) s[i]) - ((int) s[j])) != 32) 
                    return false;
            }else{
                if(((int) s[i]) - ((int) s[j]) != 0) return false;
            }
            ++i; --j;
        }
        return true;
    }
};
