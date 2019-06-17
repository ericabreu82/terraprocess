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
  \file Font.h
   
  \brief Class specifies a font.

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FONT__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_FONT__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/AbstractType.h"

// STL
#include <string>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
        \brief Class specifies a font.

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT Font
      {
      public:

        /*!
         \brief Constructor
        */
        Font();

        /*!
         \brief Destructor
        */
        virtual ~Font();

        /*!
          \brief Returns font family name.

          \param font family name
        */
        void setFamily(const std::string& family);

        /*!
          \brief Sets font family name.

          \return font family name
        */
        std::string getFamily() const;

        /*!
          \brief Sets point size of the font.

          \param point size of the font
        */
        void setPointSize(int point);

        /*!
          \brief Returns point size of the font.

          \return point size of the font
        */
        int getPointSize() const;

        /*!
          \brief Sets font with bold style.

          \param true if font use bold, false otherwise
        */
        void setBold(bool bold);

        /*!
          \brief Returns true if font use bold, false otherwise

          \return true if font use bold, false otherwise
        */
        bool isBold() const;

        /*!
          \brief Sets font with italic style.

          \param true if font use italic, false otherwise
        */
        void setItalic(bool italic);

        /*!
          \brief Returns true if font use italic, false otherwise

          \return true if font use italic, false otherwise
        */
        bool isItalic() const;

        /*!
          \brief Sets font with underline style.

          \param true if font use underline, false otherwise
        */
        void setUnderline(bool underline);

        /*!
          \brief Returns true if font use underline, false otherwise

          \return true if font use underline, false otherwise
        */
        bool isUnderline() const;

        /*!
          \brief Sets font with strikeout style.

          \param true if font use strikeout, false otherwise
        */
        void setStrikeout(bool strikeout);

        /*!
          \brief Returns true if font use strikeout, false otherwise

          \return true if font use strikeout, false otherwise
        */
        bool isStrikeout() const;

        /*!
          \brief Sets font with kerning style.

          \param true if font use kerning, false otherwise
        */
        void setKerning(bool kerning);

        /*!
          \brief Returns true if font use kerning, false otherwise

          \return true if font use kerning, false otherwise
        */
        bool isKerning() const;

        /*!
          \brief Serialize font object.

          \return font object serialized
        */
        virtual std::string toString() const;

        /*!
          \brief Sets this object state from a string.

          \param font object serialized
        */
        virtual void fromString(std::string font);

        /*!
        \brief

        \param
        \return
        */
        bool operator==(const Font& font) const;

        /*!
        \brief

        \param
        \return
        */
        bool operator!=(const Font& font) const;

      protected:

        /*!
          \brief State boolean to string.

          \param font style option
        */
        virtual std::string toString(bool flag) const;

        /*!
          \brief State string to boolean.

          \param font style option
        */
        virtual bool toBool(std::string str);

        std::string m_family; //!< font family name
        int m_pointSize; //!< point size of the font
        bool m_bold; //!< true if font use bold, false otherwise  
        bool m_italic; //!< true if font use italic, false otherwise
        bool m_underline; //!< true if font use underline, false otherwise
        bool m_strikeout; //!< true if font use strikeout, false otherwise
        bool m_kerning; //!< true if font use kerning, false otherwise  
        Align m_textAlign; //!<
      };

      inline bool tr::processQt::propertyBrowser::Font::operator==(const Font& font) const
      {
        bool result = false;
        if (m_family == font.getFamily()
          && m_pointSize == font.getPointSize()
          && m_bold == font.isBold()
          && m_italic == font.isItalic()
          && m_underline == font.isUnderline()
          && m_strikeout == font.isStrikeout()
          && m_kerning == font.isKerning())
        {
          result = true;
        }
        return result;
      }

      inline bool tr::processQt::propertyBrowser::Font::operator!=(const Font& font) const
      {
        return !operator==(font);
      }
    }
  }
}

#endif
