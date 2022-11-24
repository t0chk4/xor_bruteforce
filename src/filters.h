#pragma once

#include "abstract_filter.h"

namespace xbf
{

namespace filters
{

class StartsWith : public AbstractFilter
{

	using BytesList_t = AbstractFilter::BytesList_t;
	using FilterKeyword_t = AbstractFilter::FilterKeyword_t;

public:

	StartsWith(FilterKeyword_t& keyword);

	bool check(BytesList_t& bytes) override;

	~StartsWith() noexcept = default;

private:

	FilterKeyword_t m_Keyword;

};

class EndsWith : public AbstractFilter
{

	using BytesList_t = AbstractFilter::BytesList_t;
	using FilterKeyword_t = AbstractFilter::FilterKeyword_t;

public:

	EndsWith(FilterKeyword_t& keyword);

	bool check(BytesList_t& bytes) override;

	~EndsWith() noexcept = default;

private:

	FilterKeyword_t m_Keyword;

};

};

};