#include "table.h"

int main(){
  Player playerAI(1000, false, "Declan");
  Player playerHuman(1000, true, "Chad TC");
  Table tc(5, playerAI, playerHuman);
  // tc.play();
  return 0;
}
