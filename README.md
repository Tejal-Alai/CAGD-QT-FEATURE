# Visulizer

## Overview

The Visualizer project is designed to provide a graphical interface for performing various transformation operations and clipping on geometric shapes. 
The project is organized into three main components: Geometry, Algorithm, and Visualizer.

### 1. Geometry DLL

The Geometry DLL contains classes and functions for handling geometric entities such as points, lines, and shapes. It serves as the foundational library for storing and manipulating geometric data within the Visualizer project.
 
Classes:

+ Point: Represents a 2D point in Cartesian coordinates.

+ Line: Represents a line segment defined by two points.

+ Shape: Base class for different geometric shapes.

### 2. Algorithm DLL
The Algorithm DLL includes classes and functions related to clipping and geometric transformations. 
This DLL provides the necessary algorithms for operations like translation, rotation, scaling, and clipping.

Files:

+ Transformation.cpp: Contains functions for translating, rotating, and scaling geometric entities.

+ Clipping.cpp: Implements clipping algorithm.

### 3. Visualizer (Main Project)

The Visualizer project utilizes the Geometry and Algorithm DLLs to create an interactive graphical interface for users to work with geometric shapes.

Features:

+ Shape Container: Allows users to add circles and rectangles to the visualizer canvas.

+ Transformation Operations: Perform translation, rotation, and scaling on the added shapes.

+ Clipping: Define a clipping region and clip shapes accordingly.

+ Real-time Visualization: Shapes are rendered in real-time through OpenGL, providing immediate feedback on transformations and clipping.

## Project Screenshots

### Initial State

![Initial State]![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/cf99125b-d90f-43f7-95a5-38d8dff92010)
)


### Performing Transformations

![Performing Transformations]![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/2f5afbec-9abc-4cf5-9458-3ed505166b07)


### Clipping in Action

![Clipping in Action]![image](https://github.com/Tejal-Alai/CAGD-QT-project/assets/131939644/eaffef6c-09bf-4ca6-966b-d673eb6b30c5)

