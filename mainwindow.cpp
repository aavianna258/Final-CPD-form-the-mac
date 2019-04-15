#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "HashTable.h"
#include "TrieTree.h"
#include "showtext.h"
#include <cmath>

#include <iostream>
#include <fstream>
#include <cstdlib>

#define STR_NULL ""

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator *role = new QIntValidator(0,100000);
    ui->lineEdit->setValidator(role);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButton_clicked
 * Inserts the training file in to the hash table
 */
void MainWindow::on_pushButton_clicked()
{

    QString file_path = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../",
                "Text files (*.txt)"
                );
    QMessageBox::information(this, tr("File Name"), file_path);

    if(file_path != STR_NULL){
        std::string path = file_path.toUtf8().constData();
        string line;
        int score;
        int phrase_id = 0;

        ifstream myfile (path);
        if (myfile.fail() )
        {
            cout << "could not open file" <<endl;
            exit(0);
        }

        // create new hash, trie, table_of_phrases
        table = new HashTable(20000);
        trie = new Trie();
        phrases = new PhraseTable();

        while (! myfile.eof() )
        {

            // there the main file is entered
            myfile >> score;  //get score
            myfile.get();    // get blank space

            // reads the line
            getline(myfile,line);
            phrases->add_phrase(line);

            int len = line.size();
            while(len >0) {  //identify all individual strings
                string sub;
                len = line.find(" ");
                if (len > 0)
                {
                    sub = line.substr(0,len);
                    line = line.substr(len+1,line.size());
                }
                else {
                    sub = line.substr(0,line.size()-1);
                }
                table->puts(sub, score,phrase_id); //insert string with the score and phrase id
                trie->addWord(sub);
            }

            phrase_id++;
        }
        myfile.close();
        sortedLists = new Lists(table);
    }


}

/**
 * @brief MainWindow::on_pushButton_search_clicked
 * Searches for the words that have the informed prefix. Once the words are found they are added to the List
 */
void MainWindow::on_pushButton_search_clicked()
{
    // clear the list
    ui->listOut->clear();
    QString prefix = ui->textPrefix->toPlainText();
    if(prefix != STR_NULL && table != nullptr){
        // gets the tiped prefix
        std::string std_prefix = prefix.toUtf8().constData();
        // transforms it to upper case
        transform(std_prefix.begin(), std_prefix.end(),std_prefix.begin(), ::toupper);
        // searches for the words related to the entered prefix
        vector<string> words = trie->searchPrefix(std_prefix);
        if(!words.empty()){
            QList<QString> words_Qlist;
            for(int i=0; i < (int) words.size(); i++){
                words_Qlist.append(QString::fromUtf8(words[i].c_str()));
            }
            // error
            ui->listOut->addItems(words_Qlist);
        }else{
            QString error;
            error = "Prefix does not match any word";
            QMessageBox::information(this, tr("Error: "), error);
        }

    }
    else{
        QString error;
        if(table)
            error = "Please, enter a prefix before clicking on this button";
        else
            error = "The training wasn't properly loaded";

        QMessageBox::information(this, tr("Error: "), error);
    }
}

/**
 * @brief MainWindow::on_listOut_itemDoubleClicked
 * @param item
 * Once the item from the List of words (searched by prefix) is double cicked,
 * A dialog box appers with the word's information (grabed from the hash table).
 */
void MainWindow::on_listOut_itemDoubleClicked(QListWidgetItem *item)
{
    item->setBackgroundColor(Qt::red);
    string item_string = item->text().toUtf8().constData();

    WordEntry* entry = table->finds(item_string);

    string show = "WordInfo: " + item_string +"\n--\nAppearences: " + to_string(entry->getAppearences()) +
                    "\nAverage: " + to_string(entry->getAverage());

    QString out = QString::fromUtf8(show.c_str());
    QMessageBox::information(this, tr("Entry info: "), out);



}

/**
 * @brief MainWindow::on_pushButton_2_clicked
 * Function that gets a review and puts in a label its score.
 */
