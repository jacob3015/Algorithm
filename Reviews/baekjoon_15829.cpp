#include <iostream>
#include <string>

using namespace std;

int solution(int size, string value) {

    long long total = 0;
    long long exp = 0;
    long long r = 1;
    long long M = 1234567891;

    // H = sum(ai * 31^i) % M

    for(char c : value) {
        long long a = c - 'a';
        a++;
        a %= M;

        r *= 31;
        if(exp++ == 0) {
            r = 1;
        }
        r %= M;

        total += a * r;
    }

    return total % M;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int size;
    string value;

    cin >> size;
    cin >> value;

    cout << solution(size, value) << '\n';

    return 0;
}