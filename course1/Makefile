#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
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

# Platform Overrides (default is HOST)
PLATFORM = HOST

# Compiler Flags and Defines
CC = gcc
CFLAGS = -Wall -Werror -Wno-pointer-sign -g -O0 -std=c99
CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE $(INCLUDES)

TARGET = course1.out
OBJS = $(SOURCES:.c=.o)

# Compile one .c file into one .o file
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# Link everything into the executable
.PHONY: build
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Remove generated files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
