def findMinArrowShots(points):
    if not points:
        return 0

    # 根据每个气球的结束位置进行排序
    points.sort(key=lambda x: x[1])

    arrows = 1
    end = points[0][1]

    for x_start, x_end in points:
        # 如果当前气球的开始位置大于上一个气球的结束位置
        if x_start > end:
            # 需要一支新的箭
            arrows += 1
            end = x_end

    return arrows

# 测试用例
print(findMinArrowShots([[10,16],[2,8],[1,6],[7,12]]))  # 应该输出 2
print(findMinArrowShots([[1,2],[3,4],[5,6],[7,8]]))     # 应该输出 4
print(findMinArrowShots([[1,2],[2,3],[3,4],[4,5]]))     # 应该输出 2
