################################################################################
# VARIABLES: Definition of the relevant variables from the configuration script.
################################################################################

# Include the configuration.
-include Makefile.inc

CXX_COMMON:=-I$(PREFIX_INCLUDE) $(CXX_COMMON) $(GZIP_LIB)
CXX_COMMON+= -L$(PREFIX_LIB) -Wl,-rpath,$(PREFIX_LIB) -lpythia8 -ldl

################################################################################
# RULES: Definition of the rules used to build the PYTHIA examples.
################################################################################

# Rules without physical targets (secondary expansion for specific rules).
.SECONDEXPANSION:
.PHONY: all clean

# All targets (no default behavior).
all:
	$(info Usage: make XX)

# PYTHIA, ROOT and FastJet.
eventGenerator: $$@.cc 
ifeq ($(ROOT_USE)$(FASTJET3_USE),truetrue)
	$(CXX) $@.cc -o $@ -w $(CXX_COMMON) $(shell $(FASTJET3_CONFIG) --cxxflags --libs) $(shell $(ROOT_CONFIG) --cflags --glibs)
else	
	$(error Error: $@ requires ROOT and FASTJET3)
endif