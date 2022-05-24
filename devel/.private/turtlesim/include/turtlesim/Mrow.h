// Generated by gencpp from file turtlesim/Mrow.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_MROW_H
#define TURTLESIM_MESSAGE_MROW_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <turtlesim/Cell.h>

namespace turtlesim
{
template <class ContainerAllocator>
struct Mrow_
{
  typedef Mrow_<ContainerAllocator> Type;

  Mrow_()
    : cells()  {
    }
  Mrow_(const ContainerAllocator& _alloc)
    : cells(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::turtlesim::Cell_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::turtlesim::Cell_<ContainerAllocator> >::other >  _cells_type;
  _cells_type cells;





  typedef boost::shared_ptr< ::turtlesim::Mrow_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::Mrow_<ContainerAllocator> const> ConstPtr;

}; // struct Mrow_

typedef ::turtlesim::Mrow_<std::allocator<void> > Mrow;

typedef boost::shared_ptr< ::turtlesim::Mrow > MrowPtr;
typedef boost::shared_ptr< ::turtlesim::Mrow const> MrowConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::Mrow_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::Mrow_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlesim::Mrow_<ContainerAllocator1> & lhs, const ::turtlesim::Mrow_<ContainerAllocator2> & rhs)
{
  return lhs.cells == rhs.cells;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlesim::Mrow_<ContainerAllocator1> & lhs, const ::turtlesim::Mrow_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::Mrow_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::Mrow_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::Mrow_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::Mrow_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::Mrow_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::Mrow_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::Mrow_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dc4d4a6faec42c0efee83680cff86b79";
  }

  static const char* value(const ::turtlesim::Mrow_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdc4d4a6faec42c0eULL;
  static const uint64_t static_value2 = 0xfee83680cff86b79ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::Mrow_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/Mrow";
  }

  static const char* value(const ::turtlesim::Mrow_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::Mrow_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Cell[] cells\n"
"\n"
"================================================================================\n"
"MSG: turtlesim/Cell\n"
"float32 red\n"
"float32 green \n"
"float32 blue\n"
"float32 distance \n"
"float32 occupy \n"
;
  }

  static const char* value(const ::turtlesim::Mrow_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::Mrow_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cells);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Mrow_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::Mrow_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim::Mrow_<ContainerAllocator>& v)
  {
    s << indent << "cells[]" << std::endl;
    for (size_t i = 0; i < v.cells.size(); ++i)
    {
      s << indent << "  cells[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::turtlesim::Cell_<ContainerAllocator> >::stream(s, indent + "    ", v.cells[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_MROW_H
