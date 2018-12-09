// player.cpp

#include "player.h"

Player::Player(){
  isHuman = false;
  isPlaying = true;
  name = "John Doe";
}

// constructor
Player::Player(bool humanity, string userID)
{
  isHuman = humanity;
  isPlaying = true;
  name = userID;
}

// // destructor
// Player::~Player(){
//
// }

// // get method that returns specific card from a hand
// Card Player::getCard(int index){
//   return hand[index];
// }

// // get method that returns money
// int Player::getMoney(){
//   return money;
// }
//
// // get method that returns wager
// int Player::getWager(){
//   return wager;
// }

// get method that returns if player is human
bool Player::getHumanity(){
  return isHuman;
}

// get method that returns if player is playing
bool Player::getPlayStatus(){
  return isPlaying;
}

// get method that returns name of player
string Player::getName(){
  return name;
}

// // set method that changes specific card in hand
// void Player::setCard(int index, char newSuit, int val){
//   hand[index].suit = newSuit;
//   hand[index].value = val;
// }

// // set method that changes money
// void Player::setMoney(int newMoney){
//   money = newMoney;
// }

// // set method that changes wager
// void Player::setWager(int bet){
//   wager = bet;
// }

// set method that changes if player is human or not
void Player::setHumanity(bool humanStatus){
  isHuman = humanStatus;
}

// set method that
void Player::setPlayStatus(bool playStatus){
  isPlaying = playStatus;
}

void Player::setName(string newName){
  name = newName;
}

// void Player::fold(){
//   isPlaying = false;
// }
//
// void Player::check(){
// }
//
// void Player::call(int turnBet){
//   int temp = turnBet - wager;
//   wager = turnBet;
//   money -= temp;
// }
//
// void Player::raise(int bet, int turnBet){
//   // if(bet < money && bet >= turnBet){
//     wager += bet;
//     money -= bet;
  // }
  // else if(bet == money && bet > turnBet){
  //   allIn();
  // }
  // else{
  //   cout << "Cannot raise " << bet << " dollars!" << endl;
  //   cout << "Can only raise " << money << " dollars" << endl;
  //   cout << "Please enter a valid bet amount: ";
  //   cin.ignore();
  //   cin >> bet;
  //   raise(bet, turnBet);
//   // }
// }
//
// void Player::allIn(){
//   wager += money;
//   money = 0;
// }
