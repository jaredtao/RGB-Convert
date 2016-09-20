#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QScreen>
#include <QApplication>
#include <QTImer>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	setWindowFlags(Qt::FramelessWindowHint);
	ui->setupUi(this);
	getRgb();
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
	QString rgb = ui->lineEdit_hex->text().trimmed();
	QColor color(rgb);
	QPixmap pix(ui->label_outImg2->width(), ui->label_outImg2->height());
	pix.fill(color);
	ui->label_outImg2->setPixmap(pix);
	ui->lineEdit_outHex2->setText(QString("%1, %2, %3").arg(color.red()).arg(color.green()).arg(color.blue()));
}

void MainWindow::getRgb()
{
	QSize size = ui->label_mouseColor->size();
	QPixmap pixmap = qApp->primaryScreen()->grabWindow(qApp->desktop()->winId(), QCursor::pos().x(), QCursor::pos().y(), size.width(), size.height());
	ui->label_mouseColor->setPixmap(pixmap);


	QTimer::singleShot(100, this, SLOT(getRgb()));
}

void MainWindow::on_pushButton_colorDialog_clicked()
{
	QColor color = QColorDialog::getColor(Qt::white, this);

}
