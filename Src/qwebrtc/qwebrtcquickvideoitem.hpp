#pragma once

#include "qwebrtc_global.h"
#include <QQuickPaintedItem>

class QWebRTCMediaTrack;
class QWebRTCQuickVideoItem_p;
class QWEBRTCSHARED_EXPORT QWebRTCQuickVideoItem: public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QObject* videoTrack READ videoTrack WRITE setVideoTrack NOTIFY videoTrackChanged)
    Q_PROPERTY(QSize sourceSize READ sourceSize NOTIFY sourceSizeChanged)
public:
    explicit QWebRTCQuickVideoItem(QQuickItem *parent = Q_NULLPTR);
    ~QWebRTCQuickVideoItem();

    QObject* videoTrack();
    void setVideoTrack(QObject*);

    virtual QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *) override;
    //virtual void paint(QPainter *painter) override;

    QSize sourceSize();

public Q_SLOTS:
    void asyncUpdate();

Q_SIGNALS:
    void videoTrackChanged();
    void sourceSizeChanged();

private:
    QWebRTCQuickVideoItem_p* m_impl;
};
