# Matrix Calculator

Чтение матриц из файла и вычисление выражения
`F = 0.5 · Rᵀ · T − A`.

**Технологии:** C++, fstream

## Файлы
- `matrix.h` / `matrix.cpp` — операции с матрицами (чтение, транспонирование, умножение, вычитание)
- `main.cpp` — точка входа
- `data/input.txt` — входные данные
- `data/output_example.txt` — пример результата

## Запуск

```bash
g++ main.cpp matrix.cpp -o matrix_calculator
./matrix_calculator
```

Результат сохраняется в `output.txt`.
