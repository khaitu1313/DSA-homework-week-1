#include <iostream>
#include <string>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    int size();
    void toString();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
SLinkedList<T>::SLinkedList(){
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

template <class T>
SLinkedList<T>::~SLinkedList(){
    if(count > 0){
        Node* cur = head;
        while(count != 0){
            head = head->next;
            delete cur;
            cur = head;
            count--;
        }
        tail = NULL;
    }
}

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, NULL);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        count++;
    }

    tail->next = newNode;
    tail = newNode;
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if(head == NULL && index >= 0){
        Node* newNode = new Node(e, NULL);
        head = newNode;
        tail = newNode;
        count++;
    }else{
        if(index > count - 1){
            add(e);
        }else if(index == 0){
            Node* newNode = new Node(e, this->head);
            this->head = newNode;
        }else if(index > 0 && index < count){
            Node* cur = head;
            Node* nex = cur->next;
            for(int i=0;i<=index;i++){
                cur = cur->next;
                nex = nex->next;
            }

            Node* newNode = new Node(e, nex);
            cur->next = newNode;
        }
    }
}

template <class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template <class T>
void SLinkedList<T>::toString(){  //chuyen thanh "void" (de bi loi)
    Node* cur = head;
    cout << "[";
    while(cur->next != NULL){
        cout << cur->data << ", ";
        cur = cur->next;
    }

    cout << cur->data << "]";
}

int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index=0;index<size;index++){
        list.add(0, index);
    }

    list.toString();

    return 0;
}