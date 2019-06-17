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

#include "src/process_qt/propertyBrowser/Converters.h"
#include "src/process_qt/propertyBrowser/property/Font.h"

// Qt
#include <QString>
#include <QFont>

//boost
#include <boost/tokenizer.hpp>

std::string tr::processQt::propertyBrowser::Converters::convert2StdString(const QString& qString)
{
  std::string output(qString.toLatin1().constData());
  return output;
}

QString tr::processQt::propertyBrowser::Converters::convert2QString(const std::string& stdString)
{
  return QString::fromLatin1(stdString.c_str());
}

std::vector<std::string> tr::processQt::propertyBrowser::Converters::Tokenize(const std::string& value, const std::string& separator)
{
  std::vector<std::string> vecString;

  //here we need to ensure some additional precision
  typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
  boost::char_separator<char> boostSeparator{ separator.c_str(), "", boost::keep_empty_tokens };
  tokenizer tokenizerStr{ value, boostSeparator };
  for (tokenizer::iterator it = tokenizerStr.begin(); it != tokenizerStr.end(); ++it)
  {
    vecString.push_back(*it);
  }

  return vecString;
}

QFont tr::processQt::propertyBrowser::Converters::convertToQfont(const Font& txtFont) {

  //converts information about the font
  QFont qft;
  qft.setFamily(txtFont.getFamily().c_str());
  qft.setBold(txtFont.isBold());
  qft.setItalic(txtFont.isItalic());
  qft.setKerning(txtFont.isKerning());
  qft.setStrikeOut(txtFont.isStrikeout());
  qft.setUnderline(txtFont.isUnderline());

  //we need to set the font size from PT to MM

  qft.setPointSizeF(txtFont.getPointSize());

  return qft;
}

