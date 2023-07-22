# how to use it
## 1. download images 以下载 `0-19`(20个文件夹) 为例
```bash
python download_script.py --start 0 --end 20
```
### 遗留问题
SSL connect error

Stream error in the HTTP/2 framing layer

不知道是不是因为我的网络问题。
## 2. download infos
在`download_jump/download_infos/get_infos.py`中修改`numbers`的范围，然后运行

```bash
python get_infos.py
```

得到`image_urls.txt`文件