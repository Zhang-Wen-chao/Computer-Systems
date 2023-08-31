# 写在前面
工具只是工具，想清楚自己想干什么，想达到什么目的，然后选择工具。

虽然我也安装过[Gentoo linux](https://bitbili.net/gentoo-linux-installation-and-usage-tutorial.html), 但我觉得舍本逐末了。
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
- [You are in emergency mode ... Cannot open access to console, the root account is locked. 的一种解决方法](https://ld246.com/article/1629522554915)
- 增大 `/tmp` 的空间。
  ```
  df -h /tmp
  找到包含 `/tmp` 目录的行，并将其选项修改为 `defaults,size=2G`（注意改变 `size` 选项以匹配你想要的大小）, save and quit.
  sudo mount -o remount /tmp
  ```
- [How to remove Home Folder icon from desktop in Ubuntu 20.04?](https://askubuntu.com/questions/1230877/how-to-remove-home-folder-icon-from-desktop-in-ubuntu-20-04)
  ```bash
  sudo apt install gnome-shell-extension-prefs
  ```
- [ubuntu 22.04修改内核为指定版本](https://blog.csdn.net/weixin_39190382/article/details/131965648)
- [Ubuntu操作系统如何设置默认启动内核](https://support.huaweicloud.com/trouble-ecs/ecs_trouble_0327.html)
- [password forgotten](https://forums.developer.nvidia.com/t/jetson-tx2-password-forgotten/160683/6)
# Some software
## nvidia driver
最新亲测，ubuntu22.04以后，直接联网在线装，稳定又省心。
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
- [linux下普通用户安装CUDA和cuDNN](https://blog.csdn.net/u012422446/article/details/104882357)
## cambricon driver
pcie 插槽规格要匹配，然后按照官方流程即可。
## Essential software
使用dpkg安装软件包需要手动解决依赖关系，而apt能够自动处理依赖关系并更加便捷地管理软件包。一般来说，推荐使用apt作为首选的软件包管理工具。

apt是apt-get的更现代、更推荐的替代工具，提供更丰富的功能和更友好的用户界面。建议使用apt命令来操作软件包，它相对于dpkg和apt-get更为便捷和强大。
- Microsoft Edge
  ```
  强制黑色背景: edge://flags/#enable-force-dark

  [关闭edge选中/复制文本时显示小菜单/方框](https://blog.csdn.net/qq_45611850/article/details/121380355)

  视频倍速, 右键 inspect, console: document.querySelector('video').playbackRate = 0.9
  ```
- [vscode](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-linux.pdf)
[VS code 自定义 clang-format 格式化代码格式](https://www.jianshu.com/p/c2dd26fe6f78)
- [oh my zsh](https://blog.csdn.net/tonydz0523/article/details/108112422)
  ```shell
  zsh-syntax-highlighting
  zsh-autosuggestions
  [autojump](https://blog.csdn.net/daerzei/article/details/101362569)

  # 1. 集群上设置zsh为默认
  # 然而，在其他终端或软件中，可能会以非登录 Shell 的方式启动，从而只加载 ~/.bashrc 文件，而不加载 ~/.bash_profile 文件。这就解释了为什么你的 bashrc 在其他软件中无法自动执行
  # 解决方案：在.bashrc、.bash_profile都启动zsh。
  # 2. debian上vscode怎么设置zsh为默认
  # 要在最新的 VS Code 中设置默认的终端 shell，请按照以下步骤进行操作：
  # 打开 VS Code 并进入菜单栏的 “File”（文件）选项。
  # 选择 “Preferences”（首选项）并点击 “Settings”（设置）。
  # 在设置页面的搜索框中，输入 “terminal.integrated.defaultProfile.linux”。

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
- [Conda](https://conda.io/projects/conda/en/latest/user-guide/install/index.html)
- [如何现在就在 Ubuntu 20.04 用上 Fcitx 5](https://plumz.me/archives/11740/)
配置文件在`~/.config/fcitx5`,可直接复制粘贴已有文件。
  ```
  Ctrl + ; 进入剪贴板；如果刚开始只有一行，过两天可能就自己更新了，最多30行。按0选择候选词，在Ubuntu20.04上，很长一段时间都会直接退出fcitx5.后来也不知道为什么好了。
  Ctrl + . 切换到全局配置选项卡后，勾选底部的“显示高级选项”，并下滑，找到“切换全角标点”一栏。看到旁边的快捷键了吗？我这里是
  Ctrl + Alt + H：Completion is enabled.
  把 "choose key modifier"由 alt 改成 none ,作用是选词时免按alt.
  ```
  ubuntu 20.04, fcitx5，键入0，直接闪退。[可以换个桌面](https://www.jianshu.com/p/8b2cf8bb5fe0)，但还没尝试。
- [Ubuntu 20.04 安装中文输入法（百度输入法）](https://www.zhihu.com/zvideo/1276684353373384704) 22.04会出现[qt5-default not in Ubuntu 21.04](https://zhuanlan.zhihu.com/p/443006210)
### Common software
- [Feishu](https://www.feishu.cn/download)
- [Baidu Netdisk](https://pan.baidu.com/download/)
- [Sunlogin](https://sunlogin.oray.com/)
- [Open Broadcaster Software](https://obsproject.com/)
- [VLC](https://www.videolan.org/vlc/)
- [Calibre](https://calibre-ebook.com/download)
[最强大的本地电子书管理工具：Calibre 使用指南](https://zhuanlan.zhihu.com/p/34996144)
- [Locating iostream in Clang++: fatal error: 'iostream' file not found](https://stackoverflow.com/questions/54521402/locating-iostream-in-clang-fatal-error-iostream-file-not-found)
  ```bash
  sudo apt install clang
  clang --version
  sudo apt install libstdc++-12-dev
  ```
- QQ
- Zoom
- Discord
- Telegram
- Cursor
- Krita
- [Zotero+坚果云](https://blog.csdn.net/weixin_37707670/article/details/110307759)

- [编译安装gcc12-2](https://blog.csdn.net/fen_fen/article/details/129021912)
## [Learn Git Branching](https://learngitbranching.js.org/?locale=zh_CN)
```
git revert
git config --global user.name "zvvc"
git config --global user.email "zwc@outlook.lv"
git push origin zvvc

后来为了看源码在一段时间内有哪些改动，学了 log 、 show 和 diff 。
为了找到感兴趣内容所在的文件，学了 grep （指 git grep）。
因为上游用了 submodule 所以也稍微学了一下。
在网络不理想的时候，为了从镜像拉取，学了 remote 
因为手痒，想自己给项目添加内容，为了让自己写的东西纳入 git 管理，学了 commit （那时候用的还是 commit -a ，用不到 add）。
大概是这时候，第一次遇到了躲不开的配置项，也就是 config 。
从上游拉取时，为了不和自己写的东西冲突，学了 merge 、 add 和 status，后来又学了 fetch 和 rebase 。
为了提 Pull Request，也为了备份自己写的东西，学了 push 。
为了把其他分支的修改转移到当前分支，学了 cherry-pick 。
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
```bash 
git push --set-upstream origin zvvc

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
  ```bash 
  git checkout main  # 切换到主分支
  git pull origin zvvc  # 拉取合作者的更改
  git merge zvvc  # 合并合作者的更改到主分支
  git push origin main  # 推送合并后的更改到远程仓库的主分支
  ```
如果你决定拒绝合作者的更改，你可以使用以下命令回退或重置远程分支，撤销合作者的提交。这将丢弃合作者的更改，请谨慎使用，并确保在执行之前备份重要的更改。
  ```bash
  git branch -D zvvc  # 删除本地分支（仅在你确认不需要这个分支时使用）
  git push origin :zvvc  # 删除远程分支（仅在你确认不需要这个分支时使用）
  ```
请注意，在执行这些命令之前，确保你在本地仓库的正确分支上进行操作，并且仔细评估合作者的更改以确保安全和正确性。
- 修改仓库名字
请注意，更改仓库名称后，你需要更新本地仓库的远程URL以反映新的名称。
如果你在使用命令行进行Git操作，可以使用以下命令更新远程URL：
```bash
git remote set-url origin 新的仓库URL
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
用vim不是为了炫技。vim也只是一个古老的文本编辑器。
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
## 调节风扇转速
mlu370是被动散热，不外加风扇，就会掉卡。建议直接买风扇，钱能解决的问题都不是问题。

think center m930t, F12, enter setup, power, intelligent cooling, full speed噪音太大，不行。performance mode，可以work。

下面是软件控制，但不能work。
```bash
sudo apt install lm-sensors
sudo sensors-detect  # always yes
sensors
sudo service kmod start
sudo apt install fancontrol
sudo pwmconfig  # /usr/sbin/pwmconfig: There are no fan-capable sensor modules installed
```
[解決pwmconfig抓不到風扇的問題](https://www.ubuntu-tw.org/modules/newbb/viewtopic.php?viewmode=compact&order=ASC&topic_id=107514&forum=2)
这个链接也并未解决这台电脑的问题。
# 文件处理
## 如何通过bash在Linux中下载Onedrive文件
在OneDrive网页端，以chrome浏览器为例，用F12打开开发人员工具，然后在网页中选中要下载的文件点击下载按钮。在开发工具network标签下，看到新出现的项目，右击，选择copy cURL (bash)，然后在Linux terminal中粘贴，并在末尾加上 --output <文件名> 即可。
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