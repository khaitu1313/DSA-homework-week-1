#include <iostream>
#include <sstream>
using namespace std;

class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
        void add(int value);
        void toString();
	    void replace(LinkedList* linked_list, int low, int high);
};

void LinkedList::add(int value){
    if(head == NULL){
        Node* newNode = new Node(value, NULL);
        head = newNode;
        tail = newNode;
        size++;
    }else{
        Node* newNode = new Node(value, NULL);
        tail->next = newNode;
        tail = newNode;
        size++;
    }
}

void LinkedList::toString(){
    Node* cur = head;
    cout << "[";
    while(cur->next != NULL){
        cout << cur->value << ", ";
        cur = cur->next;
    }
    cout << cur->value << "]";
}

void LinkedList::replace(LinkedList* linked_list, int low, int high){
    if(low < 0){
        low = 0;
    }

    if(high >= size){
        high = size - 1;
    }

    if(this->size < linked_list->size){
        Node* cur = this->head;
        while(cur != NULL){
            this->head = this->head->next;
            delete cur;
            cur = head;
        }

        this->head = linked_list->head;
        this->tail = linked_list->tail;
    }else{
        Node* pre = this->head;
        Node* cur = this->head;
        Node* nex = this->head;
        if(low == 0){
            for(int i=0;i<high+1;++i){
                nex = nex->next;
            }
            this->head = linked_list->head;
            linked_list->tail->next = nex;
        }
        else{
            for(int i=0;i<low-1;i++){
                pre = pre->next;
            }
            for(int i=0;i<low;i++){
                cur = cur->next;
            }
            for(int i=0;i<high;i++){
                nex = nex->next;
            }

            pre->next = linked_list->head;
            linked_list->tail->next = nex;
        }

        Node* ptr = cur;
        while(ptr != NULL){
            cur = cur->next;
            delete ptr;
            ptr = cur;
        }
    }
}
    
int main(){
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();
    l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
    l2->add(55); l2->add(45); l2->add(42);
    l1->replace(l2, -1, 2);
    l1->toString();
    cout << "\n";
    return 0;
}