def lemonadeChange(bills):
    five, ten = 0, 0
    for bill in bills:
        if bill == 5:
            five += 1
        elif bill == 10:
            if five == 0:
                return False
            five -= 1
            ten += 1
        else:
            if ten > 0 and five > 0:
                ten -= 1
                five -= 1
            elif five >= 3:
                five -= 3
            else:
                return False
    return True

# 测试用例
print(lemonadeChange([5, 5, 5, 10, 20]))  # True
print(lemonadeChange([5, 5, 10]))         # True
print(lemonadeChange([10, 10]))           # False
