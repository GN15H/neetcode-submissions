class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        pair<int,int> letters[127] = {{0,0}};
        int l=0,r=0;
        int longest=0;
        while(r<s.size()){
            if(letters[s[r]].first && letters[s[r]].second >= l){
                l = letters[s[r]].second+1;
                letters[s[r]].second=r;
            }else{
                letters[s[r]]={1, r};
                longest = max(longest,r-l+1);
            }
            ++r;
            continue;
        }
        return longest;
    }
};
