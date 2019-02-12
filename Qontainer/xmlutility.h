#ifndef XMLUTILITY_H
#define XMLUTILITY_H

#include"Model/laptop.h"
#include"Model/desktop.h"
#include"Model/smartphone.h"
#include"Model/tablet.h"
#include"Model/container.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

namespace XMLUtility{
Device* gatherDevice(QXmlStreamReader&);
Container<Device*>* loadDevices();
void saveDevices(Container<Device*>*);
void ModifyElement(int ,std::string ,std::string );
void DeleteElement(std::string);
void DeleteElementField(std::string tipo,std::string campo, std::string valore);
}

#endif // XMLUTILITY_H
