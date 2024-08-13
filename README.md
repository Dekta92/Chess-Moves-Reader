# Chess Moves Reader

## Introduction
This project incoorporates the use of essential programming constructs such as functions, file processing, and arrays in C++. The goal is to develop high-quality code with meaningful variable names, function names, and comments, while also ensuring an artistic presentation. The project reads chess moves from a file and shows a visual representation of the chessboard after the move has been made. It allows the user to study the board before displaying the next move.

## Project Components
- **Chess Move Notation**: A simplified notation to represent chess moves.
- **Chessboard Representation**: A 2D array representing the chessboard.
- **File Processing**: Reading chess moves from a text file.
- **Move Application**: Applying moves to the chessboard and updating its state.
- **Output**: Printing the board before and after each move.

## Simplified Chess Move Notation
Chess moves are represented as strings in the following format:
PieceType SourcePosition-DestinationPosition

- **PieceType**: 
  - 'K' for King
  - 'Q' for Queen
  - 'R' for Rook
  - 'B' for Bishop
  - 'N' for Knight
  - 'P' for Pawn
- **SourcePosition**: The starting position in standard chess notation (e.g., 'e2').
- **DestinationPosition**: The ending position in standard chess notation (e.g., 'e4').
 ### Examples
- `P e2-e4` (Move a Pawn from e2 to e4)
- `N g1-f3` (Move a Knight from g1 to f3)
- `B f1-c4` (Move a Bishop from f1 to c4)

## Text File Content
Create a text file named `chess_moves.txt` containing the sample moves listed below. Ensure this file is located in the same directory as your C++ program.


## Getting Started
1. Clone this repository or download the source code.
2. Create the `chess_moves.txt` file in the same directory as the C++ program. A sample file has been provided. It can be edited following the same chess move notation.
3. Compile the C++ program using your preferred compiler.
4. Run the program to see the chess moves applied to the chessboard.
