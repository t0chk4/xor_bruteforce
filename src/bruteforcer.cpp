#include "bruteforcer.h"

namespace xbf
{

Bruteforcer::Bruteforcer(Bruteforcer::BytesList_t& bytes, Bruteforcer::Filter_t&& filter)
	: m_Bytes(bytes)
	, m_Key(1)
	, m_Filter(std::move(filter))
{ }

Bruteforcer::Bruteforcer(std::string& bytes, Bruteforcer::Filter_t&& filter)
	: m_Bytes(bytes.size())
	, m_Key(1)
	, m_Filter(std::move(filter))
{
	std::copy(bytes.begin(), bytes.end(), m_Bytes.begin());
}

void Bruteforcer::attack()
{
	BytesList_t buffer;
	for (; m_Key != 0; ++m_Key)
	{
		buffer = m_Bytes;
		for (auto& x : buffer)
		{
			x ^= m_Key;
		}
		if (m_Filter->check(buffer))
		{
			return;
		}
	}
	return;
}

Bruteforcer::Key_t Bruteforcer::get_key()
{
	return m_Key;
}

};