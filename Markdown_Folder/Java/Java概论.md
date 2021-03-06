# **1. Java概论**

---

## *1.1 特点*

- 一般特点
  - 简单性
  - 面向对象技术
  - 分布性
  - 健壮性
  - 安全性
  - 体系结构中立
  - 可移植性
  - 解释执行
  - 高性能
  - 多线程
- 重要特点
  - 平台无关性
  - 完全的面向对象

---

## *1.2 主方法的标准格式*

> `public static void main(String[] args)`

```java
public   指明这个 main 方法可以被所有的对象使用 (can be called by any object)

static   指明这个 main 方法是一个类方法

void     指明这个 main 方法不返回任何值

String[] args  是一个命令行参数
```

---

## *1.3 注释*

- `/* text */`, 编译器忽略从 /* 到 */的所有文字

- `/** documentation */`, 用于自动生成代码说明文档，编译器忽略文档documentation注释的所有文字

- `// text`, 编译器忽略//之后本行的所有文字

---

## *1.4 基本输入输出*

> 输出
> `System.out.println("Hello World!");`
>
> 输入
> ~~`System.in.read();`~~
> 不好用，用 `Scanner` 代替

```java
import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextInt();      //读取整型数据
        scanner.nextDouble();   //读取浮点型数据
        scanner.next();         //读取字符串数据
    }
}
```

下一篇：
> [!div class="nextstepaction"]
> [Java语言基础](Java语言基础.md)
