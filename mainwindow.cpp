#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	this->setWindowTitle("Converter");
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_convToHex_clicked()
{
	int r = ui->lineEdit_r->text().trimmed().toInt();
	int g = ui->lineEdit_g->text().trimmed().toInt();
	int b = ui->lineEdit_b->text().trimmed().toInt();
	QString str;
	str.sprintf("#%02x%02x%02x", r, g, b);
	ui->lineEdit_outHex1->setText(str);

	QPixmap pix(ui->label_outImg1->width(), ui->label_outImg1->height());
	pix.fill(QColor(r, g, b));
	ui->label_outImg1->setPixmap(pix);

}

void MainWindow::on_pushButton_convTorgb_clicked()
{
//	QString rgb = ui->lineEdit_hex->text().trimmed();

//	QString str;
//	str.sprintf("%02d, %02d, %02d", str);
}
