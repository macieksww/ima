// Generated by gencpp from file turtlesim/GetPose.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_GETPOSE_H
#define TURTLESIM_MESSAGE_GETPOSE_H

#include <ros/service_traits.h>


#include <turtlesim/GetPoseRequest.h>
#include <turtlesim/GetPoseResponse.h>


namespace turtlesim
{

struct GetPose
{

typedef GetPoseRequest Request;
typedef GetPoseResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetPose
} // namespace turtlesim


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::turtlesim::GetPose > {
  static const char* value()
  {
    return "d2e1f87d4f41d06b5a0b3a27a28052fe";
  }

  static const char* value(const ::turtlesim::GetPose&) { return value(); }
};

template<>
struct DataType< ::turtlesim::GetPose > {
  static const char* value()
  {
    return "turtlesim/GetPose";
  }

  static const char* value(const ::turtlesim::GetPose&) { return value(); }
};


// service_traits::MD5Sum< ::turtlesim::GetPoseRequest> should match
// service_traits::MD5Sum< ::turtlesim::GetPose >
template<>
struct MD5Sum< ::turtlesim::GetPoseRequest>
{
  static const char* value()
  {
    return MD5Sum< ::turtlesim::GetPose >::value();
  }
  static const char* value(const ::turtlesim::GetPoseRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlesim::GetPoseRequest> should match
// service_traits::DataType< ::turtlesim::GetPose >
template<>
struct DataType< ::turtlesim::GetPoseRequest>
{
  static const char* value()
  {
    return DataType< ::turtlesim::GetPose >::value();
  }
  static const char* value(const ::turtlesim::GetPoseRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::turtlesim::GetPoseResponse> should match
// service_traits::MD5Sum< ::turtlesim::GetPose >
template<>
struct MD5Sum< ::turtlesim::GetPoseResponse>
{
  static const char* value()
  {
    return MD5Sum< ::turtlesim::GetPose >::value();
  }
  static const char* value(const ::turtlesim::GetPoseResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlesim::GetPoseResponse> should match
// service_traits::DataType< ::turtlesim::GetPose >
template<>
struct DataType< ::turtlesim::GetPoseResponse>
{
  static const char* value()
  {
    return DataType< ::turtlesim::GetPose >::value();
  }
  static const char* value(const ::turtlesim::GetPoseResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TURTLESIM_MESSAGE_GETPOSE_H
