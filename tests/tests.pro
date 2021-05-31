include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


INCLUDEPATH += ../app

SOURCES += \
    ../app/load.c \
    ../app/plb.c \
    ../app/save.c \
    ../app/show.c \
    ../app/showalphaonly.c \
    ../app/showclassified.c \
    ../app/showfirstwords.c \
    ../app/showlenght.c \
    ../app/shownumspaces.c \
    ../app/showodd.c \
    ../app/showunderscores.c \
    ../app/showupper.c \
    ../app/text/append_line.c \
    ../app/text/ch.c \
    ../app/text/create_text.c \
    ../app/text/m.c \
    ../app/text/process_forward.c \
    ../app/text/remove_all.c \
    ../app/text/s.c \
    main.cpp \

HEADERS += \
    ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    helpf.h \
    m.h \
    plb.h \
    s.h \
    save.h \
    showclassified.h
