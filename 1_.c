#include <stdio.h>

// 宣告新的資料結構 person_t
struct person_t
{
    const char *name;
    unsigned age;
};
// 簡化型別名稱
typedef struct person_t person_t; // struct person_t == person_t


// 簡化 namespace
// 1. 產生匿名結構
// 2. 定義匿名結構的型別名稱
typedef struct {
    const char *name;
    unsigned age;
} dog_t;


int main(void)
{
    // 初始化結構
    struct person_t p1 = {
        "Kai",
        31
    };

    printf("Name: %s\n", p1.name);
    printf("age: %d\n", p1.age);
    // p1 初始化的方式綁死參數對應位置 之後調整結構變數順序時需要一起修改

    // 使用參數對應
    struct person_t p2 = {
        .age = 10,
        .name = "Foo"
    };
    printf("Name: %s\n", p2.name);
    printf("age: %d\n", p2.age);

    // 使用 typedef 型別
    person_t p3 = {
        .age = 20,
        .name = "bar"
    };

    printf("Name: %s\n", p3.name);
    printf("age: %d\n", p3.age);

    dog_t d = {
        .age = 5,
        .name = "Hime"
    };
    printf("Name: %s\n", d.name);
    printf("age: %d\n", d.age);
    return 0;
}