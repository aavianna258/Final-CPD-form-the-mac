#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <HashTable.h>
#include <TrieTree.h>
#include <phrasetable.h>
#include <QIntValidator>
#include <QListWidget>
#include <Qt>
#include <lists.h>
#include <stopwords.h>
#include <iomanip>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_search_clicked();
    void on_listOut_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_2_clicked();
    void on_button_searchPhrases_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_KBestW_clicked();

    void on_pushButton_KworstW_clicked();

    void on_pushButton_KmfreqW_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
    HashTable* table;
    Trie* trie;
    PhraseTable* phrases;
    Lists* sortedLists;
    StopWords* stop_words;


};

#endif // MAINWINDOW_H
