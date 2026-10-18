// 17. Letter Combinations of a Phone Number

class Solution {
    void solve(string digits, string output, int idx, vector<string>& ans, string mapp[]){
        if(idx==digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[idx] - '0';
        string value = mapp[number];
        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(digits,output,idx+1,ans,mapp);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output = "";
        int idx = 0;
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,idx,ans,mapp);
        return ans;

    }
};