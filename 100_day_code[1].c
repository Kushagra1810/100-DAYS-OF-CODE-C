#include <stdio.h>
#include <math.h>

// ====================== Day 1 ======================
// Day 1 Q1: Input two numbers and display their sum
void day1_q1() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Sum = %d\n", a + b);
}

// Day 1 Q2: Input two numbers and display sum, difference, product, and quotient
void day1_q2() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b != 0)
        printf("Sum=%d, Diff=%d, Product=%d, Quotient=%d\n", a + b, a - b, a * b, a / b);
    else
        printf("Sum=%d, Diff=%d, Product=%d, Quotient=undefined\n", a + b, a - b, a * b);
}

// ====================== Day 2 ======================
// Day 2 Q1: Area and perimeter of rectangle
void day2_q1() {
    int l, b;
    scanf("%d %d", &l, &b);
    printf("Area=%d, Perimeter=%d\n", l * b, 2 * (l + b));
}

// Day 2 Q2: Area and circumference of circle (π = 3.14159)
void day2_q2() {
    double r;
    scanf("%lf", &r);
    double area = 3.14159 * r * r;
    double circ = 2 * 3.14159 * r;
    printf("Area=%.2f, Circumference=%.2f\n", area, circ);
}

// ====================== Day 3 ======================
// Day 3 Q1: Celsius to Fahrenheit
void day3_q1() {
    double c;
    scanf("%lf", &c);
    double f = (c * 9.0 / 5.0) + 32.0;
    // Print without decimal if whole, else print without trailing zeros is complex in C;
    // We match typical formatting: if f is whole, print as integer-like.
    if (fabs(f - round(f)) < 1e-9) printf("Fahrenheit=%.0f\n", f);
    else printf("Fahrenheit=%.2f\n", f);
}

// Day 3 Q2: Swap two numbers using a third variable
void day3_q2() {
    int a, b, temp;
    scanf("%d %d", &a, &b);
    temp = a; a = b; b = temp;
    printf("After swap: %d %d\n", a, b);
}

// ====================== Day 4 ======================
// Day 4 Q1: Swap two numbers without third variable
void day4_q1() {
    int a, b;
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap: %d %d\n", a, b);
}

// Day 4 Q2: Sum of first n natural numbers
void day4_q2() {
    int n;
    scanf("%d", &n);
    int sum = n * (n + 1) / 2; // formula
    printf("Sum=%d\n", sum);
}

// ====================== Day 5 ======================
// Day 5 Q1: Simple and compound interest
// SI = (p*r*t)/100
// CI = p * (1 + r/100)^t - p
void day5_q1() {
    double p, r, t;
    scanf("%lf %lf %lf", &p, &r, &t);
    double si = (p * r * t) / 100.0;
    double ci = p * pow((1.0 + r / 100.0), t) - p;
    // Print SI without decimals if whole; CI printed with two decimals (common)
    if (fabs(si - round(si)) < 1e-9) printf("Simple Interest=%.0f, ", si);
    else printf("Simple Interest=%.2f, ", si);
    // For CI print up to 2 decimals; user testcases sometimes show 1 decimal; we use 2 decimals for clarity
    printf("Compound Interest=%.2f\n", ci);
}

// Day 5 Q2: Convert seconds to h:m:s
void day5_q2() {
    int sec;
    scanf("%d", &sec);
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = sec % 60;
    printf("%d:%d:%d\n", h, m, s);
}

// ====================== Day 6 ======================
// Day 6 Q1: Even or odd
void day6_q1() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) printf("%d is even\n", n);
    else printf("%d is odd\n", n);
}

// Day 6 Q2: Positive, negative or zero
void day6_q2() {
    int n;
    scanf("%d", &n);
    if (n > 0) printf("Positive\n");
    else if (n < 0) printf("Negative\n");
    else printf("Zero\n");
}

// ====================== Day 7 ======================
// Day 7 Q1: Leap year
void day7_q1() {
    int y;
    scanf("%d", &y);
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");
}

// Day 7 Q2: Vowel or consonant
void day7_q2() {
    char ch;
    scanf(" %c", &ch);
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
        ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        printf("Vowel\n");
    else
        printf("Consonant\n");
}

// ====================== Day 8 ======================
// Day 8 Q1: Check uppercase, lowercase, digit or special
void day8_q1() {
    char ch;
    scanf(" %c", &ch);
    if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase alphabet\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Lowercase alphabet\n");
    else if (ch >= '0' && ch <= '9')
        printf("Digit\n");
    else
        printf("Special character\n");
}

// Day 8 Q2: Largest among three numbers
void day8_q2() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    printf("Largest is %d\n", largest);
}

// ====================== Day 9 ======================
// Day 9 Q1: Roots of quadratic equation
void day9_q1() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double d = b*b - 4*a*c;
    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2*a);
        double r2 = (-b - sqrt(d)) / (2*a);
        printf("Real and distinct roots: %.2f , %.2f\n", r1, r2);
    } else if (d == 0) {
        double r = -b / (2*a);
        printf("Real and equal roots: %.2f\n", r);
    } else {
        printf("Imaginary roots\n");
    }
}

