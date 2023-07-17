import signal
import sys
import os
import requests
import time
from datetime import datetime

# 创建总文件夹
base_dir = "jump_images"
if not os.path.exists(base_dir):
    os.makedirs(base_dir)

# 创建日志文件
log_file = os.path.join(base_dir, "log.txt")

def log_message(message):
    # 获取当前系统时间
    current_datetime = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # 将消息和当前系统时间写入日志文件
    with open(log_file, "a") as f:
        log_line = f"{message} 当前系统时间为: {current_datetime}\n"
        f.write(log_line)

# 记录开始时间
start_time = time.time()

# 记录开始下载的消息
log_message("开始下载图片")

def signal_handler(signal, frame):
    # 获取当前系统时间
    current_datetime = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # 在捕获到中断信号时记录当前时间
    with open(log_file, "a") as f:
        log_line = f"捕获到键盘中断信号, 命令执行到URL: {url} 时中断，当前系统时间为: {current_datetime}\n"
        f.write(log_line)

    sys.exit(0)

# 注册信号处理函数
signal.signal(signal.SIGINT, signal_handler)

def download_image(url, folder_path):
    # 提取图片文件名
    filename = url.split("/")[-3] + "-" + url.split("/")[-2] + "-" + url.split("/")[-1]

    # 检查图片是否已存在
    if os.path.exists(os.path.join(folder_path, filename)):
        status = f"图片 {filename} 已存在，跳过下载"
    else:
        try:
            # 记录命令开始的时间
            start_time = time.time()

            # 下载图片
            response = requests.get(url, stream=True, verify=False)
            if response.status_code == 200:
                # 保存图片到指定路径
                with open(os.path.join(folder_path, filename), "wb") as f:
                    f.write(response.content)
                status = f"下载并保存图片 {filename} 成功"
            else:
                status = f"下载图片 {filename} 失败"

        except KeyboardInterrupt:
            # 在中断发生时记录当前时间并抛出异常
            current_datetime = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            status = f"键盘中断，当前系统时间为: {current_datetime}"
            with open(log_file, "a") as f:
                log_line = f"捕获到键盘中断信号, 命令执行到URL: {url} 时中断，{status}\n"
                f.write(log_line)
            raise KeyboardInterrupt
        
        except Exception as e:
            status = f"下载图片 {filename} 出现异常：{str(e)}"
        
        finally:
            if "status" not in locals():
                status = f"下载图片 {filename} 失败（未知错误）"

            # 计算命令执行的耗时（毫秒）
            end_time = time.time()
            elapsed_time = int((end_time - start_time) * 1000)

    # 将状态、URL、耗时和开始时间写入日志文件
    with open(log_file, "a") as f:
        log_line = f"URL: {url}\t"
        # 如果存在 elapsed_time，则写入日志文件
        if "elapsed_time" in locals():
            log_line += f"执行耗时: {elapsed_time} 毫秒\t"
        log_line += f"{status}\t\n"
        f.write(log_line)

# 打开文件
with open("image_urls.txt", "r") as file:
    current_parent_dir = ""
    current_child_dir = ""
    control_images_folder = False

    # 记录文件夹下载开始的时间
    folder_start_time = time.time()

    # 逐行读取文件内容
    for line in file:
        line = line.strip()
        
        # 检查是否为文件夹行
        if line.startswith("Images for"):
            # 只在非第一个文件夹时记录时间
            if current_parent_dir:
                # 计算文件夹下载的耗时（毫秒）
                folder_end_time = time.time()
                folder_elapsed_time = int((folder_end_time - folder_start_time) * 1000)

                # 将文件夹下载耗时和名称写入日志文件
                with open(log_file, "a") as f:
                    log_line = f"{current_parent_dir} 文件夹下载耗时: {folder_elapsed_time} 毫秒\n\n"
                    f.write(log_line)

            parent_dir = line.split(" ")[-1][:-1]
            current_parent_dir = os.path.join(base_dir, parent_dir)
            current_child_dir = os.path.join(current_parent_dir, "Images")
            
            # 创建父文件夹和子文件夹
            if not os.path.exists(current_parent_dir):
                os.makedirs(current_parent_dir)
            if not os.path.exists(current_child_dir):
                os.makedirs(current_child_dir)
            
            # 记录新的文件夹开始下载的时间
            folder_start_time = time.time()

            control_images_folder = False
        
        # 检查是否为Control Images文件夹行
        elif line.startswith("Control Images for"):
            control_dir = os.path.join(current_parent_dir, "Control Images")
            if not os.path.exists(control_dir):
                os.makedirs(control_dir)
            
            control_images_folder = True
        
        # 检查是否为图片行
        elif line.startswith("http"):
            if current_parent_dir and current_child_dir:
                # 下载图片到相应文件夹
                if control_images_folder:
                    download_image(line, control_dir)
                else:
                    download_image(line, current_child_dir)

    # 计算最后一个文件夹的下载耗时（毫秒）
    folder_end_time = time.time()
    folder_elapsed_time = int((folder_end_time - folder_start_time) * 1000)

    # 获取最后一个文件夹的名称
    if current_parent_dir:
        last_folder_name = os.path.basename(current_parent_dir)
        # 将最后一个文件夹的下载耗时和名称写入日志文件
        with open(log_file, "a") as f:
            log_line = f"{last_folder_name} 文件夹下载耗时: {folder_elapsed_time} 毫秒\n\n"
            f.write(log_line)

# 记录结束时间
end_time = time.time()

# 计算总耗时（秒）
total_elapsed_time = int(end_time - start_time)

# 记录结束下载的消息
log_message("结束下载图片")

# 将总耗时和当前系统时间写入日志文件
with open(log_file, "a") as f:
    log_line = f"总耗时: {total_elapsed_time} 秒\t当前系统时间: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n"
    f.write(log_line)