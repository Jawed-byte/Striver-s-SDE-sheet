class MinStack {
public:
    vector<int>v;
    stack<int>s;
    stack<int>ss;
    
    MinStack() {
        
    }
    
    void push(int val) 
    {
       s.push(val);
       if(ss.empty() || ss.top()>=val)
           ss.push(val);
    }
    
    int pop() 
    {
        if(s.empty())
           return -1;
        int ans=s.top();
          s.pop();
        if(ss.top()==ans)
            ss.pop();
          return ans;
    }
    
    int top() 
    {
        return s.top();
    }
    
    int getMin() 
    {
        if(ss.empty())
            return -1;
        return ss.top();
    }
};
