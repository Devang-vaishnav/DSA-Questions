class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int rightInd = n-1;
        int leftInd = 0;
        while(leftInd < rightInd){
            ans = max(ans,min(height[leftInd],height[rightInd])*(rightInd-leftInd));
            if(height[leftInd] < height[rightInd]) leftInd++;
            else rightInd--;
        }
        return ans;
    }
};