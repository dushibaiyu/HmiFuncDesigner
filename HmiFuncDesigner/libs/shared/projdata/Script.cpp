#include "script.h"

Script::Script()
{
    m_scriptObjects.clear();
}

Script::~Script()
{
    qDeleteAll(m_scriptObjects);
    m_scriptObjects.clear();
}


void Script::AddScriptObject(ScriptObject *obj)
{
    int pos = m_scriptObjects.indexOf(obj);
    if (pos == -1) {
        m_scriptObjects.append(obj);
    }
}

void Script::ModifyScriptObject(ScriptObject *oldobj, ScriptObject *newobj)
{
    int pos = m_scriptObjects.indexOf(oldobj);
    if (pos == -1) {
        return;
    }
    m_scriptObjects.replace(pos, newobj);
}

void Script::DeleteScriptObject(ScriptObject *obj)
{
    m_scriptObjects.removeOne(obj);
}

ScriptObject *Script::GetScriptObject(const QString &szName)
{
    foreach (ScriptObject *pobj, m_scriptObjects) {
        if (pobj->m_name == szName) {
            return pobj;
        }
    }
    return NULL;
}


bool Script::openFromXml(XMLObject *pXmlObj)
{
    qDeleteAll(m_scriptObjects);
    m_scriptObjects.clear();
    XMLObject *pScriptsObj = pXmlObj->getCurrentChild("scripts");
    if(pScriptsObj == NULL) {
        return false;
    }
    QVector<XMLObject* > listScriptsObj = pScriptsObj->getCurrentChildren("script");
    foreach(XMLObject* pScriptObj, listScriptsObj) {
        ScriptObject *pObj = new ScriptObject();
        pObj->m_name = pScriptObj->getProperty("name");
        pObj->m_inUse = pScriptObj->getProperty("in_use") == "1";
        pObj->m_desc = pScriptObj->getProperty("desc");
        pObj->m_runMode = pScriptObj->getProperty("run_mode");
        pObj->m_runModeArgs = pScriptObj->getProperty("run_mode_args");
        pObj->m_scriptText = pScriptObj->getText();
        m_scriptObjects.append(pObj);
    }
    return true;
}


bool Script::saveToXml(XMLObject *pXmlObj)
{
    XMLObject *pScriptsObj = new XMLObject(pXmlObj);
    pScriptsObj->setTagName("scripts");
    for (int i = 0; i < m_scriptObjects.size(); i++) {
        ScriptObject *pObj = m_scriptObjects.at(i);
        XMLObject *pScriptObj = new XMLObject(pScriptsObj);
        pScriptObj->setTagName("script");
        pScriptObj->setProperty("name", pObj->m_name);
        pScriptObj->setProperty("in_use", pObj->m_inUse ? "1" : "0");
        pScriptObj->setProperty("desc", pObj->m_desc);
        pScriptObj->setProperty("run_mode", pObj->m_runMode);
        pScriptObj->setProperty("run_mode_args", pObj->m_runModeArgs);
        pScriptObj->setText(pObj->m_scriptText);
    }
    return true;
}




