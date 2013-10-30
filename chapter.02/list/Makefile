CC=gcc
OBJS=main.o eprintf.o list.o
TARGET=list

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	
clean:
	rm -f $(OBJS) $(TARGET)