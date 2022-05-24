// Generated by gencpp from file turtlesim/HasTurtleResponse.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_HASTURTLERESPONSE_H
#define TURTLESIM_MESSAGE_HASTURTLERESPONSE_H


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
struct HasTurtleResponse_
{
  typedef HasTurtleResponse_<ContainerAllocator> Type;

  HasTurtleResponse_()
    : result(false)  {
    }
  HasTurtleResponse_(const ContainerAllocator& _alloc)
    : result(false)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::turtlesim::HasTurtleResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::HasTurtleResponse_<ContainerAllocator> const> ConstPtr;

}; // struct HasTurtleResponse_

typedef ::turtlesim::HasTurtleResponse_<std::allocator<void> > HasTurtleResponse;

typedef boost::shared_ptr< ::turtlesim::HasTurtleResponse > HasTurtleResponsePtr;
typedef boost::shared_ptr< ::turtlesim::HasTurtleResponse const> HasTurtleResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::HasTurtleResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlesim::HasTurtleResponse_<ContainerAllocator1> & lhs, const ::turtlesim::HasTurtleResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlesim::HasTurtleResponse_<ContainerAllocator1> & lhs, const ::turtlesim::HasTurtleResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::HasTurtleResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::HasTurtleResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::HasTurtleResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eb13ac1f1354ccecb7941ee8fa2192e8";
  }

  static const char* value(const ::turtlesim::HasTurtleResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeb13ac1f1354ccecULL;
  static const uint64_t static_value2 = 0xb7941ee8fa2192e8ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/HasTurtleResponse";
  }

  static const char* value(const ::turtlesim::HasTurtleResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool result\n"
;
  }

  static const char* value(const ::turtlesim::HasTurtleResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HasTurtleResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::HasTurtleResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim::HasTurtleResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_HASTURTLERESPONSE_H
