
OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = testSmallVector

all: $(TARGETS)

testSmallVector: testSmallVector.o
	g++ -o testSmallVector testSmallVector.o

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o
