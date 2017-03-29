[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 1.0 # lx
  ymax = 1.0 # ly
[]

[Variables]
  [./u]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[Kernels]
  [./younglaplace_u]
    type = YoungLaplace 
    variable = u
    flux_value = 0.2
    spectral_parameter = 1.0
  [../]
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
[]

[Outputs]
  exodus = true
[]
