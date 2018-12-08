// player.h

struct Card{
  int value;
  char suit;
};

#define PREFLOP 1
#define FLOP 2
#define TURN 3
#define RIVER 4
#define POSTRIVER 5

class Player{
 public:
  // constructor
  Player(int, bool, string);
  // destructor
  ~Player();
  // get methods
  Card getCard(int);
  vector<Card> getHand();
  int getMoney();
  int getWager();
  bool getHumanity();
  bool getPlayStatus();
  string getName();
  // set methods
  void setCard(int, char, int);
  void setMoney(int);
  void setWager(int);
  void setHumanity(bool)
  void setPlayStatus(bool);
  void setName(string);
  // betting functions
  void fold(); 
  void check();
  void call(int);
  void raise(int, int);
  void allIn();
 private:
  // instance variables
  vector<Card> hand;
  int money;
  int wager;
  bool isHuman;
  bool isPlaying;
  string name;
}
