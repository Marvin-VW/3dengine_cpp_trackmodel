[![Build status](https://github.com/Marvin-VW/3dengine_cpp/actions/workflows/tests.yaml/badge.svg)]()
[![GitHub latest commit](https://badgen.net/github/last-commit/Marvin-VW/3dengine_cpp)](https://GitHub.com/Marvin-VW/3dengine_cpp/commit/)

# 3dengine_cpp_trackmodel

Simple 3d Engine written in C++ using QT as UI.

## Dependencies

The project is based on the following components:

* CMake
* boost
* googletest
* fmt

See [scripts/](https://github.com/Marvin-VW/3dengine_cpp/tree/main/scripts) for dependency install scripts for multiple distributions.

GoogleTest is pulled in as a git submodule to avoid problems with missing cmake files in sub distributions.

## Usage

Clone, prepare and build with the following steps:

	git clone https://github.com/Marvin-VW/3dengine_cpp.git
	cd 3dengine_cpp

	git submodule update --init
	
	mkdir build/
	cd build/
	cmake ../
	make
