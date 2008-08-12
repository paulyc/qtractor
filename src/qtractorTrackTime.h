// qtractorTrackTime.h
//
/****************************************************************************
   Copyright (C) 2005-2008, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*****************************************************************************/

#ifndef __qtractorTrackTime_h
#define __qtractorTrackTime_h

#include "qtractorScrollView.h"

#include <QPixmap>


// Forward declarations.
class qtractorTracks;

class QResizeEvent;
class QMouseEvent;
class QKeyEvent;


//----------------------------------------------------------------------------
// qtractorTrackTime -- Track time scale widget.

class qtractorTrackTime : public qtractorScrollView
{
	Q_OBJECT

public:

	// Constructor.
	qtractorTrackTime(qtractorTracks *pTracks, QWidget *pParent = 0);
	// Destructor.
	~qtractorTrackTime();

	// Rectangular contents update.
	void updateContents(const QRect& rect);
	// Overall contents update.
	void updateContents();

protected:

	// Resize event handler.
	void resizeEvent(QResizeEvent *pResizeEvent);

	// Draw the time scale.
	void drawContents(QPainter *pPainter, const QRect& rect);

	// Check if some position header is to be dragged...
	bool dragHeadStart(const QPoint& pos);

	// Handle selection with mouse.
	void mousePressEvent(QMouseEvent *pMouseEvent);
	void mouseMoveEvent(QMouseEvent *pMouseEvent);
	void mouseReleaseEvent(QMouseEvent *pMouseEvent);

	// Reset drag/select state.
	void resetDragState();

	// Keyboard event handler.
	void keyPressEvent(QKeyEvent *pKeyEvent);

	// Context menu request slot (dummy).
	void contextMenuEvent(QContextMenuEvent *);

protected slots:

	// To have timeline in h-sync with main track view.
	void contentsXMovingSlot(int cx, int cy);

	// (Re)create the time scale pixmap.
	void updatePixmap(int cx, int cy);

private:

	// The logical parent binding.
	qtractorTracks *m_pTracks;

	// Local double-buffering pixmap.
	QPixmap m_pixmap;

	// The current selecting/dragging head stuff.
	enum DragState {
		DragNone = 0, DragStart, DragSelect,
		DragPlayHead, DragEditHead, DragEditTail,
		DragLoopStart, DragLoopEnd
	} m_dragState, m_dragCursor;

	QRect  m_rectDrag;
	QPoint m_posDrag;
};


#endif  // __qtractorTrackTime_h


// end of qtractorTrackTime.h
