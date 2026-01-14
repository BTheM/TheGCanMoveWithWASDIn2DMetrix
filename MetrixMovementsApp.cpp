#include <iostream>
#include <conio.h>

using namespace std;

void TwoDNumbers(char Character, short &Vertical, short &Herozintal)
{
    switch (Character)
    {
    case 'W':
    {
        if (Vertical == 0)
        {
            return;
        }
        Vertical -= 1;
        return;
    }
    case 'S':
    {
        if (Vertical == 4)
        {
            return;
        }
        Vertical += 1;
        return;
    }
    case 'D':
    {
        if (Herozintal == 4)
        {
            return;
        }
        Herozintal += 1;
        return;
    }
    case 'A':
    {
        if (Herozintal == 0)
        {
            return;
        }
        Herozintal -= 1;
        return;
    }
    }
}

void TilesScreen()
{
    char character = ' ';
    string Space = "          ";
    string g = "    g     ";
    string TilesMetrix[5][5] =
    { {Space, Space, Space, Space, Space},
        {Space, Space, Space, Space, Space},
        {Space, Space, Space, Space, Space},
        {Space, Space, Space, Space, Space},
        {Space, Space, Space, Space, Space}
    };
    short VerticalMovement = 4;
    short HerozanticalMovement = 3;
    short OldVerticalPosition = VerticalMovement;
    short OldHerozanticalPosition = HerozanticalMovement;
    while (true)
    {
        system("cls");

        TilesMetrix[VerticalMovement][HerozanticalMovement] = g;
        for (short i = 0; i < 5; i++)
        {
            for (short j = 0; j < 5; j++)
            {
                cout << TilesMetrix[i][j];
                
            }
            cout << endl;
        }
        cout << "\nMove with WASD" << endl;
        _kbhit();
        character = _getch();
        character = toupper(character);

        TilesMetrix[OldVerticalPosition][OldHerozanticalPosition] = Space;
        TwoDNumbers(character, VerticalMovement, HerozanticalMovement);
        OldVerticalPosition = VerticalMovement;
        OldHerozanticalPosition = HerozanticalMovement;
    }
}

int main()
{
    TilesScreen();


    return 0;
}