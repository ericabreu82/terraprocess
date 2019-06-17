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
\file Converters.h

\brief This file contains several data-type converter functions

\ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_CONVERTERS__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_CONVERTERS__

#include "src/process_qt/Config.h"

#include <string>
#include <vector>

class QString;
class QFont;

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      class Font;

      class TERRAPROCESSQTEXPORT Converters
      {
          public:

            static std::string convert2StdString(const QString& qString);

            static QString convert2QString(const std::string& stdString);

            static std::vector<std::string> Tokenize(const std::string& value, const std::string& separator);

            /*!
              \brief This function converts a object Font to QFont

              \param txtFont object Font
            */
            static QFont convertToQfont(const Font& txtFont);
      };
    }
  }
}

#endif //__TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_CONVERTERS__ 
