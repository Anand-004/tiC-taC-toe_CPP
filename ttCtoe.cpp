#include <iostream>
#include <ctime>  //included for creating random seed with time (for computers turn)




char getPlayerchoice(); //get users choice for symbol



int main()
    {
        char playerChar;
        char computerChar;
        std::cout<<"\n---------- Welcome to TIC-TAC-TOE terminal Game ----------\n";
        std::cout<<"\n";
        playerChar=getPlayerchoice();
        if(playerChar=='x')
            {
                computerChar='o';
            }
        else
            {
                computerChar='x';
            }

    }//End OF Main Function;


char getPlayerchoice()
    {   
        char userChar;
        do{
            std::cout<<"\n #    Select Your Character(x or o) : ";
            std::cin>>userChar;
            if(!(userChar=='x')&&!(userChar=='o')){
                std::cout<<"\n !!!----please enter a valid Character----!!!\n";
            }
        }while(!(userChar=='x')&&!(userChar=='o'));
        
        return userChar;
    }

