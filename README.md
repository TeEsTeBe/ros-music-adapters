# ros-music-adapters

A collection of adapters to connect the Robot Operating System to the MUSIC library.

## Software dependencies
- ROS
	* detailed instructions can be found here: http://wiki.ros.org/melodic/Installation/Ubuntu
	* in short:
		- sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
		- sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
		- sudo apt update
		- sudo apt install ros-melodic-desktop-full
		- sudo rosdep init
		- rosdep update
		- source /opt/ros/melodic/setup.zsh
		- sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
- MUSIC <https://github.com/INCF/MUSIC>
	* clone git repo: https://github.com/INCF/MUSIC
	* pip install mpi4py
	* cd /PATH/TO/MUSIC/REPOSITORY
	* libtoolize
	* aclocal
	* autoheader
	* autoconf
	* automake --add-missing
	* ./configure [--prefix=/MUSIC/INSTALLATION/PATH]
	* make
	* make check
	* make install
	* ldconfig
	* if you want to test it: mpirun -np 4 /usr/local/bin/music [or path-to-install-music-to/bin/music] examples/demo.music
- OpenMPI
	* for example in Ubuntu 18.04: sudo apt install libblacs-mpi-dev
- pthread


- MUSIC-adapters
	* git clone https://github.com/incf-music/music-adapters
	* sudo apt install pkg-config libjsoncpp-dev libzmq3-dev libblas-dev libgsl-dev
	* cmake -DCMAKE_INSTALL_PREFIX:PATH=/MUSIC_ADAPTERS/INSTALL/PATH -DMUSIC_ROOT_DIR=/MUSIC/INSTALLATION/PATH /MUSIC_ADAPTERS/SRC/PATH
	* make
	* make install

## Optional dependencies
- Json-cpp
- GSL BLAS

## Installation

The ros-music-adapters can be installed as a catkin package. (see http://wiki.ros.org/ROS/Tutorials/CreatingPackage)

### .. or with cmake
- create build dir and cd into it
- cmake -DCMAKE_INSTALL_PREFIX:PATH=/ROS_MUSIC_ADAPTERS/INSTALLATION/PATH -DMUSICADAPTER_ROOT_DIR=/MUSIC_ADAPTERS/INSTALLATION/PATH /ROS_MUSIC_ADAPTERS/SRC/PATH
- make
- make install


## Example: Braitenberg vehicle

### NEST installation
If you want to use the ros-music-adapters with NEST, you have to compile NEST with MUSIC and MPI(for more details see https://nest-simulator.readthedocs.io/en/latest/installation/index.html and https://nest-simulator.readthedocs.io/en/latest/installation/install_options.html):
- Download or clone NEST
- Install dependencies
- cmake -DCMAKE_INSTALL_PREFIX:PATH=/NEST/INSTALLATION/DIR /NEST/SRC/DIR -Dwith-music=ON[or /PATH/TO/MUSIC/INSTALLATION] -Dwith-mpi=ON
- make 
- make install
- make installcheck

### Gazebo installation
For the braitenberg vehicle example you need the Gazebo robotic simulator:
- curl -sSL http://get.gazebosim.org | sh

### catkin_package (*TODO)
- see: https://wiki.ros.org/catkin/commands/catkin_make
- cd catkin_ws
- catkin_make install
- source devel/setup.bash

### start the example
- run ROS: roslaunch pioneer3at demo.launch
- run Gazebo: gzclient
- run NEST with MUSIC: mpirun -np 7 music braitenberg3.music
