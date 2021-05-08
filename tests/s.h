#ifndef S_H
#define S_H
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
extern "C"{
    #include "common.h"
    #include<stdlib.h>
    #include "text/text.h"
    #include "text/_text.h"
}
static void check_sep_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    /* Выводим строку на экран */
    char tmp[MAXLINE];
    if(cursor != -1) {
        sprintf(tmp,"%.*s|%.*s\n", cursor, contents, (int)strlen(contents) - cursor, contents + cursor);
    } else {
        sprintf(tmp,"%s\n", contents);
    }
    strcat((char*)data,tmp);
}
TEST(stest,test1)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    m(txt,0,0);
    s(txt);
    char txts[MAXLINE] = {'\0'};
    process_forward(txt,check_sep_line,txts);
    char tmp2[] = "|\nqwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    ASSERT_STREQ(txts,tmp2);
}
TEST(stest,test2)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    m(txt,2,2);
    s(txt);
    char txts[MAXLINE] = {'\0'};
    process_forward(txt,check_sep_line,txts);
    char tmp2[] = "qwerty12345678\nbiwfouwe fnwfn\n- |\nhello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    ASSERT_STREQ(txts,tmp2);
}
#endif // S_H
