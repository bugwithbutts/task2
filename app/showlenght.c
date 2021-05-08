/**
* showlenght.c — реализует команду вывода длин строк хранимого текста на экран
*
* Copyright (c) 2021, Dmitriy Kurochkin <diimmiiiifififu@gmail.com>
*
* This code is licensed under a MIT-style license.
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showlenght(text txt)
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
    
    /*Выводим количество символов в строке*/
    printf("%ld\n", strlen(contents));
}
