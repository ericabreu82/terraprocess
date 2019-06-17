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
  \file Font.cpp
   
  \brief 

  \ingroup propertyBrowser
*/

// TerraLib
#include "src/process_qt/propertyBrowser/property/Font.h"

// STL
#include <sstream>
#include <string> 
#include <iostream>
#include <vector>
#include <cstdlib>

tr::processQt::propertyBrowser::Font::Font() :
m_family("Arial"),
m_pointSize(12),
m_bold(false),
m_italic(false),
m_underline(false),
m_strikeout(false),
m_kerning(false),
m_textAlign(TPTopLeft)
{

}

tr::processQt::propertyBrowser::Font::~Font()
{

}

void tr::processQt::propertyBrowser::Font::setFamily( const std::string& family )
{
  m_family = family;
}

std::string tr::processQt::propertyBrowser::Font::getFamily() const
{
  return m_family;
}

void tr::processQt::propertyBrowser::Font::setPointSize( int point )
{
  m_pointSize = point;
}

int tr::processQt::propertyBrowser::Font::getPointSize() const
{
  return m_pointSize;
}

void tr::processQt::propertyBrowser::Font::setBold( bool bold )
{
  m_bold = bold;
}

bool tr::processQt::propertyBrowser::Font::isBold() const
{
  return m_bold;
}

void tr::processQt::propertyBrowser::Font::setItalic( bool italic )
{
  m_italic = italic;
}

bool tr::processQt::propertyBrowser::Font::isItalic() const
{
  return m_italic;
}

void tr::processQt::propertyBrowser::Font::setUnderline( bool underline )
{
  m_underline = underline;
}

bool tr::processQt::propertyBrowser::Font::isUnderline() const
{
  return m_underline;
}

void tr::processQt::propertyBrowser::Font::setStrikeout( bool strikeout )
{
  m_strikeout = strikeout;
}

bool tr::processQt::propertyBrowser::Font::isStrikeout() const
{
  return m_strikeout;
}

void tr::processQt::propertyBrowser::Font::setKerning( bool kerning )
{
  m_kerning = kerning;
}

bool tr::processQt::propertyBrowser::Font::isKerning() const
{
  return m_kerning;
}

std::string tr::processQt::propertyBrowser::Font::toString() const
{
  std::string s_convert;
  std::stringstream ss;//create a stringstream

  s_convert = m_family;
  
  ss << m_pointSize;
  s_convert += "," + ss.str();
  s_convert += ",";

  s_convert += toString(m_bold);
  s_convert += ",";
  s_convert += toString(m_italic);
  s_convert += ",";
  s_convert += toString(m_underline);
  s_convert += ",";
  s_convert += toString(m_strikeout);
  s_convert += ",";
  s_convert += toString(m_kerning);

  return s_convert;
}

void tr::processQt::propertyBrowser::Font::fromString( std::string font )
{
  std::vector<std::string> strings;
  std::istringstream f(font);
  std::string s;    
  while (std::getline(f, s, ',')) 
  {
    strings.push_back(s);
  }

  if(strings.empty() || strings.size() > 7)
    return;

  m_family = strings[0];
  m_pointSize = std::atoi(strings[1].c_str());
  m_bold = toBool(strings[2]);
  m_italic = toBool(strings[3]);
  m_underline = toBool(strings[4]);
  m_strikeout = toBool(strings[5]);
  m_kerning = toBool(strings[6]);
}

std::string tr::processQt::propertyBrowser::Font::toString( bool flag ) const
{
  return flag ? "true" : "false"; 
}

bool tr::processQt::propertyBrowser::Font::toBool( std::string str )
{
  if(str.compare("true") == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
