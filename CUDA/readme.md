# 谭升
https://face2ai.com/program-blog/#GPU%E7%BC%96%E7%A8%8B%EF%BC%88CUDA%EF%BC%89

这个人也太牛掰了！在没有chatgpt的时代，如此深入分析了CUDA代码。
## cuda版本很重要
```bash
nvcc hello.cu -o hello
./hello
```

nvidia-smi 显示的cuda版本是支持的最高版本，编译cuda代码时候，cuda版本选择驱动支持的最高版本没有问题，选择更高版本不行，选择更低版本我没尝试过。

## 31
```bash
nvcc stream_omp.cu -o stream_omp -Xcompiler -fopenmp
```
# sangyc10
这个博主的代码也都看完了，讲并行蛮深入的。

https://github.com/sangyc10/CUDA-code.git