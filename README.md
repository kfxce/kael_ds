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
│   ├── dynamic_array.c
│   ├── global.c
│   ├── kael_ds.h
│   ├── link_list.c
│   ├── link_queue.c
│   ├── link_stack.c
│   ├── seq_queue.c
│   └── seq_stack.c
├── Makefile
├── README.md
└── test
    ├── Makefile
    ├── test_dynamic_array.c
    ├── test_link_list.c
    ├── test_link_queue.c
    ├── test_link_stack.c
    ├── test_seq_queue.c
    └── test_seq_stack.c
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
2. 单向链表

## 0x2. 栈

有这么几种实现：
1. 顺序栈
2. 链式栈


## 0x3. 队列

有这么两种：
1. 顺序队列
2. 链式队列
