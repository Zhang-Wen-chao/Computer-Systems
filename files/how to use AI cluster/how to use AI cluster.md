# instruction
If you want to use the cluster , you have to connecte the school network.
每个用户的家目录在/public/home/$USERNAME下，限额1TB，用于存放软件、计算数据、基础环境等。

[如何使用SLURM？](https://zhuanlan.zhihu.com/p/345387783)
## 北大手册
https://hpc.pku.edu.cn/_book/

```shell
查看自己还有多少空间
df -h .
```
## jjp让我跑的代码
https://github.com/ml-jku/hti-cnn
```shell
python main.py --config ../configs/gapnet.json --gpu 0 --j 1 --training.batchsize 1
```

# 申请显卡并测试torch和cuda
critical : ai_gpu08~60，每个用户限制运行20个作业，限制提交40个作业，每个作业最大运行时长为15天，每个用户限制使用12张显卡
critical_a40 : ai_gpu01~07/sist-a40-06~09，每个用户限制运行20个作业，限制提交40个作业，每个作业最大运行时长为10天，每个用户限制使用8张显卡

不要一开始就用run.slurm, 首先要salloc 一张卡 debug成功。
ai_gpu26-35，都是NVIDIA TITAN RTX，24GB显存。
```shell
salloc -N 1 -n 10 --time=2-0:0:0 -p critical --gres=gpu:1 

salloc -N 1 -n 10 --time=9-0:0:0 -p critical --gres=gpu:NVIDIATITANRTX:1 

salloc -N 1 -n 10 --time=9-0:0:0 -p critical --gres=gpu:4 --nodelist=ai_gpu28

salloc -N 1 -n 10 --time=9-0:0:0 -p critical_a40 --gres=gpu:NVIDIAA40:1

salloc -N 1 -n 10 --time=9-0:0:0 --gres=gpu:NVIDIAA40:1

salloc -N 1 -n 10 --time=9-0:0:0 -p critical --gres=gpu:TeslaM4024GB:1 

salloc -N 1 -n 10 --time=9-0:0:0 -p normal --gres=gpu:1 --nodelist=sist_gpu63

nvcc -V
nvidia-smi
ssh -CY gpu29 //转发可视化窗口
python -c "import torch;print (torch.cuda.is_available ());print (torch.__version__);import torchvision;print(torchvision.__version__)"

## The function of each environment
py38,torch=1.7.1 , for DiffuStereo.
py39,torch=1.9.0 , for diffusiondet.

paddlepaddle
python tools/infer.py -c configs/rtdetr/rtdetr_r50vd_6x_coco.yml -o weights=https://bj.bcebos.com/v1/paddledet/models/rtdetr_r50vd_6x_coco.pdparams --infer_img=bus.jpg
```

[【小白教学】如何用YOLOv7训练自己的数据集](https://zhuanlan.zhihu.com/p/547878330)

[Train YOLOv8 on Custom Dataset – A Complete Tutorial](https://learnopencv.com/train-yolov8-on-custom-dataset/)

[ImageNet 2012数据集](https://www.jianshu.com/p/0265226d7b08)

### detectron2
```shell
python demo.py --config-file ../configs/COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml \
  --input /public/home/zhangwch2022/Pytorch_implementation/detectron2/demo/input1.jpg \
  --output /public/home/zhangwch2022/Pytorch_implementation/detectron2/demo/output2.jpg \
  --opts MODEL.WEIGHTS /public/home/zhangwch2022/Pytorch_implementation/detectron2/demo/model_final_f10217.pkl \

python ./tools/train.py \
  --config-file ./configs/COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_1x.yaml \
  --num-gpus 1 SOLVER.IMS_PER_BATCH 2 SOLVER.BASE_LR 0.0025
```
# 提交作业
#!/bin/bash
#SBATCH --job-name=yolov7
#SBATCH --partition=critical_a40
#SBATCH --time=2-00:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=16
#SBATCH --mem-per-cpu=10G
#SBATCH --gres=gpu:NVIDIAA40:4
#SBATCH --mail-type=fail
#SBATCH --mail-user=wczhang@mail.bnu.edu.cn
#SBATCH --output=../output/%j.out
#SBATCH --error=../output/%j.err

source activate yolov7

./run.sh
# 下载软件
### nccl
```shell
make -j10 BUILDDIR=/public/home/zhangwch2022/software/nccl  src.build CUDA_HOME=/public/home/zhangwch2022/software/cuda-11.8 NVCC_GENCODE="-gencode=arch=compute_75,code=sm_75"
```
nccl我还没完全理解，安装的时候和cudnn操作一样，复制到cuda下面。
python -c "import torch;print(torch.cuda.nccl.version())"
### onnxruntime
```shell
conda install -c conda-forge onnxruntime
```

### 安装GLIBC的失败经历
```shell
<!-- GLIBC_2.18 configure 不支持make 4.xx -->
https://zhuanlan.zhihu.com/p/397911151
<!-- LD_LIBRARY_PATH shouldn't contain the current directory when *** building glibc-2.14 -->
https://zhuanlan.zhihu.com/p/165346316

5月2日晚上22：57，在武晓涛的激励下，再次
../configure  --prefix=/public/home/zhangwch2022/software/glibc-2.37 --enable-add-ons --disable-avx512 --disable-multi-arch --disable-sysconfig
make
5月3日13：02
make install
失败
```

## 反向代理, 在集群上的GPU上用jupyter
```shell
stable diffusion webui用这个
ssh -CNfR 8086:localhost:7860 login02  #转发GPU端口到本地
10.15.89.191:8085
10.15.89.192:8086

#### First, on compute node, e.g. sist_gpu42, choose a [port] like 8008 or else
ssh -CNfR [port]:sist_gpu42:[port] login01

ssh -CNfR 35135:ai_gpu08:35135 login02
#### Then, on your own computer, start a cmd/terminal and set
ssh -L [port]:127.0.0.1:[port] [username]@10.15.89.191 -N

ssh -L 35135:127.0.0.1:35135 zhangwch2022@10.15.89.192 -N
#### On compute node, start jupyter with specified port
jupyter notebook --port [port] --ip=0.0.0.0

jupyter notebook --port 35135 --ip=0.0.0.0
#### Finally, visit 10.15.89.191:[port] on your web browser.
just Ctrl+click the website that terminal gives you

#### 如何在Jupyter应用中添加、删除虚拟环境
https://zhuanlan.zhihu.com/p/287001294
cd .conda/envs/yolov8
python -m ipykernel install --user --name yolov8 --display-name YOLOv8
python -m ipykernel install --user --name zhangwch2022-kId7UiNb --display-name kId7UiNb
```

### 武晓涛尝试的tensorboard
```shell
本地终端依次运行
ssh -L 6006:127.0.0.1:12345 zhangwch2022@10.15.89.192 -p 22112
不是，我通过第一个命令 从本地命令行进入到了服务器环境
conda activate eva3d  #切换到有tensorboard的环境
进入目录
tensorboard --logdir=log --port=12345
然后访问http://localhost:6006/
```
## 小技巧
### 文本处理
```shell
sed -i -e '1s/^/TangWei, /' -e 'N;s/n//' *.txt
```
