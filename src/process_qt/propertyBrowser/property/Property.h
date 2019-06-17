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
  \file Property.h
   
   \brief A property acts like a attribute member of a object and stores the state of this attribute. A set of properties stores the state of an object.
   Any data type, not included in the convertValue method in the class tr::processQt::propertyBrowser::Variant, it will be by default "std::string" value.

  \ingroup propertyBrowser
*/

#ifndef __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY__
#define __TERRAPROCESS_PROCESSQT_PROPERTYBROWSER_PROPERTY__

#include "src/process_qt/Config.h"
#include "src/process_qt/propertyBrowser/enum/EnumType.h"
#include "src/process_qt/propertyBrowser/property/DataTypes.h"
#include "src/process_qt/propertyBrowser/property/DataTypesUtils.h"
#include "src/process_qt/propertyBrowser/property/Data.h"
#include "src/process_qt/propertyBrowser/property/Variant.h"

//Terralib
#include <terralib/datatype/AbstractData.h>

// To declare metatype (QVariant will recognize this type)
#include <QMetaType>

//STL
#include <memory>
#include <string>
#include <vector>

namespace tr
{
  namespace processQt
  {
    namespace propertyBrowser
    {
      /*!
        \brief A property acts like a attribute member of a object and stores the state of this attribute. A set of properties stores the state of an object.
        Any data type, not included in the convertValue method in the class Variant, it will be by default "std::string" value.

        \ingroup propertyBrowser
      */
      class TERRAPROCESSQTEXPORT Property
      {
      public:

        typedef std::unique_ptr<Property> Ptr;

        /*!
          \brief Constructor
        */
        explicit Property(int parentItemHashCode = 0);

        /*!
        \brief Constructor
        */
        Property(const std::string& propertyName, te::dt::AbstractData* data, EnumType* type);

        /*!
        \brief Copy Constructor
        */
        Property(const tr::processQt::propertyBrowser::Property& rhs);

        /*!
          \brief Destructor
        */
        virtual ~Property();

        /*!
          \brief Method that returns the name of this property.

          \return name of this property
        */
        const std::string& getName() const;

        /*!
          \brief Sets the name of this property.

          \param name of this property
        */
        void setName(const std::string& name);

        /*!
          \brief Returns the type of this property

          \return type of this property
        */
        EnumType* getType() const;

        const std::vector<tr::processQt::propertyBrowser::Property>& getSubProperty() const;

        /*
          To use this method, you need to declare a variable with
          corresponding type and pass it as the method parameter.
        */


        /*!
          \brief Stores a copy of value.

          \param Variant object
        */
        void setValue(te::dt::AbstractData* data, EnumType* type, bool usePrecision = false, int precisionValue = 2);

        template <typename T>
        void setValue(const T& value, EnumType* type, bool usePrecision = false, int precisionValue = 2);

        const te::dt::AbstractData* getValue() const;

        /*!
          \brief Returns true if property is editable, false otherwise.

          \return true if property is editable, false otherwise
        */
        bool isEditable() const;

        /*!
          \brief Sets true if property is editable, false otherwise

          \param true if property is editable, false otherwise
        */
        void setEditable(bool editable);

        /*Property Options*/

        void addOption(const Variant& variant);

        void removeOption(const Variant& variant);

        void setOptionChoice(const Variant& variant);
        
        const Variant& getOptionByCurrentChoice() const;

        const std::vector<Variant>& getOptionChoices() const;

        //Ex.: For font information
        void addSubProperty(const Property& property);

        bool addSubProperty(const Property& parent, const Property& subProperty);

        void removeSubProperty(const Property& property);

        bool removeSubProperty(const std::string& name);

        virtual bool updateSubProperty(const Property& property);

        virtual bool completelyUpdateSubProperty(const Property& property);

        /*!
          \brief Returns true if no value has been set, false otherwise.

          \return true if no value has been set, false otherwise
        */
        bool isNull() const;

        /*!
          \brief Reset state of this object. Null state.
        */
        void clear();

        /*!
          \brief Sets the label of this property.

          \param label of this property
        */
        virtual void setLabel(const std::string& label);

        /*!
          \brief Returns the label of this property.

          \return label of this property
        */
        virtual const std::string& getLabel() const;

        /*!
        \brief Checks if the given property name exists on the subproperty list.

        \return TRUE if it exists. FALSE otherwise
        */
        virtual bool containsSubProperty(const std::string& name) const;

        virtual const tr::processQt::propertyBrowser::Property& getSubProperty(const std::string& name) const;

        /*!
        \brief Checks if the values of the current property is equals of the values of the other property.
          Will also check values of the sub properties.
          It also checks whether the number of properties and sub-properties is equal between sets.

        \param property
        \return true if equals, false otherwise
        */
        virtual bool equals(const Property& property) const;

        /*!
          \brief Sets true if property will be used in a menu, false otherwise.

          \param true if property will be used in a menu, false otherwise
        */
        virtual void setMenu(bool menu);

        /*!
          \brief Returns true if property will be used in a menu, false otherwise.

          \return true if property will be used in a menu, false otherwise
        */
        virtual bool isMenu() const;

        virtual void setIcon(const std::string& icon);

        virtual const std::string& getIcon() const;

        /*!
          \brief Sets the visibility of this property.

          \param visibility of this property
        */
        virtual void setVisible(bool visible);

        /*!
          \brief Return true if visible, false otherwise.

          \return true if visible, false otherwise
        */
        virtual bool isVisible() const;

        /*!
          \brief Returns true if property is required, false otherwise.

          \return true if property is required, false otherwise
        */
        bool isRequired() const;

