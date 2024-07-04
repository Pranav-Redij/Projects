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
  //1)horizontal and vertical
  for(int i=0;i<=2;i++)
  {
    if((board[i][0]==board[i][1]&&board[i][0]==board[i][2]) || (board[0][i]==board[1][i]&&board[0][i]==board[2][i]))
    {
      return false;
    }
  }
  //2)diagonal case
  if((board[0][0]==board[1][1]&&board[0][0]==board[2][2]) || (board[0][2]==board[1][1]&&board[0][2]==board[2][0]))
  {
    return false;
  }
  // Check for draw (improved logic)
  bool hasEmptySquare = false;
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return true;
        // an empty square is found
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
   cout<<"Please try again \n";
    player_turn();
    return;
   //break; 
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
    return;
  }
}

bool equals3(char a,char b,char c)
{
  if(a==b && a==c)
  return true;
  
  return false;
}
char checkWinner(char boardcopy[3][3])
{
   char winner = 'P';

  // horizontal
  for (int i = 0; i < 3; i++) {
    if (equals3(boardcopy[i][0], boardcopy[i][1], boardcopy[i][2])) {
      winner = boardcopy[i][0];
    }
  }

  // Vertical
  for (int i = 0; i < 3; i++) {
    if (equals3(boardcopy[0][i], boardcopy[1][i], boardcopy[2][i])) {
      winner = boardcopy[0][i];
    }
  }

  // Diagonal
  if (equals3(boardcopy[0][0], boardcopy[1][1], boardcopy[2][2])) {
    winner = boardcopy[0][0];
  }
  if (equals3(boardcopy[2][0], boardcopy[1][1], boardcopy[0][2])) {
    winner = boardcopy[2][0];
  }

  int openSpots = 0;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (boardcopy[i][j] != 'X' && boardcopy[i][j] != 'O') {
        openSpots++;
      }
    }
  }

  if (winner == 'P' && openSpots == 0) {
    return 'D';//draw
  } else {
    return winner;
  }
}
int minmax(char boardcopy[3][3],int depth,bool isMaximizing)
{
  char result = checkWinner(boardcopy);
  
  unordered_map<char,int>mp;
  mp['X']=-1;
  mp['O']=1;
  mp['D']=0;//draw

  if (result == 'X' || result == 'O' || result == 'D') {
    return mp[result];
  }

  if (isMaximizing) {
    int bestScore = INT_MIN;//will return winning score as we wanted to won the ai
    for (int  i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        // Is the spot available?
        if (boardcopy[i][j]!='X' && boardcopy[i][j]!='O') {
          char ai='O';
          char num=boardcopy[i][j];
          boardcopy[i][j]=ai;
          int score = minmax(boardcopy, depth + 1, false);
          boardcopy[i][j]=num;
          bestScore = max(score, bestScore);
        }
      }
    }
    return bestScore;
  } else {
    int bestScore = INT_MAX;//will return loosing score as we wanted to lost the human
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        // Is the spot available?
        if (boardcopy[i][j]!='X' && boardcopy[i][j]!='O') {
          char human='X';
          char num=boardcopy[i][j];
          boardcopy[i][j]=human;
          int score = minmax(boardcopy, depth + 1, true);
          boardcopy[i][j]=num;
          bestScore = min(score, bestScore);
        }
      }
    }
    return bestScore;
  }
}
int findoutbest()
{
    char boardcopy[3][3];
    //boardcopy=board;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        boardcopy[i][j] = board[i][j];
      }
    }
    int ni,nj;
    int score=INT_MIN;
    int maxscore=INT_MIN;
    for(int i=0;i<=2;i++)
    {
      for(int j=0;j<=2;j++)
      {
        if(boardcopy[i][j]!='X' && boardcopy[i][j]!='O')
        {
          //it is empty and we can place there 
          char ai='O';
          char num=boardcopy[i][j];
          boardcopy[i][j]=ai;
          score=minmax(boardcopy,0,false);//it will return the score
          boardcopy[i][j]=num;
          if(score>maxscore)
          {
            maxscore=score;
            ni=i;
            nj=j;
          }
        }
      }
    }
    int map[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    return map[ni][nj];
}
void computer_player_turn()
{
   choice=findoutbest();

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
   cout<<"Please try again \n";
    computer_player_turn();
    return;
   //break; 
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
    return;
  }
}

void display_board()
{ 
    system("cls");              //this is for clearing screen so new board will not print
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
void doubleplayer()
{
  while(gameover())
  {
    display_board();
    player_turn();
    gameover();
  }
  if(turn=='X'&& draw==false)
  {
    display_board();  
    cout<<"Player2 [O] Win's!!! \n";
  }
  else if(turn=='O' && draw==false)
  {
    display_board();  
    cout<<"Player1 [X] Win's!!! \n";
  }else{
    cout<<"draw\n";
  }
}
void singleplayer()
{
  while(gameover())
  {
    display_board();
    if(turn=='X')
    {
      player_turn();
    }else{
      //computer will take decision
      computer_player_turn();
    }
    gameover();
  }
  if(turn=='X'&& draw==false)
  {
    display_board();  
    cout<<"Player2 [O] Win's!!! \n";
  }
  else if(turn=='O' && draw==false)
  {
    display_board();  
    cout<<"Player1 [X] Win's!!! \n";
  }else{
    cout<<"draw\n";
  }
}
int main()
{ 
 cout<<"\n1.Single Player Mode  2.Double Player Mode\n";
 cout<<"\nCHOOSE OPTION:";
 int op=0;
 cin>>op;
 
 if(op==1)
 {
     singleplayer();
 }else if(op==2){
     doubleplayer();
 }else{
     cout<<"\ninvalid choice.........";
 }
 return 0;   
}
