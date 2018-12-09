// includes all libraries and player.h
#include "table.h"

int main(){
  // AI player creation
  Player playerAI(false, "Declan");
  // human player creation
  Player playerHuman(true, "Chad TC");
  // table creation with player inputs
  Table tc(playerHuman, playerAI);
  // plays forever
  tc.play();
  return 0;
}
