
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {

    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for(int i = 1; i <= n; i++) {

        for(int w = 1; w <= W; w++) {

            if(wt[i - 1] <= w) {

                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );

            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display DP table
    cout << "\nDP Table:\n";

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> wt[i] >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nMaximum Profit: " << knapsack(W, wt, val, n) << endl;

    return 0;
}

// Theory:
// The 0/1 Knapsack problem is an optimization problem solved using Dynamic Programming (DP). In this problem, we are given a set of items, where each item has a specific weight and value, and a knapsack with limited capacity. The main objective is to maximize the total value of selected items without exceeding the given capacity.

// In this method, each item has only two choices: either we select the complete item (1) or we do not select it (0). We cannot take a fraction of an item.

// A two-dimensional DP table is created to store the maximum profit for different items and knapsack capacities. For each item, we check whether its weight is less than or equal to the current capacity. If it fits, we choose the maximum value between including and excluding the item. Otherwise, we exclude the item.

// Finally, the DP table gives the maximum possible profit at dp[n][W].

// Algorithm: Dynamic Programming.

// Time Complexity: \(O(n \times W)\)

// Space Complexity: \(O(n \times W)\)
// Algorithm / Steps:
// 1. Start the program.
// 2. Read the number of items from the user.
// 3. Read the weight and value of each item.
// 4. Read the maximum capacity of the knapsack.
// 5. Create a two-dimensional DP table of size (n+1) × (W+1) and initialize it with zeros.
// 6. Traverse each item using a loop from 1 to n.
// 7. Traverse each possible capacity using a loop from 1 to W.
// 8. Check whether the current item's weight is less than or equal to the current capacity.
// 9. If the item fits, calculate the maximum value between:
//    - Including the current item.
//    - Excluding the current item.
// 10. If the item does not fit, copy the previous row's value.
// 11. Repeat this process to fill the complete DP table.
// 12. Display the DP table.
// 13. Display the maximum profit stored at dp[n][W].
// 14. Stop the program.





// input ;Enter number of items: 4

// Enter weight and value of item 1: 2 3
// Enter weight and value of item 2: 3 4
// Enter weight and value of item 3: 4 5
// Enter weight and value of item 4: 5 6

// Enter knapsack capacity: 5

//output; DP Table:
// 0    0    0    0    0    0
// 0    0    3    3    3    3
// 0    0    3    4    4    7
// 0    0    3    4    5    7
// 0    0    3    4    5    7

// Maximum Profit: 7

//explain
// Part 1: Header files
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;


// - iostream – For input and output.
// - vector – To store weights, values and the DP table.
// - algorithm – To use the max() function.
// - using namespace std – Avoids writing std:: repeatedly.
// Part 2: Knapsack function
// int knapsack(int W, vector<int> wt, vector<int> val, int n)


// This function calculates the maximum profit.
// - W – Capacity of the bag.
// - wt – Stores the weights of items.
// - val – Stores the values of items.
// - n – Total number of items.
// Step 1: Create DP table
// vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));


// This creates a two-dimensional table.
// - Rows represent the number of items.
// - Columns represent the capacity of the bag.
// - Initially, all values are zero.
// Why do we use n + 1 and W + 1? Because we also need a row for zero items and a column for zero capacity.
// Step 2: Apply nested loops
// for(int i = 1; i <= n; i++) {
//     for(int w = 1; w <= W; w++) {


// - Outer loop selects items one by one.
// - Inner loop checks different bag capacities.
// Step 3: Check item weight
// if(wt[i - 1] <= w)


// This checks whether the current item's weight is less than or equal to the bag's current capacity.

// If the weight fits, we have two choices:

// Choice 1: Include the item
// val[i - 1] + dp[i - 1][w - wt[i - 1]]


// We add the item's value and the best profit possible with the remaining capacity, using the previous items.

// Choice 2: Exclude the item
// dp[i - 1][w]


// We don't select the current item, so we keep the previous maximum profit.
// dp[i][w] = max(
//     val[i - 1] + dp[i - 1][w - wt[i - 1]],
//     dp[i - 1][w]
// );


// The max() function selects whichever choice gives more profit.
// Step 4: If the item does not fit
// else {
//     dp[i][w] = dp[i - 1][w];
// }


// If the item's weight is greater than the bag capacity, we cannot include it. So we copy the previous result.
// Step 5: Display DP table
// for(int i = 0; i <= n; i++) {
//     for(int w = 0; w <= W; w++) {
//         cout << dp[i][w] << "\t";
//     }
//     cout << endl;
// }


// This displays the completed DP table.
// Step 6: Return maximum profit
// return dp[n][W];


// The last cell contains the maximum profit using all items within the given capacity.

// 7. Understand the example
// Our input items are:
// Item	Weight	Value
// Item 1	2	3
// Item 2	3	4
// Item 3	4	5
// Item 4	5	6

// Knapsack capacity = 5.

// We have to select items whose total weight does not exceed 5.
// Step 1: Create the DP table
// We create 5 rows (0 to 4 items) and 6 columns (capacity 0 to 5).
// Initially all values are zero
// Items / Capacity	0	1	2	3	4	5
// 0 items	0	0	0	0	0	0
// 1 item	0	0	0	0	0	0
// 2 items	0	0	0	0	0	0
// 3 items	0	0	0	0	0	0
// 4 items	0	0	0	0	0	0


// Step 2: Calculate maximum profit
// Item 1: Weight = 2, Value = 3.

// If capacity is 2 or more, we can include this item. Maximum profit becomes 3.

// Item 2: Weight = 3, Value = 4.

// For capacity 5, we can select Item 1 and Item 2 together.

// Total weight = 2 + 3 = 5.

// Total value = 3 + 4 = 7.

// Item 3: Weight = 4, Value = 5.

// At capacity 5, the best profit remains 7.

// Item 4: Weight = 5, Value = 6.

// At capacity 5, its value is 6, but the previous combination gives 7. So we keep 7.
// Step 3: Final DP table
// Items / Capacity	0	1	2	3	4	5
// 0 items	0	0	0	0	0	0
// Item 1	0	0	3	3	3	3
// Item 2	0	0	3	4	4	7
// Item 3	0	0	3	4	5	7
// Item 4	0	0	3	4	5	7

// The last cell is dp[4][5] = 7.
// Final answer
// Selected items: Item 1 + Item 2

// Total weight: 2 + 3 = 5

// Maximum profit:
// 7

// 8. Important viva questions
// Question	Answer
// Which technique is used?	Dynamic Programming
// What is 0/1 Knapsack?	Either select the complete item or don't select it
// Why use DP?	To store previous results and avoid repeated calculations
// What is wt[]?	Array of item weights
// What is val[]?	Array of item values
// What is W?	Capacity of the bag
// Why use max()?	To choose the maximum profit
// What is a DP table?	A table that stores calculated results
// Time complexity?	\(O(nW)\)
// Space complexity?	\(O(nW)\)

// 9. Short explanation to tell mam
// "This program implements the 0/1 Knapsack problem using Dynamic Programming. First, we accept the number of items, their weights, values and bag capacity. Then we create a two-dimensional DP table initialized with zeros. We check each item and compare two choices: including the item or excluding it. If the item fits, we select the choice that gives maximum profit using the max function. If it does not fit, we copy the previous result. Finally, the last cell of the DP table gives the maximum profit."
// 10. Easy trick to remember the code
// Remember these 6 steps:
// 1. Accept item weights and values.
// 2. Create a 2D DP table.
// 3. Check each item and capacity.
// 4. Calculate include and exclude choices.
// 5. Store the maximum value.
// 6. Return the last cell as maximum profit.

// Most important formula for your practical:
// \[
// dp[i][w]=\max
// \begin{cases}
// val[i-1]+dp[i-1][w-wt[i-1]]\\
// dp[i-1][w]
// \end{cases}
// \]

// In simple words: We compare including the item and excluding the item, then store whichever gives more profit.