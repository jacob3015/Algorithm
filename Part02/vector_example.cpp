#include <vector>
#include <string>

using namespace std;

// C++ std::vector 정리
int main()
{
    // 1차원 vector 초기화 방법
    vector<int> vec1; // empty vector
    vector<int> vec2(10); // 0 0 0 0 0 0 0 0 0 0
    vector<int> vec3(10, 1); // 1 1 1 1 1 1 1 1 1 1
    vector<int> vec4 {10, 20, 30, 40, 50}; // 10 20 30 40 50
    vector<int> vec5(vec4); // 10 20 30 40 50
    vector<int> vec6(vec4.begin(), vec4.begin() + 3); // 10 20 30

    // 2차원 vector 초기화 방법
    vector<vector<int>> mat1(2, vector<int>(3, 1));
    // 1 1 1
    // 1 1 1
    vector<vector<int>> mat {
        {1, 2, 3},
        {4, 5, 6}
    };
    // 1 2 3
    // 4 5 6

    vector<string> vec;

    // push_back()은 임시 string을 생성해 "hello"를 임시 string에 복사한 뒤, 임시 string을 vector에 전달해 삽입한다.
    vec.push_back("hello");

    // emplace_back()은 임시 string을 생성하지 않고 vector 내부에서 "hello" 값을 갖는 string 객체를 생성한 뒤 vector에 삽입한다. 
    vec.emplace_back("hello");

    // emplace_back() 잘못된 사용법
    string str = "hello";
    vec.emplace_back(str);

    // emplace_back() 올바른 사용법
    vec.emplace_back("hello");

    return 0;
}