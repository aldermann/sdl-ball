//
// Created by Trần Công Việt An on 2/5/20.
//

#pragma once

#include <unordered_set>

#include "engine/object/bounding_box/bounding_box.hpp"
#include "engine/physics/dynamic.hpp"

class GameObject {
  friend class GameManager;

protected:
  BoundingBox::Box *boundingBox;
  Physics::Dynamic dynamic;
  bool solid;

public:
  int type = 0;
  GameObject();
  GameObject(BoundingBox::Box *bounding, Physics::Dynamic dynamic, bool solid);
  GameObject(BoundingBox::Box *bounding, const Physics::Dynamic &dynamic);
  GameObject(BoundingBox::Box *bounding,
             const Geometry::Point &position,
             double mass,
             double elasticity,
             bool solid);

  virtual ~GameObject();
  [[nodiscard]] const Geometry::Point &position() const;

private:
  void innerRender();
  static void handleCollision(GameObject *ob1, GameObject *ob2, double time);

public:
  void destroy();
  virtual void render();
  virtual void tick(double delta);
  virtual void onKeyDown(SDL_Keycode key);
  virtual void onKeyUp(SDL_Keycode key);
  virtual void onCollide(GameObject *otherObject);
  virtual void onMouseDown(const Geometry::Point &p);
};
