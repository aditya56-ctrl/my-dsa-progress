// brute force
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>pse(n,-1);
        
        for(int i = n-1; i > 0; i--){
            for(int j = i -1; j >=0; j--){
                if(arr[j] < arr[i]){
                    pse[i] = arr[j];
                    break;
                }
            }
        }
        return pse;
    }
};


// optimal
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>pse(n,-1);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            st.push(arr[i]);
            
        }
        return pse;
        
    }
};