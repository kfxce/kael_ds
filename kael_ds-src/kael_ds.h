extern const int True; 
extern const int False; 
extern const int ERR; 

struct DynamicArray
{
        void **paddr;
        int m_capacity; 
        int m_size;
};

struct DynamicArray * init_dynamic_array(int capacity);

int insert_dynamic_array(struct DynamicArray *dynamic_array, int pos, void *data);

void print_dynamic_array(struct DynamicArray *dynamic_array, void(*callback)(void *));

int remove_by_pos_dynamic_array(struct DynamicArray *dynamic_array, int pos);

int remove_by_value_dynamic_array(struct DynamicArray *dynamic_array, void *data,
        int(*compare_callback)(void *, void*));

int destroy_dynamic_array(struct DynamicArray *dynamic_array);

void *get_by_pos_dynamic_array(struct DynamicArray *dynamic_array, int pos);

int is_empty_dynamic_array(struct DynamicArray *dynamic_array);


struct LinkNode
{
    void *data; 
    struct LinkNode *next;
};


struct LinkList
{
    struct LinkNode header; 
    int m_size;
};

struct LinkList *init_link_list();

int insert_link_list(struct LinkList *link_list, int pos, void *data);

void print_link_list(struct LinkList *link_list, void(*callbaack)(void *));

int remove_by_pos_link_list(struct LinkList *link_list, int pos);

int remove_by_value_link_list(struct LinkList *link_list, void *data, int(*compare_callback)(void *, void *));

int clear_link_list(struct LinkList *link_list);

int len_link_list(struct LinkList *link_list);

int destroy_link_list(struct LinkList *link_list);

int is_empty_link_list(struct LinkList *link_list);

void *get_by_pos_link_list(struct LinkList *link_list, int pos);


#define STACK_MAX 1024

struct SeqStack
{
    void *data[STACK_MAX];
    int m_size;
};

struct SeqStack *init_seq_stack();

int push_seq_stack(struct SeqStack *stack, void *data);

void *pop_seq_stack(struct SeqStack *stack);

void *top_seq_stack(struct SeqStack *stack);

int size_seq_stack(struct SeqStack *stack);

int is_empty_seq_stack(struct SeqStack *stack);

int destroy_seq_stack(struct SeqStack *stack);


struct LinkStackNode {
    struct LinkStackNode *next;
    void *data; 
};

struct LinkStack
{
    struct LinkStackNode header;
    int m_size;
};


struct LinkStack *init_link_stack();

int push_link_stack(struct LinkStack *link_stack, void *data);

void *pop_link_stack(struct LinkStack *link_stack);

void *top_link_stack(struct LinkStack *link_stack);

int is_empty_link_stack(struct LinkStack *link_stack);

int size_link_stack(struct LinkStack *link_stack);

int destroy_link_stack(struct LinkStack *link_stack);


#define SEQ_QUEUE_MAX 1024

struct SeqQueue {
    struct DynamicArray *dynamic_array;
};

struct SeqQueue *init_seq_queue(int capacity);

int en_seq_queue(struct SeqQueue *seq_queue, void *data);

void *de_seq_queue(struct SeqQueue *seq_queue);

int size_seq_queue(struct SeqQueue *seq_queue);

int destroy_seq_queue(struct SeqQueue *seq_queue);

int is_empty_seq_queue(struct SeqQueue *seq_queue);


struct LinkQueue {
    struct LinkList *link_list;
};

struct LinkQueue *init_link_queue();

int en_link_queue(struct LinkQueue *link_queue, void *data);

void *de_link_queue(struct LinkQueue *link_queue);

int size_link_queue(struct LinkQueue *link_queue);

int destroy_link_queue(struct LinkQueue *link_queue);

int is_empty_link_queue(struct LinkQueue *link_queue);
