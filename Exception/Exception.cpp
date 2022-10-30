#include "Exception.h"

// https://github.com/MoongStory/ConvertDataType
#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

MOONG::Exception::Exception(const int code, const std::string reason, const DWORD last_error/* = 0*/) : code(code), reason(reason), last_error(last_error)
{
}

const int MOONG::Exception::getCode()
{
	return this->code;
}

const std::string MOONG::Exception::getReason()
{
	if (this->code == MOONG::EXCEPTION::CODE::FUNCTION_CALL_FAILED)
	{
		reason += " function call failed.";

		if (this->last_error != 0)
		{
			reason += std::string(" GetLastError[") + MOONG::ConvertDataType::dword_to_string(this->last_error) + std::string("]");
		}
	}

	return this->reason;
}
