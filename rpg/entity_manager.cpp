/* ENTITY_MANAGER_CPP */

#include <string>
#include <map>

#include "entity_manager.hpp"

template <class T>
void EntityManager::loadJson(std::string filename)
{

    JsonBox::Value v;
    v.loadFromFile(filename);

    JsonBox::Object o =  v.getObject();
    for (auto entity : o)
    {
    
        std::string key = entity.first;
        this->data[key] = dynamic_cast<Entity*>(new T(key, entity.second, this));
        
    }
}

template <class T>
T* EntityManager::getEntity(std::string id)
{

    if(id.substr(0, entityToString<T>().size()) == entityToString<T>())
        return dynamic_cast<T*>(this->data.at(id));

    else
        return nullptr;
}

EntityManager::EntityManager() {}
EntityManager::~EntityManager()
{

    for(auto& entity : this->data)
    {
    
        delete entity.second;
    
    }

} 
    

