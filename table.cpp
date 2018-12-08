// table.cpp
// implementation

#include "table.h"

Table::Table(int blind, Player player1, Player player2){
  // setting minimum blind
  minBlind = blind;

  // initializing players
  playerHuman = player1;
  playerAI = player2;

  // other initializations
  turnCount = 0;
  pot = 0;
}

Table::~Table(){
}
//
// // generates new, unsorted deck
// void Table::generateNewDeck(){
//   // empties deck
//   deck.clear();
//
//   // adds 52 cards
//   // increments 13 times
//   for(int i = 0; i < 13; i++){
//     // 4 suits per increment
//     deck.push_back(card(i+1, 's'));
//     deck.push_back(card(i+1, 'c'));
//     deck.push_back(card(i+1, 'd'));
//     deck.push_back(card(i+1, 'h'));
//   }
// }
//
// // randomizes order of cards in deck
// void Table::shuffle(){
//   int random;
//   vector<card> newDeck;
//
//   // randomly chooses a card from existing deck
//   // puts in new deck, deletes from old deck
//   while(deck.size() > 0){
//     random = rand() % deck.size();
//     newDeck.push_back(deck[random]);
//     deck.erase(deck.begin() + i);
//   }
//
//   deck = newDeck;
// }
//
// // resets player cards to new random cards
// void Table::deal(){
//   int random;
//   Card playerCard;
//
//   // deals 2 cards to human
//   for(int i = 0; i < 2, i++){
//     playerCard = deck[0];
//     playerHuman.setCard(i, playerCard.suit, playerCard.value);
//     deck.erase(deck.begin());
//   }
//
//   // Deals 2 cards to AI
//   for(int j = 0; j < 2, i++){
//     playerCard = deck[0];
//     playerAI.setCard(i, playerCard.suit, playerCard.value);
//     deck.erase(deck.begin());
//   }
// }
//
// // resets amount players have bet to zero
// void Table::resetWager(){
//   playerHuman.setWager(0);
//   playerAI.setWager(0);
// }
//
// // resets table, bets, and player hands
// void Table::reset(){
//   generateNewDeck();
//   shuffle();
//   deal();
//   resetWager();
//   clearCommunityCards();
// }
//
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
//
// // adds card to middle of the table
// void Table::addCommunityCard(){
//   Card communityCard = deck[0];
//   communityCards.push_back(communityCard);
//   deck.erase(deck.begin());
// }
//
// // clears all cards from middle of table
// void Table::clearCommunityCards(){
//   communityCards.clear();
// }
//
// // gives pot to winner, then resets pot
// void Table::givePot(Player winner){
//   winner.setWager(winner.getWager() + pot);
//   pot = 0;
// }
//
// // cycles through full turn until someone gets pot
// void Table::playTurn(){
//
//   // variables
//   Player winner;
//   bool isTurnOver = 0;
//   string action;
//   // stage 1 = preflop
//   // stage 2 = flop
//   // stage 3 = turn
//   // stage 4 = river
//   int stage = 1;
//   int value;
//   // final hand value
//   int player1Hand;
//   // final hand value
//   int player2Hand;
//
//   // resets table, bets, and player hands
//   reset();
//
//   // gets blinds
//   betBlinds();
//
//   // play out single turn
//   while(!isTurnOver){
//
//   	cout << "What action would you like to take?" << endl;
//   	cout << " 'Check', 'Call', 'Raise', 'Fold', 'All-In'" << endl;
//   	cin.ignore();
//   	cin >> stage;
//
//   	if(stage == "Check"){
//   	  if(playerHuman.getWager() == playerAI.getWager()){
//      	  playerHuman.check();
//     	  playerAI.check();
//     	  switch(stage){
//     	    case 1:
//             addCommunityCard();
//             addCommunityCard();
//             addCommunityCard();
//             stage++;
//             break;
//           case 2:
//             addCommunityCard();
//             stage++;
//             break;
//           case 3:
//             addCommunityCard();
//             stage++;
//             break;
//           case 4:
//             int player1Hand = findWinner(playerHuman);
//             int player2Hand = findWinner(playerAI);
//             if(player1Hand >= player2Hand){
//               winner = player1Hand;
//             }
//             else {
//               winner = player2Hand;
//             }
//             isTurnOver = 1;
//             break;
//     	  }
//   	  }
//   	  else{
//   	    cout << "Cannot check! Please select a valid action" << endl;
//   	    cin.ignore();
//   	    cin >> stage;
//   	  }
//   	}
//   	if(stage == "Call"){
//       if(playerHuman.getWager() < playerAI.getWager()){
//         playerHuman.call();
//         switch(stage){
//     	    case 1:
//             addCommunityCard();
//             addCommunityCard();
//             addCommunityCard();
//             stage++;
//             break;
//           case 2:
//             addCommunityCard();
//             stage++;
//             break;
//           case 3:
//             addCommunityCard();
//             stage++;
//             break;
//           case 4:
//             int player1Hand = findWinner(playerHuman);
//             int player2Hand = findWinner(playerAI);
//             if(player1Hand >= player2Hand){
//               winner = player1Hand;
//             }
//             else {
//               winner = player2Hand;
//             }
//             isTurnOver = 1;
//             break;
//     	  }
//       }
//       else {
//         cout << "Cannot check! Please select a valid action" << endl;
//   	    cin.ignore();
//   	    cin >> stage;
//       }
//   	}
//   	if(stage == "Raise"){
//
//   	}
//   	if(stage == "Fold"){
//
//   	}
//   	if(stage == "All-In"){
//
//   	}
//
//   }
//
//
//
//
//
//
//
//
//   //
//   //
//   //   }
//   //   if(stage == "Call"){
//   //     if(playerHuman.getWager() < playerAI.getWager() && playerAI.getwager() != 0){
// 	// playerHuman.call(playerAI.getWager() - playerHuman.getWager());
// 	// break;
//   //     }
//   //     else(){
// 	//   cout << "Cannot call! Please select a valid action" << endl;
// 	//   cin.ignore();
// 	//   cin >> stage;
// 	// }
//   //   }
//   //   if(stage == "Raise"){
//   //     cout << "Please enter the amount you would like to raise the current bet by: ";
//   //     cin >> value;
//   //     playerHuman.raise(value, playerAI.getWager());
//   //   }
//   // }
//
//   // end of turn actions
//   givePot(winner);
//   turnCount++;
// }
//
// void Table::play(){
//
// }
//
// int Table::findWinner(Player player){
//   int numByValue[13] = { 0 };
//   int value = 0;
//   for(int i = 0; i < communityCards.size(); i++){
//     numByValue[communityCards[i].getValue()]++;
//   }
//   for(int i = 0; i < 2; i++){
//     numByValue[player.getCard(i).value]++;
//   }
//   if(numByValue.find(numByValue.begin(), numByValue.end(), 4)){
//     return 4;
//   }
//   if(numByValue.find(numByValue.begin(), numByValue.end(), 3)){
//     value += 3;
//   }
//   if(numByValue.find(numByValue.begin(), numByValue.end(), 2)){
//     value += 2;
//   }
//   return value;
// }
//
// void Table::display(){
//   // clears
//   system("clear");
//
//   cout << "                                                                   |" << endl;
//   cout << "                         _______   _______                         |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |_______| |_______|                        |" << endl;
//   cout << "                                                                   |" << endl;
//   cout << "        ___________________________________________________        |" << endl;
//   cout << "       /                                                   \\       |" << endl;
//   cout << "      /                                                     \\      |" << endl;
//   cout << "     /                                                       \\     |" << endl;
//   cout << "    |                                                         |    |" << endl;
//   cout << "    |                                                         |    |" << endl;
//   cout << "    |                                                         |    |" << endl;
//   cout << "     \\                                                       /     |" << endl;
//   cout << "      \\                                                     /      |" << endl;
//   cout << "       \\___________________________________________________/       |" << endl;
//   cout << "                                                                   |" << endl;
//   cout << "                         _______   _______                         |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |       | |       |                        |" << endl;
//   cout << "                        |_______| |_______|                        |" << endl;
//   cout << "                                                                   |" << endl;
// }
