class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       if(temperatures.size() == 1) return {0};
       stack<pair<int,int>> indices;
       int size = temperatures.size();
       vector<int> result(size, 0);
       int previous = temperatures[0];
       for(int i=0; i<size; i++){
            if(temperatures[i] > previous){
                while(!indices.empty() && indices.top().first < temperatures[i]){
                    result[indices.top().second] = i-indices.top().second;
                    indices.pop();
                }
            }
            indices.push({temperatures[i], i});
            previous=temperatures[i];
       }
       return result;
    }
};
