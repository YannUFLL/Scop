CC=g++
CFLAGS=-I. -I./include -Werror -Wextra -Wall
SRCDIR=src
OBJDIR=obj
BINDIR=.

SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

$(BINDIR)/scop: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/scop