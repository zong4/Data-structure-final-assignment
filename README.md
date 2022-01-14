# 文件介绍

##  Cpp

###  Library_client

这是一个用Map容器实现的书库管理系统，可以直接运行AutoLib.cpp。

### Library_new

这是自己写的，实现了对购物车，书库以及收藏夹的基础功能。

#### UML.txt

这是PlantUML的画图代码。

### Test

这是用来生成.so文件的目录。

## Test

这是用来测试Ctypes的目录（用Ctypes调用.so文件），关于Ctypes可以查看[此文章](https://zong4.github.io/2022/01/05/Ctypes/)。

# 功能实现

原本预期功能是用C++实现基础功能后，构造接口函数并用Ctypes编译成.so文件，在Python中运行.so文件，用Flask将输出显示到网页上，同时实现按钮与接口函数的配对，从而将整个课设可视化。

但是由于Ctypes对C++类的支持不太完善，故没有成功，只能在控制台上实现比较简陋的控制界面。
