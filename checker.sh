#!/bin/bash

# Компиляция программ
g++ -DWANDOKA -std=c++17 ./workspace/main/main.cpp -o ./workspace/main/main
g++ -DWANDOKA -std=c++17 ./workspace/brute/brute.cpp -o ./workspace/brute/brute
g++ -DWANDOKA -std=c++17 ./workspace/test_generator/test_generator.cpp -o ./workspace/test_generator/test_generator

# Установка количества итераций (по умолчанию 1000)
am_of_loops=${1:-1000}

# Отображение количества итераций
echo "Amount of loops is $am_of_loops"

# Переменная для отображения прогресса (если передан второй аргумент)
output_progress=$2

# Цикл для тестирования
for ((i=1; i<=am_of_loops; i++))
do
    if [ -n "$output_progress" ]; then
        echo "Testing..."
    fi

    # Генерация теста и запуск решений
    ./workspace/test_generator/test_generator > ./.tmp/checker_input
    ./workspace/main/main < ./.tmp/checker_input > ./.tmp/checker_main_output
    ./workspace/brute/brute < ./.tmp/checker_input > ./.tmp/checker_brute_output

    # Сравнение выводов
    if ! diff ./.tmp/checker_main_output ./.tmp/checker_brute_output > /dev/null; then
        echo "INPUT:"
        cat ./.tmp/checker_input
        echo
        echo "SOLUTION OUTPUT:"
        cat ./.tmp/checker_main_output
        echo
        echo "BRUTE OUTPUT:"
        cat ./.tmp/checker_brute_output
        echo
    fi
done

echo "Done"
