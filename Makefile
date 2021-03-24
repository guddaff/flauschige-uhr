CC       ?= clang
CFLAGS   ?= -Wpedantic
TARGET    = $(shell basename `pwd`)

SRCDIR    = src
BUILDDIR  = obj
TARGETDIR = bin
SRCEXT    = c
OBJEXT    = o

SOURCES   = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS   = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

all: directories $(TARGET)

directories:
	@mkdir -p $(BUILDDIR) $(SRCDIR) $(TARGETDIR)

clean:
	@rm -rf $(BUILDDIR)/*

cleanall:
	@rm -rf $(TARGETDIR) $(BUILDDIR)

format:
	clang-format -i $(SOURCES)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<
