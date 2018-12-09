// table.cpp
// implementation

#include "table.h"

Table::Table(Player player1, Player player2){
  // setting minimum blind
  // minBlind = blind;

  // initializing players
  playerHuman = player1;
  playerAI = player2;

  // other initializations
  turnCount = 0;
  // pot = 0;
  cout << "Table initialized!" << endl;
}

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

// // resets amount players have bet to zero
// void Table::resetWager(){
//   playerHuman.setWager(0);
//   playerAI.setWager(0);
// }

// resets table, bets, and player hands
void Table::reset(){
  generateNewDeck();
  shuffle();
  deal();
  // resetWager();
  clearCommunityCards();
}

// // table requires players to bet at start of turn
// void Table::betBlinds(){
//   // big and small bets for players alternate with turn
//   if(turnCount % 2 == 0){
//     playerAI.raise(minBlind, playerHuman.getWager());
//     playerHuman.raise(2*minBlind, playerAI.getWager());
//   } else {
//     playerHuman.raise(minBlind, playerAI.getWager());
//     playerAI.raise(2*minBlind, playerHuman.getWager());
//   }
// }

// adds card to middle of the table
void Table::addCommunityCard(){
  cout << "yes!" << endl;
  Card communityCard;
  cout << "motherfucker" << endl;
  communityCard = deck[0];
  cout << "ok!" << endl;
  communityCards.push_back(communityCard);
  cout << "suit is: " << communityCard.suit << endl;
  cout << "value is: " << communityCard.value << endl;
  deck.erase(deck.begin());
}

// clears all cards from middle of table
void Table::clearCommunityCards(){
  communityCards.clear();
}

// // gives pot to winner, then resets pot
// void Table::givePot(Player winner){
//   winner.setWager(winner.getWager() + pot);
//   pot = 0;
// }

// cycles through full turn until someone gets pot
void Table::playTurn(){

  // variables
  Player winner;
  // bool isTurnOver = 0;
  // string action;
  // stage 1 = preflop
  // stage 2 = flop
  // stage 3 = turn
  // stage 4 = river
  // int stage = 1;
  // int value;
  // final hand value
  int player1Hand;
  // final hand value
  int player2Hand;
  int action;

  // resets table, bets, and player hands
  reset();

  addCommunityCard();
  addCommunityCard();
  addCommunityCard();
  addCommunityCard();
  addCommunityCard();

  display(0);

  // prompts player
  cout << "Do you think you're going to win?" << endl;
  cout << "0 --- No" << endl;
  cout << "1 --- Yes" << endl;
	cin >> action;

  bool playerWin;

  // loops until user enters 0 or 1
  while(action != 1 && action != 0){
    cout << action << " is not a valid choice!" << endl << endl;
    cout << "Do you think you're going to win?" << endl;
    cout << "0 --- No" << endl;
    cout << "1 --- Yes" << endl;
  	cin.ignore();
  	cin >> action;
  }

  playerWin = findPlayerPoints() > findAIPoints();

    if((action == 1 && playerWin) || (action == 0 && !playerWin)){
      correct++;
    }
    else if ((action == 1 && !playerWin) || (action == 0 && playerWin)){
      correct--;
    }

  	// if(action == "Check"){
  	//   if(playerHuman.getWager() == playerAI.getWager()){
    //  	  playerHuman.check();
    // 	  playerAI.check();
    // 	  switch(stage){
    // 	    case 1:
    //         addCommunityCard();
    //         addCommunityCard();
    //         addCommunityCard();
    //         stage++;
    //         break;
    //       case 2:
    //         addCommunityCard();
    //         stage++;
    //         break;
    //       case 3:
    //         addCommunityCard();
    //         stage++;
    //         break;
    //       case 4:
    //         int player1Hand = findWinner(playerHuman);
    //         int player2Hand = findWinner(playerAI);
    //         if(player1Hand >= player2Hand){
    //           winner = playerHuman;
    //         }
    //         else {
    //           winner = playerAI;
    //         }
    //         isTurnOver = 1;
    //         break;
    // 	  }
  	//   }
  	//   else{
  	//     cout << "Cannot check! Please select a valid action" << endl;
  	//     cin.ignore();
  	//     cin >> stage;
  	//   }
  	// }
  // 	if(stage == "Call"){
  //     if(playerHuman.getWager() < playerAI.getWager()){
  //       playerHuman.call();
  //       switch(stage){
  //   	    case 1:
  //           addCommunityCard();
  //           addCommunityCard();
  //           addCommunityCard();
  //           stage++;
  //           break;
  //         case 2:
  //           addCommunityCard();
  //           stage++;
  //           break;
  //         case 3:
  //           addCommunityCard();
  //           stage++;
  //           break;
  //         case 4:
  //           int player1Hand = findWinner(playerHuman);
  //           int player2Hand = findWinner(playerAI);
  //           if(player1Hand >= player2Hand){
  //             winner = player1Hand;
  //           }
  //           else {
  //             winner = player2Hand;
  //           }
  //           isTurnOver = 1;
  //           break;
  //   	  }
  //     }
  //     else {
  //       cout << "Cannot check! Please select a valid action" << endl;
  // 	    cin.ignore();
  // 	    cin >> stage;
  //     }
  // 	}
  // 	if(stage == "Raise"){
  //
  // 	}
  // 	if(stage == "Fold"){
  //
  // 	}
  // 	if(stage == "All-In"){

  //   }
  //
  // }











  //
  //
  //   }
  //   if(stage == "Call"){
  //     if(playerHuman.getWager() < playerAI.getWager() && playerAI.getwager() != 0){
	// playerHuman.call(playerAI.getWager() - playerHuman.getWager());
	// break;
  //     }
  //     else(){
	//   cout << "Cannot call! Please select a valid action" << endl;
	//   cin.ignore();
	//   cin >> stage;
	// }
  //   }
  //   if(stage == "Raise"){
  //     cout << "Please enter the amount you would like to raise the current bet by: ";
  //     cin >> value;
  //     playerHuman.raise(value, playerAI.getWager());
  //   }
  // }








  // end of turn actions
  // givePot(winner);
  turnCount++;
  cout << "turnCount: " << turnCount << endl;
}

