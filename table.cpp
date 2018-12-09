// table.cpp
// implementation

#include "table.h"

Table::Table(Player player1, Player player2){

  // initializing players
  playerHuman = player1;
  playerAI = player2;

  // other initializations
  turnCount = 0;
  // pot = 0;
  cout << "Table initialized!" << endl;
}

// deconstructor
Table::~Table(){
}

// generates new, unsorted deck
void Table::generateNewDeck(){
  // empties deck
  deck.clear();

  // card struct
  Card newCard;

  // adds 52 cards
  // increments 13 times
  for(int i = 0; i < 13; i++){
    // spades
    newCard = {i+1, 's'};
    deck.push_back(newCard);
    // clubs
    newCard = {i+1, 'c'};
    deck.push_back(newCard);
    // diamonds
    newCard = {i+1, 'd'};
    deck.push_back(newCard);
    // hearts
    newCard = {i+1, 'h'};
    deck.push_back(newCard);
  }
}

// randomizes order of cards in deck
void Table::shuffle(){
  int random;
  vector<Card> newDeck;
  srand(time(NULL));

  // randomly chooses a card from existing deck
  // puts in new deck, deletes from old deck
  while(deck.size() > 0){
    random = rand() % deck.size();
    newDeck.push_back(deck[random]);
    deck.erase(deck.begin() + random);
  }

  deck = newDeck;
}

// resets player cards to new random cards
void Table::deal(){
  Card playerCard;

  // deals 2 cards to human
  for(int i = 0; i < 2; i++){
    playerCard = deck[0];
    humanCards.push_back(playerCard);
    deck.erase(deck.begin());
  }

  // Deals 2 cards to AI
  for(int j = 0; j < 2; j++){
    playerCard = deck[0];
    aiCards.push_back(playerCard);
    deck.erase(deck.begin());
  }

}

// resets table, bets, and player hands
void Table::reset(){
  generateNewDeck();
  shuffle();
  deal();
  // resetWager();
  clearCommunityCards();
  clearHumanCards();
  clearAICards();
}

// adds card to middle of the table
void Table::addCommunityCard(){
  Card communityCard;
  communityCard = deck[0];
  communityCards.push_back(communityCard);
  deck.erase(deck.begin());
}

// clears all cards from middle of table
void Table::clearCommunityCards(){
  communityCards.clear();
}

// empties human cards
void Table::clearHumanCards(){
  humanCards.clear();
}

// empties AI cards
void Table::clearAICards(){
  aiCards.clear();
}

// cycles through full turn until someone gets pot
void Table::playTurn(){

  // variables
  Player winner;
  // final hand value
  int player1Hand;
  // final hand value
  int player2Hand;
  int action;

  // resets table, bets, and player hands
  reset();

  // puts out 5 community cards
  addCommunityCard();
  addCommunityCard();
  addCommunityCard();
  addCommunityCard();
  addCommunityCard();

  // displays cards
  display();

  // prompts player
  cout << "Do you think you're going to win?" << endl;
  cout << "0 --- No" << endl;
  cout << "1 --- Yes" << endl;
  cin >> action;

  // loops until user enters 0 or 1
  while((action != 1 && action != 0) || cin.fail()){
    cout << action << " is not a valid choice!" << endl << endl;
    cout << "Do you think you're going to win?" << endl;
    cout << "0 --- No" << endl;
    cout << "1 --- Yes" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> action;
  }

  // shows ai cards
  cout << endl;
  cout << "The AI's cards are: " << endl;
  cout << aiCards[0].value << " of " << aiCards[0].suit << endl;
  cout << aiCards[1].value << " of " << aiCards[1].suit << endl << endl;

  bool playerWin;
  // determines if player is correct or not, updates correct appropriately and displays message accordingly
  playerWin = findPlayerPoints() >= findAIPoints();
  if((action == 1 && playerWin) || (action == 0 && playerWin)){
    correct++;
    cout << "Congratulations you were correct!" << endl;
  }
  else if ((action == 1 && !playerWin) || (action == 0 && playerWin)){
    correct--;
    cout << "Sorry, you were incorrect." << endl;
  }
  else{
    correct++;
    cout << "Ties go to the player!" << endl;
  }

  // end of turn actions
  turnCount++;
  cout << "Turn: " << turnCount << endl;
  cout << "Predictions correct: " << correct << endl;

  // waits a little bit before starting next round
  usleep(3000000);
}

// loops through play turn infinitly
void Table::play(){
  while(1){
    playTurn();
  }
}

