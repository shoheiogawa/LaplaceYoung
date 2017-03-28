#ifndef LAPLACEYOUNGAPP_H
#define LAPLACEYOUNGAPP_H

#include "MooseApp.h"

class LaplaceyoungApp;

template<>
InputParameters validParams<LaplaceyoungApp>();

class LaplaceyoungApp : public MooseApp
{
public:
  LaplaceyoungApp(InputParameters parameters);
  virtual ~LaplaceyoungApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LAPLACEYOUNGAPP_H */
