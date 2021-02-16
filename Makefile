target = libkael_ds.a
CC = gcc
AR = ar
# 获取当前目录下所有的.c文件
src = $(wildcard ./kael_ds-src/*.c)

# patsubst 是一个匹配替换函数
# 从src文件列表中获取.c文件,然后.c替换为.o
obj = $(patsubst ./%.c, ./%.o, $(src))

$(target):$(obj)
	$(AR) rcs $(target) $(obj)

%.o:%.c
	$(CC) -c $< -o $@

# 声明clean为伪目标
.PHONY:clean
clean:
	rm $(obj) $(target) -f
