.PHONY : clean

CC:= g++
CPPFLAGS= -fPIC -Wall -g -Iinc/
#CPPFLAGS=-I./inc

LDFLAGS= -shared
TARGET=app

SRCDIR := src
INCDIR := inc
SOURCES = $(shell echo $(SRCDIR)/*.cpp)
HEADERS = $(shell echo $(INCDIR)/*.h)
OBJECTS=$(SOURCES:$(SRCDIR)/.cpp=$(SRCDIR)/.o)


INSTALL_LIBDIR=../build/lib
INSTALL_INCDIR=../build/include

LIB_TARGET=$(INSTALL_LIBDIR)/liblink_data.so

all: $(LIB_TARGET)

clean:
	rm -f $(LIB_TARGET)
	rm -f $(OBJS) $(TARGET)

%.o:%.cpp
	$(CC) -c $< $(CPPFLAGS) -o $@

$(LIB_TARGET) : $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	cp $(INCDIR)/*.h $(INSTALL_INCDIR)

#g++ -fPIC -Wall -g -Iinc/ src/main.cpp src/test.cpp -o ../build/lib/liblink_data.so -shared