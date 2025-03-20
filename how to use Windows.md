# some settings
- [不花里胡哨看电脑主板支持最大内存与频率](https://blog.csdn.net/qq_45164497/article/details/126358529)

- [Windows 10 总是不打招呼就自动更新？教你如何关闭它](https://www.dians.net/thread-1745.htm)

- [win11 永久激活](https://zhuanlan.zhihu.com/p/637930518)
## shortcut
1. win + shift + s 是截图.
2. win + v 是剪切板.
3. win + Ctrl + O 是屏幕键盘.
4. Alt + Ctrl + Delete，立即终结电脑的异常状态
# some softwares
## [Zotero](https://www.zotero.org/download/)
[Zotero更改储存路径&迁移文件](https://zhuanlan.zhihu.com/p/478035708)

[zotero+坚果云](https://blog.csdn.net/weixin_37707670/article/details/110307759)
## wsl2
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
## edge
- [CSDN 代码复制限制](https://greasyfork.org/zh-CN/scripts/454012-csdn-%E4%BB%A3%E7%A0%81%E5%A4%8D%E5%88%B6%E9%99%90%E5%88%B6)
- [关闭edge选中/复制文本时显示小菜单/方框](https://blog.csdn.net/qq_45611850/article/details/121380355)
- 视频倍速
```html
右键 inspect，console。
document.querySelector('video').playbackRate = 0.9
```
## [Visual Studio Code](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)
### oh my zsh
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
## wallpaper
壁纸，传输大文件到国外。
## 蒙特卡洛算法
蒙特卡洛算法°当然算法原理很简单
一开始根本是不信，单纯是觉得好玩，报着试试看的态度，简单用python尝试了一下，但是结果确令人震惊，暴力随机居然可以模拟真实，这简直开始让我怀疑世界了，真实的世界不会也是这么随机模拟“的吧。
# Removable storage device
[U盘写保护无法格式化怎么办？](https://www.reneelab.com.cn/m/how-to-format-write-protected-usb.html)

[Windows下使用Diskpart格式化U盘](https://www.cnblogs.com/zhuxiaoxi/p/9292863.html)
# Download YouTube videos
https://www.youtube.com/watch?v=K1lQa5QsyDU

加上ss，VPN非美国节点，即可下载。
https://www.ssyoutube.com/watch?v=K1lQa5QsyDU

# 连接天猫精灵
我的天猫精灵在桌子右侧第三个抽屉。网易云音乐还能连接天猫精灵，那就好了。

# ivcam 虚拟摄像头
虽然连接的方式很多，但还是简单点好。

就用电脑释放热点，手机或者平板连接这个热点，这能确保两个设备，一定在一个局域网内。