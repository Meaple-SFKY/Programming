# Python程序设计语言



## 1. Python基本语法元素

### Python的两种编程方式

- 文件式
  - 批量处理一组语句并运行结果，编程的主要方式
- 交互式
  - 对每个输入语句即时运行结果，适合语法学习

### Python程序语法元素分析

- 程序的格式框架
  - 缩进：一行代码前的空白区域，表达程序的格式框架
  - 注释：以`#`开头，其后内容为注释或以三个单引号`'''`作为开头和结尾
- 命名与保留字
  - 命名：关联标识符的过程
  - 保留字：被编程语言内部定义并保留使用的标识符
- 数据类型
- 语句与函数
- Python程序的输入与输出



## 2. Python基本图形绘制

> Python是以计算生态为标志的超级语言

### turtle库的基本介绍

turtle（海龟）库是turtle绘图体系的Python实现

- turtle的绘图窗体
  - `turtle.setup(width, height, startx, starty)`
  - `turtle.setup(width, height)`在屏幕的正中心
  - `(startx, starty)`是窗体左上角相对于屏幕左上角的坐标
- turtle空间坐标体系
  - `turtle.goto(x, y)`
  - `turtle.fd(d)`
  - `turtle.bk(d)`
  - `turtle.circle(r, angele)`
- turtle的角度坐标体系
  - `turtle.seth(angle)`
  - `turtle.left(angle)`
  - `turtle.right(angle)`



---

### turtle程序语法元素分析

-  画笔控制函数
  - `turtle.penup()别名turtle.pu()`
  - `turtle.pendowm()别名turtle.pd()`
  - `turtle.pensize(width)别名turtle.width(width)`
  - `turtle.pencolor()`
    -  `turtle.pencolor("purple")`
    - `turtle.pencolor(0.63, 0.13, 0.94)`
    - `turtle.pencolor((0.63, 0.13, 0.94))`
- 运动控制函数
  - `turtle.foward()别名turtle.fd()`
  - `turtle.circlr(r, extent = None)//半径，弧度，半径为正值时圆心在左侧`
-  方向控制函数
   - `turtle.setheading(angle)别名turtle.seth(angle)//当前方向`

- 循环语句
  - `for i in range(5)`
  - `range()//产生循环计数序列`
    - `range(N)//产生从0到N - 1的序列`
    - `range(M, N)//产生从M到N - 1的序列`



