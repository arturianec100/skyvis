#ifndef DIAGRAMINFO_H
#define DIAGRAMINFO_H

#include <QtCore>
#include <QtWidgets>
#include "../ast/diagram.h"

/*!
 * \brief The _low level_ struct that contain data required for DiagramStorage
 * \author arturianec100
 */
struct DiagramInfo {
    QFile *m_pFile;
    QGraphicsScene *m_pScene;
    Diagram *m_pAst;

    DiagramInfo(QFile *file = nullptr, QGraphicsScene *scene = nullptr,
                Diagram *ast = nullptr);
    DiagramInfo(const DiagramInfo &other) = default;
    ~DiagramInfo();
};

Q_DECLARE_METATYPE(DiagramInfo);

#endif // DIAGRAMINFO_H
