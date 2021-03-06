//
// Created by Trần Công Việt An on 17/5/20.
//

#pragma once


#include <engine/object/object.hpp>

#include "healthbar.hpp"


class Player : public GameObject {
private:
  int size;
  double speed;
  int lastShoot = 0;
  bool onAir = false;
  void jump();
  void shoot(const Geometry::Point& target, double bulletVelocity);
  Texture texture;
  Healthbar* healthbar;

public:
  Player(const Geometry::Point& position, double speed, Healthbar* health);
  void render() override;
  void onKeyDown(SDL_Keycode key) override;
  void onKeyUp(SDL_Keycode key) override;
  void onMouseDown(const Geometry::Point  &p) override;
  void onCollide(GameObject* otherObject) override;
};
