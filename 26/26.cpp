#include <iostream>
#include <assert.h>
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
    SLinkedList(): head(NULL), tail(NULL), count(0){ };
    ~SLinkedList() { };
    void add(const T& e);
    void add(int index, const T& e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
    void toString();
    void clear();
    T removeAt(int index);
    bool removeItem(const T& item);
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
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, NULL);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        count++;
    }else{
        tail->next = newNode;
        tail = newNode;
        count++;
    }
}

template <class T>
void SLinkedList<T>::add(int index, const T& e) {
        if(head==NULL || index > count - 1){
            add(e);
        }else if(index == 0){
            Node* newNode = new Node(e, this->head);
            this->head = newNode;
            count++;
        }else{
            Node* cur = head;
            Node* nex = cur->next;
            for(int i=0;i<index-1;i++){
                cur = cur->next;
                nex = nex->next;
            }

            Node* newNode = new Node(e, nex);
            cur->next = newNode;
            count++;
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
    while(cur!= NULL){
        cout << cur->data;
        cur = cur->next;
        if (cur!=NULL) cout<<", ";
    }

    cout << "]";
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if(index == 0){
        return this->head->data;
    }else if(index == count - 1){
        return this->tail->data;
    }else{
        Node* cur = head;
        for(int i=1;i<=index;i++){
            cur = cur->next;
        }
        return cur->data;
    }
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if(index == 0){
        this->head->data = e;
    }else if(index == count - 1){
        this->tail->data = e;
    }else if(index > 0 && index < count - 1){
        Node* cur = head;
        for(int i=0;i<=index;i++){
            cur = cur->next;
        }
        cur->data = e;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if(head == NULL && tail == NULL && count == 0){
        return true;
    }

    return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index whenever item appears in list, otherwise return -1 */
    if(empty()){
        return -1;
    }else{
        Node* cur = head;
        for(int i=0;i<count;i++){
            if(cur->data == item){
                return i;
            }else{
                cur = cur->next;
            }
        }

        return -1;
    }
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if(indexOf(item) != -1){
        return true;
    }else{
        return false;
    }
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    T tmp = get(index);
    if(index == 0){
        Node* cur = head;
        head = head->next;
        delete cur;
    }else{
        Node* pre = head;
        Node* cur = head->next;
        for(int i=0;i<index-1;i++){
            pre = pre->next;
            cur = cur->next;
        }
        
        pre->next = cur->next;
        delete cur;
    }

    return tmp;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = indexOf(item);
    if(index != -1){
        Node* pre = head;
        Node* cur = head->next;
        for(int i=0;i<index;i++){
            pre = pre->next;
            cur = cur->next;
        }

        pre->next = cur->next;
        delete cur;
        return true;
    }else{
        return false;
    }
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* cur = head;
    while(!empty()){
        head = head->next;
        delete cur;
        cur = head;
        count--;
    }
}

int main(){
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    // assert(list.get(0) == list.removeAt(0));
    // assert(list.get(9) == list.removeAt(9));
    assert(list.removeAt(9));

    list.toString();

    return 0;
}