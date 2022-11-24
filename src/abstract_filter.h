#pragma once

#include <string>
#include <vector>

namespace xbf
{

namespace filters
{

class AbstractFilter
{

protected:

	using FilterKeyword_t = std::string;
	using BytesList_t = std::vector<char>;

public:

	virtual ~AbstractFilter() = default;

	virtual bool check(BytesList_t& bytes) = 0;

protected:

	FilterKeyword_t m_Keyword;

};

};

};