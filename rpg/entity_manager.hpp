/* entity_manager_hpp */
#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <string>
#include <map>

#include "entity.hpp"

class EntityManager
{

    private:
        std::map<std::string, Entity*> data;


    public:

    template<typename T>
    void loadJson(std::string filename);
    
    template<typename T>
    T* getEntity(std::string id);


    // constructor
    EntityManager();


    // Desctuctor
    ~EntityManager();
        
};

template<typename T>
    std::string entityToString();


#endif /* ENTITY_MANAGER_HPP */    
