#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // 테스트 케이스의 개수 T를 입력 받는다.
    int T;
    cin >> T;

    // 답을 저장할 vector를 초기화한다.
    vector<int> answer(T);

    for (int& result : answer) {

        // a와 b를 입력 받는다.
        int a, b;
        cin >> a >> b;

        // b가 4의 배수인 경우와 a^b이 10의 배수인 경우를 고려해 삼항연산자로 처리한다.
        b = b % 4 ? b % 4 : 4;
        result = (int)pow(a % 10, b) % 10;
        result = result ? result : 10;
    }

    // 답을 출력한다.
    for (const int& a : answer) {
        cout << a << endl;
    }

    return 0;
}