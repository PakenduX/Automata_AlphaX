TEMPLATE = app

QT += \
     widgets \
     webengine \


HEADERS += \
    readautomata.h \
    threesome.h

SOURCES += \
    readautomata.cpp \
    threesome.cpp \
    main.cpp

mac: LIBS += -framework CoreFoundation
else:unix|win32: LIBS += -lCoreFoundation

RESOURCES += \
    automata.qrc

DISTFILES += \
    web/vendor/arbor.js \
    web/vendor/cola.v3.min.js \
    web/vendor/cytoscape.js \
    web/vendor/cytoscape.min.js \
    web/vendor/dagre.js \
    web/vendor/foograph.js \
    web/vendor/jquery-3.1.0.min.js \
    web/vendor/rhill-voronoi-core.js \
    web/vendor/springy.js \
    web/graph.js \
    web/graph.html
