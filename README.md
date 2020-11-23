## toy-compiler

用来应付傻逼编译原理课设的玩具编译器

实现过程极大地借鉴了带佬 [@Rabbit](https://github.com/ttzztztz) 的课设代码 [地址 >>](https://github.com/ttzztztz/Compiler-Course-Design)，没有他代码就写不完力（

因为是个半成品，然后很多地方还是东拼西凑的，所以功能也没实现多少：

- 没有实现一元运算符运算和布尔值字面量
- 没有实现任何维度的数组
- 没有实现行注释和快注释
- 没有实现 for / for-each 循环
- 没有实现任何优化
- 没有实现 LLVM IR 到机器代码的转化（懒

差不多得了 =_=||

### 实验环境

- WSL Debian 10 (based on WSL 2, Windows 10 Pro 20H2 19042.630)
- Jetbrains CLion 2020.2.1 Build #CL-202.6948.80
- GNU GCC version 8.3.0 (Debian 8.3.0-6)
- GNU Bison 3.3.2
- LLVM 10.0.1 (on Debian 10)

- flex 2.6.4
- CMake version 3.13.4

### 使用方法

#### 使用脚本

在 `code/script/` 目录下有实用脚本，用于完成特定功能：

- `clear.sh` ：清除 Flex 和 Bison 生成的文法/语法处理器和临时文件，<font color="red">项目可能会因此而不能编译</font>
- `generate.sh` ：使用 Flex 和 Bison 重新生成文法/语法处理器的源文件
- `setup.sh` ：设置环境，安装执行本项目所需的必要依赖（仅限 Linux 环境）
- `install.sh` ：加载 CMake 项目，并产生临时文件，用于下一步的构建
- `build.sh` ：构建二进制文件，在此之前需要先加载 CMake 项目才可以编译
- 测试脚本、运行脚本施工中……

您也可以在项目的根目录中使用 `bash start.sh [option]` 来快捷执行上面的操作

### 测试用例

测试用例如下：

```txt
int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 114514;
    float b = 3.4 + 5.6;
    if (b > 1.2) {
        print_int(1919810);
    }

    while (a > 0) {
        if (add(a, 1) % 2 == 1) {
            print_int(a);
            break;
        }
        a = a - 1;
    }
    return 0;
}
```





