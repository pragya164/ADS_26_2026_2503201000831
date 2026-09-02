#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {   // Base case
        return 1;
    }
    
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n);
    return 0;
}