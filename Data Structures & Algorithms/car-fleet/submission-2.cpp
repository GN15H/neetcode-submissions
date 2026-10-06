class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> arr(position.size());
        for(int i=0; i<size; i++){
            arr[i] = {position[i], speed[i]};
        }
        sort(arr.begin(), arr.end());
        int fleets = 0;
        stack<pair<int,int>> s;
        pair<int,int> actual = {position[0]-1,0};
        for(const pair<int,int>& x: arr){
            cout<<"{"<<x.first<<"-"<<x.second<<"}"<<", ";
        }
        for(const pair<int,int>& x: arr){
            while(!s.empty() && 
            ((double) s.top().second)/((double)(target-s.top().first)) >=
            ((double) x.second)/((double)(target-x.first))
            )
            s.pop();
            s.push(x);
        }
        return s.size();
    }
};
