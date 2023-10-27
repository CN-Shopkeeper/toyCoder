## ToyCoder

一个极其无聊的小作业，要求 C++在不使用 STL 的情况下，将一篇英文文章进行编码（对所有字符打乱顺序、字符的绝对位置增加位移得到相对位置），并将编码结果，按照字符-相对位置的方式存入到二进制文件中；同时还需要完成一个解码器能够对该二进制文件进行解码还原原来的文章。

## 编译运行

本作业基于 CMake

```shell
cmake -S . -B cmake-build
cmake --build cmake-build
```

## 文件目录

- `cmake`: 存放 cmake 脚本
- `data`: 存放输入输出数据
- `src`: 源代码
- `CMakeLists.txt`: cmake 配置文件
