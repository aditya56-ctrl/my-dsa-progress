//brute force
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                int idx = j % n;
                if (nums[idx] > nums[i]) {
                    ans[i] = nums[idx];
                    break;
                } 
            }
        }
        return ans;
    }
};



//optimal 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            int idx = i % n;

            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[idx] = st.top();
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};