CC       ?= clang
CFLAGS   ?= -Wpedantic
LDFLAGS   = --static
TARGET    = $(shell basename `pwd`)

SRCDIR    = src
BUILDDIR  = obj
TARGETDIR = bin
DESTDIR   = /usr/bin
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

install:
	install -Dsm755  ${TARGETDIR}/${TARGET} ${DESTDIR}/${TARGET}

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $<
