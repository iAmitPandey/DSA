// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> result;
//         for(int i =0; i<nums.size(); i++){
//             set<int> st;
//             for(int j =i+1; j<nums.size(); j++){
//                 int sum = -(nums[i]+nums[j]);
//                 if(st.find(sum) != st.end()){
//                     vector<int> triplate = {nums[i], nums[j], sum};
//                     sort(triplate.begin(), triplate.end());
//                     result.insert(triplate);
//                 }
//                 st.insert(nums[j]);
//             }
//         }
//         return vector<vector<int>>(result.begin(), result.end());
//     }
// };
// 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i =0; i<n; i++){
            int rem = -nums[i];
            int l = i+1, r = n-1;
            while(l<r){
                int sum = nums[l]+nums[r];
                if(sum<rem)l++;
                else if(sum>rem)r--;
                else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    st.insert(triplet);
                    while(l<r && nums[l]==triplet[1])l++;
                    while(l<r && nums[r]==triplet[2])r--;
                }
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return vector<vector<int>> (st.begin(), st.end());
    }
};
