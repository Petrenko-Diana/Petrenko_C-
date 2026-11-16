#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    double radius;     
    Point2D center;    
} Circle;

void inputCircle(Circle *c) {
    printf("Enter Circle Details\n");
    printf("Enter radius: ");
    scanf("%lf", &c->radius);
    
    printf("Enter center coordinates (x y): ");
    scanf("%lf %lf", &c->center.x, &c->center.y);
}

void printCircle(const Circle *c) {
    printf("\n Circle Information:\n");
    printf("Radius : %.2f\n", c->radius);
    printf("Center : (%.2f, %.2f)\n", c->center.x, c->center.y);
}

int main(void) {
    Circle myCircle;

    inputCircle(&myCircle);
    printCircle(&myCircle);

    return 0;
}