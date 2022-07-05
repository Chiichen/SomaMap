#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QObject>

class WorkerThread:public QObject
{
    Q_OBJECT
public:
    WorkerThread();
};

#endif // WORKERTHREAD_H
