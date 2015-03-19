#include <klocalizedstring.h>

/********************************************************************************
** Form generated from reading UI file 'breezeexceptiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREEZEEXCEPTIONDIALOG_H
#define UI_BREEZEEXCEPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BreezeExceptionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *detectDialogButton;
    QLineEdit *exceptionEditor;
    QComboBox *exceptionType;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QCheckBox *borderSizeCheckBox;
    QCheckBox *hideTitleBar;
    QComboBox *borderSizeComboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BreezeExceptionDialog)
    {
        if (BreezeExceptionDialog->objectName().isEmpty())
            BreezeExceptionDialog->setObjectName(QStringLiteral("BreezeExceptionDialog"));
        BreezeExceptionDialog->resize(362, 321);
        verticalLayout = new QVBoxLayout(BreezeExceptionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BreezeExceptionDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        detectDialogButton = new QPushButton(groupBox);
        detectDialogButton->setObjectName(QStringLiteral("detectDialogButton"));

        gridLayout_2->addWidget(detectDialogButton, 2, 2, 1, 1);

        exceptionEditor = new QLineEdit(groupBox);
        exceptionEditor->setObjectName(QStringLiteral("exceptionEditor"));
        exceptionEditor->setProperty("showClearButton", QVariant(true));

        gridLayout_2->addWidget(exceptionEditor, 1, 1, 1, 2);

        exceptionType = new QComboBox(groupBox);
        exceptionType->setObjectName(QStringLiteral("exceptionType"));

        gridLayout_2->addWidget(exceptionType, 0, 1, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BreezeExceptionDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        borderSizeCheckBox = new QCheckBox(groupBox_2);
        borderSizeCheckBox->setObjectName(QStringLiteral("borderSizeCheckBox"));

        gridLayout_3->addWidget(borderSizeCheckBox, 0, 0, 1, 1);

        hideTitleBar = new QCheckBox(groupBox_2);
        hideTitleBar->setObjectName(QStringLiteral("hideTitleBar"));

        gridLayout_3->addWidget(hideTitleBar, 2, 0, 1, 2);

        borderSizeComboBox = new QComboBox(groupBox_2);
        borderSizeComboBox->setObjectName(QStringLiteral("borderSizeComboBox"));
        borderSizeComboBox->setEnabled(false);

        gridLayout_3->addWidget(borderSizeComboBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(BreezeExceptionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef UI_QT_NO_SHORTCUT
        label->setBuddy(exceptionType);
        label_2->setBuddy(exceptionEditor);
#endif // QT_NO_SHORTCUT

        retranslateUi(BreezeExceptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BreezeExceptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BreezeExceptionDialog, SLOT(reject()));
        QObject::connect(borderSizeCheckBox, SIGNAL(toggled(bool)), borderSizeComboBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(BreezeExceptionDialog);
    } // setupUi

    void retranslateUi(QDialog *BreezeExceptionDialog)
    {
        BreezeExceptionDialog->setWindowTitle(tr2i18n("Dialog", 0));
        groupBox->setTitle(tr2i18n("Window Identification", 0));
        label->setText(tr2i18n("&Matching window property: ", 0));
        label_2->setText(tr2i18n("Regular expression &to match: ", 0));
        detectDialogButton->setText(tr2i18n("Detect Window Properties", 0));
        exceptionType->clear();
        exceptionType->insertItems(0, QStringList()
         << tr2i18n("Window Class Name", 0)
         << tr2i18n("Window Title", 0)
        );
        groupBox_2->setTitle(tr2i18n("Decoration Options", 0));
        borderSizeCheckBox->setText(tr2i18n("Border size:", 0));
        hideTitleBar->setText(tr2i18n("Hide window title bar", 0));
        borderSizeComboBox->clear();
        borderSizeComboBox->insertItems(0, QStringList()
         << tr2i18n("No Border", "@item:inlistbox Border size:")
         << tr2i18n("No Side Borders", "@item:inlistbox Border size:")
         << tr2i18n("Tiny", "@item:inlistbox Border size:")
         << tr2i18n("Normal", "@item:inlistbox Border size:")
         << tr2i18n("Large", "@item:inlistbox Border size:")
         << tr2i18n("Very Large", "@item:inlistbox Border size:")
         << tr2i18n("Huge", "@item:inlistbox Border size:")
         << tr2i18n("Very Huge", "@item:inlistbox Border size:")
         << tr2i18n("Oversized", "@item:inlistbox Border size:")
        );
    } // retranslateUi

};

namespace Ui {
    class BreezeExceptionDialog: public Ui_BreezeExceptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BREEZEEXCEPTIONDIALOG_H

