#include "chesssquare.h"

chessSquare::chessSquare(int col, int row, QWidget *parent) : QLabel(parent)
{
    //setFixedSize(50,50);
    setMinimumSize(64,64);
    setScaledContents(true);

    this->column = col;
    this->row = row;
    chesspiece = nullptr;
    active = false;
    setStatusTip(this->toChessNotation());

    //Ustawiamy domyślny kolor
    if (col%2==0) {
        if (row%2==0) {
           setColor(1);
           backgroundColor = "grey";
        } else {
           setColor(0);
           backgroundColor = "white";
        }
    } else {
        if (row%2==0) {
           setColor(0);
           backgroundColor = "white";
        } else {
           setColor(1);
           backgroundColor = "grey";
        }
    }
}

void chessSquare::setActive(bool active)
{
    this->active = active;
    setStyleSheet("QLabel { background-color : " + backgroundColor + "; }");
}

void chessSquare::setActive(QString color)
{
    this->active = true;
    setStyleSheet("QLabel { background-color : " + color + "; }");
}

bool chessSquare::isPiece()
{
    if (chesspiece!=nullptr) {
        return true;
    } else {
        return false;
    }
}

chessPiece* chessSquare::getPiece()
{
    return chesspiece;
}

void chessSquare::setPiece(chessPiece *piece)
{
    this->chesspiece = piece;
    setPixmap(chesspiece->getImage());
    setStatusTip(this->toChessNotation() + " - " + chesspiece->getName());
}

void chessSquare::removePiece()
{
    chesspiece = nullptr;
    QPixmap empty(0,0);
    setPixmap(empty);
    setStatusTip(this->toChessNotation());
}

void chessSquare::setBackgroundColor(QString color)
{
    backgroundColor = color;
    setStyleSheet("QLabel { background-color : " + color + "; }");
}

QString chessSquare::toChessNotation()
{
    QString coordinates;
    char x = column + 49;
    char y = row + 65;
    if (column>=0 && column<8 && row>=0 && row<8) {
        coordinates.append(x);
        coordinates.append(y);
    }
    return coordinates;
}

void chessSquare::mousePressEvent(QMouseEvent* event) {
    if (active==true) {
        emit clicked(column, row);
    }
}

void chessSquare::setColor(int color)
{
    switch (color) {
    case 0:
        setStyleSheet("QLabel { background-color : white; }");
        break;
    case 1:
        setStyleSheet("QLabel { background-color : grey; }");
        break;
    default:
        throw QString("Incorrect chess square color");
        break;
    }
    this->color = color;
}

chessSquare::~chessSquare()
{
    //qDebug() << "Chess square " << column << row << " deleted.";
}