void MainWindow::on_pushButton_2_clicked()
{

    QString qreview = ui->plainText_review->toPlainText();
    if( table != nullptr && qreview!=STR_NULL){

        stop_words = new StopWords();

        std::string message = qreview.toUtf8().constData();
        transform(message.begin(), message.end(),message.begin(), ::toupper);

        //used for calculating the average
        double sum = 0;
        int count = 0;
        double score = 0;
        vector<string> stp_words;

        stp_words = stop_words->getWords();

        for(int o=0; o<stp_words.size(); o++){
            cout << stp_words[o] << endl;
        }

        if(stop_words->inArray("A")){
            cout << "Ta no array! " << endl;
        }

        int len = message.size();
        //get each individual word from the input
        while(len != (int) std::string::npos)
        {
            string sub;
            len = message.find(" ");
            if (len != (int) string::npos)
            {
                sub = message.substr(0,len);
                message = message.substr(len+1,message.size());
            }
            else {
                sub = message;
            }
            //calculate the score of each word

            // FILTRA STOP WORDS
            if(!stop_words->inArray(sub)){
                sum += table->getAverage(sub);
                count++;
            }

        }
        score = sum/count;

        ui->label_score->setNum(score);
        if(score < 2.0){
            ui->label_score->setStyleSheet("QLabel { background-color : red; color : black; }");
        }else if(score >= 2 && score < 3.5){
            ui->label_score->setStyleSheet("QLabel { background-color : yellow; color : black; }");

        }else{
            ui->label_score->setStyleSheet("QLabel { background-color : green; color : black; }");
        }
    }else{
        QString error;
        if(table)
            error = "Please, enter a review before clicking on this button";
        else
            error = "The training wasn't properly loaded";


        QMessageBox::information(this, tr("Error: "), error);
    }

}


/**
 * @brief MainWindow::on_button_searchPhrases_clicked
 * Search for all the frases with the given word
 * The phrases are added to the list in the ui
 */
void MainWindow::on_button_searchPhrases_clicked()
{
    ui->listWidget->clear();
    QString text = ui->text_searchPhrases->toPlainText();
    if(text != STR_NULL && table != nullptr){
        string word = text.toUtf8().constData();
        transform(word.begin(), word.end(),word.begin(), ::toupper);

        // Gets the entry in the hash table
        WordEntry* entry = table->finds(word);
        vector<string> matches = entry->getPhrases(phrases);


        if(!matches.empty()){
            // if there are returned phrases
            QList<QString> words_Qlist;
            for(int i=0; i < (int) matches.size(); i++){
                words_Qlist.append(QString::fromUtf8(matches[i].c_str()));
            }

            ui->listWidget->addItems(words_Qlist);

        }else{
            QString error;
            error = "Prefix does not match any word";
            QMessageBox::information(this, tr("Error: "), error);
        }


    }else{
        QString error;
        if(table == nullptr)
            error = "Please, load a training file before clicking on this button";
        else
            error = "Please, don't leave the word field in blank";

        QMessageBox::information(this, tr("Error: "), error);
    }

}

/**
 * @brief MainWindow::on_listWidget_itemDoubleClicked
 * @param item
 * UNDER CONSTRUCTION
 */
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ShowText nextForm;
    nextForm.setText("Abacate doce");
    nextForm.setModal(true);
    nextForm.setText(item->text());
    nextForm.exec();
}

void MainWindow::on_pushButton_KBestW_clicked()
{


    QString qnum = ui->lineEdit->text();
    if( this->table  != nullptr && qnum!=STR_NULL){
        ui->listOut->clear();
        std::string num_s = qnum.toUtf8().constData();
        int num = stoi(num_s);

        vector<WordEntry> entries = sortedLists->getBestWords(num);



        if(!entries.empty()){

            QList<QString> words_Qlist;
            for(int i=0; i < (int) entries.size(); i++){
                words_Qlist.append(QString::fromUtf8(entries[i].getWord().c_str()));
            }

            ui->listOut->addItems(words_Qlist);

        }else{
            QString error;
            error = "Error!";
            QMessageBox::information(this, tr("Error: "), error);
        }





    }else{
        QString error;
        if(table)
            error = "Please, inform a number before clicking on this button";
        else
            error = "The training wasn't properly loaded";
        QMessageBox::information(this, tr("Error: "), error);
    }
}



