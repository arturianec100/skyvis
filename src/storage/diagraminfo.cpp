#include "diagraminfo.h"
#include "../common.h"


DiagramInfo::DiagramInfo(QFile *file, QGraphicsScene *scene, Diagram *ast) :
    m_pFile(file), m_pScene(scene), m_pAst(ast)
{

}

DiagramInfo::~DiagramInfo()
{
    SAFE_DELETE(m_pFile)
    SAFE_DELETE(m_pScene)
    SAFE_DELETE(m_pAst)
}
