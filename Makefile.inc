# PYTHIA configuration file.

# Install directory prefixes.
PREFIX_BIN=/cvmfs/sft.cern.ch/lcg/releases/MCGenerators/pythia8/245-956de/x86_64-centos7-gcc8-opt/bin
PREFIX_INCLUDE=/cvmfs/sft.cern.ch/lcg/releases/MCGenerators/pythia8/245-956de/x86_64-centos7-gcc8-opt/include
PREFIX_LIB=/cvmfs/sft.cern.ch/lcg/releases/MCGenerators/pythia8/245-956de/x86_64-centos7-gcc8-opt/lib
PREFIX_SHARE=/cvmfs/sft.cern.ch/lcg/releases/MCGenerators/pythia8/245-956de/x86_64-centos7-gcc8-opt/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
CXX=g++
CXX_COMMON=-O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC -pthread
CXX_SHARED=-dynamiclib
CXX_SONAME=-Wl,-dylib_install_name,@rpath/
LIB_SUFFIX=.dylib
OBJ_COMMON=

FASTJET3_USE=true
FASTJET3_CONFIG=fastjet-config
FASTJET3_BIN=/cvmfs/sft.cern.ch/lcg/releases/fastjet/3.4.0p1-af3e7/x86_64-centos7-gcc8-opt/bin
FASTJET3_INCLUDE=-I/cvmfs/sft.cern.ch/lcg/releases/fastjet/3.4.0p1-af3e7/x86_64-centos7-gcc8-opt/include
FASTJET3_LIB=-L/cvmfs/sft.cern.ch/lcg/releases/fastjet/3.4.0p1-af3e7/x86_64-centos7-gcc8-opt/lib

ROOT_USE=true
ROOT_CONFIG=root-config
ROOT_BIN=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.24.06-3455f/x86_64-centos7-gcc8-opt/bin
ROOT_INCLUDE=-I/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.24.06-3455f/x86_64-centos7-gcc8-opt/include
ROOT_LIB=-L/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.24.06-3455f/x86_64-centos7-gcc8-opt/lib