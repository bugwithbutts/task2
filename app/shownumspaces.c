/**
* shownumspaces.c — реализует команду вывода количество пробелов в строках
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит количество пробелов в каждой строке на экран в порядке следования
 */
void shownumspaces(text txt)
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
    
    /* Считаем количество пробелов */
    int numspaces = 0;
    for (int i = 0; i < (int)strlen(contents); i++)
        if (contents[i] == ' ')
            numspaces++;

    /* Вывод значения на экран*/
    printf("%d\n", numspaces);
}