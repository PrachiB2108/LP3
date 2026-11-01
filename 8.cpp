
#include <iostream>
#include <vector>
using namespace std;

#define N 8

// Function to print the chessboard
void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check whether placing queen is safe
bool isSafe(vector<vector<int>>& board, int row, int col) {

    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to solve 8-Queens using Backtracking
bool solve(vector<vector<int>>& board, int row) {

    // Base case: All queens are placed
    if (row == N) {
        cout << "Final 8-Queens Solution:\n";
        printBoard(board);
        return true;
    }

    // Try placing queen in every column
    for (int col = 0; col < N; col++) {

        if (isSafe(board, row, col)) {

            // Place queen
            board[row][col] = 1;

            // Recursive call for next row
            if (solve(board, row + 1))
                return true;

            // Backtracking: Remove queen
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    // Initialize chessboard with all zeros
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place first queen at position (0, 0)
    board[0][0] = 1;

    cout << "Starting with first Queen at (0, 0):\n";
    printBoard(board);

    // Solve for remaining queens starting from row 1
    if (!solve(board, 1)) {
        cout << "No solution found!";
    }

    return 0;
}

// Theory:
// The 8-Queens problem is a classic problem solved using the Backtracking technique. The objective is to place 8 queens on an 8×8 chessboard in such a way that no two queens attack each other.

// In this problem, the first queen is already placed at position (0, 0). We need to place the remaining 7 queens on the chessboard.

// A queen can attack another queen in the same row, column or diagonal. Therefore, before placing a queen, we check whether the position is safe or not. If the position is safe, we place the queen and move to the next row using recursion. If no safe position is available, we remove the previously placed queen and try another position. This process is called Backtracking.

// The process continues until all 8 queens are successfully placed on the chessboard. Finally, the program displays the solution matrix.

// Algorithm: Backtracking.

// Time Complexity: \(O(N!)\) (commonly stated as an upper-bound estimate for this row-wise search).

// Space Complexity: \(O(N^2)\) for the chessboard.
// Algorithm / Steps:
// 1. Start the program.
// 2. Define the chessboard size as 8×8.
// 3. Initialize the chessboard with all zeros, where 0 represents an empty cell.
// 4. Place the first queen at position (0, 0).
// 5. Display the initial chessboard.
// 6. Start placing the remaining queens from row 1.
// 7. Check each column in the current row to find a safe position.
// 8. Check whether the position is safe by verifying:
//    - No queen is present in the same column.
//    - No queen is present in the upper-left diagonal.
//    - No queen is present in the upper-right diagonal.
// 9. If the position is safe, place the queen and move to the next row using recursion.
// 10. If all 8 queens are placed successfully, display the final chessboard.
// 11. If no safe position is available, remove the previously placed queen and try another position. This process is called backtracking.
// 12. Repeat until a valid solution is found.
// 13. Stop the program.

// Starting with first Queen at (0, 0):
// Q . . . . . . .
// . . . . . . . .
// . . . . . . . .
// . . . . . . . .
// . . . . . . . .
// . . . . . . . .
// . . . . . . . .
// . . . . . . . .

// Final 8-Queens Solution:
// Q . . . . . . .
// . . . . . . Q .
// . . . . Q . . .
// . . . . . . . Q
// . . Q . . . . .
// . . . . . Q . .
// . . . Q . . . .
// . Q . . . . . .


// Explanation:
// - printBoard() displays the chessboard.
// - vector<vector<int>>& board passes the chessboard by reference.
// - Outer loop i represents rows.
// - Inner loop j represents columns.
// - If the value is 1, it prints Q (Queen).
// - Otherwise, it prints . (Empty position).
// - endl moves to the next row.
// Remember:
// - 1 = Queen
// - 0 = Empty position
// 3. isSafe() Function
// bool isSafe(vector<vector<int>>& board, int row, int col)


// This function checks whether placing a queen at the given row and column is safe or not.

// It returns:
// - true – position is safe.
// - false – position is not safe.
// A. Check column
// for (int i = 0; i < row; i++) {
//     if (board[i][col] == 1)
//         return false;
// }


// Checks whether another queen is already present in the same column.

// If a queen is found, it returns false.

// B. Check upper-left diagonal
// for (int i = row - 1, j = col - 1;
//      i >= 0 && j >= 0; i--, j--) {
//     if (board[i][j] == 1)
//         return false;
// }


// Checks the upper-left diagonal of the current position.

// If another queen is found, the position is unsafe.

// C. Check upper-right diagonal
// for (int i = row - 1, j = col + 1;
//      i >= 0 && j < N; i--, j++) {
//     if (board[i][j] == 1)
//         return false;
// }


// Checks the upper-right diagonal.

// If another queen is found, it returns false.
// return true;


// If no queen is found in the checked positions, it returns true.

// Why do we check only upward directions?

// Because our program places queens row by row, from top to bottom. So queens can only exist in previous rows.
// 4. solve() Function – Main Logic
// bool solve(vector<vector<int>>& board, int row)


// This function places queens using the Backtracking technique.

// It takes:
// - board – chessboard matrix.
// - row – current row where we want to place a queen.
// A. Base condition
// if (row == N) {
//     cout << "Final 8-Queens Solution:\n";
//     printBoard(board);
//     return true;
// }


// - Checks whether all 8 queens are placed.
// - If row == 8, all rows have been completed.
// - Prints the final chessboard.
// - Returns true because the solution is found.
// B. Try every column
// for (int col = 0; col < N; col++) {


// Checks all 8 columns in the current row, one by one.

// C. Check safe position
// if (isSafe(board, row, col)) {


// Calls the isSafe() function to check whether the current position is safe.

// D. Place Queen
// board[row][col] = 1;


// If the position is safe, place the queen by storing 1 in that position.

// E. Recursive call
// if (solve(board, row + 1))
//     return true;


// - Calls the same function for the next row.
// - row + 1 moves to the next row.
// - If all queens are placed successfully, returns true.
// F. Backtracking
// board[row][col] = 0;


// If placing the queen does not lead to a solution, remove the queen by setting the position back to 0.

// Then try another column.

// This process is called Backtracking.
// return false;


// If no column works in the current row, return false.
// 5. Main Function
// int main() {


// Execution of the program starts here.

// A. Initialize chessboard
// vector<vector<int>> board(N, vector<int>(N, 0));


// Creates an 8×8 matrix and initializes all positions with zero.

// B. Place first queen
// board[0][0] = 1;


// Places the first queen at row 0 and column 0.

// Remember: Array indexing starts from 0.

// C. Display initial board
// cout << "Starting with first Queen at (0, 0):\n";
// printBoard(board);


// Displays the chessboard with the first queen already placed.

// D. Solve the problem
// if (!solve(board, 1)) {
//     cout << "No solution found!";
// }


// - Starts placing the remaining queens from row 1.
// - ! means NOT.
// - If the solve() function returns false, it displays "No solution found!".
// return 0;


// Ends the program successfully.

// 6. Flow of the program
// Start

// Initialize 8×8 chessboard
// Place first queen at (0, 0)
// Check safe position using isSafe()

// Place queen and move to next row
// All 8 queens placed?
// Yes
// Print solution

// No
// Backtrack and try another column



// 7. Important viva questions
// Question	Answer
// Which technique is used?	Backtracking
// What is N?	Size of chessboard (8)
// What does Q represent?	Queen
// What does 0 represent?	Empty position
// What does 1 represent?	Queen placed
// What is isSafe()?	Checks whether a position is safe
// What is recursion?	A function calling itself
// What is backtracking?	Undoing a choice and trying another choice
// Why use row + 1?	To move to the next row
// What is the base condition?	row == N
// Why use return true?	To indicate that a solution is found

// 8. How to explain to mam in practical
// You can say:

// "Ma'am, this program solves the 8-Queens problem using Backtracking. First, we create an 8×8 chessboard and initialize all positions with zero. Then we place the first queen at position (0, 0). After that, we check safe positions in each row using the isSafe function. We check the column and both diagonals. If the position is safe, we place the queen and recursively move to the next row. If no solution is found, we remove the queen and try another position. This process is called Backtracking. Finally, when all 8 queens are placed safely, we display the chessboard."
// Remember these 4 most important functions:
// 1. printBoard() – Displays chessboard.
// 2. isSafe() – Checks safe position.
// 3. solve() – Places queens using recursion and backtracking.
// 4. main() – Initializes board and starts execution.