# **3. Java面向对象基础**

---

## *3.1 面向对象概型*

### <1>面向对象概念

- *面向过程*：分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一个一个依次调用函数
- *面向对象*：把构成问题事物分解成各个对象，建立对象的目的不是为了完成一个步骤，而是为了描叙某个事物在整个解决问题的步骤中的行为

---

## *3.2 类的定义*

### <1>类和对象

> - 类：就是分类标准
>
>   - 公司招聘启事的条件
>     - 年龄、性别、籍贯、是否党员（特征）
>     - 熟悉Java编程、数据库、Web开发（能力）
>   - 两部分构成
>     - 属性（变量、变量）
>     - 方法（函数、能力）
>
> - 对象是类的一个实例
>   - 例子：公司根据招聘启事招聘的员工

> [!NOTE]
>
> - 类是抽象的，类描述了对象的属性和行为。
> - 对象是具体的，对象是类的一个实例。

### <2>抽象

> - 抽象：将具体的实例转化为类
>
>   - 描述出分类标准
>   - 将关键信息提取出来并进行建模
>   - 方法的抽象、属性的抽象
>
> - 抽象是类定义必须具备的能力，抽象是面向对象思想中最重要的能力
>   - 招聘什么样的人员，最考虑一个管理者的能力
>   - 人们能够解决问题的复杂性直接取决于抽象的类型和质量
>
> - 在编程之前一定要好好思考，多做分析、多做设计

> [!TIP]
> 面向对象分析 -> 面向对象设计 -> 面向对象编程

### <3>类的定义

- 类的定义包含两部分：
  - 类的说明：由class关键字和类名组成
  - 类的实体：成员变量的定义和成员方法的定义

>类定义的格式

```java
[ 类修饰符] class  类名 [ extends  父类名 ][ implements  接口名 ] {
     成员变量定义；
     方法定义；
}
```

- 类名的第一个字母要大写，类体要用花括号{}括起来

- 成员变量的定义和成员方法的定义方法和C语言中变量和方法的定义类似

### <4>类的应用

#### [1]类的实例化-对象的产生

- 定义对象的引用
- 采用new关键字实例化对象

> [!IMPORTANT]
> 所有复杂类型对象的产生都要分为这两步

创建类对象的一般形式

```java
类名 对象变量 = new  类名(参数1，参数2，…);
       或者
类名 对象变量；
对象变量 = new 类名(参数1，参数2，…);
```

#### [2]对象的使用

对象产生后可以通过对象名和"."操作符调用对象的变量和方法

### <5>实践 – 类的定义与实例化

- 定义一个People类，包括
  - 两个成员属性：姓名name，年龄age
  - 成员方法 setInfo ，供外部调用，设置两个成员属性的值
  - 成员方法 showName，供外部调用，返回"姓名"的值

- 在Demo类中
  - 定义主方法，构建People类对象，调用setInfo和showName方法

```java
class People {
    int age;
    String name;
    void setInfo(int myage, String myname) {
        age = myage;
        name = myname;
    }
    String showName() {
        return "["+ age + ", " + name + "]";
    }
}
```

```java
public class Demo {
    public static void main(String args[]) {
        People someguy = new People();
        someguy. setInfo( 18,  "SUN" );
        System.out.println(someguy.shownNme());
    }
}
```

### <6>对象的初始化和构造方法

构造方法是一个类方法中方法名与类名相同的类方法，它的作用是当使用new关键字创建一个对象时，自动调用并对新建对象进行初始化操作

> - 构造方法的特点
>   - 构造方法与类名相同
>   - 构造方法没有返回值，不定义返回类型
>   - 构造方法可以重载，针对参数数量和类型定义多个同名构造方法
>   - 构造方法不能由编程人员显式地直接调用，它是在对象创建时由new 运算符自动调用的
>   - 构造方法只用来对类实例进行初始化，目的在于简化初始化操作

> [!IMPORTANT]
> 在Java中，对象的创建和初始化是统一的——两者缺一不可

### <7>构造方法—构造方法的作用

- 构造方法的作用
  - 对象初始化
  - 引入更多的灵活度（变量赋值或更复杂的操作）

