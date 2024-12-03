// NUMBER GUESSING GAME
#include <bits/stdc++.h>
using namespace std ;
int main ()
{
    cout << "=============================  WELCOME  =============================" << endl ;
    cout << "==========================       to         =========================" << endl ;
    cout << "=======================  NUMBER-GUESSING GAME  ======================" << endl ;
    cout << endl ;
    int num ;
    int guess ;
    int tries ;
    int range ;
    cout << "Enter the Range up to Which you Want to Guess The Number : " ;
    cin >> range ;
    srand(time(NULL)) ;
    num = (rand() % range) + 1 ;
    tries = 0 ;
    do
    {
        cout << "Enter a Guess Between (1-" << range << "): " ;
        cin >> guess ;
        tries ++ ;
        if(guess > num)
        {
            cout << "Too HIGH!" << endl ;
        }
        else if(guess < num)
        {
            cout << "Too LOW!" << endl ;
        }
        else
        {
            cout << "CORRECT Guess!" << endl ;
            cout << "The Number is " << num << "." << endl ; 
            cout << "Number of tries : " << tries << endl ;
        }
    } while (guess != num);
    cout << endl << "=============================  GAME OVER  =============================" << endl ;
    return 0 ;
}