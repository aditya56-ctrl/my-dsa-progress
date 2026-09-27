// optimal Solution
// TC O(2n)
// SC O(2n)
class Solution {
	public:
	vector<int> nextLargerElement(vector<int>& arr) {
		
		int n = arr.size();
		vector<int>ans(n);
		stack<int>s;
		
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && s.top()<=arr[i]) {
				s.pop();
			}
			if(s.empty()) ans[i] = -1;
			else ans[i] = s.top();
			
			s.push(arr[i]);
		}
		return ans;
	}
};


// brute force will be using 2 loops tc O(n^2)
