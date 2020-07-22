.PHONY : clean

CC:= g++
CPPFLAGS= -Wall -g -Iinc/ -I../build/include/ -L../build/lib/
#CPPFLAGS=-I./inc

TARGET=../build/app

SRCDIR := src
INCDIR := inc
SOURCES = $(shell echo $(SRCDIR)/*.cpp)
HEADERS = $(shell echo $(INCDIR)/*.h)
OBJECTS=$(SOURCES:$(SRCDIR)/.cpp=$(SRCDIR)/.o)


# INSTALL_LIBDIR=../build/lib
# INSTALL_INCDIR=../build/include

all: $(TARGET)

clean:
	rm -f $(LIB_TARGET)
	rm -f $(OBJS) $(TARGET)


$(TARGET):$(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -llink_data -o $@

%.o:%.cpp
	$(CC) -c $< $(CPPFLAGS) -o $@


#g++ -fPIC -Wall -g -Iinc/ src/main.cpp src/test.cpp -o ../build/lib/liblink_data.so -shared