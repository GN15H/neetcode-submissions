class Solution {
private:

    int evalAdd(stack<int>& nums){
        int result = 0;
        for(int i=0;i<2;i++){
            result+=nums.top();
            nums.pop();
        }
        return result;
    }

    int evalSub(stack<int>& nums){
        int result = 0;
        result-=nums.top();
        nums.pop();
        result+=nums.top();
        nums.pop();
        return result;
    }
    int evalMult(stack<int>& nums){
        int result = 1;
        for(int i=0;i<2;i++){
            result*=nums.top();
            nums.pop();
        }
        return result;
    }
    int evalDiv(stack<int>& nums){
        double result = 1;
        result/=nums.top();
        nums.pop();
        result*=nums.top();
        nums.pop();
        return (int)result;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> nums;
        for(const string& token: tokens){
            if(token == "+" || token == "*" || token == "-" || token == "/"){
                int eval;
                switch(token[0]){
                    case '+':
                        eval = evalAdd(nums);
                        break;
                    case '-':
                        eval = evalSub(nums);
                        break;
                    case '*':
                        eval = evalMult(nums);
                        break;
                    case '/':
                        eval = evalDiv(nums);
                        break;
                }
                cout<<"numerito "<<eval<<endl;
                nums.push(eval);
            }
            else
                nums.push(stoi(token));
        } 
        return nums.top();
    }
};
