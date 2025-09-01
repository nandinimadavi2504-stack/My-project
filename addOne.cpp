#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    // Taking input
    cin >> name >> age;

    // Output result
    cout << "Hello " << name << "! Next year, you will be " << (age + 1) << " years old" << endl;

    return 0;
}
