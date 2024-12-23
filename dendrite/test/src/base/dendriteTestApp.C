//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "dendriteTestApp.h"
#include "dendriteApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
dendriteTestApp::validParams()
{
  InputParameters params = dendriteApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

dendriteTestApp::dendriteTestApp(InputParameters parameters) : MooseApp(parameters)
{
  dendriteTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

dendriteTestApp::~dendriteTestApp() {}

void
dendriteTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  dendriteApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"dendriteTestApp"});
    Registry::registerActionsTo(af, {"dendriteTestApp"});
  }
}

void
dendriteTestApp::registerApps()
{
  registerApp(dendriteApp);
  registerApp(dendriteTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
dendriteTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  dendriteTestApp::registerAll(f, af, s);
}
extern "C" void
dendriteTestApp__registerApps()
{
  dendriteTestApp::registerApps();
}
