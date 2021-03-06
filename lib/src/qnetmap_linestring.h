﻿/*
* This file is part of QNetMap,
* an open-source cross-platform map widget
*
* Copyright (c) 2011-2014 JSC Sintels (sintels.ru) and/or its affiliates.
* Copyright (c) 2012-2014 OJSC T8 (t8.ru) and/or its affiliates.
* Based on QMapControl LineString code by Kai Winter
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with QNetMap. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QNETMAP_LINESTRING_H
#define QNETMAP_LINESTRING_H

#include "qnetmap_global.h"
#include "qnetmap_geometry.h"
#include "qnetmap_point.h"

namespace qnetmap
{
   //! \class TLineString
   //! \brief A collection of TPoint objects to describe a line
   class QNETMAP_EXPORT TLineString : public TGeometry
   {
      //Q_OBJECT

   public:
      TLineString();
      explicit TLineString(const TPointList& points, const QString& name = QString(), QPen* pen = 0);
      virtual ~TLineString();

      //! returns the points of the TLineString
      /*!
      * @return  a list with the points of the TLineString
      */
      TPointList	points();

      //! adds a point at the end of the TLineString
      /*!
      * @param point the point which should be added to the TLineString
      */
      void addPoint(TPoint* point);

      //! sets the given list as points of the TLineString
      /*!
      * @param points the points which should be set for the TLineString
      */
      void setPoints(const TPointList& points);

      //! returns the number of Points the TLineString consists of
      /*!
      * @return the number of the TLineString?s Points
      */
      virtual int pointsCount() const;

      virtual QRectF boundingBoxF(const int Zoom_ = -1);

      // virtual TGeometry	Clone();
      // virtual TPoint EndPoint();
      // virtual TPoint StartPoint();
      // virtual TPoint Value();

      //! returns true if the TLineString has Childs
      /*!
      * This is equal to: numberOfPoints() > 0
      * @return true it the TLineString has Childs (=Points)
      * @see clickedPoints()
      */
      virtual bool hasPoints() const;
      //! \brief возвращает контур рисования (для проверки пересекаемости фигур)
      virtual QPainterPath painterPath(void) const;

   protected:
      virtual void drawGeometry(QPainter* painter, const QRect &screensize, const QPoint offset);

   private:
      Q_DISABLE_COPY(TLineString)

      TPointList m_Vertices;
   };
}
#endif
