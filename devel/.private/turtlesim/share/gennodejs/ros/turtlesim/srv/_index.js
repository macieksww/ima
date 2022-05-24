
"use strict";

let GetPose = require('./GetPose.js')
let GetSonar = require('./GetSonar.js')
let GetFrameSize = require('./GetFrameSize.js')
let Spawn = require('./Spawn.js')
let GetCameraImage = require('./GetCameraImage.js')
let TeleportRelative = require('./TeleportRelative.js')
let SetPen = require('./SetPen.js')
let GetTurtles = require('./GetTurtles.js')
let HasTurtle = require('./HasTurtle.js')
let Kill = require('./Kill.js')
let TeleportAbsolute = require('./TeleportAbsolute.js')

module.exports = {
  GetPose: GetPose,
  GetSonar: GetSonar,
  GetFrameSize: GetFrameSize,
  Spawn: Spawn,
  GetCameraImage: GetCameraImage,
  TeleportRelative: TeleportRelative,
  SetPen: SetPen,
  GetTurtles: GetTurtles,
  HasTurtle: HasTurtle,
  Kill: Kill,
  TeleportAbsolute: TeleportAbsolute,
};
