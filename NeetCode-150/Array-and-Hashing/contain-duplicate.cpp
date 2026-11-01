
// here we can map every element to its frequency and check if any element has a frequency greater than 1. If yes, then we have a duplicate.

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for (auto x : freq) {
            if (x.second > 1) {
                return true;
            }
        }

        return false;
    }
};