/**
 * showclassified.c -- реализует команду вывода хранимого текста на экран, с заменой букв на звездочки
 *
 * Copyright (c) 2021, Anisimov Nikita
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h> 
#include "common.h"
#include "text/text.h"

static void show_class(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран, с заменой букв на звездочки
 */
void showclassified(text txt)
{
    /* Применяем функцию show_class к каждой строке текста */    
    process_forward(txt, show_class, NULL);
}

/**
 * Выводит содержимое указанного файла на экран, с заменой букв на звездочки
 */
static void show_class(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);
    UNUSED(index);    
    /* Выводим строку на экран */
    for(unsigned int i = 0; i < strlen(contents) ;i++)
        if(isalpha(contents[i])) fputc('*',stdout);
        else fputc(contents[i],stdout);

    fputc('\n',stdout);
}
