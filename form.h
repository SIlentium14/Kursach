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
#include <QFileDialog>
#include <QFile>
#include "one_element.h"
#include <algorithm>
using namespace std;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(bool root = false,QWidget *parent = nullptr);

    ~Form();

    void add_master();

    void redrawind();

    void Layout_clearer();
signals:
    void signal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void element_clicked();

    void image_clicked(Title*);
    void on_pushButton_3_clicked();

    void deleting_signal_action();

    void on_pushButton_5_clicked();

private:
    QFile* data;
    QFile* data_picture;
    void box_checker();
    void add_box();
    QGroupBox *box_;
    Ui::Form *ui;
    int column_count=0;
    int row_count=0;
    vector<Title> all_;
    bool is_admin_;
};

#endif // FORM_H
