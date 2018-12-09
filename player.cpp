// player.cpp

#include "player.h"

// empty constructor
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
