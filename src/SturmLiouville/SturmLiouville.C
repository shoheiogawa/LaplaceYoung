#include "SturmLiouville.h"
#include <math.h>  // For sqrt()
#include <stdio.h> // For fabs()

class SturmLiouville;

template<>
InputParameters validParams<SturmLiouville>()
{

  InputParameters params = validParams<Kernel>();
  params.addClassDescription("The Sturm-Liouville equation $ -\\nabla \\cdot ( k \\nabla u + \\kappa u) = 0$ , with the weak form of:"
      "$( \\nabla \\phi_i, k \\nabla u_h) - <\\nabla \\phi_i, \\nabla u_h> +( \\phi_i, \\kappa u ) = 0 $.");
  params.addParamRequired<Real>("flux_value", "The solution values at boundary: $\\sigma$ .");  
  params.addParamRequired<Real>("spectral_parameter", "The spectoral parameter: $\\kappa$ .");  
  return params;

}

SturmLiouville::SturmLiouville(const InputParameters & InputParameters) 
  : Diffusion(parameters), 
  _flux_value(getParam<Real>("flux_value")),
  _spectral_parameter(getParam<Real>("spectral_parameter")),
{
}

SturmLiouville::~SturmLiouville() 
{
}

Real
SturmLiouville::computeQpResidual()
{
  return evaluateDiffusionCoefficient() * Diffusion::computeQpResidual() - _flux_value + evaluateSpectralParameter() * _u[_qp] * _grad_test[_i][_qp];
}

Real
SturmLiouville::computeQpJacobian()
{
  return evaluateDiffusionCoefficient() * Diffusion::computeQpJacobian() - _flux_value + evaluateSpectralParameter() * _grad_phi[_j][_qp];
}

Real
SturmLiouville::evaluateDiffusionCoefficient()
{
  return 1.0 / (sqrt(1 + fabs( (_u[_qp] * grad_phi[_i][_qp]) * (_u[_qp] * grad_phi[_i][_qp]) ) );
}

Real
SturmLiouville::evaluateSpectralParameter()
{
  return _spectral_parameter;
}

#endif // SturmLiouville_H
