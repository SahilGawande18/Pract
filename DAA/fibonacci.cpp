#include <iostream>
using namespace std;

int fib(int n, int &steps) {
    steps++;
    if (n <= 1) {
        return n;
    }
    return fib(n - 1, steps) + fib(n - 2, steps);
}

int fib_iterative(int n, int &steps1) {
    steps1 = 0;
    if (n <= 1) {
        steps1++;
        return n;
    }
    
    int a = 0, b = 1, c = 0;
    
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
        steps1++;
    }
    return c;
}

int main() {
    int n, steps = 0, steps1 = 0;
    cout << "Enter a term: ";
    cin >> n;
    
    int result = fib(n, steps);
    int result_iterative = fib_iterative(n, steps1); // Corrected function call
    
    cout << "\nUsing recursive approach" << endl;
    cout << "Term: " << result << " steps: " << steps << endl;
    
    cout << "Using iterative approach" << endl;
    cout << "Term: " << result_iterative << " steps: " << steps1 << endl;
    
    return 0;
}
