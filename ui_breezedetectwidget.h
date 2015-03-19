#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'breezedetectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREEZEDETECTWIDGET_H
#define UI_BREEZEDETECTWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BreezeDetectWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *windowClass;
    QLabel *label_2;
    QLabel *windowTitle;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *windowClassCheckBox;
    QRadioButton *windowTitleCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BreezeDetectWidget)
    {
        if (BreezeDetectWidget->objectName().isEmpty())
            BreezeDetectWidget->setObjectName(QStringLiteral("BreezeDetectWidget"));
        BreezeDetectWidget->resize(400, 239);
        verticalLayout = new QVBoxLayout(BreezeDetectWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BreezeDetectWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        windowClass = new QLabel(groupBox);
        windowClass->setObjectName(QStringLiteral("windowClass"));
        windowClass->setText(QStringLiteral("TextLabel"));

        gridLayout->addWidget(windowClass, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        windowTitle = new QLabel(groupBox);
        windowTitle->setObjectName(QStringLiteral("windowTitle"));
        windowTitle->setText(QStringLiteral("TextLabel"));

        gridLayout->addWidget(windowTitle, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BreezeDetectWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        windowClassCheckBox = new QRadioButton(groupBox_2);
        windowClassCheckBox->setObjectName(QStringLiteral("windowClassCheckBox"));

        verticalLayout_2->addWidget(windowClassCheckBox);

        windowTitleCheckBox = new QRadioButton(groupBox_2);
        windowTitleCheckBox->setObjectName(QStringLiteral("windowTitleCheckBox"));
        windowTitleCheckBox->setLocale(QLocale(QLocale::French, QLocale::France));

        verticalLayout_2->addWidget(windowTitleCheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(BreezeDetectWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BreezeDetectWidget);
        QObject::connect(buttonBox, SIGNAL(accepted()), BreezeDetectWidget, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BreezeDetectWidget, SLOT(reject()));

        QMetaObject::connectSlotsByName(BreezeDetectWidget);
    } // setupUi

    void retranslateUi(QDialog *BreezeDetectWidget)
    {
        BreezeDetectWidget->setWindowTitle(tr2i18n("Dialog", 0));
        groupBox->setTitle(tr2i18n("Information about Selected Window", 0));
        label->setText(tr2i18n("Class: ", 0));
        label_2->setText(tr2i18n("Title: ", 0));
        groupBox_2->setTitle(tr2i18n("Window Property Selection", 0));
        windowClassCheckBox->setText(tr2i18n("Use window class (whole application)", 0));
        windowTitleCheckBox->setText(tr2i18n("Use window title", 0));
    } // retranslateUi

};

namespace Ui {
    class BreezeDetectWidget: public Ui_BreezeDetectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BREEZEDETECTWIDGET_H