        /*!
          \brief Sets true if property is required, false otherwise

          \param true if property is required, false otherwise
        */
        void setRequired(bool required);

        /*!
          \brief Sets the hashcode of the object that owns this property.

          \param hashcode
        */
        void setParentItemHashCode(int hashCode);

        /*!
          \brief Returns the hashcode of the object that owns this property.

          \return hashcode
        */
        int getParentItemHashCode() const;

        /*!
          \brief Returns true if property compose a widget, false otherwise.
          If true, and the object that owns this property has a parent, it will not appear in a property browser or a menu, it will be used within a widget.

          \return true if property compose a widget, false otherwise
        */
        bool isComposeWidget() const;

        /*!
          \brief Sets true if property compose a widget, false otherwise
          If true, and the object that owns this property has a parent, it will not appear in a property browser or a menu, it will be used within a widget.

          \param true if property compose a widget, false otherwise
        */
        void setComposeWidget(bool compose);

        /*!
          \brief Returns true if property is public, false otherwise.
          If the component, father of this property, is a child of another component,
          then this property can be used by the parent component to display the value or call windows. It can not be edited.

          \return true if property compose a widget, false otherwise
        */
        bool isPublic() const;

        /*!
          \brief Sets true if property is public, false otherwise
          If the component, father of this property, is a child of another component,
          then this property can be used by the parent component to display the value or call windows. It can not be edited.

          \param true if property compose a widget, false otherwise
        */
        void setPublic(bool publicProperty);

        /*!
        \brief Returns true if property is serializable, false otherwise.

        \return true if the property can be serialized in file or database
        */
        bool isSerializable() const;

        /*!
        \brief Sets true if property is serializable, false otherwise.

        \param true if the property can be serialized in file or database
        */
        void setSerializable(bool serializable);

        bool operator ==(const Property& other) const;
        bool operator ==(const std::string& name) const;

        Property& operator =(const Property& other);

        const std::string& getParent() const;
        void setParent(const std::string& parentClass);

        bool getUsePrecision() const;

        void setUsePrecision(bool usePrecision);

        int getPrecision() const;

        void setPrecision(int precision);

        template<typename T> static const T& GetValueAs(const tr::processQt::propertyBrowser::Property& property);

      protected:

        int                                                     m_parentItemHashCode; //!< hashcode of the object that owns this property
        std::string                                             m_name; //!< name of this property
        EnumType*                                               m_type; //!< data type of this property
        Variant                                                 m_currentChoice; //!<
        bool                                                    m_editable; //!<
        std::vector<Variant>                                    m_options; //!<
        std::vector<tr::processQt::propertyBrowser::Property>   m_subProperty; //!<
        std::string                                             m_label; //!<
        bool                                                    m_menu; //!< the property will be used in a menu. 
        std::string                                             m_icon; //!<
        bool                                                    m_visible; //!< visibility
        bool                                                    m_required; //!< required
        bool                                                    m_composeWidget; //!< compose widget
        bool                                                    m_public; //!< public property, used by another component
        mutable Property::Ptr                                   m_nullProperty; //!< Represents a null property
        bool                                                    m_serializable; //!< if true the property can be serialized in file or database
        std::string                                             m_parentClass;

        bool                                                    m_usePrecision; //temporary
        int                                                     m_precisionValue; //temporary
        std::unique_ptr<te::dt::AbstractData>                   m_data; //!< The data inside this property

      };

      inline bool tr::processQt::propertyBrowser::Property::operator ==(const Property& other) const
      {
        if (getName().compare(other.getName()) == 0)
        {
          return true;
        }

        return false;
      }

      inline bool tr::processQt::propertyBrowser::Property::operator ==(const std::string& name) const
      {
        if (getName().compare(name) == 0)
        {
          return true;
        }

        return false;
      }

      inline Property& tr::processQt::propertyBrowser::Property::operator =(const Property& other)
      {
        this->m_parentItemHashCode = other.m_parentItemHashCode;
        this->m_name = other.m_name;
        this->m_type = other.m_type;
        this->m_currentChoice = other.m_currentChoice;
        this->m_editable = other.m_editable;
        this->m_options = other.m_options;
        this->m_subProperty = other.m_subProperty;
        this->m_label = other.m_label;
        this->m_menu = other.m_menu;
        this->m_icon = other.m_icon;
        this->m_visible = other.m_visible;
        this->m_required = other.m_required;
        this->m_composeWidget = other.m_composeWidget;
        this->m_public = other.m_public;
        this->m_serializable = other.m_serializable;
        this->m_parentClass = other.m_parentClass;
        this->m_usePrecision = other.m_usePrecision;
        this->m_precisionValue = other.m_precisionValue;
        if (other.m_data.get() != 0)
        {
          this->m_data.reset(other.m_data->clone());
        }

        return *this;
      }

      template<typename T>
      const T& tr::processQt::propertyBrowser::Property::GetValueAs(const tr::processQt::propertyBrowser::Property& property)
      {
        const te::dt::AbstractData* absData = property.getValue();
        return tr::processQt::propertyBrowser::GetValueAs<T>(absData);
      }

      template <typename T>
      void tr::processQt::propertyBrowser::Property::setValue(const T& value, EnumType* type, bool usePrecision, int precisionValue)
      {
        te::dt::AbstractData* absData = CreateData<T>(value);
        setValue(absData, type, usePrecision, precisionValue);
      }
    }
  }
}

Q_DECLARE_METATYPE(tr::processQt::propertyBrowser::Property) // To declare metatype (QVariant will recognize this type)

#endif
