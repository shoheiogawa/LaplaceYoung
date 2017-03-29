#ifndef SturmLiouville_H
#define SturmLiouville_H

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

    Real _boundary_value;
    Real _spectral_parameter;

};

#endif // SturmLiouville_H