> - 每个类都至少有一个构造方法，如果程序员没有为类定义构造方法，系统会自动为该类生成一个默认的构造方法
>   - 默认构造方法的名字与类名相同，它的参数列表和方法体均为空，自动将所有实例变量初始化为默认值(数值型为0，布尔型为false，字符型为'\u0000'，对象型为null)

- 一旦定义了自己的构造方法，默认构造方法将不再起作用

### <8>static类成员变量和类成员方法

> - static修饰的成员变量为类成员方法、也叫静态变量
>   - 保存在内存区的公共存储单元中，而不是保存在某个对象的内存区中。任何一个类对象在访问它时都会得到相同的数值
>   - 如果某一个类对象对它进行了修改，所有对象的此成员变量也都做了修改
>   - 可以通过类名调用静态变量
>
> - static修饰的成员方法为类成员方法、也叫静态方法
>   - 静态方法属整个类，不用进行实例化操作
>   - 静态方法只可以使用类中的静态成员，不能使用非静态成员
>   - 可以通过类名调用静态方法

### <9>Code - static成员变量

> [!IMPORTANT]
> `Static`类只可以使用`Static`变量

```java
//  定义一个学生档案类，包括学生姓名、性别和所在学校
//  使用static修饰成员变量
class Student {
    String name;
    String  sex;
    static String school="合肥工业大学";
}
public class Test_Demo {
    public static void main(String args[]) {
        Student stu1=new Student();
        Student stu2=new Student();
        stu1.name="李明 ";
        stu1.sex="男 ";
        stu2.name="张敏 ";
        stu2.sex="女";
        //对类成员变量赋值
        Student.school="安徽大学";  
        System.out.println(stu1.name+"  "+stu1.sex+"  "+stu1.school);
        System.out.println(stu2.name+"  "+stu2.sex+"  "+stu2.school);
    }
}
```

---

## *3.3 Java常用类*

> Java常用类

常用类|类名
-----|---
字符串处理类|String类
基本数据类型包装类|Byte、Integer、Short 、Long、Float、Double、Character
数学计算类|Math、BigInteger 、Random
日期处理类|Date、Calendar

### <1>字符串

> 字符串是字符组成的序列，是编程常用的数据类型。字符串分为常量和变量

- 字符串常量是指其值保持不变的量，使用双引号括起来的字符序列
- 字符串变量要通过String 类来实现，需要声明和初始化
- String类在java.lang包中，java.lang包中的类被默认引入，可以直接使用

> [!TIP]
>
> 声明格式: String 字符串变量;
> 初始化: 字符串变量 = new String();
> 合并使用: String 字符串变量 = new String();

```java
S1 = " wang san ";
S2 = "is a student";
System.out.println(s1+s2);
```

> [!NOTE]
> 运算符'+'的作用是将前后两个字符串连接起来

### <2>字符串操作

类名|类的作用
----|------
length()|返回字符串长度
char charAt(int index)|返回字符串中第index个字符
int indexOf(char ch)|返回字符串中字符ch第一次出现的位置
int indexOf(String str,int index)|返回值为从字符串的第index位置开始，子串str第一次出现的位置
subString(int index1 ,int index2)|返回的是从字符串的第index1位置开始到index2位置结束的子串
String[] split(String regex)|根据传入的参数字符串分割字符串

示例

```java
String s=new  String();
s="I am a student.";
s.length()的值为15
s.charAt(7)的值为s
s.indexOf('a') 其值为2
    注意字符串从0计数
    找不到其值为-1
s.indexOf("stu",0)的值为7，
s.indexOf("stu",9)的值为-1
s.subString(7,13)的值为"studen"
```

### <3>字符串比较

字符在计算机中是按照Unicode编码存储的，两个字符串的比较实际上是字符串中对应字符编码的比较。从首字符开始逐个向后比较对应字符，当发现了一对不同的字符或到字符串末尾，两个字符串比较结束

- 常用的成员方法
  - `equals(Object obj)`本字符串与obj字符串比较，相等返回true,不等返回false
  - `equalsIgnoreCase(String str)`字符串比较，忽略大小写
  - `compareTo(String str)`返回值为整型，本字符串大于str取正值，小于取负值，相等取0值

