// Auto-generated. Do not edit!

// (in-package package_303770.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ranges {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ranges = null;
    }
    else {
      if (initObj.hasOwnProperty('ranges')) {
        this.ranges = initObj.ranges
      }
      else {
        this.ranges = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ranges
    // Serialize message field [ranges]
    bufferOffset = _arraySerializer.float32(obj.ranges, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ranges
    let len;
    let data = new ranges(null);
    // Deserialize message field [ranges]
    data.ranges = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.ranges.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'package_303770/ranges';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b59fbb52705f63cb3fada08d311c9c4d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[] ranges
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ranges(null);
    if (msg.ranges !== undefined) {
      resolved.ranges = msg.ranges;
    }
    else {
      resolved.ranges = []
    }

    return resolved;
    }
};

module.exports = ranges;
