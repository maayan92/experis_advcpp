CC := $(CXX)
CXX := g++

CPPFLAGS := -I. -I../../inc/advcpp -I../../inc/ -I../inc/
CFLAGS += -Werror -Wall -Wextra
CFLAGS += -g

CXXFLAGS = $(CFLAGS) -std=c++03

LDLIBS := -lpthread

TARGET := shared_ptrTest 

OBJS := shared_ptrTest.o ../../src/mutex.o

$(TARGET): $(OBJS)

all: $(TARGET)

check: $(TARGET) 	
	@clear
	./$(TARGET)
	
recheck: clean all
	@clear
	./$(TARGET)
	
#valgrind: valgrind --tool=helgrind --log-file=sharedPtrValgrind.txt ./shared_ptrTest

clean: 
	@$(RM) -f $(TARGET) $(OBJS)

.PHONY: all clean check recheck