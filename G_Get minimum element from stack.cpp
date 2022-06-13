lass Solution{
    int minEle;
    stack<int> s;
    public:
       int getMin(){
           if(s.size()==0)
            return -1;
           return minEle;
       }
       int pop(){
           int temp;
           if(s.size()==0)
            return -1;
           else
           {
               if(s.top()>=minEle)
               {
                 temp=s.top();
                 s.pop();
               }
               else
               {
                 temp=minEle;
                 minEle=2*minEle-s.top();
                 s.pop();
               }
           }
           return temp;
       }
       
       /*push element x into the stack*/
       void push(int x){
          if(s.empty())
          {
              s.push(x);
              minEle=x;
          }
          else
          {
              if(x>=minEle)
                s.push(x);
              else
              {
                  s.push(2*x-minEle);
                  minEle=x;
              }
          }
       }
};
