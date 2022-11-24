#include "xor.h"

namespace xbf
{

template <class T>
void encode_xor(T& c, const char key)
{
	std::for_each(c.begin(), c.end(), [=](auto& x) { x ^= key; });
}
	
};