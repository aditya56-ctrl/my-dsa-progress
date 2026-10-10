class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        for (int i = 0; i < n; i++) {
            int money = bills[i];
            if (money == 5) {
                five++;
            } else if (money == 10) {
                if (five == 0)
                    return 0;
                five--;
                ten++;
            } else if (money == 20) {
                if (ten > 0 && five >0) {
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five -= 3;
                }
                else return 0;
            }
        }
        return 1;
    }
};