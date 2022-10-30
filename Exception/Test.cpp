#include "Exception.h"

void PrintResult(MOONG::Exception& exception);

int main()
{
	MOONG::Exception exception_1(1, "function_name");
	PrintResult(exception_1);

	MOONG::Exception exception_2(1, "function_name", 12);
	PrintResult(exception_2);
}

void PrintResult(MOONG::Exception& exception)
{
	std::cout << "CODE[" << exception.getCode() << "], reason[" << exception.getReason().c_str() << "]" << std::endl;
}