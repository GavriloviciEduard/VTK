vtk_module(vtkInteractionStyle
  GROUPS
    Rendering
  IMPLEMENTS
    vtkRenderingCore
  KIT
    vtkInteraction
  DEPENDS
    vtkCommonDataModel
    vtkRenderingCore
  PRIVATE_DEPENDS
    vtkCommonCore
    vtkCommonMath
    vtkCommonTransforms
    vtkFiltersExtraction
    vtkFiltersSources
  )