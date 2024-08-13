#include <iostream>
#include <cstdlib>
#include "processChessMoves.h"
void clear_screen() {
    int result = system("cls");
    if (result != 0) {
        cout << "Error clearing screen." << endl;
    }
}
int main()
{
    char chessboard[8][8];

    initializeBoard(chessboard);
    cout << "Initial Board:" << endl;
    printBoard(chessboard);

    int i = 0;

    while (i < count_lines())
    {
        string chess_move = read_move(i + 1);
        cout << "Move:" << chess_move << endl << endl;
        movePiece(chess_move, chessboard);
        printBoard(chessboard);
        char option = 'n';
        while (option != 'y')
        {
            cout << "Move to next move? (y/n)" << endl;
            cin >> option;
        }

        clear_screen();
        i++;

    }


    return 0;
}
