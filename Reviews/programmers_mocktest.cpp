#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {

    vector<int> answer;

    vector<int> answer1 {1, 2, 3, 4, 5};
    vector<int> answer2 {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> answer3 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    auto bp1 = answer1.begin();
    auto ep1 = answer1.end();

    auto bp2 = answer2.begin();
    auto ep2 = answer2.end();

    auto bp3 = answer3.begin();
    auto ep3 = answer3.end();

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    

    int size = answers.size();

    for(int i = 0; i < size; i++) {
        if(bp1 == ep1) {
            bp1 = answer1.begin();
        }
        if(bp2 == ep2) {
            bp2 = answer2.begin();
        }
        if(bp3 == ep3) {
            bp3 = answer3.begin();
        }

        if(*bp1++ == answers[i]) {
            count1++;
        }
        if(*bp2++ == answers[i]) {
            count2++;
        }
        if(*bp3++ == answers[i]) {
            count3++;
        }
    }

    vector<int> count {count1, count2, count3};
    int max = *max_element(count.begin(), count.end());
    for(int i = 1; i < 4; i++) {
        if(count[i-1] == max) {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;

}