#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Input 3-digit number

    int reversed = 0;
    
    // Reverse the number
    while(n != 0) {
        int digit = n % 10;        // Get last digit
        reversed = reversed * 10 + digit; // Append it
        n = n / 10;                // Remove last digit
    }

    cout << reversed << endl;      // Output reversed number
    return 0;
}
