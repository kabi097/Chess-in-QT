#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <QLabel>
#include <QDebug>
#include "chesspiece.h"

class chessSquare : public QLabel
{
    Q_OBJECT
public:
    chessSquare(int col, int row, QWidget *parent=nullptr);
    void setActive(bool active);        //Ustawia pole jako aktywne (w zależności od wartości active)
    void setActive(QString color);      //Ustawia pole jako aktywne i dodatkowo ustawia tymczasowy kolor tła
    bool isPiece();                     //Funkcja sprawdzająca czy na danym polu znajduje się figura
    chessPiece* getPiece();             //Zwraca figurę z danego pola
    void setPiece(chessPiece* piece);   //Ustawia figurę na polu
    void removePiece();                 //Usuwa figurę z pola
    void setBackgroundColor(QString color); //Ustawia nowy domyślny kolor tła
    QString toChessNotation();          //Zwraca współrzędne w zapisane w notacji szachowej
    ~chessSquare();

signals:
    void clicked(int x, int y);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    void setColor(int color);           //Ustawia tymczasowy kolor na szachownicy (0 - biały, 1 - czarny)
    bool active;
    QString backgroundColor;
    int color;
    int column;
    int row;
    chessPiece* chesspiece;

};

#endif // CHESSSQUARE_H
