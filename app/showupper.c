/**
 * showupper.c -- функция для вывода текста с капитализацией всех символов
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
void showupper(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /*Выделяем память под копию текущей строки*/
    char* contents_copy = (char *)malloc((MAXLINE + 1)*sizeof(char));

    /*Копируем текующую строку*/
    strcpy(contents_copy, contents);

    /*Поднимаем регистр в копии строки*/
    char* c = contents_copy;
    while (*c) {
        *c = toupper(*c);
        c++;
    }

    /* Выводим копию строки на экран */
    if(cursor != -1) {
        printf("%.*s|%.*s\n", cursor, contents_copy, (int)strlen(contents_copy) - cursor, contents_copy + cursor);
    } else {
        printf("%s\n", contents_copy);
    }
}
