#include "Casino.cpp"
using namespace std;

int main()
{
    Casino New;
    card deck[52];
    int selectGame=10;
    while (totalMoney>0 || selectGame!=0)
    {
        cout << "WELCOME TO MY CASINO!\n";
        cout << "Your total MONEY: Rp." << totalMoney << "\n";
        cout << "Press 1 to play BlackJack\n";
        cout << "Press 2 to play Baccarat\n";
        cout << "Press 0 to stop playing\n";
        cin >> selectGame;
        if (selectGame==1)
        {
            New.playBlackJack(deck);
        }
        else if (selectGame==2)
        {
            New.playBaccarat(deck);
        }
        else if (selectGame==0)
        {
            return 0;
        }
    }
    return 0;
}
