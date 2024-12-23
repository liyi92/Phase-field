#include "dendriteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
dendriteApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

dendriteApp::dendriteApp(InputParameters parameters) : MooseApp(parameters)
{
  dendriteApp::registerAll(_factory, _action_factory, _syntax);
}

dendriteApp::~dendriteApp() {}

void
dendriteApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<dendriteApp>(f, af, s);
  Registry::registerObjectsTo(f, {"dendriteApp"});
  Registry::registerActionsTo(af, {"dendriteApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
dendriteApp::registerApps()
{
  registerApp(dendriteApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
dendriteApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  dendriteApp::registerAll(f, af, s);
}
extern "C" void
dendriteApp__registerApps()
{
  dendriteApp::registerApps();
}
