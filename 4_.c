/**
 * struct array
*/
#include <stdio.h>
struct point_t {
    double x;
    double y;
};
typedef struct point_t point_t;

int main(int argc, char const *argv[])
{
    point_t pts[] = {
        {
            .x = 1,
            .y = 11
        },
        {
            .x = 2,
            .y = 12
        },
        {
            .x = 3,
            .y = 13
        }
    };
    for (size_t i = 0; i < sizeof(pts)/sizeof(pts[0]); i++)
    {
        printf("(%.2f, %.2f)\n", pts[i].x, pts[i].y);
    }
    
    return 0;
}
