#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    Player(const string &n);
    virtual ~Player();

    virtual const string &getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream &operator<<(ostream &out, const Player &player);

protected:
    string name;
};

class GreedyPlayer : public Player {
private:
    string type;

public:
    GreedyPlayer(const string &n) : Player(n) {
        type = "Greedy";
    }
    virtual const string &getType() const override {
        return type;
    }
    virtual Move play(const State &s) override {
        int sheap = 0;
        int scoins = 0;
        for (int i = 0; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > scoins) {
                sheap = i;
                scoins = s.getCoins(i);
            }
        }
        Move GreedyObject(sheap, scoins, 0, 0);
        return GreedyObject;
    }
};

class SpartanPlayer : public Player {
public:
    SpartanPlayer(const string &n) : Player(n) {
        type = "Spartan";
    }
    virtual const string &getType() const override {
        return type;
    }

    virtual Move play(const State &s) override {
        int sheap = 0;
        int scoins = 0;
        for (int i = 0; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > scoins) {
                sheap = i;
                scoins = s.getCoins(i);
            }
        }
        Move SpartanObject(sheap, 1, 0, 0);
        return SpartanObject;
    }

private:
    string type;
};

class SneakyPlayer : public Player {
public:
    SneakyPlayer(const string &n) : Player(n) {
        type = "Sneaky";
    }
    virtual const string &getType() const override {
        return type;
    }

    virtual Move play(const State &s) override {
        int j = 0;
        while (s.getCoins(j) == 0) {
            j++;
        }
        int sheap = j;
        int scoins = s.getCoins(j);
        for (int i = j + 1; i < s.getHeaps(); i++) {
            if ((s.getCoins(i) < scoins) && (s.getCoins(i) > 0)) {
                sheap = i;
                scoins = s.getCoins(i);
            }
        }
        Move SneakyObject(sheap, scoins, 0, 0);
        return SneakyObject;
    }

private:
    string type;
};

class RighteousPlayer : public Player {
public:
    RighteousPlayer(const string &n) : Player(n) {
        type = "Righteous";
    }
    virtual const string &getType() const override {
        return type;
    }

     virtual Move play(const State &s) override {
        int theap = 0;
        int sheap = 0;
        int scoins = s.getCoins(0);
        int tcoins = scoins;

        for (int i = 1; i < s.getHeaps(); i++) {
            if (s.getCoins(i) > scoins) {
                sheap = i;
                scoins = s.getCoins(i);
            } else if (s.getCoins(i) < tcoins) {
                theap = i;
                tcoins = s.getCoins(i);
            }
        }
        scoins -= scoins / 2;
        Move RighteousObject(
            sheap, scoins, theap, scoins - 1);
        return RighteousObject;
    }

private:
    string type;
};

Player::Player(const string &n) { name = n; }
Player::~Player() {}

ostream &operator<<(ostream &out, const Player &player) {
    out << player.getType() << " player " << player.name;
    
    return out;
}


















