// Generated by gencpp from file package_303770/pose_actionActionGoal.msg
// DO NOT EDIT!


#ifndef PACKAGE_303770_MESSAGE_POSE_ACTIONACTIONGOAL_H
#define PACKAGE_303770_MESSAGE_POSE_ACTIONACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <package_303770/pose_actionGoal.h>

namespace package_303770
{
template <class ContainerAllocator>
struct pose_actionActionGoal_
{
  typedef pose_actionActionGoal_<ContainerAllocator> Type;

  pose_actionActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  pose_actionActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::package_303770::pose_actionGoal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::package_303770::pose_actionActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::package_303770::pose_actionActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct pose_actionActionGoal_

typedef ::package_303770::pose_actionActionGoal_<std::allocator<void> > pose_actionActionGoal;

typedef boost::shared_ptr< ::package_303770::pose_actionActionGoal > pose_actionActionGoalPtr;
typedef boost::shared_ptr< ::package_303770::pose_actionActionGoal const> pose_actionActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::package_303770::pose_actionActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::package_303770::pose_actionActionGoal_<ContainerAllocator1> & lhs, const ::package_303770::pose_actionActionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.goal_id == rhs.goal_id &&
    lhs.goal == rhs.goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::package_303770::pose_actionActionGoal_<ContainerAllocator1> & lhs, const ::package_303770::pose_actionActionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace package_303770

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::package_303770::pose_actionActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::package_303770::pose_actionActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::package_303770::pose_actionActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a0bdbbb3bfdac1eb4a50ba792052760a";
  }

  static const char* value(const ::package_303770::pose_actionActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa0bdbbb3bfdac1ebULL;
  static const uint64_t static_value2 = 0x4a50ba792052760aULL;
};

template<class ContainerAllocator>
struct DataType< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "package_303770/pose_actionActionGoal";
  }

  static const char* value(const ::package_303770::pose_actionActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"pose_actionGoal goal\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: package_303770/pose_actionGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#goal\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::package_303770::pose_actionActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pose_actionActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::package_303770::pose_actionActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::package_303770::pose_actionActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::package_303770::pose_actionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PACKAGE_303770_MESSAGE_POSE_ACTIONACTIONGOAL_H