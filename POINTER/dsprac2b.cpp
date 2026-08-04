#include <iostream>
using namespace std;

void value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter Call by Value:" << endl;
    cout << "a = " << a << " b = " << b << endl;
}

void reference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter Call by Reference:" << endl;
    cout << "a = " << a << " b = " << b << endl;
}

int main()
{
    int x = 10, y = 20;

    cout << "Before Function Call:" << endl;
    cout << "x = " << x << " y = " << y << endl;

    value(x, y);

    cout << "\nAfter Call by Value in Main:" << endl;
    cout << "x = " << x << " y = " << y << endl;

    reference(x, y);

    cout << "\nAfter Call by Reference in Main:" << endl;
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}