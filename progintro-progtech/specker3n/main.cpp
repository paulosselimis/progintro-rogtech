#include <iostream>
#include <stdexcept>

using namespace std;


class Game {
private:
    int game_heaps, game_players, current_heap, current_player;
    int *hcoins;
    Player **players_list;

public:
    Game(int heaps, int players) {
        hcoins= new int [heaps];
        game_heaps = heaps;
        game_players = players;
        current_heap = 0;
        current_player = 0;
        players_list = new Player*[players];
    }
    ~Game() {
        delete[] hcoins;
        delete[] players_list;
    }
    void addHeap(int coins)  {
        if (current_heap > game_heaps)
            throw logic_error("All heaps are full with coins!");
        else if (coins < 0)
            throw logic_error("Coins must be a positive number!"); 
        else {
                hcoins[current_heap++] = coins;
            }
    }
    void addPlayer(Player *player)  {
        if (current_player > game_players)
            throw logic_error("All players are added!");
        else {
            players_list[current_player++] = player;
        } 
    }
    void play(ostream &out)  {
        if ((current_player != game_players) && (current_heap != game_heaps)) {
            throw logic_error("Have you added all heaps and players?");
        } else {
            int i = 0;
            State currentState(game_heaps, hcoins, game_players);
            while (!currentState.winning()) {
                out << "State: " << currentState << endl;
                out << *players_list[i % game_players] << " "
                    << players_list[i % game_players]->play(currentState) << endl;
                currentState.next(
                    players_list[i % game_players]->play(currentState));

                i++;
            }
            out << "State: " << currentState << endl;
            i--;
            out << *players_list[i % game_players] << " wins" << endl;
        }
    }
    
    int getPlayers() const {
        return current_player-1;
        
    }
    
    const Player *getPlayer(int p) const {
        if(p<0 || p>current_player) throw logic_error("");
        else return players_list[p];
    }

};










