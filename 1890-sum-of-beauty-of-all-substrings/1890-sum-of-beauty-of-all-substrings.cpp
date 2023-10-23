class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            unordered_map<char,int>mp;
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(auto k : mp){
                    if(mx < k.second) mx = k.second;
                    if(mn > k.second){
                        mn = k.second;
                    }
                }
                int temp = mx - mn;
                if(temp > 0) sum += temp;
            }
            cout<<endl;
        }
        return sum;
    }
};