// Day 9 Q2: Assign grade based on percentage
void day9_q2() {
    int p;
    scanf("%d", &p);
    if (p >= 90 && p <= 100) printf("Grade A\n");
    else if (p >= 80) printf("Grade B\n");
    else if (p >= 70) printf("Grade C\n");
    else if (p >= 60) printf("Grade D\n");
    else printf("Grade F\n");
}

// ====================== Day 10 ======================
// Day 10 Q1: Triangle classification
void day10_q1() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("Equilateral\n");
    else if (a == b || b == c || a == c)
        printf("Isosceles\n");
    else
        printf("Scalene\n");
}

// Day 10 Q2: Day of week using switch-case
void day10_q2() {
    int d;
    scanf("%d", &d);
    switch(d) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        case 7: printf("Sunday\n"); break;
        default: printf("Invalid day\n");
    }
}

// ====================== MAIN MENU ======================
int main() {
    // Usage:
    // Provide appropriate inputs as per the chosen program.
    // For automatic testing, run the program and supply inputs in the required order.
    int choice;
    if (scanf("%d", &choice) != 1) return 0;
    // If you want interactive menu, replace the above with a loop printing options and using scanf.
    switch (choice) {
        case 1: day1_q1(); break;
        case 2: day1_q2(); break;
        case 3: day2_q1(); break;
        case 4: day2_q2(); break;
        case 5: day3_q1(); break;
        case 6: day3_q2(); break;
        case 7: day4_q1(); break;
        case 8: day4_q2(); break;
        case 9: day5_q1(); break;
        case 10: day5_q2(); break;
        case 11: day6_q1(); break;
        case 12: day6_q2(); break;
        case 13: day7_q1(); break;
        case 14: day7_q2(); break;
        case 15: day8_q1(); break;
        case 16: day8_q2(); break;
        case 17: day9_q1(); break;
        case 18: day9_q2(); break;
        case 19: day10_q1(); break;
        case 20: day10_q2(); break;
        default: /* invalid choice */ break;
    }
    return 0;
}

/*
=================== PROVIDED TEST CASES & EXPECTED OUTPUTS ===================

-- Day 1 Q1 --
Input 1:
3 4
Output 1:
Sum = 7
Input 2:
-1 20
Output 2:
Sum = 19

-- Day 1 Q2 --
Input 1:
10 2
Output 1:
Sum=12, Diff=8, Product=20, Quotient=5
Input 2:
7 3
Output 2:
Sum=10, Diff=4, Product=21, Quotient=2

-- Day 2 Q1 --
Input 1:
5 10
Output 1:
Area=50, Perimeter=30
Input 2:
3 7
Output 2:
Area=21, Perimeter=20

-- Day 2 Q2 --
Input 1:
7
Output 1:
Area=153.94, Circumference=43.96
Input 2:
3
Output 2:
Area=28.27, Circumference=18.85

-- Day 3 Q1 --
Input 1:
0
Output 1:
Fahrenheit=32
Input 2:
100
Output 2:
Fahrenheit=212

-- Day 3 Q2 --
Input 1:
3 5
Output 1:
After swap: 5 3
Input 2:
-1 1
Output 2:
After swap: 1 -1

-- Day 4 Q1 --
Input 1:
10 20
Output 1:
After swap: 20 10
Input 2:
7 14
Output 2:
After swap: 14 7

-- Day 4 Q2 --
Input 1:
5
Output 1:
Sum=15
Input 2:
10
Output 2:
Sum=55

-- Day 5 Q1 --
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5
Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76

-- Day 5 Q2 --
Input 1:
3661
Output 1:
1:1:1
Input 2:
7322
Output 2:
2:2:2

-- Day 6 Q1 --
Input 1:
7
Output 1:
7 is odd
Input 2:
12
Output 2:
12 is even

-- Day 6 Q2 --
Input 1:
-5
Output 1:
Negative
Input 2:
0
Output 2:
Zero
Input 3:
10
Output 3:
Positive

-- Day 7 Q1 --
Input 1:
2020
Output 1:
Leap year
Input 2:
1900
Output 2:
Not a leap year
Input 3:
2000
Output 3:
Leap year

-- Day 7 Q2 --
Input 1:
a
Output 1:
Vowel
Input 2:
b
Output 2:
Consonant

-- Day 8 Q1 --
Input 1:
A
Output 1:
Uppercase alphabet
Input 2:
a
Output 2:
Lowercase alphabet
Input 3:
3
Output 3:
Digit
Input 4:
#
Output 4:
Special character

-- Day 8 Q2 --
Input 1:
3 7 5
Output 1:
Largest is 7
Input 2:
-1 -5 0
Output 2:
Largest is 0

-- Day 9 Q1 --
Input 1:
1 -3 2
Output 1:
Roots are real and different: 2, 1
Input 2:
1 -2 1
Output 2:
Roots are real and same: 1
Input 3:
1 2 5
Output 3:
Roots are complex

-- Day 9 Q2 --
Input 1:
95
Output 1:
Grade A
Input 2:
82
Output 2:
Grade B
Input 3:
68
Output 3:
Grade D
Input 4:
50
Output 4:
Grade F

-- Day 10 Q1 --
Input 1:
3 3 3
Output 1:
Equilateral
Input 2:
3 3 4
Output 2:
Isosceles
Input 3:
2 3 4
Output 3:
Scalene

-- Day 10 Q2 --
Input 1:
1
Output 1:
Monday
Input 2:
5
Output 2:
Friday