QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editor.c \
    load.c \
    plb.c \
    save.c \
    show.c \
    showalphaonly.c \
    showclassified.c \
    showfirstwords.c \
    showlenght.c \
    shownumspaces.c \
    showodd.c \
    showunderscores.c \
    showupper.c \
    text/append_line.c \
    text/ch.c \
    text/create_text.c \
    text/m.c \
    text/process_forward.c \
    text/remove_all.c \
    text/s.c

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    common.h \   
    text/_text.h \
    text/text.h

DISTFILES += \
    a \
    gtest-master/qmake-gtest.pro.user \
    tests/gtest_dependency.pri

SUBDIRS += \
    tests/tests.pro
