#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
int i = INT_MAX;
float f = FLT_MAX;
double d = DBL_MAX;
printf ("Size of integer = %d, max value of integer = %d\n", sizeof(i),i);
printf ("Size of float = %d, max value of float = %f\n", sizeof(f),f);
printf ("Size of double = %d, max value of double = %lf\n", sizeof(d),d);
return 0;
}
