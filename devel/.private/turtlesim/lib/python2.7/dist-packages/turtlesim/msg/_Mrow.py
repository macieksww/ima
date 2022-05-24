# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from turtlesim/Mrow.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import turtlesim.msg

class Mrow(genpy.Message):
  _md5sum = "dc4d4a6faec42c0efee83680cff86b79"
  _type = "turtlesim/Mrow"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """Cell[] cells

================================================================================
MSG: turtlesim/Cell
float32 red
float32 green 
float32 blue
float32 distance 
float32 occupy """
  __slots__ = ['cells']
  _slot_types = ['turtlesim/Cell[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       cells

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Mrow, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.cells is None:
        self.cells = []
    else:
      self.cells = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.cells)
      buff.write(_struct_I.pack(length))
      for val1 in self.cells:
        _x = val1
        buff.write(_get_struct_5f().pack(_x.red, _x.green, _x.blue, _x.distance, _x.occupy))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.cells is None:
        self.cells = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.cells = []
      for i in range(0, length):
        val1 = turtlesim.msg.Cell()
        _x = val1
        start = end
        end += 20
        (_x.red, _x.green, _x.blue, _x.distance, _x.occupy,) = _get_struct_5f().unpack(str[start:end])
        self.cells.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.cells)
      buff.write(_struct_I.pack(length))
      for val1 in self.cells:
        _x = val1
        buff.write(_get_struct_5f().pack(_x.red, _x.green, _x.blue, _x.distance, _x.occupy))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.cells is None:
        self.cells = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.cells = []
      for i in range(0, length):
        val1 = turtlesim.msg.Cell()
        _x = val1
        start = end
        end += 20
        (_x.red, _x.green, _x.blue, _x.distance, _x.occupy,) = _get_struct_5f().unpack(str[start:end])
        self.cells.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_5f = None
def _get_struct_5f():
    global _struct_5f
    if _struct_5f is None:
        _struct_5f = struct.Struct("<5f")
    return _struct_5f
