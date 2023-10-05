#include<iostream>
using namespace std;
int main()
{
int a = 7, b = 3;
cout << "Before swaping a = " << a << " , b = " << b << endl;
a = a ^ b;
b = b ^ a;
a = a ^ b;
cout << "After swaping a = " << a << " , b = " << b << endl;
return 0;
}