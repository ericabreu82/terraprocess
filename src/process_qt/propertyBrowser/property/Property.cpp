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
  \file Property.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

#include "src/process_qt/propertyBrowser/property/Property.h"
#include "src/process_qt/propertyBrowser/enum/Enums.h"

#include <terralib/common/Exception.h>

// STL
#include <vector>
#include <algorithm>

tr::processQt::propertyBrowser::Property::Property( int parentItemHashCode ) :
  m_parentItemHashCode(parentItemHashCode),
  m_name("unknown"),
  m_type(0),
  m_editable(true),
  m_label(""),
  m_menu(false),
  m_icon(""),
  m_visible(true),
  m_required(false),
  m_composeWidget(false),
  m_public(false),
  m_serializable(true),
  m_usePrecision(false),
  m_precisionValue(2)
{
  m_type = Enums::getInstance().getEnumDataType()->getDataTypeNone();
}

tr::processQt::propertyBrowser::Property::Property(const std::string& propertyName, te::dt::AbstractData* data, EnumType* type)
  : m_parentItemHashCode(0)
  , m_name(propertyName)
  , m_type(type)
  , m_editable(true)
  , m_label("")
  , m_menu(false)
  , m_icon("")
  , m_visible(true)
  , m_required(false)
  , m_composeWidget(false)
  , m_public(false)
  , m_serializable(true)
  , m_usePrecision(false)
  , m_precisionValue(2)
  , m_data(data)
{
}

tr::processQt::propertyBrowser::Property::Property(const tr::processQt::propertyBrowser::Property& rhs)
  : m_parentItemHashCode(0)
  , m_name("")
  , m_type(nullptr)
  , m_editable(true)
  , m_label("")
  , m_menu(false)
  , m_icon("")
  , m_visible(true)
  , m_required(false)
  , m_composeWidget(false)
  , m_public(false)
  , m_serializable(true)
  , m_usePrecision(false)
  , m_precisionValue(2)
  , m_data(nullptr)
{
  *this = rhs;
}

tr::processQt::propertyBrowser::Property::~Property()
{
  
}

const std::string& tr::processQt::propertyBrowser::Property::getName() const
{
  return m_name;
}

