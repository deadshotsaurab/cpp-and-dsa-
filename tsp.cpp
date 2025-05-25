#include <iostream>
#include <vector>

using namespace std;

class NQueens {
private:
    int N;
    vector<vector<int > > board; // Using an integer matrix to store the board

    // Check if it's safe to place a queen at board[row][col]
    bool isSafe(int row, int col) {
        // Check this row on the left side
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1) return false;

        // Check upper diagonal on the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1) return false;

        // Check lower diagonal on the left side
        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j] == 1) return false;

        return true;
    }

    // Recursive function to solve the N-Queens problem
    bool solveNQueens(int col) {
        if (col >= N) return true; // Base case: All queens are placed

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1; // Place the queen

                if (solveNQueens(col + 1)) return true; // Recur to place the next queen

                board[i][col] = 0; // Backtrack: Remove the queen
            }
        }
        return false; // Trigger backtracking
    }

    // Display the board configuration
    void displayBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }

public:
    // Constructor to initialize the board with N
    NQueens(int n) : N(n), board(n, vector<int>(n, 0)) {}

    // Solve and display the solution if it exists
    void solve() {
        if (solveNQueens(0)) {
            cout << "Solution for " << N << "-Queens:\n";
            displayBoard();
        } else {
            cout << "No solution exists for " << N << "-Queens.\n";
        }
    }
};

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    NQueens queens(N);
    queens.solve();

    return 0;
}

