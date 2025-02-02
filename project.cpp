#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Constants for the board and players
const char User = 'X';
const char AI = 'O';
const char Empty = '-';

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout <<endl;;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

bool isGameOver(const vector<vector<char>>& board) {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != Empty && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true; 
        if (board[0][i] != Empty && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true; 
    }
    if (board[0][0] != Empty && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] != Empty && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true; 

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == Empty)
                return false; // Game is not over
        }
    }
    return true; 
}

int evaluateBoard(const vector<vector<char>>& board) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == AI) return 10; // AI wins
            if (board[i][0] == User) return -10; // User wins
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == AI) return 10;
            if (board[0][i] == User) return -10;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == AI) return 10;
        if (board[0][0] == User) return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == AI) return 10;
        if (board[0][2] == User) return -10;
    }
    return 0; 
}


int minimax(vector<vector<char>>& board, int depth, bool isMaximizing, int alpha, int beta) {
    int score = evaluateBoard(board);

   
    if (score == 10) return score - depth; 
    if (score == -10) return score + depth; 
    if (isGameOver(board)) return 0;

    if (isMaximizing) {
        int bestScore = -numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == Empty) {
                    board[i][j] = AI;
                    bestScore = max(bestScore, minimax(board, depth + 1, false, alpha, beta));
                    board[i][j] = Empty;
                    alpha = max(alpha, bestScore);
                    if (beta <= alpha)
                     break; 
                }
            }
        }
        return bestScore;
    } else {
        int Good_Score = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == Empty) {
                    board[i][j] = User;
                    Good_Score = min(Good_Score, minimax(board, depth + 1, true, alpha, beta));
                    board[i][j] = Empty;
                    beta = min(beta, Good_Score);
                    if (beta <= alpha)
                     break; 
                }
            }
        }
        return Good_Score;
    }
}

// Function for the AI's move
void aiMove(vector<vector<char>>& board) {
    int Good_Score = -numeric_limits<int>::max();
    int Good_MoveRow = -1, Good_MoveCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == Empty) {
                board[i][j] = AI;
                int moveScore = minimax(board, 0, false, -numeric_limits<int>::max(), numeric_limits<int>::max());
                board[i][j] = Empty;

                if (moveScore > Good_Score) {
                    Good_Score = moveScore;
                    Good_MoveRow = i;
                    Good_MoveCol = j;
                }
            }
        }
    }

    board[Good_MoveRow][Good_MoveCol] = AI;
}


int main() {
    vector<vector<char>> board(3, vector<char>(3, Empty)); 
    bool User_Turn = true;

    cout << "Welcome to Tic-Tac-Toe!"<<endl;
    cout << "You are X, and the AI is O."<<endl;

    while (!isGameOver(board)) {
        displayBoard(board);

        if (User_Turn) {
            int row, col;
            cout << "Raj Your_Turn! Enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != Empty) {
                cout << "Wrong_move. Try again!"<<endl;
                continue;
            }

            board[row][col] = User;
        } else {
            cout << "AI's turn..."<<endl;
            aiMove(board);
        }

        User_Turn = !User_Turn;
    }

    displayBoard(board);

    // Determine the result
    int result = evaluateBoard(board);
    if (result == 10)
        cout << "AI wins!"<<endl;
    else if (result == -10)
        cout << "You win!"<<endl;
    else
        cout << "It's a draw!"<<endl;

    return 0;
}