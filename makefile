
OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = testSmallVector testSmallString

all: $(TARGETS)

testSmallVector: testSmallVector.o
	g++ -o testSmallVector testSmallVector.o

testSmallString: testSmallString.o
	g++ -o testSmallString testSmallString.o

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o
