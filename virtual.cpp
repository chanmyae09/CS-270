#include <iostream>
class A {
public:
A() { std::cout << "Init A" << std::endl; }
A (const A& other) { std::cout << "Copy A" << std::endl; }
void method1() { std::cout << "A1" << std::endl; }
virtual void method2() { std::cout << "A2" << std::endl; }
virtual void method3() { std::cout << "A3" << std::endl; }
virtual ~A() { std::cout << "~A" << std::endl; }
};
class B : public A {
public:
B() { std::cout <<"Init B" << std::endl; }
void method1() { std::cout << "B1" << std::endl; }
virtual void method2() { std::cout << "B2" << std::endl; }
virtual ~B() { std::cout << "~B" << std::endl; }
};
void f1(A& param) {
param.method1();
param.method2();
param.method3();
}
void f2(A param) {
param.method2();
}
int main() {
A var1;
B var2;
var1.method2();
var2.method1();
f1(var1);
f1(var2);
f2(var1);
f2(var2);
return 0;
}
