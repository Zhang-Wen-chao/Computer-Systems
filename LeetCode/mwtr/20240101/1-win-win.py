# 小美正在参加比赛，一共有 n 场比赛，赢得一场可以获得 1 分，如果上一场也赢了，可以获得额外的 1 分。
# 现在给你 n 场 比赛的结果，你需要计算小美的分数。 
# 输入：
# 4 
# 1 1 0 1 
# 输出：
# 4
def calculate_score(results):
    score = 0
    consecutive_win = False

    for result in results:
        if result == 1:
            score += 1
            if consecutive_win:
                score += 1
            consecutive_win = True
        else:
            consecutive_win = False

    return score

def main():
    n = int(input("输入比赛场数: "))
    results = list(map(int, input("输入比赛结果: ").split()))

    if len(results) != n:
        print("输入的比赛结果数量与比赛场数不符。")
        return

    score = calculate_score(results)
    print("小美的得分是:", score)

if __name__ == "__main__":
    main()
