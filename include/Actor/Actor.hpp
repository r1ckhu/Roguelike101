#pragma once
#include <SDL.h>

#include <memory>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

class Stage;
class Actor {
  public:
   virtual ~Actor() = default;

   virtual void process(Stage* game_info) = 0;
   virtual void processInput(Stage* game_info, SDL_Event& event) = 0;

   template <typename T>
   void addComponent(std::shared_ptr<T> component) {
      components_[std::type_index(typeid(T))] = component;
   }

   template <typename T>
   std::shared_ptr<T> getComponent() const {
      auto it = components_.find(std::type_index(typeid(T)));
      if (it != components_.end()) {
         return std::static_pointer_cast<T>(it->second);
      }
      throw std::runtime_error("Component not found");
   }

   int x, y;
  private:
   std::unordered_map<std::type_index, std::shared_ptr<void>> components_;
};