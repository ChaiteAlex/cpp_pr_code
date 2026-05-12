// classic_op.cpp : Этот файл содержит классы и структуры

#include <iostream>
using namespace std;

/*
Упражнение 1. Описать конструктор для некоторого класса А таким
образом, чтобы были выполнены следующие условия:
а) это единственный явно описанный конструктор класса А,
б) справедливы следующие описания объектов класса А:
A a;
A b(1);
A c(1, 2);
A d('1’, 1);

class A {
	int val1, val2;

public:
	A(int x, int y);
	void dout() { cout << val1 << " " << val2 << endl; }

};

A::A(int x = 0, int y = 0)
{
	val1 = x, val2 = y;
}

int main() 
{
	A a;
	A b(1);
	A c(1, 2);
	A d('1', 1);

	a.dout();
	b.dout();
	c.dout();
	d.dout();
}*/

/*
Упражнение 2. Описать класс B таким образом, чтобы все конструкции
функции main были верными, а на экран выдалось 10 20 30.
int main() {
B b1, b2 = b1, b3(b2);
cout << b1.get() << b2.get() << b3.get() << endl;
return 0;
}
*/

class B {
	int val;

public:
	
	B() {
		val = 10;
	}

	B(B& obj) {
		val = obj.val + 10;
	}

	int get() { return val; }
};



int main() {
	B b1, b2 = b1, b3(b2);
	cout << b1.get() << b2.get() << b3.get() << endl;
	return 0;
}
