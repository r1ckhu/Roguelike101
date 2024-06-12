#pragma once
#include <SDL.h>

#include <memory>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

class Stage;
class Actor {
  public:
   virtual void process(Stage* game_info, SDL_Event event) = 0;
   int x, y;

   template <typename T>
   std::shared_ptr<T> addComponent(std::shared_ptr<T> component) {
      components_[std::type_index(typeid(T))] = component;
      return std::make_shared<T>(component);
   }

   template <typename T>
   std::shared_ptr<T> getComponent() const {
      auto it = components_.find(std::type_index(typeid(T)));
      if (it != components_.end()) {
         return std::static_pointer_cast<T>(it->second);
      }
      throw std::runtime_error("Component not found");
   }

  private:
   std::unordered_map<std::type_index, std::shared_ptr<void>> components_;
};