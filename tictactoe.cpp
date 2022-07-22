//my first game and project to.....😉😎
#include<iostream>
using namespace std;
int choice;
char turn='X';
int row,column;
bool draw=false;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool gameover()
{
  //check win
  for(int i=0;i<=2;i++)
  {
    if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] || board[0][i]==board[1][i]&&board[0][i]==board[2][i])
    {
      return false;
    }
  }
  if(board[0][0]==board[1][1]&&board[0][0]==board[2][2] || board[0][2]==board[1][1]&&board[0][2]==board[2][0])
  {
    return false;
  }
  //checking game over(if there is any box that is not filled)
   for(int i=0;i<=2;i++)
   {
      for(int j=0;j<=2;j++)
      {
        if(board[i][j]!='X'||board[i][j]!='O')
        {
          return true;
        }
      }
   }
   //draw game
   draw=true;
   return false;
}

void player_turn()
{  
  if(turn=='X')
   {
   cout<<"\n Player1 [X] Turn:";
   }
   if(turn=='O')
   {
   cout<<"\n Player2 [O] Turn:";
   }
   cin>>choice;

   switch(choice)
 {
   case 1:
   row=0;
   column=0;
   break;
   case 2:
   row=0;
   column=1;
   break;
   case 3:
   row=0;
   column=2;
   break;
   case 4:
   row=1;
   column=0;
   break;
   case 5:
   row=1;
   column=1;
   break;
   case 6:
   row=1;
   column=2;
   break;
   case 7:
   row=2;
   column=0;
   break;
   case 8:
   row=2;
   column=1;
   break;
   case 9:
    row=2;
    column=2;
   break;
   default:
   cout<<"Invalid choice"<<endl;
   break; 
  }
if(turn=='X' && board[row][column]!='X' && board[row][column]!='O' )
{
  board[row][column]='X';
  turn='O';
}
else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O')
{
  board[row][column]='O';
  turn='X';
}else{
  cout<<"Wrong choice!!!!! \n Please try again \n";
  player_turn();
}
}
void display_board()
{ system("cls");              //this is for clearing screen so new board will not print
  cout<<"Tick Cross Game"<<endl;
  cout<<"  Player1 [X] \n  Player2 [O] \n\n\n ";
  cout<<"\t     |     |     \n";  
  cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n"; 
  cout<<"\t_____|_____|_____\n";
  cout<<"\t     |     |     \n";  
  cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";   
  cout<<"\t_____|_____|_____\n";
  cout<<"\t     |     |     \n";  
  cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n"; 
  cout<<"\t     |     |     \n"; 
}
int main()
{ 
  while(gameover())
{
  display_board();
  player_turn();
  gameover();
}
if(turn=='X'&& draw=='false')
{
  cout<<"Player2 [O] Win's!!! \n";
}
else if(turn=='O' && draw=='false')
{
  cout<<"Player1 [X] Win's!!! \n";
}else{
  cout<<"draw\n";
}
 return 0;   
}