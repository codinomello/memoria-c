#!/bin/bash

# Verifica se o usuário passou um argumento
if [ -z "$1" ]; then
    echo "Uso: build <arquivo.c>"
    exit 1
fi

# Garante que o argumento tem a extensão .c
if [[ "$1" != *.c ]]; then
    echo "Erro: O arquivo deve ter a extensão .c"
    exit 1
fi

# Remove a extensão .c para nomear o executável
output="${1%.c}"

# Verifica se o arquivo existe antes de compilar
if [ ! -f "$1" ]; then
    echo "Erro: Arquivo '$1' não encontrado!"
    exit 1
fi

# Compila o programa
gcc -o "$output" "$1" && echo "Compilado com sucesso: ./$output"