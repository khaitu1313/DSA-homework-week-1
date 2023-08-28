#include <iostream>
using namespace std;

class Train {
    public:
        class TrainCar;
    private:
        TrainCar* head;
        TrainCar* tail;
        int size;
    public:
        class TrainCar {
            private:
                int remainingSpace;
                TrainCar* next;
                friend class Train;
            public:
                TrainCar() {this->next = NULL;}
                TrainCar(int remainingSpace, TrainCar* next = NULL) {
                    this->remainingSpace = remainingSpace;
                    this->next = next;
                }
        };
        Train() {
            this->head = new TrainCar(0);
            this->tail = this->head;
            this->size = 1;
        }
        void add(int remaining);
        int allocate(int containerSize);
        int totalRemainingSpace();
};

void Train::add(int remaining){
    TrainCar* newTrainCar = new TrainCar(remaining);
    this->tail->next = newTrainCar;
    this->tail = newTrainCar;
    this->size++;
}

int Train::allocate(int containerSize){
    if(size == 1){
        return -1;
    }

    TrainCar* cur = head;
    for(int i=0;i<size;i++){
        if(cur->remainingSpace >= containerSize){
            cur->remainingSpace -= containerSize;
            return i;
        }
        cur = cur->next;
    }

    return -1;
}

int Train::totalRemainingSpace(){
    int sum = 0;
    TrainCar* cur = head;
    for(int i=0;i<size;i++){
        sum += cur->remainingSpace;
        cur = cur->next;
    }

    return sum;
}

int main(){
    Train* t = new Train();
    t->add(200); t->add(400); t->add(300); ; t->add(600); t->add(500); t->add(100);
    cout << t->allocate(390) << "\n";
    cout << t->allocate(590) << "\n";
    cout << t->totalRemainingSpace() << "\n";
    cout << t->allocate(510) << "\n";
    cout << t->allocate(10) << "\n";
    return 0;
}