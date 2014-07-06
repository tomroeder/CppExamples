#include <iostream>
#include <functional>

#include <QImage>
#include <QPainter>
#include <QFuture>
#include <QtCore>

#include <QList>
#include <QDir>
#include <QStringList>

#include "MapReduce2.h"

using namespace std;

void LoadImages(QList<QImage> & imageList)
{
	QDir dir("/tmp");

	QStringList nameFilters;
	nameFilters << "*.png" << "*.jpg";

	QStringList files = dir.entryList(nameFilters);

    for (int i = 0; i < files.size(); ++i)
    {
         //cout << files.at(i).toLocal8Bit().constData() << endl;
         QImage image;
         if (image.load(files.at(i)) )
         {
        	 imageList.append(image);
         }
    }
}

void addToCollage(QImage &collage, const QImage &thumbnail)
{
	QPainter p(&collage);
	static QPoint offset = QPoint(0, 0);
	p.drawImage(offset, thumbnail);
	offset += QPoint(10,10);//10 is todo...;
}

QImage scaled(const QImage &image)
{
    return image.scaled(100, 100);
}

void RunMapReduceExample2()
{
	QList<QImage> images;
	LoadImages(images);
	for(unsigned i=0; i<1000000; i++)
	{
		QFuture<QImage> collage = QtConcurrent::mappedReduced(images, scaled, addToCollage);
	}

	//std::bind(&QImage::scaledToWidth, 100, Qt::SmoothTransformation);

	//QFuture<QImage> thumbnails = QtConcurrent::mapped(images, std::bind(&QImage::scaledToWidth, 100, Qt::SmoothTransformation) );
}

