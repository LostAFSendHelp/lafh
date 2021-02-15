QT       += core gui network networkauth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/services/JiraClient.cpp \
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

CONFIG += warn_off

HEADERS += \
    src/services/JiraClient.h \
    src/views/AddColumnView.h \
    src/views/CreatePlannerItemDialog.h \
    src/views/MainWindow.h \
    src/views/PlannerColumn.h \
    src/views/PlannerItemCard.h \
    src/views/PlannerItemDetailsDialog.h

INCLUDEPATH += \
    src/

DISTFILES += \
    assets/credentials.json \
    assets/placeholder.txt

CONFIG(debug, debug|release) {
    path = debug
}

CONFIG(release, debug|release) {
    path = release
}

message(Building for config: $$path)

win32 {
    QMAKE_POST_LINK += robocopy $$PWD/assets $$OUT_PWD/$$path/assets /E >nul
}
