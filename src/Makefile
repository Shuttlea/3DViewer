CC = gcc -Wall -Werror -Wextra -std=c11
OS := $(shell uname)
CHECK_PATH = $(shell pkg-config --cflags --libs check)

ifeq ($(OS),Darwin)
#IF MACOS DOES'T USE PKG-CONFIG, ONLY HOMEBREW:
#CHECK_PATH = -I$(shell brew --prefix check)/include -L$(shell brew --prefix check)/lib -lcheck -lm -lpthread
GCOV_EX = --gcov-executable gcov-13 -r . #DEPENDS ON VERSION
endif

all: install

install:
	mkdir build
	cmake -B build
	cd ./build && make && cd ../
	ln -s $(PWD)/build/QOpenGLWidget.app $(HOME)/Desktop/QOpenGLWidget

uninstall:
	rm -rf build $(HOME)/Desktop/QOpenGLWidget

dist: 
	mkdir build
	cmake -B build
	cd ./build && make && cd ../
	mkdir 3DViewer-1.0
	mv ./build/QOpenGLWidget.app ./3DViewer-1.0/
	tar -cf 3DViewer.tar 3DViewer-1.0/QOpenGLWidget.app

tests: viewer.c viewer.h test/test_viewer.c
	$(CC) --coverage -c viewer.c -o test/viewer.o
	$(CC) -c test/test_viewer.c -o test/test_viewer.o $(CHECK_PATH)
	$(CC) --coverage test/viewer.o test/test_viewer.o -o test/testing $(CHECK_PATH)
	./test/testing

dvi:
	doxygen viewerconfig 
	open html/index.html

gcov_report: tests
	mkdir report
	gcovr $(GCOV_EX) --html --html-details -o report/coverage_report.html

clean:
	rm -rf build a.out $(HOME)/Desktop/QOpenGLWidget ./3DViewer-1.0 3DViewer.tar test/*.o test/testing test/*.gcno test/*.gcda report latex html

clang:
#	clang-format -i *.c *.cpp *.h test/*.c Viwer/*.cpp Viwer/*.h Model/*.h Model/*.cpp
	clang-format -i  test/*.c Viwer/*.cpp Viwer/*.h Model/*.h Model/*.cpp Controller/*.cpp Controller/*.h
