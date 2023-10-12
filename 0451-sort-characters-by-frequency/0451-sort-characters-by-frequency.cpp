class Solution {
public:
    string frequencySort(string s) {
        if(s.size() < 3) return s;
        unordered_map<char,int>mp;
        for(auto i : s) mp[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto i : mp) pq.push({i.second,i.first});
        string st = "";
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            for(int j = 0; j < i.first; j++) st+=i.second;
        }
        return st;
    }
};