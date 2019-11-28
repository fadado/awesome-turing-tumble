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

# Dot files to process
DotFiles := $(wildcard puzzle??*.gv)	\
	    puzzle02.gv puzzle07.gv	\
	    puzzle06.gv			\
	    puzzle192.gv		\
	    puzzle201.gv		\

# Targets to create
Images	   := $(addprefix img/,$(DotFiles:.gv=.png))
SvgTargets := $(addprefix SVG/,$(DotFiles:.gv=.svg))
PngTargets := $(addprefix PNG/,$(DotFiles:.gv=.png))
PdfTargets := $(addprefix PDF/,$(DotFiles:.gv=.pdf))
DotTargets := $(addprefix DOT/,$(DotFiles:.gv=.dot))
CppTargets := $(addprefix CPP/,$(DotFiles:.gv=.cpp))

# All depends on board.h
$(Images): board.h

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

WithText    := -DShowGraphLabel=1 -DShowObjective=1
WithoutText := -DShowGraphLabel=0 -DShowObjective=0

# Extracts puzzle ID
puzzle = -DPuzzle=$(patsubst 0%,%,$(patsubst $(3)puzzle%.$(2),%,$(1)))

# Render images
define render =
  cpp $(CPPFLAGS) $(ShowText) $(call puzzle,$@,$(1),$(2)) $< \
  | dot -T$(1) -o $@
endef

# Implicit rules
img/%.png: ShowText := $(WithoutText)
img/%.png: %.gv; $(call render,png,img/)

SVG/%.svg: ShowText := $(WithText)
SVG/%.svg: %.gv; $(call render,svg,SVG/)

PDF/%.pdf: ShowText := $(WithText)
PDF/%.pdf: %.gv; $(call render,pdf,PDF/)

PNG/%.png: ShowText := $(WithText)
PNG/%.png: %.gv; $(call render,png,PNG/)

# Derived graphs
define derived
img/puzzle$(1).png: ShowText := $(WithText)
img/puzzle$(1).png: puzzle$(2).gv; $$(call render,png,img/)
SVG/puzzle$(1).svg: ShowText := $(WithText)
SVG/puzzle$(1).svg: puzzle$(2).gv; $$(call render,svg,SVG/)
PNG/puzzle$(1).png: ShowText := $(WithText)
PNG/puzzle$(1).png: puzzle$(2).gv; $$(call render,png,PNG/)
PDF/puzzle$(1).pdf: ShowText := $(WithText)
PDF/puzzle$(1).pdf: puzzle$(2).gv; $$(call render,pdf,PDF/)
endef

$(eval $(call derived,02,01))
$(eval $(call derived,07,01))
$(eval $(call derived,06,05))
$(eval $(call derived,192,190))
$(eval $(call derived,201,200))

all: $(Images)
	@echo 'Done!'

# Debug only formats
define renderP =
  cpp $(CPPFLAGS) $(WithText) $(call puzzle,$@,$(1),$(2)) $< >$@
endef

define debugged
DOT/puzzle$(1).dot: ShowText := $(WithText)
DOT/puzzle$(1).dot: puzzle$(2).gv; $$(call renderP,dot,DOT/)
CPP/puzzle$(1).cpp: ShowText := $(WithText)
CPP/puzzle$(1).cpp: puzzle$(2).gv; $$(call renderP,cpp,CPP/)
endef

DOT CPP: ; mkdir $@

DOT/%.dot: %.gv | DOT; $(call renderP,dot,DOT/)
CPP/%.cpp: %.gv | CPP; $(call renderP,cpp,CPP/)

$(eval $(call debugged,02,01))
$(eval $(call debugged,07,01))
$(eval $(call debugged,06,05))
$(eval $(call debugged,192,190))
$(eval $(call debugged,201,200))

# Other formats
.PHONY: svg png pdf dot cpp publish debug

svg: $(SvgTargets)
png: $(PngTargets)
pdf: $(PdfTargets)

publish: all svg png pdf

dot: $(DotTargets)
cpp: $(CppTargets)

debug: dot cpp

########################################################################
# Tools
########################################################################

.PHONY: clean clobber help

clean:
	@rm -f SVG/*.svg img/*.png

clobber: clean
	@rm -f PNG/*.png PDF/*.pdf 
	@rm -rf DOT CPP

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
