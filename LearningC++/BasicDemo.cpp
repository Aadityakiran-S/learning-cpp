#include "BasicDemo.h"
#include <iostream>

namespace PointerReference {
void Demo::run() {
	int i = 0;
	int& ri = i; // reference to i
	ri++; // increment i through the reference

	std::cout << "i: " << i << std::endl; // should output 1

	int j = 2;

	int* pi = &i; // pointer to i
	int k = *pi; // dereference pointer to get value of i

	std::cout << "k: " << k << std::endl; // should output 1

	*pi = 7; // change value of i through pointer
	std::cout << "i: " << i << std::endl; // should output 7

	(*pi)++; // increment i through pointer
	std::cout << "i: " << i << std::endl; // should output 8

	pi = &j;
	pi = nullptr; // set pointer to null
	if (pi == nullptr) {
		std::cout << "pi is null" << std::endl;
	}
}

class referenceMember {
	private:
		int& ref;

	public: 
		referenceMember(int& r) : ref(r) {}
		int reportValue() { return ref; }
};

class pointerMember {
	private:
		int* pi = nullptr;

	public:
		pointerMember(int* p) : pi(p) {}
		int reportValue() { 
			if (pi == nullptr) {
				throw std::runtime_error("Null pointer dereference in reportValue() of pointerMember");
			}
			return *pi; 
		}
		void setPointer(int* p) { pi = p; }
};
}