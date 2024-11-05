#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
   
    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {  // Fix: Use == for comparison
            return false;
        }
    }
   
    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {  // Fix: Use == for comparison
            return false;
        }
    }
   
    return true;
}

bool SolveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {  // All queens are placed
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (issafe(board, i, col, n)) {
            board[i][col] = 1;  // Place queen
            
            if (SolveNQueens(board, col + 1, n)) {  // Recur to place next queen
                return true;
            }
            
            board[i][col] = 0;  // Backtrack
        }
    }
    
    return false;
}

void PrintBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  // Fix: Correct inner loop variable to j
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int firstrow, firstcol;
    cout << "Enter row and col for the first queen: ";
    cin >> firstrow >> firstcol;
    
    if (firstcol >= n || firstcol < 0 || firstrow >= n || firstrow < 0) {
        cout << "Enter valid numbers for row and column." << endl;
        return 1;
    }
    
    board[firstrow][firstcol] = 1;  // Fix: Place the first queen
    
    // Start placing queens from the next column
    if (SolveNQueens(board, 1, n)) {  // Fix: Start from column 1
        PrintBoard(board, n);
    } else {
        cout << "No solution exists for the given initial position." << endl;
    }

    return 0;
}