示例

```java
String s = new String("student");
s.equals("Student")的值为false
s.equalsIgnoreCase("Student")的值为true
s.compareTo("five student")的值为正
s.compareTo("two student")的值为负
```

### <4>String类实战

> 读入一字符串，分别输出大写字符数、小写字符数 和非英文字符数。 怎么统计 ？
>
>给定字符串`"aajava哈哈JAVA&（#@%￥java嘿嘿javaok"`查找出现`"java"`子串的次数?

```java
LowCase: abcdefghijklmnopqistuvwxyz
UpperCase: ABCDEFGHIJKLMNOPQISTUVWXYZ
```

### <5>基本数据处理类

> 对于每一种基本数据类型，Java分别提供相应的类对其进行封装，以便提供更强大的数据处理能力

基本数据类型|数据类型类
----------|---------
byte|Byte
short|Short
int|Integer
long|Long
char|Char
boolean|Boolean
float|Float
double|Double

方法|返回值类型|返回值
---|---------|-----
Boolean.getBoolean("false")|boolean|false
Integer.parseInt("123")|int|123
Long.parseLong("375")|long|375
Float.parseFloat("345.23")|float|345.23
Double.parseDouble("67892.34")|double|67892.34

```java
int a = Integer.parseInt("3");
Float f = Float.MAX_VALUE;
```

### <6>字符串与数字的转换方法

- 基本数据类型转换为字符串的方法是`String.valueOf(基本数据类型)`
  - `StringvalueOf(123)`的值为"123"
  - `StringvalueOf(0.34)`的值为"0.34"

### <7>数学计算类

> `Math`类在`java.lang`包中。***Math***类包含许多用来进行科学计算的类方法，这些方法可以直接通过类名调用。另外，`Math`类还有两个静态常量，它们分别是：
>
> - E = 2.7182828284590452354
> - PI = 3.14159265358979323846

以下是***Math***类的常用类方法：

类方法|作用（返回值）
-----|-----------
public static long abs(double a)|返回a的绝对值
public static double max(double a,double b)|返回a、b的最大值
public static double min(double a,double b)|返回a、b的最小值
public static double random()|产生一个0到1之间的随机数（不包括0和1）
public static double pow(double a,double b)|返回a的b次幂
public static double sqrt(double a)|返回a的平方根
public static double log(double a)|返回a的对数
public static double sin(double a)|返回正弦值
public static double asin(double a)|返回反正弦值

### <8>BigInteger类

- `java.math`包中的`BigInteger`类提供任意精度的整数运算。可以使用构造方法
  - `public BigInteger(String val)`构造一个十进制的***BigInteger***对象
- 以下是BigInteger类的常用类方法

类方法|作用（返回值）
-----|----------
public BigInteger add(BigInteger val)|返回当前大整数对象与参数指定的大整数对象的和
public BigInteger subtract(BigInteger val)|返回当前大整数对象与参数指定的大整数对象的差
public BigInteger multiply(BigInteger val)|返回当前大整数对象与参数指定的大整数对象的积
public BigInteger divide(BigInteger val)|返回当前大整数对象与参数指定的大整数对象的商
public BigInteger remainder(BigInteger val)|返回当前大整数对象与参数指定的大整数对象的余
public int compareTo(BigInteger val)|返回当前大整数对象与参数指定的大整数的比较结果，返回值是1、-1或0，分别表示当前大整数对象大于、小于或等于参数指定的大整数
public BigInteger pow(int a)|返回当前大整数对象的a次幂
public String toString()|返回当前大整数对象十进制的字符串表示
public String toString(int p)|返回当前大整数对象p进制的字符串表示

### <9>Random类

> - 使用***Math***类调用其类方法`random()`返回一个0至1之间的随机数(不包括0和1)
> - `Java`提供了更为灵活的用于获得随机数的***Random***类（该类在java.util包中）.***Random***类的如下构造方法：
>   - `public Random();`
>   - `public Random(long seed); //使用参数seed指定的种子创建一个Random对象`
> - 需要注意的是，对于具有相同种子的两个*Random*对象，二者依次调用`nextInt()`方法获取的随机数序列是相同的

