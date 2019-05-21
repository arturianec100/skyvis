#ifndef DIAGRAMINFO_H
#define DIAGRAMINFO_H

#include <QtCore>
#include <QtWidgets>
#include "../ast/diagram.h"

struct DiagramInfo {
    QFile *file;
    QGraphicsScene *scene;
    Diagram *ast;

    DiagramInfo() = default;
    DiagramInfo(const DiagramInfo &other) = default;
    ~DiagramInfo() = default;
};

Q_DECLARE_METATYPE(DiagramInfo);

#endif // DIAGRAMINFO_H
