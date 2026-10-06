class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> duplicates;
        for(const int n: nums){
            if(duplicates.find(n) != duplicates.end())
                return true;
            duplicates.insert(n);
        }
        return false;
    }
};