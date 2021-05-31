#ifndef M_H
#define M_H
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
extern "C"{
    #include "common.h"
    #include<stdlib.h>
    #include "text/text.h"
    #include "text/_text.h"
}
static void check_cursor_line(int index, char *contents, int cursor, void *data)
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
TEST(mtest,test1)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    m(txt,2,2);
    char txts[MAXLINE] = {'\0'};
    process_forward(txt,check_cursor_line,txts);
    char tmp2[] = "qwerty12345678\nbiwfouwe fnwfn\n- |hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    ASSERT_STREQ(txts,tmp2);
}
TEST(mtest,wrongtest1)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    int ret = m(txt,4,2);
    ASSERT_EQ(ret,-1);
}
TEST(mtest,emptytext)
{
    FILE* f = fopen("a","w");
    char tmp[] = "";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    int ret = m(txt,4,2);
    ASSERT_EQ(ret,-1);
}
#endif // M_H
