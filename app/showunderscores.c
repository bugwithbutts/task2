/**
 * showunderscores.c -- выводит содержимое указанного файла на экран с заменой пробелов на нижнее подчеркивание
 *
 * Copyright (c) 2021, Konstantin Smirnov
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <string.h>
#include <stdlib.h>

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showunderscores(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    char* contents_copy =(char *)malloc((MAXLINE+1)*sizeof(char));
    strcpy(contents_copy, contents);

    int i=0;
    while (contents_copy[i]!='\0') {
        if (contents_copy[i]==' ')
            contents_copy[i]='_';
        i++;
    }
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);
    
    /* Выводим строку на экран */
    if(cursor != -1) {
        printf("%.*s|%.*s\n", cursor, contents_copy, (int)strlen(contents_copy) - cursor, contents_copy + cursor);
    } else {
        printf("%s\n", contents_copy);
    }
}
