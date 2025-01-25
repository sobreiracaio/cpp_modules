#!/bin/bash

# Função para gerar números válidos e inválidos para inteiros
generate_ints() {
    echo -e "\033[32mValores válidos para inteiros:\033[0m"
    for i in 42 -10 0 123456789 2147483647 -2147483648; do
        echo "Processando: $i"
        ./convert $i
        echo
    done

    echo -e "\033[32mValores inválidos para inteiros:\033[0m"
    for i in "abc" "42.5" "3.14" "-123abc" "--100" "2147483648" "-2147483649"; do
        echo "Processando: $i"
        ./convert $i
        echo "***********"
        echo
    done
}

# Função para gerar números válidos e inválidos para floats
generate_floats() {
    echo -e "\033[32mValores válidos para floats:\033[0m"
    for i in 42.5f -10.7f 0.0f 3.14159f 3.4028235e+38f -3.4028235e+38f; do
        echo "Processando: $i"
        ./convert $i
        echo
    done

    echo -e "\033[32mValores inválidos para floats:\033[0m"
    for i in "abc" "42" "1.2.3" "--42.5" "3.14abc" "3.4028236e+38" "-3.4028236e+38"; do
        echo "Processando: $i"
        ./convert $i
        echo "***********"
        echo
    done
}

# Função para gerar números válidos e inválidos para doubles
generate_doubles() {
    echo -e "\033[32mValores válidos para doubles:\033[0m"
    for i in 42.123456 -10.123456 0.0 1.23456789 1.7976931348623157e+308 -1.7976931348623157e+308; do
        echo "Processando: $i"
        ./convert $i
        echo
    done

    echo -e "\033[32mValores inválidos para doubles:\033[0m"
    for i in "abc" "42.5" "1.2.3" "--10.123" "3.14abc" "1.7976931348623158e+308" "-1.7976931348623158e+308"; do
        echo "Processando: $i"
        ./convert $i
        echo "***********"
        echo
    done
}

# Função para gerar caracteres válidos e inválidos
generate_chars() {
    echo -e "\033[32mValores válidos para caracteres:\033[0m"
    for i in 'a' 'Z' '9' ' ' '\n' $'\x7f'; do
        echo "Processando: $i"
        ./convert $i
        echo
    done

    echo -e "\033[32mValores inválidos para caracteres:\033[0m"
    for i in "abc" "42.5" "hello" "!!" "123" $'\x80' $'\xff'; do
        echo "Processando: $i"
        ./convert $i
        echo "***********"
        echo
    done
}

# Função para gerar strings válidas e inválidas
generate_strings() {
    echo -e "\033[32mValores válidos para strings:\033[0m"
    for i in "hello" "world" "42.123" "a string with spaces" "valid_string" "12.34" "42" "hello123"; do
        echo "Processando: $i"
        ./convert "$i"
        echo
    done

    echo -e "\033[32mValores inválidos para strings:\033[0m"
    for i in "42.123abc" "1..23" "123--45" "   " "12:34" "hello@world" "string_with_@_in_middle"; do
        echo "Processando: $i"
        ./convert "$i"
        echo "***********"
        echo
    done
}

# Chamada das funções para gerar os testes
generate_ints
echo "***********"
generate_floats
echo "***********"
generate_doubles
echo "***********"
generate_strings
