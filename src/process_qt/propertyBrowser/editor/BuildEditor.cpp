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
  \file BuildEditor.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "BuildEditor.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"
#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser//factory/editor/EditorFactory.h"
#include "src/process_qt/propertyBrowser/factory/editor/EditorFactoryParamsCreate.h"

// Qt
#include <QMetaType>

tr::processQt::propertyBrowser::BuildEditor::BuildEditor()
{
  
}

tr::processQt::propertyBrowser::BuildEditor::~BuildEditor()
{
 
}

tr::processQt::propertyBrowser::AbstractEditor* tr::processQt::propertyBrowser::BuildEditor::buildEditor(const EditorFactoryParamsCreate& params)
{
  QModelIndex index = params.getModelIndex();

  int propertyType = qMetaTypeId<tr::processQt::propertyBrowser::Property>();
  QVariant variant = index.data(propertyType);
  
  AbstractEditor* editor = 0;

  te::common::ParameterizedAbstractFactory<AbstractEditor, std::string, EditorFactoryParamsCreate>::dictionary_type& d = te::common::ParameterizedAbstractFactory<AbstractEditor, std::string, EditorFactoryParamsCreate>::getDictionary();

  tr::processQt::propertyBrowser::Property prop = qvariant_cast<tr::processQt::propertyBrowser::Property>(variant);
  std::string editorName = prop.getType()->getName();
  EditorFactory* fact = dynamic_cast<EditorFactory*>(d.find(editorName));
  if (fact)
  {
    editor = tr::processQt::propertyBrowser::EditorFactory::make(editorName, params);
  }
  return editor;
}

