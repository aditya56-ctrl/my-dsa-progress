//tc O(1)
//sc O(n)
class MinStack {
public:
    stack<pair<int,int>>s;  //pair<val,minEl>
    MinStack() {
        
    }
    
    void push(int value) {
      if(s.empty()){
        s.push({value,value});
      }else{
        int minVal = min(value,s.top().second);
        s.push({value,minVal});
      }  
    }
    
    void pop() {
       s.pop(); 
    }
    
    int top() {
       return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};