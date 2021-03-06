# **2. Java语言基础**

---

## *2.1 标识符与关键字*

### <1>标识符

- 计算机中的变量、常量、方法、类等都需要用名字来加以识别的，这种名字就是标识符。标识符是由字母、数字或符号组成的字符串，遵循以下规则：
  1. 符号只允许下划线_和美元$符号
  2. 不能以数字开头
  3. 不能使用Java关键字
  4. 注意英文字母大小写代表不同含义
  5. 取名应遵循易于理解、便于记忆的原则

例如：
合法标识符|非法标识符
--|--
Lotus_1|A?2
wang$|3ab

### <2>Java命名规范

- 项目名：全部小写，如果项目名是多个英语单词组成，每个单词都要小写
- 包名：全部小写
- 类名：首字母大写，也就是帕斯卡命名法，首字母大写，如果类名是多个单词拼成；每个单词的首字母都要大写
- 变量名、方法名：首字母小写，也就是驼峰命名法，如果名称有多个单词组成，每个单词的首字母都要大写
- 常量名全部大写

### <3>保留字

> 保留字（关键字）是Java语言中已经被赋予特定意义的一些单词

- 不可以把这类词作为名字来用
- Java中的true、false、null都是小写，C++中大写
- Java中无sizeof运算符
- goto和const是Java编程语言中保留的*没有意义*的关键字

abstract|boolean|break|byte|case
--------|-------|-----|----|----
catch|char|class|const|continue
do|double|else|extends|false
finally|cast|default|final|while
float|for|future|generic|goto
if|implements|import|inner|instanceof
int|interface|long|native|new
null|operator|outer|package|private
protected|public|rest|return|short
static|super|switch|synchronizes|this
throe|throws|transient|true|try
var|void|volatile

---

## *2.2 Java语言的数据类型*

> - 数据类型
>   - 基本数据类型
>     - 数值类型
>       - 整数类型：  ```byte, short, int, long```
>       - 浮点数类型: ```float, double```
>     - 字符类型：char
>     - 布尔类型：boolean
>   - 复合数据类型
>     - 类类型:  class
>     - 接口类型：interface

Java语言有8种简单数据类型，分别是：```byte、short、int、long、float、double、char、boolean```
> 这8种数据类型习惯上可分为4大类型：
>
> - 整数类型：```byte、short、int、long```
> - 浮点类型：```float、double```
> - 字符类型：```char```
> - 逻辑类型：```boolean```

### <1>基本数据类型

#### [1]数值类型

##### (1)整数类型

Java编程语言中的整数类型都是有符号整数，不存在无符号整数。（与 C 和 C++不同）

byte|short|int|long
----|-----|---|----
$-2^7$|$-2^{15}$|$-2^{31}$>|$-2^{63}$
$2^7 - 1$|$2^{15} - 1$|$2^{31} - 1$|$2^{63} - 1$

>整数可用十进制、八进制或十六进制表示。首位为"0"表示八进制，首位为"0x"表示十六进制

数值|进制
----|----
5|十进制
075|八进制（十进制61）
0x9ABC|十六进制（十进制39612）

> 整型，如在其后有一个字母"L"表示一个long常量（也可小写为"l"）

##### (2)浮点类型

> `float`和`double`

- 如果一个数值常量中包含小数点或指数部分，或者其后跟有字母`F`或`f`（`float`）,  `D`或`d`（`double`），则该数为浮点数

- 如果不明确指明浮点数的类型，*浮点数缺省为`double`类型*
  - 3.14159   （`double`型浮点数）
  - 2.08E25   （`double`型浮点数）
  - 6.56f     （`float`型浮点数）

- `float`为*32位*（单精度），`double`为*64位*（双精度）

#### [2]字符型

