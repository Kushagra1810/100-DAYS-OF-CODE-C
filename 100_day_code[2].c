#include <stdio.h>
#include <stdlib.h>  // for llabs()
#include <math.h>

// ====================== Day 11 ======================
// Day 11 Q1: Display month name and number of days using switch-case
void day11_q1() {
    int m;
    scanf("%d", &m);
    switch (m) {
        case 1: printf("January, 31 days\n"); break;
        case 2: printf("February, 28 days\n"); break;
        case 3: printf("March, 31 days\n"); break;
        case 4: printf("April, 30 days\n"); break;
        case 5: printf("May, 31 days\n"); break;
        case 6: printf("June, 30 days\n"); break;
        case 7: printf("July, 31 days\n"); break;
        case 8: printf("August, 31 days\n"); break;
        case 9: printf("September, 30 days\n"); break;
        case 10: printf("October, 31 days\n"); break;
        case 11: printf("November, 30 days\n"); break;
        case 12: printf("December, 31 days\n"); break;
        default: printf("Invalid month number\n");
    }
}

// Day 11 Q2: Profit or loss percentage
void day11_q2() {
    double cp, sp;
    scanf("%lf %lf", &cp, &sp);
    if (cp <= 0) { printf("Invalid cost price\n"); return; }
    double diff = sp - cp;
    double perc = (diff / cp) * 100.0;
    if (diff > 0) printf("Profit %.0f%%\n", perc);
    else if (diff < 0) printf("Loss %.0f%%\n", -perc);
    else printf("No Profit No Loss\n");
}

// ====================== Day 12 ======================
// Day 12 Q1: Library fine
void day12_q1() {
    int days;
    scanf("%d", &days);
    if (days > 30) { printf("Membership Cancelled\n"); return; }
    if (days <= 0) { printf("No fine\n"); return; }
    int fine = 0, d = days;
    if (d > 5) { fine += 5 * 2; d -= 5; } else { fine += d * 2; d = 0; }
    if (d > 0) { if (d > 5) { fine += 5 * 4; d -= 5; } else { fine += d * 4; d = 0; } }
    if (d > 0) { if (d > 20) { fine += 20 * 6; d -= 20; } else { fine += d * 6; d = 0; } }
    printf("Fine ₹%d\n", fine);
}

// Day 12 Q2: Electricity bill
void day12_q2() {
    int units;
    scanf("%d", &units);
    double bill = 0.0;
    int u = units;
    if (u > 100) { bill += 100 * 5; u -= 100; }
    else { bill += u * 5; u = 0; }
    if (u > 0) { if (u > 100) { bill += 100 * 7; u -= 100; } else { bill += u * 7; u = 0; } }
    if (u > 0) { if (u > 100) { bill += 100 * 10; u -= 100; } else { bill += u * 10; u = 0; } }
    if (u > 0) bill += u * 12;
    printf("Bill: ₹%.0f\n", bill);
}

// ====================== Day 13 ======================
// Day 13 Q1: Calculator (+ - * / %)
void day13_q1() {
    long long a, b; char op;
    scanf("%lld %lld %c", &a, &b, &op);
    switch (op) {
        case '+': printf("%lld\n", a + b); break;
        case '-': printf("%lld\n", a - b); break;
        case '*': printf("%lld\n", a * b); break;
        case '/': if (b != 0) printf("%lld\n", a / b); else printf("Division by zero\n"); break;
        case '%': if (b != 0) printf("%lld\n", a % b); else printf("Modulo by zero\n"); break;
        default: printf("Invalid operator\n");
    }
}

// Day 13 Q2: Print numbers 1..n
void day13_q2() {
    int n; scanf("%d",&n);
    for (int i=1; i<=n; i++){ if(i>1)printf(" "); printf("%d",i);}
    printf("\n");
}

// ====================== Day 14 ======================
void day14_q1() { int n; scanf("%d",&n); printf("%d\n", n*n); }
void day14_q2() { int n; scanf("%d",&n); long long prod=1; int f=0; for(int i=2;i<=n;i+=2){prod*=i;f=1;} if(!f) printf("1\n"); else printf("%lld\n",prod); }

