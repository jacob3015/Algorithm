#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    // cin setting
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<int> vec;

    while(n > 1) {
        vec.push_back(n % 2);
        n /= 2;
    }

    vec.push_back(n);

    string result = "";
    
    while(!vec.empty()) {
        result += to_string(vec.back());
        vec.pop_back();
    }

    cout << result << '\n';
}