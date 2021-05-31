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
    char txts2[MAXLINE];
    strcpy(txts2, tmpstr.c_str());
    ASSERT_STREQ(tmp2,txts2);
}
#endif // SHOWCLASSIFIED_H
