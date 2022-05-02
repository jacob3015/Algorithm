#include <iostream>

using namespace std;

struct Node
{
    // 저장한 값
    int data;

    // 다음 노드를 가리키는 포인터
    Node* next;

    Node(int d, Node* n) : data(d), next(n) {}
};

class LinkedList
{
private:
    // 첫번째 노드를 가리키는 포인터
    Node* head;

    // 마지막 노드를 가리키는 포인터
    Node* tail;

    // 노드 개수
    int size;

public:

    LinkedList();

    // 동적 할당된 모든 노드를 삭제한다.
    ~LinkedList();

    // 리스트 맨 앞에 노드를 삽입한다.
    void push_front(int val);

    // 리스트 맨 뒤에 노드를 삽입한다.
    void push_back(int val);

    // 리스트 맨 앞의 노드를 삭제한다.
    void pop_front();

    // 빈 리스트인지 확인한다.
    bool empty() const;

    // 리스트의 모든 노드를 head부터 tail순으로 출력한다.
    void print_all() const;

    // 리스트의 노드 개수를 출력한다.
    void print_size() const;
};

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0)
{
    cout << "Called Constructor" << endl;
}

LinkedList::~LinkedList()
{
    cout << "Called Destructor" << endl;
    while (!this->empty()) {
        this->pop_front();
    }
}

/**
 * 리스트가 비어 있다면, head와 tail이 새로운 노드를 가리키도록 하고
 * 리스트가 비어 있지 않다면, head만 새로운 노드를 가리키도록 하고
 * head가 가리키고 있던 노드는 새로운 노드가 가리키도록 한다.
*/
void LinkedList::push_front(int val)
{
    Node* node = new Node(val, nullptr);

    this->empty() ? tail = node : node->next = head;
    head = node;

    size++;
}

/**
 * 리스트가 비어 있다면, head와 tail이 새로운 노드를 가리키도록 하고
 * 리스트가 비어 있지 않다면, 마지막 노드가 새로운 노드를 가리키도록 하고
 * tail은 새로운 노드를 가리키도록 한다.
*/
void LinkedList::push_back(int val)
{
    Node* node = new Node(val, nullptr);

    this->empty() ? head = node : tail->next = node;
    tail = node;

    size++;
}

/**
 * 리스트가 비어 있지 않다면, 첫번째 노드를 가리키는 노드 포인터를 생성한다.
 * 리스트에 남아있는 노드가 1개면, head와 tail이 nullptr를 가리키도록 하고
 * 아니라면, head만 다음 노드를 가리키도록 한다.
 * 노드 포인터가 가리키고 있는 노드는 삭제한다.
*/
void LinkedList::pop_front()
{
    if (this->empty()) {
        return;
    }

    Node* temp = head;
    if (head == tail) {
        tail = temp->next;
    }
    head = temp->next;
    delete temp;

    size--;
}

bool LinkedList::empty() const
{
    return head == nullptr;
}

void LinkedList::print_all() const
{
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << ", ";
        curr = curr->next;
    }
    cout << endl;
}

void LinkedList::print_size() const
{
    cout << "List size : " << this->size << endl;
}

int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();
    ll.print_size();

    ll.pop_front();
    ll.print_all();
    ll.print_size();

    ll.push_back(15);
    ll.push_back(25);
    ll.print_all();
    ll.print_size();
    return 0;
}