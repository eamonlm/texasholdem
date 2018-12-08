// table.h
// interface

#include "player.h"

class Table {
  public:
    Table(int, Player, Player);
    ~Table();
    // void generateNewDeck();
    // void shuffle();
    // void deal();
    // void resetWager();
    // void reset();
    // void betBlinds();
    // void addCommunityCard();
    // void clearCommunityCards();
    // void givePot(Player);
    // void playTurn();
    // void play();
    // int findWinner(Player);
    // void display();
  private:
    vector<Card> deck;
    vector<Card> communityCards;
    Player playerHuman;
    Player playerAI;
    int turnCount;
    int minBlind;
    int pot;
}x
