#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'breezeconfigurationui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREEZECONFIGURATIONUI_H
#define UI_BREEZECONFIGURATIONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "config/breezeexceptionlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_BreezeConfigurationUI
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *titleAlignment;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QCheckBox *drawBorderOnMaximizedWindows;
    QComboBox *buttonSize;
    QCheckBox *drawSizeGrip;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *animationsDurationLabel;
    QSpinBox *animationsDuration;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *animationsEnabled;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    Breeze::ExceptionListWidget *exceptions;

    void setupUi(QWidget *BreezeConfigurationUI)
    {
        if (BreezeConfigurationUI->objectName().isEmpty())
            BreezeConfigurationUI->setObjectName(QStringLiteral("BreezeConfigurationUI"));
        BreezeConfigurationUI->resize(433, 548);
        verticalLayout = new QVBoxLayout(BreezeConfigurationUI);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BreezeConfigurationUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        titleAlignment = new QComboBox(groupBox);
        titleAlignment->setObjectName(QStringLiteral("titleAlignment"));

        gridLayout->addWidget(titleAlignment, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        drawBorderOnMaximizedWindows = new QCheckBox(groupBox);
        drawBorderOnMaximizedWindows->setObjectName(QStringLiteral("drawBorderOnMaximizedWindows"));

        gridLayout->addWidget(drawBorderOnMaximizedWindows, 2, 0, 1, 3);

        buttonSize = new QComboBox(groupBox);
        buttonSize->setObjectName(QStringLiteral("buttonSize"));

        gridLayout->addWidget(buttonSize, 1, 1, 1, 1);

        drawSizeGrip = new QCheckBox(groupBox);
        drawSizeGrip->setObjectName(QStringLiteral("drawSizeGrip"));

        gridLayout->addWidget(drawSizeGrip, 3, 0, 1, 3);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BreezeConfigurationUI);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        animationsDurationLabel = new QLabel(groupBox_2);
        animationsDurationLabel->setObjectName(QStringLiteral("animationsDurationLabel"));
        animationsDurationLabel->setEnabled(false);

        gridLayout_2->addWidget(animationsDurationLabel, 2, 0, 1, 1);

        animationsDuration = new QSpinBox(groupBox_2);
        animationsDuration->setObjectName(QStringLiteral("animationsDuration"));
        animationsDuration->setEnabled(false);
        animationsDuration->setMaximum(500);

        gridLayout_2->addWidget(animationsDuration, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        animationsEnabled = new QCheckBox(groupBox_2);
        animationsEnabled->setObjectName(QStringLiteral("animationsEnabled"));

        gridLayout_2->addWidget(animationsEnabled, 0, 0, 1, 3);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(BreezeConfigurationUI);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        exceptions = new Breeze::ExceptionListWidget(groupBox_3);
        exceptions->setObjectName(QStringLiteral("exceptions"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exceptions->sizePolicy().hasHeightForWidth());
        exceptions->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(exceptions);


        verticalLayout->addWidget(groupBox_3);

#ifndef UI_QT_NO_SHORTCUT
        label_3->setBuddy(titleAlignment);
        label_4->setBuddy(buttonSize);
        animationsDurationLabel->setBuddy(animationsDuration);
#endif // QT_NO_SHORTCUT

        retranslateUi(BreezeConfigurationUI);
        QObject::connect(animationsEnabled, SIGNAL(toggled(bool)), animationsDurationLabel, SLOT(setEnabled(bool)));
        QObject::connect(animationsEnabled, SIGNAL(toggled(bool)), animationsDuration, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(BreezeConfigurationUI);
    } // setupUi

    void retranslateUi(QWidget *BreezeConfigurationUI)
    {
        groupBox->setTitle(tr2i18n("General", 0));
        label_3->setText(tr2i18n("Tit&le alignment:", 0));
        titleAlignment->clear();
        titleAlignment->insertItems(0, QStringList()
         << tr2i18n("Left", 0)
         << tr2i18n("Center", 0)
         << tr2i18n("Center (Full Width)", 0)
         << tr2i18n("Right", 0)
        );
        label_4->setText(tr2i18n("B&utton size:", 0));
        drawBorderOnMaximizedWindows->setText(tr2i18n("Display window borders for maximized windows", 0));
        buttonSize->clear();
        buttonSize->insertItems(0, QStringList()
         << tr2i18n("Small", "@item:inlistbox Button size:")
         << tr2i18n("Normal", "@item:inlistbox Button size:")
         << tr2i18n("Large", "@item:inlistbox Button size:")
         << tr2i18n("Very Large", "@item:inlistbox Button size:")
        );
        drawSizeGrip->setText(tr2i18n("Add handle to resize windows with no border", 0));
        groupBox_2->setTitle(tr2i18n("Animations", 0));
        animationsDurationLabel->setText(tr2i18n("&Animations duration:", 0));
        animationsDuration->setSuffix(tr2i18n("ms", 0));
        animationsEnabled->setText(tr2i18n("Enable animations", 0));
        groupBox_3->setTitle(tr2i18n("Window-Specific Overrides", 0));
        Q_UNUSED(BreezeConfigurationUI);
    } // retranslateUi

};

namespace Ui {
    class BreezeConfigurationUI: public Ui_BreezeConfigurationUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BREEZECONFIGURATIONUI_H

