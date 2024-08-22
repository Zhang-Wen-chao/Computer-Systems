# 一家银行系统通过机器学习技术优化其信用卡申请者的信用评分模型。
# 目前，银行使用的是一个逻辑回归模型，但为了提高预测准确性，银行希望尝试使用支持向量机（SVM)的模型。
# 在构建svm模型前，需要对特征进行选择，以圈定哪些特征对信用评分最重要。
# 请写Python程序，实现一个基于决策树的特征选择方法，以确定最重要的特征。

# 输入
# [[50000, 1, 'Yes', 'Good'], [50000,2,'No','Bad'],[70000,3,'Yes','Good'],[40000,4,'No','Bad']]
# 输出
# 2

# 输入数据为一个二维列表，其中每一行代表一个信用卡申请者的记录，每一列代表一个特征。
# 其中最后一列是目标变量，其中’Good'表示信用良好，‘Bad'表示信用不佳，倒数第二行也是字符串特征，其余特征值可以是整数或者浮点数。
# 补充说明：使用决策树的方法计算， 固定随机种子42，可以用numpy，pandas，scikit-learn库。保证输出唯一。

import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.preprocessing import LabelEncoder

# 原始输入数据
data = [
    [50000, 1, 'Yes', 'Good'],
    [50000, 2, 'No', 'Bad'],
    [70000, 3, 'Yes', 'Good'],
    [40000, 4, 'No', 'Bad']
]

# 转换为DataFrame
df = pd.DataFrame(data, columns=['收入', '负债比率', '是否已婚', '信用评分'])

# 编码分类变量
label_encoders = {}
for column in ['是否已婚', '信用评分']:
    le = LabelEncoder()
    df[column] = le.fit_transform(df[column])
    label_encoders[column] = le

# 特征和标签
X = df.drop('信用评分', axis=1)
y = df['信用评分']

# 创建并训练决策树模型
clf = DecisionTreeClassifier(random_state=42)
clf.fit(X, y)

# 获取特征重要性
feature_importances = clf.feature_importances_

# 找到最重要的特征
most_important_feature_index = feature_importances.argmax()

# 输出最重要的特征的序号（从1开始计数）
print(most_important_feature_index)
