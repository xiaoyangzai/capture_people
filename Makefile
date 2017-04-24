#############################################################################
# Makefile for building: play_video
# Generated by qmake (2.01a) (Qt 4.6.3) on: Sat May 23 17:38:48 2015
# Project:  play_video.pro
# Template: app
# Command: /opt/Qt4.8/bin/qmake -unix -o Makefile play_video.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc
CXX           = arm-linux-g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/Qt4.8/mkspecs/qws/linux-arm-g++ -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtNetwork -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I/opt/mytslib/include
LINK          = arm-linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/Qt4.8/lib
LIBS          = $(SUBLIBS)  -L/opt/mytslib/lib -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/opt/mytslib/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /opt/Qt4.8/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
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
		mainwidget.cpp \
		videodevice.cpp moc_mainwidget.cpp \
		moc_videodevice.cpp
OBJECTS       = main.o \
		mainwidget.o \
		videodevice.o \
		moc_mainwidget.o \
		moc_videodevice.o
DIST          = /opt/Qt4.8/mkspecs/common/g++.conf \
		/opt/Qt4.8/mkspecs/common/unix.conf \
		/opt/Qt4.8/mkspecs/common/linux.conf \
		/opt/Qt4.8/mkspecs/common/qws.conf \
		/opt/Qt4.8/mkspecs/qconfig.pri \
		/opt/Qt4.8/mkspecs/features/qt_functions.prf \
		/opt/Qt4.8/mkspecs/features/qt_config.prf \
		/opt/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/opt/Qt4.8/mkspecs/features/default_pre.prf \
		/opt/Qt4.8/mkspecs/features/release.prf \
		/opt/Qt4.8/mkspecs/features/default_post.prf \
		/opt/Qt4.8/mkspecs/features/warn_on.prf \
		/opt/Qt4.8/mkspecs/features/qt.prf \
		/opt/Qt4.8/mkspecs/features/unix/thread.prf \
		/opt/Qt4.8/mkspecs/features/moc.prf \
		/opt/Qt4.8/mkspecs/features/resources.prf \
		/opt/Qt4.8/mkspecs/features/uic.prf \
		/opt/Qt4.8/mkspecs/features/yacc.prf \
		/opt/Qt4.8/mkspecs/features/lex.prf \
		/opt/Qt4.8/mkspecs/features/include_source_dir.prf \
		play_video.pro
QMAKE_TARGET  = play_video
DESTDIR       = 
TARGET        = play_video

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: play_video.pro  /opt/Qt4.8/mkspecs/qws/linux-arm-g++/qmake.conf /opt/Qt4.8/mkspecs/common/g++.conf \
		/opt/Qt4.8/mkspecs/common/unix.conf \
		/opt/Qt4.8/mkspecs/common/linux.conf \
		/opt/Qt4.8/mkspecs/common/qws.conf \
		/opt/Qt4.8/mkspecs/qconfig.pri \
		/opt/Qt4.8/mkspecs/features/qt_functions.prf \
		/opt/Qt4.8/mkspecs/features/qt_config.prf \
		/opt/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/opt/Qt4.8/mkspecs/features/default_pre.prf \
		/opt/Qt4.8/mkspecs/features/release.prf \
		/opt/Qt4.8/mkspecs/features/default_post.prf \
		/opt/Qt4.8/mkspecs/features/warn_on.prf \
		/opt/Qt4.8/mkspecs/features/qt.prf \
		/opt/Qt4.8/mkspecs/features/unix/thread.prf \
		/opt/Qt4.8/mkspecs/features/moc.prf \
		/opt/Qt4.8/mkspecs/features/resources.prf \
		/opt/Qt4.8/mkspecs/features/uic.prf \
		/opt/Qt4.8/mkspecs/features/yacc.prf \
		/opt/Qt4.8/mkspecs/features/lex.prf \
		/opt/Qt4.8/mkspecs/features/include_source_dir.prf \
		/opt/Qt4.8/lib/libQtGui.prl \
		/opt/Qt4.8/lib/libQtNetwork.prl \
		/opt/Qt4.8/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile play_video.pro
/opt/Qt4.8/mkspecs/common/g++.conf:
/opt/Qt4.8/mkspecs/common/unix.conf:
/opt/Qt4.8/mkspecs/common/linux.conf:
/opt/Qt4.8/mkspecs/common/qws.conf:
/opt/Qt4.8/mkspecs/qconfig.pri:
/opt/Qt4.8/mkspecs/features/qt_functions.prf:
/opt/Qt4.8/mkspecs/features/qt_config.prf:
/opt/Qt4.8/mkspecs/features/exclusive_builds.prf:
/opt/Qt4.8/mkspecs/features/default_pre.prf:
/opt/Qt4.8/mkspecs/features/release.prf:
/opt/Qt4.8/mkspecs/features/default_post.prf:
/opt/Qt4.8/mkspecs/features/warn_on.prf:
/opt/Qt4.8/mkspecs/features/qt.prf:
/opt/Qt4.8/mkspecs/features/unix/thread.prf:
/opt/Qt4.8/mkspecs/features/moc.prf:
/opt/Qt4.8/mkspecs/features/resources.prf:
/opt/Qt4.8/mkspecs/features/uic.prf:
/opt/Qt4.8/mkspecs/features/yacc.prf:
/opt/Qt4.8/mkspecs/features/lex.prf:
/opt/Qt4.8/mkspecs/features/include_source_dir.prf:
/opt/Qt4.8/lib/libQtGui.prl:
/opt/Qt4.8/lib/libQtNetwork.prl:
/opt/Qt4.8/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile play_video.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/play_video1.0.0 || $(MKDIR) .tmp/play_video1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/play_video1.0.0/ && $(COPY_FILE) --parents mainwidget.h videodevice.h .tmp/play_video1.0.0/ && $(COPY_FILE) --parents main.cpp mainwidget.cpp videodevice.cpp .tmp/play_video1.0.0/ && (cd `dirname .tmp/play_video1.0.0` && $(TAR) play_video1.0.0.tar play_video1.0.0 && $(COMPRESS) play_video1.0.0.tar) && $(MOVE) `dirname .tmp/play_video1.0.0`/play_video1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/play_video1.0.0


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

compiler_moc_header_make_all: moc_mainwidget.cpp moc_videodevice.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwidget.cpp moc_videodevice.cpp
moc_mainwidget.cpp: videodevice.h \
		mainwidget.h
	/opt/Qt4.8/bin/moc $(DEFINES) $(INCPATH) mainwidget.h -o moc_mainwidget.cpp

moc_videodevice.cpp: videodevice.h
	/opt/Qt4.8/bin/moc $(DEFINES) $(INCPATH) videodevice.h -o moc_videodevice.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp mainwidget.h \
		videodevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwidget.o: mainwidget.cpp mainwidget.h \
		videodevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwidget.o mainwidget.cpp

videodevice.o: videodevice.cpp videodevice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o videodevice.o videodevice.cpp

moc_mainwidget.o: moc_mainwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwidget.o moc_mainwidget.cpp

moc_videodevice.o: moc_videodevice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_videodevice.o moc_videodevice.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
