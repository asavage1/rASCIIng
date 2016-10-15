#
# Makefile for rASCIIng
#
CXX      = g++

racing: game.cpp map.cpp parse.cpp print_racing.cpp rASCIIng.cpp game.h map.h parse.h print_racing.h
	${CXX} -o racing game.cpp map.cpp parse.cpp print_racing.cpp rASCIIng.cpp

racing_mac: game.cpp map.cpp parse_ncurses.cpp print_racing.cpp rASCIIng.cpp game.h map.h parse.h print_racing.h
	${CXX} -o racing_mac game.cpp map.cpp parse_ncurses.cpp print_racing.cpp rASCIIng.cpp

test_ncurses: test_ncurses.cpp
	${CXX} -lncurses -o test_ncurses test_ncurses.cpp
