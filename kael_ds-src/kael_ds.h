// 成功
#define True 1
// 失败
#define False 0


/*
 * =============================
 * =         动态数组          =
 * =============================
 */

// 动态数组结构体
struct DynamicArray
{
        void **paddr; // 维护在堆区的真实数组指针
        int m_capacity; // 数组容量
        int m_size; // 数组大小
};

/* 初始化动态数组
 *
 * param int capacity: 数组的容量
 *
 * return struct DynamicArray *: 动态数组结构体指针
 *
 * 注意：如果返回为NULL则表示初始化失败
 */

struct DynamicArray * init_dynamic_array(int capacity);

/* 插入功能
 *
 * param struct DynamicArray *dynamic_array: 被插入新元素的动态数组指针
 * param int pos: 被插入动态数组的位置
 * param void *data: 被插入动态数组的新元素
 *
 * return int: True：成功，False：失败
 */
int insert_dynamic_array(struct DynamicArray *dynamic_array, int pos, void *data);

/* 遍历动态数组
 */
void print_dynamic_array(struct DynamicArray *dynamic_array, void(*callback)(void *));
