import numpy as np
from sklearn.svm import SVC

def svm_lagrange_multipliers(data):
    # 提取特征和标签
    X = np.array([[item[0], item[1]] for item in data])
    y = np.array([item[2] for item in data])
    
    # 创建并训练硬间隔SVM (线性核, C非常大)
    model = SVC(kernel='linear', C=1e10)
    model.fit(X, y)
    
    # 获取支持向量对应的拉格朗日乘数
    alphas = np.zeros(len(y))
    alphas[model.support_] = model.dual_coef_[0]
    
    # 保留两位小数并转换为字符串
    alphas = [f'{alpha:.2f}' if alpha >= 0 else '0.00' for alpha in alphas]
    
    return alphas

# 示例输入
data = [
    [1.0, 2.0, 1],
    [2.0, 3.0, -1]
]

# 计算拉格朗日乘数
result = svm_lagrange_multipliers(data)
print(result)
