#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
string player_one;
string player_two;
void drawboard()
{
    cout << " "<< board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " "<< board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " "<< board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

char current_marker;
string current_player;

bool place_marker(int box)
{
    int row = box / 3;
    int col;

    if(box%3==0)
    {
        row = row - 1;
        col = 2;
    }
    else
        col = (box%3)-1;

    if(board[row][col]!='X' && board[row][col]!='O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
        return false;
    //cout << row << "," << col << endl;
}

string winner()
{
    for(int i=0;i<3;i++)
    {
        //row-wise
        if((board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X') || (board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O'))
            return current_player;
        //column-wise
        if((board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X') || (board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O'))
            return current_player;
    }

    //diagonal-wise
    if((board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O'))
            return current_player;
    if((board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X') || (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O'))
            return current_player;

    return "0"; //if there is no win no lose situation
}

void swap_player_and_marker()
{
    if(current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if(current_player == player_one)
        current_player = player_two;
    else    
        current_player = player_one;
}

void game()
{
    char marker_p1;
    char marker_p2;
    string player_won;
    cout << "Please enter the name of 1st player : ";
    cin >> player_one;
    cout << "Please enter the name of 2nd player : ";
    cin >> player_two;
    cout << endl;
    cout << "Here is your grid for tic-tac-toe!! Enjoy playing :)" << endl;
    drawboard();
    cout << endl;
    cout << "Please choose the marker from X or O! " << endl;
    cout << player_one << " , Choose your marker : ";  
    cin >> marker_p1;
    while(marker_p1!='X' && marker_p1!='O')
    {
        cout << "Please choose the marker from X or O! " << endl;
        cout << player_one << " , Choose your marker : "; 
        cin >> marker_p1;
        if(marker_p1=='X' || marker_p1=='O')
            break;
    }

    current_player = player_one;
    current_marker = marker_p1;

    for(int i=0;i<9;i++)
    {
        cout << "It is " << current_player << "'s turn. Enter slot where you want to place your marker : ";
        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9)
        {
            cout << "Please enter a valid slot!" << endl;
            i--;
            continue;
        }

        if(!place_marker(slot))
        {
            cout << "Sorry, this slot is already occupied. Try some another slot." << endl;
            i--;
            continue;
        }
        
        drawboard();
        cout << endl;
        player_won = winner();
        if(player_won == player_one)
        {
            cout << "Result : " << player_one << " won! Congrats!";
            break;
        }
        if(player_won == player_two)
        {
            cout << "Result : " << player_two << " won! Congrats!";
            break;
        }
        swap_player_and_marker();
    }
         
    if(player_won == "0")
    {
        cout << "Result : This game is tie, nobody wins or loses!";
    }
}

int main()
{
    game();  
}