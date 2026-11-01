class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // simple
        // vector<int> res(nums.size());
        // int prefix = 1;
        // for(int i=0; i<nums.size(); i++){
        //     res[i] = prefix;
        //     prefix *= nums[i];
        // }
        // int postfix = 1;
        // for(int i=nums.size()-1; i>=0; i--){
        //     res[i] *= postfix;
        //     postfix *= nums[i];
        // }
        // return res;

        int prod= 1, zeroCount = 0, n = nums.size();
        vector<int> sol;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0) prod*=nums[i];
            else zeroCount++;
        }
        if(zeroCount>1) return vector<int>(n, 0);
        for(int i = 0; i<n; i++){
            if(zeroCount>0) {
                if(nums[i] ==0) sol.push_back(prod);
                else sol.push_back(0);
            }else{
                sol.push_back(prod/nums[i]);
            }
        }
        return sol;
    }
};
