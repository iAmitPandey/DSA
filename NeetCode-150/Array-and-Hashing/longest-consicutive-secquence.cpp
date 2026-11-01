class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi=0;
        for(int num:st){
            if(st.find(num-1)!=st.end())continue;
            int currMax = 0, currNum=num;
            while(st.find(currNum)!=st.end()){
                currNum++;
                currMax++;
            }
            maxi = max(currMax, maxi);
        }
        return maxi;

        // unordered_map<int, int> mp;
        // int res = 0;

        // for (int num : nums) {
        //     if (!mp[num]) {
        //         mp[num] = mp[num - 1] + mp[num + 1] + 1;
        //         mp[num - mp[num - 1]] = mp[num];
        //         mp[num + mp[num + 1]] = mp[num];
        //         res = max(res, mp[num]);
        //     }
        // }
        // return res;
    }
};
