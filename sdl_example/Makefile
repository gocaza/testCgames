# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 -g --std=c17 -Wall -lSDL2 -lm
# CFLAGS = -Os -g -std=c17 -Wall -Werror
# CFLAGS += -Wsign-compare -Wwrite-strings -Wtype-limits -pedantic
# # CFLAGS += -fsanitize=address
# ## Use short (8-bit) data types 
# CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
# ## Splits up object files per function
# CFLAGS += -ffunction-sections -fdata-sections 

##LIBDIR = ../../AVR-Programming-Library
#LIBDIR = /usr/lib/avr/include
TARGET = main
# TARGET = $(lastword $(subst /, ,$(CURDIR)))

SOURCES=$(wildcard *.c $(LIBDIR)/*.c)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(wildcard *.h $(LIBDIR)/*.h)
REBUILDABLES = $(OBJECTS) $(TARGET)

all: $(TARGET)
	echo All done

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH)

%.o: %.c $(HEADERS) Makefile
	 $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<


# clang `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm   -c -o sdl_example.o sdl_example.c
# clang -o game sdl_example.o `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm

# clang `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm   -c -o sdl_example.o sdl_example.c
# clang -o game sdl_example.o `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace

%.dep: %.c
	$(CC) -M $(FLAGS) $< > $@
include $(OBJECTS:.o=.dep)

clean:
	rm -f $(REBUILDABLES) \
	$(OBJECTS:.o=.dep)
.PHONY: all clean
