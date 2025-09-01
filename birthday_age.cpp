#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name;
    int year;
    if (!(cin >> name >> year)) return 0;

    const int CURRENT_YEAR = 2020;
    int age = CURRENT_YEAR - year;

    cout << "Happy Birthday " << name << "! Your current age is " << age;
    return 0;
}
