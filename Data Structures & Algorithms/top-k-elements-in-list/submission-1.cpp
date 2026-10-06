class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> freq;
       for(const int n: nums){
            freq[n] += 1;
       } 
       vector<pair<int,int>> res;
       for(const pair<int,int>& it: freq){
            res.push_back(it);
       }
       sort(res.begin(), res.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second;
       });
       vector<int> result(k,0);
       for(int i=0;i<k;i++){
            result[i] = res[i].first;
       }
       return result;
    }
};