- 关于字符型
  - `Java`中的`char`是*16位*的无符号型数据
  - 内存分配*2个字节*,占16位，最高位不用来表示符号
  - 字符必须用一对单引号括起来，如`'a', 'B'`等
  - `Java`采用*Unicode字符集*字符进行编码,每个编码2个字节
  - 与`C`语言类似，`Java`也提供转义字符，以反斜杠（`\`）开头，将其后的字符转变为另外的含义

> [!TIP]
> 例如：'A'、'!'、'9'、'好'、'\t'、'怹'、'α'

```java
public class Demo {
    public static void main (String[] args) {
        char chinaWord = '你',
        char japanWord = 'あ',
        int p1 = 36382, p2 = 38385;
        System.out.println("汉字\'你\'在Unicode表中的顺序位置" + (int)chinaWord);
        System.out.println("日语\'あ\'在Unicode表中的顺序位置" + (int)japanWord);
        System.out.println("unicode表中第20328位置上的字符是:" + (char)p1);
        System.out.println("unicode表中第12358位置上的字符是:" + (char)p2);
    }
}
```

![[alt text]](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/char.png?raw=true)

##### (1)字符集

> - 字符集是字符的*有序集合*
> - 字符集的简史
>   码|字节数
>   --|----
>   ASCII码|一个字节，使用0-127
>   ASCII码及拓展字符集|一个字节，使用0-255
>   GB2313、GBK、GBK18030、BIG5、SJIS|英文字符一个字节，0-127表示，中文字符两个字节
>   Unicode|所有字符全部使用2个字节

##### (2)中国字符集

- 在中国，大陆最常用的就是GBK18030编码，除此之外还有GBK，GB2313
- GB2312: 6763个汉字和682个其他符号
- 95年GBK符号: 1886个符号
- GBK18030: 收录了27484个汉字，同时收录了藏文、蒙文、维吾尔文等主要少数民族文字
- 按照GBK18030、GBK、GB2313的顺序，三种编码是向下兼容，同一个汉字在三种编码方案中是相同的编码

##### (3)字符型 VS 字符串

> - 值得注意的一点是，用*双引号引用*的文字，就是我们平时所说的字符串类型（`String`），它不是基本类型，而是一个对象类型（复合数据类型），`Java`是将字符串作为对象实现的.
>
> - char类型所规定的字符转义序列在字符串内同样适用，如"`three\nlines`"等.

#### [3]逻辑类型

- 逻辑类型
  - 常量：`true`，`false`
  - 变量的定义：
    使用关键字boolean来定义逻辑变量，定义时也可以赋初值：```boolean x = true, tom = false, jiafei;```
  - 小写（与`C++`不同）

- 为了提高程序的健壮性，`Java`为所有数据类型设置了默认值

数据类型|初值
-------|---
boolean|false
char|```'\000'```(空格)
byte|(byte)0
short|(short)0
int|0
long|0L
float|0.0f
double|0.0

> ```如果在一个方法中定义一个变量，Java不会为其分配默认值，就必须我们来给他初始化，否则将得到编译错误的提示```

### <2>复合数据类型

- 由用户定义的、一系列简单数据类型及其运算符组合而成
- 由类类型（`class`）和接口类型（`interface`）组成
- 例如：`String`就是由`class`定义的类类型数据

---

## *2.3 数据类型转换*

### <1> 类型转换

> - 各类型所占用的位数从短到长依次为：```(byte, short, char)--int--long--float--double```
> - 简单数据类型之间的转换又可以分为：
>   - 低级到高级的自动类型转换
>   - 高级到低级的强制类型转换

### <2>自动类型转换

- `Java`中整型、字符型和浮点型数据可以互相自动转换（低级向高级），混合运算

操作数1的类型|操作数2的类型|计算结果
-----------|-----------|-------
`byte`或`short`|`int`|`int`
`byte`或`short`或`int`|`long`|`long`
`byte`或`short`或`int`或`long`|`float`|`float`
`byte`或`short`或`int`或`long`或`float`|`double`|`double`
`char`|`int`|`int`

### <3>强制数据类型转换

> 由低级向高级可以自动转换，但是由高级向低级必须显式说明、进行强制转换

```java
(int)1.234  int b = (int)(0.2 + 0.3)
```

```java
public class Demo{
    public static void main (String args[ ]){
        int c=2200;
        long d=8000;
        float f;
        double g=123456789.123456789;
        c=(int)d;
        f=(float)g;   //导致精度的损失.
        System.out.println("c=  "+c);
        System.out.println("d=  "+d);
        System.out.println("f=  "+f);
        System.out.println("g=  "+g);
    }
}
```

---

## *2.4 运算符和表达式*

### <1>Java的运算符

> Java语言按运算符对数据的运算结果分类有算术运算符、逻辑运算符、关系运算符、赋值运算符和位运算符；按运算符运算的数据个数分类可分为一元运算符、二元运算符和三元运算符

算术运算符有五种  加`+`、减`–`、乘`*`、除`/`、取余`%`其中除减号可作为一元运算符外均为二元运算符

- 另外两个经常使用的一元运算符是
  - `i++`和`++i`
  - `i--`和`--i`

> [!NOTE]
> `int a=1, b=2;`
> `a+++b` = ***?***

### <2>语句与表达式

> - 语句是构成程序的基本单位，语句具有独立完整的含义，可以对计算机发出操作命令，每一条语句都必须以分号`;`作为结束符
> - 表达式是用运算符把操作数（变量、常量和方法）连接起来表达某种运算或含义的式子
> - 一个表达式可以同时包括多个操作，而操作的顺序由各运算符的优先级及括号来决定。其中运算符是算术运算符称为算术表达式，运算符为逻辑运算符称为逻辑表达式

### <3>语句与表达式

- 语句和表达式的区别与联系
  - 语句是程序的组成部分，表达式是语句的组成部分
  - 语句有结束符`;`，表达式没有结束符
  - 语句是针对程序而言的，表达式是数学上的计算概念
  - 算式的计算结果在=号右边，赋值语句=号在表达式左边

### <4>算术混合运算的精度

精度从"低"到"高"排列的顺序是：`byte < short < int < long < float < double`

Java将按运算符两边的操作元的最高精度保留结果的精度，例如：5/2的结果是2，要想得到2.5,  必须写成5.0/2或5.0f/2

char型数据和整型数据运算结果的精度是int。例如：`byte x=7;`那么 `'B'+x;`的结果是`int`型

### <5>运算的精度之例

```java
//算术运算测试
public class Demo {
    public static void main(String args[]){
        int a = 4;
        int b = 10;
        int d = b * ++a;
        int e = (a / (++b));
        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("d = " + d);
        System.out.println("e = " + e);
    }
}
```

### <6>位运算符

运算符|运算|举例|含义
-----|----|---|---
~|位反|~x|将x按位取反
&|位与|x&y|x、y逐位进行与操作
\||位或|x|y|x、y逐位进行或操作
^|位异或|x^y|x、y 逐位进行 相同取0 相异取1
<<|左移|x<<y|x向左移动，位数是y
>>|右移|x>>y|x向右移动，位数是y
>>>|不带符号右移|x>>>y|x向右移动，位数是y，空位补0

![位操作](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/bit.png?raw=true)

### <7>二元算术运算符、逻辑运算符和位运算符

运算符|运算|举例|含义
-----|----|---|---
+=|加法|x += y|x = x + y
-=|减法|x -= y|x = x - y
*=|乘法|x *= y|x = x * y
/=|除法|x /= y|x = x / y
%=|取余|x %= y|x = x % y
&=|与|x &= y|x = x & y
\|=|或|x \|= y|x = x \| y
^=|异或|x ^= y|x = x ^ y
<<=|左移|x <<= y|x = x << y
>>=|右移|x >>= y|x = x >> y
>>>=|不带符号右移|x >>>= y|x = x >>> y

### <7>运算符优先级

运算符|描述|优先级|结合性
-----|----|-----|----
. [] ()|域、数组、括号|1|从左至右
++ -- - ! ~|一元操作符|2|从右至左
* / %|乘、除、取余|3|从左至右
+ -|加、减|4|从左至右
<< >> >>>|位运算|5|从左至右
< <= > >=|逻辑运算|6|从左至右
== !=|逻辑运算|7|从左至右
&|按位与|8|从左至右
^|按位异或|9|从左至右
\||按位或|10|从左至右
&&|逻辑与|11|从左至右
\|\||逻辑或|12|从左至右
?:|条件运算符|13|从右至左
= *= /= %= += -= , <<= >>= >>>= &= ^= !=|赋值运算符|14|从右至左

### <8>运算例程

```java
//通过对给定常数进行大小比较，将比较结果作为逻辑值输出
public class Demo {
    public static void main(String args[]){
        int x = 15;
        int y = 7;
        boolean c = (x>y);
        boolean d = ((float)x / y == (double)x / y);
        System.out.println("c = " + c);
        System.out.println("d = " + d);
    }
}
```

### <9>位运算应用

- "清零"：和`0`按位"与"
- "乘２"：`<<`1位
- "除２"：`>>`1位
- "交换变量"：按位异或`^`
- "加密"

> [!NOTE]
> *交换变量*
>
> a = 10100001, b = 00000110
>
> a = a ^ b;    //a = 10100111
>
> b = a ^ b;    //b = 10100001
>
> a = a ^ b;    //a = 00000110

加密

```java
public class Demo {
    public static void main(String [] args) {
        char a1 = '合', a2 = '肥', a3 = '工', a4 = '大';
        char secret = '0';
        a1 = (char)(a1 ^ secret);         //21512 ^ 54
                     //(101010000001000 ^ 110110)
        a2 = (char)(a2 ^ secret);         //32933
        a3 = (char)(a3 ^ secret);         //24037
        a4 = (char)(a4 ^ secret);         //22823
        System.out.println("密文:" + a1 + a2 + a3 + a4);
        a1 = (char)(a1 ^ secret);
        a2 = (char)(a2 ^ secret);
        a3 = (char)(a3 ^ secret);  
        a4 = (char)(a4 ^ secret);
        System.out.println("原文:" + a1 + a2 + a3 + a4);
    }
}

