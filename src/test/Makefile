
include ../../dmlc-core/make/config.mk
include ../../dmlc-core/make/dmlc.mk

BIN = read.dmlc

# common build script for programs
export CXX=/usr/local/Cellar/gcc/7.2.0/bin/g++-7
export LDFLAGS= -L../../lib -pthread -lm -lrt $(DMLC_LDFLAGS)
export CFLAGS = -Wall  -msse2  -Wno-unknown-pragmas -fPIC -I../../rabit/include  -I../../dmlc-core/include -std=c++11 -fopenmp

ifdef DEPS_PATH
CFLAGS+= -I$(DEPS_PATH)/include
LDFLAGS+= -L$(DEPS_PATH)/lib
endif

# read.dmlc : read.cpp ../../dmlc-core/libdmlc.a ../../rabit/lib/librabit.a
read.dmlc : read.cpp ../../dmlc-core/libdmlc.a

all: $(BIN) 

$(BIN) : 
	$(CXX) $(CFLAGS) -o $@ $(filter %.cpp %.o %.c %.cc %.a,  $^) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(BIN)  *~ ../src/*~

