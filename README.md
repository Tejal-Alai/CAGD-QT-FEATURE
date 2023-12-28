# CAGD-QT-FEATURE

# Visualizer

## Overview
This is an extension of project CAGD-QT in which I have implemented shaders and automated OpenGL.
The Visualizer project is designed to provide a graphical interface for performing various transformation operations and clipping on geometric shapes. 
The project is organized into three main components: Geometry, Algorithm, and Visualizer.

### DLLs

#### 1. Geometry DLL

The Geometry DLL contains classes and functions for handling geometric entities such as points, lines, and shapes. It serves as the foundational library for storing and manipulating geometric data within the Visualizer project.
 
Classes:

+ Point: Represents a 2D point in Cartesian coordinates.

+ Line: Represents a line segment defined by two points.

+ Shape: Base class for different geometric shapes.

#### 2. Transformations DLL
Overview:
The Transformations DLL provides functions for translating, rotating, and scaling shapes.

Files:
Transform.cpp: Implements the Transform class with methods for translation, rotation, and scaling.

#### 3. Clipping DLL
Overview:
The Clipping DLL contains the algorithm for clipping shapes against a specified region.

Files:
Clipping.cpp: Defines the Clipping class for clipping shapes based on a region.
#### 4. Bezier Curve DLL
Overview:
The BezierCurve DLL offers functionality for generating Bezier and Hermite curves.

Files:
+ BezierCurve.cpp: Implements the BezierCurve class for drawing Bezier curves.
+ HermiteCurve.cpp: Defines the HermiteCurve class for drawing Hermite curves.
#### 5. Visualizer (Main Project)
Overview:
The Visualizer project integrates the functionalities of the Geometry, Transformations, Clipping, and BezierCurve DLLs to create a comprehensive OpenGL-based geometric data visualization tool.

Files:
OpenGLWindow.cpp: Main application file, using OpenGL for rendering.
ShapeContainer.cpp: Manages the collection of shapes for visualization.

Features:

+ Shape Container: Allows users to add circles and rectangles to the visualizer canvas.

+ Transformation Operations: Perform translation, rotation, and scaling on the added shapes.

+ Clipping: Define a clipping region and clip shapes accordingly.

+ Bazier Curve: Draw Bezier curve according to inputted control points.

+ Hermite Curve: Draw Hermite curve according to inputted control points.

+ Real-time Visualization: Shapes are rendered in real-time through OpenGL, providing immediate feedback on transformations and clipping.
  
+ Feature implementation : Added shapes are translated.
  
### Usage

1. Initialization:
+ Instantiate the Geometry, Transformations, Clipping, and Bezier Curve classes as needed.
+ Create a ShapeContainer to manage shapes.
2. Geometric Operations:
+ Use the Geometry DLL to create points, lines, and shapes.
3. Transformations:
+ Apply transformations (translation, rotation, scaling) using the Transformations DLL.
4. Clipping:
+ Utilize the Clipping DLL to clip shapes against a specified region.
5. Curves:
+ Generate Bezier and Hermite curves using the Bezier Curve DLL and Hermite Curve DLL respectively.
6. OpenGL Visualization:
+ Use OpenGL to visualize the transformed, clipped shapes, and curves in the main Visualizer project.
+ Change color of shapes.



