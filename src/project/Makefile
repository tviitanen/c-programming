# HT Tavoitetaso 26.3.2022
# Teemu Viitanen
# 00456573

HT: HTTavoitetaso.o HTPerusKirjasto.o HTTavoiteKirjasto.o
	gcc HTTavoitetaso.o HTPerusKirjasto.o HTTavoiteKirjasto.o -o HT
HTTavoitetaso.o: HTTavoitetaso.c HTPerusKirjasto.h
	gcc HTTavoitetaso.c -c -std=c99 -pedantic -Wall
HTPerusKirjasto.o: HTPerusKirjasto.c HTPerusKirjasto.h
	gcc HTPerusKirjasto.c -c -std=c99 -pedantic -Wall
HTTavoiteKirjasto.o: HTTavoiteKirjasto.c HTPerusKirjasto.h
	gcc HTTavoiteKirjasto.c -c -std=c99 -pedantic -Wall
