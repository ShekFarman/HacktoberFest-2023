#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board
char player = 'X'; // Starting player

void initializeBoard() {
    // Initialize the board with numbers 1 to 9
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count + '0'; // Store the number as a character
            count++;
        }
    }
}

void displayBoard() {
    // Display the Tic-Tac-Toe board
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|"); // Display vertical separators
        }
        if (i < 2) printf("\n---|---|---\n"); // Display horizontal separators
    }
    printf("\n");
}

int isWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    
    return 0; // No winner yet
}

int isDraw() {
    // Check if the board is full and there is no winner (draw)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return 0; // There are still empty spots
            }
        }
    }
    return 1; // The game is a draw
}

void switchPlayer() {
    // Switch between players 'X' and 'O'
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

void makeMove() {
    int move;
    printf("Player %c, enter the number of the cell where you want to place your mark: ", player);
    scanf("%d", &move);

    // Check if the move is valid
    if (move >= 1 && move <= 9) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player; // Place the mark
        } else {
            printf("Invalid move! Cell already taken.\n");
            makeMove(); // Retry the move
        }
    } else {
        printf("Invalid input! Please enter a number between 1 and 9.\n");
        makeMove(); // Retry the move
    }
}

int main() {
    initializeBoard(); // Set up the game board
    int gameStatus = 0; // 0 means the game is still ongoing

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        displayBoard(); // Show the board to players
        makeMove(); // Player makes a move

        if (isWin()) {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        } else if (isDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer(); // Change the turn to the next player
    }

    return 0;
}
