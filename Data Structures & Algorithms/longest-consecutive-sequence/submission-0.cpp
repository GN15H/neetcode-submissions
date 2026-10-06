class Solution {
public:
    void print_map(const unordered_map<int,int>& m){
        for(const pair<int,int>& x: m)
            cout<<"<"<<x.first<<","<<x.second<<"> ";
        cout<<endl;
    }

    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        int size = nums.size();
        unordered_map<int,int> seq;
        for(const int n: nums){
            if(seq.find(n) != seq.end()) continue;
            if(seq.find(n-1) == seq.end() && seq.find(n+1) == seq.end()){
                seq.insert({n,1});
                continue;
            }
            if(seq.find(n+1) == seq.end() && seq.find(n-1) != seq.end()){
                int sum=0;
                seq.insert({n, seq[n-1]+1});
                sum = seq[n-1];
                seq[n-1-(sum-1)] += 1;
                continue;
            }
            if(seq.find(n-1) == seq.end() && seq.find(n+1) != seq.end()){
                int sum=0;
                seq.insert({n, seq[n+1]+1});
                sum = seq[n+1];
                seq[n+1+(sum-1)] += 1;
                continue;
            }
            if(seq.find(n-1) != seq.end() && seq.find(n+1) != seq.end()){
                int l=seq[n-1];
                int r=seq[n+1];
                seq[n-1-(l-1)] += r+1;
                seq[n+1+(r-1)] += l+1;
                seq.insert({n,1});
            }
        }
        int max_seq = 0;
        for(const pair<int,int>& n: seq){
            max_seq = std::max(max_seq, n.second);
        }
        return max_seq;
    }
};
