// table.h
// interface

#include <vector>
#include <cstdlib>
#include <iomanip>

class Table {
  public:
    Table(int, Player, Player);
    ~Table();
    void generateNewDeck();
    void shuffle();
    void deal();
    void resetWager();
    void reset();
    void betBlinds();
    void addCommunityCard();
    void clearCommunityCards();
    void givePot(Player);
    void playTurn();
    void play();
  private:
    vector<card> deck;
    vector<card> communityCards;
    Player playerHuman;
    Player playerAI;
    int turnCount;
    int minBlind;
    int pot;
}x
