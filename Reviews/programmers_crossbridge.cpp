#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    // 다리가 지탱하고 있는 무게
    int bridge_weight = 0;

    // 트럭 큐
    queue<int> truck;
    for(int i : truck_weights) {
        truck.push(i);
    }

    // 다리 큐
    queue<int> bridge;

    while(!truck.empty() || !bridge.empty()) {
        while(bridge.size() < bridge_length) {
            if(truck.empty()) {
                break;
            }
            // 다리에 올릴 수 있는 트럭이 있으면 다리에 올린다.
            if(bridge_weight + truck.front() <= weight) {
                bridge.push(truck.front());
                bridge_weight += truck.front();
                truck.pop();
            }
            // 다리에 트럭을 올릴 수 없는 경우 시간 계산과 다리 무게 계산을 위해 0을 push한다.
            else {
                bridge.push(0);
            }
            answer++;
        }
        if(bridge.empty()) {
            break;
        }
        // 다리가 꽉 차면 다리에서 트럭을 내린다.
        bridge_weight -= bridge.front();
        bridge.pop();
    }

    // 마지막에 다리에 올라간 트럭이 다리를 지나는 시간을 추가한다.
    answer += bridge_length;

    return answer;
}