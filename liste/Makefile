CFLAGS = -Wall

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=bin/%)

all: $(BINS)

bin:
	mkdir $@

clean:
	rm bin/*

# Tell make that the binaries in the current directory are intermediate files so it doesn't need to care about them directly (and can delete them). http://www.gnu.org/software/make/manual/make.html#index-_002eINTERMEDIATE
# This keeps make from building the binary in the current directory a second time if you run `make; make`.
.INTERMEDIATE: $(notdir $(BINS))

# Tell make that it should delete targets if their recipes error. http://www.gnu.org/software/make/manual/make.html#index-_002eDELETE_005fON_005fERROR
.DELETE_ON_ERROR:

# This is a static pattern rule to tell make how to handle all the `$(BINS)` files. http://www.gnu.org/software/make/manual/make.html#Static-Pattern
$(BINS) : bin/% : % | bin
			mv $^ $@
