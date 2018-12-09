// player.h

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
// #include <algorithm>
using namespace std;

struct Card{
  int value;
  char suit;
};

class Player{
 public:
  // constructor
  Player();
  Player(bool, string);
  // destructor
  // ~Player();
  // get methods
  // Card getCard(int);
  // int getMoney();
  // int getWager();
  bool getHumanity();
  bool getPlayStatus();
  string getName();
  // set methods
  // void setCard(int, char, int);
  // void setMoney(int);
  // void setWager(int);
  void setHumanity(bool);
  void setPlayStatus(bool);
  void setName(string);
  // // betting functions
  // void fold();
  // void check();
  // void call(int);
  // void raise(int, int);
  // void allIn();
 private:
  // instance variables
  // int money;
  // vector<Card> hand;
  // int wager;
  bool isHuman;
  bool isPlaying;
  string name;
};
