#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> card, queue<int> find) {
    vector<int> answer;

    sort(card.begin(), card.end());
    while(!find.empty()) {
        auto upper = upper_bound(card.begin(), card.end(), find.front());
        auto lower = lower_bound(card.begin(), card.end(), find.front());
        answer.push_back(upper - lower);
        find.pop();
    }

    return answer;
}

int main() {
    int N;
    vector<int> card;
    int M;
    queue<int> find;

    cin >> N;
    int num = 0;
    for(int i = 0; i < N; i++) {
        cin >> num;
        card.push_back(num);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> num;
        find.push(num);
    }

    vector<int> answer = solution(card, find);
    for(int i : answer) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}