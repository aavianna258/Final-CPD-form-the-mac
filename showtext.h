#ifndef SHOWTEXT_H
#define SHOWTEXT_H

#include <QDialog>
#include <string>

namespace Ui {
class ShowText;
}

class ShowText : public QDialog
{
    Q_OBJECT

public:
    explicit ShowText(QWidget *parent = 0);
    ~ShowText();
    QString getText();
    void setText(QString s);

private:
    Ui::ShowText *ui;
    QString text;

};

#endif // SHOWTEXT_H
