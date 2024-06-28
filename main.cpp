#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int randomValue()
{
    srand(time(0));

    return rand() % 5;
}
void cookingMine(int arr[5][5])
{
    int bomb1 = randomValue();
    int bomb2 = randomValue();
    int bomb3 = randomValue();
    int bomb4 = randomValue();
    int bomb5 = randomValue();
    int bomb6 = randomValue();
    int bomb7 = randomValue();
    int bomb8 = randomValue();
    int bomb9 = randomValue();
    int bomb0 = randomValue();
    arr[bomb1][bomb2] = 0;
    arr[bomb3][bomb4] = 0;
    arr[bomb5][bomb6] = 0;
    arr[bomb7][bomb8] = 0;
    arr[bomb9][bomb0] = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = 1;
            }
        }
    }
    return;
}
void print(int arr[5][5], int brr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (brr[i][j] == 1)
                cout << arr[i][j];
            else
                cout << " X ";
        }
        cout << endl;
    }
    return;
}
void openmine(int arr[5][5], int brr[5][5], int r, int c, int &TakeOut, int &winPrice, int BetAmount)
{
    if (arr[r][c] == 0)
    {
        brr[r][c] = 1;
        print(arr, brr);
        cout << "\t YOU HAVE FOUND A BOMB" << endl;
        TakeOut = 1;
        winPrice = 0;
        return;
    }
    else
    {
        brr[r][c] = 1;

        print(arr, brr);
        cout << "\t YOU HAVE FOUND A DIAMOND" << endl;
        winPrice = winPrice * 2;
        return;
    }
}
int main()
{

    cout << "\t***** WELCOME TO STACK MINES *****" << endl;
    cout << "RULES: " << endl;
    cout << "1. You have entry the mine slot coordinate in matrix wise" << endl;
    cout << "2. At every correct mine your bet money will get into 2X times" << endl;
    cout << "3. if you open bomb mine then you have lost the game" << endl;
    cout << "3. THERE ARE 5 BOMBS AT MAX" << endl;
    cout << "4. if you loose once you will loose all your money" << endl;
    cout << "5. enter the coordinate as raw col (starting from 0 to 4)" << endl;
    cout << "5. 1 represent : diamond & 0 represents : bomb in this game+6+9" << endl;

    int TakeOut = 0;
    int winPrice = 0;
    int BetAmount;
    int Raw, Col;
    int arr[5][5] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int brr[5][5] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    cookingMine(arr);

    cout << "Enter the amount you wanna bet" << endl;
    cin >> BetAmount;
    winPrice = BetAmount;
    cout << "YOUR GAME IS STARTING..." << endl;
    print(arr, brr);
    while (TakeOut == 0)
    {
        cout << "Enter the coordinate of mine :" << endl;
        cout << "->";
        cin >> Raw >> Col;
        winPrice = BetAmount;
        openmine(arr, brr, Raw, Col, TakeOut, winPrice, BetAmount);
        int check;
        if (TakeOut != 1)
        {
            cout << "do you want to take out all money then press 12 or to continue press anything" << endl;
            cin >> check;
            if (check == 12)
            {
                TakeOut = 1;
                cout << "your win price is" << winPrice << endl;
            }
        }
    }

    return 0;
}