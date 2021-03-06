//
// Created by Trần Công Việt An on 2/5/20.
//

#include "bounding_box.hpp"

#include <iostream>

#include "engine/render/renderer.hpp"

namespace BoundingBox {
  // Box
  Box::~Box() = default;

  bool Box::checkCollision(const Geometry::Point &position,
                           const Geometry::Point &otherPosition,
                           Box *otherBox) {
    switch (otherBox->getShape()) {
      case Rectangle:
        return checkCollisionRect(position, otherPosition, (RectangleBox *) otherBox);
      case Circle:
        return checkCollisionCirc(position, otherPosition, (CircleBox *) otherBox);
    }
    return false;
  }

  Geometry::Vector Box::normalCollisionVector(const Geometry::Point &pos,
                                              const Geometry::Point &otherPos,
                                              Box *otherBox) {
    switch (otherBox->getShape()) {
      case Rectangle:
        return normalCollisionVectorRect(pos, otherPos, (RectangleBox *) otherBox);
      case Circle:
        return normalCollisionVectorCirc(pos, otherPos, (CircleBox *) otherBox);
    }
    return {};
  }
}// namespace BoundingBox
