#ifndef EDIT_MASTER_H
#define EDIT_MASTER_H

#include <QDialog>
#include "title.h"
#include <QFile>
#include <QFileDialog>
namespace Ui {
class Edit_Master;
}

class Edit_Master : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Master(Title *worker,QWidget *parent = nullptr);
    ~Edit_Master();
void clearing_master();

signals:
    void signal();
    void cancel_signal();
private slots:
    void on_Ok_clicked();

    void on_Cancel_clicked();

    void on_image_clicked();

private:
    Ui::Edit_Master *ui;
    Title* work_;
};

#endif // EDIT_MASTER_H
