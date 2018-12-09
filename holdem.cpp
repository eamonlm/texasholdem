#include "table.h"

int main(){
  Player playerAI(false, "Declan");
  Player playerHuman(true, "Chad TC");
  Table tc(playerAI, playerHuman);
  tc.play();


  // cout << "Holla at cha boi" << endl;
  return 0;
}
