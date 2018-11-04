/********************************************************************************
** Form generated from reading UI file 'WidgetPFD.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPFD_H
#define UI_WIDGETPFD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "qfi_PFD.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetPFD
{
public:
    QFrame *framePFD;
    QGridLayout *gridLayout;
    qfi_PFD *graphicsPFD;

    void setupUi(QWidget *WidgetPFD)
    {
        if (WidgetPFD->objectName().isEmpty())
            WidgetPFD->setObjectName(QString::fromUtf8("WidgetPFD"));
        WidgetPFD->resize(400, 400);
        framePFD = new QFrame(WidgetPFD);
        framePFD->setObjectName(QString::fromUtf8("framePFD"));
        framePFD->setGeometry(QRect(70, 70, 260, 260));
        framePFD->setStyleSheet(QString::fromUtf8("#framePFD\n"
"{\n"
"	background-color: #000;\n"
"	border-radius: 10px;\n"
"}"));
        framePFD->setFrameShape(QFrame::StyledPanel);
        framePFD->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(framePFD);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsPFD = new qfi_PFD(framePFD);
        graphicsPFD->setObjectName(QString::fromUtf8("graphicsPFD"));
        graphicsPFD->setEnabled(false);
        graphicsPFD->setFocusPolicy(Qt::NoFocus);
        graphicsPFD->setFrameShape(QFrame::NoFrame);
        graphicsPFD->setFrameShadow(QFrame::Plain);
        graphicsPFD->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsPFD->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsPFD->setInteractive(false);
        graphicsPFD->setOptimizationFlags(QGraphicsView::IndirectPainting);

        gridLayout->addWidget(graphicsPFD, 0, 0, 1, 1);


        retranslateUi(WidgetPFD);

        QMetaObject::connectSlotsByName(WidgetPFD);
    } // setupUi

    void retranslateUi(QWidget *WidgetPFD)
    {
        WidgetPFD->setWindowTitle(QApplication::translate("WidgetPFD", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WidgetPFD: public Ui_WidgetPFD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPFD_H
