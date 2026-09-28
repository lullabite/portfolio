# Parametric Truss Generator

Программы на C++, которые строят DXF-чертёж параболической арочной фермы, открываемый в AutoCAD, вместо ручного черчения.

## Часть 1 - чертёж по готовым файлам
`src/task1_basic.cpp` читает `data/coor.txt` (координаты 34 узлов) и
`data/top.txt` (49 стержней — пары номеров узлов) и записывает `ferma.dxf`.
Функции записи в DXF — в `src/dxf_out.cpp`.

| Эскиз с нумерацией узлов и стержней | Результат в AutoCAD |
|---|---|
| ![Эскиз](parametric-truss-generator/screenshots/sketch.jpg) | ![Результат](parametric-truss-generator/screenshots/task1.jpg) |

## Часть 2 - параметрическая ферма
`src/task2_oop.cpp`: класс `Constructor` сам вычисляет узлы и стержни по
4 параметрам (число панелей, длина панели, высота арки, высота нижнего пояса)
и пишет `coor.txt`/`top.txt`; класс `TXT_TO_DXF` превращает их в DXF.
Входные файлы вручную готовить не нужно.

| Панелей 10, длина панелей 20, высота 50, высота линии 25 | Панелей 30, длина 20, высота 80, высота линии 30 | Панелей 8, длина 10, высота 30, высота линии 15 |
|---|---|---|
| ![](parametric-truss-generator/screenshots/task2_1.jpg) | ![](parametric-truss-generator/screenshots/task2_2.jpg) | ![](parametric-truss-generator/screenshots/task2_3.jpg) |

## Технологии
C++, ООП, файловый ввод-вывод, формат DXF, AutoCAD

## Запуск
```bash
# из корня папки проекта; данные для части 1 лежат в data/
g++ src/task1_basic.cpp -o task1 && ./task1
g++ src/task2_oop.cpp   -o task2 && ./task2
```
> Программы читают/пишут файлы в текущей директории, поэтому для части 1
> скопируйте `data/coor.txt` и `data/top.txt` в папку запуска.
