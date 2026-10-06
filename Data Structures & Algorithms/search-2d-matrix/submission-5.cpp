class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lrow = 0;
        int rrow = matrix.size() - 1;
        int index = 0;
        while(lrow<rrow){
            index = lrow+((rrow-lrow)/2);
            if(matrix[index][0] <= target && matrix[index][matrix[index].size()-1] >= target) {
                lrow=index;
                break;
            }
            if(matrix[index][0] > target)
                rrow-=((rrow-lrow)/2)+1;
            else
                lrow+=((rrow-lrow)/2)+1;
        }
        int lcol = 0;
        int rcol = matrix[lrow].size() -1;
        std::cout<<"en donde quedamos? "<<lrow<<" "<<rrow<<std::endl;
        while(lcol<=rcol){
            std::cout<<"escuismi "<<lcol<<" "<<rcol<<std::endl;
            index = lcol+((rcol-lcol)/2);
            if(matrix[lrow][index] == target) return true;
            if(matrix[lrow][index] > target)
                rcol-=(((rcol-lcol)/2)+1);
            else
                lcol+=(((rcol-lcol)/2)+1);
        }
        return false;
    }
};
