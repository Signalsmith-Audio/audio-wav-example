.PHONY: main clean
.SILENT: main

main: out/main
	cd out && ./main

out/main: wav.h main.cpp
	mkdir -p out
	g++ -std=c++11 main.cpp -o out/main

clean:
	rm -rf out
