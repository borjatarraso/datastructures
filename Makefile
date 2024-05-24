# This file is a part of DS Project
# Makefile - dependency rules, macros and suffix (or implicit) rules
# Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>

CC = @gcc
CFLAGS = -W -Wall -ansi -pedantic -Wbad-function-cast -Wcast-align -Wcast-qual \
	 -Wchar-subscripts -Winline -Wmissing-prototypes -Wnested-externs \
	 -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes \
	 -Wwrite-strings

SRC = list.c list.h
OBJ = list.o
TARGET = list

$(TARGET): ut_list.o list.a
	$(CC) $(CFLAGS) $^ -o $@

ut_list.o: ut_list.c
	$(CC) $(CFLAGS) -c $< -o $@

list.a: $(OBJ)
	$(AR) rcs $@ $^

$(OBJ_LIST): $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f *.o *.a $(TARGET)
