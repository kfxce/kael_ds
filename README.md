# kael_ds

这个几个月一直在学Linux C，已经快要学完了，我以前是用Python的，里面内置了很多数据结构，而C语言内置是没有的，所以，就只能自己写一个，正好，数据结构的知识一直没学好，而且C语言也不熟，正好就来给自己写一个数据结构的库给自己用，写这个库对我自己有以下7个好处：
1. 熟悉下c的代码编写，
2. 学会C工程的开发，
3. 给自己准备一个c数据结构的库
4. 以后不用再编写这些代码
5. 学习下c语言单元测试的写法
6. 学习下c工程makefile的写法
7. 巩固数据结构的知识

然后我将这个库的名字命名为：kael_ds。kael，为我的网名，ds为数据结构的缩写。

编写这个项目说明，希望这是一个很好的开始。

项目文件结构：

```
kael_ds/
├── kael_ds-src
│   ├── dynamic_array.c
│   └── kael_ds.h
├── Makefile
├── README.md
└── test
```
我特地去看了下skynet项目头文件是放在了skyent-src目录下，和.c源码是放一起的，那么我也准备这样做。


生成静态库:
```
$ cd kael_ds
$ make
```

## 0x1. 线性表

关于线性表的实现有这么几种:
1. 动态数组
    * [x] 初始化
    * [x] 插入元素
    * [x] 根据元素位置删除元素
    * [x] 根据元素值删除元素
    * [x] 打印
    * [x] 销毁
2. 单向链表
    * [x] 初始化
    * [x] 插入元素
    * [x] 根据元素位置删除元素
    * [x] 打印
    * [x] 根据元素值删除元素
    * [x] 清空链表
    * [x] 返回链表长度
    * [x] 销毁链表

测试动态数组:
```
$ cd kael_ds
$ cd test
$ make test_dynamic_array
$ ./test_dynamic_array
当前的容量为: 5
当前的容量为: 5
当前的容量为: 5
当前的容量为: 5
当前的容量为: 5
当前的容量为: 5
当前的容量为: 10
姓名: 亚索6, 年龄：18
姓名: 亚索5, 年龄：18
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除第0个位置的元素
姓名: 亚索5, 年龄：18
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除第0个位置的元素
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除元素p1
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
销毁数组
Segmentation fault (core dumped)
$ make clean
```
上面有一个疑问，销毁数组之后，调用print_dynamic_array会导致段错误。我看了代码之后感觉没问题。


测试单向链表
```
$ cd test
$ make
$ ./test_link_list
当前的大小为: 0
当前的大小为: 1
当前的大小为: 2
当前的大小为: 3
当前的大小为: 4
当前的大小为: 5
当前的大小为: 6
姓名: 亚索6, 年龄：18
姓名: 亚索5, 年龄：18
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除第0个位置的元素
姓名: 亚索5, 年龄：18
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除第0个位置的元素
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
姓名: 亚索2, 年龄：18
姓名: 亚索1, 年龄：18
删除元素p1, p2
姓名: 亚索4, 年龄：18
姓名: 亚索3, 年龄：18
清空链表
链表长度: 0
销毁链表
$ make clean
```
