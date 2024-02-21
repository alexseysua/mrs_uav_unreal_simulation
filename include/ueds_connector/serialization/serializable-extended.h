// Copyright [2022] <Jakub Jirkal>
// This code is licensed under MIT license (see LICENSE for details)

#pragma once

#include <memory>

#include "../data-types.h"
#include "serializable-shared.h"

namespace Serializable::Drone::GetLocation {
  inline std::unique_ptr<ueds_connector::Coordinates> ResponseToCoordinates(std::unique_ptr<Response> response) {
    return std::make_unique<ueds_connector::Coordinates>(response->x, response->y, response->z);
  }
}

namespace Serializable::Drone::SetLocation {
  inline std::unique_ptr<Request> CoordinateToRequest(const ueds_connector::Coordinates& coordinate) {
    auto request = std::make_unique<Request>();
    request->x = coordinate.x;
    request->y = coordinate.y;
    request->z = coordinate.z;
    return request;
  }
}

namespace Serializable::Drone::GetRotation {
inline std::unique_ptr<ueds_connector::Rotation> ResponseToRotation(std::unique_ptr<Response> response) {
    return std::make_unique<ueds_connector::Rotation>(response->pitch, response->yaw, response->roll);
}
}

namespace Serializable::Drone::SetRotation {
inline std::unique_ptr<Request> RotationToRequest(const ueds_connector::Rotation& rotation) {
    auto request = std::make_unique<Request>();
    request->pitch = rotation.pitch;
    request->yaw = rotation.yaw;
    request->roll = rotation.roll;
    return request;
}
}

namespace Serializable::Drone::SetLocationAndRotation {
inline std::unique_ptr<Request> ToRequest(const ueds_connector::Coordinates& location, const ueds_connector::Rotation& rotation) {
    auto request = std::make_unique<Request>();
    request->x = location.x;
    request->y = location.y;
    request->z = location.z;
    request->pitch = rotation.pitch;
    request->yaw = rotation.yaw;
    request->roll = rotation.roll;
    return request;
}
}  // namespace Serializable::Drone::SetLocationAndRotation