void tr::processQt::propertyBrowser::Property::setName( const std::string& name )
{
  m_name = name;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::Property::getType() const
{
  return m_type;
}

void tr::processQt::propertyBrowser::Property::setValue(te::dt::AbstractData* data, EnumType* type, bool usePrecision, int precisionValue)
{
  m_data.reset(data);
  m_type = type;

  setUsePrecision(usePrecision);
  setPrecision(precisionValue);
}

const te::dt::AbstractData* tr::processQt::propertyBrowser::Property::getValue() const
{
  return m_data.get();
}

void tr::processQt::propertyBrowser::Property::addOption(const Variant& variant)
{
  if(m_options.empty())
  {
    m_currentChoice = variant;
  }

  m_options.push_back(variant);
}

void tr::processQt::propertyBrowser::Property::removeOption(const Variant& variant)
{
  for(std::vector<Variant>::iterator it = m_options.begin(); it != m_options.end(); ++it)
  {
    if((*it) == variant)
    {
      m_options.erase(it);
      break;
    }
  }
}

void tr::processQt::propertyBrowser::Property::setOptionChoice(const Variant& variant)
{
  m_currentChoice = variant; 
}

const tr::processQt::propertyBrowser::Variant& tr::processQt::propertyBrowser::Property::getOptionByCurrentChoice() const
{
  return m_currentChoice;
}

const std::vector<tr::processQt::propertyBrowser::Variant>& tr::processQt::propertyBrowser::Property::getOptionChoices() const
{
  return m_options;
}

bool tr::processQt::propertyBrowser::Property::isEditable() const
{
  return m_editable;
}

void tr::processQt::propertyBrowser::Property::setEditable( bool editable )
{
  m_editable = editable;
}

void tr::processQt::propertyBrowser::Property::addSubProperty( const Property& property )
{
  m_subProperty.push_back(property);
}

bool tr::processQt::propertyBrowser::Property::addSubProperty(const Property& parent, const Property& subProperty)
{
  const std::vector<tr::processQt::propertyBrowser::Property>& subProperties = parent.getSubProperty();
  std::size_t total = subProperties.size();
  std::size_t totalResult = 0;

  if (std::find(m_subProperty.begin(), m_subProperty.end(), parent) != m_subProperty.end())
  {
    std::vector<Property>::iterator it = std::find(m_subProperty.begin(), m_subProperty.end(), parent);
    it->addSubProperty(subProperty);
    totalResult = it->getSubProperty().size();
  }
  else
  {
    for (std::vector<tr::processQt::propertyBrowser::Property>::iterator itSub = m_subProperty.begin(); itSub != m_subProperty.end(); ++itSub)
    {
      itSub->addSubProperty(parent, subProperty);
    }
  }

  if (totalResult > total)
    return true;
  return false;
}

void tr::processQt::propertyBrowser::Property::removeSubProperty( const Property& property )
{
  for(std::vector<Property>::iterator it = m_subProperty.begin(); it != m_subProperty.end(); ++it)
  {
    if((*it) == property)
    {
      m_subProperty.erase(it);
      break;
    }
    else
    {
      it->removeSubProperty(property);
    }
  }
}

bool tr::processQt::propertyBrowser::Property::removeSubProperty(const std::string& name)
{
  bool is_removeProp = false;

  Property property;
  property.setName(name);

  if (m_subProperty.empty())
    return is_removeProp;

  if (std::find(m_subProperty.begin(), m_subProperty.end(), property) != m_subProperty.end())
  {
    std::vector<Property>::iterator it = std::find(m_subProperty.begin(), m_subProperty.end(), property);
    property = (*it);
    is_removeProp = true;
  }
  else
  {
    for (std::vector<Property>::iterator itSub = m_subProperty.begin(); itSub != m_subProperty.end(); ++itSub)
    {
      is_removeProp = itSub->removeSubProperty(name);
      if (is_removeProp)
      {
        break;
      }
    }
  }
  return is_removeProp;
}

const std::vector<tr::processQt::propertyBrowser::Property>& tr::processQt::propertyBrowser::Property::getSubProperty() const
{
  return m_subProperty;
}

bool tr::processQt::propertyBrowser::Property::updateSubProperty(const Property& property)
{
  bool result = false;

  if (m_subProperty.empty())
    return result;

  for (std::vector<tr::processQt::propertyBrowser::Property>::iterator it = m_subProperty.begin(); it != m_subProperty.end(); ++it)
  {
    if ((*it) == property)
    {
      it->setValue(property.getValue()->clone(), property.getType());
      it->setOptionChoice(property.getOptionByCurrentChoice());
      result = true;
    }
    else
    {
      it->updateSubProperty(property);
    }
  }

  return result;
}

bool tr::processQt::propertyBrowser::Property::completelyUpdateSubProperty(const Property& property)
{
  bool result = false;

  for (std::vector<tr::processQt::propertyBrowser::Property>::iterator it = m_subProperty.begin(); it != m_subProperty.end(); ++it)
  {
    if ((*it) == property)
    {
      it->setValue(property.getValue()->clone(), property.getType());
      it->setOptionChoice(property.getOptionByCurrentChoice());
      it->setEditable(property.isEditable());
      it->setLabel(property.getLabel());
      it->setMenu(property.isMenu());
      it->setIcon(property.getIcon());
      it->setVisible(property.isVisible());
      it->setRequired(property.isRequired());
      it->setParentItemHashCode(property.getParentItemHashCode());
      it->setComposeWidget(property.isComposeWidget());
      it->setPublic(property.isPublic());
      it->setSerializable(property.isSerializable());
      result = true;
    }
    else
    {
      it->updateSubProperty(property);
    }
  }
  return result;
}

bool tr::processQt::propertyBrowser::Property::isNull() const
{
  if (m_data.get() == 0)
  {
    return true;
  }

  return false;
}

bool tr::processQt::propertyBrowser::Property::containsSubProperty(const std::string& name) const
{
  if (m_subProperty.empty())
  {
    return false;
  }

  if (std::find(m_subProperty.begin(), m_subProperty.end(), name) != m_subProperty.end())
  {
    return true;
  }
  else
  {
    for (std::vector<Property>::const_iterator itSub = m_subProperty.begin(); itSub != m_subProperty.end(); ++itSub)
    {
      if(itSub->containsSubProperty(name))
      {
        return true;
      }
    }
  }

  return false;
}

const tr::processQt::propertyBrowser::Property& tr::processQt::propertyBrowser::Property::getSubProperty( const std::string& name ) const
{
  if (m_nullProperty.get() == 0)
  {
    m_nullProperty.reset(new Property);
  }

  if (m_subProperty.empty())
  {
    Property* p = m_nullProperty.get();
    return *p;
  }

  if(std::find(m_subProperty.begin(), m_subProperty.end(), name) != m_subProperty.end())
  {
    std::vector<Property>::const_iterator it = std::find(m_subProperty.begin(), m_subProperty.end(), name);
    return (*it);
  }
  else
  {
    for (std::vector<Property>::const_iterator itSub = m_subProperty.begin(); itSub != m_subProperty.end(); ++itSub)
    {
      if (itSub->containsSubProperty(name) == 0)
      {
        const Property& prop = itSub->getSubProperty(name);
        return prop;
      }
    }
  }
  
  throw te::common::Exception("Property::The given sub property name was not found in the sub property list");
}

bool tr::processQt::propertyBrowser::Property::equals(const Property& property) const
{
  bool result = true;

  if (m_subProperty.size() != property.getSubProperty().size())
  {
    return false;
  }
  
  if (this->getValue()->toString() == property.getValue()->toString())
  {
    for (std::vector<Property>::const_iterator it = m_subProperty.begin(); it != m_subProperty.end(); ++it)
    {
      Property prop = (*it);
      std::string name = prop.getName();
      if (property.containsSubProperty(name) == true)
      {
        Property otherProp = property.getSubProperty(name);
        // will also check values of the sub properties
        if (prop.equals(otherProp) == false)
        {
          result = false;
          break;
        }
      }
      else
      {
        result = false;
        break;
      }
    }
  }
  else
  {
    result = false;
  }
  return result;
}

void tr::processQt::propertyBrowser::Property::clear()
{
  EnumDataType* dataType = Enums::getInstance().getEnumDataType();

  m_name = "unknown";
  m_editable = true;
  m_type = dataType->getDataTypeNone();
  m_currentChoice.clear();
  m_options.clear();
  m_subProperty.clear();
  m_menu = false;
  m_icon = "";
  m_required = false;
  m_composeWidget = false;
  m_label = "";
  m_data.reset();
}

void tr::processQt::propertyBrowser::Property::setLabel( const std::string& label )
{
  m_label = label;
}

const std::string& tr::processQt::propertyBrowser::Property::getLabel() const
{
  return m_label;
}

void tr::processQt::propertyBrowser::Property::setMenu( bool menu )
{
  m_menu = menu;
}

bool tr::processQt::propertyBrowser::Property::isMenu() const
{
  return m_menu;
}

void tr::processQt::propertyBrowser::Property::setIcon( const std::string& icon )
{
  m_icon = icon;
}

const std::string& tr::processQt::propertyBrowser::Property::getIcon() const
{
  return m_icon;
}

void tr::processQt::propertyBrowser::Property::setVisible( bool visible )
{
  m_visible = visible;
}

bool tr::processQt::propertyBrowser::Property::isVisible() const
{
  return m_visible;
}

bool tr::processQt::propertyBrowser::Property::isRequired() const
{
  return m_required;
}

void tr::processQt::propertyBrowser::Property::setRequired( bool required )
{
  m_required = required;
}

void tr::processQt::propertyBrowser::Property::setParentItemHashCode( int hashCode )
{
  m_parentItemHashCode = hashCode;
}

int tr::processQt::propertyBrowser::Property::getParentItemHashCode() const
{
  return m_parentItemHashCode;
}

bool tr::processQt::propertyBrowser::Property::isComposeWidget() const
{
  return m_composeWidget;
}

void tr::processQt::propertyBrowser::Property::setComposeWidget( bool compose )
{
  m_composeWidget = compose;
}

bool tr::processQt::propertyBrowser::Property::isPublic() const
{
  return m_public;
}

void tr::processQt::propertyBrowser::Property::setPublic( bool publicProperty )
{
  /*
  If the component, father of this property, is a child of another component, 
  then this property can be used by the parent component to display the value or call windows. It can not be edited.
  */
  m_public = publicProperty;
  if(m_public)
  {
    m_editable = false;
  }
}

bool tr::processQt::propertyBrowser::Property::isSerializable() const
{
  return m_serializable;
}

void tr::processQt::propertyBrowser::Property::setSerializable(bool serializable)
{
  m_serializable = serializable;
}

const std::string& tr::processQt::propertyBrowser::Property::getParent() const
{
  return m_parentClass;
}

void tr::processQt::propertyBrowser::Property::setParent(const std::string& parentClass)
{
  m_parentClass = parentClass;

  for (std::vector<Property>::iterator it = this->m_subProperty.begin(); it != this->m_subProperty.end(); ++it)
  {
    it->setParent(parentClass);
  }
}

bool tr::processQt::propertyBrowser::Property::getUsePrecision() const
{
  return m_usePrecision;
}

void tr::processQt::propertyBrowser::Property::setUsePrecision(bool usePrecision)
{
  m_usePrecision = usePrecision;
}

int tr::processQt::propertyBrowser::Property::getPrecision() const
{
  return m_precisionValue;
}

void tr::processQt::propertyBrowser::Property::setPrecision(int precision)
{
  m_precisionValue = precision;
}
