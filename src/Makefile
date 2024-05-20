# CC = gcc -Wall -Werror -Wextra -std=c11
# OS := $(shell uname)
# CHECK_PATH = $(shell pkg-config --cflags --libs check)

C = g++ 
FLAGS = -std=c++17 -Wall -Werror -Wextra
GTEST = $(shell pkg-config --cflags --libs gtest)  -pthread
GCOV =  -fprofile-arcs -ftest-coverage
# TARGETS = Model/model.cc Test/test.cc 
# GTFLAG = $(shell pkg-config --cflags --libs gtest) -pthread
GCOV_EX = --gcov-executable  --exclude-throw-branches --html --html-details
SOURCES=*.c
OBJECTS=*.o

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
	mkdir 3DViewer-2.0
	mv ./build/QOpenGLWidget.app ./3DViewer-2.0/
	tar -cf 3DViewer.tar 3DViewer-2.0/QOpenGLWidget.app

# tests: viewer.c viewer.h test/test_viewer.c
# 	$(CC) --coverage -c viewer.c -o test/viewer.o
# 	$(CC) -c test/test_viewer.c -o test/test_viewer.o $(CHECK_PATH)
# 	$(CC) --coverage test/viewer.o test/test_viewer.o -o test/testing $(CHECK_PATH)
# 	./test/testing

test:
	$(C) $(FLAGS) $(GTEST) $(GCOV) -c Model/*.cpp
	$(C) $(FLAGS) $(GTEST) $(GCOV) -c -o test.o  Test/test.cc  
#	$(C) $(FLAGS) -o testss $(TARGETS)  $(GTEST) $(GCOV)
	$(C) $(FLAGS) $(GCOV) $(OBJECTS) -o tests  $(GTEST) 
#	$(C) $(FLAGS) -o testss model.o test.o $(GCOV)  -mmacosx-version-min=11.5  -pthread
	./tests

dvi:
	doxygen viewerconfig 
	open html/index.html

# gcov_report: tests
# 	mkdir report
# 	gcovr $(GCOV_EX) --html --html-details -o report/coverage_report.html

gcov_report: clean add_coverage test
	mkdir report
	gcovr --html-details --exclude-throw-branches -o report/coverage.html
	open ./report/coverage.html

clean:
	rm -rf build test tests *.o *.gcno *.gcda report latex html 

clang:
#	clang-format -i *.c *.cpp *.h test/*.c Viwer/*.cpp Viwer/*.h Model/*.h Model/*.cpp
	clang-format -i  Test/*.c Viwer/*.cpp Viwer/*.h Model/*.h Model/*.cpp Controller/*.cpp Controller/*.h movingClasses/*.h

add_coverage:
	$(eval FLAGS += --coverage)

.PHONY: all test clean gcov_report