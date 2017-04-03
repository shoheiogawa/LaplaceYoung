#include "SturmLiouville.h"
#include <math.h>  // For sqrt()
#include <stdio.h> // For fabs()

template<>
InputParameters validParams<SturmLiouville>()
{

  InputParameters params = validParams<Diffusion>();
  params.addClassDescription("The Sturm-Liouville equation $ -\\nabla \\cdot ( k \\nabla u + \\kappa u) = 0$ , with the weak form of:"
      "$( \\nabla \\phi_i, k \\nabla u_h) - <\\nabla \\phi_i, \\nabla u_h> +( \\phi_i, \\kappa u ) = 0 $.");
  // params.addRequiredParam<Real>("flux_value", "The solution values at boundary: $\\sigma$ .");  
  params.addRequiredParam<Real>("spectral_parameter", "The spectoral parameter: $\\kappa$ .");  
  return params;

}

SturmLiouville::SturmLiouville(const InputParameters & parameters) 
  : Diffusion(parameters), 
  //_flux_value(getParam<Real>("flux_value")),
  _spectral_parameter(getParam<Real>("spectral_parameter"))
{
}

SturmLiouville::~SturmLiouville() 
{
}

Real
SturmLiouville::computeQpResidual()
{
  return evaluateDiffusionCoefficient() * _grad_u[_qp] * _grad_test[_i][_qp] + evaluateSpectralParameter() * _u[_qp] * _test[_i][_qp];
}

Real
SturmLiouville::computeQpJacobian()
{
  return evaluateDiffusionCoefficient() * _grad_phi[_j][_qp] * _grad_test[_i][_qp] + evaluateSpectralParameter() * _phi[_j][_qp] * _test[_i][_qp];
}

Real
SturmLiouville::evaluateDiffusionCoefficient()
{
  return 1.0 / (std::sqrt( 1.0 + fabs( ( _grad_u[_qp]  * _grad_u[_qp]  ) ) ) );
}

Real
SturmLiouville::evaluateSpectralParameter()
{
  return _spectral_parameter;
}

