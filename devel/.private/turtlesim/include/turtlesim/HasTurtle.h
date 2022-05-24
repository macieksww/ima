// Generated by gencpp from file turtlesim/HasTurtle.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_HASTURTLE_H
#define TURTLESIM_MESSAGE_HASTURTLE_H

#include <ros/service_traits.h>


#include <turtlesim/HasTurtleRequest.h>
#include <turtlesim/HasTurtleResponse.h>


namespace turtlesim
{

struct HasTurtle
{

typedef HasTurtleRequest Request;
typedef HasTurtleResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct HasTurtle
} // namespace turtlesim


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::turtlesim::HasTurtle > {
  static const char* value()
  {
    return "ee91d68745ef4d7a247816a59dffedf2";
  }

  static const char* value(const ::turtlesim::HasTurtle&) { return value(); }
};

template<>
struct DataType< ::turtlesim::HasTurtle > {
  static const char* value()
  {
    return "turtlesim/HasTurtle";
  }

  static const char* value(const ::turtlesim::HasTurtle&) { return value(); }
};


// service_traits::MD5Sum< ::turtlesim::HasTurtleRequest> should match
// service_traits::MD5Sum< ::turtlesim::HasTurtle >
template<>
struct MD5Sum< ::turtlesim::HasTurtleRequest>
{
  static const char* value()
  {
    return MD5Sum< ::turtlesim::HasTurtle >::value();
  }
  static const char* value(const ::turtlesim::HasTurtleRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlesim::HasTurtleRequest> should match
// service_traits::DataType< ::turtlesim::HasTurtle >
template<>
struct DataType< ::turtlesim::HasTurtleRequest>
{
  static const char* value()
  {
    return DataType< ::turtlesim::HasTurtle >::value();
  }
  static const char* value(const ::turtlesim::HasTurtleRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::turtlesim::HasTurtleResponse> should match
// service_traits::MD5Sum< ::turtlesim::HasTurtle >
template<>
struct MD5Sum< ::turtlesim::HasTurtleResponse>
{
  static const char* value()
  {
    return MD5Sum< ::turtlesim::HasTurtle >::value();
  }
  static const char* value(const ::turtlesim::HasTurtleResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlesim::HasTurtleResponse> should match
// service_traits::DataType< ::turtlesim::HasTurtle >
template<>
struct DataType< ::turtlesim::HasTurtleResponse>
{
  static const char* value()
  {
    return DataType< ::turtlesim::HasTurtle >::value();
  }
  static const char* value(const ::turtlesim::HasTurtleResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TURTLESIM_MESSAGE_HASTURTLE_H
