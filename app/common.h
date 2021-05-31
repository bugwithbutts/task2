/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран с капитализацией всех символов (Квист Татьяна)
 */
void showupper(text txt);

/**
 * Выводит нечётные строки указанного файла (Волкова Екатерина)
 */
void showodd(text txt);
void plb(text txt);
/**
 * Выводит количество символов в строке в столбец (Курочкин Дмитрий)
 */
void showlenght(text txt);

/**
 * Выводит количество пробелов в каждой строке (Хуснутдинова Айгуль)
 */
void shownumspaces(text txt);

/**
 * Выводит первые слова строк (Куусела Демид)
 */
void showfirstwords(text txt);

/**
 * Выводит содержимое указанного файла на экран с заменой пробелов на нижнее подчеркивание (Смирнов Константин)
 */
void showunderscores(text txt);

/**
 * Выводим содержимое указанного файла на экран, опуская небуквенные символы (Беленков Николай)
 */
void showalphaonly(text txt);

/**
 * Выводим содержимое указанного файла на экран, заменяя буквенные символы на звёздочки (Анисимов Никита)
 */
void showclassified(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, const char *filename);

/**
 * Сохраняем содержимое в указанный файл (Квист Татьяна)
 */
void save(text txt, const char *filename);

#endif
