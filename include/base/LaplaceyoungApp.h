#ifndef LAPLACEYOUNGAPP_H
#define LAPLACEYOUNGAPP_H

#include "MooseApp.h"

class LaplaceYoungApp;

template<>
InputParameters validParams<LaplaceYoungApp>();

class LaplaceYoungApp : public MooseApp
{
public:
  LaplaceYoungApp(InputParameters parameters);
  virtual ~LaplaceYoungApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LAPLACEYOUNGAPP_H */
