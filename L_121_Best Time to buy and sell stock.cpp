// Method1: O(n^2)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=max(res,prices[j]-prices[i]);
            }
        }
        return res;
    }
};

// Method2: O(n)

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int maxPro=0;
        int minPrice=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            minPrice=min(minPrice,prices[i]);
            maxPro=max(maxPro,prices[i]-minPrice);
        }
        return maxPro;
    }
};
