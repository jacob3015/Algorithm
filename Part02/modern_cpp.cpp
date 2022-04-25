#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <algorithm>

// using namespace example
using namespace std;

// using alias declaration examples
using uint = unsigned int;
using pis = pair<int, string>;
using da10 = double[10];
using func = void(*)(int);

// using template alias example
template<typename T>
using matrix1d = vector<T>;

// auto 사용 예시를 위한 function
vector<int> odds() { return {1, 3, 5, 7, 9}; }

// using 사용 예시를 위한 function
void my_function(int n) { cout << n << endl; }

// lambda expression 사용 예시를 위한 구조체
struct Person
{
    string name;
    int age;

    // std::vector emplace_back 사용을 위한 constructor
    Person(string n, int a) : name(n), age(a) {}
};


int main()
{
    // 시작 시간
    auto start = chrono::system_clock::now();

    // auto examples
    auto a1 = 10; // int
    auto a2 = 3.14f; // float
    auto a1 = 10; // int
    auto a2 = 3.14f; // float
    auto a3 = "hello"; // const char*
    auto a4 = "hello"s; // string
    auto a5 = sqrt(2.0); // double
    auto a6 = odds(); // vector<int>
    auto a7 = a6.begin(); // vector<int>::iterator
    auto lambda = [](int x) { return x * 2; };

    // using examples
    da10 arr {};
    matrix1d<float> vec(3);
    func fp = &my_function;

    vector<int> numbers {10, 20, 30};

    // range-based for examples, n에 numbers의 원소가 복사됩니다.
    for (int n : numbers) {
        cout << n << endl;
    }

    // n에 numbers의 원소를 참조형으로 가져옵니다.
    for (auto& n : numbers) {
        cout << n << endl;
    }

    // n에 numbers의 원소를 읽기 전용 참조형으로 가져옵니다.
    for (const auto& n : numbers) {
        cout << n << endl;
    }

    // range-based for is same as below
    for (auto iter = numbers.begin(); iter < numbers.end(); iter++) {
        cout << *iter << endl;
    }

    // lambda expression 변수 선언
    auto square = [](double a) { return a * a; };
    cout << square(1.414) << endl;

    vector<Person> students;
    students.emplace_back("Kim", 20);
    students.emplace_back("Park", 27);
    students.emplace_back("Lee", 22);

    // 정렬 함수의 조건으로 lambda expression 사용 예시
    sort(students.begin(), students.end(), [](const Person& p1, const Person& p2) { return p1.age < p2.age; });

    for (const auto& s : students) {
        cout << s.name << ", " << s.age << endl;
    }

    // 완료 시간
    auto end = chrono::system_clock::now();

    // 경과 시간
    auto msec = chrono::duration<double>(end - start).count() * 1000;

    cout << "Elapsed time : " << msec << "msec" << endl;

    return 0;
}