/**
 * showodd.c — реализует команду вывода текста в прямом порядке следования строк, опуская строки с четными номерами
 *
 * Copyright (c) 2021, Ekaterina Volkova <evolkova@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showodd(text txt)
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
    UNUSED(cursor);
    UNUSED(data);
 
    /* Работаем только с чётными строками */ 
    if(index % 2 == 1) {
        /* Выводим строку на экран */
        if(cursor != -1) {
            printf("%.*s|%.*s\n", cursor, contents, (int)strlen(contents) - cursor, contents + cursor);
        } else {
            printf("%s\n", contents);
        }    
    }
}

