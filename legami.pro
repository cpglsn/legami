######################################################################
# Automatically generated by qmake (2.01a) Wed Sep 14 01:37:42 2011
######################################################################

TEMPLATE = app
TARGET = legami

QT += core \
      gui \
      sql \
      xml \

HEADERS += gui/MainWindow.h \
           logica/BusinessUser.h \
           logica/Contatto.h \
           logica/ExecutiveUser.h \
           logica/Gruppo.h \
           logica/Legami.h \
           logica/Profilo.h \
           logica/User.h

SOURCES += main.cpp \
           gui/MainWindow.cpp \
           logica/BusinessUser.cpp \
           logica/Contatto.cpp \
           logica/ExecutiveUser.cpp \
           logica/Gruppo.cpp \
           logica/Legami.cpp \
           logica/Profilo.cpp \
           logica/User.cpp

FORMS +=   gui/mainwindow.ui

OBJECTS_DIR = obj
