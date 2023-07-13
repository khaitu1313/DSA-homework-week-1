#include <iostream>
using namespace std;

class Character {
protected:
    int hp;
private:
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
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

/*
Declare and define the derived class Player that satisfies:
    - Methods of base class Character cannot be accessed outside Player class using Player instances.
        Ex: Player pl; pl.setX(); will raise errors when compiled.
    - Player class has these methods and constructors:
        + Constructor Player(): acts just like Character()
        + Constructor Player(int hp, int x, int y): acts just like Character(hp, x, y)
        + Method void printPlayerData(): print data of the instance with format: hp-x-y
        + Method void moveTo(int x, int y): set the values of x, y to new values
    - The mentioned constructors and methods can be accessed outside Player class
*/
class Player: public Character{
public:
    Player(){
        setHp(0);
        setX(0);
        setY(0);
    }

    Player(int hp, int x, int y){
        setHp(hp);
        setX(x);
        setY(y);
    }

    void printPlayerData(){
        cout << this->hp << "-" << this->getX() << "-" << this->getY() << endl;
    }

    void moveTo(int x, int y){
        setX(x);
        setY(y);
    }
};

int main(){
    Player pl1(70, 8, 3);
    pl1.printPlayerData();
    return 0;
}