#ifndef SturmLiouville_H
#define SturmLiouville_H

#include "Diffusion.h"

class SturmLiouville;

template<>
InputParameters validParams<SturmLiouville>();

class SturmLiouville : public Diffusion
{

public:
  SturmLiouville(const InputParameters & parameters);
  virtual ~SturmLiouville();

protected:
    virtual Real computeQpResidual() override;
    
    virtual Real computeQpJacobian() override;

    virtual Real evaluateDiffusionCoefficient();

    virtual Real evaluateSpectralParameter();

    Real _spectral_parameter;

};

#endif // SturmLiouville_H

