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

#include "src/process_qt/propertyBrowser/property/Properties.h"

tr::processQt::propertyBrowser::Properties::Properties()
  : m_objName("unknown")
  , m_typeObj(0)
  , m_hasWindows(false)
  , m_hashcode(0)
{

}

tr::processQt::propertyBrowser::Properties::Properties(const std::string& objectName, tr::processQt::propertyBrowser::EnumType* type, int hashCode)
  : m_objName(objectName)
  , m_typeObj(type)
  , m_hasWindows(false)
  , m_hashcode(hashCode)
{

}

tr::processQt::propertyBrowser::Properties::~Properties(void)
{

}

bool tr::processQt::propertyBrowser::Properties::addProperty(const tr::processQt::propertyBrowser::Property& property)
{
  std::size_t total = m_properties.size();
  m_properties.push_back(property);

  if (m_properties.size() > total)
    return true;
  return false;
}

bool tr::processQt::propertyBrowser::Properties::addSubProperty(const tr::processQt::propertyBrowser::Property& parent, const tr::processQt::propertyBrowser::Property& subProperty)
{
  const std::vector<tr::processQt::propertyBrowser::Property>& subProperties = parent.getSubProperty();
  std::size_t total = subProperties.size();
  std::size_t totalResult = 0;

  if (std::find(m_properties.begin(), m_properties.end(), parent) != m_properties.end())
  {
    std::vector<Property>::iterator it = std::find(m_properties.begin(), m_properties.end(), parent);
    it->addSubProperty(subProperty);
    totalResult = it->getSubProperty().size();
  }
  else
  {
    for (std::vector<tr::processQt::propertyBrowser::Property>::iterator itSub = m_properties.begin(); itSub != m_properties.end(); ++itSub)
    {
      if (itSub->addSubProperty(parent, subProperty))
      {
        totalResult += total;
      }
    }
  }

  if (totalResult > total)
    return true;
  return false;
}

bool tr::processQt::propertyBrowser::Properties::removeProperty(const std::string& name)
{
  bool result = false;

  for (std::vector<Property>::iterator it = m_properties.begin(); it != m_properties.end(); ++it)
  {
    if (it->getName().compare(name) == 0)
    {
      m_properties.erase(it);
      result = true;
      break;
    }
    else
    {
      it->removeSubProperty(name);
    }
  }
  return result;
}

bool tr::processQt::propertyBrowser::Properties::updateProperty(const tr::processQt::propertyBrowser::Property& property)
{
  bool result = false;

  for (std::vector<Property>::iterator it = m_properties.begin(); it != m_properties.end(); ++it)
  {
    if (it->getName().compare(property.getName()) == 0)
    {
      it->setValue(property.getValue()->clone(), property.getType());
      it->setOptionChoice(property.getOptionByCurrentChoice());

      //if this property has subproperties, we must update them too
      const std::vector<Property>& vecSubProperties = property.getSubProperty();
      for (size_t j = 0; j < vecSubProperties.size(); ++j)
      {
        it->updateSubProperty(vecSubProperties[j]);
      }

      result = true;
    }
    else
    {
      it->updateSubProperty(property);
    }
  }
  return result;
}

bool tr::processQt::propertyBrowser::Properties::completelyUpdateProperty(const tr::processQt::propertyBrowser::Property& property)
{
  bool result = false;

  for (std::vector<Property>::iterator it = m_properties.begin(); it != m_properties.end(); ++it)
  {
    if (it->getName().compare(property.getName()) == 0)
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
      it->completelyUpdateSubProperty(property);
    }
  }
  return result;
}

const std::vector<tr::processQt::propertyBrowser::Property>& tr::processQt::propertyBrowser::Properties::getProperties() const
{
  return m_properties;
}

bool tr::processQt::propertyBrowser::Properties::clear()
{
  m_properties.clear();
  return m_properties.empty();
}

const std::string& tr::processQt::propertyBrowser::Properties::getObjectName() const
{
  return m_objName;
}

void tr::processQt::propertyBrowser::Properties::setObjectName(const std::string& name)
{
  m_objName = name;
}

tr::processQt::propertyBrowser::EnumType* tr::processQt::propertyBrowser::Properties::getTypeObj() const
{
  return m_typeObj;
}

void tr::processQt::propertyBrowser::Properties::setTypeObj(tr::processQt::propertyBrowser::EnumType* type)
{
  m_typeObj = type;
}

bool tr::processQt::propertyBrowser::Properties::contains(const std::string& propertyName) const
{
  if (std::find(m_properties.begin(), m_properties.end(), propertyName) != m_properties.end())
  {
    return true;
  }
  else
  {
    for (std::vector<tr::processQt::propertyBrowser::Property>::const_iterator itSub = m_properties.begin(); itSub != m_properties.end(); ++itSub)
    {
      if (itSub->containsSubProperty(propertyName))
      {
        return true;
      }
    }
  }

  return false;
}

bool tr::processQt::propertyBrowser::Properties::contains(const std::vector<Property>& properties) const
{
  for (std::vector<tr::processQt::propertyBrowser::Property>::const_iterator itProp = properties.begin(); itProp != properties.end(); ++itProp)
  {
    const std::string& propertyName = itProp->getName();
    if (contains(propertyName))
    {
      return true;
    }
  }

  return false;
}

const tr::processQt::propertyBrowser::Property& tr::processQt::propertyBrowser::Properties::getProperty(const std::string& name) const
{
  std::vector<tr::processQt::propertyBrowser::Property>::const_iterator it = std::find(m_properties.begin(), m_properties.end(), name);
  if (it != m_properties.end())
  {
    return (*it);
  }

  for (std::vector<tr::processQt::propertyBrowser::Property>::const_iterator itSub = m_properties.begin(); itSub != m_properties.end(); ++itSub)
  {
    if (itSub->containsSubProperty(name))
    {
      const Property& prop = itSub->getSubProperty(name);
      return prop;
    }
  }
  throw te::common::Exception("Properties::The given property name was not found in the property list");
}

void tr::processQt::propertyBrowser::Properties::setHasWindows(bool windows)
{
  m_hasWindows = windows;
}

bool tr::processQt::propertyBrowser::Properties::hasWindows() const
{
  return m_hasWindows;
}

int tr::processQt::propertyBrowser::Properties::getHashCode()
{
  return m_hashcode;
}

void tr::processQt::propertyBrowser::Properties::setHashCode(int hashCode)
{
  m_hashcode = hashCode;
}

void tr::processQt::propertyBrowser::Properties::reparentProperties(const std::string& parentClass)
{
  for (std::vector<Property>::iterator it = m_properties.begin(); it != m_properties.end(); ++it)
  {
    it->setParent(parentClass);
  }
}

bool tr::processQt::propertyBrowser::Properties::equals(const Properties& properties) const
{
  bool result = true;

  if (m_properties.size() != properties.getProperties().size())
  {
    return false;
  }

  for (std::vector<Property>::const_iterator it = m_properties.begin(); it != m_properties.end(); ++it)
  {
    const Property& prop = (*it);
    const std::string& name = prop.getName();
    if (properties.contains(name) == true)
    {
      const Property& otherProp = properties.getProperty(name);
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
  return result;
}

