class MyQueue {
public:
    stack<int>s;
    stack<int>ss;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.size()==0)
            s.push(x);
        else{
            while(s.size()>0){
                ss.push(s.top());
                s.pop();
            }
            s.push(x);
            while(ss.size()>0){
                s.push(ss.top());
                ss.pop();
            }
        }
    }
    
    int pop() {
        int temp=s.top();
        s.pop();
        return temp;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.size()==0;
    }
};
