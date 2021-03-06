// Generated by gencpp from file turtlesim/GetFrameSizeRequest.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_GETFRAMESIZEREQUEST_H
#define TURTLESIM_MESSAGE_GETFRAMESIZEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtlesim
{
template <class ContainerAllocator>
struct GetFrameSizeRequest_
{
  typedef GetFrameSizeRequest_<ContainerAllocator> Type;

  GetFrameSizeRequest_()
    {
    }
  GetFrameSizeRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetFrameSizeRequest_

typedef ::turtlesim::GetFrameSizeRequest_<std::allocator<void> > GetFrameSizeRequest;

typedef boost::shared_ptr< ::turtlesim::GetFrameSizeRequest > GetFrameSizeRequestPtr;
typedef boost::shared_ptr< ::turtlesim::GetFrameSizeRequest const> GetFrameSizeRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::turtlesim::GetFrameSizeRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/GetFrameSizeRequest";
  }

  static const char* value(const ::turtlesim::GetFrameSizeRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::turtlesim::GetFrameSizeRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetFrameSizeRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::GetFrameSizeRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::turtlesim::GetFrameSizeRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_GETFRAMESIZEREQUEST_H
