#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* nptr;

    Node(int d, Node* np) : data(d), nptr(np) {}
};

class LinkedList
{
private:
    Node* head;

public:

    // 생성자
    LinkedList();

    // 소멸자, 동적 할당된 리스트의 모든 노드를 삭제한다.
    ~LinkedList();

    // 리스트 맨 앞에 노드를 삽입한다.
    void push_front(int val);

    // 리스트 맨 앞의 노드를 삭제한다.
    void pop_front();

    // 빈 리스트인지 확인한다.
    bool empty() const;

    // 리스트의 모든 노드를 출력한다.
    void print_all() const;
};

LinkedList::LinkedList() : head(nullptr)
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

void LinkedList::push_front(int val)
{
    Node* node = new Node(val, nullptr);
    if (!this->empty()) {
        node->nptr = head;
    }
    this->head = node;
}

void LinkedList::pop_front()
{
    if (this->empty()) {
        return;
    }
    Node* temp = this->head;
    head = temp->nptr;
    delete temp;
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
        curr = curr->nptr;
    }
    cout << endl;
}

int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(40);
    ll.print_all();
    return 0;
}