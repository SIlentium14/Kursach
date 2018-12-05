#ifndef FORM_H
#define FORM_H
#include <QTableView>
#include <QTableWidget>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QTextEdit>
#include <vector>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
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

private:
    void box_checker();
    void add_box();
    QGroupBox *stand_box;
    Ui::Form *ui;
    int column_count=0;
    int row_count=0;
};

#endif // FORM_H
