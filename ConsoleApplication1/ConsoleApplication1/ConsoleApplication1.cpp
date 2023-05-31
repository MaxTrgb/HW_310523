 /*Task1. Write a program that implements the Tic Tac Toe game on a 3x3 two - dimensional array.
 The program should allow the player to enter his moves in the form of row and column coordinates.
 Rules of the game :
 The game is played between two players, one using "X" and the other using "O".
 Players take turns making their moves on free cells of the reachable array.
 The game ends when one of the players gets three of his symbols in a row, column or diagonal.
 After each move, the program should check whether there is already a winner or whether there are no free cells for the move.
 If one of the players wins or the game is tied, the program should display a corresponding messageand end the game.
 The use of multidimensional arrays will make it possible to present the playing fieldand monitor the state of the game.
 You will need logic to verify the winand determine the next player.*/

#include <iostream>
#include <stdlib.h>
using namespace std;

// Function to generate and initialize the game grid
char** GenerateArray(int& N);

// Function to print the game grid
void PrintGrid(char** arr, int& size, bool player, bool isFirstMove);

// Function to convert the number input from the numpad to row and column coordinates
void NumPadAdapter(int& controller, int& row, int& column);

// Function to handle invalid input
void Eror();

// Functions to check for a win in rows, columns, and diagonals
bool Row(char** arr, int size, char P);
bool Columns(char** arr, int size, char P);
bool Diag(char** arr, int size, char P);

// Function to check if a player has won the game
bool Victory(char** arr, int size, char P);

int main()
{
    int count = 0; // Counter for the number of moves
    int N = 3; // Size of the game grid
    char** arr = GenerateArray(N); // Generate and initialize the game grid
    char X = 'X', O = 'O'; // Symbols for the two players
    int row = 0, column = 0; // Variables to store the row and column coordinates of the move
    bool player = true; // Variable to determine the current player (true for Player X, false for Player O)
    int controller = 0; // Variable to store the input from the player

    PrintGrid(arr, N, player, true); // Print the initial game grid

    while (true)
    {
        cout << "\tEnter where to move: ";
        cin >> controller;

        if (controller >= 1 && controller <= 9)
        {
            NumPadAdapter(controller, row, column); // Convert the number input from the numpad to row and column coordinates

            if (arr[row - 1][column - 1] == ' ')
            {
                if (player)
                {
                    arr[row - 1][column - 1] = X; // Update the game grid with the move of Player X
                    PrintGrid(arr, N, player, false); // Print the updated game grid

                    player = false; // Switch to the next player (Player O)
                    if (Victory(arr, N, X)) // Check if Player X has won the game
                    {
                        printf("\n\tPlayer %c Win\n\n", X); // Print the winning message for Player X
                        break;
                    }
                    count++;
                }
                else
                {
                    arr[row - 1][column - 1] = O; // Update the game grid with the move of Player O
                    PrintGrid(arr, N, player, false); // Print the updated game grid

                    player = true; // Switch to the next player (Player X)
                    if (Victory(arr, N, O)) // Check if Player O has won the game
                    {
                        printf("\n\tPlayer %c Win\n\n", O); // Print the winning message for Player O
                        break;
                    }
                    count++;
                }
            }
            else
            {
                Eror(); // Handle invalid move (cell is already occupied)
            }
        }
        else
        {
            Eror(); // Handle invalid input
        }

        if (count == 9) // If all the cells are filled and no one has won, it's a tie
        {
            cout << "\n\t DRAW\n\n\n\n";
            break;
        }
    }

    for (int i = 0; i < N; ++i) // Free the dynamically allocated memory for the game grid
    {
        delete[] arr[i];
    }
    delete[] arr;

    system("pause");
    return 0;
}

// Function to generate and initialize the game grid
char** GenerateArray(int& N)
{
    char** arr = new char* [N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = new char[N];
        for (int j = 0; j < N; ++j)
        {
            arr[i][j] = ' ';
        }
    }
    return arr;
}

// Function to print the game grid
void PrintGrid(char** arr, int& size, bool player, bool isFirstMove)
{
    system("cls");
    if (isFirstMove)
    {
        cout << "\n\tPlayer X move\t\tUse numpad to play";
    }
    else
    {
        if (player)
        {
            cout << "\n\tPlayer O move\t\tUse numpad to play";
        }
        else
        {
            cout << "\n\tPlayer X move\t\tUse numpad to play";
        }
    }
    printf("\n\n\t%c | %c | %c\t\t7 | 8 | 9\n\t---------\t\t---------\n\t%c | %c | %c\t\t4 | 5 | 6\n\t---------\t\t---------\n\t%c | %c | %c\t\t1 | 2 | 3\n\n\n\n",
        arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2], arr[2][0], arr[2][1], arr[2][2]);
}

// Function to convert the number input from the numpad to row and column coordinates
void NumPadAdapter(int& controller, int& row, int& column)
{
    switch (controller)
    {
    case 1:
        row = 3;
        column = 1;
        break;
    case 2:
        row = 3;
        column = 2;
        break;
    case 3:
        row = 3;
        column = 3;
        break;
    case 4:
        row = 2;
        column = 1;
        break;
    case 5:
        row = 2;
        column = 2;
        break;
    case 6:
        row = 2;
        column = 3;
        break;
    case 7:
        row = 1;
        column = 1;
        break;
    case 8:
        row = 1;
        column = 2;
        break;
    case 9:
        row = 1;
        column = 3;
        break;
    }
}

// Function to handle invalid input
void Eror()
{
    cout << "\tInvalid move. Please try again.\n\n";
}

// Functions to check for a win in rows, columns, and diagonals
bool Row(char** arr, int size, char P)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i][0] == P && arr[i][1] == P && arr[i][2] == P)
        {
            return true;
        }
    }
    return false;
}

bool Columns(char** arr, int size, char P)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[0][i] == P && arr[1][i] == P && arr[2][i] == P)
        {
            return true;
        }
    }
    return false;
}

bool Diag(char** arr, int size, char P)
{
    if ((arr[0][0] == P && arr[1][1] == P && arr[2][2] == P) || (arr[0][2] == P && arr[1][1] == P && arr[2][0] == P))
    {
        return true;
    }
    return false;
}

// Function to check if a player has won the game
bool Victory(char** arr, int size, char P)
{
    return (Row(arr, size, P) || Columns(arr, size, P) || Diag(arr, size, P));
}
