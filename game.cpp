#include <iostream>
using namespace std;

void singlePlayer(bool &winStatus);
void doublePlayer(bool &winStatus);
void menu(bool& winStatus);
void initializeBoard(char (&board)[3][3]);
bool checkWin(const char (&board)[3][3]);
void displayBoard(const char (&board)[3][3]);
void whoseTurn(bool &playerOne, bool &playerTwo);
void playerMove (char (&board)[3][3]);
void playerTwoMove (char (&board)[3][3]);
void aiMove(char (&board)[3][3]);


int main() { 
bool winStatus = false;
menu(winStatus);
return 0;
}

void menu(bool &winStatus){
    int choice;
    cout<<"Welcome to Tic Tac Toe"<<endl;
    cout<<"Please make a choice for single or double player"<<endl;
    cout<<"1. Single Player"<<endl;
    cout<<"2. Double Player"<<endl;
    cin >> choice;
  // choice = ;
    if (choice == 1){
    singlePlayer(winStatus);
    }else if (choice == 2)
    doublePlayer(winStatus);



}
void singlePlayer(bool &winstatus){// so you can use pass by reference of an argument of a function then pass it by reference
    char board[3][3];
    cout<<"Welcome to the single Player game!"<<endl;
    initializeBoard(board);
    bool playerTurn = false;
    bool playerTwoTurn = true;
    //below is where the game play start
    while (true){
        displayBoard(board);
        whoseTurn(playerTurn, playerTwoTurn);
        if (playerTurn){
            playerMove(board);
        }else if (playerTwoTurn){
            aiMove(board);
        }
        cout<<endl;
        if (checkWin(board)){
            cout<<"Congratulations! You Win!"<<endl;
            break;
        };
    }
    
   

}
// TODO: implement the double player
void doublePlayer(bool &winStatus){
    char board[3][3];
    cout<<"Welcome to the double Player game!"<<endl;
    initializeBoard(board);
    bool playerTurn = false;
    bool playerTwoTurn = true;

    while(true){
        displayBoard(board);
        whoseTurn(playerTurn, playerTwoTurn);
        if (playerTurn){
            playerMove(board);
        }
        else if (playerTwoTurn){
            playerTwoMove(board);
        }
        cout<<endl;
        if (checkWin(board)){
            cout<< (playerTurn ? "Player 1 Wins!": "Player 2 Wins!")<<endl;
            break;
        }

    }

    
}

void initializeBoard(char (&board)[3][3]){
   int count = 0;
   
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board [i][j] = '0'+ count;
            count++;
        }
        
    }
}

void displayBoard(const char (&board)[3][3]){
    for (int i =0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<< board[i][j];
            if (j<2 && i<2){
                cout<<"_|";
            }
            else if (j==2 && i<2){
                cout<<"_";
            }
            else if (j<2 && i==2){
                cout<<" |";
            }
        }
        
        cout<<endl;
        
    }
}

void playerMove(char (&board)[3][3]){
int move;
cout<<"Player 1 - X"<<endl;
cout<<"AI player - O"<<endl;
cout<<"Please make the first move by putting in the the number"<<endl;
cin>> move;

while (move < 0 || move > 8 || board[move/3][move%3]!= '0' + move){
    cout<<"Invalid Move. Please Try Again."<<endl;
    cin >> move;
}

board[move / 3] [move % 3] = 'X';

}

void playerTwoMove(char (&board)[3][3]){
int move;
cout<<"Player 1 - X"<<endl;
cout<<"AI player - O"<<endl;
cout<<"Please make the first move by putting in the the number"<<endl;
cin>> move;

while (move < 0 || move > 8 || board[move/3][move%3]!= '0' + move){
    cout<<"Invalid Move. Please Try Again."<<endl;
    cin >> move;
}

board[move / 3] [move % 3] = 'O';


}


void whoseTurn(bool &playerOne, bool &playerTwo){
    if (playerOne){
        playerOne = false;
        playerTwo = true;
    }
    else {
        playerOne = true;
        playerTwo = false;
    }
}

bool checkWin(const char (&board)[3][3]){
    for (int i=0; i<3; i++){
        if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2])){//checking row-wise
            return true;
        }
    }

    for (int i=0; i<3; i++){
        if ((board[0][i]==board[1][i]) && (board[1][i]==board[2][i])){//checking column-wise
            return true;
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    else 
        return false;

}

void aiMove (char (&board)[3][3]){
    srand(time(0));
    int x, y;

    do {
        x = rand()%3;
        y = rand()%3;
    } while (board[x][y] == 'X' ||  board[x][y] == 'O' );//wrong logic. keep doing until it is not equal
    //the condition inside while should be ==

    board[x][y] = 'O';
}

