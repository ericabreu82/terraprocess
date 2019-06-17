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
  \file Variant.h
   
  \brief Class acts like a union for some C++/TerraLib5 data types. Responsible for storing the value.
  Any data type, not included in the convertValue method in this class, it will be by default "std::string".
  Storing value types:

    - std::string 
    - double
    - int 
    - long 
    - float 
    - bool 
    - te::color::RGBAColor 
    - tr::processQt::propertyBrowser::Font 

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_VARIANT__ 
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_VARIANT__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/property/Font.h"
#include "src/process_qt/propertyBrowser/enum/AbstractType.h"
#include "src/process_qt/propertyBrowser/enum/EnumType.h"

#include <terralib/color/RGBAColor.h>
#include <terralib/geometry/Geometry.h>
#include <terralib/maptools/AbstractLayer.h>

// STL
#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
        \brief Class acts like a union for some C++/TerraLib5 data types. Responsible for storing the value.
         Any data type, not included in the convertValue method in this class, it will be by default "std::string".
         Storing value types:

          - std::string
          - double
          - int
          - long
          - float
          - bool
          - te::color::RGBAColor
          - Font

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT Variant
      {
      public:

        /*!
          \brief Constructor
        */
        Variant();

        /*!
          \brief Constructor

          \type data type
          \valueCopy value pointer (real data)
        */
        Variant(EnumType* type, const void* valueCopy);

        /*!
          \brief Destructor
        */
        virtual ~Variant();

        /*!
          \brief Stores a copy of value.

          \param value copies the value to be stored
          \param type data type
        */
        template <typename ValueType>
        void setValue(ValueType value, EnumType* type);

        /*!
          \brief
        */
        virtual void fromString(const std::string& value, EnumType* type);

        /*!
          \brief Returns data type of this object.
        */
        EnumType* getType() const;

        /*!
          \brief Return true if value is not of common C++ data type, false otherwise.

          \param true if value is not of common C++ data type, false otherwise
        */
        virtual bool isComplex() const;

        /*!
          \brief Returns the value of string type. (The setValue method received a string)

          \return value of string type
        */
        const std::string& toString() const;

        /*!
          \brief Returns the value of double type. (The setValue method received a double)

          \return value of double type
        */
        double toDouble() const;

        /*!
          \brief Returns the value of int type. (The setValue method received a int)

          \return value of int type
        */
        int toInt() const;

        /*!
          \brief Returns the value of long type. (The setValue method received a long)

          \return value of long type
        */
        long toLong() const;

        /*!
          \brief Returns the value of float type. (The setValue method received a float)

          \return value of float type
        */
        float toFloat() const;

        /*!
          \brief Returns the value of boolean type. (The setValue method received a boolean)

          \return value of boolean type
        */
        bool toBool() const;

        /*!
          \brief Returns the value of te::color::RGBAColor type. (The setValue method received a te::color::RGBAColor). Complex type.

          \return value of te::color::RGBAColor type
        */
        const te::color::RGBAColor& toColor() const;

        /*!
          \brief Returns the value of Font type. (The setValue method received a te::layout::Font). Complex type.

          \return value of Font type
        */
        const Font& toFont() const;

        /*!
          \brief Returns the value of Font type. (The setValue method received a te::layout::Font). Complex type.

          \return value of Font type
        */
        const te::gm::Envelope& toEnvelope() const;

        /*!
          \brief Returns the shared pointer of te::gm::Geometry type. (The setValue method received a shared pointer of te::gm::Geometry).

          \return shared poiniter of te::gm::Geometry type
        */
        const te::gm::GeometryShrPtr toGeometry() const;

        /*!
        \brief Returns the list of shared pointer of te::map::AbstractLayerPtr type. (The setValue method received a list of shared pointer of te::map::AbstractLayer).

        \return list of shared pointer of te::map::AbstractLayerPtr type
        */
        const std::list<te::map::AbstractLayerPtr> toLayerList() const;

        /*!
        \brief Returns the vector of string. (The setValue method received a vector of string).

        \return vector of string
        */
        const std::vector<std::string>& toStringVector() const;

        /*!
        \brief Returns the vector of string. (The setValue method received a vector of string).

        \return vector of string
        */
        const std::vector< std::vector<std::string> >& toStringMatrix() const;

        /*!
          \brief Converts the value to a string.

          \return Value as a string
        */
        virtual std::string convertToString() const;

        /*!
          \brief Returns true if no value has been set, false otherwise.

          \return true if no value has been set, false otherwise
        */
        bool isNull() const;

        /*!
          \brief Reset state of object. Null state.
        */
        virtual void clear();

        virtual void setPrecision(int p);

        virtual void usePrecision(bool usePrecision);

        virtual int getprecision() const;

        virtual bool isUsingPrecision() const;

        bool operator ==(const Variant& other) const;

        bool operator !=(const Variant& other) const;

        Variant& operator=(const Variant& properties);

      protected:

        /*!
            \brief Stores a copy of value.

            \param v this object
            \param value copies the value to be stored
            \param type data type
          */
        template <typename ValueType>
        void variantSetValue(Variant& v, const ValueType& value, EnumType* type);

        /*!
            \brief Discovers the type of the value and sets for the corresponding attribute (storage).
            Any type of data, not included in this class, it will be by default "std::string"

            \param valueCopy pointer of the value to be stored
         */
        void convertValue(const void* valueCopy);

        /*!
            \brief Convert a string representation of a number into a double value.

            \param str string representation of a number
            \return double value
         */
        virtual double string2Double(std::string str);

        /*!
            \brief Convert a string representation of a number into a int value.

            \param str string representation of a number
            \return int value
         */
        virtual int string2Int(std::string str);

        /*!
            \brief Convert a string representation of a number into a float value.

            \param str string representation of a number
            \return float value
         */
        virtual float string2Float(std::string str);

        /*!
            \brief Convert a string representation of a number into a long value.

            \param str string representation of a number
            \return long value
         */
        virtual long string2Long(std::string str);

        /*!
            \brief Convert a int value into a string representation of a number.

            \param value int value
            \return string representation of a number
         */
        virtual std::string toString(int value) const;

        /*!
        \brief Convert a double value into a string representation of a number.

        \param value int value
        \return string representation of a number
        */
        virtual std::string toString(double value) const;

        /*!
            \brief Convert a string value into a boolean representation of a string. Ex.: true, false.

            \param str string value
            \return boolean representation of a string. Ex.: true, false
         */
        virtual bool toBool(std::string str);


        std::string                           m_sValue; //!< value of string type
        double                                m_dValue; //!< value of double type
        int                                   m_iValue; //!< value of int type
        long                                  m_lValue; //!< value of long type
        float                                 m_fValue; //!< value of float type
        bool                                  m_bValue; //!< value of boolean type 
        te::color::RGBAColor                  m_colorValue; //!< value of te::color::RGBAColor type
        Font                                  m_fontValue; //!< value of Font type
        te::gm::Envelope                      m_envelopeValue; //!< value of the envelope type
        EnumType* m_type; //!< data type of this object
        bool                                  m_null; //!< true if no value has been set, false otherwise
        bool                                  m_complex; //!< true if value is not of common C++ data type, false otherwise
        te::gm::GeometryShrPtr                m_geometryPtr; //!< shared pointer of te::gm::Geometry type
        std::vector<std::string>              m_vString; //!< value of string vector type
        std::vector< std::vector<std::string> > m_stringMatrix; //!< value vector of string vector type
        std::list<te::map::AbstractLayerPtr>  m_listLayer; //!< value of te::map::AbstractLayerPtr list type
        bool                                  m_usePrecision; //!< true if uses precision in double value
        int                                   m_precision; //!< value of precision
      };

      template<typename ValueType>
      inline void tr::processQt::propertyBrowser::Variant::setValue(ValueType value, EnumType* type)
      {
        ValueType v = value;
        variantSetValue(*this, v, type);
      }

      /* Is still necessary to revise this method.*/
      template <typename ValueType>
      inline void tr::processQt::propertyBrowser::Variant::variantSetValue(Variant& v,
        const ValueType& value, EnumType* type)
      {
        v = Variant(type, &value);
      }
    }
  }
}

#endif
