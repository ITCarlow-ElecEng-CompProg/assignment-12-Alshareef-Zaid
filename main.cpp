/** Zaid H Alshareef
*   31/1/2018
*   Lab 12
*   Complex Number Calculations */

/** Preprocessor directives */
#include <iostream>
#include <iomanip>
/** allows getchar() */
#include <cstdio>
/** allows system(cls) */
#include <windows.h>
#include <math.h>

using namespace std;

/** Structure definition - Cartesian number */
struct number
{
    double real, imag;
};

/** Structure definition - polar number */
struct polarnumber
{
    double mag, angle;
};

/** Main function */
int main (void)
{
    /** Display heading */
    cout << "Complex Number Calculations."  ;

    /** Declaring structure variables */
    struct number one, two;

    /** Read in values for real */
    cout << "\n\nReal 1 :\t" ;
    cin >> one.real ;
    cout << "Real 2 :\t" ;
    cin >> two.real;

    /** Read in values for imaginary */
    cout << "\nImaginary 1 :\t" ;
    cin >> one.imag ;
    cout << "Imaginary 2 :\t" ;
    cin >> two.imag ;

    /** Structure variable names */
    struct number sum, subtract, multiplication, division;

    /** Calling structure based sub functions */
    struct number add (struct number, struct number);
    struct number sub (struct number, struct number);
    struct number mul (struct number, struct number);
    struct number div (struct number, struct number);

    /** mathematical function invoking */
    sum = add (one, two);
    subtract = sub (one, two);
    multiplication = mul (one, two);
    division = div(one,two);

    /** If else statements to display mathematical functions of input numbers
        Required so the correct sign is displayed on the console */
    if (sum.imag >= 0)
    cout << "\n\nAddition = " << sum.real << " + j" << sum.imag;
    else
    cout << "\n\nAddition = " << sum.real << " - j" << fabs(sum.imag);

    if (subtract.imag >= 0)
    cout << "\n\nSubtraction = " << subtract.real << " + j" << subtract.imag;
    else
    cout << "\n\nSubtraction = " << subtract.real << " - j" << fabs(subtract.imag);

    if (multiplication.imag >= 0)
    cout << "\n\nMultiplication = " << multiplication.real << " + j" << multiplication.imag;
    else
    cout << "\n\nMultiplication = " << multiplication.real << " - j" << fabs(multiplication.imag);

    if (division.imag >= 0)
    cout << "\n\nDivision = " << division.real << " + j" << division.imag ;
    else
    cout << "\n\nDivision = " << division.real << " - j" << fabs(division.imag);

    /** Terminating main function */
    return 0;

}

/** Addition sub function */
struct number add (struct number n1, struct number n2)
{
    /** declaring res as a variable in the number structure */
    struct number res;

    /** adding two values together */
    res.real = n1.real + n2.real;
    res.imag = n1.imag + n2.imag;

    /** return result to main function */
    return res;
}

/** Addition sub function */
struct number sub (struct number n1, struct number n2)
{
    /** declaring res as a variable in the number structure */
    struct number res;

    /** subtracting two values together */
    res.real = n1.real - n2.real;
    res.imag = n1.imag - n2.imag;

    /** retuern result to main function */
    return res;
}

/** multiplication sub function */
struct number mul (struct number n1, struct number n2)
{
    /** Struct declarations */
    struct number res;
    struct polarnumber n1P, n2P, resP;

    /** convert from cart to polar */
    n1P.mag = sqrt(pow(n1.real, 2) + pow(n1.imag, 2));
    n1P.angle = atan2(n1.imag, n1.real);

    /** convert from cart to polar */
    n2P.mag = sqrt(pow(n2.real, 2) + pow(n2.imag, 2));
    n2P.angle = atan2(n2.imag, n2.real);

    /** multiply together */
    resP.mag = n1P.mag * n2P.mag;
    resP.angle = n1P.angle + n2P.angle;

    /** convert polar to Cartesian and return value */
    res.real = resP.mag * cos(resP.angle);
    res.imag = resP.mag * sin(resP.angle);

    /** return result to main function */
    return res;
}

/** division sub function */
struct number div (struct number n1, struct number n2)
{
    /**structure variables */
    struct number res;
    struct polarnumber n1P, n2P, resP;

    /** convert from cart to polar */
    n1P.mag = sqrt(pow(n1.real, 2) + pow(n1.imag, 2));
    n1P.angle = atan2(n1.imag, n1.real);

    /** convert from cart to polar */
    n2P.mag = sqrt(pow(n2.real, 2) + pow(n2.imag, 2));
    n2P.angle = atan2(n2.imag, n2.real);

    /** divide together */
    resP.mag = n1P.mag / n2P.mag;
    resP.angle = n1P.angle - n2P.angle;

    /** convert polar to Cartesian and return value */
    res.real = resP.mag * cos(resP.angle);
    res.imag = resP.mag * sin(resP.angle);


    return res;
}
