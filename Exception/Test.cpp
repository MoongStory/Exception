#include "Exception.h"

void PrintResult(const std::exception& exception);

int main()
{
	//MOONG::ExceptionFunctionCallFailed exception_1;
	//PrintResult(exception_1);

	return 0;
}

void PrintResult(const std::exception& exception)
{
	std::cout << "what[" << exception.what() << "]" << std::endl;

	std::cout << std::endl;
}