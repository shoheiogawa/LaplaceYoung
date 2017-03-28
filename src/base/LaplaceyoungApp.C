#include "LaplaceYoungApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<LaplaceYoungApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LaplaceYoungApp::LaplaceYoungApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LaplaceYoungApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LaplaceYoungApp::associateSyntax(_syntax, _action_factory);
}

LaplaceYoungApp::~LaplaceYoungApp()
{
}

// External entry point for dynamic application loading
extern "C" void LaplaceYoungApp__registerApps() { LaplaceYoungApp::registerApps(); }
void
LaplaceYoungApp::registerApps()
{
  registerApp(LaplaceYoungApp);
}

// External entry point for dynamic object registration
extern "C" void LaplaceYoungApp__registerObjects(Factory & factory) { LaplaceYoungApp::registerObjects(factory); }
void
LaplaceYoungApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void LaplaceYoungApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { LaplaceYoungApp::associateSyntax(syntax, action_factory); }
void
LaplaceYoungApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
