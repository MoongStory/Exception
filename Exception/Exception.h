// https://github.com/MoongStory/Exception

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <iostream>
#include <Windows.h>

// https://github.com/MoongStory/ConvertDataType
#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

namespace MOONG
{
	class Exception
	{
	public:
	protected:
	private:

	public:
		virtual const std::string getReason() = 0;
	protected:
	private:
	};



	template <typename T> class ExceptionFunctionCallFailed : public Exception
	{
	public:
	protected:
	private:
		std::string function_name;
		T error_code;
		bool isGetLastError;

	public:
		ExceptionFunctionCallFailed(const std::string function_name, T error_code, bool isGetLastError = true) : function_name(function_name), error_code(error_code), isGetLastError(isGetLastError)
		{
		}

		const std::string getReason()
		{
			return "정의되지 않은 자료형. 클래스 템플릿 특수화를 추가해주세요.";
		}
	protected:
	private:
	};

	template <> class ExceptionFunctionCallFailed<DWORD> : public Exception
	{
	public:
	protected:
	private:
		std::string function_name;
		DWORD error_code;
		bool isGetLastError;

	public:
		ExceptionFunctionCallFailed(const std::string function_name, DWORD error_code, bool isGetLastError = true) : function_name(function_name), error_code(error_code), isGetLastError(isGetLastError)
		{
		}

		const std::string getReason()
		{
			std::string reason = std::string("[") + this->function_name + std::string("] 함수 호출 실패.");

			if (this->isGetLastError == true)
			{
				reason += std::string(" GetLastError[");
			}
			else
			{
				reason += std::string(" ErrorCode[");
			}

			reason += MOONG::ConvertDataType::dword_to_string(this->error_code) + std::string("]");

			return reason;
		}
	protected:
	private:
	};

	template <> class ExceptionFunctionCallFailed<int> : public Exception
	{
	public:
	protected:
	private:
		std::string function_name;
		int error_code;
		bool isGetLastError;

	public:
		ExceptionFunctionCallFailed(const std::string function_name, int error_code, bool isGetLastError = true) : function_name(function_name), error_code(error_code), isGetLastError(isGetLastError)
		{
		}

		const std::string getReason()
		{
			std::string reason = std::string("[") + this->function_name + std::string("] 함수 호출 실패.");

			if (this->isGetLastError == true)
			{
				reason += std::string(" GetLastError[");
			}
			else
			{
				reason += std::string(" ErrorCode[");
			}

			reason += MOONG::ConvertDataType::int_to_string(this->error_code) + std::string("]");

			return reason;
		}
	protected:
	private:
	};

	class ExceptionBadAlloc : public Exception
	{
	public:
	protected:
	private:

	public:
		const std::string getReason()
		{
			return "메모리 할당 실패.";
		}
	protected:
	private:
	};
}

#endif	// _EXCEPTION_H_