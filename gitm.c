// name: Ali Haider Kachwalla
// unikey: akac6194
// SID: 520446193

// Code starts here: Necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Recursive check functions moving in each direction, returning total in a row
int checkUp(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkUp(board, x, y-1, user);
        } else return 0;
    }
}
int checkDown(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkDown(board, x, y+1, user);
        } else return 0;
    }
}
int checkLeft(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkLeft(board, x-1, y, user);
        } else return 0;
    }
}
int checkRight(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkRight(board, x+1, y, user);
        } else return 0;
    }
}
int checkLeftUp(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkLeftUp(board, x-1, y-1, user);
        } else return 0;
    }
}
int checkLeftDown(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkLeftDown(board, x-1, y+1, user);
        } else return 0;
    }
}
int checkRightUp(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkRightUp(board, x+1, y-1, user);
        } else return 0;
    }
}
int checkRightDown(char board[19][19], int x, int y, char user) {
    if (x < 0 || x > 18 || y < 0 || y > 18) return 0;
    else {
        if (board[x][y] == user) {
            return 1 + checkRightDown(board, x+1, y+1, user);
        } else return 0;
    }
}

// Function to implement recursive checks
int check(char board[19][19], int x, int y) {
    // Set initial char to make life easier
    char user = board[x][y];
    // Checks for > 5 due to initial stone being counted twice
    if (checkUp(board, x, y, user) + checkDown(board, x, y, user) > 5 ||
        checkLeft(board, x, y, user) + checkRight(board, x, y, user) > 5 ||
        checkLeftUp(board, x, y, user) + checkRightDown(board, x, y, user) > 5 ||
        checkRightUp(board, x, y, user) + checkLeftDown(board, x, y, user) > 5) {
            // Using initial char: decide who wins
            if (user == '#') printf("Black wins!\n");
            else printf("White wins!\n");

            return 0;
        }

    // Check for a full board by making check negative if empty space is found
    int full = 0;
    for (int i = 0; i < 19; i++) {
        if (full) break;
        for (int j = 0; j < 19; j++) {
            if (full) break;
            if (board[i][j] == '.') {
                full = 1;
            }
        }
    }

    // Printing from full flag if empty space not found
    if (full == 0) {
        printf("Wow, a tie!\n");
        return 0;
    } 

    return 1;
}

// Displays previous moves in order
int history(char moves[]) {
    for (int i = 0; i < 722; i++) {
        // End print if moves[i] is empty
        if (moves[i] != '.') {
            printf("%c", moves[i++]);
            // All moves stored as chars so reconverting before printing
            printf("%d", (int) moves[i]);
        } else break;
    }
    printf("\n");

    return 1;
}

int main() {
    // Setting up initial variables
    // Turn counter
    int turn = 0;
    // Initial mist pos
    int xMist = 9;
    int yMist = 9;
    // Board + filling with empty spaces
    char board[19][19];
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            board[i][j] = '.';
        }
    }
    // Moves + filling with empty spaces
    char moves[772];
    for (int i = 0; i < 256; i++) {
        moves[i] = '.';
    }

    while (1) {
        // Continuously get new inputs until while loop exited
        char cmd[2000];
        fgets(cmd, 2000, stdin);
 
        // Check for which command entered
        if (strcmp(cmd, "term\n") == 0) {
            // Exit program with no other output
            return 1;
        } else if (strcmp(cmd, "resign\n") == 0) {
            // Whoever's turn it is, the other wins
            if (turn % 2 == 1) {
                printf("Black wins!\n");
            } else {
                printf("White wins!\n");
            }
            break;
        } else if (strcmp(cmd, "who\n") == 0) {
            // Who's turn is it?
            if (turn % 2 == 0) {
                printf("B\n");
            } else {
                printf("W\n");
            }
        // Only did an exact mask for initial processing, later on further comparison
        } else if (strncmp(cmd, "place ", strlen("place ")) == 0) {
            // Check for number of spaces
            int spaces = 0;
            for (int i = 0; i < strlen(cmd); i++) {
                if (cmd[i] == ' ') spaces += 1;
            }   
            if (spaces != 1) {
                printf("Invalid!\n");
                continue;
            }

            // Tracking locations, set to 99 initially to trigger error if unchanged
            int X = 99;
            int Y = 99;

            // Checking if first part of coordinate is a letter
            if (isalpha(cmd[6]) == 0) {
                printf("Invalid!\n");
                continue;
            } else {
                // Storing numerical equivalent
                X = (int) cmd[6] - 65;
            }

            // Checking first digit of second coordinate
            if (cmd[7] > '0' && cmd[7] <= '9') {
                // If 1 digit
                if (cmd[8] == '\n') {
                    Y = atoi(&cmd[7]) - 1;
                // If 2 digits
                } else if (cmd[8] >= '0' && cmd[8] <= '9') {
                    if (cmd[9] == '\n') {
                        Y = atoi(&cmd[7]) - 1;
                    }
                }
            }

            // If coordinates are off board (can't be less than 0 due to enforced minimums)
            if (X > 18 || Y > 18) {
                printf("Invalid coordinate\n");
                continue;
            }
            
            // If position is empty
            if (board[X][Y] == '.') {
                if (turn % 2 == 0) {
                    board[X][Y] = '#';
                } else {
                    board[X][Y] = 'o';
                }

                // New mist centre location
                xMist = (5*(X+1)*(X+1) + 3*(X+1) + 4)%19;
                yMist = (4*(Y+1)*(Y+1) + 2*(Y+1) - 4)%19;

                // Record stone being placed in moves
                moves[turn*2] = (char) X + 65;
                moves[turn*2 + 1] = (char) Y + 1;

                // Check if game ends
                if (check(board, X, Y) == 0) break;
            // If position not empty
            } else {
                printf("Occupied coordinate\n");
                continue;
            }

            // Increment turn if all goes well
            turn += 1;
        } else if (strcmp(cmd, "view\n") == 0) {
            // Finding start and end points for pring
            int xStart = xMist - 3;
            int xEnd = xMist + 3;
            int yStart = yMist - 3;
            int yEnd = yMist + 3;
            
            // Print centre of mist
            printf("%c%d,", (char) (xMist + 65), (yMist + 1));
            // Print pieces in mist
            for (int i = yEnd; i >= yStart; i = i - 1) {
                for (int j = xStart; j <= xEnd; j++) {
                    if (i < 0 || i > 18) printf("x");
                    else if (j < 0 || j > 18) printf("x");
                    else printf("%c", board[j][i]);
                }
            }
            printf("\n");
        } else if (strcmp(cmd, "history\n") == 0) {
            history(moves);
        // No match to valid commands
        } else {
            printf("Invalid!\n");
        }
    }
    // Sequence when game ends
    history(moves);
    printf("Thank you for playing!\n");
    return 0;
}