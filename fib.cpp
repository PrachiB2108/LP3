#include <iostream>
using namespace std;

int fib_iterative(int n, int &steps)
{
    steps = 0;

    if (n == 0)
    {
        steps++;
        return 0;
    }
    else if (n == 1)
    {
        steps++;
        return 1;
    }

    int a = 0, b = 1;

    for (int i = 2; i <= n; i++)
    {
        steps++;
        int temp = a + b;
        a = b;
        b = temp;
    } 

    return b;
}

int step=0;
int fib_recursive(int n)
{
    step++;

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

int main()
{
    int n, steps;

    cout << "Enter n: ";
    cin >> n;

    cout << "Iterative" << endl;
    int result = fib_iterative(n, steps);
    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Step count (iterative) = " << steps << endl;

    cout<< endl;
    cout << "Recursive" << endl;
    int results = fib_recursive(n);
    cout << "Fibonacci(" << n << ") = " << results << endl;
    cout << "Step count (Recursive) = " << step << endl;

    return 0;
}
// Theory: Fibonacci Series
// The Fibonacci series is a sequence of numbers in which each number is the sum of the previous two numbers. The series starts with 0 and 1.

// Formula:
// \[
// F(n)=F(n-1)+F(n-2)
// \]

// Where:
// - F(0) = 0
// - F(1) = 1
// In this program, Fibonacci numbers are calculated using two methods: Iterative and Recursive.
// 1. Iterative Method: Uses a loop to calculate Fibonacci numbers and counts the number of steps.
// 2. Recursive Method: Uses a function that calls itself to calculate Fibonacci numbers and counts the number of function calls.
// The program displays the Fibonacci number and step count for both methods.

// Time Complexity:
// - Iterative: \(O(n)\)
// - Recursive: \(O(2^n)\) approximately.
// Conclusion: Thus, the Fibonacci series is calculated using iterative and recursive methods, and their step counts are compared.