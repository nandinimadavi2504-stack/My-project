#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  // number of test cases

    while (T--) {
        int L1, L2, L3;
        cin >> L1 >> L2 >> L3;

        // Triangle inequality check (using >=)
        if ((L1 + L2 >= L3) && (L1 + L3 >= L2) && (L2 + L3 >= L1)) {
            int C = L1 + L2 + L3;  // circumference
            cout << C << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
