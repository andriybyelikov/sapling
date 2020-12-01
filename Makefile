OBJDIR  := obj
SRCDIR  := src
BINARY  := sapling

CC      := gcc
CFLAGS  := -std=c11 -pedantic -I$(SRCDIR) -g
LDFLAGS := -lsapling

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR):
	mkdir $@

clean:
	rm -rf $(OBJDIR) $(BINARY)
