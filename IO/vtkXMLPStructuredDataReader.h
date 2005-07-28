/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkXMLPStructuredDataReader.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkXMLPStructuredDataReader - Superclass for parallel structured data XML readers.
// .SECTION Description
// vtkXMLPStructuredDataReader provides functionality common to all
// parallel structured data format readers.

// .SECTION See Also
// vtkXMLPImageDataReader vtkXMLPStructuredGridReader
// vtkXMLPRectilinearGridReader

#ifndef __vtkXMLPStructuredDataReader_h
#define __vtkXMLPStructuredDataReader_h

#include "vtkXMLPDataReader.h"

class vtkExtentSplitter;
class vtkExtentTranslator;
class vtkTableExtentTranslator;
class vtkXMLStructuredDataReader;

class VTK_IO_EXPORT vtkXMLPStructuredDataReader : public vtkXMLPDataReader
{
public:
  vtkTypeRevisionMacro(vtkXMLPStructuredDataReader,vtkXMLPDataReader);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description:
  // Get an extent translator that will create pieces matching the
  // input file's piece breakdown.  This can be used further down the
  // pipeline to prevent reading from outside this process's piece.
  // The translator is only valid after an UpdateInformation has been
  // called.
  virtual vtkExtentTranslator* GetExtentTranslator();
  
  // For the specified port, copy the information this reader sets up in
  // SetupOutputInformation to outInfo
  virtual void CopyOutputInformation(vtkInformation *outInfo, int port);
protected:
  vtkXMLPStructuredDataReader();
  ~vtkXMLPStructuredDataReader();
  
  vtkIdType GetNumberOfPoints();
  vtkIdType GetNumberOfCells();
  void CopyArrayForPoints(vtkDataArray* inArray, vtkDataArray* outArray);
  void CopyArrayForCells(vtkDataArray* inArray, vtkDataArray* outArray);
  
  virtual void SetOutputExtent(int* extent)=0;
  virtual void GetPieceInputExtent(int index, int* extent)=0;
  
  // Pipeline execute data driver.  Called by vtkXMLReader.
  void ReadXMLData();
  int ReadPrimaryElement(vtkXMLDataElement* ePrimary);
  
  void SetupOutputData();

  void SetupEmptyOutput();
  void SetupPieces(int numPieces);
  void DestroyPieces();
  int ReadPiece(vtkXMLDataElement* ePiece);
  int ReadPieceData();
  void CopySubExtent(int* inExtent, int* inDimensions, vtkIdType* inIncrements,
                     int* outExtent,int* outDimensions,vtkIdType* outIncrements,
                     int* subExtent, int* subDimensions,
                     vtkDataArray* inArray, vtkDataArray* outArray);
  int ComputePieceSubExtents();
  
  vtkTableExtentTranslator* ExtentTranslator;
  vtkExtentSplitter* ExtentSplitter;
  
  // The extent to be updated in the output.
  int UpdateExtent[6];
  int PointDimensions[3];
  vtkIdType PointIncrements[3];
  int CellDimensions[3];
  vtkIdType CellIncrements[3];
  
  // The extent currently being read from a piece.
  int SubExtent[6];
  int SubPointDimensions[3];
  int SubCellDimensions[3];
  int SubPieceExtent[6];
  int SubPiecePointDimensions[3];
  vtkIdType SubPiecePointIncrements[3];
  int SubPieceCellDimensions[3];
  vtkIdType SubPieceCellIncrements[3];
  
  // Information per-piece.
  int* PieceExtents;
  
private:
  vtkXMLPStructuredDataReader(const vtkXMLPStructuredDataReader&);  // Not implemented.
  void operator=(const vtkXMLPStructuredDataReader&);  // Not implemented.
};

#endif
