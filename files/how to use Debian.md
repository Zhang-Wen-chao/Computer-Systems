# Debian's basic installation issues
- [如何轻松安装 Debian Linux 系统](https://zhuanlan.zhihu.com/p/410974122)

- [ISO下载](https://cdimage.debian.org/cdimage/unofficial/non-free/cd-including-firmware/11.6.0-live+nonfree/amd64/iso-hybrid/)

- [balena下载](https://www.balena.io/etcher#download-etcher)

- [原创-解决Parrot安装卡在91%](https://blog.csdn.net/xyq165980/article/details/128259388)

- [How To Fix Busybox Initramfs Error On Ubuntu](https://ostechnix.com/how-to-fix-busybox-initramfs-error-on-ubuntu/)

- 开机总是出现default keyring输入密码: 终端输入seahorse，把default keyring的密码设为空。

- [ubuntu20.04 黑屏/紫屏后的处理办法](https://codeantenna.com/a/GWbmAVSb7g)
ctrl + alt + F3 (tty登陆)

- [Linux下tmpfs介绍及使用](https://www.serverspc.com/46025.html)

- [mount 挂载磁盘报错 mount: wrong fs type, bad option, bad superblock on](https://blog.csdn.net/wohu1104/article/details/121021207)

- [linux挂载windows的ntfs硬盘](https://github.com/tuxera/ntfs-3g)

- [You are in emergency mode ... Cannot open access to console, the root account is locked. 的一种解决方法](https://ld246.com/article/1629522554915)

- 增大 `/tmp` 的空间。
   ```
   df -h /tmp
   找到包含 `/tmp` 目录的行，并将其选项修改为 `defaults,size=2G`（注意改变 `size` 选项以匹配你想要的大小）, save and quit.
   sudo mount -o remount /tmp
   ```
# network
## 禁用 IPv6
```shell
要禁用 IPv6，你可以在 Linux 系统中执行以下步骤：

打开终端，并以 root 用户身份执行以下命令：
echo "net.ipv6.conf.all.disable_ipv6 = 1" >> /etc/sysctl.conf
echo "net.ipv6.conf.default.disable_ipv6 = 1" >> /etc/sysctl.conf

执行以下命令以应用更改：

sysctl -p

这将在 /etc/sysctl.conf 文件中添加两个条目，用于禁用 IPv6，然后应用更改。请注意，这将禁用系统上所有网络接口的 IPv6，包括所有网卡、虚拟接口等等。如果你需要启用某些接口的 IPv6，可以使用以下命令：

echo "net.ipv6.conf.<interface-name>.disable_ipv6 = 0" >> /etc/sysctl.conf

将 <interface-name> 替换为要启用 IPv6 的网络接口的名称，然后再次执行 sysctl -p 以应用更改。
```
# Some software
sudo apt install gcc g++ gdb make cmake vim git
## bash
1. 如何通过bash在Linux中下载Onedrive文件
在OneDrive网页端，以chrome浏览器为例，用F12打开开发人员工具，然后在网页中选中要下载的文件点击下载按钮。在开发工具network标签下，看到新出现的项目，右击，选择copy cURL (bash)，然后在Linux terminal中粘贴，并在末尾加上 --output <文件名> 即可。
## cuda、cudnn、nvvc、nccl
- [Debian 11下安装Nvidia显卡驱动与Cuda](https://yangyq.net/2023/03/debian-11-nvidia-driver-cuda.html)
- [Debian 11下升级Cuda与Nvidia显卡驱动](https://yangyq.net/2023/03/debian-11-cuda-nvidia-driver-upgrade.html)
- [在安裝 Nvidia 驅動時發生 “The Nouveau kernel driver is currently in use by your system. …”](https://clay-atlas.com/blog/2020/02/11/linux-chinese-note-nvidia-driver-nouveau-kernel/)
- [在Fedora上安装NVIDIA驱动详细教程及解析](https://blog.csdn.net/qq_61653333/article/details/128883198)
- [linux下普通用户安装CUDA和cuDNN](https://blog.csdn.net/u012422446/article/details/104882357)

```shell
nvcc -V
nvidia-smi
python -c "import torch;print (torch.cuda.is_available ());print (torch.__version__);import torchvision;print(torchvision.__version__)"
```
## conda
[解决CondaHTTPError: HTTP 000 CONNECTION 问题](https://zhuanlan.zhihu.com/p/260034241)
## Essential software
- Fcixt 5
```
候选翻页：逗号句号。

Ctrl+; 进入剪贴板输入模式.

ctrl+alt+H：激活 spell hint状态，把 "choose key modifier"由 alt 改成 none ,作用是选词时免按alt.

设计的时候剪切板就只能显示一行。
```
- [Clash for Terminal](https://glados.rocks/console)
- [Feishu](https://www.feishu.cn/download)
- [Baidu Netdisk](https://pan.baidu.com/download/)
- [Baidu Input Method Editors](https://shurufa.baidu.com/)
- [Sunlogin](https://sunlogin.oray.com/)
- [Open Broadcaster Software](https://obsproject.com/)
- [VLC](https://www.videolan.org/vlc/)
- [vscode](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf)
- [Wemeet](https://meeting.tencent.com/)
```
腾讯会议不兼容wayland协议怎么解决？
sudo vim /etc/gdm3/daemon.conf
把 #WaylandEnable=false 的注释井号去掉
sudo service gdm3 restart
```
- [Calibre](https://calibre-ebook.com/download)
[最强大的本地电子书管理工具：Calibre 使用指南](https://zhuanlan.zhihu.com/p/34996144)
- libreoffice
```
libreoffice --impress --norestore 2.4git课程材料.pptx &
sudo apt-get update
sudo apt-get install libreoffice-java-common
```
- QQ
- Zoom
- Discord
- Telegram
- Cursor
- Zotero

[ubuntu安装Zotero,任何版本ubuntu适用](https://blog.csdn.net/xinjieyuan/article/details/105407564)

[文献管理软件——Zotero以及实用插件介绍 第一期](https://www.bilibili.com/video/BV1L24y117Qr/?share_source=copy_web)

[zotero+坚果云](https://blog.csdn.net/weixin_37707670/article/details/110307759)
### oh my zsh
- autosuggestion 
- syntax-highlighting
- autojump
- Powerlevel10k
1. 集群上设置zsh为默认
然而，在其他终端或软件中，可能会以非登录 Shell 的方式启动，从而只加载 ~/.bashrc 文件，而不加载 ~/.bash_profile 文件。这就解释了为什么你的 bashrc 在其他软件中无法自动执行。
解决方案：在.bashrc、.bash_profile都启动zsh。
2. debian上vscode怎么设置zsh为默认
要在最新的 VS Code 中设置默认的终端 shell，请按照以下步骤进行操作：
打开 VS Code 并进入菜单栏的 “File”（文件）选项。
选择 “Preferences”（首选项）并点击 “Settings”（设置）。
在设置页面的搜索框中，输入 “terminal.integrated.defaultProfile.linux”。
在右侧的下拉菜单中，选择您想要的默认终端 shell。如果您已经安装了 Zsh，则可能会看到类似 “zsh” 或 “Zsh” 的选项。
保存设置并关闭页面。
现在，当您在 VS Code 中打开终端时，它应该默认使用您选择的终端 shell。
3. some alias
目前我在debian本地也开始使用命令行版本的clash,然后在网络设置里面手动设置127.0.0.1:7890
现在感觉比图形界面的要稳定一些。
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
### gcc
[Linux centos7安装gcc12-2](https://blog.csdn.net/fen_fen/article/details/129021912)
### Extensions
- [VS code 自定义 clang-format 格式化代码格式](https://www.jianshu.com/p/c2dd26fe6f78)
### Settings
- autosave
### conda and docker
- miniconda3
```
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh
```
<https://mirrors.tuna.tsinghua.edu.cn/help/anaconda/>

[pip 使用国内镜像源](https://www.runoob.com/w3cnote/pip-cn-mirror.html)

- Docker
[Debian 11 / Ubuntu 22.04 安装 Docker 以及 Docker Compose 教程](https://u.sb/debian-install-docker/)

## [Learn Git Branching](https://learngitbranching.js.org/?locale=zh_CN)
```
git commit --amend
git push -f
git reset
git reset HEAD~1
git reset --hard
git revert
git config --global user.name "zvvc"
git config --global user.email "zwc@outlook.lv"
git push origin zvvc

后来为了看源码在一段时间内有哪些改动，学了 log 、 show 和 diff 。
为了找到感兴趣内容所在的文件，学了 grep （指 git grep）。
发现上游有多个分支，为了查看不同分支，学了 branch 和 checkout （现在一般用 switch）。
因为上游用了 submodule 所以也稍微学了一下。
在网络不理想的时候，为了从镜像拉取，学了 remote 。
因为手痒，想自己给项目添加内容，为了让自己写的东西纳入 git 管理，学了 commit （那时候用的还是 commit -a ，用不到 add）。
大概是这时候，第一次遇到了躲不开的配置项，也就是 config 。
从上游拉取时，为了不和自己写的东西冲突，学了 merge 、 add 和 status，后来又学了 fetch 和 rebase 。
为了提 Pull Request，也为了备份自己写的东西，学了 push 。
为了把其他分支的修改转移到当前分支，学了 cherry-pick 。
为了撤回修改，学了 reset （当时有些需求现在可以用 restore 完成）。
为了恢复丢掉的修改记录，学了 reflog 。
为了保存写到一半的内容，学了 stash 。
为了找到引入或修复 bug 的版本，学了 bisect 和 blame 。
为了知道最近的 tag 名称，学了 describe 。
为了知道 tag 对应的提交代码，学了 rev-parse 。
（以上两条是为了更方便地 blame 。）
为了同时访问多个分支，学了 worktree 。
为了降低索引的大小，学了 gc 、 prune 和 repack 。
遇到过索引中的对象文件损坏，为了修复，学了 fsck 。
最近还学到用 ls-files 查看自己改了哪些文件。
当然过程中也断断续续学了不少选项，比如 commit --amend 、pull --rebase 、rebase --autostash、commit --fixup 、rebase --autosquash 等。
另外时不时用到 init 、 revert 、 rm 、 mv 、 apply 和 rev-list ，但是没仔细学过。
到这里我觉得我已经认识了大多数初级指令。但是对于如何使用 hook，如何直接操作索引中的对象，我还是一无所知。对于使用邮件的工作流程，我也不太了解。
回想起来，从一开始到现在，学的每个东西都是为了能用就行。但是因为有这么多需要，也确实只有学习这么多东西才够用
```
- 作为仓库的合作者
```
提交自己的代码
git push --set-upstream origin zvvc

拉取最新的代码
git checkout main
git pull
git checkout zvvc
git merge main
```
- 作为仓库的拥有者
作为仓库的拥有者，你可以根据合作者执行的命令 git push --set-upstream origin zvvc 采取以下步骤进行处理：

确认合作者的更改：使用 git log 命令查看合作者推送的提交，以了解他们所做的更改。

检查分支：确保合作者要推送到的分支名称 zvvc 不会与现有的分支名称发生冲突。

审查更改：使用 git diff 命令来查看合作者所做的具体更改内容。

接受或拒绝更改：根据你对合作者更改的评估，可以选择接受或拒绝这些更改。

如果你决定接受合作者的更改，可以执行以下命令将其合并到你的主分支（比如 main 或 master）中：
```
git checkout main  # 切换到主分支
git pull origin zvvc  # 拉取合作者的更改
git merge zvvc  # 合并合作者的更改到主分支
git push origin main  # 推送合并后的更改到远程仓库的主分支
```
如果你决定拒绝合作者的更改，你可以使用以下命令回退或重置远程分支，撤销合作者的提交。这将丢弃合作者的更改，请谨慎使用，并确保在执行之前备份重要的更改。
```
git branch -D zvvc  # 删除本地分支（仅在你确认不需要这个分支时使用）
git push origin :zvvc  # 删除远程分支（仅在你确认不需要这个分支时使用）
```
请注意，在执行这些命令之前，确保你在本地仓库的正确分支上进行操作，并且仔细评估合作者的更改以确保安全和正确性。
- 修改仓库名字
请注意，更改仓库名称后，你需要更新本地仓库的远程URL以反映新的名称。
如果你在使用命令行进行Git操作，可以使用以下命令更新远程URL：
```
git remote set-url origin 新的仓库URL
```
- [Missing or invalid credentials.](https://juejin.cn/post/7062237873570840589)
- 查看github星星数量
https://github.com/Zhang-Wen-chao/CS240/stargazers

- [github文件夹有向右的白色箭头并且不能打开的解决办法](https://www.jianshu.com/p/7cc6ea70e48e)
- [2021.8.13起，Github要求使用基于令牌的身份验证](https://zhuanlan.zhihu.com/p/401978754)

### 自定义命令
在.gitconfig文件里按照自己的需求加上
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
## edge
- [CSDN 代码复制限制](https://greasyfork.org/zh-CN/scripts/454012-csdn-%E4%BB%A3%E7%A0%81%E5%A4%8D%E5%88%B6%E9%99%90%E5%88%B6)
- 强制黑色背景
edge://flags/#enable-force-dark
- [关闭edge选中/复制文本时显示小菜单/方框](https://blog.csdn.net/qq_45611850/article/details/121380355)
- 视频倍速
```html
右键 inspect，console。
document.querySelector('video').playbackRate = 0.9
```
- 同步问题
据我观察，如果一直setting up sync，那就关闭外网、重新登录都试一试。
## vim
用vim不是为了炫技。vim也只是一个古老的文本编辑器。

移动模式: h(左)j(下)k(上)l(右) 一定要最先的记死用熟
插入模式: 你可以输入想要输入的东西,没什么可以说的
保存文件: :w然后回车
复制内容: v 进入虚拟模式, hjkl 移动复制, 然后按下 y
粘贴内容: p
为什么要学 vim
方向键联系 hjkl
h左，j下，k上，l右

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
- p paste

# 文件处理
## 物理打印机
```bash
lpstat -o
cancel HP_LaserJet_M1536dnf_MFP_3184B1_-7
lp -d  printer HP_LaserJet_M1536dnf_MFP_3184B1_ /usr/share/cups/data/testprint
```
## wps
The Linux version has no ads.
## libreoffice
libreoffice is open source.
## tree
View the tree structure of the file organization. 
## compressed software
```bash
tar -czvf download_jump.tar.gz /home/student001/zhangwch/Working-at-SHIC/scripts/download_jump

tar -czvf 'Natural Language Processing_Tu Kewei.tar.gz' '/home/student001/zhangwch/Studying-at-ShanghaiTech/Natural Language Processing_Tu Kewei'

unzip xxx.zip

unrar x <rar文件名> <目标目录>
```