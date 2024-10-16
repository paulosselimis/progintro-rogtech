#include <iostream>
#include <stdexcept>

using namespace std;

class Move {
 public:
 // Take sc coins from heap sh and put tc coins to heap th.
 Move(int sh, int sc, int th, int tc) {
     sheap=sh; scoins=sc; theap=th; tcoins=tc;
 }

 int getSource() const { return sheap; }
 int getSourceCoins() const { return scoins; }
 int getTarget() const { return theap; }
 int getTargetCoins() const { return tcoins; }

 friend ostream & operator << (ostream &out, const Move &move) {
     if(move.getTargetCoins()!=0) out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts " <<
     move.getTargetCoins() << " coins to heap " << move.getTarget();
     else out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts nothing";
     return out;
 }
 
 private:
 int scoins, tcoins, sheap, theap;
 
 };
 
 class State {
 public:
 // State with h heaps, where the i-th heap starts with c[i] coins.
 // A total of n players are in the game, numbered from 0 to n-1,
 // and player 0 is the first to play.
 State(int h, const int c[], int n) {
     heaps=h;
     players=n;
     hcoins=new int[heaps];
     for(int i=0; i<heaps; i++) hcoins[i]=c[i];
     
 }
 ~State() { delete [] hcoins; }
 
 int getCoins(int h) const {
     if (h < 0 || h >= heaps) {
            throw logic_error(
                "Invalid heap number, enter a number between 1 and heaps!");
            
        } else {
            return hcoins[h];
        }
 }

 void next(const Move &move) {
     if ((move.getSource() < 0) || (move.getSource() > heaps) ||
            (move.getTarget() < 0) || (move.getTarget() > heaps)) {
            throw logic_error("Invalid Heap!");
           
        } else if (
            (move.getSourceCoins() < 1) || (move.getTargetCoins() < 0) ||
            (move.getSourceCoins() <= move.getTargetCoins()) ||
            (move.getSourceCoins() > getCoins(move.getSource()))) {
            throw logic_error("Invalid Coin number!");
        } else {
            hcoins[move.getSource()] -= move.getSourceCoins();
            hcoins[move.getTarget()] += move.getTargetCoins();
            
            playerturn++;
            if(playerturn>players-1) playerturn=0;
        }
     
 }
 bool winning() const {
      int s = 0;
        for (int i = 0; i < heaps; i++)
            s = s + getCoins(i);
        return not s; }
            
 int getHeaps() const { return heaps; }

 int getPlayers() const { return players; }
 int getPlaying() const { return playerturn; }

 friend ostream & operator << (ostream &out, const State &state) {
     for (int i = 0; i < state.getHeaps(); i++) {
            out << state.hcoins[i];
            if (i != state.getHeaps() - 1)
                out << ", ";
                
        }
    out << " with " << state.getPlaying() << "/" << state.getPlayers() << " playing next";
     
     return out;
 }
 
 private:
 int heaps, *hcoins, players;
 int playerturn=0;

 };
 











