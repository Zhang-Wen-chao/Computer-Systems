# 多多有很多作业，同一时刻他只能做一份作业。
# 一个学期内多多共有（n）份作业，第（i) 份作业会在第（t_i) 时刻布置下来，需要（w_i）时间才能完成，
# 多多可以在任意时刻改变自己当前的作业（前提是改变后的作业必须已有布置且未完成），
# 第(i）份作业的完成耗时为最终完成时刻減去作业被布置的时刻（t_i)（详细样例）。
# 请问多多应如何分配自己的作业时间，才能使得所有作业的完成耗时总和最短？

# 输入描述
# 第一行为一个整数（n）（1 <= n <= 10^5），表示有（n）份作业。
# 接下去（n）行，每行两个整数（ti,w_i） （（1 <= t_i, w_i <= 10^9）），分别表示作业的布置时刻与完成时间。
# 输出描述
# 输出一个整数，表示所有作业的最短完成耗时。

# 补充说明
# 对于50% 的数据，（1≤ n ≤ 1000），（1 ≤ ti, wi ≤ 10^5）；
# 对于 100% 的数据，（1≤ n ≤ 10^5），（1 ≤ ti,Wi ≤ 10^9）。
# 数据保证对于任意的（i \in [1,n-1]），有（t_i <= t_{i+1}）。

# input 1:
# 3
# 1 5
# 5 1
# 7 3
# output 1: 10
# • 在时刻1到时刻6之间做作业1，作业1开始时刻为1，完成时刻为6，耗时为6-1=5。
# • 时刻6到时刻7做作业2，作业2开始时刻为5，完成时刻为7，耗时为 7-5=2。
# • 时刻7到时刻 10做作业3，作业3开始时刻为7，完成时刻为10，耗时为3。
# 总耗时为5+2+3=10。

# input 2:
# 5
# 1 1
# 4 2
# 9 3
# 16 4
# 25 5
# output 2: 15

import heapq
from collections import deque 
from math import inf

# 输入作业数量
n = int(input())
tasks = []

# 输入每个作业的开始时间和所需完成时间
for _ in range(n):
    tasks.append(list(map(int, input().split())))

# 根据作业的布置时刻和完成时间排序
tasks.sort(key=lambda x:(x[0], x[1]))
tasks.append([inf, inf])

# 使用双端队列存储排序后的任务
task_queue = deque(tasks)
# 优先队列，用于存储当前正在进行的作业，按剩余时间最短排序
current_tasks = []

total_time_spent, current_time = 0, 0

# 开始处理任务
while task_queue:
    start_time, remaining_time = task_queue.popleft()
    
    # 如果有当前正在进行的作业，并且当前时间小于下一个任务的开始时间
    while current_tasks and current_time < start_time:
        task_duration, task_start = heapq.heappop(current_tasks)
        
        # 如果当前作业能在下一个任务开始前完成
        if current_time + task_duration <= start_time:
            total_time_spent += current_time + task_duration - task_start
            current_time = current_time + task_duration
        else:
            # 如果当前作业不能完成，则更新作业的剩余时间，并返回到优先队列
            total_time_spent += start_time - task_start
            heapq.heappush(current_tasks, (task_duration - (start_time - current_time), start_time))
            current_time = start_time
    
    # 更新当前时间为下一个任务的开始时间
    current_time = start_time
    # 将当前任务添加到优先队列
    heapq.heappush(current_tasks, (remaining_time, start_time))

# 输出所有作业的最短完成耗时
print(total_time_spent)
