// Generated by gencpp from file turtlesim/GetSonarRequest.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_GETSONARREQUEST_H
#define TURTLESIM_MESSAGE_GETSONARREQUEST_H


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
struct GetSonarRequest_
{
  typedef GetSonarRequest_<ContainerAllocator> Type;

  GetSonarRequest_()
    : fov_center(0.0)
    , fov_range(0.0)
    , range_min(0.0)
    , range_max(0.0)
    , name()  {
    }
  GetSonarRequest_(const ContainerAllocator& _alloc)
    : fov_center(0.0)
    , fov_range(0.0)
    , range_min(0.0)
    , range_max(0.0)
    , name(_alloc)  {
  (void)_alloc;
    }



   typedef float _fov_center_type;
  _fov_center_type fov_center;

   typedef float _fov_range_type;
  _fov_range_type fov_range;

   typedef float _range_min_type;
  _range_min_type range_min;

   typedef float _range_max_type;
  _range_max_type range_max;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;





  typedef boost::shared_ptr< ::turtlesim::GetSonarRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::GetSonarRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetSonarRequest_

typedef ::turtlesim::GetSonarRequest_<std::allocator<void> > GetSonarRequest;

typedef boost::shared_ptr< ::turtlesim::GetSonarRequest > GetSonarRequestPtr;
typedef boost::shared_ptr< ::turtlesim::GetSonarRequest const> GetSonarRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::GetSonarRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::GetSonarRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlesim::GetSonarRequest_<ContainerAllocator1> & lhs, const ::turtlesim::GetSonarRequest_<ContainerAllocator2> & rhs)
{
  return lhs.fov_center == rhs.fov_center &&
    lhs.fov_range == rhs.fov_range &&
    lhs.range_min == rhs.range_min &&
    lhs.range_max == rhs.range_max &&
    lhs.name == rhs.name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlesim::GetSonarRequest_<ContainerAllocator1> & lhs, const ::turtlesim::GetSonarRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetSonarRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetSonarRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetSonarRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "806295c5008144c60089d69500f850f0";
  }

  static const char* value(const ::turtlesim::GetSonarRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x806295c5008144c6ULL;
  static const uint64_t static_value2 = 0x0089d69500f850f0ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/GetSonarRequest";
  }

  static const char* value(const ::turtlesim::GetSonarRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 fov_center\n"
"float32 fov_range\n"
"float32 range_min\n"
"float32 range_max\n"
"string name\n"
;
  }

  static const char* value(const ::turtlesim::GetSonarRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.fov_center);
      stream.next(m.fov_range);
      stream.next(m.range_min);
      stream.next(m.range_max);
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetSonarRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::GetSonarRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim::GetSonarRequest_<ContainerAllocator>& v)
  {
    s << indent << "fov_center: ";
    Printer<float>::stream(s, indent + "  ", v.fov_center);
    s << indent << "fov_range: ";
    Printer<float>::stream(s, indent + "  ", v.fov_range);
    s << indent << "range_min: ";
    Printer<float>::stream(s, indent + "  ", v.range_min);
    s << indent << "range_max: ";
    Printer<float>::stream(s, indent + "  ", v.range_max);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_GETSONARREQUEST_H
