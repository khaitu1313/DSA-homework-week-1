#include <iostream>
using namespace std;

class LLNode{
public:
    int val;
    LLNode* next;
    LLNode() {this->val = 0; this->next = NULL;}
    LLNode(int val, LLNode*next) {this->val = val; this->next = next;}
    static LLNode* createWithIterators(int* begin, int* end){
        LLNode* HEAD = new LLNode(*begin, NULL);
        LLNode* cur = HEAD;
        for(int* ptr=(begin+1);ptr<end;ptr++){
            LLNode* node = new LLNode(*ptr, NULL);
            cur->next = node;
            cur = node;
        }

        return HEAD;
    }
    static void printList(LLNode* head){
        LLNode* cur = head;
        cout << "[";
        while(cur->next != NULL){
           cout << cur->val << ", "; 
           cur = cur->next;
        }
        cout << cur->val << "]";
    }
};

LLNode* foldLinkedList(LLNode* head){
        LLNode* HEAD;
        LLNode* tmp = head;
        int count = 0;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }

        if(count % 2 == 0){
            int n = count / 2;
            int* arr = new int[n];
            LLNode* cur = head;
            for(int i=n-1;i>=0;i--){
                arr[i] = cur->val;
                cur = cur->next;
            }
            for(int i=n;i<count;i++){
                arr[i-n] += cur->val;
                cur = cur->next;
            }

            HEAD = LLNode::createWithIterators(arr, arr + n);
            delete[] arr;
        }else{
            int n = count / 2 + 1;
            int* arr = new int[n];
            LLNode* cur = head;
            for(int i=n-1;i>=0;i--){
                arr[i] = cur->val;
                cur = cur->next;
            }
            for(int i=n;i<count;i++){
                arr[i-n+1] += cur->val;
                cur = cur->next;
            }

            HEAD = LLNode::createWithIterators(arr, arr + n);
            delete[] arr;
        }

        return HEAD;
    }

int main(){
    int arr[] = {9, 5, 7, 5, 0};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead);
    return 0;
}