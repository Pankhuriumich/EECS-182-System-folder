#include <iostream>
#include <sstream>
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


// A convenience function to compute a string
// form of a rational value for printing. To convert from
// ints to strings, in C++, the easiest way is to write first
// to a stringstream type and then convert to a string. 

string tostring_rational(const Rational &r) {
    stringstream result;
    result << "Rational(" << r.p << "," << r.q << ")";
    return result.str();
}


// Multiply two rational numbers and return the resulting rational number.
// This version uses reference parameters, which is preferred for
// passing around structures. Use const for semantics similar to 
// pass-by-value.
Rational multiply(const Rational &r1, const Rational &r2) {
    Rational result;
    result.p = r1.p * r2.p;
    result.q = r1.q * r2.q;
    return result;
}

// Computes product of two rationals a:b and c:d as (ad+bc):bd.
Rational add(const Rational &r1, const Rational &r2) {
    Rational result;
    result.p = r1.p*r2.q + r2.p*r1.q;
    result.q = r1.q*r2.q;
    return result;
}

// Adds rational r2 to r1. The function does not return anything via
// return value. It modifies r1. Note that r1 is a reference parameter and
// is not constant, since we want to change r1.
void addto(Rational &r1, const Rational &r2) {
    r1 = add(r1, r2);
    return;
}



int main() {
    Rational r1, r2;
    // We use the create_rational() function defined above this time
    // unlike in rational1. 
    r1 = create_rational(3, 4);
    r2 = create_rational(9, 5);


    // Try out multiply function.
    r1 = create_rational(1, 2);
    r2 = create_rational(2, 3);
    Rational r3 = multiply(r1, r2);
    cout << "product of " << tostring_rational(r1) 
         << " and " 
         << tostring_rational(r2) << " is "
         << tostring_rational(r3) << endl;


   // Try out add function.
    r1 = create_rational(1, 2);
    r2 = create_rational(2, 3);
    r3 = add(r1, r2);
    cout << "sum of " << tostring_rational(r1) 
         << " and " 
         << tostring_rational(r2) << " is "
         << tostring_rational(r3) << endl;


   // Try out addto function.
    r1 = create_rational(1, 2);
    r2 = create_rational(2, 3);
    cout << "Old r1 = " << tostring_rational(r1) << endl;
    cout << "r2 = " << tostring_rational(r2) << endl;
    addto(r1, r2);
    cout << "r1 and r2, respectively, after addto(r1,r2): " 
         << tostring_rational(r1) << " and " 
         << tostring_rational(r2) << endl;
 }





