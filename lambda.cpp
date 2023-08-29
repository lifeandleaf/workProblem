/*
lambda表达式：
[capture list] (parameter list) -> return type
{
   function body;
};

capture list：捕获列表，指 lambda 所在函数中定义的局部变量的列表，通常为空。
    [=] 以值传递的方式捕获局部变量
    [&] 以引用的方式捕获局部变量
    [=, &a] 以值传递的方式捕获除a外的所有局部变量，a以引用的方式捕获
    [&, a] 以引用的方式捕获除a外的所有局部变量，a以值传递的方式捕获
    [a, b, &c, &d] 以值传递的方式捕获a,b以引用的方式捕获c,d
return type、parameter list、function body：分别表示返回值类型、参数列表、函数体，和普通函数一样。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {4, 2, 3, 1};

    sort(arr, arr + 4, [=](int x, int y) -> bool {
        return x < y;
    });
    for(int i : arr) cout << i << " ";
    return 0;
}