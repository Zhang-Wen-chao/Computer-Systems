# foreword
基于现有硬件的一些使用心得。工具只是工具，想清楚自己想干什么，想达到什么目的，然后选择工具。
1. AMD Ryzen™ 7 9700X × 16
2. GeForce RTX™ 5070 Ti

上策：windows + wsl2
中策：双系统
下策：再买一台（因为我没钱）
# windows 独有
- [Windows 10 总是不打招呼就自动更新？教你如何关闭它](https://www.dians.net/thread-1745.htm)

- [win11 永久激活](https://zhuanlan.zhihu.com/p/637930518)

## shortcut
1. win + shift + s 是截图.
2. win + v 是剪切板.
3. win + Ctrl + O 是屏幕键盘.
4. Alt + Ctrl + Delete，立即终结电脑的异常状态
## ivcam 虚拟摄像头
虽然连接的方式很多，但还是简单点好。

就用电脑释放热点，手机或者平板连接这个热点，这能确保两个设备，一定在一个局域网内。
# 在 windows和 linux 都能用的软件
## clash
https://help.lefly.cloud/contents/linux/cfw.html#%E4%B8%8B%E8%BD%BD%E5%B9%B6%E5%AE%89%E8%A3%85cfw
## Visual Studio Code
https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf

https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf

## oh my zsh
- git
- autosuggestion 
- syntax-highlighting
- autojump

```shell
# clash
open () {
  ports=(7890 7891 9090)
  for port in "${ports[@]}"
  do
    pids=$(lsof -i TCP:$port -t)
    if [[ -n $pids ]]; then
      echo "Killing processes on port $port: $pids"
      pkill -TERM -P $pids
    fi
  done
  echo "GLaDOS proxy enabled"
  cd /public/home/zhangwch2022/software/clash
  # ./clash-linux-amd64-v1.10.0 -f wyc-glados.yaml -d .
  ./clash-linux-amd64-v1.10.0 -f zwc-glados.yaml -d .
}
close () {
  ports=(7890 7891 9090)  # 要关闭的端口数组
  for port in "${ports[@]}"
  do
    pids=$(lsof -i TCP:$port | awk 'NR!=1 {print $2}')
    for pid in $pids
    do
      echo "Killing process $pid"
      kill -9 $pid
    done
    echo "Port $port closed"
  done
}
up () {
  # export http_proxy="127.0.0.1:7890"
  # export https_proxy="127.0.0.1:7890"
  export http_proxy="http://127.0.0.1:7890"
  export https_proxy="http://127.0.0.1:7890"

  env | grep -i proxy
}
down () {
  unset http_proxy
  unset https_proxy
  env | grep -i proxy
}
# curl https://en.wikipedia.org/wiki/Beijing
# curl https://www.baidu.com/
# curl https://www.google.com/
```
## vim
vim也只是一个古老的文本编辑器。
- h左，j下，k上，l右
- w 光标向前移动到下个单词首字母，，3w
- W 跳转到下一个字符串的首字母 （对应英文单词Word）
- e 光标向前移动到单词尾字母，，2e
- E 跳转到下一个字符串的尾字母 （对应英文单词End）
- b 光标向后移动到单词首字母
- B 光标向后移动到字符串首
- x 删除字符串
- r 更改一个字符 （对应英文单词Replace）
- d 可与w、e、b、W、E、B、h、j、k、l、d等字符组合，用来删除字符串或者句子。 （对应英文单词Delete）
- dl 与x功能一样，删除光标下一个字符，相当于键盘上的Del； dh 与之相反，功能相当于键盘上的backspace
- dw、de、dW、dE 均为向后删除一个单词或字符串，区别在于de/dE是从当前位置到单词或字符串末尾，而dw/dW是删除当前位置到下一个单词或字符串之前
- db、dB 向前删除一个单词或字符串。需要注意的是光标下的字符不删除
- dk、dj 分别是向上和向下删除两行
- dd 删除本行
3dd        删除三行
- yy 复制当前行
- 复制内容: v 进入虚拟模式, hjkl 移动复制, 然后按下 y
- p paste
## [Zotero](https://www.zotero.org/download/)
[Zotero更改储存路径&迁移文件](https://zhuanlan.zhihu.com/p/478035708)

[zotero+坚果云](https://blog.csdn.net/weixin_37707670/article/details/110307759)
## edge
- [CSDN 代码复制限制](https://greasyfork.org/zh-CN/scripts/454012-csdn-%E4%BB%A3%E7%A0%81%E5%A4%8D%E5%88%B6%E9%99%90%E5%88%B6)
- [关闭edge选中/复制文本时显示小菜单/方框](https://blog.csdn.net/qq_45611850/article/details/121380355)
- 视频倍速
```html
右键 inspect，console。
document.querySelector('video').playbackRate = 0.9
```
## 其他
- Lark
- Chrome
- Baidu Netdisk
- Sunlogin
- [在 Ubuntu下安装配置 TeX Live 与 TeXstudio](https://muzing.top/posts/6b2dc40e/)
# wsl2
docker desktop 会导致内存占用过大，卡死 wsl2。

在 wsl2 里面安装 docker
https://zhuanlan.zhihu.com/p/1882479728281227725?utm_campaign=shareopn&utm_medium=social&utm_psn=1883614922887373408&utm_source=wechat_session


现在不用手动开关了 修改一下.wslconfig文件就能自动开启代理了，以下是我的配置文件，修改前需要在powershell运行 wsl --update --pre-release

```
[wsl2]
nestedVirtualization=true
ipv6=true
[experimental]
autoMemoryReclaim=gradual # gradual | dropcache | disabled
networkingMode=mirrored
dnsTunneling=true
firewall=true
autoProxy=true
```
注意，这个方案仅在win11 22h1及以上版本生效

https://learn.microsoft.com/zh-cn/windows/wsl/wsl-config
配置更改的 8 秒规则

https://blog.csdn.net/Power_Blogger/article/details/128158694

https://learn.microsoft.com/en-us/windows/wsl/wsl-config#configure-global-options-with-wslconfig

https://huaweicloud.csdn.net/63311d63d3efff3090b52a2a.html

https://zhuanlan.zhihu.com/p/1882479728281227725
# ubuntu 24.04
## 安装驱动
微星主板，不知道为什么，进入u盘的ubuntu22 启动，但是点击了 try or install ubuntu 之后，就黑屏了，我现在觉得是显示器和显卡的问题。

u盘的ubuntu24 是正常安装的，但是在图形界面，怎么安装显卡驱动都不行。我现在的理解，还是因为显示器用了显卡，所以显卡上有x的驱动在用，就没法安装其他驱动。
解决方法：进入 advanced ubuntu, root, drop to prompt, 进入命令行界面，直接安装cuda 12.8, 就 ok 了。

### 之前的尝试
亲测 ubuntu20.04，直接联网在线装，稳定又省心。
```bash
第一步：
sudo apt updae
sudo apt install gcc g++ make cmake

第二步：
打开软件和更新--附加驱动--会自动搜索可用驱动；
找一个最新的，比如“专有530”--应用更改--装好--重启；

验证：
nvidia-smi和nvidia-settings检查是否装好，很简单省事。
```
## 安装输入法
fcitx5，小鹤双拼，逗号句号翻页。

- [Ubuntu 20.04 安装中文输入法（百度输入法）](https://www.zhihu.com/zvideo/1276684353373384704) 22.04会出现[qt5-default not in Ubuntu 21.04](https://zhuanlan.zhihu.com/p/443006210)
- [fcitx输入法代码分析总结](https://blog.csdn.net/ss49344/article/details/107051672)
- [如何现在就在 Ubuntu 20.04 用上 Fcitx 5](https://plumz.me/archives/11740/)
配置文件在`~/.config/fcitx5`,可直接复制粘贴已有文件。
  ```
  Ctrl + ; 进入剪贴板；如果刚开始只有一行，过两天可能就自己更新了，最多30行。按0选择候选词，在Ubuntu20.04上，很长一段时间都会直接退出fcitx5.后来也不知道为什么好了。
  Ctrl + . 切换到全局配置选项卡后，勾选底部的“显示高级选项”，并下滑，找到“切换全角标点”一栏。看到旁边的快捷键了吗？我这里是
  Ctrl + Alt + H：Completion is enabled.
  把 "choose key modifier"由 alt 改成 none ,作用是选词时免按alt.
  ```
  ubuntu 20.04, fcitx5，键入0，直接闪退。[可以换个桌面](https://www.jianshu.com/p/8b2cf8bb5fe0)，但还没尝试
## docker 源
https://blog.csdn.net/penguinli/article/details/145289060

https://ghfast.top/

https://www.cnblogs.com/xydchen/p/18258781

阿里云
https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors
登录名
nick6249360572
绑定手机
185****8655

https://www.kelen.cc/dry/docker-hub-mirror

build tensorrt-llm时候，这个博客立大功。
https://blog.csdn.net/qq_44506233/article/details/129319708
## singularity
使用singularity 可以在无超级用户权限下使用docker
本地安装文档参考 https://apptainer.org/user-docs/master/quick_start.html
一般常用逻辑：
如果要安装新的python package在你的.sif环境下，
首先在本地将.sif(dockerhub上build好的文件) 编译成 my_name 的sandbox文件夹，
在my_name下安装新的python包
之后再将sandbox编译成.sif文件，传到集群上使用

集群上使用预编译好的singularity需要运行(此外还有--bind 参数之类的可以参考使用)
singularity shell --nv xxx.sif
python xxxxx

下面命令都是在本地wsl/linux里使用sudo权限进行的
编译sandbox
sudo singularity build --sandbox my_name xxx.sif

安装新的包
sudo singularity shell -w my_name 
pip install xxx 
apt-get install xxx

编译回.sif文件
sudo singularity build xxx.sif my_name
## 低版本的CUDA、CUDNN
[如何在Docker中搭建CUDA & CUDNN 开发环境](https://zhuanlan.zhihu.com/p/580156606)
```bash
apt-get update
pip install jupyter
jupyter-notebook --generate-config
jupyter-notebook password
vim /root/.jupyter/jupyter_server_config.json
vim /root/.jupyter/jupyter_server_config.py 
# 启动 jupyter
jupyter notebook --ip=0.0.0.0 --allow-root
# 本地浏览器远程连接docker的jupyter
ssh -L 8008:localhost:80 student001@10.20.30.160
http://localhost:8008
# 导出文件系统
sudo docker export 65c6f7fb7d9e > Ubuntu20.04-CUDA.tar
# 监视 gpu
screen watch -n 1 nvidia-smi
```
[docker容器中使用jupyter notebook](https://zhuanlan.zhihu.com/p/74243731)

[本地使用服务器Docker中jupyter notebook](https://blog.csdn.net/weixin_41242128/article/details/108886706)

[[SOLVED] Docker with GPU: "Failed to initialize NVML: Unknown Error"](https://bbs.archlinux.org/viewtopic.php?id=266915)
### test 语句
```shell
nvcc -V
nvidia-smi
python -c "import torch; print(torch.__version__)"
python -c "import torch; print(torch.version.cuda)"
python -c "import torch.backends.cudnn as cudnn; print(cudnn.version())"
python -c "import tensorrt; print(tensorrt.__version__)"
python -c "import pytorch_quantization; print(pytorch_quantization.__version__)"
```
## 安装wps 的问题
https://blog.csdn.net/qq_42879057/article/details/139123173

缺失的就是下面这个软件。
https://mirrors.ustc.edu.cn/debian/pool/main/f/freetype/libfreetype6_2.12.1%2Bdfsg-5%2Bdeb12u3_amd64.deb

# todo
1. 把鼠标添加进入，研究一下快捷键。
2. 把下面的内容，整合到上面去。
3. 把 switch cuda 函数，放到 oh my zsh 上面去。
4. 清理 chrome 的书签
5. 新的目标出现了：以百度网盘、github为枢纽，连接双系统。
要做到，离开一个系统之前，github提交状态。切换到一个系统后，拉取一下就能继续工作。
文件同步，有点难。好像也不难，公共文件，放到一块共用的硬盘就好了。

未来
可以研究一下：WIFI 和网线，网速叠加。
台式机无线网卡和有线网能共用吗？ - 汉宝宝的回答 - 知乎
https://www.zhihu.com/question/417839988/answer/1442059295

discord，平板上登陆了，应该是谷歌邮箱。以后可以在电脑上安装一下。

line，平板上登陆了，以后可以在电脑上安装一下。

Telegram，平板上登陆了，以后可以在电脑上安装一下。

faststone，这个长截图很好用，但是要付费。可以研究一下，有没有破解软件。

SuperDisplay，我在Google play 付费购买了，就是相当于把平板变为数位板吧？还可以做扩展屏幕。以后有时间玩一下。


我觉得，不需要太大的存储空间。主要研究一下，万兆网速，能不能做到，任何电影、戏曲、视频，都能迅速找到，然后迅速加载，播放到大屏幕上。
存储空间最多放一点，养娃的照片，这个放到百度网盘也一样。一家用一个百度网盘会员。


再研究一下，怎么加入别人的YouTube家庭组，可以免广告。


zotero，谷歌记录了密码。
坚果云，谷歌记录了密码。
但是，去tm的吧，我就没看过论文。

spotify，用谷歌账户登陆的，平板上登陆了，以后可以在电脑上安装一下。


谷歌账户，还有短的前缀吗？



研究一下买4k屏幕，应该有国补的吧，看看是湖北买还是上海买。一定要一步到位，满足多种需求。

研究一下 powershell的优化美化。
https://zhuanlan.zhihu.com/p/137251716
https://blog.unclezs.com/pages/9b6e12/#%E7%AE%80%E4%BB%8B


把台式机，那一堆包装，研究一下，还有多的配件。没事就使劲问客服。

搞明白lvm管理

研究一下，能不能像手机组件一样，把Google 搜索栏，直接放到win 11任务栏？


研究一下，给机箱，再装一个风扇。之前b站发开箱视频，送了一个。

研究一下，在台式机上，再来一块ssd，稳定装debian。
# some settings
- [不花里胡哨看电脑主板支持最大内存与频率](https://blog.csdn.net/qq_45164497/article/details/126358529)
# some softwares

## Essential software
- [Clash for Windows](https://glados.rocks/console)

- [Baidu Input Method Editors](https://shurufa.baidu.com/)
[关于在Win11任务栏隐藏输入法（中英文切换）图标的解决办法](https://blog.csdn.net/weixin_47907823/article/details/121954248)

- [Mouse without Borders](https://www.microsoft.com/en-us/download/details.aspx?id=35460)

- [Outlook requires updates before it can start](https://learn.microsoft.com/en-us/answers/questions/830716/outlook-requires-updates-before-it-can-start)
## logitech mouse G300s
### linux 下设置
![logitech_red](../images/linux_red.png "logitech_red")

![logitech_blue](../images/linux_blue.png "logitech_blue")
### win 下设置
![logitech_yellow](../images/win_yellow.png "logitech_yellow")

![win_blue](../images/win_blue.png "win_blue")
### mac 下怎么设置
研究一下，Mac常用快捷键。

## wallpaper
壁纸，传输大文件到国外。
## 蒙特卡洛算法
蒙特卡洛算法°当然算法原理很简单
一开始根本是不信，单纯是觉得好玩，报着试试看的态度，简单用python尝试了一下，但是结果确令人震惊，暴力随机居然可以模拟真实，这简直开始让我怀疑世界了，真实的世界不会也是这么随机模拟“的吧。
# 常用小技巧
## Removable storage device
[U盘写保护无法格式化怎么办？](https://www.reneelab.com.cn/m/how-to-format-write-protected-usb.html)

[Windows下使用Diskpart格式化U盘](https://www.cnblogs.com/zhuxiaoxi/p/9292863.html)
## Download YouTube videos
https://www.youtube.com/watch?v=K1lQa5QsyDU

加上ss，VPN非美国节点，即可下载。
https://www.ssyoutube.com/watch?v=K1lQa5QsyDU

## 连接天猫精灵
我的天猫精灵在桌子右侧第三个抽屉。网易云音乐还能连接天猫精灵，那就好了。


# Debian
- [如何轻松安装 Debian Linux 系统](https://zhuanlan.zhihu.com/p/410974122)
- [ISO下载](https://cdimage.debian.org/cdimage/unofficial/non-free/cd-including-firmware/11.6.0-live+nonfree/amd64/iso-hybrid/)
- [balena下载](https://www.balena.io/etcher#download-etcher)
- [原创-解决Parrot安装卡在91%](https://blog.csdn.net/xyq165980/article/details/128259388)
- [How To Fix Busybox Initramfs Error On Ubuntu](https://ostechnix.com/how-to-fix-busybox-initramfs-error-on-ubuntu/)
- 开机总是出现default keyring输入密码: 终端输入seahorse，把default keyring的密码设为空。
- [基于双机械硬盘和一块固态硬盘安装ubuntu系统的硬盘挂载](https://blog.csdn.net/weixin_43326587/article/details/108482676)最好在装系统时候就直接分好区，比如把机械硬盘挂载在`/home`，固态硬盘挂载在`/`。
- [mount 挂载磁盘报错 mount: wrong fs type, bad option, bad superblock on](https://blog.csdn.net/wohu1104/article/details/121021207)
- [How to remove Home Folder icon from desktop in Ubuntu 20.04?](https://askubuntu.com/questions/1230877/how-to-remove-home-folder-icon-from-desktop-in-ubuntu-20-04)
  ```bash
  sudo apt install gnome-shell-extension-prefs
  ```

# Software
## Essential software
### Microsoft Edge
- Microsoft Edge
[关闭edge选中/复制文本时显示小菜单/方框](https://blog.csdn.net/qq_45611850/article/details/121380355)
### VScode
使用 Ctrl + R 搜索历史命令：在命令行中按下快捷键 Ctrl + R ，终端回提示 reverse-i-search ，然后在其中输入你要搜索的命令，找到之后按回车就会执行这条命令。 再按 Ctrl + G 退出搜索。

vscode的正则表达式搜索中的通配符: '.*'

- [vscode](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf)
- oh my zsh
  ```shell
  ZSH_THEME="muse"
  zsh-syntax-highlighting
  zsh-autosuggestions
  [autojump](https://blog.csdn.net/daerzei/article/details/101362569)
  
  https://zhuanlan.zhihu.com/p/509092527
  
  http://www.uj5u.com/caozuo/274326.html

  # clash
  open () {
    ports=(7890 7891 9090)
    for port in "${ports[@]}"
    do
      pids=$(lsof -i TCP:$port -t)
      if [[ -n $pids ]]; then
        echo "Killing processes on port $port: $pids"
        pkill -TERM -P $pids
      fi
    done
    echo "GLaDOS proxy enabled"
    cd /public/home/zhangwch2022/software/clash
    # ./clash-linux-amd64-v1.10.0 -f wyc-glados.yaml -d .
    ./clash-linux-amd64-v1.10.0 -f zwc-glados.yaml -d .
  }
  close () {
    ports=(7890 7891 9090)  # 要关闭的端口数组
    for port in "${ports[@]}"
    do
      pids=$(lsof -i TCP:$port | awk 'NR!=1 {print $2}')
      for pid in $pids
      do
        echo "Killing process $pid"
        kill -9 $pid
      done
      echo "Port $port closed"
    done
  }
  up () {
    export http_proxy="127.0.0.1:7890"
    export https_proxy="127.0.0.1:7890"
    # export http_proxy="http://127.0.0.1:7890"
    # export https_proxy="http://127.0.0.1:7890"
    env | grep -i proxy
  }
  down () {
    unset http_proxy
    unset https_proxy
    env | grep -i proxy
  }
  # curl https://en.wikipedia.org/wiki/Beijing
  # curl https://www.baidu.com/
  # curl https://www.google.com/
  ```
- [Clash for Terminal](https://glados.rocks/console)
- [Got permission denied while trying to connect to the Docker daemon socket](https://dev.to/kenji_goh/got-permission-denied-while-trying-to-connect-to-the-docker-daemon-socket-3dne)

### Common software
- Vivado
- sudo apt install translate-shell
- [Open Broadcaster Software](https://obsproject.com/)
- [VLC](https://www.videolan.org/vlc/)
- [Ventoy](https://www.ventoy.net/cn/doc_start.html)
- [快速上手 Goldendict](https://zhuanlan.zhihu.com/p/344770839)
- [Calibre](https://calibre-ebook.com/download)
- [Locating iostream in Clang++: fatal error: 'iostream' file not found](https://stackoverflow.com/questions/54521402/locating-iostream-in-clang-fatal-error-iostream-file-not-found)
  ```bash
  sudo apt install clang
  clang --version
  sudo apt install libstdc++-12-dev
  ```
- [ubuntu安装Zotero,任何版本ubuntu适用](https://blog.csdn.net/xinjieyuan/article/details/105407564) 
- [Zotero+坚果云](https://blog.csdn.net/weixin_37707670/article/details/110307759)
- [编译安装gcc12-2](https://blog.csdn.net/fen_fen/article/details/129021912)
## opencv
[Opencv 4.3（CUDA11 ） 编译踩坑记录](https://www.cnblogs.com/geoffreyone/p/15040907.html)
新版本的bug会少一些。费了好几个小时安装3.3，一堆错误。编译安装4.8.1，没啥报错。
```bash
wget https://github.com/opencv/opencv/archive/refs/tags/4.8.1.zip
cmake ..
make
make install
python -c "import cv2; print(cv2.__version__)"
```
然后cmake是可以检测到opencv的版本的。

[ImportError: libGL.so.1: cannot open shared object file: No such file or dir...解决Python import cv2报错](https://blog.csdn.net/qq_39691492/article/details/130688233)
方案二work了。
## [Learn Git Branching](https://learngitbranching.js.org/?locale=zh_CN)
```bash
因为上游用了 submodule 所以也稍微学了一下。
为了把其他分支的修改转移到当前分支，学了 cherry-pick 。
为了恢复丢掉的修改记录，学了 reflog 。
为了找到引入或修复 bug 的版本，学了 bisect 和 blame 。
为了知道最近的 tag 名称，学了 describe 。
为了知道 tag 对应的提交代码，学了 rev-parse 。
（以上两条是为了更方便地 blame 。）
为了同时访问多个分支，学了 worktree 。
为了降低索引的大小，学了 gc 、 prune 和 repack 。
遇到过索引中的对象文件损坏，为了修复，学了 fsck 。
最近还学到用 ls-files 查看自己改了哪些文件。
当然过程中也断断续续学了不少选项，比如 commit --amend 、pull --rebase 、rebase --autostash、commit --fixup 、rebase --autosquash 等。
到这里我觉得我已经认识了大多数初级指令。但是对于如何使用 hook，如何直接操作索引中的对象，我还是一无所知。对于使用邮件的工作流程，我也不太了解。
```
- [Missing or invalid credentials.](https://juejin.cn/post/7062237873570840589)
- 查看github星星数量
https://github.com/Zhang-Wen-chao/CS240/stargazers
- [github文件夹有向右的白色箭头并且不能打开的解决办法](https://www.jianshu.com/p/7cc6ea70e48e)
- [2021.8.13起，Github要求使用基于令牌的身份验证](https://zhuanlan.zhihu.com/p/401978754)在.gitconfig文件里按照自己的需求加上
  ```shell
  [user]
    name = Zhang-Wen-chao
    email = zhangwch2022@shanghaitech.edu.cn
  [http]
    sslVerify = false
  [alias]
    gpush = !git add . && git commit -m 'update' && git push
    safepull = "! [ -z \"$(git status --porcelain)\" ] && [ -z \"$(git log origin/$(git symbolic-ref --short HEAD)..HEAD --oneline)\" ] && git pull"
  [filter "lfs"]
    smudge = git-lfs smudge -- %f
    process = git-lfs filter-process
    required = true
    clean = git-lfs clean -- %f
  [lfs]
    contenttype = 0
  [credential]
    helper = cache
  ```
