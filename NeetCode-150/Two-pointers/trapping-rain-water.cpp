// here we can see a building can store water if there is taller building on the left and right side 
// and trapperd water at ith index will be min(leftMax, rightMax) -height[i]

// this is the brute force approach 
// class Solution {
//    public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> right(n);
//         int lMax = 0, rMax = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             rMax = max(rMax, height[i]);
//             right[i] = rMax;
//         }
//         int trappedWater=0;
//         for (int i = 0; i < n; i++) {
//             lMax = max(lMax, height[i]);
//             trappedWater += (min(lMax, right[i])-height[i]);
//         }
//         return trappedWater;
//     }
// };

// this is the optimal approach
class Solution {
public:
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int l=0, r=height.size()-1, lmax=0, rmax=0;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax>rmax){
                trappedWater+=(rmax-height[r]);
                r--;
            }else{
                trappedWater+=(lmax-height[l]);
                l++;
            }
        }
        return trappedWater;
    }
};

