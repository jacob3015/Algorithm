#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // 입력 vector
    vector<int> prices {1, 2, 3, 2, 3};

    // 결과 vector
    vector<int> answer;

    // 입력 vector의 index를 저장하는 index vector 초기화
    vector<int> index;
    for(int i = prices.size()-1; i > -1; i--) {
        index.push_back(i);
    }

    // index vector의 front와 back을 iterator처럼 사용해 결과 값 도출
    while(!index.empty()) {
        int start = index.back();
        for(int end = start; end <= index.front(); end++) {
            if(prices[start] > prices[end] || end == index.front()) {
                answer.push_back(end - start);
                break;
            }
        }
        index.pop_back();
    }

    // 결과 vector 출력
    for(int i : answer) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}