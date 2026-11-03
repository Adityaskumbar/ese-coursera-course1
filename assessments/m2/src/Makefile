#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colora#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Host platform configuration
PLATFORM = HOST

CC = gcc
LD = gcc

CFLAGS = -Wall -Werror -Wno-pointer-sign -g -O0 -std=c99
CPPFLAGS = -DHOST $(INCLUDES)
LDFLAGS =

TARGET = m2.out
OBJS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: build clean

build: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
