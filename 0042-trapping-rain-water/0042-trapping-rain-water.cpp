class Solution {
public:

    vector<int> leftBoundary(vector<int>& height , int n){
        vector<int> left;
        left.push_back(-1);
        int mx = INT_MIN;
        for(int i = 1; i < n; i++){
            mx = max(mx,height[i-1]);
            left.push_back(mx);
        }
        return left;
    }

    vector<int> rightBoundary(vector<int>& height, int n){
        vector<int> right;
        right.push_back(-1);
        int mx = INT_MIN;
        for(int i = n-2; i >= 0; i--){
            mx = max(mx,height[i+1]);
            right.push_back(mx);
        }
        reverse(right.begin(),right.end());
        return right;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left = leftBoundary(height,n);
        vector<int> right = rightBoundary(height,n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(left[i] == -1 || right[i] == -1) continue;
            int water = min(left[i],right[i]) - height[i];
            if(water > 0) sum += water;
        }
        return sum;
    }
};