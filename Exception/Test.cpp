#include "Exception.h"

void PrintResult(MOONG::Exception& exception);

int main()
{
	MOONG::ExceptionFunctionCallFailed<DWORD> exception_1("function_name", 123);
	PrintResult(exception_1);

	MOONG::ExceptionFunctionCallFailed<DWORD> exception_2("function_name", 321, false);
	PrintResult(exception_2);

	MOONG::ExceptionFunctionCallFailed<int> exception_3("function_name", 123);
	PrintResult(exception_3);

	MOONG::ExceptionFunctionCallFailed<char> exception_4("function_name", 'a');
	PrintResult(exception_4);

	return 0;
}

void PrintResult(MOONG::Exception& exception)
{
	std::cout << "reason[" << exception.getReason().c_str() << "]" << std::endl;

	std::cout << std::endl;
}