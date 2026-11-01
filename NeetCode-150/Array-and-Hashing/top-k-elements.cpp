class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums) freq[num]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it:freq){
            bucket[it.second].push_back(it.first);
        }
        vector<int> topK;
        for(int i = bucket.size()-1; i>=0; i--){
            for(auto it: bucket[i]){
                topK.push_back(it);
                k--;
                if(k==0) return topK;
            }
        }
        return {};
    }
};

