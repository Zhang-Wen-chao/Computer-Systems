import numpy as np

# 定义卷积层
class Conv2D:
    def __init__(self, in_channels, out_channels, kernel_size):
        self.in_channels = in_channels
        self.out_channels = out_channels
        self.kernel_size = kernel_size
        self.weights = np.random.randn(out_channels, in_channels, kernel_size, kernel_size) * 0.1
        self.bias = np.zeros(out_channels)
        
    def forward(self, x):
        self.x = x
        batch_size, in_channels, height, width = x.shape
        out_height = height - self.kernel_size + 1
        out_width = width - self.kernel_size + 1
        out = np.zeros((batch_size, self.out_channels, out_height, out_width))
        
        for i in range(out_height):
            for j in range(out_width):
                region = x[:, :, i:i+self.kernel_size, j:j+self.kernel_size]
                out[:, :, i, j] = np.tensordot(region, self.weights, axes=([1,2,3], [1,2,3])) + self.bias
                
        return out
    
    def backward(self, d_out, learning_rate):
        batch_size, in_channels, height, width = self.x.shape
        _, out_channels, out_height, out_width = d_out.shape
        d_x = np.zeros_like(self.x)
        d_weights = np.zeros_like(self.weights)
        d_bias = np.zeros_like(self.bias)
        
        for i in range(out_height):
            for j in range(out_width):
                region = self.x[:, :, i:i+self.kernel_size, j:j+self.kernel_size]
                for n in range(batch_size):
                    for f in range(self.out_channels):
                        d_weights[f] += d_out[n, f, i, j] * region[n]
                        d_bias[f] += d_out[n, f, i, j]
                        d_x[n, :, i:i+self.kernel_size, j:j+self.kernel_size] += d_out[n, f, i, j] * self.weights[f]
                        
        self.weights -= learning_rate * d_weights / batch_size
        self.bias -= learning_rate * d_bias / batch_size
        
        return d_x

# 定义最大池化层
class MaxPool2D:
    def __init__(self, size):
        self.size = size
        
    def forward(self, x):
        self.x = x
        batch_size, in_channels, height, width = x.shape
        out_height = height // self.size
        out_width = width // self.size
        out = np.zeros((batch_size, in_channels, out_height, out_width))
        
        for i in range(out_height):
            for j in range(out_width):
                region = x[:, :, i*self.size:(i+1)*self.size, j*self.size:(j+1)*self.size]
                out[:, :, i, j] = np.max(region, axis=(2, 3))
                
        return out
    
    def backward(self, d_out):
        batch_size, in_channels, out_height, out_width = d_out.shape
        d_x = np.zeros_like(self.x)
        
        for i in range(out_height):
            for j in range(out_width):
                region = self.x[:, :, i*self.size:(i+1)*self.size, j*self.size:(j+1)*self.size]
                max_region = np.max(region, axis=(2, 3), keepdims=True)
                mask = (region == max_region)
                d_x[:, :, i*self.size:(i+1)*self.size, j*self.size:(j+1)*self.size] += d_out[:, :, i, j][:, :, None, None] * mask
                
        return d_x

# 定义全连接层
class FullyConnected:
    def __init__(self, input_dim, output_dim):
        self.weights = np.random.randn(input_dim, output_dim) * 0.1
        self.bias = np.zeros(output_dim)
        
    def forward(self, x):
        self.x = x
        return np.dot(x, self.weights) + self.bias
    
    def backward(self, d_out, learning_rate):
        d_x = np.dot(d_out, self.weights.T)
        d_weights = np.dot(self.x.T, d_out)
        d_bias = np.sum(d_out, axis=0)
        
        self.weights -= learning_rate * d_weights / self.x.shape[0]
        self.bias -= learning_rate * d_bias / self.x.shape[0]
        
        return d_x

# 定义ReLU激活函数
class ReLU:
    def forward(self, x):
        self.x = x
        return np.maximum(0, x)
    
    def backward(self, d_out):
        d_x = d_out.copy()
        d_x[self.x <= 0] = 0
        return d_x

# 定义交叉熵损失函数
def cross_entropy_loss(predictions, targets):
    m = targets.shape[0]
    p = softmax(predictions)
    log_likelihood = -np.log(p[range(m), targets])
    loss = np.sum(log_likelihood) / m
    return loss

def softmax(x):
    exp_x = np.exp(x - np.max(x, axis=1, keepdims=True))
    return exp_x / np.sum(exp_x, axis=1, keepdims=True)

def cross_entropy_loss_backward(predictions, targets):
    m = targets.shape[0]
    grad = softmax(predictions)
    grad[range(m), targets] -= 1
    grad = grad / m
    return grad

# 定义简单卷积神经网络
class SimpleCNN:
    def __init__(self):
        self.conv1 = Conv2D(in_channels=1, out_channels=6, kernel_size=3)
        self.relu1 = ReLU()
        self.pool1 = MaxPool2D(size=2)
        self.fc1 = FullyConnected(input_dim=6*3*3, output_dim=10)
        
    def forward(self, x):
        x = self.conv1.forward(x)
        x = self.relu1.forward(x)
        x = self.pool1.forward(x)
        x = x.reshape(x.shape[0], -1)  # 展平
        x = self.fc1.forward(x)
        return x
    
    def backward(self, d_out, learning_rate):
        d_out = self.fc1.backward(d_out, learning_rate)
        d_out = d_out.reshape(d_out.shape[0], 6, 3, 3)
        d_out = self.pool1.backward(d_out)
        d_out = self.relu1.backward(d_out)
        d_out = self.conv1.backward(d_out, learning_rate)
        return d_out

# 创建网络
model = SimpleCNN()

# 生成一些随机数据
inputs = np.random.randn(10, 1, 8, 8)  # 假设输入图像大小为8x8，单通道
targets = np.random.randint(0, 10, 10)  # 假设有10个类别

# 训练模型
num_epochs = 100
learning_rate = 0.01

for epoch in range(num_epochs):
    # 前向传播
    outputs = model.forward(inputs)
    loss = cross_entropy_loss(outputs, targets)
    
    # 反向传播和优化
    d_out = cross_entropy_loss_backward(outputs, targets)
    model.backward(d_out, learning_rate)
    
    if (epoch+1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss:.4f}')

print("Training finished.")
