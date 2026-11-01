class Solution {
   public:
    int maxArea(vector<int>& heights) {
        // brute force O(n^2)
        // int maxi = 0;
        // for (int i = 0; i < heights.size() - 1; i++) {
        //     int h1 = heights[i];
        //     for (int j = i + 1; j < heights.size(); j++) {
        //         int h2 = heights[j];
        //         maxi= max(maxi, min(h1,h2) * (j-i));
        //     }
        // }
        // return maxi;

        int  i =0, j = heights.size()-1, maxa = 0;
        while(i<j){
            maxa = max((j-i)* min(heights[i], heights[j]), maxa);
            if(heights[i]>heights[j]) j--;
            else i++;
        }
        return maxa;
    }
};
