#include <iostream>
using namespace std;

typedef struct {
    int p;
    int q;
} Rational;

// Create a  rational number from two integers and return it.
Rational create_rational(int x, int y) {
    Rational result;
    result.p = x;
    result.q = y;
    return result;
}

// Another convenience function to print out a rational value as a
// ratio of its p and q to standard output.
void print_rational(Rational r) {
    cout << r.p << ":" << r.q << endl;
}

// Multiply two rational numbers and return the resulting rational number.
Rational multiply(Rational r1, Rational r2) {
    Rational result;
    result.p = r1.p * r2.p;
    result.q = r1.q * r2.q;
    return result;
}



int main() {
    Rational r1, r2;
    // We use the create_rational() function defined above this time
    // unlike in rational1. 
    r1 = create_rational(3, 4);
    r2 = create_rational(9, 5);

    // Let's test assignment of rationals.
    cout << "r1 before assignment: ";
    print_rational(r1);
    cout << "r2 before assignment: ";
    print_rational(r2);
    r1 = r2;
    cout << "r1 after assignment: ";
    print_rational(r1);
    cout << "r2 after assignment: ";
    print_rational(r2);
}




