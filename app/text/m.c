/**
 * m.c -- функция для перемещения курсора в заданную позицию
 * 
 * Copyright (c) 2021, Kvist Tatyana <kvist@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "_text.h"

int m(text txt, int line_num, int cursor_pos) 
{
    /*Если заданный номер строки или позиция курсора меньше 0*/
    if (line_num < 0 || cursor_pos < 0) return -1;

    /*Указатель на строку, в которой должен стоять курсор*/
    node *current = txt->begin;
    int index = 0;
    
    /*Идём до заданной строки*/
    while (current) {
        if (line_num == index) break;
        current = current->next;
        index++;
    }

    /*Если заданный номер строки больше строк в файле*/
    if (current == NULL) return -1;

    /*Если заданный позиция курсора больше длины заданной строки*/
    if (strlen(current->contents) < (long unsigned int)cursor_pos) return -1;

    /*Присваиваем новые позиции строки и курсора*/
    txt->cursor->line = current;
    txt->cursor->position = cursor_pos;

    return 0;
}