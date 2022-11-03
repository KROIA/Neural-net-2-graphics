

include(Extern/SFML_EditorWidget/SFML_EditorWidget.pri)
include(Extern/Neural-net-2/Neural-net-2.pri)

inc = $$PWD/inc
src = $$PWD/src

INCLUDEPATH +=  $$inc

DEFINES += QT_NEURAL_NET

HEADERS += \
    $$inc/connectionPainter.h \
    $$inc/graphicsUtilities.h \
    $$inc/netModel.h \
    $$inc/neuronPainter.h \
    $$inc/pixelPainter.h

SOURCES += \
    $$src/connectionPainter.cpp \
    $$src/graphicsUtilities.cpp \
    $$src/netModel.cpp \
    $$src/neuronPainter.cpp \
    $$src/pixelPainter.cpp
