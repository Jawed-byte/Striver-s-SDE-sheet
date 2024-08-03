//  Approach 1:
    Time: O(n^2)
    Space: O(1)
        
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

//  Approach 2:
    Time: O(n)
    Space: O(1)

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
