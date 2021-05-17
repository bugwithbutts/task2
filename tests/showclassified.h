#ifndef SHOWCLASSIFIED_H
#define SHOWCLASSIFIED_H
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>
extern "C"{
    #include "common.h"
    #include<stdlib.h>
    #include "text/text.h"
    #include "text/_text.h"
    #include "helpf.h"
}
static void check_class_line(int index, char *contents, int cursor, void *data)
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
TEST(classtest,test1)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    testing::internal::CaptureStdout();
    load(txt,"a");
    showclassified(txt);
    std::string tmpstr = (testing::internal::GetCapturedStdout());
    char txts[MAXLINE];
    strcpy(txts,tmpstr.c_str());
    char tmp2[] = "******12345678\n******** *****\n- ***** ***** 2\n- ******* ****** 1\n\n*\n\n123456789\n";      
    ASSERT_STREQ(tmp2,tmpstr.c_str());
}
#endif // SHOWCLASSIFIED_H
