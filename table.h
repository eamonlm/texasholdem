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
    void reset();
    void addCommunityCard();
    void clearCommunityCards();
    void clearHumanCards();
    void clearAICards();
    void playTurn();
    void play();
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
    int correct;
};
