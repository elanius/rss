/********************************************************************************
** Form generated from reading UI file 'rss.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSS_H
#define UI_RSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rssClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QLineEdit *leNewFeed;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbAdd;
    QPushButton *pdRemove;
    QPushButton *pbRefresh;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *rssClass)
    {
        if (rssClass->objectName().isEmpty())
            rssClass->setObjectName(QStringLiteral("rssClass"));
        rssClass->resize(724, 538);
        centralWidget = new QWidget(rssClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 631, 431));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        treeWidget = new QTreeWidget(horizontalLayoutWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        leNewFeed = new QLineEdit(horizontalLayoutWidget);
        leNewFeed->setObjectName(QStringLiteral("leNewFeed"));

        verticalLayout->addWidget(leNewFeed);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbAdd = new QPushButton(horizontalLayoutWidget);
        pbAdd->setObjectName(QStringLiteral("pbAdd"));

        horizontalLayout_2->addWidget(pbAdd);

        pdRemove = new QPushButton(horizontalLayoutWidget);
        pdRemove->setObjectName(QStringLiteral("pdRemove"));

        horizontalLayout_2->addWidget(pdRemove);

        pbRefresh = new QPushButton(horizontalLayoutWidget);
        pbRefresh->setObjectName(QStringLiteral("pbRefresh"));

        horizontalLayout_2->addWidget(pbRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        plainTextEdit = new QPlainTextEdit(horizontalLayoutWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        rssClass->setCentralWidget(centralWidget);

        retranslateUi(rssClass);
        QObject::connect(pbAdd, SIGNAL(clicked()), rssClass, SLOT(onAdd()));
        QObject::connect(pdRemove, SIGNAL(clicked()), rssClass, SLOT(onRemove()));
        QObject::connect(pbRefresh, SIGNAL(clicked()), rssClass, SLOT(onRefresh()));

        QMetaObject::connectSlotsByName(rssClass);
    } // setupUi

    void retranslateUi(QMainWindow *rssClass)
    {
        rssClass->setWindowTitle(QApplication::translate("rssClass", "rss", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("rssClass", "default", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("rssClass", "http://rss.sme.sk/rss/rss.asp?id=frontpage", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        pbAdd->setText(QApplication::translate("rssClass", "+", Q_NULLPTR));
        pdRemove->setText(QApplication::translate("rssClass", "-", Q_NULLPTR));
        pbRefresh->setText(QApplication::translate("rssClass", "Refresh", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rssClass: public Ui_rssClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSS_H
