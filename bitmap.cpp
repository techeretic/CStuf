#include <iostream>

using namespace std;

class stack_node {
public:
	int value;
	stack_node *next;

	stack_node(int val) {
		value = val;
		next = NULL;
	}
};

class stack {
public:
	int size;
	stack_node *top;
	stack() {
		top = NULL;
		size = 0;
	}
	void push(int val) {
		if (top == NULL) {
			top = new stack_node(val);
		} else {
			stack_node *tmp = new stack_node(val);
			tmp->next = top;
			top = tmp;
		}
		size++;
	}
	void pop() {
		stack_node *tmp = top;
		top = top->next;
		delete tmp;
		size--;
	}
	char* toString() {
		char* str = new char[size];
		int i = 0;
		stack_node *tmp = top;
		while(tmp) {
			str[i++] = tmp->value == 1 ? '1' : '0';
			tmp = tmp->next;
		}
		return str;
	}
	int toInt() {
		int sz = size;
		int op = 0;
		stack_node *tmp = top;
		while(tmp) {
			sz--;
			if (tmp->value == 1)
				op += 1<<sz;
			//cout << "\n bit is " << tmp->value << " && power is " << sz << " and o/p is " << op;
			tmp = tmp->next;
		}
		return op;
	}
};

char* getBinary(int val) {
	stack s;
	while(val > 0) {
		s.push(val%2);
		val = val/2;
	}
	return s.toString();
}

int getNumber(int val) {
	stack s;
	while(val > 0) {
		s.push(val%2);
		val = val/2;
	}
	return s.toInt();
}

int main() {
	int choice, ch2;
	do {
		cout << "\n\n\t Input Number 1 : ";
		cin >> choice;
		
		if (choice > 0) {
			cout << "\n\n\t Input Number 1 : ";
			cin >> ch2;

			cout << "\n\n\tBinary representation of " << choice
				 << " is " << getBinary(choice) << " & Decimal = " << getNumber(choice) << "\n";
			cout << "\n\n\tBinary representation of " << ch2
							 << " is " << getBinary(ch2) << " & Decimal = " << getNumber(ch2) << "\n";
			
			cout << "\n\n\t "<< choice << " & " << ch2 << " = " << getBinary(choice & ch2) << " & Decimal = " << getNumber(choice & ch2) << "\n";
			
			cout << "\n\n\t "<< choice << " | " << ch2 << " = " << getBinary(choice | ch2) << " & Decimal = " << getNumber(choice | ch2) << "\n";
			

			stack s;
			int temp = ch2;
			while(temp > 0) {
				s.push(temp%2);
				temp = temp/2;
			}
			temp = (choice << s.size | ch2);
			cout << "\n\n\t Combining "<< choice << " & " << ch2 << " = " << temp << " Binary = " << getBinary(temp)
				 << " && Decimal = " << getNumber(temp);  
		}

	} while (choice > 0);
	cout<<"\n\n\tExiting\n\n";
	return 0;
}