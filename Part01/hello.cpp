#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "wordl!", "Finish", "dev", "settings."};

    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;
}