// returns player points
int Table::findPlayerPoints(){
  int numByValue[13] = { 0 };
  int value = 0;
  // checks cards in center
  for(int i = 0; i < communityCards.size(); i++){
    numByValue[communityCards[i].value - 1]++;
  }
  // checks player cards
  for(int i = 0; i < 2; i++){
    numByValue[humanCards[i].value - 1]++;
  }
  // checks for quads, trips, and dubs
  for(int j = 0; j < 13; j++){
    if(numByValue[j] == 4) return 4;
    if(numByValue[j] == 3) return 3;
    if(numByValue[j] == 2) return 2;
  }
}

// returns AI points
int Table::findAIPoints(){
  int numByValue[13] = { 0 };
  int value = 0;
  // checks cards in center
  for(int i = 0; i < communityCards.size(); i++){
    numByValue[communityCards[i].value - 1]++;
  }
  // checks player cards
  for(int i = 0; i < 2; i++){
    numByValue[aiCards[i].value - 1]++;
  }
  // checks for quads, trips, and dubs
  for(int j = 0; j < 13; j++){
    if(numByValue[j] == 4) return 4;
    if(numByValue[j] == 3) return 3;
    if(numByValue[j] == 2) return 2;
  }
  return 0;
}

// display shows 2 cards for human, 5 flipped cards in the center, and a deck
void Table::display(){
  // clears
  system("clear");

  // opponent's hand display
  cout << "                                                                                   |" << endl;
  cout << "                               _______   _______                                   |" << endl;
  cout << "                              |       | |       |                                  |" << endl;
  cout << "                              |       | |       |                                  |" << endl;
  cout << "                              |       | |       |";
  cout << setw(10) << playerAI.getName() << "'s cards (AI)           |            LEGEND" << endl;
  cout << "                              |       | |       |                                  |" << endl;
  cout << "                              |_______| |_______|                                  |    CARDS            SUITS" << endl;
  cout << "                                                                                   |    1: Ace           s: Spades" << endl;
  // begin board display
  cout << "        _______________________________________________________________            |    2: 2             c: Clubs" << endl;
  cout << "       /                                                               \\           |    3: 3             d: Diamonds" << endl;
  cout << "      /    _______   _______   _______   _______   _______   _______    \\          |    4: 4             h: Hearts" << endl;
  cout << "     /    |       | |       | |       | |       | |       | |       |    \\         |    5: 5" << endl;
  cout << "    |     |    ";
  cout << "   | |" << setw(4) << communityCards[0].value;
  cout << "   | |" << setw(4) << communityCards[1].value;
  cout << "   | |" << setw(4) << communityCards[2].value;
  cout << "   | |" << setw(4) << communityCards[3].value;
  cout << "   | |" << setw(4) << communityCards[4].value;
  cout << "   |     |        |    6: 6" << endl;
  cout << "    |     | DECK  | |       | |       | |       | |       | |       |     |        |    7: 7" << endl;
  cout << "    |     |    ";
  cout << "   | |" << setw(4) << communityCards[0].suit;
  cout << "   | |" << setw(4) << communityCards[1].suit;
  cout << "   | |" << setw(4) << communityCards[2].suit;
  cout << "   | |" << setw(4) << communityCards[3].suit;
  cout << "   | |" << setw(4) << communityCards[4].suit;
  cout << "   |     |        |    8: 8" << endl;
  cout << "     \\    |_______| |_______| |_______| |_______| |_______| |_______|    /         |    9: 9" << endl;
  cout << "      \\                                                                 /          |    10: 10" << endl;
  cout << "       \\_______________________________________________________________/           |    11: Jack" << endl;
  cout << "                                                                                   |    12: Queen" << endl;
  // your hand display
  cout << "                               _______   _______                                   |    13: King" << endl;
  cout << "                              |       | |       |                                  |" << endl;
  cout << "                              |" << setw(4) << humanCards[0].value;
  cout << "   | |" << setw(4) << humanCards[1].value;
  cout << "   |                                  |" << endl;
  cout << "                              |       | |       |";
  cout << setw(10) << playerHuman.getName() << "'s cards (Human?)       |" << endl;
  cout << "                              |" << setw(4) << humanCards[0].suit;
  cout << "   | |" << setw(4) << humanCards[1].suit;
  cout << "   |                                  |" << endl;
  cout << "                              |_______| |_______|                                  |" << endl;
  cout << "                                                                                   |" << endl;
  cout << "                                                                                   |" << endl;
}
