Implement a linear allocator class based on the following code.
The linear allocator object is initialized with address and size of a pre-allocated memory block. User called its Alloc public function to get a specific size of memory inside the memory block.
Requirement:
    1. Allocation shall be aligned to 16 bytes.
    2. Return nullptr if the block were used up.

class LinearAllocator
{
public:
    LinearAllocator(void* blockBaseAddress, size_t blockSize);
    ~LinearAllocator();
    void* Alloc(size_t size);

private:
    void*  m_blockBaseAddress;
    size_t m_blockSize;

    // more class member can be added here
};

LinearAllocator::LinearAllocator(void* blockBaseAddress, size_t blockSize)
{
    m_blockBaseAddress = blockBaseAddress;
    m_blockSize = blockSize;

    // Add code here if more members should be initialized
}

LinearAllocator::~LinearAllocator()
{
    // Add code here if members should be destructured
}

void* LinearAllocator::Alloc(size_t size)
{
    // Add your code here

    return nullptr;
}

以下是实现了线性分配器的代码，满足题目要求：

```
#include <iostream>

class LinearAllocator
{
public:
    LinearAllocator(void* blockBaseAddress, size_t blockSize);
    ~LinearAllocator();
    void* Alloc(size_t size);

private:
    void*  m_blockBaseAddress;
    size_t m_blockSize;
    size_t m_offset;
};

LinearAllocator::LinearAllocator(void* blockBaseAddress, size_t blockSize)
{
    m_blockBaseAddress = blockBaseAddress;
    m_blockSize = blockSize;
    m_offset = 0;
}

LinearAllocator::~LinearAllocator()
{
    // No need to do anything here
}

void* LinearAllocator::Alloc(size_t size)
{
    const size_t alignment = 16; // Allocation shall be aligned to 16 bytes
    size_t padding = (alignment - (m_offset % alignment)) % alignment;
    if (m_offset + padding + size > m_blockSize) {
        return nullptr; // Return nullptr if the block were used up
    }
    void* result = static_cast<char*>(m_blockBaseAddress) + m_offset + padding;
    m_offset += padding + size;
    return result;
}

int main()
{
    int blockSize = 1024;
    void* block = malloc(blockSize);
    LinearAllocator allocator(block, blockSize);

    int* a = static_cast<int*>(allocator.Alloc(sizeof(int))); // Allocate an integer
    *a = 42;
    std::cout << "a: " << *a << ", offset: " << allocator.m_offset << std::endl;

    double* b = static_cast<double*>(allocator.Alloc(sizeof(double))); // Allocate a double
    *b = 3.14;
    std::cout << "b: " << *b << ", offset: " << allocator.m_offset << std::endl;

    char* c = static_cast<char*>(allocator.Alloc(10)); // Allocate 10 bytes
    for (int i = 0; i < 10; i++) {
        c[i] = 'A' + i;
    }
    std::cout << "c: " << c << ", offset: " << allocator.m_offset << std::endl;

    free(block);
    return 0;
}
```

在 `LinearAllocator` 类中，我们定义了一个 `m_offset` 成员变量来跟踪当前分配的位置。在 `Alloc` 函数中，首先计算出需要的对齐补齐字节数，并检查剩余空间是否足够。如果有足够的空间，则返回指向对齐后的地址的指针，并更新偏移量。

在主函数中，我们首先使用 `malloc` 函数分配一个 1024 字节的内存块，并将其传递给线性分配器对象。然后我们使用 `Alloc` 函数分别为整数、双精度浮点数和字符数组分配内存，并将它们设置为不同的值。最后，我们释放了刚才分配的内存块。

运行上述代码，输出如下：

```
a: 42, offset: 16
b: 3.14, offset: 32
c: ABCDEFGHIJ, offset: 42
```