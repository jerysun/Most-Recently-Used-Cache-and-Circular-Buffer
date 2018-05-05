DEBUG           = yes
AS							= as
CXX							= g++
LD							= ld
CPP             = $(CXX) -E
AR              = ar
NM              = nm
STRIP           = strip
RM              = rm -rf

CXXFLAGS				= -Wall -g -std=c++14
LDFLAGS					= 
PWD         		= $(shell pwd)
INCDIR					= $(PWD)
LIBDIR					= $(PWD)

#LIBRARY1		= -lm
OBJS           += main.o
OBJS           := $(OBJS:%.cpp=%.o)

$(LIB1:=$(LIBRARY1))

$(PWD)/%.o: $(PWD)/%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $< -I$(INCDIR)

T = mru_cb

$T:$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ -L$(LIBDIR) $(LIB1)
ifneq ($(DEBUG),yes)
	@$(STRIP) $@
endif
	
clean:
	$(RM) *.o $T core
