// https://github.com/MoongStory/Exception

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <Windows.h>
#include <exception>

namespace MOONG
{
	//class ExceptionFunctionCallFailed : public std::exception
	//{
	//public:
	//	const char* what() const noexcept override
	//	{
	//		return "함수 호출 실패.";
	//	}
	//};
}

#endif	// _EXCEPTION_H_