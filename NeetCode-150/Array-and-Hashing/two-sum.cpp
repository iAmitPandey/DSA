class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // this is the brute force we are checking for every element 
        // for(int i=0; i<nums.size()-1; i++){
        //     int rem = target-nums[i];
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[j]==rem) return {i,j};
        //     }
        // }
        // return {};

        // we can use an map to store the indices
        // the mapping will be element->index
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            int rem = target-nums[i];
            if(mp.contains(rem)) return {mp[rem], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
