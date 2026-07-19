#include "AIManager.h"

AIManager::AIManager(QObject* parent)
    : QObject(parent)
{

}

AIManager::~AIManager() = default;

bool AIManager::Initialize()
{
    return true;
}