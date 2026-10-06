class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        const int n = s.size();
        std::unordered_map<char, int> letters;        
        for(const char c: s)
            if(letters.find(c) != letters.end())
                letters[c] += 1;
            else
                letters.insert({c,1});
        for(const char c: t)
            if(letters.find(c) == letters.end())
                return false;
            else
                letters[c]-=1;
        for(const std::pair<char,int>& it: letters)
            if(it.second != 0) return false;
        return true;
    }
};
