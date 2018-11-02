vtk_module(vtkRenderingLICOpenGL2
  BACKEND
    OpenGL2
  TEST_DEPENDS
    vtkTestingCore
    vtkTestingRendering
    vtkInteractionStyle
  KIT
    vtkOpenGL
  DEPENDS
    vtkCommonCore
    vtkCommonDataModel
    vtkCommonExecutionModel
    vtkRenderingOpenGL2
  PRIVATE_DEPENDS
    vtkCommonMath
    vtkCommonSystem
    vtkIOCore
    vtkIOLegacy
    vtkIOXML
    vtkImagingCore
    vtkImagingSources
    vtkRenderingCore
    vtkglew
    vtksys
  )