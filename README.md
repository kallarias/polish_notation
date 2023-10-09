# polish_notation
implemented the Polish notation for creating graphs of functions defined by arbitrary expressions

The graph.c program has been developed in the C programming language for constructing graphs of functions specified by arbitrary expressions. 
To calculate the values of expressions, Dijkstra's algorithm is used to translate the expression into Polish notation. The program was built using Makefile. 
The build stage name is all. An executable file named graph.

* ***Conditions***
  
The size of the field for displaying graphs is a rectangle of 25 by 80 points.

The scope is [0; 4 Pi]

Range of values - [-1; 1]

Orientation of the coordinate plane - the ordinate axis is directed downwards, the abscissa axis is directed to the right.

The coordinate center is the middle of the left border (point {0, 13}).

Values are rounded according to mathematical rules.

<br/>

* ***Graphic arts***
  
The graph is displayed using "asterisks" for the graph line and "." for the rest of the screen space. ==***

* ***Modules***

Parse an expression string and get a list of tokens.

Translation into Polish notation and calculation using it.

Drawing a graph in the terminal.

Libraries for organizing dynamic data structures (stack, list, etc.).

> Only `<math.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>` and my own libraries are used

> Possible operations & functions\
> "+" \
> "-" (unary and binary)\
> "*" \
> "/"\
> "()" \
>sin(x)\
>cos(x)\
>tan(x)\
>ctg(x)\
>sqrt(x)\
>ln(x)

На языке программирования Си разработана программа graph.c для построения графиков функций, задаваемых произвольными выражениями. 
Для вычисления значений выражений используется алгоритм Дейкстры для перевода выражения в польскую нотацию. 
Сборку программы осуществлена при помощи Makefile. Имя стадии сборки - all. Исполняемый файл с именем graph.

* ***Условия***
  
Размер поля для вывода графиков - прямоугольник 25 на 80 точек.

Область определения - [0; 4 Пи]

Область значений - [-1; 1]

Ориентация координатной плоскости - ось ординат направлена вниз, ось абсцисс - направо. 

Центр координат - середина левой границы (точка {0, 13}). 

Значения округляются по правилам математики.

<br/>

* ***Графика***
  
График выведен с помощью знаков "Звездочек" для линии графика и "." для всего остального пространства экрана. ==***

* ***Модули***

Разбор строки выражения и получение списка лексем.

Перевод в польскую нотацию и вычисление по ней.

Отрисовка графика в терминале.

Библиотеки для организации динамических структур данных (стек, список и т.д.).

> Используются только `<math.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>` и мои собственные библиотеки 

> Возможные операции & функции \
> "+" \
> "-" (унарный и бинарный) \
> "*" \
> "/" \
> "()" \
> sin(x) \
> cos(x) \
> tan(x) \
> ctg(x) \
> sqrt(x) \
> ln(x)
