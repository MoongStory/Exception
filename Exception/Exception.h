// https://github.com/MoongStory/Exception

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <Windows.h>

namespace MOONG
{
	namespace EXCEPTION
	{
		const enum CODE
		{
			SUCCESS = 0,
			FUNCTION_CALL_FAILED = 1
		};
	}

	class Exception
	{
	public:
	protected:
	private:
		int code;
		std::string reason;
		DWORD last_error;

	public:
		Exception(const int code, const std::string reason, const DWORD last_error = 0);

		const int getCode();
		const std::string getReason();
	protected:
	private:
	};
}

#endif	// _EXCEPTION_H_