void MainWindow::on_pushButton_KworstW_clicked()
{

    QString qnum = ui->lineEdit->text();
    if( this->table  != nullptr && qnum!=STR_NULL){
        ui->listOut->clear();
        std::string num_s = qnum.toUtf8().constData();
        int num = stoi(num_s);

        vector<WordEntry> entries = sortedLists->getWorstWords(num);



        if(!entries.empty()){

            QList<QString> words_Qlist;
            for(int i=0; i < (int) entries.size(); i++){
                words_Qlist.append(QString::fromUtf8(entries[i].getWord().c_str()));
            }

            ui->listOut->addItems(words_Qlist);

        }else{
            QString error;
            error = "Error!";
            QMessageBox::information(this, tr("Error: "), error);
        }





    }else{
        QString error;
        if(table)
            error = "Please, inform a number before clicking on this button";
        else
            error = "The training wasn't properly loaded";
        QMessageBox::information(this, tr("Error: "), error);
    }
}

void MainWindow::on_pushButton_KmfreqW_clicked()
{
    QString qnum = ui->lineEdit->text();
    if( this->table != nullptr && qnum!=STR_NULL){
        ui->listOut->clear();
        std::string num_s = qnum.toUtf8().constData();
        int num = stoi(num_s);

        vector<WordEntry> entries = sortedLists->getFreqWords(num);



        if(!entries.empty()){

            QList<QString> words_Qlist;
            for(int i=0; i < (int) entries.size(); i++){
                words_Qlist.append(QString::fromUtf8(entries[i].getWord().c_str()));
            }

            ui->listOut->addItems(words_Qlist);

        }else{
            QString error;
            error = "Error!";
            QMessageBox::information(this, tr("Error: "), error);
        }





    }else{
        QString error;
        if(table)
            error = "Please, inform a number before clicking on this button";
        else
            error = "The training wasn't properly loaded";
        QMessageBox::information(this, tr("Error: "), error);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../",
                "Text files (*.tsv)"
                );
    QMessageBox::information(this, tr("File Name"), file_path);

    if(file_path != STR_NULL){
        std::string path = file_path.toUtf8().constData();
        string line;
        int score;
        string comment = " ";
        int phrase_id;
        int sent_id;

        ifstream myfile (path);
        if (myfile.fail() )
        {
            cout << "could not open file" <<endl;
            exit(0);
        }


        //open output file
        ofstream outfile ("out.csv");
        if (outfile.fail())
        {
            cout << "could not open output file" <<endl;
            exit(0);
        }


        //read and discard first line(header) from test.csv
        getline(myfile, line);

        //write header on out.csv
        outfile << "PhraseId,Sentiment\n";
        while (! myfile.eof() )
        {

            //read input's PhraseID
            myfile >> phrase_id;

            //read and discard "\t%d\t" from test.csv
            myfile >> sent_id;
            //read comment from test.csv
            getline(myfile, comment);

            //used for calculating the average
            double sum = 0;
            int count = 0;
            int len = comment.size();

            //get each individual word from the input
            while(len != std::string::npos)
            {
                string sub;
                len = comment.find(" ");
                if (len != string::npos)
                {
                    sub = comment.substr(0,len);
                    comment = comment.substr(len+1,comment.size());
                }
                else
                {
                    sub = comment;
                }
                //calculate the score of each word
                //linha que deve ser usada de verdade

                transform(sub.begin(), sub.end(),sub.begin(), ::toupper);


                // FILTRA STOP WORDS


                if(!stop_words->inArray(sub)){
                    sum += table->getAverage(sub);
                    count++;
                }




            }
            //write "PhraseID,score\n" on out.csv
            if(!myfile.eof())
                outfile << phrase_id << "," << (int) round(sum/count) << endl;
        }


        outfile.close();
        myfile.close();
    }
}
