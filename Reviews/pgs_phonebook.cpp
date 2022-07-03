#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {

    unordered_map<string, int> prefix;

    for(string s : phone_book) {
        prefix[s];
    }

    for(string s : phone_book) {
        for(int i = 1; i <= s.length(); i++) {
            string str = s.substr(0, i);
            if(s != str && prefix.count(str)) {
                return false;
            }
        }
    }
    
    return true;
}