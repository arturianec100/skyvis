#include "diagraminfo.h"
#include "../common.h"


DiagramInfo::DiagramInfo(QString filePath, QGraphicsScene *pScene, Diagram *pAst) :
    m_filePath(filePath), m_pScene(pScene), m_pAst(pAst)
{

}

DiagramInfo::~DiagramInfo()
{
    SAFE_DELETE(m_pScene)
    SAFE_DELETE(m_pAst)
}