### <10>Date类

- ***Date类***在`java.util`包里

#### [1] ***Date类***的构造方法之一

> `Date()`使用***Date类***的无参数构造方法创建的对象可以获取本地当前时间

- 例：`Date nowTime=new Date();`
  - 当前`nowTime`对象中含有的日期、时间就是创建`nowTime`对象时的本地计算机的日期和时间。
  - 例如，假设当前时间是：2011年3月10日23:05:32（CST时区），那么`System.out.println(nowTime);` 输出结果是：`Thu Mar 10 23:05:32 CST 2011`
  - `Date`对象表示时间的默认顺序是：星期、月、日、小时、分、秒、年

#### [2]Date类的构造方法之二

> - `Date(long time)`使用`long`型参数创建指定的时间
> - 计算机系统将其自身的时间的"公元"设置在`1970年1月1日0时`（格林威治时间），可以根据这个时间使用Date的带参数的构造方法：`Date(long time)`来创建一个`Date`对象

- 例如：`Date date1=new Date(1000), date2=new Date(-1000);`
  - 其中的参数取正数表示公元后的时间，取负数表示公元前的时间，其中1000表示1000毫秒，那么，`date1`含有的日期、时间就是计算机系统公元后1秒时刻的日期、时间
  - 如果运行***Java***程序的本地时区是北京时区（与格林威治时间相差8个小时），那么上述`date1`就是`1970年01月01日08时00分01秒`、`date2`就是`1970年01月01日07时59分59秒`

### <11>Calendar类

- Calendar类在java.util包中

>使用Calendar类的static方法 getInstance()可以初始化一个日历对象，如

```java
Calendar calendar= Calendar.getInstance();
```

- calendar对象可以调用方法

```java
public final void set(int year,int month,int date)
public final void set(int year,int month,int date,int hour,int minute)
public final void set(int year,int month, int date, int hour, int minute,int second)
public final void setTime(Date date)
```

- Calendar对象可以对日期进行计算

```java
public void add(int field,int amount)
```

实例

```java
import java.util.Calendar;
import java.util.Date;

public class Demo{
    public static void main(String[] args){
        Date date = new Date();
        System.out.println(date);
        Calendar calendar =  Calendar.getInstance();
        calendar.setTime(date);
        calendar.add(Calendar.YEAR, 1);
        date = calendar.getTime();
        System.out.println(date);
    }
}
```

---

## *3.4 Java数组*

- 数组是程序设计使用最频繁的数据结构，它用来表示一组类型相同的有序数据
- 这些数据使用同一个标识符命名叫数组名，数组中的每个数据叫数组元素，可通过下标来访问
- 和变量一样，数组必须先定义，后使用
- 定义数组时确定数组的名称、数据类型，还要为它分配内存，初始化
- 在Java中，数组是对象。类Object中定义的方法都可以用于数组对象

### <1>一维数组的初始化

声明一个数组***仅为数组指定了数组名和元素的数据类型***，并未指定数组元素的个数，***系统无法为数组分配存储空间***。声明后的数组由初始化来完成上述工作，经过初始化的数组才能引用
> 数组初始化可以通过`new`操作符完成，也可以通过给元素赋初值完成

### <2>创建数组

#### [1] 静态初始化

- 在定义数组的同时对数组元素进行初始化
- 静态初始化可用于任何元素类型，初值块中每个位置的每个元素对应一个***引用(reference)***

```java
int intArray[] = {1, 2, 3, 4};
float[] heights = {84.124, 78.2, 61.5};
boolean[] tired = {true, false, false, true};
String[] names = {"Zhang", "Li", "Wang"};
```

#### [2]动态初始化

- 是使用运算符new为数组分配空间
- 数组说明的方括号中的数字表示数组元素个数

> [!NOTE]
> type[] arrayName = new type[arraySize]
>
> type arrayName[] = new type[arraySize]
>
> char[] s = new char[20];

#### [3]一维数组初始化示例

第一种形式|第二种形式|第三种形式
--------|---------|--------
int score[]; score = new int[10]|int score[] = new int[10];|int score[] = {65, 34, 78, 81, 56, 92, 56, 87, 90, 77};

