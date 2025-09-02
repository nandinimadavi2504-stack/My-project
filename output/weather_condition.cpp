#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  // number of test cases

    while (T--) {
        int temp, humidity;
        cin >> temp >> humidity;

        if (temp >= 30 && humidity >= 90) {
            cout << "Hot and Humid" << endl;
        }
        else if (temp >= 30 && humidity < 90) {
            cout << "Hot" << endl;
        }
        else if (temp < 30 && humidity >= 90) {
            cout << "Cool and Humid" << endl;
        }
        else { // temp < 30 && humidity < 90
            cout << "Cool" << endl;
        }
    }

    return 0;
}
