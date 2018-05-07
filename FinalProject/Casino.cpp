#include "Casino.hpp"

Casino::Casino(){}
Casino::~Casino(){}

void Casino::printCard(card &c)
{
    if (c.Rank==0)
    {
        cout << "2";
    }
    else if (c.Rank==1)
    {
        cout << "3";
    }
    else if (c.Rank==2)
    {
        cout << "4";
    }
    else if (c.Rank==3)
    {
        cout << "5";
    }
    else if (c.Rank==4)
    {
        cout << "6";
    }
    else if (c.Rank==5)
    {
        cout << "7";
    }
    else if (c.Rank==6)
    {
        cout << "8";
    }
    else if (c.Rank==7)
    {
        cout << "9";
    }
    else if (c.Rank==8)
    {
        cout << "t";
    }
    else if (c.Rank==9)
    {
        cout << "J";
    }
    else if (c.Rank==10)
    {
        cout << "Q";
    }
    else if (c.Rank==11)
    {
        cout << "K";
    }
    else if (c.Rank==12)
    {
        cout << "A";
    }
    if (c.Suit==0)
    {
        cout << "C";
    }
    else if (c.Suit==1)
    {
        cout << "D";
    }
    else if (c.Suit==2)
    {
        cout << "H";
    }
    else if (c.Suit==3)
    {
        cout << "S";
    }
}

void Casino::printDeck(card deck[])
{
    for (int i=0;i<52;i++)
    {
        printCard(deck[i]);
        cout << " ";
    }
    cout << "\n";
}

void Casino::swapCard(card &a,card &b)
{
    card temp;
    temp=a;
    a=b;
    b=temp;
}

void Casino::shuffleDeck(card deck[])
{
    unsigned seed = time(0);
    srand(seed);
    
    for (int i=0;i<52;i++)
    {
        swap(deck[rand()%52],deck[rand()%52]);
    }
}

int Casino::getCardValue(card x)
{
    if (x.Rank==Rank_Ace)
    {
        return 11;
    }
    else if (x.Rank>=Rank_10)
    {
        return 10;
    }
    else
    {
        return (x.Rank+2);
    }
}

