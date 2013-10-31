CC=gcc
OBJS=main.o eprintf.o tree.o
TARGET=tree

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	
clean:
	rm -f $(OBJS) $(TARGET)