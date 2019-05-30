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
    QString m_filePath;
    QGraphicsScene *m_pScene;
    Diagram *m_pAst;

    DiagramInfo(QString filePath = QString(), QGraphicsScene *pScene = nullptr,
                Diagram *pAst = nullptr);
    DiagramInfo(const DiagramInfo &other) = default;
    ~DiagramInfo();
};

Q_DECLARE_METATYPE(DiagramInfo);
Q_DECLARE_METATYPE(DiagramInfo*);

#endif // DIAGRAMINFO_H
