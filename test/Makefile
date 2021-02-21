all:test_dynamic_array.o test_link_list.o test_seq_stack.o test_link_stack.o test_seq_queue.o test_link_queue.o test_binary_tree.o
	gcc test_link_list.o -L ../ -l kfxce_ds -o test_link_list
	gcc test_dynamic_array.o -L ../ -l kfxce_ds -o test_dynamic_array
	gcc test_seq_stack.o -L ../ -l kfxce_ds -o test_seq_stack
	gcc test_link_stack.o -L ../ -l kfxce_ds -o test_link_stack
	gcc test_seq_queue.o -L ../ -l kfxce_ds -o test_seq_queue
	gcc test_link_queue.o -L ../ -l kfxce_ds -o test_link_queue
	gcc test_binary_tree.o -L ../ -l kfxce_ds -o test_binary_tree

test_dynamic_array.o:test_dynamic_array.c
	gcc -c test_dynamic_array.c -o test_dynamic_array.o -g

test_link_list.o:test_link_list.c
	gcc -c test_link_list.c -o test_link_list.o -g

test_seq_stack.o:test_seq_stack.c
	gcc -c test_seq_stack.c -o test_seq_stack.o -g

test_link_stack.o:test_link_stack.c
	gcc -c test_link_stack.c -o test_link_stack.o -g

test_seq_queue.o: test_seq_queue.c
	gcc -c test_seq_queue.c -o test_seq_queue.o -g

test_link_queue.o:test_link_queue.c
	gcc -c test_link_queue.c -o test_link_queue.o -g

test_binary_tree.o:test_binary_tree.c
	gcc -c test_binary_tree.c -o test_binary_tree.o -g

clean:
	-rm test_dynamic_array
	-rm test_dynamic_array.o
	-rm test_link_list
	-rm test_link_list.o
	-rm test_seq_stack
	-rm test_seq_stack.o
	-rm test_link_stack.o
	-rm test_link_stack
	-rm test_seq_queue
	-rm test_seq_queue.o
	-rm test_link_queue.o
	-rm test_link_queue
	-rm test_binary_tree
	-rm test_binary_tree.o
