QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/views/AddColumnView.cpp \
    src/views/CreatePlannerItemDialog.cpp \
    src/views/MainWindow.cpp \
    src/views/PlannerColumn.cpp \
    src/views/PlannerItemCard.cpp \
    src/views/PlannerItemDetailsDialog.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    src/views/AddColumnView.ui \
    src/views/CreatePlannerItemDialog.ui \
    src/views/MainWindow.ui \
    src/views/PlannerColumn.ui \
    src/views/PlannerItemCard.ui \
    src/views/PlannerItemDetailsDialog.ui

HEADERS += \
    src/views/AddColumnView.h \
    src/views/CreatePlannerItemDialog.h \
    src/views/MainWindow.h \
    src/views/PlannerColumn.h \
    src/views/PlannerItemCard.h \
    src/views/PlannerItemDetailsDialog.h