void Casino::playBaccarat(card deck[52])
{
    int pTotal=0;
    int bTotal=0;
    int bet=0;
    int select=10;
    int card=0;
    for (int suit=0;suit<Max_Suit; suit++)
    {
        for (int rank=0;rank<Max_Rank; rank++)
        {
            deck[card].Suit = static_cast<Suit>(suit);
            deck[card].Rank = static_cast<Rank>(rank);
            card++;
        }
    }
    shuffleDeck(deck);
    
    cout << "Let's Play Baccarat!\n\n";
    
    while (select!=0 && totalMoney>0)
    {
        cout << "Your total money is Rp" << totalMoney << "\n";
        cout << "Press 1 to bet on Player\n";
        cout << "Press 2 to bet on Banker\n";
        cout << "Press 3 to bet on tie\n";
        cout << "Press 0 to go back to main menu\n";
        cin >> select;
        
        if (select==1 || select==2 || select==3)
        {
            cout << "Enter you bet amount: ";
            cin >> bet;
            if (bet>totalMoney)
            {
                cout << "Invalid Input!\n";
                break;
            }
            
            cout << "\nPlayer's Card:\n";
            cout << " ----  ----\n|    ||    |\n| ";
            printCard(deck[0]);
            cout << " || ";
            printCard(deck[2]);
            cout << " |\n|    ||    |\n ----  ----\n";
            pTotal = (getCardValue(deck[0]) + getCardValue(deck[2])) % 10;
            cout << "Player Total: " << pTotal << "\n";
            
            cout << "\nBanker's Card:\n";
            cout << " ----  ----\n|    ||    |\n| ";
            printCard(deck[1]);
            cout << " || ";
            printCard(deck[3]);
            cout << " |\n|    ||    |\n ----  ----\n";
            bTotal = (getCardValue(deck[1]) + getCardValue(deck[3])) % 10;
            cout << "Banker Total: " << bTotal << "\n";
            
            if (pTotal<6)
            {
                cout << "\nPlayer draw:\n";
                cout << " ----\n|    |\n| ";
                printCard(deck[4]);
                cout << " |\n|    |\n ----\n";
                pTotal= (pTotal + getCardValue(deck[4])) % 10;
                cout << "Player Total: " << pTotal << "\n";
                if (bTotal<3)
                {
                    cout << "\nBanker draw:\n";
                    cout << " ----\n|    |\n| ";
                    printCard(deck[5]);
                    cout << " |\n|    |\n ----\n\n";
                    bTotal = (bTotal + getCardValue(deck[5])) % 10;
                    cout << "Banker Total: " << bTotal << "\n";
                }
                else if (bTotal==3)
                {
                    if (getCardValue(deck[4])!=8)
                    {
                        cout << "\nBanker draw:\n";
                        cout << " ----\n|    |\n| ";
                        printCard(deck[5]);
                        cout << " |\n|    |\n ----\n\n";
                        bTotal = (bTotal + getCardValue(deck[5])) % 10;
                        cout << "Banker Total: " << bTotal << "\n";
                    }
                }
                else if (bTotal==4)
                {
                    if (getCardValue(deck[4])>=2 && getCardValue(deck[4])<=7)
                    {
                        cout << "\nBanker draw:\n";
                        cout << " ----\n|    |\n| ";
                        printCard(deck[5]);
                        cout << " |\n|    |\n ----\n\n";
                        bTotal = (bTotal + getCardValue(deck[5])) % 10;
                        cout << "Banker Total: " << bTotal << "\n";
                    }
                }
                else if (bTotal==5)
                {
                    if (getCardValue(deck[4])>=4 && getCardValue(deck[4])<=7)
                    {
                        cout << "\nBanker draw:\n";
                        cout << " ----\n|    |\n| ";
                        printCard(deck[5]);
                        cout << " |\n|    |\n ----\n\n";
                        bTotal = (bTotal + getCardValue(deck[5])) % 10;
                        cout << "Banker Total: " << bTotal << "\n";
                    }
                }
                else if (bTotal==6)
                {
                    if (getCardValue(deck[4])==6 || getCardValue(deck[4])==7)
                    {
                        cout << "\nBanker draw:\n";
                        cout << " ----\n|    |\n| ";
                        printCard(deck[5]);
                        cout << " |\n|    |\n ----\n\n";
                        bTotal = (bTotal + getCardValue(deck[5])) % 10;
                        cout << "Banker Total: " << bTotal << "\n";
                    }
                }
                if (select==1)
                {
                    if (bTotal>=pTotal)
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                    else if (pTotal>bTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + bet;
                    }
                }
                else if (select==2)
                {
                    if (bTotal>pTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + (bet*0.95);
                    }
                    else if (pTotal>=bTotal)
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                }
                else if (select==3)
                {
                    if (bTotal==pTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + (bet*8);
                    }
                    else
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                }
            }
            else
            {
                if (bTotal<6)
                {
                    cout << "\nBanker draw:\n";
                    cout << " ----\n|    |\n| ";
                    printCard(deck[4]);
                    cout << " |\n|    |\n ----\n\n";
                    bTotal = (bTotal + getCardValue(deck[4])) % 10;
                    cout << "Banker Total: " << bTotal << "\n";
                }
                if (select==1)
                {
                    if (pTotal>bTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + bet;
                    }
                    else if (bTotal>=pTotal)
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                }
                else if (select==2)
                {
                    if (bTotal>pTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + (bet*0.95);
                    }
                    else if (pTotal>=bTotal)
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                }
                else if (select==3)
                {
                    if (bTotal==pTotal)
                    {
                        cout << "You Win!\n\n";
                        totalMoney = totalMoney + (bet*8);
                    }
                    else
                    {
                        cout << "You Lose!\n\n";
                        totalMoney = totalMoney - bet;
                    }
                }
            }
        }
        if (select==0)
        {
            break;
        }
        shuffleDeck(deck);
    }
}