// ====================== Day 15 ======================
void day15_q1() { int n; scanf("%d",&n); if(n<0){ printf("Invalid\n"); return;} unsigned long long f=1; for(int i=2;i<=n;i++) f*=i; printf("%llu\n",f);}
void day15_q2() { long long n; scanf("%lld",&n); long long sign=(n<0)?-1:1; n=llabs(n); long long rev=0; while(n>0){rev=rev*10+(n%10);n/=10;} printf("%lld\n",rev*sign); }

// ====================== Day 16 ======================
void day16_q1() { unsigned int n; scanf("%u",&n); if(n==0){printf("0\n");return;} char buf[64];int idx=0; while(n>0){buf[idx++]='0'+(n&1);n>>=1;} for(int i=idx-1;i>=0;i--) putchar(buf[i]); putchar('\n'); }
void day16_q2() { long long n; scanf("%lld",&n); long long orig=n, nn=llabs(n), rev=0; while(nn>0){rev=rev*10+(nn%10); nn/=10;} if(rev==llabs(orig)) printf("Palindrome\n"); else printf("Not palindrome\n"); }

// ====================== Day 17 ======================
void day17_q1() { long long n; scanf("%lld",&n); if(n<0){printf("Not Armstrong\n");return;} long long t=n; int d=0; while(t>0){d++;t/=10;} if(d==0) d=1; t=n; long long sum=0; while(t>0){int x=t%10; long long p=1; for(int i=0;i<d;i++) p*=x; sum+=p; t/=10;} if(sum==n) printf("Armstrong\n"); else printf("Not Armstrong\n"); }
void day17_q2() { long long n; scanf("%lld",&n); if(n<=1){printf("Not prime\n");return;} if(n<=3){printf("Prime\n");return;} if(n%2==0){printf("Not prime\n");return;} for(long long i=3;i*i<=n;i+=2){if(n%i==0){printf("Not prime\n");return;}} printf("Prime\n"); }

// ====================== Day 18 ======================
void day18_q1(){ long long n; scanf("%lld",&n); long long nn=llabs(n); for(long long i=1;i<=nn;i++){ if(nn%i==0) printf("%lld ",i);} printf("\n"); }
long long gcd_ll(long long a,long long b){ if(a<0)a=-a; if(b<0)b=-b; while(b){ long long t=a%b; a=b; b=t;} return a; }
void day18_q2(){ long long a,b; scanf("%lld%lld",&a,&b); printf("%lld\n",gcd_ll(a,b)); }

// ====================== Day 19 ======================
void day19_q1(){ long long a,b; scanf("%lld%lld",&a,&b); if(a==0||b==0){printf("0\n");return;} long long g=gcd_ll(a,b); long long l=llabs((a/g)*b); printf("%lld\n",l); }
void day19_q2(){ long long n; scanf("%lld",&n); long long nn=llabs(n),s=0; while(nn){s+=nn%10; nn/=10;} printf("%lld\n",s); }

// ====================== Day 20 ======================
void day20_q1(){ long long n; scanf("%lld",&n); long long nn=llabs(n); if(nn==0){printf("0\n");return;} long long p=1; int f=0; while(nn){int d=nn%10; if(d%2==1){p*=d; f=1;} nn/=10;} if(!f) printf("1\n"); else printf("%lld\n",p); }
void day20_q2(){ char s[1024]; scanf("%s",s); for(int i=0;s[i];i++){ if(s[i]=='0') putchar('1'); else if(s[i]=='1') putchar('0'); else {printf("Invalid\n"); return;} } putchar('\n'); }