```

---

## *2.5 程序流程控制*

### <1>基本控制结构

- ***顺序结构***就是按照指令的先后顺序依次执行
- 为实现***分支结构***程序设计，`Java`语言提供了条件分支语句 `if` 和多重分支语句`switch`，根据它们所包含的逻辑表达式的值决定程序执行的方向
- ***循环结构***的程序可以对反复执行的程序段进行精炼，用较少的语句执行大量重复的工作。`Java`提供了`for` 、`while`和`do-while`三种循环语句

### <2>分支结构

> **分支结构**，是在两条或多条（两条以上）执行路径中选择一条执行的控制结构

#### [1]if 语句格式

```java
if (条件表达式) {
    语句组；
}
```

> [!TIP]
> 括号中的条件是逻辑表达式，其值为true执行语句块1，否则直接执行if 语句的下一条语句。花括号中的多个语句被看成是一条复合语句

例：

```java
//本程序从命令行输入两个数据进行比较，
// 输出较大的那个数
public class Demo {
    public static void main(String args[]) {
        int x,y = 0;
        //读入命令行参数
        x = Integer.parseInt(args[0]);
        y = Integer.parseInt(args[1]);
        if (x >= y) System.out.println("x = " + x);
        else System.out.println("y = " + y);
    }
}

```

> [!NOTE]
>
> - 程序总结：
>   - if 的用法
>   - String类型 args[ ] 的使用
>   - IDE环境与命令行环境（命令行参数）
>   - 程序的功能性、完善性、良好用户交互能力

- if-then-else

```java
// if…else语句格式
if (条件) {
    (语句块1)
}
else {
    (语句块2)
}
```

> [!NOTE]
>
> - 括号中的条件是逻辑表达式，
>   - 其值为 true 执行语句块1
>   - 其值为 false 执行语句块2
> - 两种情况在完成各自的任务之后，于if的下一条语句汇合

例：求三个数中的最大者

```java
//给出任意三个数，通过使用if语句嵌套，将它们
//按从小到大排序
import javax.swing.JOptionPane;
public class Demo {
    public static void main(String args[]){
        String str;
        double x, y, z, t;
        str = JOptionPane.showInputDialog("请输入第一个数");
        x = Double.parseDouble(str);
        str = JOptionPane.showInputDialog("请输入第二个数");
        y = Double.parseDouble(str);
        str = JOptionPane.showInputDialog("请输入第三个数");
        z = Double.parseDouble(str);
        if (x > y){
            t = x;
            x = y;
            y = t;
            if (x > z){
                t = x;
                x = z;
                z = t;
            }
            else if (y > z){
                t = y;
                y = z;
                z = t;
            }
        }  
        else if (x > z) {
            t = x;
            x = z;
            z = t;
            if (y > z) {
                t = y;
                y = z;
                z = t;
            }
        }
        else {
            t = y;
            y = z;
            z = t;
        }
   System.out.println("最小值 ＝ " + x);
   System.out.println("中间值 ＝ " + y);
   System.out.println("最大值 ＝ " + z);
   System.exit(0);
  }
}


