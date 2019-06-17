/*##################################################################################
#  Copyright (C) 2019 - TerraProcess Team - Brazil.
#
#  This file is part of the TerraProcess - A GIS application used for
#  generating scripts for data processing using graphic language.
#
#  TerraProcess is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published
#  by the Free Software Foundation, either version 3 of the License,
#  or (at your option) any later version.
#
#  TerraProcess is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with TerraProcess. See COPYING. If not, write to
#  TerraProcess Team. See README file for more information.
##################################################################################*/

/*!
  \file terraprocess/src/process_qt/builder/BuilderMainWindow.cpp

  \brief It contains the main window for TerraProcess Builder Application.
*/

#include "src/process_qt/builder/BuilderMainWindow.h"
#include "src/process_qt/propertyBrowser/tree/ContextPropertyEditor.h";
#include "src/process_qt/propertyBrowser/tree/PropertyDelegate.h";
#include "src/process_qt/propertyBrowser/proxy/DefaultProxy.h";
#include "src/process_qt/graphics/core/View.h";
#include "src/process_qt/graphics/core/Scene.h";

#include "ui_BuilderMainWindowForm.h"

// TerraProcess Includes
#include "src/process_qt/model/ModelBoxDockWidget.h"

// Qt Includes
#include <QGraphicsView>
#include <QVBoxLayout>

tr::processQt::builder::BuilderMainWindow::BuilderMainWindow(QWidget* parent) :
  QMainWindow(parent),
  m_view(nullptr),
  m_tree(nullptr),
  m_ui(new Ui::BuilderMainWindowForm)
{
  m_ui->setupUi(this);

  tr::processQt::model::ModelBoxDockWidget* dockWidget = new tr::processQt::model::ModelBoxDockWidget(this);

  this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

  dockWidget->setFloating(false);

  //central widget
  tr::processQt::graphics::Scene* graphicsScene = new tr::processQt::graphics::Scene();
  m_view = new tr::processQt::graphics::View(graphicsScene, this);
  this->setCentralWidget(m_view);

  initPropertyBrowser();

  dockWidget->show();
}

tr::processQt::builder::BuilderMainWindow::~BuilderMainWindow()
{

}

void tr::processQt::builder::BuilderMainWindow::initPropertyBrowser()
{
  tr::processQt::model::ModelBoxDockWidget* dockWidgetPropertyBrowser = new tr::processQt::model::ModelBoxDockWidget(this);

  dockWidgetPropertyBrowser->setWindowTitle(tr("Property Browser"));

  this->addDockWidget(Qt::RightDockWidgetArea, dockWidgetPropertyBrowser);

  dockWidgetPropertyBrowser->setFloating(false);

  createPropertyTree(dockWidgetPropertyBrowser);
}

void tr::processQt::builder::BuilderMainWindow::createPropertyTree(tr::processQt::model::ModelBoxDockWidget* dockWidget)
{
  tr::processQt::propertyBrowser::DefaultProxy* proxy = new tr::processQt::propertyBrowser::DefaultProxy();

  tr::processQt::propertyBrowser::ContextPropertyEditor* context = new tr::processQt::propertyBrowser::ContextPropertyEditor(proxy, m_view->getScene());
  tr::processQt::propertyBrowser::PropertyDelegate* propDelegate = new tr::processQt::propertyBrowser::PropertyDelegate(context);
  m_tree.reset(new tr::processQt::propertyBrowser::PropertyTree(propDelegate, dockWidget)); // create property tree

  dockWidget->setWidget(m_tree.get());

  connect(m_tree.get(), SIGNAL(propertiesChanged(const tr::processQt::propertyBrowser::Property&)), this, SLOT(onPropertiesChanged(const tr::processQt::propertyBrowser::Property&)));
}

void tr::processQt::builder::BuilderMainWindow::onPropertiesChanged(const tr::processQt::propertyBrowser::Property& property)
{

}
