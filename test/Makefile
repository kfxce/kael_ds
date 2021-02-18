all:test_dynamic_array.o test_link_list.o test_seq_stack.o
	gcc test_link_list.o -L ../ -l kael_ds -o test_link_list
	gcc test_dynamic_array.o -L ../ -l kael_ds -o test_dynamic_array
	gcc test_seq_stack.o -L ../ -l kael_ds -o test_seq_stack

test_dynamic_array.o:test_dynamic_array.c
	gcc -c test_dynamic_array.c -o test_dynamic_array.o -g

test_link_list.o:test_link_list.c
	gcc -c test_link_list.c -o test_link_list.o -g

test_stack.o:test_seq_stack.c
	gcc -c test_seq_stack.c -o test_stack.o -g

clean:
	-rm test_dynamic_array
	-rm test_dynamic_array.o
	-rm test_link_list
	-rm test_link_list.o
	-rm test_seq_stack
	-rm test_seq_stack.o
