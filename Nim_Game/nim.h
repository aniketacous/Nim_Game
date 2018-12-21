#ifndef NIM_H
#define NIM_H
#include<iostream>
#include<cstdlib>


using namespace std;

namespace csis3700{

  class nim
  {
    public:
        nim(int x,int y,int z);
        void print();
        int get_players_turn() const;
        bool take_turn(int pile, int stone);
        nim();
        bool is_game_over();


    private:
        int players_turn;
        int piles[3];

  };
void test();
void play();

}

#endif // NIM_H
