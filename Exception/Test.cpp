#include "Exception.h"

void PrintResult(MOONG::Exception& exception);

int main()
{
	MOONG::ExceptionFunctionCallFailed<DWORD> exception_1("함수 이름", 123);
	PrintResult(exception_1);

	MOONG::ExceptionFunctionCallFailed<DWORD> exception_2("함수 이름", 321, false);
	PrintResult(exception_2);

	MOONG::ExceptionFunctionCallFailed<int> exception_3("함수 이름", 123);
	PrintResult(exception_3);

	MOONG::ExceptionFunctionCallFailed<char> exception_4("함수 이름", 'a');
	PrintResult(exception_4);

	MOONG::ExceptionBadAlloc exception_5;
	PrintResult(exception_5);

	return 0;
}

void PrintResult(MOONG::Exception& exception)
{
	std::cout << "reason[" << exception.getReason().c_str() << "]" << std::endl;

	std::cout << std::endl;
}