// Generated by gencpp from file turtlesim/GetCameraImageResponse.msg
// DO NOT EDIT!


#ifndef TURTLESIM_MESSAGE_GETCAMERAIMAGERESPONSE_H
#define TURTLESIM_MESSAGE_GETCAMERAIMAGERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>
#include <turtlesim/Mrow.h>

namespace turtlesim
{
template <class ContainerAllocator>
struct GetCameraImageResponse_
{
  typedef GetCameraImageResponse_<ContainerAllocator> Type;

  GetCameraImageResponse_()
    : image()
    , m_rows()  {
    }
  GetCameraImageResponse_(const ContainerAllocator& _alloc)
    : image(_alloc)
    , m_rows(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _image_type;
  _image_type image;

   typedef std::vector< ::turtlesim::Mrow_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::turtlesim::Mrow_<ContainerAllocator> >::other >  _m_rows_type;
  _m_rows_type m_rows;





  typedef boost::shared_ptr< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetCameraImageResponse_

typedef ::turtlesim::GetCameraImageResponse_<std::allocator<void> > GetCameraImageResponse;

typedef boost::shared_ptr< ::turtlesim::GetCameraImageResponse > GetCameraImageResponsePtr;
typedef boost::shared_ptr< ::turtlesim::GetCameraImageResponse const> GetCameraImageResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlesim::GetCameraImageResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtlesim::GetCameraImageResponse_<ContainerAllocator1> & lhs, const ::turtlesim::GetCameraImageResponse_<ContainerAllocator2> & rhs)
{
  return lhs.image == rhs.image &&
    lhs.m_rows == rhs.m_rows;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtlesim::GetCameraImageResponse_<ContainerAllocator1> & lhs, const ::turtlesim::GetCameraImageResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtlesim

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fa2b089c65dd022d4b833c4f0146f099";
  }

  static const char* value(const ::turtlesim::GetCameraImageResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfa2b089c65dd022dULL;
  static const uint64_t static_value2 = 0x4b833c4f0146f099ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlesim/GetCameraImageResponse";
  }

  static const char* value(const ::turtlesim::GetCameraImageResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs/Image image\n"
"Mrow[] m_rows\n"
"\n"
"\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/Image\n"
"# This message contains an uncompressed image\n"
"# (0, 0) is at top-left corner of image\n"
"#\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"                     # If the frame_id here and the frame_id of the CameraInfo\n"
"                     # message associated with the image conflict\n"
"                     # the behavior is undefined\n"
"\n"
"uint32 height         # image height, that is, number of rows\n"
"uint32 width          # image width, that is, number of columns\n"
"\n"
"# The legal values for encoding are in file src/image_encodings.cpp\n"
"# If you want to standardize a new string format, join\n"
"# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n"
"\n"
"string encoding       # Encoding of pixels -- channel meaning, ordering, size\n"
"                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n"
"\n"
"uint8 is_bigendian    # is this data bigendian?\n"
"uint32 step           # Full row length in bytes\n"
"uint8[] data          # actual matrix data, size is (step * rows)\n"
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
"MSG: turtlesim/Mrow\n"
"Cell[] cells\n"
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

  static const char* value(const ::turtlesim::GetCameraImageResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.image);
      stream.next(m.m_rows);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCameraImageResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlesim::GetCameraImageResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlesim::GetCameraImageResponse_<ContainerAllocator>& v)
  {
    s << indent << "image: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.image);
    s << indent << "m_rows[]" << std::endl;
    for (size_t i = 0; i < v.m_rows.size(); ++i)
    {
      s << indent << "  m_rows[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::turtlesim::Mrow_<ContainerAllocator> >::stream(s, indent + "    ", v.m_rows[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLESIM_MESSAGE_GETCAMERAIMAGERESPONSE_H
