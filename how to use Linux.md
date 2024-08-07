# Preface
工具只是工具，想清楚自己想干什么，想达到什么目的，然后选择工具。
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
# Driver
## nvidia driver
最新亲测，ubuntu20.04以后，直接联网在线装，稳定又省心。
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
### cuda
```shell
nvcc -V
nvidia-smi
python -c "import torch; print(torch.__version__)"
python -c "import torch; print(torch.version.cuda)"
python -c "import torch.backends.cudnn as cudnn; print(cudnn.version())"
python -c "import tensorrt; print(tensorrt.__version__)"
python -c "import pytorch_quantization; print(pytorch_quantization.__version__)"
```
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
### Common software
- Lark
- [在 Ubuntu下安装配置 TeX Live 与 TeXstudio](https://muzing.top/posts/6b2dc40e/)
- [Baidu Netdisk](https://pan.baidu.com/download/)
- [Sunlogin](https://sunlogin.oray.com/)
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