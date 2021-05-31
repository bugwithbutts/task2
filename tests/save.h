#ifndef SAVE_H
#define SAVE_H
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>
extern "C"{
    #include "common.h"
    #include<stdlib.h>
    #include "text/text.h"
    #include "text/_text.h"
}
static void check_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);
    /* Выводим строку на экран */
    char tmp[MAXLINE];
    sprintf(tmp,"%s\n", contents);
    strcat((char*)data,tmp);
}
TEST(savetest,test1)
{    
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");    
    save(txt,"b");
    text txt2 = create_text();
    load(txt2,"b");
    char txts[MAXLINE] = {'\0'};
    char txts2[MAXLINE] = {'\0'};
    process_forward(txt, check_line, (void*)txts);
    process_forward(txt2, check_line, (void*)txts2);
    ASSERT_STREQ(txts,tmp);
    ASSERT_STREQ(txts,txts2);
}

#endif // SAVE_H