void Table::play(){
  while(1){
    playTurn();
  }
}

// // if player1 is human, takes input
// // if player1 is AI, takes random input
// void doHumanAction(Player human, Player ai){
//   // prompts
//   cout << "Enter a number to take an action." << endl;
// 	cout << " '1 --- Check', '2 --- Call', '3 --- Raise', '4 --- Fold', '5 --- All-In'" << endl;
// 	cin.ignore();
// 	cin >> action;
//
//   // switch case for action
//   switch(action){
//   case 1:
//     if(human.getWager() < ai.getWager())
//   case 2:
//   case 3:
//   case 4:
//   case 5:
//
//   }
// }

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

// display shows 2 cards for each player, 5 flipped cards in the center, and a deck
// if isTurnOver is false, AI cards appear empty
// else, all cards are displayed
void Table::display(bool givenAnswer){
  // clears
  system("clear");

  cout << "                                                                               |" << endl;
  cout << "                               _______   _______                               |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |_______| |_______|                              |" << endl;
  cout << "                                                                               |" << endl;
  cout << "        _______________________________________________________________        |" << endl;
  cout << "       /                                                               \\       |" << endl;
  cout << "      /    _______   _______   _______   _______   _______   _______    \\      |" << endl;
  cout << "     /    |       | |       | |       | |       | |       | |       |    \\     |" << endl;
  cout << "    |     |       | |       | |       | |       | |       | |       |     |    |" << endl;
  cout << "    |     |       | |       | |       | |       | |       | |       |     |    |" << endl;
  cout << "    |     |       | |       | |       | |       | |       | |       |     |    |" << endl;
  cout << "     \\    |_______| |_______| |_______| |_______| |_______| |_______|    /     |" << endl;
  cout << "      \\                                                                 /      |" << endl;
  cout << "       \\_______________________________________________________________/       |" << endl;
  cout << "                                                                               |" << endl;
  cout << "                               _______   _______                               |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |       | |       |                              |" << endl;
  cout << "                              |_______| |_______|                              |" << endl;
  cout << "                                                                               |" << endl;
  cout << "                                                                               |" << endl;
}
