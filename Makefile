#############################################################################
# Makefile for building: legami
# Generated by qmake (2.01a) (Qt 4.7.2) on: Sun Sep 18 15:21:09 2011
# Project:  legami.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile legami.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Igui -Ilogica -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/lib64/qt4
LIBS          = $(SUBLIBS)  -L/usr/lib64/qt4 -lQtGui -L/usr/lib64 -L/usr/lib64/qt4 -L/usr/X11R6/lib -lQtCore -lgthread-2.0 -lrt -lglib-2.0 -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		gui/MainWindow.cpp \
		logica/BusinessUser.cpp \
		logica/Contatto.cpp \
		logica/ExecutiveUser.cpp \
		logica/Gruppo.cpp \
		logica/Legami.cpp \
		logica/Profilo.cpp \
		logica/User.cpp \
		logica/Xml.cpp moc_MainWindow.cpp
OBJECTS       = main.o \
		MainWindow.o \
		BusinessUser.o \
		Contatto.o \
		ExecutiveUser.o \
		Gruppo.o \
		Legami.o \
		Profilo.o \
		User.o \
		Xml.o \
		moc_MainWindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		legami.pro
QMAKE_TARGET  = legami
DESTDIR       = 
TARGET        = legami

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: legami.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/qt4/libQtGui.prl \
		/usr/lib64/qt4/libQtCore.prl
	$(QMAKE) -o Makefile legami.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/qt4/libQtGui.prl:
/usr/lib64/qt4/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile legami.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/legami1.0.0 || $(MKDIR) .tmp/legami1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/legami1.0.0/ && $(COPY_FILE) --parents gui/MainWindow.h logica/BusinessUser.h logica/Contatto.h logica/ExecutiveUser.h logica/Gruppo.h logica/Legami.h logica/Profilo.h logica/User.h logica/Xml.h .tmp/legami1.0.0/ && $(COPY_FILE) --parents main.cpp gui/MainWindow.cpp logica/BusinessUser.cpp logica/Contatto.cpp logica/ExecutiveUser.cpp logica/Gruppo.cpp logica/Legami.cpp logica/Profilo.cpp logica/User.cpp logica/Xml.cpp .tmp/legami1.0.0/ && $(COPY_FILE) --parents gui/mainwindow.ui .tmp/legami1.0.0/ && (cd `dirname .tmp/legami1.0.0` && $(TAR) legami1.0.0.tar legami1.0.0 && $(COMPRESS) legami1.0.0.tar) && $(MOVE) `dirname .tmp/legami1.0.0`/legami1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/legami1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp
moc_MainWindow.cpp: gui/MainWindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: gui/mainwindow.ui
	/usr/bin/uic gui/mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp gui/MainWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: gui/MainWindow.cpp gui/MainWindow.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o gui/MainWindow.cpp

BusinessUser.o: logica/BusinessUser.cpp logica/BusinessUser.h \
		logica/User.h \
		logica/Profilo.h \
		logica/Legami.h \
		logica/Contatto.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BusinessUser.o logica/BusinessUser.cpp

Contatto.o: logica/Contatto.cpp logica/Contatto.h \
		logica/User.h \
		logica/Profilo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Contatto.o logica/Contatto.cpp

ExecutiveUser.o: logica/ExecutiveUser.cpp logica/ExecutiveUser.h \
		logica/BusinessUser.h \
		logica/User.h \
		logica/Profilo.h \
		logica/Legami.h \
		logica/Contatto.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ExecutiveUser.o logica/ExecutiveUser.cpp

Gruppo.o: logica/Gruppo.cpp logica/Gruppo.h \
		logica/User.h \
		logica/Profilo.h \
		logica/Xml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Gruppo.o logica/Gruppo.cpp

Legami.o: logica/Legami.cpp logica/Legami.h \
		logica/User.h \
		logica/Profilo.h \
		logica/Contatto.h \
		logica/Xml.h \
		logica/BusinessUser.h \
		logica/ExecutiveUser.h \
		logica/Gruppo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Legami.o logica/Legami.cpp

Profilo.o: logica/Profilo.cpp logica/Profilo.h \
		logica/Xml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Profilo.o logica/Profilo.cpp

User.o: logica/User.cpp logica/User.h \
		logica/Profilo.h \
		logica/Contatto.h \
		logica/Legami.h \
		logica/Xml.h \
		logica/Gruppo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o User.o logica/User.cpp

Xml.o: logica/Xml.cpp logica/Xml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Xml.o logica/Xml.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

