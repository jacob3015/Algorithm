#include <iostream>
#include <array>

using namespace std;

int main()
{
    // Cpp style array example

    array<int, 5> scores = {50, 60, 70, 80, 90};

    int sum = 0;
    for (const int& s : scores) {
        sum += s;
    }

    float mean = (float) sum / scores.size();

    cout << "Mean score : " << mean << endl;
}