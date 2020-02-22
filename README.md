Andromeda Project
=================

Andromeda project goal is to create a simple game engine using Vulkan.

Setup
-----

Visual Studio 2019 provide all you need to setup this project.
Clone this repository and open the main folder with VS2019.

Sub-projects
------------

* __Carbon__

Contains all the mathematics of the engine.
You can find here :

	* Vector3
	* Matrix3x4
	* Quaternion
	* Transform

* __Photon__

The Vulkan graphics engine. Not started for now.

* __Pulsar__

Provide basics frameworks for the engine :

	* A friendly test framework to implement unit test for other projects
	* A customizable Logging system
	* Basics assert functionnalities
