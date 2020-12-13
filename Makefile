INCDIR  := include
SRCDIR  := src
OBJDIR  := obj
BINARY  := sapling

CC      := gcc
CFLAGS  := -std=c11 -pedantic -I$(SRCDIR) -I$(INCDIR) -g
LDFLAGS := -lsapling

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))

.PHONY: all clean install

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR):
	mkdir $@

clean:
	rm -rf $(OBJDIR) $(BINARY)

install:
	cp sapling /usr/local/bin
	gzip -kf sapling.1
	cp sapling.1.gz /usr/local/man/man1
