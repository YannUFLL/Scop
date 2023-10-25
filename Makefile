CC=g++
CFLAGS=-I. -I./include -Werror -Wextra -Wall 
LDFLAGS=
SRCDIR=src
OBJDIR=obj
BINDIR=.
LIBDIRMACOS=./lib/macos
LIBDIRLINUX=./lib/linux

LIBMACOS=$(patsubst $(LIBDIRMACOS)/lib%.a,-l%,$(wildcard $(LIBDIRMACOS)/*.a))
LIBLINUX=$(patsubst $(LIBDIRLINUX)/lib%.a,-l%,$(wildcard $(LIBDIRLINUX)/*.a))
SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

#platform specific

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
    LDFLAGS += -L$(LIBDIRMACOS) -l $(LIBMACOS) -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -framework CoreGraphic 
endif
ifeq ($(UNAME_S), Linux) # Linux
    LDFLAGS +=-L$(LIBDIRLINUX) $(LIBLINUX) -lGL 
endif

all: $(BINDIR)/scop

re : fclean all

$(BINDIR)/scop: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJDIR)/*.o 

fclean: clean
	rm -f $(BINDIR)/scop

.PHONY: clean fclean