// ====================== MAIN ======================
int main() {
    int c; if(scanf("%d",&c)!=1) return 0;
    switch(c){
        case 1: day11_q1(); break; case 2: day11_q2(); break;
        case 3: day12_q1(); break; case 4: day12_q2(); break;
        case 5: day13_q1(); break; case 6: day13_q2(); break;
        case 7: day14_q1(); break; case 8: day14_q2(); break;
        case 9: day15_q1(); break; case 10: day15_q2(); break;
        case 11: day16_q1(); break; case 12: day16_q2(); break;
        case 13: day17_q1(); break; case 14: day17_q2(); break;
        case 15: day18_q1(); break; case 16: day18_q2(); break;
        case 17: day19_q1(); break; case 18: day19_q2(); break;
        case 19: day20_q1(); break; case 20: day20_q2(); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}



/*
=================== TEST CASES & EXPECTED OUTPUTS (Day 11–20) ===================

-- Day 11 Q1 (Month name & days) --
Input 1:
2
Output 1:
February, 28 days
Input 2:
12
Output 2:
December, 31 days

-- Day 11 Q2 (Profit/Loss %) --
Input 1:
1000 1200
Output 1:
Profit 20%
Input 2:
1000 800
Output 2:
Loss 20%
Input 3:
1000 1000
Output 3:
No Profit No Loss

-- Day 12 Q1 (Library Fine) --
Input 1:
4
Output 1:
Fine ₹8
Input 2:
8
Output 2:
Fine ₹22
Input 3:
15
Output 3:
Fine ₹60
Input 4:
31
Output 4:
Membership Cancelled

-- Day 12 Q2 (Electricity Bill) --
Input 1:
50
Output 1:
Bill: ₹250
Input 2:
150
Output 2:
Bill: ₹850
Input 3:
250
Output 3:
Bill: ₹1700

-- Day 13 Q1 (Calculator) --
Input 1:
4 2 +
Output 1:
6
Input 2:
10 3 %
Output 2:
1
Input 3:
15 5 /
Output 3:
3

-- Day 13 Q2 (Print numbers 1..n) --
Input 1:
5
Output 1:
1 2 3 4 5
Input 2:
3
Output 2:
1 2 3

-- Day 14 Q1 (Sum of first n odd numbers) --
Input 1:
3
Output 1:
9
Input 2:
5
Output 2:
25

-- Day 14 Q2 (Product of even numbers 1..n) --
Input 1:
4
Output 1:
8 (2 * 4)
Input 2:
6
Output 2:
48 (2 * 4 * 6)

-- Day 15 Q1 (Factorial) --
Input 1:
5
Output 1:
120
Input 2:
3
Output 2:
6

-- Day 15 Q2 (Reverse number) --
Input 1:
1234
Output 1:
4321
Input 2:
100
Output 2:
1

-- Day 16 Q1 (Binary representation) --
Input 1:
10
Output 1:
1010
Input 2:
7
Output 2:
111

-- Day 16 Q2 (Palindrome check) --
Input 1:
121
Output 1:
Palindrome
Input 2:
123
Output 2:
Not palindrome

-- Day 17 Q1 (Armstrong number) --
Input 1:
153
Output 1:
Armstrong
Input 2:
123
Output 2:
Not Armstrong

-- Day 17 Q2 (Prime check) --
Input 1:
7
Output 1:
Prime
Input 2:
10
Output 2:
Not prime

-- Day 18 Q1 (Factors of a number) --
Input 1:
6
Output 1:
1 2 3 6
Input 2:
10
Output 2:
1 2 5 10

-- Day 18 Q2 (GCD) --
Input 1:
12 18
Output 1:
6
Input 2:
7 9
Output 2:
1

-- Day 19 Q1 (LCM) --
Input 1:
4 5
Output 1:
20
Input 2:
7 3
Output 2:
21

-- Day 19 Q2 (Sum of digits) --
Input 1:
123
Output 1:
6
Input 2:
999
Output 2:
27

-- Day 20 Q1 (Product of odd digits) --
Input 1:
12345
Output 1:
15 (1*3*5)
Input 2:
2468
Output 2:
1 (no odd digits, assume 1)

-- Day 20 Q2 (1’s complement of binary string) --
Input 1:
1010
Output 1:
0101
Input 2:
1111
Output 2:
0000

=============================================================================


