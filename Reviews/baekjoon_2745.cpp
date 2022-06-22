#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string number;
    int base;

    cin >> number;
    cin >> base;

    int len = number.length();
    int total = 0;

    // ASCII - A : 65, Z : 90, 0 : 48, 9 : 57
    for(int i = 0; i < len; i++) {
        int num = number[i];
        if(num < 60) {
            num -= '0';
        } else {
            num -= 'A';
            num += 10;
        }
        total += num * pow(base, len - (i + 1));
    }

    cout << total << '\n';

    return 0;
}