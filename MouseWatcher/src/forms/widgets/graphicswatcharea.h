#ifndef GRAPHICSWATCHAREA_H
#define GRAPHICSWATCHAREA_H


#include <QGraphicsView>

class GraphicsWatchArea : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphicsWatchArea(QWidget *parent = nullptr);
    GraphicsWatchArea(QGraphicsScene *scene, QWidget *parent);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *e);

public slots:

signals:
    void MouseClickedAt(int X, int Y);
    void MouseClickedAt(QMouseEvent* event);
    void MouseNowAt(int X, int Y);

};

#endif // GRAPHICSWATCHAREA_H