```

#### [2]Switch 语句

```java
switch(表达式) {
    case 值1: 语句块1; break;
    case 值2: 语句块2; break;
    case 值3: 语句块3; break；
        ......
    case 值n: 语句块n; break；
    default: 语句块n+1;
}
```

> 1. switch 语句中的表达式的数据类型可以是byte、char、short、int 类型
> 2. 根据表达式值与case语句后面的匹配情况决定程序执行的分支
> 3. 每个case 语句都要有break语句
> 4. 不匹配的情况执行 default 语句

Switch语句实例：

```java
//通过键盘输入月份，输出相应月份的英文单词
//注意月份是在命令行中给出的
public class Demo {
    public static void main(String args[]){
        int month;
        month = Short.parseShort(args[0]);
        switch(month){
            case 1: System.out.println("January"); break;
            case 2: System.out.println("February"); break;
            case 3: System.out.println("March"); break;
            case 4: System.out.println("April"); break;
            case 5: System.out.println("May"); break;
            case 6: System.out.println("June"); break;
            case 7: System.out.println("July"); break;
            case 8: System.out.println("August"); break;
            case 9: System.out.println("September"); break;
            case 10: System.out.println("October"); break;
            case 11: System.out.println("Novenber"); break;
            case 12: System.out.println("December"); break;
            default: System.out.println("Input Number Error!!"); break;
        }
    }
}
```

### <3>循环结构

***循环结构***是程序中一种重要的基本结构，是指：
> 在一定的条件下反复执行某段程序，被反复执行的这段程序称为*"循环体"*

- `Java`中有三种语句来实现循环结构，分别是`while`，`do-while`和 `for` 语句

#### [1]while语句

- while语句的格式如下

```java
while (条件表达式) {
    循环体语句;
}
```

- 在循环刚开始时，会计算一次"条件表达式"的值
  - 当条件为假时，将不执行循环体，直接跳转到循环体外，执行循环体外的后续语句
  - 当条件为真时，便执行循环体。每执行完一次循环体，都会重新计算一次条件表达式，当条件为真时，便继续执行循环体，直到条件为假才结束循环

#### [2]do-while语句

- do-while语句的格式如下

```java
do {
    循环体语句；
} while (条件表达式)
```

> [!TIP]
>
> - do-while循环与while循环的不同在于：
>   - 它先执行循环中的语句，然后再判断条件是否为真，如果为真则继续循环
>   - 如果为假，则终止循环
>   - 因此，do-while循环至少要执行一次循环语句

#### [3]for语句

> for语句是三个循环语句中功能最强，使用最广泛的一个

- for语句的格式如下

```java
for (表达式1; 表达式2; 表达式3) {
    循环体语句;
}
```

- 表达式1一般是一个赋值语句，它用来给循环控制变量赋初值
- 表达式2是一个布尔类型的表达式，它决定什么时候退出循环
- 表达式3一般用来修改循环变量，控制变量每循环一次后按什么方式变化

三个部分之间用"; "分开

> - for语句的执行过程
>   1. 在循环刚开始时，先计算表达式1，在这个过程中，一般完成的是初始化循环变量或其它变量
>   2. 根据表达式2的值来决定是否执行循环体。表达式2是一个返回布尔值的表达式，若该值为假，将不执行循环体，并退出循环；若该值为真，将执行循环体
>   3. 执行完一次循环体后，计算表达式3，在这个过程中一般会修改循环变量
>   4. 转入第（2）步继续执行

#### [4]循环嵌套

- 循环嵌套是指在循环体中包含有循环语句的情况
- 三种循环语句即可以自身进行嵌套，也可以相互进行嵌套构成多重循环
- 多重循环自内向外展开，即先执行内循环，后执行外循环。多重循环不允许相互交叉

```java
//分别输出1!、2!、3!、...6! 以及它们的和
public class Demo {
    public static void main(String args[]) {
        long sum=0;
        for(int i=1;i<=6;i++) {
            long m=1;
            for(int j=1;j<=i;j++)
                m*=j;
            System.out.println(i+"!="+m);
            sum+=m;
        }
        System.out.println("1!+2!+3!+...+6!=" +sum);
    }
}
```

#### [5]跳转语句

跳转语句用来实现循环执行过程中的流程转移。在`switch`语句中使用过的`break`语句就是一种跳转语句。在`Java`语言中，有两种跳转语句：`break`语句和`continue`语句

- `Java`语言中，可用`break`和`continue`控制循环的流程
  - `break`用于强行退出循环，不执行循环中剩余的语句
  - `continue`则停止执行当前的循环，开始新的循环
- `break`语句和`continue`语句都有两种使用形式
  - 不带标号的`break`语句和`continue`语句
  - 带标号的`break`语句和`continue`语句
  - 只使用`break`只能退出内循环；要想达到从内循环体中直接跳转出外循环的目的，必需与`label`标号语句连用

- 带标号的`break`与`continue`示例

```java
public class Demo {
    public static void main(String[] args) {
        System.out.println("i j");
        search:for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 50; j++) {
                if (j == 3)
                    break search;
                System.out.println(i + " " + j);
            }
        }
    }
}
```

```java
public class Demo {
    public static void main(String[] args) {
        System.out.println("i j");
        search:for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 50; j++) {
                if (j == 3)
                    continue search;
                System.out.println(i+" "+j);
            }
        }
    }
}
```

> [!NOTE]
> 下面代码会产生什么样的输出？

```java
public class TestSwitch {
    public static void main(String [] args){
        char letter = 'A' ;
        switch (letter){
            case 'A':
            case 'a':
                System.out.println("Some kind of A.");
            case 'B':
            case 'b':
                System.out.println("Some kind of B.");
                break;
            default:
                System.out.println("Something else.");
                break;
        }
    }
}
```

上一篇：
> [!div class="nextstepaction"]
> [Java概论](Java概论.md)

下一篇：
> [!div class="nextstepaction"]
> [Java面向对象基础](Java面向对象基础.md)
