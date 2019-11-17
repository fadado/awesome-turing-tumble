# Makefile for Turing Tumble graphs

########################################################################
# Configuration
########################################################################

# Disable builtins.
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

# Warn when an undefined variable is referenced.
MAKEFLAGS += --warn-undefined-variables

# Make will not print the recipe used to remake files.
.SILENT:

# Eliminate use of the built-in implicit rules. Also clear out the
# default list of suffixes for suffix rules.
.SUFFIXES:

# Sets the default goal to be used if no targets were specified on the
# command line.
.DEFAULT_GOAL := all

# When it is time to consider phony targets, make will run its recipe
# unconditionally, regardless of whether a file with that name exists or
# what its last-modification time is.
.PHONY: all

# Default shell: if we require GNU Make, why not require Bash?
SHELL := /bin/bash

# The argument(s) passed to the shell are taken from the variable
# .SHELLFLAGS.
.SHELLFLAGS := -o errexit -o pipefail -o nounset -c

# Make will delete the target of a rule if it has changed and its recipe
# exits with a nonzero exit status.
.DELETE_ON_ERROR:

########################################################################
# Targets and files
########################################################################

BOARD=board.h

# Dot files to process
DotFiles := $(wildcard *.gv)

# Targets to create
SvgTargets := $(DotFiles:.gv=.svg)
PngTargets := $(DotFiles:.gv=.png)
PdfTargets := $(DotFiles:.gv=.pdf)

$(SvgTargets): $(BOARD)

########################################################################
# Rules
########################################################################

%.svg: %.gv
	cpp -P $< | dot -Tsvg -o $@

%.png: %.gv
	cpp -P $< | dot -Tpng -o $@

%.pdf: %.gv
	cpp -P $< | dot -Tpdf -o $@

.PHONY: svg png pdf

svg: $(SvgTargets)
png: $(PngTargets)
pdf: $(PdfTargets)

all: $(SvgTargets)
	#@ls -lh *.svg

########################################################################
# Tools
########################################################################

.PHONY: clean list

clean:
	@rm -f *.svg *.png *.pdf

# Show targets
help:
	echo 'Targets:';					\
	$(MAKE) --print-data-base --just-print 2>&1		\
	| grep -v '^[mM]akefile'				\
	| awk '/^[^ \t.%][-A-Za-z0-9_]*:/ { print $$1 }'	\
	| sort --unique						\
	| sed 's/:\+$$//'					\
	| pr --omit-pagination --indent=4 --width=80 --columns=4

# EOF
