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
DotTargets := $(DotFiles:.gv=.dot)
CppTargets := $(DotFiles:.gv=.cpp)

$(SvgTargets): $(BOARD)

########################################################################
# Rules
########################################################################

WithText := -DShowGraphLabel=1 -DShowObjective=1
WithoutText := -DShowGraphLabel=0 -DShowObjective=0

CPPFLAGS :=			\
	-P			\
	-CC			\
	-undef			\
	-finput-charset=UTF-8	\
	-fdollars-in-identifiers\
	-Wno-deprecated		\
	-Wundef			\
	-Wunused-macros		\

CPP := cpp $(CPPFLAGS)

%.svg: %.gv
	@$(CPP) $(WithText) $< | dot -Tsvg -o $@

%.png: %.gv
	@$(CPP) $(WithoutText) $< | dot -Tpng -o PNG/$@

%.pdf: %.gv
	@$(CPP) $(WithText) $< | dot -Tpdf -o PDF/$@

# Debug only formats
DOT CPP: ; mkdir $@

%.dot: %.gv | DOT
	@$(CPP) $(WithText) $< | dot -Tdot -o DOT/$@

%.cpp: %.gv | CPP
	@$(CPP) $(WithText) $< > CPP/$@

.PHONY: svg png pdf dot cpp publish

svg: $(SvgTargets); @cp --update $(SvgTargets) SVG
png: $(PngTargets)
pdf: $(PdfTargets)
dot: $(DotTargets)
cpp: $(CppTargets)

all: $(SvgTargets)

########################################################################
# Tools
########################################################################

.PHONY: clean clobber help

clean:
	@rm -f *.svg

clobber: clean
	@rm -f SVG/*.svg PNG/*.png PDF/*.pdf

# Show targets
help:
	@echo 'Targets:';					\
	$(MAKE) --print-data-base --just-print 2>&1		\
	| grep -v '^[mM]akefile'				\
	| awk '/^[^ \t.%][-A-Za-z0-9_]*:/ { print $$1 }'	\
	| sort --unique						\
	| sed 's/:\+$$//'					\
	| pr --omit-pagination --indent=4 --width=80 --columns=4

# EOF
