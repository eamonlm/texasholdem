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
  Player();
  Player(bool, string);
  bool getHumanity();
  bool getPlayStatus();
  string getName();
  void setHumanity(bool);
  void setPlayStatus(bool);
  void setName(string);
 private:
  bool isHuman;
  bool isPlaying;
  string name;
};
