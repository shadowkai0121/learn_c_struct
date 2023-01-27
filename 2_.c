/**
 * assign value
*/
#include <assert.h>
typedef struct point_t point_t;
struct point_t
{
    double x;
    double y;
};

int main(int argc, char const *argv[])
{
    point_t pt = {
        .x = 2,
        .y = 3
    };
    assert(pt.x == 2);
    assert(pt.y == 3);
    pt.x = 2.1;
    assert(pt.x == 2); // false
    return 0;
}