> [!TIP]
> `Java`数组的下标最小值为0，最大值为元素个数减一

#### [4]实战

- 编写"复制一维数组的程序"
  - 定义两个一维数组`a[3]`和`b[5]`
  - 赋值`a[i] = i;`
  - 赋值`b[j] = 10 * j;`
  - 将`a[i]`逐位复制`b[i];`

#### [5]一维数组的复制

```java
//1ArrayCopy
//一维数组的复制

class Example04_01{
    public static void main(String args[]) {
        int a[], b[], i, j;
        a = new int[3];
        b = new int[5];
        System.out.println("a.length = " + a.length);
        for (i = 0; i < a.length; i++)  {  
            a[i] = i;
            System.out.print(a[i] + "  ");
        }
        System.out.println();
        System.out.println("Before array assigment  ");
        System.out.println("b.length = " + b.length);
        for (j = 0; j < b.length; j++)  {
            b[j] = j*10;
            System.out.print(b[j] + "  ");
        }
        System.out.println( );
        b = a;
        System.out.println("After array assigment  ");
        System.out.println( "b.length = " + b.length);
        for (j = 0; j < b.length; j++) {
            System.out.print(b[j] + "  ");
            System.out.println();
        }
    }
}
```

### <3>复合类型的数组

- 复合类型的数组需要经过两步进行空间分配
  - 使用运算符 new 只是为数组本身分配空间，并没有对数组的元素进行初始化
  - 第一步先创建数组本身 `type arrayName[] = new type[arraySize];`
  - 第二步分别创建各个数组元素 `arrayName[0] = new type(paramList);` `…`; `arrayName[arraySize-1] = new type(paramList);`

```java
string stringArrar[];
stringArray = new String[3];
stringArray[0] = new String("how");
stringArray[1] = new String("are");
```

### <4>多维数组

> [!IMPORTANT]
> Java中没有真正的多维数组，可以建立数组的数组（的数组……），由此得到多维数组

- 例如数组元素为一维数组时，称为二维数组，数组元素为二维数组时成为三维数组等等，依次类推
- 多维数组需要有多个下标来确定，拿二维数组为例，二维数组相当一个具有行列的表
- 只要给出表的行号和列号就可以确定表中的元素

二维数组的声明：

```java
类型标识符 数组名[] []  
    或  
类型标识符 [] []  数组名
```

### <5>二维数组的初始化

- 声明的目的是指定数组名和元素的数据类型
- 初始化的目的是指定数组的行数与列数，为数组分配内存，给元素赋初值一般由赋值语句完成，也可以在初始化时通过初值表，同时完成赋初值的工作。
  1. 先声明数组再初始化
    `类型标识符  数组名[][]`
    `数组名=new 类型标识符 [行数][列数]`
  2. 声明的同时进行初始化
    `类型标识符  数组名[][] = new 类型标识符[行数][列数]`
        或
    `类型标识符[][] 数组名 = new 类型标识符[行数][列数]`
  3. 赋初值初始化数组
    `类型标识符  数组名[][] = { {初值表},{初值表}, …, {初值表} }`
- 二维数组行列数的检测也是通过属性length进行的，不同的是测列数时需要给定一个行标

```java
获得行数     数组名.length
获得列数     数组名[行标].length
```

二维数组初始化示例
第一种方式|第二种方式|三种方式
--------|---------|--------
int a[][]; a = new int[3][4];|int a[][] = new int[3][4]|int grade [][] = { {65,34}, {81,56,92}, {56,87,90}, {92,69,75} };

> [!TIP]
> 数组的引用方法是在数组名后面的括号中指定其下标，通过下标值的变换，可取得相应数组元素的值

- 二维数组实例

```java
String s[][] = new String[2][];
s[0] = new String[2];
s[1] = new String[3];
s[0][0] = new String("Good");
s[0][1] = new String("Luck");
s[1][0] = new String("to");
s[1][1] = new String("you");
s[1][2] = new String("!");
```

### <6>非矩阵数组

