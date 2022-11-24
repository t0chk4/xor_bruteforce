#include <memory>

#include "../src/xbf.h"

int main()
{

	const char key = 0x7f;

	std::string valid 	   { 0x37, 0x1a, 0x13, 0x13, 0x10, 0x5f, 0x8, 0x10, 0xd, 0x13, 0x1b, 0x5e };
	std::string non_valid1 { 0x11, 0x1a, 0x13, 0x13, 0x10, 0x5f, 0x8, 0x10, 0xd, 0x13, 0x1b, 0x5e };
	std::string non_valid2 { 0x37, 0x1a, 0x13, 0x13, 0x10, 0x5f, 0x8, 0x10, 0xd, 0x13, 0x1b, 0x11 };

	std::string start_kw = "Hell";
	std::string end_kw = "ld!";

	xbf::Bruteforcer bf1(valid, std::make_unique<xbf::filters::StartsWith>(start_kw));
	bf1.attack();
	std::cout << "Test #1: " << (bf1.get_key() == key ? "Correct" : "Failed") << '\n';

	xbf::Bruteforcer bf2(non_valid1, std::make_unique<xbf::filters::StartsWith>(start_kw));
	bf2.attack();
	std::cout << "Test #2: " << (bf2.get_key() == 0 ? "Correct" : "Failed") << '\n';

	xbf::Bruteforcer bf3(non_valid2, std::make_unique<xbf::filters::EndsWith>(end_kw));
	bf3.attack();
	std::cout << "Test #3: " << (bf3.get_key() == 0 ? "Correct" : "Failed") << '\n';
	std::cout << std::endl;

	return 0;
	
}