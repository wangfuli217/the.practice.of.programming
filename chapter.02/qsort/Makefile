CC=gcc
OBJS=main.o qsort.o
TARGET=qsort

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	
clean:
	rm -f $(OBJS) $(TARGET)