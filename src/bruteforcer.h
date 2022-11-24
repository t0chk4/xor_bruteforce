#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iterator>

#include "filters.h"
#include "abstract_filter.h"

namespace xbf
{

class Bruteforcer
{

	using BytesList_t = std::vector<char>;
	using Key_t = char;
	using Filter_t = std::unique_ptr<filters::AbstractFilter>;

public:

	Bruteforcer(BytesList_t& bytes, Filter_t&& filter);

	Bruteforcer(std::string& bytes, Filter_t&& filter);

	Bruteforcer(const Bruteforcer&) = delete;

	void attack();

	Key_t get_key();

	~Bruteforcer() noexcept = default;

private:

	BytesList_t m_Bytes;

	Key_t m_Key;

	Filter_t m_Filter;

	// Filter_t m_Filter;

};

};