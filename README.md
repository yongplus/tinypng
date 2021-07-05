# 图片压缩软件

日常开发经常会用到[tinypng.org](https://tinypng.org/)图片批量压缩，tinypng平均压缩率能达到60%，肉眼能观察到的画质损失微乎其微，对页面加载提速及体验、缩小程序包有很大帮助。

项目图片过多时，通过官方网站压缩效率低、繁琐，于是最初用go基于tinypng的API写了个CLI程序，后嫌麻烦，用Golang Qt写了个GUI程序，因Qt主要是C++写的，Go Qt无论是调试还是编译都极其慢和不方便，凭借对Qt的热爱和本着学习心态决定用C++把Go写的这套重写一遍（代码仅学习，由于工作原因，很多年没接触过C++ Qt，几乎忘光了^_^~!）。


**软件截图：**  
![截图](http://0f3.com/tinypng/Screenshot1.png)  
![截图](http://0f3.com/tinypng/Screenshot2.png)  

以下是对电商项目的商品详情页图片压缩测试数据，无论是页面大小还是访问速度的提升都很显著  
![截图](http://0f3.com/tinypng/compared.png)  



[go语言版本](https://github.com/yongplus/tinypng/blob/master/doc/Golang)  
[软件安装程序](http://0f3.com/tinypng/installer.exe)

总得来说，日常开发小工具Go Qt可以快速入门(看对象名就基本可以猜到含义)，开发效率高、容错率高，是个不错选择。
