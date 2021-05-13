QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
LIBS += -L"C:\Users\pocke\Desktop\SFML-2.5.1\lib" #change this
LIBS += -L"C:\Users\pocke\Desktop\SFML-2.5.1\bin" #change this

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-system-d -lsfml-network-d -lsfml-window-d

#WINDOWS
INCLUDEPATH += "C:\Users\pocke\Desktop\SFML-2.5.1\include" #change this
DEPENDPATH += "C:\Users\pocke\Desktop\SFML-2.5.1\include" #change this

#-----------------------------------------



SOURCES += \
        animate.cpp \
        coord_translation.cpp \
        graph.cpp \
        log.cpp \
        main.cpp \
        plot.cpp \
        sidebar.cpp \
        system.cpp \
        number.cpp \
        operator.cpp \
        rpar.cpp \
        shunting_yard.cpp \
        textfield.cpp \
        token.cpp \
        variable.cpp \
        lpar.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Constants.h \
    Z_OUTPUT_H.h \
    Z_WORK_REPORT_1_H.h \
    Z_WORK_REPORT_2_H.h \
    Z_WORK_REPORT_FINAL_H.h \
    animate.h \
    coord_translation.h \
    graph.h \
    log.h \
    plot.h \
    sidebar.h \
    system.h \
    lpar.h \
    number.h \
    operator.h \
    rpar.h \
    shunting_yard.h \
    textfield.h \
    token.h \
    variable.h
