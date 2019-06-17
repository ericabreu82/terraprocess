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

#include "src/process_qt/propertyBrowser/property/DataConverters.h"

#include "src/process_qt/propertyBrowser/property/DataTypes.h"
#include "src/process_qt/propertyBrowser/property/DataTypesUtils.h"
#include "src/process_qt/propertyBrowser/property/Data.h"
#include "src/process_qt/propertyBrowser/Converters.h"

//DataTypes
#include "src/process_qt/propertyBrowser/property/Font.h"

//Terralib
#include <terralib/color/RGBAColor.h>
#include <terralib/common/Exception.h>
#include <terralib/geometry/Envelope.h>
#include <terralib/geometry/Geometry.h>
#include <terralib/geometry/WKTReader.h>
#include <terralib/maptools/AbstractLayer.h>

// Boost
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>


te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertBoolToString(te::dt::AbstractData* abstractData)
{
  return ConvertToStringUsingBoost<bool>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToBool(te::dt::AbstractData* abstractData)
{
  return ConvertFromStringUsingBoost<bool>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertColorToString(te::dt::AbstractData* abstractData)
{
  const te::color::RGBAColor& color = GetValueAs<te::color::RGBAColor>(abstractData);
  std::string strColor = boost::lexical_cast<std::string>(color.getRed());
  strColor += "," + boost::lexical_cast<std::string>(color.getGreen());
  strColor += "," + boost::lexical_cast<std::string>(color.getBlue());
  strColor += "," + boost::lexical_cast<std::string>(color.getAlpha());

  return CreateData<std::string>(strColor);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToColor(te::dt::AbstractData* abstractData)
{
  const std::string& strValue = GetValueAs<std::string>(abstractData);
  std::vector<std::string> vecTokens = tr::processQt::propertyBrowser::Converters::Tokenize(strValue, ",");

  if (vecTokens.size() != 4)
  {
    throw te::common::Exception("ConvertStringToColor: Cannot convert from String to Color");
  }

  int r = boost::lexical_cast<int>(vecTokens[0]);
  int g = boost::lexical_cast<int>(vecTokens[1]);
  int b = boost::lexical_cast<int>(vecTokens[2]);
  int a = boost::lexical_cast<int>(vecTokens[3]);

  te::color::RGBAColor rgbaColor(r, g, b, a);
  return CreateData<te::color::RGBAColor>(rgbaColor);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertDoubleToString(te::dt::AbstractData* abstractData)
{
  return ConvertToStringUsingBoost<double>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToDouble(te::dt::AbstractData* abstractData)
{
  return ConvertFromStringUsingBoost<double>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertEnvelopeToString(te::dt::AbstractData* abstractData)
{
  const te::gm::Envelope& envelope = GetValueAs<te::gm::Envelope>(abstractData);

  //here we need to ensure some additional precision
  std::ostringstream convert;
  convert.precision(15);

  if (envelope.isValid())
  {
    convert << envelope.getLowerLeftX();
    convert << "," << envelope.getLowerLeftY();
    convert << "," << envelope.getUpperRightX();
    convert << "," << envelope.getUpperRightY();
  }
  
  return CreateData<std::string>(convert.str());
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToEnvelope(te::dt::AbstractData* abstractData)
{
  const std::string& strValue = GetValueAs<std::string>(abstractData);
  if (strValue.empty())
  {
    te::gm::Envelope envelope;
    return CreateData<te::gm::Envelope>(envelope);
  }

  std::vector<std::string> vecTokens = tr::processQt::propertyBrowser::Converters::Tokenize(strValue, ",");
  if (vecTokens.size() != 4)
  {
    throw te::common::Exception("ConvertStringToEnvelope: Cannot convert from String to Envelope");
  }

  double x1 = boost::lexical_cast<double>(vecTokens[0]);
  double y1 = boost::lexical_cast<double>(vecTokens[1]);
  double x2 = boost::lexical_cast<double>(vecTokens[2]);
  double y2 = boost::lexical_cast<double>(vecTokens[3]);

  te::gm::Envelope envelope(x1, y1, x2, y2);
  return CreateData<te::gm::Envelope>(envelope);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertFontToString(te::dt::AbstractData* abstractData)
{
  const tr::processQt::propertyBrowser::Font& font = GetValueAs<tr::processQt::propertyBrowser::Font>(abstractData);

  std::string strValue = font.toString();
  return CreateData<std::string>(strValue);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToFont(te::dt::AbstractData* abstractData)
{
  const std::string& strValue = GetValueAs<std::string>(abstractData);

  tr::processQt::propertyBrowser::Font font;
  font.fromString(strValue);

  return CreateData<tr::processQt::propertyBrowser::Font>(font);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertGeometryToString(te::dt::AbstractData* abstractData)
{
  te::gm::GeometryShrPtr geometry(GetValueAs<te::gm::GeometryShrPtr>(abstractData));
  
  std::string strValue = geometry->asText();
  return CreateData<std::string>(strValue);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToGeometry(te::dt::AbstractData* abstractData)
{
  const std::string& strValue = GetValueAs<std::string>(abstractData);

  te::gm::GeometryShrPtr geometry(te::gm::WKTReader::read(strValue.c_str()));
  return CreateData<te::gm::GeometryShrPtr>(geometry);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertIntToString(te::dt::AbstractData* abstractData)
{
  return ConvertToStringUsingBoost<int>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToInt(te::dt::AbstractData* abstractData)
{
  return ConvertFromStringUsingBoost<int>(abstractData);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringListToString(te::dt::AbstractData* abstractData)
{
  const std::vector<std::string>& vecString = GetValueAs< std::vector<std::string> >(abstractData);

  std::string strValue;
  for (std::size_t i = 0; i < vecString.size(); ++i)
  {
    if (i > 0)
    {
      strValue += ",";
    }
    strValue += vecString[i];
  }

  return CreateData<std::string>(strValue);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToStringList(te::dt::AbstractData* abstractData)
{
  const std::string& strValue = GetValueAs<std::string>(abstractData);

  std::vector<std::string> vecTokens = tr::processQt::propertyBrowser::Converters::Tokenize(strValue, ",");
  return CreateData< std::vector<std::string> >(vecTokens);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringMatrixToString(te::dt::AbstractData* abstractData)
{
  const std::vector< std::vector<std::string> >& stringMatrix = GetValueAs< std::vector< std::vector<std::string> > >(abstractData);

  std::string strValue;
  for (std::size_t i = 0; i < stringMatrix.size(); ++i)
  {
    if (i > 0)
    {
      strValue += ";";
    }

    for (std::size_t j = 0; j < stringMatrix[i].size(); ++j)
    {
      if (j > 0)
      {
        strValue += ",";
      }

      strValue += stringMatrix[i][j];
    }
  }

  return CreateData<std::string>(strValue);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToStringMatrix(te::dt::AbstractData* abstractData)
{
  std::vector< std::vector<std::string> > stringMatrix;

  const std::string& strValue = GetValueAs<std::string>(abstractData);

  std::vector<std::string> vecRows = tr::processQt::propertyBrowser::Converters::Tokenize(strValue, ";");
  for (std::size_t i = 0; i < vecRows.size(); ++i)
  {
    std::vector<std::string> vecColumns = tr::processQt::propertyBrowser::Converters::Tokenize(vecRows[i], ",");
    stringMatrix.push_back(vecColumns);
  }

  return CreateData< std::vector< std::vector<std::string> > >(stringMatrix);
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertAbstractLayerListToString(te::dt::AbstractData* abstractData)
{
  return CreateData<std::string>("");
}

te::dt::AbstractData* tr::processQt::propertyBrowser::ConvertStringToAbstractLayerList(te::dt::AbstractData* abstractData)
{
  std::list<te::map::AbstractLayerPtr> emptyList;

  return CreateData< std::list<te::map::AbstractLayerPtr> >(emptyList);
}