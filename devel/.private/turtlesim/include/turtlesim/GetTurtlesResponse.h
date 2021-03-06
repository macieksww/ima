// Generated by gencpp from file turtlesim/GetTurtlesResponse.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_GETTURTLESRESPONSE_H
#define TURTLESIM_MESSAGE_GETTURTLESRESPONSE_H


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
struct GetTurtlesResponse_
{
  typedef GetTurtlesResponse_<ContainerAllocator> Type;

  GetTurtlesResponse_()
    : list()  {
    }
  GetTurtlesResponse_(const ContainerAllocator& _alloc)
    : list(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _list_type;
  _list_type list;





  typedef boost::shared_ptr< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetTurtlesResponse_

typedef ::turtlesim::GetTurtlesResponse_<std::allocator<void> > GetTurtlesResponse;

typedef boost::shared_ptr< ::turtlesim::GetTurtlesResponse > GetTurtlesResponsePtr;
typedef boost::shared_ptr< ::turtlesim::GetTurtlesResponse const> GetTurtlesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::GetTurtlesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlesim::GetTurtlesResponse_<ContainerAllocator1> & lhs, const ::turtlesim::GetTurtlesResponse_<ContainerAllocator2> & rhs)
{
  return lhs.list == rhs.list;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlesim::GetTurtlesResponse_<ContainerAllocator1> & lhs, const ::turtlesim::GetTurtlesResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8e09fa9aad51508cfdcab3b64f048ce0";
  }

  static const char* value(const ::turtlesim::GetTurtlesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8e09fa9aad51508cULL;
  static const uint64_t static_value2 = 0xfdcab3b64f048ce0ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/GetTurtlesResponse";
  }

  static const char* value(const ::turtlesim::GetTurtlesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] list\n"
"\n"
;
  }

  static const char* value(const ::turtlesim::GetTurtlesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.list);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetTurtlesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::GetTurtlesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim::GetTurtlesResponse_<ContainerAllocator>& v)
  {
    s << indent << "list[]" << std::endl;
    for (size_t i = 0; i < v.list.size(); ++i)
    {
      s << indent << "  list[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.list[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_GETTURTLESRESPONSE_H
