/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _dbookmarkspopup_h_
#define _dbookmarkspopup_h_

#include <QUrl>

#include "ui_bookmarksPopup.h"

class dbookmarkspopup: public QWidget
{
  Q_OBJECT

 public:
  dbookmarkspopup(void);
  ~dbookmarkspopup();
  void populate(const QUrl &url);

 private:
  QUrl m_url;
  QString m_title;
  Ui_bookmarksPopup ui;
  qint64 m_folderOid;
  void updateBookmark(void);

 public slots:
  void slotSetIcons(void);

 private slots:
  void slotAddFolder(void);
  void slotTitleChanged(void);
  void slotDeleteBookmark(void);
  void slotFolderSelected(const QModelIndex &index);
  void slotFolderDataChanged
    (const QModelIndex &topLeft, const QModelIndex &bottomRight);
  void slotDescriptionChanged(void);

 signals:
  void closed(void);
  void changed(void);
  void iconsChanged(void);
};

#endif
