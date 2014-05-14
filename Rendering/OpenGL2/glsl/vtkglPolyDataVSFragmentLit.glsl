/*=========================================================================

  Program:   Visualization Toolkit

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// this shader is used to implement lighting in the fragment shader
// it handles setting up the basic varying variables for the fragment shader

// all variables that represent positions or directions have a suffix
// indicating the coordinate system they are in. The possible values are
// MC - Model Coordinates
// WC - WC world coordinates
// VC - View Coordinates
// DC - Display Coordinates

attribute vec4 vertexMC;
attribute vec3 zinger;

uniform mat3 normalMatrix; // transform model coordinate directions to view coordinates

// material property values
//VTK::Color::Dec

// camera and actor matrix values
uniform mat4 MCVCMatrix;  // combined Model to View transform
uniform mat4 MCWCMatrix;  // model to world matrix
uniform mat4 VCDCMatrix;  // the camera's projection matrix

varying vec4 vertexVC;
varying vec4 vertexWC;
varying vec3 vertexColor;
//varying vec3 normalVC;

void main()
{
  //vec3 normalVC = normalMatrix * normalMC;

  // compute the projected vertex position
  vertexWC = MCWCMatrix * vertexMC;
  vertexVC = MCVCMatrix * vertexMC;
  gl_Position = VCDCMatrix * vertexVC;
  vertexColor = diffuseColor.rgb;
}



