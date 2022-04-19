#include <iostream>

using namespace std;

int main()
{
    // C style array example
    
    int scores[5] = {50, 60, 70, 80, 90};

    int sz = sizeof(scores) / sizeof(int);

    int sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += scores[i];
    }

    float mean = (float) sum / sz;

    cout << "Mean score: " << mean << endl;
}