void Casino::playBlackJack(card deck[52])
{
    int pTotal=0;
    int bTotal=0;
    string Hit;
    int index=3;
    int bet=0;
    int select=10;
    int card=0;
    for (int suit=0;suit<Max_Suit; suit++)
    {
        for (int rank=0;rank<Max_Rank; rank++)
        {
            deck[card].Suit = static_cast<Suit>(suit);
            deck[card].Rank = static_cast<Rank>(rank);
            card++;
        }
    }
    
    shuffleDeck(deck);
    
    cout << "Let's Play BlackJack!\n\n";
    
    while (totalMoney>0 && select!=0)
    {
        cout << "Your total money is Rp" << totalMoney << "\n";
        cout << "Press 1 to Play\n";
        cout << "Press 0 to go back to main menu\n";
        cin >> select;
        
        if (select==1)
        {
            cout << "Enter bet: ";
            cin >> bet;
            if (bet>totalMoney)
            {
                cout << "Invalid Input!\n";
                break;
            }
            cout << "Your Cards: \n";
            cout << " ----  ----\n|    ||    |\n| ";
            printCard(deck[0]);
            cout << " || ";
            printCard(deck[1]);
            cout << " |\n|    ||    |\n ----  ----\n";
            pTotal = getCardValue(deck[0]) + getCardValue(deck[1]);
            cout << "your total is: ";
            cout << pTotal << "\n\n";
            
            if (pTotal==21)
            {
                cout << "Dealer's Cards: \n";
                cout << " ----  ----\n|    ||    |\n| ";
                printCard(deck[2]);
                cout << " || ";
                printCard(deck[index]);
                cout << " |\n|    ||    |\n ----  ----\n";
                bTotal = getCardValue(deck[2]) + getCardValue(deck[index]);
                cout << "Dealer's total is: ";
                cout << bTotal << "\n";
                
                if (bTotal==21)
                {
                    cout << "\nIts a DRAW!\n\n";
                }
                else
                {
                    cout << "\nNatural 21, You WIN!\n\n";
                    totalMoney = totalMoney + bet;
                }
            }
            
            else
            {
                cout << "Dealer's Card: \n";
                cout << " ----\n|    |\n| ";
                printCard(deck[2]);
                cout << " |\n|    |\n ----\n";
                bTotal = getCardValue(deck[2]);
                cout << "Dealer's total is: ";
                cout << bTotal << "\n\n";
                
                while (true)
                {
                    cout << "Hit?";
                    cin >> Hit;
                    if (Hit=="yes")
                    {
                        cout << "\nYou draw: \n";
                        cout << " ----\n|    |\n| ";
                        printCard(deck[index]);
                        cout << " |\n|    |\n ----\n";
                        pTotal = pTotal + getCardValue(deck[index]);
                        cout << "Your Total is: ";
                        cout << pTotal << "\n\n";
                        index++;
                        if (pTotal>21)
                        {
                            if (deck[0].Rank==12 || deck[1].Rank==12 || deck[index-3].Rank==12 || deck[index-2].Rank==12 || deck[index-1].Rank==12)
                            {
                                pTotal-=10;
                                cout << "Your Total now (Since you have ace): ";
                                cout << pTotal << "\n\n";
                            }
                            else
                            {
                                cout << "Bust! You LOSE!\n\n";
                                totalMoney = totalMoney - bet;
                                break;
                            }
                        }
                    }
                    else if (Hit=="no")
                    {
                        cout << "Dealer's Cards: \n";
                        cout << " ----  ----\n|    ||    |\n| ";
                        printCard(deck[2]);
                        cout << " || ";
                        printCard(deck[index]);
                        cout << " |\n|    ||    |\n ----  ----\n";
                        bTotal = getCardValue(deck[2]) + getCardValue(deck[index]);
                        cout << "Dealer's total is: ";
                        cout << bTotal << "\n\n";
                        index++;
                        while (true)
                        {
                            
                            if (bTotal<17)
                            {
                                cout << "Dealer draw: \n";
                                cout << " ----\n|    |\n| ";
                                printCard(deck[index]);
                                cout << " |\n|    |\n ----\n";
                                bTotal = bTotal + getCardValue(deck[index]);
                                cout << "\nDealer's total is: ";
                                cout << bTotal << "\n\n";
                                index++;
                            }
                            else if (bTotal>21)
                            {
                                cout << "Dealer bust! You WIN!\n\n";
                                totalMoney = totalMoney + bet;
                                break;
                            }
                            else
                            {
                                cout << "Dealer stand\n";
                                cout << "Your total is: ";
                                cout << pTotal << "\n";
                                cout << "Dealer's total is: ";
                                cout << bTotal << "\n\n";
                                
                                if (bTotal>pTotal)
                                {
                                    cout << "You LOSE!\n\n";
                                    totalMoney = totalMoney - bet;
                                }
                                else if (bTotal==pTotal)
                                {
                                    cout << "Its a DRAW!\n\n";
                                }
                                else
                                {
                                    cout << "You WIN!\n\n";
                                    totalMoney = totalMoney + bet;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        else if (select==0)
        {
            break;
        }
        shuffleDeck(deck);
    }
}
