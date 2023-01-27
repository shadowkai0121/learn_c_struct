/**
 * pointer to struct
*/
#include <stdlib.h>
#include <stdio.h>
struct point_t {
    double x;
    double y;
};
typedef struct point_t point_t;

int main(int argc, char const *argv[])
{
    // 手動分配 heap
    size_t s = sizeof(point_t);
    printf("point_t size:%d\n", s);
    point_t *pt = malloc(s);
    if (!pt) {
        return 1;
    }
    // dereference
    (*pt).x = 1.0;
    (*pt).y = 1.1;
    // -> 可視為 dereference 語法糖
    printf("point1(%.2f, %.2f)\n", pt->x, pt->y);
    free(pt);

    // 自動分配
    point_t *pointPtr, point2;
    pointPtr = &point2;
    pointPtr->x = 2.0;
    pointPtr->y = 2.2;
    printf("point2(%.2f, %.2f)\n", pointPtr->x, pointPtr->y);
    return 0;
}
