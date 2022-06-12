class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minh;
    priority_queue<int>maxh;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(maxh.size()==0){
          maxh.push(num);
          return;
      }
      if(maxh.size()==minh.size()){
          if(minh.top()<num){
              maxh.push(minh.top());
              minh.pop();
              minh.push(num);
          }
          else
          {
              maxh.push(num);
          }
      }
        else{
            if(maxh.top()>num){
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(num);
            }
            else{
                minh.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()){
            double res=minh.top()+maxh.top();
            return res/2;
        }
        else
        {
            return maxh.top();
        }
    }
};
