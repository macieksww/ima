#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/maciek/my_catkin_ws/src/ros_tutorials/turtlesim"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/maciek/my_catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/maciek/my_catkin_ws/install/lib/python2.7/dist-packages:/home/maciek/my_catkin_ws/build/turtlesim/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/maciek/my_catkin_ws/build/turtlesim" \
    "/usr/bin/python2" \
    "/home/maciek/my_catkin_ws/src/ros_tutorials/turtlesim/setup.py" \
     \
    build --build-base "/home/maciek/my_catkin_ws/build/turtlesim" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/maciek/my_catkin_ws/install" --install-scripts="/home/maciek/my_catkin_ws/install/bin"
