
// g++ --version
//     sudo apt install build-essential
//     pass student
// clear
// pwd
// cd Desktop
// touch 72311158J.cpp
//     g++ 72311158J.cpp
//     ./a.out


#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}

int fract_knapsact(vector<int>val,vector<int>wt,int W){
    int n=val.size();
    vector<pair<double,int>>ratio(n,make_pair(0.0,0));

    for(int i=0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare);

    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(wt[idx]<=W){
            ans+=val[idx];
            W-=wt[idx];
        }else{
            ans+=ratio[i].first*W;
            W=0;
            break;
        }
    }
    cout<<"max value = "<<ans<<endl;
    return ans;
}

int main(){
    int W,n;
    cout<<"Enter total number of product : ";
   cin>>n;
    vector<int>val(n);
    vector<int>wt(n);
   
    cout<<"Enter total Weight : ";
   cin>>W;
    
   cout<<"Enter Value Array : ";
    for(int i=0;i<n;i++){
        int x;
         cin>>x;
         val[i]=x; 

    }

    cout<<"Enter Weight Array : ";
    for(int i=0;i<n;i++){
         int x;
         cin>>x; 
         wt[i]=x;
    }
    fract_knapsact(val,wt,W);

    return 0;
}
// Theory:
// The Fractional Knapsack problem is an optimization problem solved using the Greedy Method. In this problem, we are given a set of items, each having a specific value and weight, and a knapsack with limited capacity. The main objective is to maximize the total value of items placed in the knapsack without exceeding its capacity.

// First, we calculate the value-to-weight ratio of each item using the formula:
// \[
// Ratio = \frac{Value}{Weight}
// \]

// Then, we sort all the items in descending order according to their ratios. The item with the highest ratio is selected first. If the complete item fits into the remaining capacity, we take the whole item. Otherwise, we take only the required fraction of that item to fill the knapsack.

// This process continues until the knapsack becomes full or all items are considered. Finally, the maximum total value is calculated and displayed.

// Time Complexity: \(O(n\log n)\)

// Space Complexity: \(O(n)\)

// 1. Algorithm: Fractional Knapsack Using Greedy Method
// 1. Start the program.
// 2. Read the number of products n.
// 3. Read the knapsack capacity W.
// 4. Read the value array val[] and weight array wt[].
// 5. Calculate the value-to-weight ratio of each product using val[i] / wt[i].
// 6. Store the ratio and original index of each product in a pair.
// 7. Sort all products in descending order according to their ratios.
// 8. Initialize ans = 0.
// 9. Traverse the sorted products one by one.
// 10. Check whether the product's weight is less than or equal to the remaining capacity.
// 11. If yes, select the complete product, add its value to ans and subtract its weight from W.
// 12. Otherwise, select the fraction of the product that fits, add its value (ratio × W) to ans, set W = 0 and stop.
// 13. Display the maximum value.
// 14. Stop the program.
















// give me step













// Algorithm / Steps:
// 1. Start the program.
// 2. Read the number of items, total knapsack capacity, values and weights from the user.
// 3. Calculate the value-to-weight ratio of each item using the formula:
// \[
// Ratio = \frac{Value}{Weight}
// \]

// 4. Store each item's ratio and original index using a pair.
// 5. Sort all items in descending order according to their ratios.
// 6. Initialize the maximum value (ans = 0).
// 7. Traverse the sorted items one by one.
// 8. If the item's weight is less than or equal to the remaining capacity, select the complete item, add its value to the answer and update the remaining capacity.
// 9. Otherwise, select only the fraction of the item that fits into the remaining capacity and add its value to the answer.
// 10. Repeat until the knapsack becomes full or all items are considered.
// 11. Display the maximum value.
// 12. Stop the program.



// 1. What is Fractional Knapsack?
// Fractional Knapsack is a Greedy Algorithm.

// Suppose you have:
// - A bag with limited capacity.
// - Different products with different weights and values.
// - You want to get maximum value.
// You can take a complete product or a fraction (part) of a product.

// Main formula:
// \[
// Ratio = \frac{Value}{Weight}
// \]

// We select the product with the highest ratio first.
// 2. Code explanation
// Part 1: Header files
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;


// - iostream – used for input and output.
// - vector – used to store values and weights.
// - algorithm – used for sorting.
// - using namespace std – avoids writing std:: every time.
// Part 2: Compare function
// bool compare(pair<double,int>p1,pair<double,int>p2){
//     return p1.first>p2.first;
// }


// Explanation:
// - bool – returns true or false.
// - pair<double,int> – stores two values together.
// - p1.first – ratio of first item.
// - p2.first – ratio of second item.
// - > – sorts ratios in descending order.
// Why use this function?

// To arrange products from highest ratio to lowest ratio.
// Part 3: Fractional Knapsack function
// int fract_knapsact(vector<int>val,vector<int>wt,int W){


// This function takes three parameters:
// Parameter	Meaning
// val	Array of product values
// wt	Array of product weights
// W	Total capacity of bag

