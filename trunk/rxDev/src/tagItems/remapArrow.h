/****************************************************************************
**
** Original Code:
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

#include "nodeItem.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE

//Datastructure
class remapArrowData {
public:
    QPointF startNode;
    QPointF endNode;
    QString from;
    QString to;
    QString ifString;
    QString unlessString;
};
//! [0]
class RemapArrow : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 14 };

    RemapArrow(NodeItem *startItem, NodeItem *endItem,
      QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    QGraphicsTextItem title;
    QGraphicsTextItem incl;
    int type() const
        { return Type; }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void setColor(const QColor &color)
        { myColor = color; }
    NodeItem *startItem() const
        { return myStartItem; }
    NodeItem *endItem() const
        { return myEndItem; }
    bool getArrowData();

public slots:
    void updatePosition();
    void setFrom(QString newFrom);
    void setTo(QString newTo);
    QString getFrom();
    QString getTo();
    QString getIf();
    void setIf(QString newIf);
    QString getUnless();
    void setUnless(QString newUnless);


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event );


private:
    bool _subToPub;
    NodeItem *myStartItem;
    NodeItem *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
    QPoint textPos;
    QString _fromString;
    QString _toString;
    QString _ifString;
    QString _unlessString;
};
//! [0]

#endif
