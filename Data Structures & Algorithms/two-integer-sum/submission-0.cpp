class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> m;
        const int size = nums.size();
        for(int i=0;i<size;i++)
            m.insert({target-nums[i],i});
        for(int i=0;i<size;i++)
            if(m.find(nums[i]) != m.end())
                if(m[nums[i]] != i)
                    if(i < m[nums[i]])
                        return {i,m[nums[i]]};
                    else
                        return {m[nums[i]],i};
        return {0,0};
    }
};
