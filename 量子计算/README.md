## 前言

量子计算有别于传统二进制的计算方法。量子计算机的概念最早是由著名物理学家费曼于1981年提出,现在量子计算是当今世界最具颠覆性的技术之一感兴趣的同学来看看。


### 相关开源仓库
MindQuantum仓库地址:[gitee.com/mindspore/mindquantum](https://gitee.com/mindspore/mindquantum)

**简介**
MindQuantum是基于昇思MindSpore开源深度学习框架和HiQ量子计算云平台开发的通用量子计算框架，支持多种量子神经网络的训练和推理。

win系统安装方法：
1. 安装MindSpore
> 小白注意(大佬忽略)，如果之前安装了python请全部卸掉，只安装一个版本即可，只要是防止小白装错地方又不会处理。

安装MindSpore视频教程：[点击观看](https://www.bilibili.com/video/BV13e411P7tT/?share_source=copy_web&vd_source=5cce33ff95191f8ec5e6ea0eb4f41f15)


2. 安装MindQuantum
- 确保MinGW-W64和CMake的版本>= 3.18.3,并将他们添加到path上


- 安装了protobuf,没装的去[官网](https://github.com/protocolbuffers/protobuf/releases/)下，装完添加到path上

  在黑框输入pip install mindquantum

### 使用

在桌面新建一个text.py文件试运行量子计算程序：


```
from mindquantum import *
import numpy as np

encoder = Circuit().h(0).rx({'a0': 2}, 0).ry('a1', 1)
print(encoder)
print(encoder.get_qs(pr={'a0': np.pi / 2, 'a1': np.pi / 2}, ket=True))
```

你将得到

```
q0: ────H───────RX(2*a0)──

q1: ──RY(a1)──────────────

-1/2j¦00⟩
-1/2j¦01⟩
-1/2j¦10⟩
-1/2j¦11⟩
```

![程序](img/%E6%B5%8B%E8%AF%95.png)