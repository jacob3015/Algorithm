#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    string answer = "";

    unordered_map<string, int> par;
    unordered_map<string, int> com;

    for(string s : participant) {
        if(par.count(s)) {
            par[s]++;
        } else {
            par.insert({s, 1});
        }
    }

    for(string s : completion) {
        if(com.count(s)) {
            com[s]++;
        } else {
            com.insert({s, 1});
        }
    }

    for(string s : participant) {
        if(par[s] != com[s]) {
            answer = s;
            break;
        }
    }
    
    return answer;
}