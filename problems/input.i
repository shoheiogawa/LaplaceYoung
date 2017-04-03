[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 30
  ny = 30
  xmax = 1.0 # lx
  ymax = 1.0 # ly
  elem_type = TRI3
[]

[Variables]
  [./u]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./LY]
    type = SturmLiouville
    variable = u
    flux_value = 0.0
    spectral_parameter = 1.0
  [../]
[]

[BCs]
  [./border_flux]
    type = NeumannBC
    variable = u
    boundary = '0 1 2 3'
    value = 0.2
  [../]
[]

[Executioner]
  type = Steady
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  line_search = basic
[]

[Outputs]
  exodus = true
[]

