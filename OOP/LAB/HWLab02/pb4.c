/**
 * 4.
 *
 * a. Compute the approximated value of square root of a
 * positive real number. Use a given precision.
 *
 * b. Given a vector of numbers, find the longest contiguous
 * subsequence such that the difference
 * of any two consecutive elements is a prime number.
 */
#include <stdio.h>

//float computeRoot(float number, float eps) {
//    float found = 0.0;
//    float prec = 0.00001;
//
//    while (!(found * found - number >= eps &&
//             number - found*found <= eps)) {
//        //printf("%f", found);
//        found += prec;
//    }
//
//    return found - prec;
//}

double computeRoot(double number, float eps){
    double res = number;

    while( (res - number / res ) > eps ){
        res = (res + number / res) / 2;
    }

    return res;
}

void main() {
    printf("Enter a number and a precision to find it's root");

    printf("\nNumber: ");
    float n = 0;
    scanf("%f", &n);

    printf("\nPrecision: ");
    float eps = 0;
    scanf("%f", &eps);

    if (n < 0)
        printf("Invalid number");
    else {
        double res = computeRoot(n, eps);
        printf("The root is: %f\n", res);
        printf("The number is %f\nwith prec = %f", res*res, eps);
    }
}