#include <QCoreApplication>

/*
  What
  Iterator Pattern

  Description
  Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

  Why
  Make it easy to traverse a collection of objects

  Example
  Qt Containers - don't reinvent the wheel!
  https://sourcemaking.com/design_patterns/iterator

 */

#include <QDebug>

template <class T>
void fillContainer(T &container, int max)
{
    for(int i = 0; i < max; i++)
    {
       container.append(i);
    }
}

template <class T>
void fillSet(T &container, int max)
{
    for(int i = 0; i < max; i++)
    {
        container.insert(i);
    }
}

template <class T>
void fillPair(T &container, int max)
{
    for(int i = 0; i < max; i++)
    {
        container.insert(i,QString::number(i));
    }
}



template <class T>
void display(T value,QString message)
{
    qInfo() << message;
    //auto = T::iterator for example QVectorIterator::iterator
    for(auto i = value.begin(); i != value.end(); ++i)
    {
        qInfo() << *i;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    fillContainer<QList<int>>(list,5);

    QVector<int> vector;
    fillContainer<QVector<int>>(vector,5);

    QSet<int> set;
    fillSet<QSet<int>>(set,5);


    QHash<int,QString> hash;
    fillPair<QHash<int,QString>>(hash,5);

    QMap<int,QString> map;
    fillPair<QMap<int,QString>>(map,5);


    display<QList<int>>(list,"Displaying a list");
    display<QSet<int>>(set,"Displaying a set");
    display<QVector<int>>(vector,"Displaying a vector");
    display<QHash<int,QString>>(hash,"Displaying a hash");
    display<QMap<int,QString>>(map,"Displaying a map");

    return a.exec();
}
