#include<iostream>
using namespace std;
class Entity{

    public:
    Entity(){
        cout << "Entity constructor" << endl;
    }

    ~Entity(){
        cout << "Entity destructor" << endl;
    }

}; 
class Monster : public Entity{

    public :
    Monster(){
        cout << "Monster constructor" << endl;
    }

    ~Monster(){
        cout << "Monster destructor" << endl;
    }
};
int main(){
    Monster m1;

}
