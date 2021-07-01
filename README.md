# tinypng

平常开发经常会用到[tinypng.org](https://tinypng.org/)图片批量压缩，tinypng平均压缩率能达到60%，肉眼能观察到的画质损失微乎其微，对页面加载提速及体验、缩小程序包有很大帮助。
于是最初用go基于tinypng的API写了个CLI程序，后嫌麻烦，用Golang Qt写了个GUI程序，因Qt主要是C++写的，Go Qt无论是调试还是编译都极其慢和不方便，带着学习心态决定用C++把Go写到重写一遍。


