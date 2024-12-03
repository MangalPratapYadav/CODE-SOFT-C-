#include <bits/stdc++.h>
using namespace std ;
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '} ;
// welcome Function
void welcome()
{
    cout << "=============================  WELCOME  =============================" << endl ;
    cout << "===========================       to       ==========================" << endl ;
    cout << "========================  TIC-TAC-TOE GAME  =========================" << endl ;
    cout << endl ;
}
// Display Function
void display_board()
{
    cout << "Current BOARD Position" << endl << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   " << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
    cout << "-----------------------" << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   " << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
    cout << "-----------------------" << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   " << endl ;
    cout << "   " << "    |   " << "    |   " << endl ;
}
// Get X Player Choice Function
void get_X_player_choice()
{
    while(true)
    {
        cout << "Select Your Position (1 - 9) : " ;
        int choice ;
        cin >> choice ;
        choice -= 1 ;
        if(choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice From (1 - 9) Only." << endl ;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position." << endl ;
        }
        else{
            board[choice] = 'X' ;
            break ;
        }
    }
}
// Get O Player Choice Function
void get_O_player_choice()
{
    while(true)
    {
        cout << "Select Your Position (1 - 9) : " ;
        int choice ;
        cin >> choice ;
        choice -= 1 ;
        if(choice < 0 || choice > 8)
        {
            cout << "Please Select Your Choice From (1 - 9) Only." << endl ;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position." << endl ;
        }
        else{
            board[choice] = 'O' ;
            break ;
        }
    }
}
// Get Computer Choice Function
void get_computer_choice()
{
    srand(time(0)) ;
    int choice ;
    do
    {
        choice = rand() % 10 ;
    } while (board[choice] != ' ') ;
    board[choice] = 'O' ;
    
}
// Count Board function 
int count_board(char symbol)
{
    int total = 0 ;
    for(int i = 0 ; i < 9 ; i ++)
    {
        if(board[i] == symbol)
        {
            total ++ ;
        }
    }
    return total ;
}
// Check Winner Function
char check_winner()
{
    // row wise
    if(board[0] != ' ' and board[0] == board[1] and board[1] == board[2])
    {
        return board[2] ;
    }
    if(board[3] != ' ' and board[3] == board[4] and board[4] == board[5])
    {
        return board[5] ;
    }
    if(board[6] != ' ' and board[6] == board[7] and board[7] == board[8])
    {
        return board[7] ;
    }
    // column wise
    if(board[0] != ' ' and board[0] == board[3] and board[3] == board[6])
    {
        return board[3] ;
    }
    if(board[1] != ' ' and board[1] == board[4] and board[4] == board[7])
    {
        return board[4] ;
    }
    if(board[2] != ' ' and board[2] == board[5] and board[5] == board[8])
    {
        return board[5] ;
    }
    // diagonal wise
    if(board[0] != ' ' and board[0] == board[4] and board[4] == board[8])
    {
        return board[4] ;
    }
    if(board[2] != ' ' and board[2] == board[4] and board[4] == board[6])
    {
        return board[4] ;
    }
    if(count_board('X') + count_board('O') < 9)
    {
        return 'C' ;
    }
    else
    {
        return 'D' ;
    }
}
// Computer vs Player
void computer_vs_player()
{
    string player_name ;
    cout << endl ;
    cout << "Enter Your Name : " ;
    cin >> player_name ;
    while(true)
    {
        display_board() ;
        if(count_board('X') == count_board('O'))
        {
            cout << player_name << "'s Turn." << endl ;
            get_X_player_choice() ;
        }
        else{
            get_computer_choice() ;
        }
        char winner = check_winner() ;
        if(winner == 'X')
        {
            display_board() ;
            cout << player_name << " Won The Game." << endl ;
            break;
        }
        else if(winner == 'O')
        {
            display_board() ;
            cout << "Computer Won The Game." << endl ;
            break;
        }
        else if(winner == 'D')
        {
            cout << "Game is Draw." << endl ;
            break;
        }
    }
}
// Player1 vs Player2
void player_vs_player()
{
    string X_player_name ;
    string O_player_name ;
    cout << endl ;
    cout << "Enter the (X) Player Name : " ;
    cin >> X_player_name ;
    cout << endl ;
    cout << "Enter the (O) Player Name : " ;
    cin >> O_player_name ;
    while(true)
    {
        display_board() ;
        if(count_board('X') == count_board('O'))
        {
            cout << X_player_name << "'s Turn." << endl ;
            get_X_player_choice() ;
        }
        else 
        {
            cout << O_player_name << "'s Turn." << endl ;
            get_O_player_choice() ;
        }
        char winner = check_winner() ;
        if(winner == 'X')
        {
            display_board() ;
            cout << X_player_name << " Won The Game." << endl ;
            break;
        }
        else if(winner == 'O')
        {
            display_board() ;
            cout << O_player_name << " Won The Game." << endl ;
            break;
        }
        else if(winner == 'D')
        {
            display_board() ;
            cout << "Game is Draw." << endl ;
            break;
        }
    }
}
// Play Again
void play_again()
{
    cout << endl ;
    string again ;
    cout << "Enter (Y/y) To Play Again Or for Quit Enter (n/N) : " ;
    cin >> again ;
    if(again == "Y" || again == "y")
    {
        cout << endl ;
        int mode ;
        do
        {
            cout << endl ;
            cout << "1 -> Computer VS Player." << endl ;
            cout << "2 -> Player VS Player." << endl << endl ;
            cout << "Select The Game Mode : " ;
            cin >> mode ;
            if(mode != 1 && mode != 2)
            {
                cout << endl << "Please Select Valid Game Mode." << endl ;
            }
        } while (mode != 1 && mode != 2);   
        if(mode == 1)
        {
            fill(begin(board), end(board), ' ') ;

            display_board() ;
            computer_vs_player() ;
            play_again() ;
        }
        if(mode == 2)
        {
            fill(begin(board), end(board), ' ') ;
            display_board() ;
            player_vs_player() ;
            play_again() ;
        }
    }
    else if(again == "N" || again == "n")
    {
        cout << endl << "=============================  GAME OVER  =============================" << endl ;
    }
    else
    {
        play_again() ;
    }
}
// Tic Tac Toe Function
void tictactoe()
{
    welcome() ;
    display_board() ;
    cout << endl ;
    int mode ;
    do
    {
        cout << endl ;
        cout << "1 -> Computer VS Player." << endl ;
        cout << "2 -> Player VS Player." << endl << endl ;
        cout << "Select The Game Mode : " ;
        cin >> mode ;
        if(mode != 1 && mode != 2)
        {
            cout << endl << "Please Select Valid Game Mode." << endl ;
        }
    } while (mode != 1 && mode != 2);   
    if(mode == 1)
    {
        computer_vs_player() ;
        play_again() ;
    }
    if(mode == 2)
    {
         player_vs_player() ;
         play_again() ;
    }
}
// Now Our Main Function
int main ()
{
    tictactoe() ;
    return 0 ;
}