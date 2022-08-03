# compiler-llvmir

## 编译

```
mkdir build
cd build
cmake ..
make
```

## 运行

```
./compiler [-h] [-D] [-a] [-i] [-I testcase.ir] [-S] [-v] [-o testcase.s] [-O<optlevel>] testcase.sy
```

* -h  打印命令行参数格式帮助
* -D  打印"------open------"等调试信息
* -a  打印AST
* -i  打印IR
* -I testcase.ir  输出IR到文件testcase.ir
* -S  打印汇编（该选项实际无效，始终不把汇编打印到屏幕上，而是输出到文件）
* -v  打印生成汇编过程中的调试信息
* -o testcase.s   输出汇编到文件testcase.s
* -O2 指定优化等级（不指定该选项时，默认为不优化）

#### 注意

1. testcase.sy 源语言程序文件（除第0个参数./compiler外，只允许存在这1个非选项参数）
2. 选项顺序可以随便调换，也可以随便组合

#### 示例

* 功能测试：./compiler -S -o testcase.s testcase.sy

* 性能测试：./compiler -S -o testcase.s testcase.sy -O2
* 打印AST：./compiler -D -a testcase.sy
* 打印IR：./compiler -D -i testcase.sy
* 打印AST和IR：./compiler -D -a -i testcase.sy
* 输出IR：./compiler -D -I testcase.ir testcase.sy
* 输出汇编：./compiler -D -S -v -o testcase.s testcase.sy
