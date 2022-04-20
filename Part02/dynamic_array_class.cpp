#include <iostream>

using namespace std;

// 정수 타입 동적 배열을 구현한 클래스
// Example:
//      DynamicArray da(5);
//      for (int i = 0; i < da.size(); i++) {
//         cout << da[i] << endl;
//      }
class DynamicArray
{
private:
    // 배열의 크기
    unsigned int sz;

    // 배열 포인터
    int* arr;

public:
    // Consturctor.
    // 입력 n으로 배열의 크기를 초기화하고, 새로운 배열을 메모리에 할당해 배열 포인터를 초기화한다.
    explicit DynamicArray(int n);

    // Destructor.
    // 메모리에 할당된 배열을 delete한다.
    ~DynamicArray();

    // 배열의 크기를 반환한다.
    unsigned int size();

    // Array element reference를 반환한다.
    int& operator[] (const int i);

    // 변경할 수 없는 array element reference를 반환한다.
    const int& operator[] (const int i) const;
};

DynamicArray::DynamicArray(int n) : sz(n)
{
    arr = new int[sz] {};
}

DynamicArray::~DynamicArray()
{
    delete [] arr;
}

unsigned int DynamicArray::size()
{
    return sz;
}

int& DynamicArray::operator[] (const int i)
{
    return arr[i];
}

const int& DynamicArray::operator[] (const int i) const
{
    return arr[i];
}

int main()
{
    DynamicArray da(5);
    da[0] = 10;
    da[1] = 20;
    da[2] = 30;

    for (int i = 0; i < da.size(); i++) {
        cout << da[i] << endl;
    }
}