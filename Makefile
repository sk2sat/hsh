TARGET	= hsh
OBJS	= main.o

%.o:%.c
	gcc -c $<

$(TARGET):$(OBJS)
	gcc -o $@ $^

run:
	make
	./$(TARGET)
