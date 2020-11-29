.PHONY: main
ifndef VERBOSE
.SILENT:
endif

main: out/main
	cd out && ./main

out/main: *.h main.cpp
	mkdir -p out
	g++ -std=c++11 -Wall -Wextra -Wfatal-errors -O3 \
 		-Wpedantic -pedantic-errors \
		main.cpp \
		-o out/main

clean:
	rm -rf out
