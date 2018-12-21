#include<iostream>
#include "nim.h"
#include<string>
#include<array>
#include<assert.h>

namespace csis3700{
nim::nim(int x, int y, int z)
{
    assert (x <= 11 && x >= 5);
    assert (y <= 11 && y >= 5);
    assert (z <= 11 && z >= 5);
    piles[0]=x;
    piles[1]=y;
    piles[2]=z;
    players_turn = 1;
}
nim::nim()
{
    piles[0] = rand() % (12-5) + 5;
    piles[1] = rand()%(12-5) + 5;
    piles[2] = rand()%(12-5) + 5;
    players_turn = 1;
}
void nim::print()
{
    cout << "Player "<< players_turn <<": "<< piles[0] << " " << piles[1] << " " << piles[2] << endl;
}
 int nim::get_players_turn() const
 {
    return players_turn;
 }

 bool nim::take_turn(int pile, int stone)
 {
     if(pile<1 || pile >3)
     {
         cout<<"Please make sure you don't provide wrong pile number(1-3)"<<endl;
         return false;
     }

     if(pile==1)
     {

         if(piles[1]<=0 && piles[2]<=0 && piles[pile-1]-stone<=0)
         return false;
     }
     if(pile==2)
     {
         if(piles[0]<=0 && piles[2]<=0 && piles[pile-1]-stone<=0)
         return false;
     }
     if(pile==3)
     {
         if(piles[0]<=0 && piles[1]<=0 && piles[pile-1]-stone<=0)
         return false;
     }
     if(stone>11 || stone<1)
     {
         return false;
     }
     if(piles[pile-1] - stone < 0)
     {
         return false;
     }
     piles[pile-1] -= stone; //This part I took help, I was doing same thing but very long way and now it's just a single line of code.
     {//Removes stones
     if(players_turn==1)
       {
           players_turn=2;
       }
     else if(players_turn==2)
       {
           players_turn=1;
       }

     }
    return true;

 }


 bool nim::is_game_over()
 {
     int sum=0;
     for(int i=0; i < sizeof(piles)/sizeof(piles[0]); i++)   //Got some help for this part because I was doing it like for(int i=0; i<3;i++)
     {
        sum += piles[i];
     }
     if(sum==1)
     {
         return true;
     }
     else
     {
         return false;
     }


 }
void test()
{
// I can t a k e a few t u r n s i n t h i s game
nim game(11,10,5);
cout << game.is_game_over() << endl; // s h o ul d be f a l s e
cout << game.get_players_turn() << endl; // s h o ul d be 1
game.take_turn(1,10); // remove 10 s t o n e s f r om p i l e 1
cout << game.get_players_turn() << endl; // s h o ul d be 2
game.print(); // Pl a y e r 2 : 1 10 5
game.take_turn(2,10); // remove 10 s t o n e s f r om p i l e 2
game.print(); // Pl a y e r 1 : 1 0 5
game.take_turn(3,5); // remove 5 s t o n e s f r om p i l e 3
game.print();  // Pl a y e r 2 : 1 0 0
cout << game.is_game_over() << endl; // s h o ul d be t r u e

}
void play()
{
    nim start;
    while(start.is_game_over()==false)
    {
        start.print();
        int pile, stone;
        cout<<"Player " << start.get_players_turn() <<"\n" << "Enter number of stones you want to remove from the pile:" << endl;
        cin>>pile>>stone;
        while(start.take_turn(pile,stone)==false)
        {

            cout<<"Error, please check your input"<<endl;


            cin>>pile>>stone;
        }

    }
    if(start.get_players_turn() == 2)
    {

        cout << "Player 1 won the GAME" << endl;
    }
    else if(start.get_players_turn() == 1)
    {

        cout << "Player 2 won the GAME" << endl;
    }

}

}

