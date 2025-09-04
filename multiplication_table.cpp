#include <iostream>

using namespace std; // This line brings the standard namespace into scope.

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= 10; ++i) {
        cout << n * i;
        if (i < 10) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
