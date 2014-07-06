#include <QtConcurrentMap>
#include <QStringList>
#include <QCoreApplication>
#include <functional>

#include "ConcurrentMap.h"

namespace
{
  struct UpcaseString : public std::unary_function<const QString&,void>
  {
    void operator()(QString & str)
      {
        str = str.toUpper();
     }
  };
}


void RunConcurrentMapExample()
{
  QStringList strings;
  strings << "foo" <<  "bar" <<  "baz";

  QFuture<void> res = QtConcurrent::map(strings,UpcaseString());
  res.waitForFinished();

  for(QStringList::iterator i = strings.begin(); i != strings.end(); ++i)
	qDebug("%s",qPrintable(*i));
}
