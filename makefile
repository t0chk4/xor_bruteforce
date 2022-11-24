# Developed by t0chk4

all:
	g++ -o xbf src/xbf.cpp src/bruteforcer.cpp src/filters.cpp src/abstract_filter.cpp src/xor.cpp

test:
	g++ -o xbf_hw_test tests/hello_world.cpp src/bruteforcer.cpp src/filters.cpp src/abstract_filter.cpp src/xor.cpp
	g++ -o xbf_one_kib_test tests/kib.cpp src/bruteforcer.cpp src/filters.cpp src/abstract_filter.cpp src/xor.cpp

clear:
	rm xbf xbf_hw_test xbf_one_kib_test