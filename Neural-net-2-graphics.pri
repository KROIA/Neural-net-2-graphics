

include(Extern/SFML_EditorWidget/SFML_EditorWidget.pri)
include(Extern/Neural-net-2/Neural-net-2.pri)

inc = $$PWD/inc
src = $$PWD/src

INCLUDEPATH +=  $$inc

HEADERS += \
    $$inc/connectionPainter.h \
    #$$inc/display.h \
    #$$inc/displayInterface.h \
    #$$inc/drawable.h \
    #$$inc/drawableInterface.h \
    $$inc/graphicsUtilities.h \
    $$inc/netModel.h \
    $$inc/neuronPainter.h \
    $$inc/pixelPainter.h

SOURCES += \
    $$src/connectionPainter.cpp \
    #$$src/display.cpp \
    #$$src/drawable.cpp \
    $$src/graphicsUtilities.cpp \
    $$src/netModel.cpp \
    $$src/neuronPainter.cpp \
    $$src/pixelPainter.cpp
