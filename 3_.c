/**
 * 內嵌結構
*/
#include <assert.h>
#include <string.h>
struct person_t
{
    const char * name;
    const unsigned int age;
};
typedef struct person_t person_t;

struct employee_t
{
    person_t p; // struct 內儲存另一個 struct
    //employee_t em; // struct 不能遞迴宣告 error: unknown type name ‘employee_t’
    // 可以使用 employee_t 指標進行遞迴操作
    double salary;
};
typedef struct employee_t employee_t;

int main(int argc, char const *argv[])
{
    employee_t ee = {
        .p = {
            .name = "Kai",
            .age = 31
        },
        .salary = 49999.99
    };

    assert(strcmp(ee.p.name, "Kai") == 0);
    assert(ee.p.age == 31);
    assert(ee.salary == 49999.99);

    return 0;
}
