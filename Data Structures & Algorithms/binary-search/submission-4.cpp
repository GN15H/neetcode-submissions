class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int l = 0;
        int r = nums.size()-1;
        int index = 0; 
        do{
            index = l+((r-l)/2);
            if(nums[index] == target) return index; 
            if(nums[index]> target)
                r-=((r-l)/2)+1;
            else
                l+=((r-l)/2)+1;
        }while(r-l>=0);
        return -1;
    }
};
