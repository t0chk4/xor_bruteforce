#include "filters.h"

namespace xbf
{

namespace filters
{

// StartsWith

StartsWith::StartsWith(StartsWith::FilterKeyword_t& keyword)
	: m_Keyword(keyword)
{ }

bool StartsWith::check(StartsWith::BytesList_t& bytes)
{
	int kw_size = m_Keyword.size();
	if (bytes.size() < kw_size)
		return false;
	for (size_t i = 0; i < kw_size; ++i)
	{
		if (bytes[i] != m_Keyword[i])
			return false;
	}
	return true;
}

// EndsWith

EndsWith::EndsWith(EndsWith::FilterKeyword_t& keyword)
	: m_Keyword(keyword)
{ }

bool EndsWith::check(EndsWith::BytesList_t& bytes)
{
	int kw_size = m_Keyword.size();
	if (bytes.size() < kw_size)
		return false;
	for (size_t i = 0; i < kw_size; ++i)
	{
		if (bytes[bytes.size() - 1 - i] != m_Keyword[kw_size - 1 - i])
			return false;
	}
	return true;
}

};

};