#
# Makefile for rASCIIng
#
CXX      = g++

racing: game.cpp map.cpp parse.cpp print_racing.cpp rASCIIng.cpp game.h map.h parse.h print_racing.h
                     
	${CXX} -o racing game.cpp map.cpp parse.cpp print_racing.cpp rASCIIng.cpp