// int n=val.size();


// Finds the total number of products.
// Part 4: Create ratio vector
// vector<pair<double,int>>ratio(n,make_pair(0.0,0));


// Creates a vector that stores:
// - First: Value/Weight ratio.
// - Second: Original index of the product.
// For example:

// {6,0} means ratio is 6 and original index is 0.
// Part 5: Calculate ratio
// for(int i=0;i<n;i++){
//     double r=val[i]/(double)wt[i];
//     ratio[i]=make_pair(r,i);
// }


// Explanation:
// - Loop runs for every product.
// - Calculates value divided by weight.
// - (double) converts weight into decimal division.
// - make_pair(r,i) stores ratio and index.
// Example:

// Value = 60, Weight = 10

// Ratio = 60/10 = 6.
// Part 6: Sort the ratio
// sort(ratio.begin(),ratio.end(),compare);


// Sorts products according to their ratios in descending order.

// ratio.begin() – starting position.

// ratio.end() – ending position.

// compare – comparison function.
// Part 7: Initialize answer
// int ans=0;


// Stores the maximum total value.
// Part 8: Select products
// for(int i=0;i<n;i++){
//     int idx=ratio[i].second;


// - Loop visits each sorted product.
// - idx stores the original index of the product.
// Condition 1:
// if(wt[idx]<=W){
//     ans+=val[idx];
//     W-=wt[idx];
// }


// If the product's weight is less than or equal to remaining capacity:
// 1. Take the complete product.
// 2. Add its value to the answer.
// 3. Subtract its weight from remaining capacity.
// Condition 2:
// else{
//     ans+=ratio[i].first*W;
//     W=0;
//     break;
// }


// If the complete product does not fit:
// 1. Take only the fraction that fits.
// 2. Calculate its value using ratio × remaining capacity.
// 3. Make remaining capacity zero.
// 4. Stop the loop using break.
// Part 9: Print maximum value
// cout<<"max value = "<<ans<<endl;
// return ans;


// Displays the maximum value and returns the answer.
// Part 10: Main function
// int main(){
//     int W,n;


// - W – total capacity.
// - n – number of products.
// cout<<"Enter total number of product : ";
// cin>>n;


// Takes the number of products from the user.
// vector<int>val(n);
// vector<int>wt(n);


// Creates two vectors of size n.
// - val stores product values.
// - wt stores product weights.
// cout<<"Enter total Weight : ";
// cin>>W;


// Takes the maximum capacity of the bag.

// Input values:
// for(int i=0;i<n;i++){
//     int x;
//     cin>>x;
//     val[i]=x;
// }


// Takes the value of every product and stores it in the value vector.

// Input weights:
// for(int i=0;i<n;i++){
//     int x;
//     cin>>x;
//     wt[i]=x;
// }


// Takes the weight of every product and stores it in the weight vector.

// Function calling:
// fract_knapsact(val,wt,W);


// Calls the Fractional Knapsack function and passes values, weights and capacity.
// return 0;


// Ends the program successfully.

// 3. Dry Run (Important for Practical)
// Input:
// Enter total number of product: 3
// Enter total Weight: 50
// Enter Value Array: 60 100 120
// Enter Weight Array: 10 20 30


// First calculate the ratio:
// Product	Value	Weight	Ratio
// 1	60	10	6
// 2	100	20	5
// 3	120	30	4

// After sorting:
// 1. Product 1 → Ratio 6
// 2. Product 2 → Ratio 5
// 3. Product 3 → Ratio 4
// Now selection:
// Step	Product	Weight taken	Value gained	Remaining capacity
// 1	Product 1	10	60	40
// 2	Product 2	20	100	20
// 3	Product 3 (fraction)	20	80	0

// Maximum value
// 240
// 60 + 100 + 80 = 240

// Important correction: Your code declares ans as int. For general fractional values, change it to double ans = 0; and change the function return type to double, otherwise decimal profit can be lost.
// 4. Important viva questions
// Question	Answer
// Which algorithm is used?	Greedy Algorithm
// What is the ratio formula?	Value / Weight
// Why use sorting?	To get the highest ratio first
// Why use pair?	To store ratio and original index
// Why use double?	To calculate decimal ratios
// Why use break?	To stop when capacity becomes zero
// What is make_pair()?	Creates a pair of two values
// What is ratio[i].second?	Original index of the product
// What is ratio[i].first?	Value/weight ratio
// Time complexity?	O(n log n)

// 5. How to explain the complete program to mam
// Remember this explanation:

// "This program implements the Fractional Knapsack problem using the Greedy Algorithm. First, we take the number of products, their values, weights and total capacity from the user. Then we calculate the value-to-weight ratio of each product. We store the ratio and original index using a pair. After that, we sort all products in descending order according to their ratios. Then we select products with the highest ratio. If the complete product fits, we take it; otherwise, we take only the required fraction. Finally, we display the maximum value."

// One important thing to remember: The main logic of this program is:

// Calculate Ratio → Sort → Select Items → Calculate Maximum Value.
