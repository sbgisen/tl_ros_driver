# TL-3 (Solid-state 2D LiDAR)
<img src="http://soslab.co/wp-content/uploads/2018/11/02_SOS-LAB_Hompage-design_Products_Source_17-1.png" width="300">
<img src="http://soslab.co/wp-content/uploads/2018/11/02_SOS-LAB_Hompage-design_Products_Source_10-1030x59.png" width="800">
<img src="http://soslab.co/wp-content/uploads/2019/02/02_SOS-LAB_Hompage-design_Products_Source_20-2-1030x376.png" width="800">
<img src="http://soslab.co/wp-content/uploads/2018/11/02_SOS-LAB_Hompage-design_Products_Source_12-1030x4.png" width="800">

## Guide
* Installation
```
cd $(ROS workspace)/src
git clone https://github.com/sos-lab-co-ltd/tl_ros_driver.git
cd $(ROS workspace)
catkin_make
```
* Set permission of USB port
```
sudo chmod a+rw /dev/ttyUSB0
```
* Run TL-3 publisher node
```
roslaunch soslab_tl_driver tl_laser.launch
```
* Run TL-3 publisher node with RViz
```
roslaunch soslab_tl_driver view_tl_laser.launch
```
* Change serial port or frame_id in `soslab_tl_driver/launch/tl_laser.launch`
```xml
<?xml version="1.0"?>
<launch>
  <node pkg="soslab_tl_driver" type="tl_driver_node" name="tl_driver_node" output="screen">
    <param name="port" value="/dev/ttyUSB0"/>
    <param name="frame_id" value="laser"/>
  </node>
</launch>
```

## Test environment
- ROS Melodic Morenia
- Ubuntu 16.04 and Ubuntu 18.04

## Application demo
- Virtual touch screen (https://youtu.be/csur2P3Ajk0)
- Door Alarm Sensor (https://youtu.be/kVIUpRyEGe4)
- Elevator Sensor (https://youtu.be/0DkKYYddUEA)
