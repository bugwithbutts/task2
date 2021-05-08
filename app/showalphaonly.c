/**
 * showalphaonly.c -- реализует команду вывода хранимого текста на экран, опуская небуквенные символы
 *
 * Copyright (c) 2021, Nikolay Belenkov <nikbelen6299@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showalphaonly(text txt)
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
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    char* alphaline = (char*)malloc((MAXLINE+1)*sizeof(char));
        
    char* c = contents;
    char* a = alphaline;
    while(*c)
    {
        if(isalpha(*c))
            {*a=*c;
            a++;}
        c++;
    }
    /* Выводим строку на экран */
    if(cursor != -1) {
    printf("%.*s|%.*s\n", cursor, alphaline, (int)strlen(alphaline) - cursor, alphaline + cursor);
    } else {
    printf("%s\n", alphaline);
    }
} 
