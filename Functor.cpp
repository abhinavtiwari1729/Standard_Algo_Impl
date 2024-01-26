#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

struct Value{

    int m_result;

    void operator()(int result) {
        m_result = result;
    }
};

struct Goblin{

    int mHealth;
    int mStrength;

    Goblin(int health , int strength) : mHealth(health) , mStrength(strength){

    }
    bool operator<(Goblin & rhs){
        return this->mHealth < rhs.mHealth ;
    }

};


struct GoblinComprator{

    bool operator()(Goblin &lhs , Goblin &rhs){
        return lhs.mStrength < rhs.mStrength ;
    }

};



int main() {

    vector<Goblin> goblins = {Goblin(50 , 100), 
                              Goblin(20 , 50),
                              Goblin(30 , 200)
                              };

    sort(begin(goblins) , end(goblins) , GoblinComprator());

    std::for_each(begin(goblins) , end(goblins) , [](Goblin g){cout << g.mHealth << ", " << g.mStrength << endl ;});


}