#include "xbf.h"
#include "xor.h"

int main()
{
	std::string str = { 55, 26, 19, 19, 16, 95, 8, 16, 13, 19, 27, 94 };
	std::string keyword = "d!";
	xbf::Bruteforcer bf(str, std::make_unique<xbf::filters::EndsWith>(keyword));
	bf.attack();
	char key = bf.get_key();
	if (key == 0)
	{
		std::cout << "Attack failed!" << std::endl;
	}
	else
	{
		std::string decoded(str);
		xbf::encode_xor(decoded, key);
		std::cout << "Possible key: `" 
				  << key 
				  << "`(" 
				  << std::hex 
				  << int(key) 
				  << ")\n" 
				  << "Decoded message: " 
				  << decoded 
				  << std::endl;
	}
	return 0;
}