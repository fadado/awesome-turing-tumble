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
#.SILENT:

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
DotFiles := $(wildcard puzzle??.gv)
Duplicated := puzzle02.gv puzzle06.gv puzzle07.gv

# Targets to create
SvgTargets := $(DotFiles:.gv=.svg) $(Duplicated:.gv=.svg)
PngTargets := $(DotFiles:.gv=.png) $(Duplicated:.gv=.png)
PdfTargets := $(DotFiles:.gv=.pdf) $(Duplicated:.gv=.pdf)
DotTargets := $(DotFiles:.gv=.dot)
CppTargets := $(DotFiles:.gv=.cpp)

$(SvgTargets): $(BOARD)

########################################################################
# Rules
########################################################################

CPPFLAGS :=			\
	-P			\
	-CC			\
	-undef			\
	-finput-charset=UTF-8	\
	-fdollars-in-identifiers\
	-Wno-deprecated		\
	-Wundef			\
	-Wunused-macros		\

WithText := -DShowGraphLabel=1 -DShowObjective=1
WithoutText := -DShowGraphLabel=0 -DShowObjective=0

CPP = cpp $(CPPFLAGS)

# Extracts puzzle ID
puzzle = -DPuzzle=$(patsubst 0%,%,$(patsubst puzzle%.$(2),%,$(1)))

# Render with text into a directory
define renderT =
  @$(CPP) $(WithText) $(call puzzle,$@,$(1)) $< \
   | dot -T$(1) -o $(2)/$@
endef

# Render without text, only image, into a directory
define renderI =
  @$(CPP) $(WithoutText) $(call puzzle,$@,$(1)) $< \
   | dot -T$(1) -o $(2)/$@
endef

# Debug
define renderD =
  @$(CPP) $(WithText) $(call puzzle,$@,$(1)) $< >$(2)/$@
endef

# Implicit rules

%.svg: %.gv; $(call renderT,svg,./)
%.png: %.gv; $(call renderI,png,PNG)
%.pdf: %.gv; $(call renderT,pdf,PDF)

# Debug only formats
DOT CPP: ; mkdir $@
%.dot: %.gv | DOT; @$(call renderT,dot,DOT)
%.cpp: %.gv | CPP; @$(call renderD,cpp,CPP)

# Duplicated graphs
puzzle02.svg: puzzle01.gv; $(call renderT,svg,./)
puzzle02.png: puzzle01.gv; $(call renderI,png,PNG)
puzzle02.pdf: puzzle01.gv; $(call renderT,pdf,PDF)

puzzle06.svg: puzzle05.gv; $(call renderT,svg,./)
puzzle06.png: puzzle05.gv; $(call renderI,png,PNG)
puzzle06.pdf: puzzle05.gv; $(call renderT,pdf,PDF)

puzzle07.svg: puzzle01.gv; $(call renderT,svg,./)
puzzle07.png: puzzle01.gv; $(call renderI,png,PNG)
puzzle07.pdf: puzzle01.gv; $(call renderT,pdf,PDF)

# Targets

.PHONY: svg png pdf dot cpp publish

svg: $(SvgTargets); @cp --update *.svg SVG
png: $(PngTargets)
pdf: $(PdfTargets)
dot: $(DotTargets)
cpp: $(CppTargets)
publish: svg png pdf dot cpp

all: $(SvgTargets)
	@echo 'Done!'

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
