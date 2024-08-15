import random
import math

# 定义矩阵相乘
def matmul(a, b):
    result = [[0] * len(b[0]) for _ in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                result[i][j] += a[i][k] * b[k][j]
    return result

# 定义矩阵加法
def matadd(a, b):
    result = [[a[i][j] + b[i][j] for j in range(len(a[0]))] for i in range(len(a))]
    return result

# 定义矩阵元素级别的乘法
def matmul_elementwise(a, b):
    result = [[a[i][j] * b[i][j] for j in range(len(a[0]))] for i in range(len(a))]
    return result

# 定义矩阵按元素取最大值
def matmax(a, b):
    result = [[max(a[i][j], b[i][j]) for j in range(len(a[0]))] for i in range(len(a))]
    return result

# 定义卷积操作
def conv2d(x, weights, bias):
    batch_size, in_channels, height, width = len(x), len(x[0]), len(x[0][0]), len(x[0][0][0])
    out_channels, _, kernel_size, _ = len(weights), len(weights[0]), len(weights[0][0]), len(weights[0][0][0])
    out_height = height - kernel_size + 1
    out_width = width - kernel_size + 1
    out = [[[[0] * out_width for _ in range(out_height)] for _ in range(out_channels)] for _ in range(batch_size)]
    
    for n in range(batch_size):
        for f in range(out_channels):
            for i in range(out_height):
                for j in range(out_width):
                    for k in range(in_channels):
                        for p in range(kernel_size):
                            for q in range(kernel_size):
                                out[n][f][i][j] += x[n][k][i+p][j+q] * weights[f][k][p][q]
                    out[n][f][i][j] += bias[f]
                    
    return out

# 定义卷积操作的反向传播
def conv2d_backward(d_out, x, weights):
    batch_size, in_channels, height, width = len(x), len(x[0]), len(x[0][0]), len(x[0][0][0])
    out_channels, _, kernel_size, _ = len(weights), len(weights[0]), len(weights[0][0]), len(weights[0][0][0])
    out_height = height - kernel_size + 1
    out_width = width - kernel_size + 1
    
    d_x = [[[[0] * width for _ in range(height)] for _ in range(in_channels)] for _ in range(batch_size)]
    d_weights = [[[[0] * kernel_size for _ in range(kernel_size)] for _ in range(in_channels)] for _ in range(out_channels)]
    d_bias = [0] * out_channels
    
    for n in range(batch_size):
        for f in range(out_channels):
            for i in range(out_height):
                for j in range(out_width):
                    for k in range(in_channels):
                        for p in range(kernel_size):
                            for q in range(kernel_size):
                                d_weights[f][k][p][q] += x[n][k][i+p][j+q] * d_out[n][f][i][j]
                                d_x[n][k][i+p][j+q] += weights[f][k][p][q] * d_out[n][f][i][j]
                    d_bias[f] += d_out[n][f][i][j]
                    
    return d_x, d_weights, d_bias

# 定义最大池化操作
def max_pool2d(x, size):
    batch_size, in_channels, height, width = len(x), len(x[0]), len(x[0][0]), len(x[0][0][0])
    out_height = height // size
    out_width = width // size
    out = [[[[0] * out_width for _ in range(out_height)] for _ in range(in_channels)] for _ in range(batch_size)]
    
    for n in range(batch_size):
        for k in range(in_channels):
            for i in range(out_height):
                for j in range(out_width):
                    max_val = -float('inf')
                    for p in range(size):
                        for q in range(size):
                            max_val = max(max_val, x[n][k][i*size + p][j*size + q])
                    out[n][k][i][j] = max_val
                    
    return out


# 定义最大池化操作的反向传播
def max_pool2d_backward(d_out, x, size):
    batch_size, in_channels, height, width = len(x), len(x[0]), len(x[0][0]), len(x[0][0][0])
    out_height = height // size
    out_width = width // size
    
    d_x = [[[[0] * width for _ in range(height)] for _ in range(in_channels)] for _ in range(batch_size)]
    
    for n in range(batch_size):
        for k in range(in_channels):
            for i in range(out_height):
                for j in range(out_width):
                    max_val = -float('inf')
                    max_i, max_j = -1, -1
                    for p in range(size):
                        for q in range(size):
                            if x[n][k][i*size + p][j*size + q] > max_val:
                                max_val = x[n][k][i*size + p][j*size + q]
                                max_i, max_j = i*size + p, j*size + q
                    d_x[n][k][max_i][max_j] += d_out[n][k][i][j]
                    
    return d_x


# 定义全连接层
def fully_connected(x, weights, bias):
    output = [0] * len(weights[0])
    for i in range(len(weights)):
        for j in range(len(weights[0])):
            output[j] += x[i] * weights[i][j]
    for j in range(len(bias)):
        output[j] += bias[j]
    return output

# 定义全连接层的反向传播
def fully_connected_backward(d_out, x, weights):
    d_x = [0] * len(weights)
    d_weights = [[0] * len(weights[0]) for _ in range(len(weights))]
    d_bias = [0] * len(weights[0])
    
    for i in range(len(weights)):
        for j in range(len(weights[0])):
            d_weights[i][j] += x[i] * d_out[j]
            d_x[i] += weights[i][j] * d_out[j]
    
    for j in range(len(d_bias)):
        d_bias[j] += d_out[j]
        
    return d_x, d_weights, d_bias


# 定义ReLU激活函数
def relu(x):
    if isinstance(x[0][0], list):  # 如果是嵌套列表
        return [[[max(0, xi) for xi in row] for row in channel] for channel in x]
    elif isinstance(x[0], list):  # 如果是二维列表
        return [[max(0, xi) for xi in row] for row in x]
    else:  # 如果是一维列表
        return [max(0, xi) for xi in x]

# 定义ReLU激活函数的反向传播
def relu_backward(d_out, x):
    if isinstance(x[0][0], list):  # 如果是嵌套列表
        return [[[d_out[i][j][k] if x[i][j][k] > 0 else 0 for k in range(len(x[i][j]))] for j in range(len(x[i]))] for i in range(len(x))]
    elif isinstance(x[0], list):  # 如果是二维列表
        return [[d_out[i][j] if x[i][j] > 0 else 0 for j in range(len(x[i]))] for i in range(len(x))]
    else:  # 如果是一维列表
        return [d_out[i] if x[i] > 0 else 0 for i in range(len(x))]

# 定义交叉熵损失函数
def cross_entropy_loss(predictions, targets):
    exp_predictions = [math.exp(pred) for pred in predictions]
    sum_exp = sum(exp_predictions)
    softmax = [exp_pred / sum_exp for exp_pred in exp_predictions]
    loss = -math.log(softmax[targets])
    return loss

# 定义softmax函数
def softmax(x):
    exp_x = [math.exp(xi) for xi in x]
    sum_exp_x = sum(exp_x)
    return [xi / sum_exp_x for xi in exp_x]

# 定义交叉熵损失的反向传播
def cross_entropy_loss_backward(predictions, targets):
    m = len(predictions)
    softmax_output = softmax(predictions)
    softmax_output[targets] -= 1
    grad = [softmax_output[i] / m for i in range(m)]
    return grad

class SimpleCNN:
    def __init__(self):
        self.conv1_weights = [[[[random.random() * 0.1 for _ in range(3)] for _ in range(3)] for _ in range(1)] for _ in range(6)]
        self.conv1_bias = [0 for _ in range(6)]
        self.fc1_weights = [[random.random() * 0.1 for _ in range(10)] for _ in range(6*3*3)]
        self.fc1_bias = [0 for _ in range(10)]
    
    def forward(self, x):
        self.x = x
        self.x_conv1 = conv2d(x, self.conv1_weights, self.conv1_bias)
        self.x_relu1 = [[relu(channel) for channel in sample] for sample in self.x_conv1]
        self.x_pool1 = max_pool2d(self.x_relu1, 2)
        self.x_flatten = [item for sublist in self.x_pool1 for sublist2 in sublist for item in sublist2]
        self.x_fc1 = fully_connected(self.x_flatten, self.fc1_weights, self.fc1_bias)
        return self.x_fc1
    
    def backward(self, d_out, learning_rate):
        d_fc1, d_fc1_weights, d_fc1_bias = fully_connected_backward(d_out, self.x_flatten, self.fc1_weights)
        d_pool1 = max_pool2d_backward([[d_fc1]], self.x_relu1, 2)
        d_relu1 = [[relu_backward(d_pool1[n], self.x_conv1[n]) for n in range(len(d_pool1))]]
        d_conv1, d_conv1_weights, d_conv1_bias = conv2d_backward(d_relu1[0], self.x, self.conv1_weights)
        
        for i in range(len(self.fc1_weights)):
            for j in range(len(self.fc1_weights[0])):
                self.fc1_weights[i][j] -= learning_rate * d_fc1_weights[i][j]
        for i in range(len(self.fc1_bias)):
            self.fc1_bias[i] -= learning_rate * d_fc1_bias[i]
        
        for i in range(len(self.conv1_weights)):
            for j in range(len(self.conv1_weights[0])):
                for k in range(len(self.conv1_weights[0][0])):
                    for l in range(len(self.conv1_weights[0][0][0])):
                        self.conv1_weights[i][j][k][l] -= learning_rate * d_conv1_weights[i][j][k][l]
        for i in range(len(self.conv1_bias)):
            self.conv1_bias[i] -= learning_rate * d_conv1_bias[i]


# 创建网络
model = SimpleCNN()

# 生成一些随机数据
inputs = [[[[random.random() for _ in range(8)] for _ in range(8)] for _ in range(1)] for _ in range(1)]  # 假设输入图像大小为8x8，单通道
targets = 5  # 假设目标类别为5

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
