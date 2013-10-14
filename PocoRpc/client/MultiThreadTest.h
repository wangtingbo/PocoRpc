/* 
 * File:   MultiThreadTest.h
 * Author: kk
 *
 * Created on 2013年10月11日, 下午9:49
 */

#ifndef MULTITHREADTEST_H
#define	MULTITHREADTEST_H

#include "PocoRpc/base/base.h"
#include "PocoRpc/base/runable.h"

#include <Poco/Thread.h>
#include <Poco/SharedPtr.h>

class MultiThreadTest {
 public:
  MultiThreadTest(int thread_count);
  virtual ~MultiThreadTest();
  
  void start();
  void stop();
  
 private:
  typedef Poco::SharedPtr<Poco::Thread> ThreadPtr;
  typedef std::vector<ThreadPtr> ThreadPtrVec;
  
  int thread_count_;
  bool exit_;
  scoped_ptr<ThreadPtrVec> thread_list_;
  scoped_ptr<Poco::Runnable> ra_test_;

  void test();
  
  DISALLOW_COPY_AND_ASSIGN(MultiThreadTest);
};

#endif	/* MULTITHREADTEST_H */
