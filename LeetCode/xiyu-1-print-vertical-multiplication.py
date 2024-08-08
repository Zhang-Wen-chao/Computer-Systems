def format_print(a, b):
    a_str = str(a)
    b_str = str(b)
    
    # 确定结果的长度以便对齐
    result_length = len(str(a * b))
    
    # 打印顶部的两个数字并对齐
    print(f"{a_str:>{result_length}}")
    print(f"{b_str:>{result_length}}")
    print("-" * result_length)
    
    # 打印每一步的中间结果
    intermediate_results = []
    for i, digit in enumerate(reversed(b_str)):
        intermediate_result = a * int(digit) * (10 ** i)
        intermediate_results.append(intermediate_result)
        print(f"{(a * int(digit)):>{result_length - i}}")
    
    print("-" * result_length)
    
    # 打印最终结果
    final_result = a * b
    print(f"{final_result:>{result_length}}")

# 示例
format_print(12345, 678)
