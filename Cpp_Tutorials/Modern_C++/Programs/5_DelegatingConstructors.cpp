// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()                                //This is called delegating constructor.
    : Player{"None", 0, 0}                      //Instead of initializing the valies call the 3 args constructor.
{
    cout << "No-args constructor" << endl;
}

Player::Player(std::string name_val)            //This is called delegating constructor.
    : Player{name_val, 0, 0}                    //Instead of initializing the valies call the 3 args constructor.
{
    cout << "One-arg constructor" << endl;
}

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}                //Initialize 3 args constructor with the data we need.
{
    cout << "Three-args constructor" << endl;
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}

/*******************************************************************************************
1. In this feature another constructor is called instead of initialization list.

2. This feature only works in initialization list.add_pointer Another constructor cannot be 
   called from the body of delegating constructor.

3. Delegation cannot be done to another constructor and provide the initilization values.

4. The delegating constructor calls the whole of another constructor and not just the initialization
   list part.

5. This feature is provided for avoiding duplicacy.
******************************************************************************************/