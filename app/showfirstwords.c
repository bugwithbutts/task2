/**
 * showfirstwords.c -- функция для вывода первого слово из каждой строки
 * 
 * Copyright (c) 2021, Demid Kuusela 
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void showf_words(int index, char *contents, int cursor, void *data);

/* Выводит содержимое указанного файла на экран */
void showfirstwords(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showf_words, NULL);
}

static void showf_words(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);
    UNUSED(index);


    int i = 0;
    /*Обрабатываем пробелы в начале строки*/
    while(contents[i] == ' '){
        i++;
    }

    /*Идём либо до следующего пробела либо до конца строки*/
    while (contents[i] != ' ' && contents[i] != '\0') {
        printf("%c", contents[i]);
        i++;
    }

    printf("\n");
}