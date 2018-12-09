#ifndef FORM_H
#define FORM_H
#include <QTableView>
#include <QTableWidget>
#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <vector>
#include <QScrollArea>
#include <QListView>
#include <QListWidget>
#include "one_element.h"
using namespace std;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void signal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void element_clicked();
private:
    void box_checker();
    void add_box();
    QGroupBox *box_;
    Ui::Form *ui;
    int column_count=0;
    int row_count=0;
    vector<Title> all_;
};

#endif // FORM_H
