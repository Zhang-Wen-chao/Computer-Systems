#include <linux/slab.h>

void *ptr = kmalloc(size, GFP_KERNEL);
if (ptr == NULL) {
    // 内存分配失败的处理
    return -ENOMEM;
}

// 使用分配的内存块做一些操作

kfree(ptr); // 释放内存块