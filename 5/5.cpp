#include <iostream>
using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    Character();
    Character(int hp, int x, int y);
    int getHp();
    void setHp(int hp);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getManhattanDistTo(Character* other);

    // Operator =: copy all data from Character other
    void operator=(const Character& other);

    // Operator <: Character a < Character b when a's hp is less than or equal b's hp
    bool operator<(const Character& other);

    // Operator () with zero parameters: print data of the instance with format: hp-x-y
    void operator()();
};

Character::Character() {
    // STUDENT ANSWER
    this->hp = 0;
    this->x = 0;
    this->y = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    setHp(hp);
    setX(x);
    setY(y);
}

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    setHp(other->getHp());
    setX(other->getX());
    setY(other->getY());
}

// Copy all data from Character other
void Character::operator=(const Character& other) {
    // STUDENT ANSWER
    setHp(other.hp);
    setX(other.x);
    setY(other.y);
}

// Character a < Character b when a's hp is less than or equal b's hp
bool Character::operator<(const Character& other) {
    // STUDENT ANSWER
    if(this->hp < other.hp){
        return true;
    }else{
        return false;
    }
}

// Print data of the instance with format: hp-x-y
void Character::operator()() {
    // STUDENT ANSWER
    cout << this->hp << "-" << this->x << "-" << this->y << endl;
}

int main(){
    Character ch1(100, 3, 6);
    Character ch2 = ch1;
    ch2();
    return 0;
}