// table.h
// interface

#include "player.h"

class Table {
  public:
    Table(Player, Player);
    ~Table();
    void generateNewDeck();
    void shuffle();
    void deal();
    // void resetWager();
    void reset();
    // void betBlinds();
    void addCommunityCard();
    void clearCommunityCards();
    // void givePot(Player);
    void playTurn();
    void play();
    // void doAction(Player);
    int findPlayerPoints();
    int findAIPoints();
    void display();
  private:
    vector<Card> deck;
    vector<Card> communityCards;
    vector<Card> humanCards;
    vector<Card> aiCards;
    Player playerHuman;
    Player playerAI;
    int turnCount;
    // int minBlind;
    // int pot;
    int correct;
};
