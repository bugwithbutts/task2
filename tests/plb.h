#ifndef PLB_H
#define PLB_H
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
extern "C"{
    #include "common.h"
    #include<stdlib.h>
    #include "text/text.h"
    #include "text/_text.h"
    #include "helpf.h"
}

TEST(plbtest,test1)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    m(txt,2,2);
    testing::internal::CaptureStdout();
    plb(txt);
    std::string tmpstr = testing::internal::GetCapturedStdout();
    char tmp2[] = "- \n";
    ASSERT_STREQ(tmpstr.c_str(),tmp2);
}
TEST(plbtest,test2)
{
    FILE* f = fopen("a","w");
    char tmp[] = "qwerty12345678\nbiwfouwe fnwfn\n- hello there 2\n- general Kenobi 1\n\na\n\n123456789\n";
    fprintf(f,"%s",tmp);
    fclose(f);
    text txt = create_text();
    load(txt,"a");
    m(txt,0,0);
    testing::internal::CaptureStdout();
    plb(txt);
    std::string tmpstr = testing::internal::GetCapturedStdout();
    char tmp2[] = "\n";
    ASSERT_STREQ(tmpstr.c_str(),tmp2);
}
#endif // PLB_H
