#ifndef DIAGRAMSPACE_H
#define DIAGRAMSPACE_H

#include <QtCore>
#include <QtWidgets>
#include "../storage/diagraminfo.h"
#include "../storage/diagramstorage.h"

/*!
 * \brief The fasade for all diagram related stuff
 * \author arturianec100
 */
class DiagramSpace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QTabWidget tabs READ tabs)
public:
    using TabViewPair = QPair<QTab *, QGraphicsView *>;

    explicit DiagramSpace(QObject *parent, QTabWidget *pTabs);
    virtual ~DiagramSpace() override = default;

    QTabWidget *tabs() const;

signals:
    // TODO: connect with storage
    void diagramOpeningRequested(QString fileName);
    void diagramClosingRequested(QString fileName);

public slots:
    void openDiagram(QString fileName);
    void closeDiagram(int index);

    void showOpenedDiagram(DiagramInfo *pDiagram);

private:
    QTabWidget *m_pTabs;
    DiagramStorage *m_pStorage;
    QMap<int, DiagramInfo *> m_diagramIndexes;
};

#endif // DIAGRAMSPACE_H
