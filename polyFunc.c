#include<stdio.h>
#include<math.h>

double doStuff(double x){
    x = (3*pow(x,5)) + (2*pow(x,4)) - (5*pow(x,3)) - (pow(x,2)) + (7*x) - 6;
    return x;
}

int main(){

    double x;

    printf("Please enter a value for x: ");
    scanf("%lf", &x);
    int ans = doStuff(x);

    printf("The solution is %d\n", ans);
}