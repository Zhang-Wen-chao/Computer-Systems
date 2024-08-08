import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F

# 定义一个最简单的卷积神经网络
class SimpleCNN(nn.Module):
    def __init__(self):
        super(SimpleCNN, self).__init__()
        # 卷积层，输入通道数为1，输出通道数为6，卷积核大小为3x3
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=6, kernel_size=3)
        # 全连接层
        self.fc1 = nn.Linear(in_features=6*3*3, out_features=10)  # 计算出的特征大小

    def forward(self, x):
        # 应用卷积层和激活函数，然后进行2x2池化
        x = F.relu(self.conv1(x))
        x = F.max_pool2d(x, 2)
        # 将多维张量展平成一维张量
        x = x.view(-1, 6*3*3)
        # 应用全连接层
        x = self.fc1(x)
        return x

# 创建网络
model = SimpleCNN()

# 定义损失函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = optim.SGD(model.parameters(), lr=0.01)

# 生成一些随机数据
inputs = torch.randn(10, 1, 8, 8)  # 假设输入图像大小为8x8，单通道
targets = torch.randint(0, 10, (10,))  # 假设有10个类别

# 训练模型
num_epochs = 100
for epoch in range(num_epochs):
    # 前向传播
    outputs = model(inputs)
    loss = criterion(outputs, targets)
    
    # 反向传播和优化
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    
    if (epoch+1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')

print("Training finished.")
