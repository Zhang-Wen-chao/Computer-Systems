# how to use it
## 1. download images
在`download_jump/download_images/get_images.py`中修改`numbers`的范围，然后运行
```bash
python get_images_urls.py
```

得到`image_urls.txt`文件

```bash
python download_images.py
```

得到`jump_images`文件夹

### 遗留问题
网络中断时候，正在下载的那张图片有名字，但无法显示，不知道怎么处理。

希望没有网络中断、键盘中断等。
## 2. download infos
在`download_jump/download_infos/get_infos.py`中修改`numbers`的范围，然后运行

```bash
python get_infos.py
```

得到`image_urls.txt`文件