#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
const int BOARD_SIZE = 8;
using namespace std;
int count_lines() //counts the number of lines in the file chess_moves.txt
{
    fstream fin;
    int count = 0;
    string temp;
    fin.open("chess_moves.txt");
    while (getline(fin, temp))
    {
        count++;
    }
    fin.close();
    return count;
}
void printBoard(char board[8][8])
{
    char letter = 'a';
    for (int i = 0;i < 8;i++)
    {
        cout << 8 - i;
        for (int j = 0;j < 8;j++)
        {
            cout << "|" << setw(4) << left << board[i][j];
        }
        cout << endl;
    }
    cout << "  ";
    for (int j = 0;j < 8;j++)
    {
        cout << setw(5) << left << (char)((int)letter + j);
    }
    cout << endl;

}
void initializeBoard(char chessboard[BOARD_SIZE][BOARD_SIZE])
{
    // Initialize an empty board
    //lower case is one player and uppercase is the other
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    // copy the initialized empty board into the chessboard we passed in
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            chessboard[i][j] = initialBoard[i][j];
        }
    }
}
string read_move(int turn)
{
    fstream fin;
    fin.open("chess_moves.txt");
    string move;
    if (turn > count_lines() || turn < 1)
    {
        move = ".";
        return move;
    }
    int i = 0;
    while (i < turn)
    {
        getline(fin, move);
        i++;
    }
    fin.close();
    return move;
}
int fileToIndex(char file)
{
    int col = (int)file - 97;
    return col;
}
int rankToIndex(char rank)
{
    int boardrowno = (int)rank - 48;
    int row = 8 - boardrowno;
    return row;
}
bool valid_move(string move, char chessboard[8][8])
{
    char initial_pos_letter = move[2];
    char initial_pos_number = move[3];
    int row = rankToIndex(initial_pos_number);
    int col = fileToIndex(initial_pos_letter);
    if (chessboard[row][col] == '.')
        return false;

    return true;
}
void movePiece(string chess_move, char board[8][8])
{
    if (!valid_move(chess_move, board))
    {
        cout << "Invalid move" << endl;
        return;
    }

    char initial_pos_letter = chess_move[2];
    char initial_pos_number = chess_move[3];
    char final_pos_letter = chess_move[5];
    char final_pos_number = chess_move[6];
    int i_row = rankToIndex(initial_pos_number);
    int i_col = fileToIndex(initial_pos_letter);
    int f_row = rankToIndex(final_pos_number);
    int f_col = fileToIndex(final_pos_letter);

    char piece = board[i_row][i_col];
    board[i_row][i_col] = '.';
    board[f_row][f_col] = piece;
}