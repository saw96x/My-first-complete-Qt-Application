#include "textfinder.h"
#include "ui_textfinder.h"
#include<QFile>
#include<QTextStream>
TextFinder::TextFinder(QWidget* parent)
    : QWidget(parent), ui(new Ui::TextFinder) {
    ui->setupUi(this);
    LocateTheText();
}

TextFinder::~TextFinder() {
    delete ui;
}


void TextFinder::on_pushButton_clicked() {
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}
void TextFinder::LocateTheText() {
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();
    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
