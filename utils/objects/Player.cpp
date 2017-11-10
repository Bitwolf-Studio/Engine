#include "Player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    }

    if (event->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if (event->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
}

Player::Player()
{
    this->setRect(0, 0, 100, 100);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}
