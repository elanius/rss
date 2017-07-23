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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rssClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *lChannels;
    QLabel *label;
    QLineEdit *leNewFeed;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbAdd;
    QPushButton *pdRemove;
    QPushButton *pbRefresh;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *lArticles;

    void setupUi(QMainWindow *rssClass)
    {
        if (rssClass->objectName().isEmpty())
            rssClass->setObjectName(QStringLiteral("rssClass"));
        rssClass->resize(724, 538);
        centralWidget = new QWidget(rssClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(724, 16777215));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lChannels = new QListWidget(centralWidget);
        lChannels->setObjectName(QStringLiteral("lChannels"));

        verticalLayout->addWidget(lChannels);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        leNewFeed = new QLineEdit(centralWidget);
        leNewFeed->setObjectName(QStringLiteral("leNewFeed"));

        verticalLayout->addWidget(leNewFeed);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbAdd = new QPushButton(centralWidget);
        pbAdd->setObjectName(QStringLiteral("pbAdd"));

        horizontalLayout_2->addWidget(pbAdd);

        pdRemove = new QPushButton(centralWidget);
        pdRemove->setObjectName(QStringLiteral("pdRemove"));

        horizontalLayout_2->addWidget(pdRemove);

        pbRefresh = new QPushButton(centralWidget);
        pbRefresh->setObjectName(QStringLiteral("pbRefresh"));

        horizontalLayout_2->addWidget(pbRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        lArticles = new QListWidget(centralWidget);
        lArticles->setObjectName(QStringLiteral("lArticles"));
        lArticles->setResizeMode(QListView::Adjust);

        verticalLayout_2->addWidget(lArticles);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        rssClass->setCentralWidget(centralWidget);

        retranslateUi(rssClass);
        QObject::connect(pbAdd, SIGNAL(clicked()), rssClass, SLOT(onAdd()));
        QObject::connect(pdRemove, SIGNAL(clicked()), rssClass, SLOT(onRemove()));
        QObject::connect(pbRefresh, SIGNAL(clicked()), rssClass, SLOT(onRefresh()));
        QObject::connect(lChannels, SIGNAL(itemClicked(QListWidgetItem*)), rssClass, SLOT(onChannelSelect(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(rssClass);
    } // setupUi

    void retranslateUi(QMainWindow *rssClass)
    {
        rssClass->setWindowTitle(QApplication::translate("rssClass", "rss", Q_NULLPTR));
        label_2->setText(QApplication::translate("rssClass", "Channels", Q_NULLPTR));
        label->setText(QApplication::translate("rssClass", "New RSS channel:", Q_NULLPTR));
        pbAdd->setText(QApplication::translate("rssClass", "+", Q_NULLPTR));
        pdRemove->setText(QApplication::translate("rssClass", "-", Q_NULLPTR));
        pbRefresh->setText(QApplication::translate("rssClass", "Refresh", Q_NULLPTR));
        label_3->setText(QApplication::translate("rssClass", "Articles", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rssClass: public Ui_rssClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSS_H
