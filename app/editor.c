/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *arg2;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);


        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }

            /*Сдвигаем курсор в нулевую позицию*/
            if (m(txt, 0, 0) != 0) {
                fprintf(stderr, "Can't move to zero\n");
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
        if(strcmp(cmd,"ch")==0)
	{	
		ch(txt);
		continue;
	}
        /* Выводим текст с капитализацией всех символов*/
        if (strcmp(cmd, "showupper") == 0) {
            showupper(txt);
            continue;
        }

        /* Выводим текст, состоящий из нечётных строк*/
        if (strcmp(cmd, "showodd") == 0) {
            showodd(txt);
            continue;
        }

        /*Выводим длины строк в столбец*/
        if (strcmp(cmd, "showlenght") == 0) {
            showlenght(txt);
            continue;
        }

        /*Выводим количество пробелов в каждой строке*/
        if(strcmp(cmd, "shownumspaces") == 0) {
            shownumspaces(txt);
            continue;
        }

        /* Выводим первое слово из каждой строки */
        if (strcmp(cmd, "showfirstwords") == 0) { 
            showfirstwords(txt); 
            continue; 
        }
        if(strcmp(cmd,"s")==0)
	{	
		s(txt);
		continue;
	} 
        /*Выводим текст, заменяя пробелы на нижнее подчёркивание*/
        if(strcmp(cmd, "showunderscores") == 0) {
            showunderscores(txt);
            continue;
        }

        /*Выводим только буквенные символы*/
        if(strcmp(cmd, "showalphaonly") == 0) {
            showalphaonly(txt);
            continue;
        }

        /*Выводим текст, заменяя буквенные символы на звёздочки*/
        if(strcmp(cmd, "showclassified") == 0) {
            showclassified(txt);
            continue;
        }

        /*Обработка команды save*/
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
        if(strcmp(cmd,"plb") == 0)
	{	
		plb(txt);
		continue;
	}

        /*Обработка команды m*/
        if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL ) {
                fprintf(stderr, "Usage: m line_number cursor\n");
            } else {
                if ((arg2 = strtok(NULL, " \n")) == NULL ) {
                    fprintf(stderr, "Usage: m line_number cursor\n");
                } else {
                    if (m(txt, atoi(arg), atoi(arg2)) != 0) {
                        fprintf(stderr, "Invalid arguments\n");
                    }
                }
            }
            continue;
        }
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
