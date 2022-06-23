#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector<string> answer;

    for(int i = 0; i < n; i++) {
        bitset<16> bit1 (arr1[i]);
        bitset<16> bit2 (arr2[i]);

        string bit_string = (bit1 | bit2).to_string().substr(16-n, n);
        string result = "";
        for(char c : bit_string) {
            if(c == '1') {
                result += '#';
            } else {
                result += ' ';
            }
        }
        answer.push_back(result);
    }

    return answer;
}