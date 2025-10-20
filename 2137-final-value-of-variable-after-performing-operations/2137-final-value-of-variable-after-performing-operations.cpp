class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string &op : operations) {
            if (op[1] == '+') {   // "++X" or "X++"
                X++;
            } else {             // "--X" or "X--"
                X--;
            }
        }
        return X;
    }
};