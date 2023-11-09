# Makefile

all: build

build:
	mkdir -p build
	cd build && cmake ..
	cd build && make -j4

clean:
	rm -rf build

