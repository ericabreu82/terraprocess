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

#include "src/process_qt/propertyBrowser/dialog/ColorWidget.h"

//terralib includes
#include <terralib/qt/widgets/utils/HorizontalSliderWidget.h>

//qt includes
#include <QColorDialog>
#include <QLabel>
#include <QSlider>
#include <QGridLayout>

tr::processQt::propertyBrowser::ColorWidget::ColorWidget(QWidget* parent, Qt::WindowFlags f)
  : QWidget(parent, f)
  , m_colorDialog(0)
  , m_sliderWidget(0)
  , m_propagateColorUpdate(true)
{
	QGridLayout* gridLayout = new QGridLayout(this);

	m_colorDialog = new QColorDialog(this);
  m_colorDialog->setWindowFlags(Qt::Widget);
  m_colorDialog->setOption(QColorDialog::ShowAlphaChannel, false);
  m_colorDialog->setOption(QColorDialog::NoButtons, true);
  m_colorDialog->setOption(QColorDialog::DontUseNativeDialog, true);

	// transparency slider bar
	m_sliderWidget = new te::qt::widgets::HorizontalSliderWidget(this);
	m_sliderWidget->setTitle(tr("Transparency"));
	m_sliderWidget->setMinMaxValues(0, 100);
	m_sliderWidget->setDefaultValue(0);

  gridLayout->addWidget(m_colorDialog);
  gridLayout->addWidget(m_sliderWidget);
}

tr::processQt::propertyBrowser::ColorWidget::~ColorWidget()
{
  delete m_colorDialog;
  delete m_sliderWidget;
}

void tr::processQt::propertyBrowser::ColorWidget::setColor(const QColor& color)
{
  int transparency = 100 - qRound(color.alpha() * 100. / 255.);

  m_colorDialog->setCurrentColor(color);
  m_sliderWidget->setCurrentValue(transparency);
}

QColor tr::processQt::propertyBrowser::ColorWidget::getColor() const
{
  int alpha = 255 - qRound(m_sliderWidget->getValue() * 255. / 100.);

  QColor color = m_colorDialog->currentColor();
  color.setAlpha(alpha);

  return color;
}
