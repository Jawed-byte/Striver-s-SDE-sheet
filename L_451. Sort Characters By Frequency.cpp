class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>>maxh;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
         mp[s[i]]++;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            maxh.push({i->second,i->first});
        }
        string res="";
        while(maxh.size()>0)
        {
          int freq=maxh.top().first;
          char c=maxh.top().second;
            for(int i=1;i<=freq;i++)
                res+=c;
          maxh.pop();
        }
        return res;
    }
};
