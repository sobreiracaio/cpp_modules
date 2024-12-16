/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:43:14 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/14 22:43:15 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para remover vírgulas de uma string
void remove_commas(char *str) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        if (*src != ',') {
            *dst++ = *src;
        }
    }
    *dst = '\0'; // Finaliza a string sem as vírgulas
}

// Função para substituir "{h,hpp}" por "hpp"
void replace_extension(char *str) {
    char *pos;
    // Substitui todas as ocorrências de "{h,hpp}" por "hpp"
    while ((pos = strstr(str, "{h hpp}")) != NULL) {
        // Move o conteúdo após "{h,hpp}" para antes
        memmove(pos + 3, pos + strlen("{h hpp}"), strlen(pos + strlen("{h hpp}")) + 1);
        // Substitui as três primeiras letras por "hpp"
        strncpy(pos, "hpp", 3);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <string>\n", argv[0]);
        return 1;
    }

    // Cópia da string fornecida para poder modificá-la
    char str[1024];
    strncpy(str, argv[1], sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';  // Garante que a string termine com '\0'

    // Remove vírgulas da string
    remove_commas(str);

    // Substitui "{h,hpp}" por "hpp"
    replace_extension(str);

    // Exibe a string resultante
    printf("Resultado: %s\n", str);

    // Executa o comando touch com a string resultante
    char command[1048]; // Buffer para o comando, deve ser grande o suficiente
    snprintf(command, sizeof(command), "touch %s", str); // Cria o comando
    system(command); // Executa o comando

    return 0;
}
