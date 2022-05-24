// Generated by gencpp from file package_303770/ranges.msg
// DO NOT EDIT!


#ifndef PACKAGE_303770_MESSAGE_RANGES_H
#define PACKAGE_303770_MESSAGE_RANGES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace package_303770
{
template <class ContainerAllocator>
struct ranges_
{
  typedef ranges_<ContainerAllocator> Type;

  ranges_()
    : ranges()  {
    }
  ranges_(const ContainerAllocator& _alloc)
    : ranges(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _ranges_type;
  _ranges_type ranges;





  typedef boost::shared_ptr< ::package_303770::ranges_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::package_303770::ranges_<ContainerAllocator> const> ConstPtr;

}; // struct ranges_

typedef ::package_303770::ranges_<std::allocator<void> > ranges;

typedef boost::shared_ptr< ::package_303770::ranges > rangesPtr;
typedef boost::shared_ptr< ::package_303770::ranges const> rangesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::package_303770::ranges_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::package_303770::ranges_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::package_303770::ranges_<ContainerAllocator1> & lhs, const ::package_303770::ranges_<ContainerAllocator2> & rhs)
{
  return lhs.ranges == rhs.ranges;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::package_303770::ranges_<ContainerAllocator1> & lhs, const ::package_303770::ranges_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace package_303770

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::package_303770::ranges_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::package_303770::ranges_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::package_303770::ranges_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::package_303770::ranges_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package_303770::ranges_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package_303770::ranges_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::package_303770::ranges_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b59fbb52705f63cb3fada08d311c9c4d";
  }

  static const char* value(const ::package_303770::ranges_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb59fbb52705f63cbULL;
  static const uint64_t static_value2 = 0x3fada08d311c9c4dULL;
};

template<class ContainerAllocator>
struct DataType< ::package_303770::ranges_<ContainerAllocator> >
{
  static const char* value()
  {
    return "package_303770/ranges";
  }

  static const char* value(const ::package_303770::ranges_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::package_303770::ranges_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[] ranges\n"
;
  }

  static const char* value(const ::package_303770::ranges_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::package_303770::ranges_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ranges);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ranges_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::package_303770::ranges_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::package_303770::ranges_<ContainerAllocator>& v)
  {
    s << indent << "ranges[]" << std::endl;
    for (size_t i = 0; i < v.ranges.size(); ++i)
    {
      s << indent << "  ranges[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.ranges[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PACKAGE_303770_MESSAGE_RANGES_H