class Solution {
	public:
	vector<int> calculateSpan(vector<int>& arr) {
		vector<int>ans(arr.size());
		stack<int>s;
		
		for (int i = 0; i < arr.size(); i++) {
			while (!s.empty() && arr[s.top()] <= arr[i]) {
				s.pop();
			}
			if (s.empty())
				ans[i] = i + 1;
			else
				ans[i] = i - s.top();
			
			s.push(i);
		}
		
		return ans;
	}
};
