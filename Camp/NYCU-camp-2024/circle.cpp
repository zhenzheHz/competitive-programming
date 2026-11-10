#include <stdio.h>
int main(){
    double PI = 3.1415926;
    double radius, area;
    printf("Input the radius of the circle: ");
    scanf("%lf", &radius);
    /* Compute the area of the circle, which is PI*(radius^2)  */
    area = PI * radius * radius;
    /* Print the result */
    printf("\nThe area of the circle is %.2f.\n", area);
    return 0;
}

