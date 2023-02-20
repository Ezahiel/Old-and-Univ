#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "console.ddt" //initialization of library console.ddt

using namespace std;
int color; //var for font color
char ch; //var for keybhit
const char TAB = 9;
const char ESC = 27;
char GameOver; //end game return
int help; // menu help

class Board //base class
           {
     public:
            int square;//not used var in ver 1.0 
            
            int position;
            int oldPosition;
                            Board() : position(0), oldPosition(0)
                            {  }    
           };
                         
  class dice
                   {
            public: 
                   int roll;
                   void rollDice();
              
                   };

                    void dice::rollDice()
                    {
                                srand((unsigned)time(0)); 
                                roll= (rand()%6)+1; 
    

                    }; 
             
class user: public Board, public dice  //sub class

    {
     public:
            string name;
            int tokens;
                       user() : tokens(0)
                       {  }            
    };  
                                
     
int main(int argc, char *argv[])
{ 
    Board sq; //init sq object
    sq.square=36; // not used part of monopoly game left for advance ver with 2D graph that im working on
    user player1, player2; //init players as object of user class
    
         player1.name;  
         player1.position;
         player1.roll;
         player1.tokens;

         player2.name;
         player2.position;
         player2.oldPosition;
         player2.roll;
         player2.tokens;
         
         ddt::console::textcolor(color=14); // first use of new library console for easy access to more option
         cout<< "\n      This is game MONOPOLY  ,";
         ddt::console::textcolor(color=10);         
         cout<< "\n      "
             << "\n      Basic rules: "
             << "\n      Game consist 2 players and 36 squares, "
             << "\n      First users have to input there names ,"
             << "\n      Then program ask to roll dice by pressing key 'R' on the keyboard"
             << "\n      "      
             << "\n      There are 3 special squares:"
             << "\n      Chance --> player can be send forward"
             << "\n      Risk   --> player position is reduced"
             << "\n      Loser  --> player loose 1 turn"
             << "\n      "
             << "\n      Player recive 1 token when passing square 36th"
             << "\n      Game end when one of players reach 5 tokens"
             << "\n      ";          
             ddt::console::textcolor(color=12);
             cout<< "\n      To get that help menu at any time press 'TAB' Key once ,"
                 << "\n      To end game in any time press 'ESC' Key two-tree times ,"<<endl;
             cout<< "\n";    
             ddt::console::textcolor(color=7); // init base console color font
             system("PAUSE");
             system("cls");
             ddt::console::textcolor(color=7);
             cout<<"Please enter name of the 1st player "<<endl;
             cin>>player1.name;
             ddt::console::textcolor(color=11);             
             cout<<"Welcome!.."<<player1.name<<" and Thank you...\n"<<endl;
             ddt::console::textcolor(color=7);             
             cout<<"Please enter name of the 2nd player\n"<<endl;
             cin>>player2.name;
             ddt::console::textcolor(color=15);             
             cout<<"Thank you.."<<player2.name<<endl;
             ddt::console::textcolor(color=7);
             system("PAUSE");
             system("cls"); //clear screen
             cout<<" Lets start with player 1 which is ...";
             ddt::console::textcolor(color=11);
             cout<<player1.name<<endl;
             ddt::console::textcolor(color=7);
             cout<<""<<endl;
             
             cout<<"OK! ";
             ddt::console::textcolor(color=11);
             cout<<player1.name;
             ddt::console::textcolor(color=7);
             cout<<" Please press (R) to roll dice.."<<endl;
 
 
do {
      ch = getche();           //get character
                               if ( ch == TAB ) //help menu
                               {
                                ddt::console::textcolor(color=14);    
                                cout<< "\n      This is game MONOPOLY  ,";
                                ddt::console::textcolor(color=10);         
                                cout<< "\n      "
                                    << "\n      Basic rules: "
                                    << "\n      Game consist 2 players and 36 squares, "
                                    << "\n      First users have to input there names ,"
                                    << "\n      Then program ask to roll dice by pressing key 'R' on the keyboard"
                                    << "\n      "      
                                    << "\n      There are 3 special squares:"
                                    << "\n      Chance --> player can be send forward"
                                    << "\n      Risk   --> player position is reduced"
                                    << "\n      Loser  --> player loose 1 turn"
                                    << "\n      "
                                    << "\n      Player recive 1 token when passing square 36th"
                                    << "\n      Game end when one of players reach 5 tokens"
                                    << "\n      ";          
                                    ddt::console::textcolor(color=12);
                                cout<< "\n      To get that help menu at any time press 'TAB' Key once ,"
                                    << "\n      To end game in any time press 'ESC' Key two-tree times ,"<<endl;
                                cout<< "\n";    
                                    ddt::console::textcolor(color=7);
                                    system("PAUSE");
                                    system("cls");    
                               }

      if( ch == 'r' ) //roll dice to get position
   
           player1.rollDice(); //void is working good
                          
        player1.position+=player1.roll; //position increse by roll number
        player1.oldPosition=player1.position - player1.roll; //position from last move or null if start game
                                     if (player1.position > 36 )// give token when you pass 36 or strat next turn from 36sq
                                     {
                                      player1.tokens++; //keep incrementing tokens
                                      cout<<"\n Tokens so far = "<<player1.tokens<<endl;
                                      cout<<"\n  ";
                                      ddt::console::textcolor(color=11);
                                      cout<<player1.name;
                                      ddt::console::textcolor(color=7);
                                      cout<<" receive 1 Token "<<endl;               
                                      }
                                      if (player1.position > 36) // if call to make scope of board to have 36square
                                      {
                                         player1.position = player1.position - 36;                  
                                      }   
    {                                                                        // simple graphic without using #graph.h
    cout<<"\n                              * * * * * *"<<endl;
    cout<<"                             *         **"<<endl;
    cout<<"                            *   "<<player1.roll <<"     * *"<<endl;
    cout<<"                           *         *  *"<<endl;
    cout<<" Your Dice roll is -->"<<"    * * * * * *   *"<<endl;
    cout<<"                          *         *   *"<<endl;
    cout<<"                          *         *  *"<<endl;
    cout<<"                          *         * * "<<endl;
    cout<<"                          *         ** "<<endl;
    cout<<"                          * * * * * * "<<endl;
    cout << "\n You was on Square number: "<< player1.oldPosition<<endl;
    cout << "\n You are now in Square number: "<< player1.position<<endl;
    cout<< "\n";
    } 
           if (player1.tokens==5)     // player1 end game statement
              {
                                 cout<<"\n ";
                                 ddt::console::textcolor(color=11);
                                 cout<<player1.name;
                                 ddt::console::textcolor(color=12);
                                 cout<<"  CONGRATULATIONS YOU WON THIS GAME"<<endl;
                                 ddt::console::textcolor(color=7);
                                 cout<< "\n";
                                 system("PAUSE");
                                 return GameOver;
              }
        
           if (player1.position==5) // 1st type of special position
                                   {
                                    player1.position=24;
                                    cout<<"\n Chance square: You going to square 24 "<<endl;
                                    cout<< "\n";    
                                   }
           if (player1.position==14) //2nd type of special position
                                   {
                                    player1.position=6;
                                    cout<<"\n Risk square: You going back to square 6 "<<endl;
                                    cout<< "\n";
                                   }
            if (player1.position==23) 
                                   {
                                    player1.position=33;
                                    cout<<"\n Chance square: You going to square 33 "<<endl;
                                    cout<< "\n";
                                   }
           if (player1.position==32) //3nd type of special position
                                   {
                                    cout<<"\n Loser square: You lost bet, so you give 1 roll to ";
                                    ddt::console::textcolor(color=15);
                                    cout<<player2.name<<endl;
                                    ddt::console::textcolor(color=7);
                                                cout<< "\n";
                                                system("PAUSE");
                                                system("cls");
                                                cout<<"\n  now:  ";
                                                ddt::console::textcolor(color=15);
                                                cout<<player2.name;
                                                ddt::console::textcolor(color=7);
                                                cout<<"  Press 'R' to roll "<<endl;
                                    ch = getche(); // init additional roll         
                                    player2.rollDice();
                                    player2.position+=player2.roll;
                                    player2.oldPosition=player2.position - player2.roll;
                                    if (player2.position > 36 )// give token when you pass 36 or strat next turn from 36sq
                                     {
                                      player2.tokens++;
                                      cout<<"\n Tokens so far = "<<player2.tokens<<endl;
                                      cout<<"\n  ";
                                      ddt::console::textcolor(color=15);
                                      cout<<player2.name;
                                      ddt::console::textcolor(color=7);
                                      cout<<" receive 1 Token "<<endl;               
                                      }
                                      if (player2.position > 36)
                                      {
                                         player2.position = player2.position - 36;                  
                                      }   
                                      {       
                                      cout<<"\n                              * * * * * *"<<endl;
                                      cout<<"                             *         **"<<endl;
                                      cout<<"                            *   "<<player2.roll <<"     * *"<<endl;
                                      cout<<"                           *         *  *"<<endl;
                                      cout<<" Your Dice roll is -->"<<"    * * * * * *   *"<<endl;
                                      cout<<"                          *         *   *"<<endl;
                                      cout<<"                          *         *  *"<<endl;
                                      cout<<"                          *         * * "<<endl;
                                      cout<<"                          *         ** "<<endl;
                                      cout<<"                          * * * * * * "<<endl;
                                      cout << "\n You was on Square number: "<< player2.oldPosition<<endl;
                                      cout << "\n You are now in Square number: "<< player2.position<<endl;
                                      cout<< "\n";
                                      }
                                 
                                   } 
            system("PAUSE");
           system("cls");                                   
           cout<<"\n  now:  ";
           ddt::console::textcolor(color=15);
           cout<<player2.name;
           ddt::console::textcolor(color=7);
           cout<<"  Press 'R' to roll"<<endl;
                                                                              
      ch = getche(); // init to roll for second player
        
        player2.rollDice();
        player2.position+=player2.roll;
        player2.oldPosition=player2.position - player2.roll;
        
                                     if (player2.position > 36 )//give token when you pass 36 or strat next turn from 36sq
                                     {
                                      player2.tokens++;
                                      cout<<"\n Tokens so far = "<<player2.tokens<<endl;
                                      cout<<"\n  ";
                                      ddt::console::textcolor(color=15);
                                      cout<<player2.name;
                                      ddt::console::textcolor(color=7);
                                      cout<<" receive 1 Token "<<endl;               
                                      }
                                      if (player2.position > 36)
                                      {
                                         player2.position = player2.position - 36;                  
                                      }         
        
    {       
    cout<<"\n                              * * * * * *"<<endl;
    cout<<"                             *         **"<<endl;
    cout<<"                            *   "<<player2.roll <<"     * *"<<endl;
    cout<<"                           *         *  *"<<endl;
    cout<<" Your Dice roll is -->"<<"    * * * * * *   *"<<endl;
    cout<<"                          *         *   *"<<endl;
    cout<<"                          *         *  *"<<endl;
    cout<<"                          *         * * "<<endl;
    cout<<"                          *         ** "<<endl;
    cout<<"                          * * * * * * "<<endl;
    cout << "\n You was on Square number: "<< player2.oldPosition<<endl;
    cout << "\n You are now in Square number: "<< player2.position<<endl;
    cout<< "\n";
    }        
        
        if (player2.tokens==5) // player2 end game statement
              {
                                 cout<<"\n ";
                                 ddt::console::textcolor(color=15);
                                 cout<<player2.name;
                                 ddt::console::textcolor(color=12);
                                 cout<<"  CONGRATULATIONS YOU WON THIS GAME"<<endl;
                                 ddt::console::textcolor(color=7);
                                 cout<< "\n";
                                 system("PAUSE");
                                 return GameOver;
              }

           if (player2.position==5) //1st type of special position
                                   {
                                    player2.position=24;
                                    cout<<"\n Chance square: You going to square 24"<<endl;
                                    cout<< "\n";
                                   }
           if (player2.position==14) //2nd type of special position
                                   {
                                   player2.position=6;
                                    cout<<"\n Risk square: You going back to square 6"<<endl;
                                    cout<< "\n";  
                                   }
            if (player2.position==23)
                                   {
                                    player2.position=33;
                                    cout<<"\n Chance square: You going to square 33"<<endl;
                                    cout<< "\n";
                                   }
           if (player2.position==32) //3nd type of special position
                                   {
                                    cout<<"\n Loser square: You lost bet, so you give 1 roll to ";
                                    ddt::console::textcolor(color=11);
                                    cout<<player1.name<<endl;
                                    ddt::console::textcolor(color=7);
                                                    cout<< "\n";
                                                    system("PAUSE");
                                                    system("cls");
                                                    cout<<"\n  now:  ";
                                                    ddt::console::textcolor(color=11);
                                                    cout<<player1.name;
                                                    ddt::console::textcolor(color=7);
                                                    cout<<"  Press 'R' to roll"<<endl;
                                    ch = getche();          //init additional roll
                                    player1.rollDice();
                                    player1.position+=player1.roll;
                                    player1.oldPosition=player1.position - player1.roll;
                                    if (player1.position > 36 )// give token when you pass 36 or strat next turn from 36sq
                                     {
                                      player1.tokens++;
                                      cout<<"\n Tokens so far = "<<player1.tokens<<endl;
                                      cout<<"\n  ";
                                      ddt::console::textcolor(color=11);
                                      cout<<player1.name;
                                      ddt::console::textcolor(color=7);
                                      cout<<" receive 1 Token "<<endl;               
                                      }
                                      if (player1.position > 36)
                                      {
                                         player1.position = player1.position - 36;                  
                                      }   
                                      {       
                                      cout<<"\n                              * * * * * *"<<endl;
                                      cout<<"                             *         **"<<endl;
                                      cout<<"                            *   "<<player1.roll <<"     * *"<<endl;
                                      cout<<"                           *         *  *"<<endl;
                                      cout<<" Your Dice roll is -->"<<"    * * * * * *   *"<<endl;
                                      cout<<"                          *         *   *"<<endl;
                                      cout<<"                          *         *  *"<<endl;
                                      cout<<"                          *         * * "<<endl;
                                      cout<<"                          *         ** "<<endl;
                                      cout<<"                          * * * * * * "<<endl;
                                      cout << "\n You was on Square number: "<< player1.oldPosition<<endl;
                                      cout << "\n You are now in Square number: "<< player1.position<<endl;
                                      cout<< "\n";
                                      }
                                  
                                   }    
        system("PAUSE");
        system("cls");
        cout<<"\n  now:   ";
        ddt::console::textcolor(color=11);
        cout<<player1.name;
        ddt::console::textcolor(color=7);
        cout<<"  Press 'R' to roll"<<endl;                             
   } 
   while( ch != ESC );    //exit from game in any time and give some msg
   cout<<GameOver;
   ddt::console::textcolor(color=12);
   cout<<"\n Goodbye, come back other time  ";
   ddt::console::textcolor(color=11);
   cout<<player1.name;
   ddt::console::textcolor(color=7);
   cout<<" and  ";
   ddt::console::textcolor(color=15);
   cout<<player2.name<<endl;
   ddt::console::textcolor(color=7);
   cout<< "\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
