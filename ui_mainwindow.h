/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_reviews;
    QAction *actionExport_Analysis;
    QWidget *centralWidget;
    QListWidget *listOut;
    QPushButton *pushButton_search;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_5;
    QLabel *label_score;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QPlainTextEdit *plainText_review;
    QPushButton *pushButton_2;
    QFrame *line_4;
    QTextEdit *text_searchPhrases;
    QCommandLinkButton *button_searchPhrases;
    QLabel *label_6;
    QListWidget *listWidget;
    QTextEdit *textPrefix;
    QLabel *label;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_KBestW;
    QPushButton *pushButton_KworstW;
    QPushButton *pushButton_KmfreqW;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(946, 700);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionImport_reviews = new QAction(MainWindow);
        actionImport_reviews->setObjectName(QStringLiteral("actionImport_reviews"));
        actionExport_Analysis = new QAction(MainWindow);
        actionExport_Analysis->setObjectName(QStringLiteral("actionExport_Analysis"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listOut = new QListWidget(centralWidget);
        listOut->setObjectName(QStringLiteral("listOut"));
        listOut->setGeometry(QRect(550, 70, 191, 261));
        pushButton_search = new QPushButton(centralWidget);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setGeometry(QRect(450, 80, 81, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(550, 20, 63, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 20, 101, 51));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setLineWidth(2);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 60, 271, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(760, 40, 20, 281));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(300, 80, 20, 231));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 310, 63, 20));
        label_score = new QLabel(centralWidget);
        label_score->setObjectName(QStringLiteral("label_score"));
        label_score->setGeometry(QRect(80, 310, 31, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 258, 220));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        plainText_review = new QPlainTextEdit(layoutWidget);
        plainText_review->setObjectName(QStringLiteral("plainText_review"));
        plainText_review->setMaximumSize(QSize(16777215, 8777215));

        verticalLayout->addWidget(plainText_review);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(30, 330, 761, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        text_searchPhrases = new QTextEdit(centralWidget);
        text_searchPhrases->setObjectName(QStringLiteral("text_searchPhrases"));
        text_searchPhrases->setGeometry(QRect(30, 390, 101, 31));
        button_searchPhrases = new QCommandLinkButton(centralWidget);
        button_searchPhrases->setObjectName(QStringLiteral("button_searchPhrases"));
        button_searchPhrases->setGeometry(QRect(130, 390, 111, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 350, 191, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Narrow"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(250, 340, 531, 181));
        textPrefix = new QTextEdit(centralWidget);
        textPrefix->setObjectName(QStringLiteral("textPrefix"));
        textPrefix->setGeometry(QRect(330, 80, 111, 31));
        textPrefix->setFocusPolicy(Qt::ClickFocus);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 40, 125, 39));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(330, 120, 31, 39));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(370, 190, 148, 132));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_KBestW = new QPushButton(layoutWidget1);
        pushButton_KBestW->setObjectName(QStringLiteral("pushButton_KBestW"));

        verticalLayout_2->addWidget(pushButton_KBestW);

        pushButton_KworstW = new QPushButton(layoutWidget1);
        pushButton_KworstW->setObjectName(QStringLiteral("pushButton_KworstW"));

        verticalLayout_2->addWidget(pushButton_KworstW);

        pushButton_KmfreqW = new QPushButton(layoutWidget1);
        pushButton_KmfreqW->setObjectName(QStringLiteral("pushButton_KmfreqW"));

        verticalLayout_2->addWidget(pushButton_KmfreqW);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 150, 113, 28));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(780, 20, 159, 98));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        pushButton->setFont(font2);
        pushButton->setMouseTracking(true);
        QIcon icon;
        QString iconThemeName = QStringLiteral("folder");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon);
        pushButton->setFlat(true);

        verticalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 946, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionImport_reviews);
        menuFile->addAction(actionExport_Analysis);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CPD - Final Work", Q_NULLPTR));
        actionImport_reviews->setText(QApplication::translate("MainWindow", "Import reviews", Q_NULLPTR));
        actionExport_Analysis->setText(QApplication::translate("MainWindow", "Export Analysis", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Results:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Tasks", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Score: ", Q_NULLPTR));
        label_score->setText(QApplication::translate("MainWindow", "n/a", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Review", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Analyze", Q_NULLPTR));
        button_searchPhrases->setText(QApplication::translate("MainWindow", "Show phrases", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Search phrases by word", Q_NULLPTR));
        textPrefix->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Prefix", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "K:", Q_NULLPTR));
        pushButton_KBestW->setText(QApplication::translate("MainWindow", "k-best", Q_NULLPTR));
        pushButton_KworstW->setText(QApplication::translate("MainWindow", "k-worst", Q_NULLPTR));
        pushButton_KmfreqW->setText(QApplication::translate("MainWindow", "k-freq", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Open training file...", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "run kaggle test", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
