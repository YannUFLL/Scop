CC=g++
CFLAGS=-I. -I./include -Werror -Wextra -Wall 
FRAMEWORK=-framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -framework CoreGraphics
SRCDIR=src
OBJDIR=obj
BINDIR=.
LIBDIR=./lib

LIB=$(patsubst $(LIBDIR)/lib%.a,%,$(wildcard $(LIBDIR)/*.a))
SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

$(BINDIR)/scop: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(FRAMEWORK) -L$(LIBDIR) -l $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/scop