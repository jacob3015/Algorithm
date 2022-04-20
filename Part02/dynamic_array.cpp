#include <iostream>

using namespace std;

int main()
{
    // Dynamic array example

    int* ptr = new int[3];
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    for (int i = 0; i < 3; i++) {
        cout << ptr[i] << endl;
    }

    delete [] ptr;
    ptr = nullptr;
}