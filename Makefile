CFLAGS=-Wall -Wextra -std=gnu99 -ggdb

deq-test: deq-func.o deq-test.o wrappers.o 

deq-impl.o: wrappers.h deq.h  