#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;

    queue<int> time;

    int psize = progresses.size();
    for(int i = 0; i < psize; i++) {
        int diff = 100 - progresses[i];
        if(diff % speeds[i] != 0) {
            diff += speeds[i];
        }
        time.push(diff/speeds[i]);
    }

    int pre = time.front();
    int num = 0;
    while(!time.empty()) {
        if(pre >= time.front()) {
            num++;
            time.pop();
        }
        else {
            answer.push_back(num);
            pre = time.front();
            num = 0;
        }
    }

    if(num != 0) {
        answer.push_back(num);
    }

    return answer;
}