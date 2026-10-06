class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> l (size,0);
        vector<int> r (size,0);
        vector<int> res (size,0);
        int acc_l=1;
        int acc_r=1;
        for(int i=0;i<nums.size();i++){
            acc_l*=nums[i];
            acc_r*=nums[size-i-1];
            l[i]=acc_l;
            r[size-i-1]=acc_r;
        }
        for(const int x: l)
            cout<<x<<" ,";
        cout<<endl;
        for(const int x: r)
            cout<<x<<" ,";
        res[0]=r[1];
        res[size-1]=l[size-2];
        for(int i=1;i<size-1;i++){
            res[i] = l[i-1] * r[i+1];
        }
        return res;
    }
};
