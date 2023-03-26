#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter your number: ";
	cin >> number;
	int result = 1;

	__asm
	{
		push number
		call fact
		mul[esp]
		add esp, 4
		mov result, eax
		jmp exit1
		fact :
			cmp[esp + 4], 1
			jbe returnOne
			mov eax, 1
			mov esi, [esp + 4]
			dec esi
			push esi
			call fact
			mul[esp]
			add esp, 4
			ret
		returnOne :
			mov eax, 1
			ret
		exit1 :
	}

	cout << "Factorial = " << result;
}
