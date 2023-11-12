def reconstructQueue(people):
    # 按身高降序排列，身高相同则按前面人数升序排列
    people.sort(key=lambda x: (-x[0], x[1]))

    output = []
    for p in people:
        # 插入到指定位置
        output.insert(p[1], p)

    return output

# 测试用例
print(reconstructQueue([[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]))
# 应该输出 [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
