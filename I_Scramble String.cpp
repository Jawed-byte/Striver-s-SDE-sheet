/* Recursive

int Solution::isScramble(const string a, const string b) {
    if(a.compare(b)==0)
     return 1;
    if(a.size() <=1)
     return 0;
    int n = a.size();
    int f = 0;
    for(int i=1;i<=n-1;i++){
        int cond1 = (isScramble(a.substr(0,i),b.substr(n-i,i))==1) 
                                        && 
                    (isScramble(a.substr(i,n-i),b.substr(0,n-i))==1);
        int cond2 = (isScramble(a.substr(0,i),b.substr(0,i))==1) 
                                        && 
                    (isScramble(a.substr(i,n-i),b.substr(i,n-i))==1);
        if(cond1 || cond2){
            f = 1;
            break; 
        }            
    }
    return f;
}

*/

// Memoization

unordered_map<string, int> mp;
int Solution::isScramble(const string a, const string b) {
    if(a.compare(b)==0)
     return 1;
    if(a.size() <=1)
     return 0;
    string key = a;
    key.push_back('_');
    key.append(b);
    if(mp.find(key)!=mp.end())
     return mp[key];
    int n = a.size();
    int f = 0;
    for(int i=1;i<=n-1;i++){
        int cond1 = (isScramble(a.substr(0,i),b.substr(n-i,i))==1) 
                                        && 
                    (isScramble(a.substr(i,n-i),b.substr(0,n-i))==1);
        int cond2 = (isScramble(a.substr(0,i),b.substr(0,i))==1) 
                                        && 
                    (isScramble(a.substr(i,n-i),b.substr(i,n-i))==1);
        if(cond1 || cond2){
            f = 1;
            break; 
        }            
    }
    return mp[key] = f;
}