```java
int twoDim[][] = new int [4][ ];
twoDim[0] = new int[2];
twoDim[1] = new int[4];
twoDim[2] = new int[6];
twoDim[3] = new int[8];

X X
X X X X
X X X X X X
X X X X X X X X
twoDim数组为4行，每行的
元素个数分别为2，4，6，8个  
```

### <7>其他容器

- 数组是在能随机存储和访问`reference`序列的诸多方法中，最高效的一种
- 在我们写程序的时候往往不知道要用多少对象，或者要用一种更复杂方式来存储对象情况。为此，`Java`提供了"容器类`(container class)`"。基本类型有`List, Set 和Map`

![container](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/container.jpg?raw=true)

### <7>VectorDemo

```java
import java.util.*;
/**
 * 演示Vector的使用。包括Vector的创建、向Vector中添加元素、从Vector中删除元素、
 * 统计Vector中元素的个数和遍历Vector中的元素。
 */
public class VectorDemo{
    public static void main(String[] args){
        //Vector的创建，使用Vector的构造方法进行创建
        Vector v = new Vector(4);  
        //向Vector中添加元素，使用add方法直接添加元素
        v.add("Test0");
        v.add("Test1");
        v.add("Test0");
        v.add("Test2");
        v.add("Test2");
        //从Vector中删除元素
        v.remove("Test0"); //删除指定内容的元素
        v.remove(0);       //按照索引号删除元素
        //获得Vector中已有元素的个数
        int size = v.size();
        System.out.println("size:" + size);
        //遍历Vector中的元素
        for(int i = 0;i < v.size();i++) {
            System.out.println(v.get(i));
        }
    }
}
```

> [!NOTE]
> Vector 类提供了实现可增长数组的功能，随着更多元素加入其中，数组变的更大。在删除一些元素之后，数组变小

---

## *3.5 Java内存区域*

### <1>数据存在哪里

> Java程序是在虚拟机中运行的，对程序运行时各部分如何在虚拟机中分布的有一个直观的了解，是很有必要的

数据可以存储在以下几个地方

![data](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/data.png?raw=true)

### <2>Java内存区域

- 程序计数器：是一块较小的内存空间，它可以看作是当前线程所执行的字节码的行号指示器
- 方法区：
  - 类信息：存储类的一般信息
  - 静态区域：存储由*static*关键字定义的变量
  - 常量池：存储代码中的常量信息
  - 代码区：存储编译后的代码
- 堆：*Java*语言中采用new关键字实例化对象存储的位置，只存储对象的变量，不存储方法
- 栈：先进后出
  - 虚拟机栈：*Java*虚拟机 执行过程中使用内存
    - 局部变量表：只存储8种基本数据类型和引用
    - 操作栈
    - 动态链接
    - 方法返回地址
  - 本地方法栈：非*Java*语言代码执行过程中用的内存

代码内存分布示例

```java
//创建一个新人物
class People {
    int age;
    String name;
    void  setinfo(int myage age, String myname) {
         age = myage; name = myname;
    }
    String showname() {
        return "["+ age + ", " + name + "]";
    }
}
class TestPeople{
    public static void main(String args[]) {
        People someguy = new People();
        someguy. setinfo( 18,  "SUN" );
        System.out.println(someguy.showname());
    }
}
```

### <3>声明对象时的内存模型

- 当用***People***类声明一个对象`someguy`: `People someguy = new People();`
- 内存模型
  - 在"局部变量表"里仅建立了`"someguy"`对象的引用`(reference)`
  ![model](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/model.png?raw=true)

### <4>对象分配内存后的内存模型

- 所做工作：
  - ① 为年龄`(age)`和姓名`(name)`成员变量分配内存，即类的所有成员变量被分配内存空间，然后执行构造方
  - ② `new`运算符在为`age`和`name`成员变量分配内存后，将返回一个引用给对象`someguy`
  ![model2](https://github.com/Meaple-SFKY/Programming/blob/master/Markdown_Folder/Java/Pictures/model2.png?raw=true)
  
上一篇：
> [!div class="nextstepaction"]
> [Java语言基础](Java语言基础.md)

下一篇：
> [!div class="nextstepaction"]
> [Java面向对象进阶](Java面向对象进阶.md)