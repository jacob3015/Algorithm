#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer(prices.size());
    stack<int> sta;
    int size = prices.size();

    for(int i=0;i<size;i++){
        while(!sta.empty()&&prices[sta.top()]>prices[i]){
            answer[sta.top()] = i-sta.top();
            sta.pop();
        }
        sta.push(i);
    }

    while(!sta.empty()){
        answer[sta.top()] = size-sta.top()-1;
        sta.pop();
    }
    
    return answer;
}