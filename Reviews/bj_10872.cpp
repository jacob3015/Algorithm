#include <iostream>
#include <vector>

using namespace std;

int main() {

    // cin setting
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> result(13);

    result[0] = 1;
    result[1] = 1;

    for(int i = 2; i < 13; i++) {
        result[i] = result[i-1] * i;
    }

    cout << result[n] << '\n';
    
}