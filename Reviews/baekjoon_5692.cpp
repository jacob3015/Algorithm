#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 시간 초과 이유 : cin endl
 */
int main() {
    // cin setting
    ios::sync_with_stdio(false);
    cin.tie(0);

    string num;
    vector<int> factorial {1, 1, 2, 6, 24, 120};

    while(true) {
        cin >> num;
        if(num == "0") {
            break;
        }

        int len = num.length();
        int total = 0;
        for(int i = 0; i < len; i++) {
            // ASCII code '0' = 48, '1'=49, ..., '9'=57
            total += (num[i] - '0') * factorial[len - i];
        }
        // endl -> '\n'
        cout << total << '\n';
    }
    
    return 0;
}