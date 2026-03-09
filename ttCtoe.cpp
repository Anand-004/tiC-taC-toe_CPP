#include <iostream>
#include <ctime>  //included for creating random seed with time (for computers turn)
#include<chrono>
#include<thread>




char getPlayerchoice(); //get users choice for symbol
void showBoard(char *spaces); //shows tic-tac-toe board on each turn
void playerTurn(char *spaces,char playerChar);
void computerTurn(char *spaces,char computerChar);
bool checkWinner(char *spaces,char playerChar,char computerChar);
bool checkTie(char *space);




int main()
    {
        char spaces[9]={'1','2','3','4','5','6','7','8','9'};
        char playerChar;
        char computerChar;
        char exitchar;
        bool gameEndflag=true;




        std::cout<<"\n---------- Welcome to TIC-TAC-TOE terminal Game ----------\n";
        std::cout<<"\n";
        playerChar=getPlayerchoice();
        if(playerChar=='X')
            {
                computerChar='O';
            }
        else
            {
                computerChar='X';
            }
        std::cout<<"\n Game starts ..1..2..3\n\n";
        showBoard(spaces);

        while(gameEndflag)
        {
            
            std::cout<<"\n";
            playerTurn(spaces,playerChar);
            showBoard(spaces);

            if(checkWinner(spaces,playerChar,computerChar))
                {
                    gameEndflag=false;
                    break;
                }
            
            if(checkTie(spaces))
                {
                    gameEndflag=false;
                    break;
                }

            std::cout<<"\n .....Computer Thinking .!";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            computerTurn(spaces,computerChar);
            showBoard(spaces);

            if(checkWinner(spaces,playerChar,computerChar))
                {
                    gameEndflag=false;
                    break;
                }
            
            if(checkTie(spaces))
                {
                    gameEndflag=false;
                    break;
                }
        }

        std::cout<<"\n\n          --------GoodBye---------- ";

        std::getchar();
        return 0;
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
        
        return std::toupper(userChar);
    }
void showBoard(char *spaces)
    {
        std::cout<<"\n\n";
        std::cout<<"      |      |      "<<"\n";
        std::cout<<"  "<<spaces[0]<<"   |  "<<spaces[1]<<"   |  "<<spaces[2]<<"  "<<"\n";
        std::cout<<"______|______|______"<<"\n";
        std::cout<<"      |      |      "<<"\n";
        std::cout<<"  "<<spaces[3]<<"   |  "<<spaces[4]<<"   |  "<<spaces[5]<<"  "<<"\n";
        std::cout<<"______|______|______"<<"\n";
        std::cout<<"      |      |      "<<"\n";
        std::cout<<"  "<<spaces[6]<<"   |  "<<spaces[7]<<"   |  "<<spaces[8]<<"  "<<"\n";
        std::cout<<"      |      |      "<<"\n";
    }
void playerTurn(char *spaces,char playerChar)
    {   
        int pos;
        do{
            std::cout<<"Enter the location (1-9) :";
            std::cin>>pos;
            if(!(pos>0)||!(pos<10))
                {
                    std::cout<<"\n-!!!---Please enter valid location......\n\n";
                }
            if(spaces[pos-1]=='X'||spaces[pos-1]=='O')
                {
                    std::cout<<"\n-!! Sorry the location was already filled.....\n\n";
                }
        }while((!(pos>0)||!(pos<10))||(spaces[pos-1]=='X'||spaces[pos-1]=='O'));
        spaces[pos-1]=playerChar;
    }
void computerTurn(char *spaces,char computerChar)
    {
        int pos;
        srand(time(0));
        do
        {
            pos = rand()%9;
        } while (spaces[pos]=='X'||spaces[pos]=='O');
        spaces[pos]=computerChar;
        
    }
bool checkWinner(char *spaces,char playerChar,char computerChar)
    {
        if(spaces[0]==spaces[1]&&spaces[1]==spaces[2])
            {
                if(spaces[0]==playerChar&&spaces[1]==playerChar&&spaces[2]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[3]==spaces[4]&&spaces[4]==spaces[5])
            {
                if(spaces[3]==playerChar&&spaces[4]==playerChar&&spaces[5]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[6]==spaces[7]&&spaces[7]==spaces[8])
            {
                if(spaces[6]==playerChar&&spaces[7]==playerChar&&spaces[8]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[0]==spaces[3]&&spaces[3]==spaces[6])
            {
                if(spaces[0]==playerChar&&spaces[3]==playerChar&&spaces[6]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[1]==spaces[4]&&spaces[4]==spaces[7])
            {
                if(spaces[4]==playerChar&&spaces[1]==playerChar&&spaces[7]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[2]==spaces[5]&&spaces[5]==spaces[8])
            {
                if(spaces[2]==playerChar&&spaces[5]==playerChar&&spaces[8]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[0]==spaces[4]&&spaces[4]==spaces[8])
            {
                if(spaces[0]==playerChar&&spaces[4]==playerChar&&spaces[8]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }
        if(spaces[2]==spaces[4]&&spaces[4]==spaces[6])
            {
                if(spaces[2]==playerChar&&spaces[4]==playerChar&&spaces[6]==playerChar)
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!.....PLAYER WINS.....!!!!....\n\n";
                        return true;
                    }
                else   
                    {
                        std::cout<<"\n";
                        std::cout<<"\n ....!!!!YOU loSE.....COMPUTER WINS.....!!!!....\n\n";
                        return true;
                    }
            }        
        return false;
    }
bool checkTie(char *spaces)
    {
        for(int i=0;i<9;i++)
            {
                if(spaces[i]!='X'&&spaces[i]!='O'){
                    return false;
                }
            }
        std::cout<<"\n\n          ------- ITs A Draw ------";
        return true;
    }
