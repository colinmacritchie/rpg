/* Entity_HPP */
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <JsonBox.h>
#include <string>

class EntityManager;

class Entity
{

    public:

    std::string id;
    Entity(std::string id)
    {
    
        this->id = id;
    
    }    

    /* Destructor must be made virtual as all derived classes
     * treated as Entity in the EntityManager
    */
    virtual ~Entity() {}

    /* Pure virtual function stops Entity from being instantiated and forces it
     * to be implemented  in all drived types
    */
    virtual void load(JsonBox::Value& v, EntityManager* mgr) = 0;



};

#endif /* ENTITY_HPP */
