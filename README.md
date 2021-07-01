# 图片压缩软件

- 日常开发经常会用到[tinypng.org](https://tinypng.org/)图片批量压缩，tinypng平均压缩率能达到60%，肉眼能观察到的画质损失微乎其微，对页面加载提速及体验、缩小程序包有很大帮助。
项目图片过多时，通过官方效率低、繁琐，于是最初用go基于tinypng的API写了个CLI程序，后嫌麻烦，用Golang Qt写了个GUI程序，因Qt主要是C++写的，Go Qt无论是调试还是编译都极其慢和不方便，带着学习心态决定用C++把Go写到重写一遍（代码仅学习，由于工作原因，N年没接触过C++ Qt，几乎忘关了^_^~!）。


- 软件截图：
![截图](https://github.com/yongplus/tinypng/blob/master/doc/demo.png?raw=true)


[go语言版本](https://github.com/yongplus/tinypng/blob/master/doc/Golang)

[软件安装程序](https://github.com/yongplus/tinypng/blob/master/x64/installer.exe?raw=true)

总得来说，日常开发小工具Go Qt可以快速入门(看对象名就基本可以猜到用途)，开发效率高、容错率高，是个不错选择。
