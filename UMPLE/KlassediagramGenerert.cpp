//%% NEW FILE Jury.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__JURY_H
#define DEF__JURY_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Jury.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Jury.h>
#include <User.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class User;
class Statistics;
// line 22 "model.ump"
// line 58 "model.ump"
class Jury : public User{
	
	private:
		
		//Jury Associations
		// line 33 "model.ump"
		Statistics* statistics;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Jury(const string aId, Stand* aStand, Statistics* aStatistics);
		Jury(Jury& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Jury& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Jury& Right, Jury& Left);
		friend bool operator != (Jury& Right, Jury& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Jury& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Jury& Right) const{
		  return this != &Right;  
		}
		Jury& operator=(Jury& other);
		
		void internalCopy(Jury& other);
		bool setStatistic(Statistics* aNewStatistic);
		inline unsigned int minimumNumberOfStatistics(void){
		  return 1;  
		}
		// line 0 ""
		Statistics* getStatistics();
		// line 0 ""
		bool setStatistics(Statistic aStatistics) const;
		Statistics* getStatistic(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Jury();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
using namespace __gnu_cxx;
namespace __gnu_cxx{
  template<> struct hash<Jury*>{
    size_t operator()(Jury* ptr ) const {
        return ptr->hashCode();
    }
  };
}
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#endif



//%% NEW FILE model_Main.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#include <Stand.h>
#include <Vote.h>
#include <User.h>
#include <Jury.h>
#include <Statistics.h>
int main(int argc, char *argv[]){
	
  return 0;
}




//%% NEW FILE model_Model.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__
#define DEF__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
#define WINDOWS_OS
// NO PREPROCESSOR DEFINITION FOR PRAGMA
#if _MSC_VER
#define PRAGMA
#pragma warning( disable : 4290 )
#endif
#elif defined(hpux) || defined(__hpux) || defined(__hpux__)
#define HPUX_OS
#elif defined(__APPLE__) || defined(macintosh)
#define MAC_OS
#elif defined(bsdi) || defined(__bsdi__)
#define BSD_OS
#endif

#ifdef PRAGMA
#pragma once
#ifdef _MSC_VER
#pragma include_alias("..\\model_Model.h", "model_Model.h")
#pragma include_alias(".\\Stand.h", "/Stand.h")
#pragma include_alias(".\\Vote.h", "/Vote.h")
#pragma include_alias(".\\User.h", "/User.h")
#pragma include_alias(".\\Jury.h", "/Jury.h")
#pragma include_alias(".\\Statistics.h", "/Statistics.h")
#else
#pragma interface "model_Model.h"
#endif
#endif

//------------------------
// PACKAGE FILES DECLARATION
//------------------------
#include <sstream>
#include <cmath>
  
#ifdef WINDOWS_OS
#include <windows.h>
#include <process.h>
#else
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <cstring>
#include <signal.h>
#endif

#ifdef HPUX_OS
#include <sys/pstat.h>
#elif defined MAC_OS
#undef DEBUG
#include <CoreServices/CoreServices.h>
#elif defined BSD_OS
#include <mach/mach_types.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
//------------------------
//USED LIBRARIES
//------------------------
using namespace std;

//------------------------
//USED LIBRARIES
//------------------------
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <iostream>
#include <queue>
#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>
#include <cassert>
#include "stdio.h"

//------------------------------
//NAMESPACES AND PREDEFINITIONS
//------------------------------
#ifdef __cplusplus

#endif 


//is_pointer
template <typename T> struct remove_const_type { typedef T type; };
template <typename T> struct remove_const_type<const T> { typedef T type; };
template <typename T> struct remove_volatile_type { typedef T type; };
template <typename T> struct remove_volatile_type<volatile T> { typedef T type; };
template <typename T> struct removeType : remove_const_type<typename remove_volatile_type<T>::type> {};
template <typename T> struct is_ptr_type { enum { value = false }; };
template <typename T> struct is_ptr_type<T*> { enum { value = true }; };
template <typename T> struct is_ptr : is_ptr_type<typename removeType<T>::type> {};


#define PLACE_HOLDER      int
#define USECS_PER_MSEC      1000
#define MUSECS_PER_SEC      1000
#define USECS_PER_SEC      1000000

#define INSTANCEOF(object, clazz)  !dynamic_cast<clazz*>(object)
#define ARGUMENT_UPPER_LIMIT      10
#define EMPTY()  
#define COMMA() ,
#define SEMICOLON() ;
#define TYPENAME_ARGS(i, value) typename ArgumentType##i
#define TYPENAME_VALUE_ARGS(i, value) typename ArgumentType##i=value
#define INIT_VALUE_ARG(i, name) this->_##name##i=name##i
#define SER_ARG(i, name) _##name##i=transport[i - 1]
#define DES_ARG(i, name) transport[i - 1]=_##name##i
#define NAMED_ARG(i, name) name##i 
#define MEMBER_ARG(i, name) ArgumentType##i name##i
#define INIT_MEMBER_ARG(i, name) _##name##i(name##i)
#define VOID_ARG(i, value) void
#define CAT(a, ...) a ## __VA_ARGS__
#define REPEAT_DEC(count ,macro, split, ...) CAT(REPEAT_DEC_,count)(macro, split, __VA_ARGS__)
#define REPEAT_DEC_1(macro, split, ...) 
#define REPEAT_DEC_2(macro, split, ...)  macro(1, __VA_ARGS__)
#define REPEAT_DEC_3(macro, split, ...)  macro(2, __VA_ARGS__) split() REPEAT_DEC_2(macro, split, __VA_ARGS__)
#define REPEAT_DEC_4(macro, split, ...)  macro(3, __VA_ARGS__) split() REPEAT_DEC_3(macro, split, __VA_ARGS__)
#define REPEAT_DEC_5(macro, split, ...)  macro(4, __VA_ARGS__) split() REPEAT_DEC_4(macro, split, __VA_ARGS__)
#define REPEAT_DEC_6(macro, split, ...)  macro(5, __VA_ARGS__) split() REPEAT_DEC_5(macro, split, __VA_ARGS__)
#define REPEAT_DEC_7(macro, split, ...)  macro(6, __VA_ARGS__) split() REPEAT_DEC_6(macro, split, __VA_ARGS__)
#define REPEAT_DEC_8(macro, split, ...)  macro(7, __VA_ARGS__) split() REPEAT_DEC_7(macro, split, __VA_ARGS__)
#define REPEAT_DEC_9(macro, split, ...)  macro(8, __VA_ARGS__) split() REPEAT_DEC_8(macro, split, __VA_ARGS__)
#define REPEAT_DEC_10(macro, split, ...) macro(9, __VA_ARGS__) split() REPEAT_DEC_9(macro, split, __VA_ARGS__)
#define REPEAT_DEC_11(macro, split, ...) macro(10, __VA_ARGS__) split() REPEAT_DEC_10(macro, split, __VA_ARGS__)
#define REPEAT_DEC_12(macro, split, ...) macro(11, __VA_ARGS__) split() REPEAT_DEC_11(macro, split, __VA_ARGS__)
#define REPEAT_DEC_13(macro, split, ...) macro(12, __VA_ARGS__) split() REPEAT_DEC_12(macro, split, __VA_ARGS__)
#define REPEAT_DEC_14(macro, split, ...) macro(13, __VA_ARGS__) split() REPEAT_DEC_13(macro, split, __VA_ARGS__)
#define REPEAT_DEC_15(macro, split, ...) macro(14, __VA_ARGS__) split() REPEAT_DEC_14(macro, split, __VA_ARGS__)
#define REPEAT_DEC_16(macro, split, ...) macro(15, __VA_ARGS__) split() REPEAT_DEC_15(macro, split, __VA_ARGS__)

#define REPEAT_INC(count, macro, split, ...) CAT(REPEAT_INC_,count)(macro, split, __VA_ARGS__)
#define REPEAT_INC_1(macro, split, ...)  macro(1, __VA_ARGS__)
#define REPEAT_INC_2(macro, split, ...)  REPEAT_INC_1(macro, split, __VA_ARGS__) split() macro(2, __VA_ARGS__)
#define REPEAT_INC_3(macro, split, ...)  REPEAT_INC_2(macro, split, __VA_ARGS__) split() macro(3, __VA_ARGS__)
#define REPEAT_INC_4(macro, split, ...)  REPEAT_INC_3(macro, split, __VA_ARGS__) split() macro(4, __VA_ARGS__)
#define REPEAT_INC_5(macro, split, ...)  REPEAT_INC_4(macro, split, __VA_ARGS__) split() macro(5, __VA_ARGS__)
#define REPEAT_INC_6(macro, split, ...)  REPEAT_INC_5(macro, split, __VA_ARGS__) split() macro(6, __VA_ARGS__)
#define REPEAT_INC_7(macro, split, ...)  REPEAT_INC_6(macro, split, __VA_ARGS__) split() macro(7, __VA_ARGS__)
#define REPEAT_INC_8(macro, split, ...)  REPEAT_INC_7(macro, split, __VA_ARGS__) split() macro(8, __VA_ARGS__)
#define REPEAT_INC_9(macro, split, ...)  REPEAT_INC_8(macro, split, __VA_ARGS__) split() macro(9, __VA_ARGS__)
#define REPEAT_INC_10(macro, split, ...)  REPEAT_INC_9(macro, split, __VA_ARGS__) split() macro(10, __VA_ARGS__)
#define REPEAT_INC_11(macro, split, ...) REPEAT_INC_10(macro, split, __VA_ARGS__) split() macro(11, __VA_ARGS__)
#define REPEAT_INC_12(macro, split, ...) REPEAT_INC_11(macro, split, __VA_ARGS__) split() macro(12, __VA_ARGS__)
#define REPEAT_INC_13(macro, split, ...) REPEAT_INC_12(macro, split, __VA_ARGS__) split() macro(13, __VA_ARGS__)
#define REPEAT_INC_14(macro, split, ...) REPEAT_INC_13(macro, split, __VA_ARGS__) split() macro(14, __VA_ARGS__)
#define REPEAT_INC_15(macro, split, ...) REPEAT_INC_14(macro, split, __VA_ARGS__) split() macro(15, __VA_ARGS__)
#define REPEAT_INC_16(macro, split, ...) REPEAT_INC_15(macro, split, __VA_ARGS__) split() macro(16, __VA_ARGS__)

#define VAR_TYPES(N) REPEAT_INC(N, TYPENAME_ARGS, COMMA)
#define VAR_TYPES_DEFAULT(N,VALUE) REPEAT_INC(N, TYPENAME_VALUE_ARGS, COMMA, VALUE)
#define VAR_ARGS(N) REPEAT_INC(N, NAMED_ARG, COMMA, ArgumentType)
#define VAR_NAMED_ARGS(N, name) REPEAT_INC(N, NAMED_ARG, COMMA, name)
#define VOID_ARGS(N) REPEAT_INC(N, VOID_ARG, COMMA)

#define VAR_ARGS_MEMBERS(N, name, delim) REPEAT_INC(N, MEMBER_ARG, delim, name)
#define INIT_VAR_ARGS_MEMBERS(N, name) REPEAT_INC(N, INIT_MEMBER_ARG, COMMA, name)
#define INIT_VALUE_ARGS(N, name) REPEAT_INC(N, INIT_VALUE_ARG, SEMICOLON, name)

#define SERIALIZE_ARGS(N, name) REPEAT_INC(N, SER_ARG, SEMICOLON, name)
#define DESERIALIZE_ARGS(N, name) REPEAT_INC(N, DES_ARG, SEMICOLON, name)


#define GENERATE_METHOD_CALLBACK_SIGNATURES_ARGUMENTS(N, value)      \
template<typename Caller, typename ReturnType, VAR_TYPES(N)>         \
  struct MethodCallbackSignature<Caller,ReturnType, VAR_ARGS(N)> {  \
  typedef ReturnType(Caller::*Method)(VAR_ARGS(N)); };        \
template<typename Caller, VAR_TYPES(N)>                  \
  struct MethodCallbackSignature<Caller, void, VAR_ARGS(N)> {     \
  typedef void (Caller::*Method)(VAR_ARGS(N)); };

#define GENERATE_METHOD_CALLBACK_INVOKE_ARGUMENTS(N, value)                                      \
template <class BASE, class Caller, class FutureResultType, class ReturnType, VAR_TYPES(N)>                    \
class MethodCallbackInvoke<BASE,Caller,FutureResultType,ReturnType, VAR_ARGS(N)>                        \
    : public BaseMethodCallbackInvoke<BASE, Caller, FutureResultType, ReturnType> {public:                  \
  typedef typename MethodCallbackSignature<Caller, ReturnType, VAR_ARGS(N)>::Method Callback;                  \
  MethodCallbackInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(N, arg, COMMA), const FutureResultType& result) :  \
    BaseMethodCallbackInvoke(caller, result), _method(method), INIT_VAR_ARGS_MEMBERS(N, arg) {}                \
protected: VAR_ARGS_MEMBERS(N, _arg, SEMICOLON); Callback _method; };

#define GENERATE_DELEGATE_INVOKE_ARGUMENTS(N, value)                                  \
template <class BASE, class Caller, class FutureType, class ReturnType, VAR_TYPES(N)>                \
class DelegateInvoke<BASE, Caller, FutureType, ReturnType, VAR_ARGS(N)> :                    \
public MethodCallbackInvoke<BASE, Caller, FutureType, ReturnType, VAR_ARGS(N)> {public:                \
  DelegateInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(N, arg, COMMA), const FutureType& result)  \
    : MethodCallbackInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}                  \
  void invokeMethod() { _result.resolveData(new ReturnType((_context->*_method)(VAR_NAMED_ARGS(N, _arg))));}};  \
template <class BASE, class Caller, class FutureType, VAR_TYPES(N)>                          \
class DelegateInvoke<BASE, Caller, FutureType, void, VAR_ARGS(N)> :                        \
public MethodCallbackInvoke<BASE, Caller, FutureType, void, VAR_ARGS(N)>{public:                  \
  DelegateInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(N, arg, COMMA), const FutureType& result)  \
    : MethodCallbackInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}                  \
  void invokeMethod() { (_context->*_method)(VAR_NAMED_ARGS(N, _arg));}};

#define GENERATE_DELEGATE_ARGUMENTS(N, value)                                              \
template <class Caller, class ReturnType, VAR_TYPES(N)> class Delegate<Caller, ReturnType, VAR_ARGS(N)> :            \
  public DelegateInvoke < DelegateBase, Caller, FutureResult<ReturnType>, ReturnType, VAR_ARGS(N) > {              \
  public:  Delegate(Caller* caller, Callback method, VAR_ARGS_MEMBERS(N, arg, COMMA), const FutureResult<ReturnType>& result)  \
    : DelegateInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {} };                      \
template <class Caller, VAR_TYPES(N)> class Delegate<Caller, void, VAR_TYPES(N)> :                        \
  public DelegateInvoke < DelegateBase, Caller, FutureResult<void>, void, VAR_ARGS(N) >{                    \
  public:  Delegate(Caller* caller, Callback method, VAR_ARGS_MEMBERS(N, arg, COMMA), const FutureResult<void>& result)      \
      : DelegateInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}};

#define GENERATE_MULTICAST_ARGUMENTS(N, value)                                                            \
template<class ReturnType, VAR_TYPES(N)>                                                          \
class IDelegatePublisher<ReturnType, VAR_ARGS(N)> {public:                                                  \
  virtual FutureResult<ReturnType> publish(VAR_ARGS_MEMBERS(N, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) = 0;            \
};                                                                              \
template <class ReturnType, VAR_TYPES(N)>                                                          \
class MulticastDelegate<ReturnType, VAR_ARGS(N)> : public IDelegatePublisher<ReturnType, VAR_ARGS(N)>{private:                        \
  typedef std::vector< IDelegatePublisher<ReturnType, VAR_ARGS(N)>* > SubscribersList;                                  \
  SubscribersList subscribers;                                                              \
public:                                                                            \
  MulticastDelegate() {}                                                                  \
  MulticastDelegate& operator += (IDelegatePublisher<ReturnType, VAR_ARGS(N)>* method) {                                  \
    subscribers.push_back(method);                                                            \
    return *this;}                                                                    \
    void notify(VAR_ARGS_MEMBERS(N, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {        \
      typename SubscribersList::iterator it = subscribers.begin();                                            \
      for (; it != subscribers.end(); it++) { (*it)->publish(VAR_NAMED_ARGS(N, arg), priority, delay, timeout); }  }    \
  FutureResult<ReturnType> operator () (VAR_ARGS_MEMBERS(N, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {              \
    FutureResult<ReturnType> result = publish(VAR_NAMED_ARGS(N, arg), priority, delay, timeout);                            \
    notify(VAR_NAMED_ARGS(N, arg), priority, delay, timeout);                      \
    return result;}};

#define GENERATE_ACTIVE_ARGUMENTS(N, value)                                                                              \
template <class Caller, class ReturnType, VAR_TYPES(N)> class Active<Caller, ReturnType, VAR_ARGS(N)> : public ActiveConstraintUID, public MulticastDelegate<ReturnType, VAR_ARGS(N)> { public:  \
    typedef Delegate<Caller, ReturnType, VAR_ARGS(N)> DelegateType;                                                                \
    typedef typename MethodCallbackSignature<Caller, ReturnType, VAR_ARGS(N)>::Method Callback;                                                  \
    Active(Caller* caller, Scheduler<Caller>* sch, Callback method) :_context(caller), _sch(sch), _method(method) {}                                      \
    FutureResult<ReturnType> operator () (VAR_ARGS_MEMBERS(N, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {              \
    FutureResult<ReturnType> result = publish(VAR_NAMED_ARGS(N, arg), priority, delay, timeout); return result;};                            \
    FutureResult<ReturnType> publish(VAR_ARGS_MEMBERS(N, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {                                    \
      FutureResult<ReturnType> result(new FutureObject<ReturnType>());                                                            \
      DelegateBase::Ptr pDelegate(new DelegateType(_context, _method, VAR_NAMED_ARGS(N, arg), result));                                            \
      _sch->schedule(pDelegate,priority,delay, timeout, _guardId, _conditionId);                                                        \
    this->notify(VAR_NAMED_ARGS(N, arg), priority, delay, timeout);                \
      return result;} private: Caller* _context; Scheduler<Caller>* _sch; Callback _method; };


#define GENERATE_METHOD_CALLBACK_SIGNATURES(N)  REPEAT_DEC(N, GENERATE_METHOD_CALLBACK_SIGNATURES_ARGUMENTS, EMPTY)
#define GENERATE_METHOD_CALLBACK_INVOKE(N)  REPEAT_DEC(N, GENERATE_METHOD_CALLBACK_INVOKE_ARGUMENTS, EMPTY)
#define GENERATE_DELEGATE_INVOKE(N)  REPEAT_DEC(N, GENERATE_DELEGATE_INVOKE_ARGUMENTS, EMPTY)
#define GENERATE_DELEGATE(N)  REPEAT_DEC(N, GENERATE_DELEGATE_ARGUMENTS, EMPTY)
#define GENERATE_MULTICAST_METHOD(N)  REPEAT_DEC(N, GENERATE_MULTICAST_ARGUMENTS, EMPTY)
#define GENERATE_ACTIVE_METHOD(N)  REPEAT_DEC(N, GENERATE_ACTIVE_ARGUMENTS, EMPTY)

#ifdef WINDOWS_OS
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))

#define SOCKET_TYPE            SOCKET
#define CLOSE_SOCKET(arg) \
  closesocket(arg)

#define EVENT_TYPE            HANDLE
#define CONDITION_TYPE          PLACE_HOLDER
#define THREAD_TYPE             HANDLE
#define THREAD_RETURN_TYPE        unsigned WINAPI
#define THREAD_ERROR_INSTANCE(returnValue)  ((returnValue) == NULL)
#define THREAD_ERROR_CODE(value)      GetLastError()

#define MUTEX_CRITICAL_SECTION      CRITICAL_SECTION
#define START_MUTEX_FUNCTION(arg) \
  InitializeCriticalSection((arg))

#define TERMINATE_MUTEX_FUNCTION(arg) \
  DeleteCriticalSection((arg))

#define LOCK_MUTEX_FUNCTION(arg) \
  EnterCriticalSection((arg))

#define UNLOCK_MUTEX_FUNCTION(arg) \
  LeaveCriticalSection((arg))

#define START_EVENT_TYPE_FUNCTION(mutex, cond, reset) \
  mutex = CreateEvent(NULL, reset, FALSE, NULL);    \
  if (!mutex)                      \
    throw ThreadException("mutex signal failed")

#define TERMINATE_EVENT_FUNCTION(mutex, cond) \
  CloseHandle(mutex)

#define WAIT_EVENT_FUNCTION(mutex, cond, wakeup)    \
  switch(WaitForSingleObject(mutex, INFINITE)) {    \
  case WAIT_OBJECT_0:                  \
    return;                      \
  default:                      \
    throw ThreadException("wait event failed");    \
  }

#define WAIT_TIME_EVENT_FUNCTION(mutex, cond, time, wakeup, reset, status)      \
  switch (WaitForSingleObject(mutex, time + 1))                  \
  {                                        \
  case WAIT_OBJECT_0:                                \
    status = true;                                \
    break;                                        \
  case WAIT_TIMEOUT:                                \
    status = false;                                \
    break;                                        \
  default:                                    \
    throw ThreadException("wait failed");                      \
  }

#define WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup) \
  SetEvent(mutex)

#define THREAD_JOIN_FUNCTION(hdl)        WaitForSingleObject(hdl, INFINITE)
#define THREAD_SLEEP_FUNCTION(ms)        Sleep((ms))

#define THREAD_CREATE_FUNCTION(id, funPtr, callPtr)  id =(HANDLE)CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)funPtr,callPtr,0L,NULL)

#define THREAD_TERMINATE_FUNCTION(hdl)  TerminateThread(hdl, 0)

#define THREAD_CANCEL_FUNCTION(hdl)  TerminateThread(hdl, 0)

#define IS_THREAD_ALIVE_FUNCTION(hdl, isRunning)  \
  DWORD exitCode = 0;                \
  if(GetExitCodeThread(hdl, &exitCode))       \
    isRunning = (exitCode == STILL_ACTIVE)

#define BROADCAST_FUNCTION(arg) 0

#define SET_EVENT_FUNCTION(arg) \
  SetEvent((arg))

#define RESET_EVENT_FUNCTION(arg) \
  ResetEvent((arg))

#define LOCK_MUTEX_EVENT_FUNCTION(arg) 0
#define UNLOCK_MUTEX_EVENT_FUNCTION(arg) 0
  
#else
typedef int                 BOOL;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif
#define SOCKET_TYPE            int
#define CLOSE_SOCKET(arg) \
  close(arg)

#define EVENT_TYPE              pthread_mutex_t
#define CONDITION_TYPE            pthread_cond_t

#define THREAD_TYPE              pthread_t
#define THREAD_RETURN_TYPE          void *

#define THREAD_ERROR_INSTANCE(returnValue)  ((returnValue) == NULL)
#define THREAD_ERROR_CODE(value)      errno

#define MUTEX_CRITICAL_SECTION          pthread_mutex_t
#define START_MUTEX_FUNCTION(arg)  \
  pthread_mutex_init ((arg), NULL)

#define TERMINATE_MUTEX_FUNCTION(arg) \
  pthread_mutex_destroy((arg))

#define LOCK_MUTEX_FUNCTION(arg)  \
  pthread_mutex_lock((arg))

#define UNLOCK_MUTEX_FUNCTION(arg) \
  pthread_mutex_unlock((arg))

#define START_EVENT_TYPE_FUNCTION(mutex, cond, reset) \
   if (pthread_mutex_init(&mutex, NULL))        \
    throw ThreadException("mutex signal failed");  \
   pthread_cond_init(&cond, NULL)

#define TERMINATE_EVENT_FUNCTION(mutex, cond) \
  pthread_cond_destroy(&cond); \
  pthread_mutex_destroy(&mutex)

#define WAIT_EVENT_FUNCTION(mutex, cond, wakeup)    \
  pthread_mutex_lock(&mutex);              \
  int err = 0;                    \
  while (!wakeup) {                        \
    err = pthread_cond_wait(&cond, &mutex);      \
    if (err) {                    \
      pthread_mutex_unlock(&mutex);          \
      throw ThreadException("wait event failed"); \
    }                        \
  }                          \
  wakeup = FALSE;                    \
  pthread_mutex_unlock(&mutex)


#define WAIT_TIME_EVENT_FUNCTION(mutex, cond, ms, wakeup, reset, status)      \
  struct timeval tv                                \
  struct timespec tdif                              \
  gettimeofday(&tv, NULL)                              \
  tdif.tv_sec  = tv.tv_sec + ms / MUSECS_PER_SEC                  \
  tdif.tv_nsec = tv.tv_usec*MUSECS_PER_SEC + (ms % MUSECS_PER_SEC)*USECS_PER_SEC  \
  if (tdif.tv_nsec >= NSECS_PER_SEC) {                      \
    tdif.tv_nsec -= NSECS_PER_SEC                        \
    tdif.tv_sec++                                \
      }                                    \
  pthread_mutex_lock(&mutex)                            \
      while (!wakeup)                              \
            {                              \
    status = pthread_cond_timedwait(&cond, &mutex, &tdif)            \
    if(status) {                                \
      if (status == ETIMEDOUT) break;                      \
      pthread_mutex_unlock(&mutex)                      \
      throw ThreadException(get_error(status))                \
            }                              \
            }                              \
  wakeup =  status == 0 && reset ? false : wakeup                  \
  pthread_mutex_unlock(&mutex)

#define WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup)  \
  pthread_mutex_lock(&mutex);            \
  wakeup = TRUE;                  \
  pthread_cond_signal(&cond);            \
  pthread_mutex_unlock(&mutex)

#define THREAD_JOIN_FUNCTION(id)  pthread_join(id, NULL)
#define THREAD_SLEEP_FUNCTION(ms) \
  struct timeval tv; \
    tv.tv_usec = (ms % MUSECS_PER_SEC) * USECS_PER_MSEC; \
    tv.tv_sec = ms / MUSECS_PER_SEC; \
    select(0, NULL, NULL, NULL, &tv)

#define THREAD_CREATE_FUNCTION(id, funPtr, callPtr)        \
  pthread_attr_t attr;                    \
  pthread_attr_init(&attr);                  \
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);  \
  pthread_attr_setinheritsched(&attr, PTHREAD_INHERIT_SCHED);  \
  pthread_create(&id, &attr, funPtr, callPtr);        \
  pthread_attr_destroy(&attr)

#define THREAD_TERMINATE_FUNCTION(arg)  pthread_exit(arg)
#define THREAD_CANCEL_FUNCTION(Id)          \
  if (pthread_cancel(Id) == 0)          \
    pthread_detach(Id);

#define IS_THREAD_ALIVE_FUNCTION(hdl, isRunning)  \
  isRunning = (pthread_kill(hdl, 0) == 0)

#define BROADCAST_FUNCTION(arg) \
  pthread_cond_broadcast((arg))

#define SET_EVENT_FUNCTION(arg) 1

#define RESET_EVENT_FUNCTION(arg) 1

#define LOCK_MUTEX_EVENT_FUNCTION(arg)  \
  pthread_mutex_lock((arg))

#define UNLOCK_MUTEX_EVENT_FUNCTION(arg) \
  pthread_mutex_unlock((arg))

#endif

#define CREATE_THREAD(id, funPtr, callPtr)                \
  THREAD_CREATE_FUNCTION(id, funPtr, callPtr);            \
  if(THREAD_ERROR_INSTANCE(id))                    \
    throw ThreadException(ErrorMessage(THREAD_ERROR_CODE(id)))

static std::string ErrorMessage(int errorCode){
  string str = "";
  if (errorCode == 0) {
    return str;
  }

  char const* what = "Error Numer";
  int whlen = strlen(what);
  int ncode = errorCode, dlen = 1;
  while (ncode !=0) {dlen++; ncode/=10;}
  char *buffer = (char *) malloc(sizeof(char) * (whlen + dlen + 1));
    sprintf(buffer, "%s = %d", what, errorCode);
  str = buffer;
  return str;
}

class Exception : public std::exception {
  friend ostream& operator<<(ostream& output, const Exception& ex) {
    output << "Exception: " << ex.error;
    return output;
  }
public:
  Exception() throw() : error(std::string("Exception")) {}
  Exception(std::string err) throw() : error(err) {}
  Exception(const Exception& source) throw() : std::exception(source) { error = source.error; }
  virtual ~Exception() throw () {}
  Exception& operator=(const Exception& source) throw() {
    if (&source != this) {
      error = source.error;
    }
    std::exception::operator= (source);
    return *this;
  }
  void setError(std::string exce) { error = exce; }
  virtual const char* what() const throw() { return error.c_str(); }
protected:
  std::string error;
};


struct ThreadException : public Exception{
public:
  ThreadException() : Exception() {}
  ThreadException(char* errorMessage) : Exception(errorMessage) {}
  ThreadException(std::string errorMessage) : Exception(errorMessage) {}
};

template <typename T>
void* ConvertToFunctionPointer(T x) {
  return *reinterpret_cast<void**>(&x);
}

struct Runnable {
  virtual void run() = 0;
};

class AtomicMutex{
  public:
  AtomicMutex() { START_MUTEX_FUNCTION(&section); }
  ~AtomicMutex() { TERMINATE_MUTEX_FUNCTION(&section); }
    void lock() { LOCK_MUTEX_FUNCTION(&section); }
    void unlock() { UNLOCK_MUTEX_FUNCTION(&section); }

  private:
  MUTEX_CRITICAL_SECTION section;
};

static AtomicMutex atomicMutex;

class MutexLock{
public:

  MutexLock() : m_value(0){
    wakeup = FALSE;
    START_EVENT_TYPE_FUNCTION(mutex, cond, FALSE);
  }

  MutexLock(const MutexLock& m) {
    this->m_value = m.m_value;
    this->wakeup = m.wakeup;
    this->mutex = m.mutex;
    this->cond = m.cond;
  }

  ~MutexLock(){
    TERMINATE_EVENT_FUNCTION(mutex, cond);
  }

  void wait() {
    WAIT_EVENT_FUNCTION(mutex, cond, wakeup);
  }

  void wakeUp() {
    WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup);
  }

  void lock() {
    bool canBeAccessed = this->verifyLock();
    if (canBeAccessed){
      return;
    }

    atomicMutex.lock();
    canBeAccessed = m_value == 0;
    m_value += 1;
    atomicMutex.unlock();

    if (!canBeAccessed){
      wait();
      atomicMutex.lock();
      m_value -= 1;
      atomicMutex.unlock();
    }

  }

  bool isLocked() {
    atomicMutex.lock();
    bool canBeAccessed = m_value == 0;
    atomicMutex.unlock();
    return !canBeAccessed;
  }

  bool verifyLock(int set = 0) {
    atomicMutex.lock();
    bool canBeAccessed = m_value == 0;
    if (m_value == set) {
      m_value = !set;
      canBeAccessed = true;
    }
    atomicMutex.unlock();
    return canBeAccessed;
  }

  void unlock() {
    if (!verifyLock(1)){
      wakeUp();
    }
  }

private:
  volatile int m_value;
  volatile bool wakeup;

  EVENT_TYPE mutex;
  CONDITION_TYPE  cond;
};

#define synchronized(L)                                               \
        for(L.lock();L.isLocked();                    \
      L.unlock() )

struct ThreadParameters
{
    void* runCall;
    void* context;
    ThreadParameters(void* ctx, void* callPtr) : context(ctx), runCall(callPtr) {}
};


class Thread: public Runnable {

  public:
    Thread(string threadName = "") : runnableObject(NULL), name(threadName), thrParams(this,ConvertToFunctionPointer(&Thread::run))
      , _threadHdl(0),_isRunning(false),_isTerminated(false) {}
    Thread(Runnable *target, string threadName = "") :  name(threadName),thrParams(this,ConvertToFunctionPointer(&Thread::run)) , runnableObject(target) {}
    Thread(void* funcPtr, void* ctx = 0 ,string threadName = "") : runnableObject(NULL), name(threadName), thrParams(ctx,funcPtr) {}
    Thread(void (*funcPtr)(void*), void* ctx = 0, string threadName = "") : runnableObject(NULL),name(threadName), thrParams(ctx,ConvertToFunctionPointer(funcPtr)) {}
    Thread(void (*funcPtr)(), string threadName = "") : runnableObject(NULL),name(threadName), thrParams(this,ConvertToFunctionPointer(funcPtr)) {}
    template<class T>
    Thread(void (T::*RunnableCall)(), string threadName = "") : runnableObject(NULL), name(threadName), thrParams(this,ConvertToFunctionPointer(RunnableCall)) {}
    template<class T>
    Thread(void (T::*RunnableCall)(void*), void* ctx = 0, string threadName = "") : runnableObject(NULL), name(threadName), thrParams(ctx,ConvertToFunctionPointer(RunnableCall)) {}
    virtual ~Thread() {
      THREAD_TERMINATE_FUNCTION(0);
    }

    static void sleep(long ms) throw(ThreadException) {
      THREAD_SLEEP_FUNCTION(ms);
    }

    THREAD_TYPE getId() const {
      return this->_threadHdl;
    }

    static THREAD_RETURN_TYPE threadFunctionPointer(void* ptr) {
      ThreadParameters* threadParameters = (ThreadParameters*)ptr;
      if(threadParameters->context != NULL) {
        Runnable* run = (Thread*) threadParameters->context;
        run->run();
        //((void (*)(void*)) threadParameters->runCall)(threadParameters->context);
      } else {
          ((void (*)(void)) threadParameters->runCall)();
      }

      return 0;
    }

    bool isFinished() {
      return !this->isRunning();
    }

    bool isTerminated() {
      synchronized(lock) {
        return this->_isTerminated;
      }
      return 0;
    }

    bool isRunning() {
      synchronized(lock) {
        if(this->_isRunning) {
          IS_THREAD_ALIVE_FUNCTION(_threadHdl,_isRunning);
        }
        return this->_isRunning;
      }
      
      return 0;
    }

    virtual void run() {
      if(this->runnableObject != NULL) {
        runnableObject->run();
      }
    }

    virtual void stop() {
      synchronized(lock) {
        THREAD_CANCEL_FUNCTION(_threadHdl);
        _isTerminated = true;
        _isRunning = false;
      }
    }

    string getName() const {
      return name;
    }

    void setName(string name) {
      this->name = name;
    }

    virtual void start(Runnable *target) throw(ThreadException) {
      runnableObject = target;
      start();
    }
    
    virtual void start() throw(ThreadException) {
      synchronized(lock) {
        reset();
        CREATE_THREAD(_threadHdl,Thread::threadFunctionPointer, &thrParams);
        _isRunning = true;
      }
    }

    void join() throw(ThreadException) {
      THREAD_JOIN_FUNCTION(_threadHdl);
    }
    
    void wait() throw(ThreadException) {
      lock.wait();
    }

    void wakeUp() throw(ThreadException) {
      lock.wakeUp();
    }

  private:
    mutable MutexLock lock;
    THREAD_TYPE _threadHdl;
    string name;

    ThreadParameters thrParams;
    Runnable* runnableObject;

    bool _isRunning;
    bool _isTerminated;

    void reset() {
      _threadHdl = 0;
      _isRunning = false;
      _isTerminated = false;
    }
};

template <class PT>
class AutoPtr {
public:
  AutoPtr(PT* p = NULL, bool shared = false) : _ptr(NULL) { _ptr=p; if (shared && _ptr) _ptr->reference(); }
  AutoPtr(const AutoPtr& ptr) : _ptr(NULL) { _ptr=ptr._ptr; if (_ptr) _ptr->reference(); }
  ~AutoPtr() { if (_ptr) _ptr->release(); }
  AutoPtr& operator = (const AutoPtr& ptr) {
    if (&ptr != this) {
      if (_ptr) _ptr->release();
      _ptr = ptr._ptr;
      if (_ptr) _ptr->reference();
    }
    return *this;
  }
  PT* operator -> () {
    if (_ptr)
      return _ptr;
    else
      throw std::exception("Null Pointer Exception");
  }
  PT* reference() { if (_ptr) _ptr->reference(); return _ptr; }
  PT* value() { return _ptr; }
  operator const PT* () const { return _ptr; }
  bool operator == (const AutoPtr& ptr) const { return _ptr == ptr._ptr; }
  bool operator != (const AutoPtr& ptr) const { return _ptr != ptr._ptr; }
private:
  PT* _ptr;
};

class ReferenceObject {
private:
  mutable MutexLock mutex;
  mutable volatile int referenceNumber;
public:
  ReferenceObject() {
    synchronized(mutex) {
      referenceNumber = 1;
    }
  }
  void reference() const {
    synchronized(mutex) {
      ++referenceNumber;
    }
  }
  void release() const {
    synchronized(mutex) {
      --referenceNumber;
    }
    if (referenceNumber == 0) {
      delete this;
    }
  }
  size_t size() const {
    int val = 0;
    synchronized(mutex) {
      val = referenceNumber;
    }
  }
protected:
  virtual ~ReferenceObject() {}
};
template <typename Object> struct RefPointer : public ReferenceObject { typedef AutoPtr<Object> Ptr; };

class AutoLock {
public:
  explicit AutoLock(MutexLock& mutex) : _mutex(mutex) { _mutex.lock(); }
  ~AutoLock() { try{ _mutex.unlock(); } catch (...) {} }
private:
  MutexLock& _mutex;
};

class Signal {
public:
  Signal(bool manualReset = true) {
    START_EVENT_TYPE_FUNCTION(_mutex, _cond, manualReset ? FALSE : TRUE);
  }

  ~Signal() {
    TERMINATE_EVENT_FUNCTION(_mutex, _cond);
  }

  void notify() {
    if (LOCK_MUTEX_EVENT_FUNCTION(&_mutex))
      throw ThreadException("cannot notify lock");
    if (BROADCAST_FUNCTION(&_cond))
    {
      UNLOCK_MUTEX_EVENT_FUNCTION(&_mutex);
      throw ThreadException("cannot notify lock");
    }
    if (!SET_EVENT_FUNCTION(_mutex))
    {
      throw ThreadException("cannot notify lock");
    }
    UNLOCK_MUTEX_EVENT_FUNCTION(&_mutex);
  }

  void wait() {
    WAIT_EVENT_FUNCTION(_mutex, _cond, _state);
  }

  bool wait(long ms, bool timeout = false) {
    int status = false;
    WAIT_TIME_EVENT_FUNCTION(_mutex, _cond, ms, _state, _auto, status)
      if (timeout && !status)
        throw ThreadException("Timeout Exception");
    return status;
  }

  void reset()
  {
    if (LOCK_MUTEX_EVENT_FUNCTION(&_mutex)) {
      throw ThreadException("reset signal lock");
    }
    if (!RESET_EVENT_FUNCTION(_mutex)) {
      throw ThreadException("reset signal lock");
    }
    UNLOCK_MUTEX_EVENT_FUNCTION(&_mutex);
  }

private:
  EVENT_TYPE _mutex;
  CONDITION_TYPE  _cond;
};


class UID {
public:
  unsigned int _uid;
  UID() { _uid = ++uid; }
  UID(const UID& uid) { _uid = uid._uid; }
  UID& operator=(const UID& uid)  { _uid = uid._uid; return(*this); }
  operator int() { return _uid; }
  bool operator == (const UID& uid) const { return _uid == uid._uid; }
  bool operator != (const UID& uid) const { return _uid != uid._uid; }
  bool operator == (const unsigned int& uid) const { return _uid == uid; }
  bool operator != (const unsigned int& uid) const { return _uid != uid; }
protected:
  static unsigned int uid;
};

template <class DataType>
class DataResolver {
public:
  DataResolver() : _data(0) { }
  DataType& data() {
    return *_data;
  }
  void resolveData(DataType* data) {
    delete _data;
    _data = data;
  }
private:
  DataType* _data;
};

class ErrorResolver {
public:
  ErrorResolver() :_error(0) {}
  std::string getErrorMessage() const {
    return (_error) ? _error->what() : std::string();
  }
  std::exception* getError() const {
    return _error;
  }
  void resolveError(const std::string& msg) {
    delete _error;
    _error = new std::exception(msg.c_str());
  }
  bool hasError() const {
    return _error != 0;
  }
private:
  std::exception*  _error;
};

class SharedObject : public ReferenceObject {
public:
  SharedObject() : _signal(false) {}
  void wait() {
    _signal.wait();
  }
  bool wait(long ms, bool timeout = false) {
    return _signal.wait(ms, timeout);
  }
  void notify() {
    _signal.notify();
  }
private:
  Signal       _signal;
};

template <typename T>
struct SharedObjectProxy
{
  typedef T* DataTypePtr;
public:
  SharedObjectProxy(DataTypePtr data) : _data(data) {}
  SharedObjectProxy(const SharedObjectProxy& proxy) {
    _data = proxy._data;
    _data->reference();
  }
  ~SharedObjectProxy() {
    _data->release();
  }
  void snooze() {
    _data->wait(0); //for (; data->wait(10); );
  }
  void wait() {
    _data->wait();
  }
  bool wait(long ms, bool timeout = false) {
    return _data->wait(ms, timeout);
  }
  bool ready() const {
    return _data->wait(0);
  }
  void notify() {
    _data->notify();
  }
protected:
  SharedObjectProxy();
  DataTypePtr  _data;
};

template <typename BASE, typename T = typename BASE::DataTypePtr>
struct ErrorProxy : public BASE {
public:
  ErrorProxy(T data) : BASE(data) {}
  ErrorProxy(const ErrorProxy& proxy) : BASE(proxy) {}
  std::string getErrorMessage() const {
    return _data->getErrorMessage();
  }
  std::exception* getError() const {
    return _data->getError();
  }
  void resolveError(const std::string& msg) {
    _data->resolveError(msg);
  }
  bool hasError() const {
    return _data->hasError();
  }
};

template <typename BASE, class Type, typename T = typename BASE::DataTypePtr>
struct DataProxy : public BASE {
public:
  DataProxy(T data) : BASE(data) {}
  DataProxy(const DataProxy& proxy) : BASE(proxy) {}
  Type& data() const {
    return _data->data();
  }
  void resolveData(Type* data) {
    _data->resolveData(data);
  }
};

template<typename Caller, typename ReturnType = void, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> struct MethodCallbackSignature;
template<typename Caller, typename ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> struct MethodCallbackSignature { typedef ReturnType(Caller::*Method)(VAR_ARGS(ARGUMENT_UPPER_LIMIT)); };
template<typename Caller, typename ReturnType> struct MethodCallbackSignature<Caller, ReturnType, VOID_ARGS(ARGUMENT_UPPER_LIMIT)> { typedef ReturnType(Caller::*Method)(); };
template<typename Caller, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> struct MethodCallbackSignature<Caller, void, VAR_ARGS(ARGUMENT_UPPER_LIMIT)> { typedef void (Caller::*Method)(VAR_ARGS(ARGUMENT_UPPER_LIMIT)); };
template<typename Caller> struct MethodCallbackSignature<Caller, void, VOID_ARGS(ARGUMENT_UPPER_LIMIT)> { typedef void (Caller::*Method)(); };

GENERATE_METHOD_CALLBACK_SIGNATURES(ARGUMENT_UPPER_LIMIT)


template <class BASE, class Caller, class FutureType, class ReturnType>
class BaseMethodCallbackInvoke : public BASE {
public:
  BaseMethodCallbackInvoke(Caller* caller, const FutureType& result) :
    _result(result), _context(caller) {}
  ~BaseMethodCallbackInvoke() { this->release(); }
  void run(){
    try {
      invokeMethod();
    }
    catch (std::exception& e) {
      _result.resolveError(e.what());
    }
    catch (...) {
      _result.resolveError("Invoke Error");
    }
    _result.notify();
  }
  void resolveError(const std::string& msg) {
    _result.resolveError(msg);
  }
protected:
  virtual void invokeMethod() = 0;
  Caller* _context;
  FutureType _result;
};

template<class BASE, class Caller, class FutureType, class ReturnType, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class MethodCallbackInvoke;

template <class BASE, class Caller, class FutureType, class ReturnType = void, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class MethodCallbackInvoke : public BaseMethodCallbackInvoke<BASE, Caller, FutureType, ReturnType> {
public:
  typedef typename MethodCallbackSignature<Caller, ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)>::Method Callback;
  MethodCallbackInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), const FutureType& result) :
    BaseMethodCallbackInvoke(caller, result), _method(method), INIT_VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg) {}
protected:
  VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, _arg, SEMICOLON);
  Callback    _method;
};

GENERATE_METHOD_CALLBACK_INVOKE(ARGUMENT_UPPER_LIMIT)

template <class BASE, class Caller, class FutureType, class ReturnType>
class MethodCallbackInvoke<BASE, Caller, FutureType, ReturnType> : public BaseMethodCallbackInvoke<BASE, Caller, FutureType, ReturnType>{
public:
  typedef typename MethodCallbackSignature<Caller, ReturnType>::Method Callback;
  MethodCallbackInvoke(Caller* caller, Callback method, const FutureType& result) :
    BaseMethodCallbackInvoke(caller, result), _method(method) {}
protected:
  Callback    _method;
};

template<class BASE, class Caller, class FutureType, class ReturnType = void, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class DelegateInvoke;

template <class BASE, class Caller, class FutureType, class ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class DelegateInvoke : public MethodCallbackInvoke<BASE, Caller, FutureType, ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)> {
public:
  DelegateInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), const FutureType& result)
    : MethodCallbackInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}
  void invokeMethod() {
    _result.resolveData(new ReturnType((_context->*_method)(VAR_ARGS(ARGUMENT_UPPER_LIMIT))));
  }
};

template <class BASE, class Caller, class FutureType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class DelegateInvoke<BASE, Caller, FutureType, void, VAR_ARGS(ARGUMENT_UPPER_LIMIT)> : public MethodCallbackInvoke<BASE, Caller, FutureType, void, VAR_ARGS(ARGUMENT_UPPER_LIMIT)>{
public:
  DelegateInvoke(Caller* caller, Callback method, VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), const FutureType& result)
    : MethodCallbackInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}
  void invokeMethod() {
    (_context->*_method)(VAR_ARGS(ARGUMENT_UPPER_LIMIT));
  }
};

GENERATE_DELEGATE_INVOKE(ARGUMENT_UPPER_LIMIT)

template <class BASE, class Caller, class FutureType, class ReturnType>
class DelegateInvoke<BASE, Caller, FutureType, ReturnType> : public MethodCallbackInvoke<BASE, Caller, FutureType, ReturnType, void>{
public:
  DelegateInvoke(Caller* caller, Callback method, const FutureType& result) : MethodCallbackInvoke(caller, method, result) {}
  void invokeMethod() {
    _result.resolveData(new ReturnType((_context->*_method)()));
  }
};

template <class BASE, class Caller, class FutureType>
class DelegateInvoke<BASE, Caller, FutureType> : public MethodCallbackInvoke<BASE, Caller, FutureType, void, void>{
public:
  DelegateInvoke(Caller* caller, Callback method, const FutureType& result) : MethodCallbackInvoke(caller, method, result) {}
  void invokeMethod() {
    (_context->*_method)();
  }
};

class DelegateBase : public Runnable, public RefPointer<DelegateBase> {
public:
  virtual void resolveError(const std::string& msg) = 0;
};

template <class FutureType> class FutureObject : public SharedObject, public DataResolver<FutureType>, public ErrorResolver {};
template <> class FutureObject<void> : public SharedObject, public ErrorResolver{};
template <class FutureType> class FutureResult : public DataProxy< ErrorProxy< SharedObjectProxy<FutureObject<FutureType>>>, FutureType>{
public: FutureResult(SharedObjectProxy::DataTypePtr ptr) :DataProxy(ptr){}
};
template <> class FutureResult<void> : public ErrorProxy< SharedObjectProxy<FutureObject<void>>>{
public:  FutureResult(SharedObjectProxy::DataTypePtr ptr) :ErrorProxy(ptr){}
};

template<class Caller, class ReturnType = void, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class Delegate;
template <class Caller, class ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> class Delegate : public DelegateInvoke < DelegateBase, Caller, FutureResult<ReturnType>, ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT) > {
public:  Delegate(Caller* caller, Callback method, VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), const FutureResult<ReturnType>& result) : DelegateInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}
};
template <class Caller, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> class Delegate<Caller, void, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> : public DelegateInvoke < DelegateBase, Caller, FutureResult<void>, void, VAR_ARGS(ARGUMENT_UPPER_LIMIT) >{
public:  Delegate(Caller* caller, Callback method, VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), const FutureResult<void>& result) : DelegateInvoke(caller, method, VAR_NAMED_ARGS(N, arg), result) {}
};
template <class Caller, class ReturnType> class Delegate<Caller, ReturnType, void> : public DelegateInvoke< DelegateBase, Caller, FutureResult<ReturnType>, ReturnType, void >{
public:  Delegate(Caller* caller, Callback method, const FutureResult<ReturnType>& result) : DelegateInvoke(caller, method, result) {}
};
template <class Caller> class Delegate<Caller, void, void> : public DelegateInvoke< DelegateBase, Caller, FutureResult<void>, void, void >{
public:  Delegate(Caller* caller, Callback method, const FutureResult<void>& result) : DelegateInvoke(caller, method, result) {}
};

GENERATE_DELEGATE(ARGUMENT_UPPER_LIMIT)

template <class Caller>
struct Request : public RefPointer<Request<Caller>> {
public:
  typedef std::deque<Ptr> RequestsQueue;
  typedef typename MethodCallbackSignature<Caller, bool, int>::Method RequestGuard;
  Request(int priority = 0, long delay = 0, long timeout = 0, Caller* caller = 0, RequestGuard guard = 0, int guardId = 0, int conditionId = 0) : _priority(priority), _delay(delay), _timeout(timeout), _context(caller), _guard(guard), _guardId(guardId), _conditionId(conditionId) {}
  int getPriority() const { return _priority; }
  int getDelay() const { return _delay; }
  int getTimeout() const { return _timeout; }
  bool filtered() {
    if (_guard){
      return !((_context->*_guard)(_guardId));
    }
    return false;
  }
  bool deferred() {
    if (_guard){
      return !((_context->*_guard)(_conditionId));
    }
    return false;
  }
private:
  Caller*    _context;
  RequestGuard _guard;
  int _guardId;
  int _conditionId;
  int _priority;
  long _delay;
  long _timeout;
};

template <class Caller>
struct MethodAccessRequest {
  typename Request<Caller>::Ptr request;
  Signal ready;
  typedef std::deque<MethodAccessRequest<Caller>*> MethodAccessRequestQueue;
};

template <class Caller> struct MethodInvokeRequest : public Request<Caller> {
public:
  MethodInvokeRequest(DelegateBase::Ptr requestRunnable, int priority = 0, long delay = 0, long timeout = 0, Caller* caller = 0, RequestGuard guard = 0, int guardId = 0, int conditionId = 0)
    : _requestRunnable(requestRunnable), Request(priority, delay, timeout, caller, guard, guardId, conditionId){}
  DelegateBase::Ptr getRequest() const { return _requestRunnable; }
private:
  DelegateBase::Ptr _requestRunnable;
};


template <class Caller>
class ScheduleQueue : protected Runnable {
public:
  ScheduleQueue() : deferringRunning(false)  {}
  ~ScheduleQueue() { try { clear(); } catch (...) {} }
  void request(typename Request<Caller>::Ptr request, bool urgent = false) {
    synchronized(_lock) {
      deferringRunning = false;
      if (request->deferred()) {
        _deferred.push_back(request);
      }
      else {
        addRequest(request, urgent);
      }
    }
  }

  typename Request<Caller>* processPendingRequests(){
    //::Sleep(1);    // DEBUG
    Request<Caller>::Ptr request = NULL;
      MethodAccessRequest<Caller>* mq = NULL;
      processDeferred();
      synchronized(_lock){
      // ::Sleep(1);  // DEBUG
        request = getNextRequest();
      
      }
      if (request.value() != NULL) {
        return request.reference();
      }
      else if (_pending.empty() && !_deferred.empty() && !deferringRunning) {
        _thread.start(this);
        deferringRunning = true;
      }
      mq = new MethodAccessRequest<Caller>();
      _pending.push_back(mq);
      mq->ready.wait();
      request = mq->request;
      delete mq;
      return request.reference();
  }
  void done() {
    synchronized(_lock) {
      for (MethodAccessRequest<Caller>::MethodAccessRequestQueue::iterator it = _pending.begin(); it != _pending.end(); ++it) {
        (*it)->ready.notify();
      }
      _pending.clear();
    }
  }
  bool empty() const {
    synchronized(_lock) {
      return _requests.empty() && _deferred.empty();
    }
  }
  int size() const {
    synchronized(_lock) {
      return static_cast<int>(_requests.size() + _deferred.size());
    }
  }
  void clear() {
    synchronized(_lock) {
      _requests.clear();
      _deferred.clear();
    }
    _thread.join();
  }
protected:
  void run() {
    while (deferringRunning) { try { processDeferred(); } catch (...) {} }
  }

private:
  void addRequest(typename Request<Caller>::Ptr request, bool urgent = false) {
    if (_pending.empty()) {
      if (urgent) {
        _requests.push_front(request);
      }
      else if (request.value() &&  request->getPriority() <= 0) {
        _requests.push_back(request);
      }
      else {
        typename Request<Caller>::RequestsQueue::iterator it;
        for (it = _requests.begin(); it != _requests.end(); ++it) {
          if (request->getPriority() > (*it)->getPriority())
            break;
        }
        _requests.insert(it, request);
      }
    }
    else {
      MethodAccessRequest<Caller>* mq = _pending.front();
      _pending.pop_front();
      mq->request = request;
      mq->ready.notify();
    }
  }
  void processDeferred() {
    if (!_deferred.empty()) {
      Request<Caller>::Ptr deferred = _deferred.front();
        if (deferred.value() && !deferred->deferred()) {
        _deferred.pop_front();
        addRequest(deferred);
      }
    }
    else {
      deferringRunning = false;
      return;
    }
  }
  typename Request<Caller>::Ptr getNextRequest() {
    Request<Caller>::Ptr request;
    if (!_requests.empty()) {
      request = _requests.front();
      _requests.pop_front();
    }
    return request;
  }
private:
  mutable MutexLock  _lock;
  Thread        _thread;
  bool        deferringRunning;
  typename Request<Caller>::RequestsQueue  _requests;
  typename Request<Caller>::RequestsQueue  _deferred;
  typename MethodAccessRequest<Caller>::MethodAccessRequestQueue  _pending;
};

class TimedEvent : protected Runnable {
public:
  TimedEvent() { }
  virtual ~TimedEvent() { }
  void timeout(DelegateBase::Ptr  method, long ms) {
    _method = method;
    _thread.start(this);
    try{
      _timeoutEvent.wait(ms, true);
    }
    catch (...) {
      _thread.stop();
      _method->resolveError("Timeout Exception");
      _method = NULL;
      _timeoutEvent.notify();
    }
  }
protected:
  void run() {
    _method->reference();
    _method->run();
    _timeoutEvent.notify();
  }
private:
  Thread        _thread;
  DelegateBase::Ptr  _method;
  Signal        _timeoutEvent;
};

template <class Caller>
class Scheduler : protected Runnable {
public:
  typedef typename Request<Caller>::RequestGuard GuardList;
  Scheduler(Caller* caller = 0, GuardList guardList = 0) : _context(caller), _guardList(guardList) {
    _run = true;
    _thread.start(this);
  }
  virtual ~Scheduler() { try { stop(); } catch (...) {} }
  void schedule(DelegateBase::Ptr pDelegate, int priority, long delay, long timeout, UID guard, UID condition) {
    _queue.request(new MethodInvokeRequest<Caller>(pDelegate, priority, delay, timeout, _context, _guardList, guard, condition));
  }
  void cancel() {
    _queue.clear();
  }
protected:
  void run() {
      AutoPtr<Request<Caller>> pendingRequest = _queue.processPendingRequests();
      while (pendingRequest) {
          MethodInvokeRequest<Caller>* mth = dynamic_cast<MethodInvokeRequest<Caller>*>(pendingRequest.value());
        if (mth != NULL && !mth->filtered()) {
            long delay = mth->getDelay();
            if (delay > 0) {
                Thread::sleep(delay);
            }
            if (mth->getTimeout() > 0) {
                _timeEvent.timeout(mth->getRequest(), mth->getTimeout());
            }
            else {
                DelegateBase::Ptr pDelegate = mth->getRequest();
            if (pDelegate.value()) {
              pDelegate->reference();
              pDelegate->run();
              pDelegate = NULL;
          }
          }
        }
        pendingRequest = NULL;
        if (_run)
          pendingRequest = _queue.processPendingRequests();
      }
    }
  void stop() {
    _queue.clear();
    _queue.done();
    _run = false;
    _thread.join();
  }
private:
  Caller*          _context;
  Thread          _thread;
  ScheduleQueue<Caller>  _queue;
  GuardList        _guardList;
  bool          _run;
  TimedEvent        _timeEvent;
};


struct ActiveConstraintUID {
public:
  UID getGuardUID() { return _guardId; }
  UID getConditionUID() { return _conditionId; }
protected:
  UID _guardId;
  UID _conditionId;
};

template<class ReturnType, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class IDelegatePublisher;
template<class ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class IDelegatePublisher {
public:
  virtual FutureResult<ReturnType> publish(VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) = 0;
};
template<class ReturnType>
class IDelegatePublisher<ReturnType> {
public:
  virtual FutureResult<ReturnType> publish(int priority = 0, long delay = 0, long timeout = 0) = 0;
};

template<class ReturnType, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class MulticastDelegate;
template <class ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class MulticastDelegate : public IDelegatePublisher<ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)> {
private:
  typedef std::vector< IDelegatePublisher<ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)> * > SubscribersList;
  SubscribersList subscribers;
public:
  MulticastDelegate() {}
  MulticastDelegate& operator += (const IDelegatePublisher<ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>* method) {
    subscribers.push_back(method);
    return *this;
  }
  void notify(VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {
    typename SubscribersList::iterator it = subscribers.begin();
    for (; it != subscribers.end(); it++) { it->publish(VAR_NAMED_ARGS(ARGUMENT_UPPER_LIMIT, arg), priority, delay, timeout); }
  }
  FutureResult<ReturnType> operator () (VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {
  FutureResult<ReturnType> result = publish(VAR_NAMED_ARGS(ARGUMENT_UPPER_LIMIT, arg), priority, delay, timeout);
    notify(VAR_NAMED_ARGS(ARGUMENT_UPPER_LIMIT, arg), priority, delay, timeout);
    return result;
  }
};
template <class ReturnType>
class MulticastDelegate<ReturnType> : public IDelegatePublisher<ReturnType>{
private:
  typedef std::vector< IDelegatePublisher<ReturnType> * > SubscribersList;
  SubscribersList subscribers;
public:
  MulticastDelegate() {}
  MulticastDelegate& operator += (const IDelegatePublisher<ReturnType>* method) {
  subscribers.push_back(method);
    return *this;
  }
  void notify(int priority = 0, long delay = 0, long timeout = 0) {
    typename SubscribersList::iterator it = subscribers.begin();
    for (; it != subscribers.end(); it++) { (*it)->publish(priority, delay, timeout); }
  }
  FutureResult<ReturnType> operator () (int priority = 0, long delay = 0, long timeout = 0) {
    FutureResult<ReturnType> result = publish(priority, delay, timeout);
    notify(priority, delay, timeout);
    return result;
  }
};


GENERATE_MULTICAST_METHOD(ARGUMENT_UPPER_LIMIT)

template<class Caller, class ReturnType, VAR_TYPES_DEFAULT(ARGUMENT_UPPER_LIMIT, void)> class Active;
template <class Caller, class ReturnType, VAR_TYPES(ARGUMENT_UPPER_LIMIT)>
class Active : public ActiveConstraintUID, public MulticastDelegate<ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)>{
public:
  typedef Delegate<Caller, ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)> DelegateType;
  typedef typename MethodCallbackSignature<Caller, ReturnType, VAR_ARGS(ARGUMENT_UPPER_LIMIT)>::Method Callback;
  Active(Caller* caller, Scheduler<Caller>* sch, Callback method) :_context(caller), _sch(sch), _method(method) {}
  FutureResult<ReturnType> operator () (VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {
    FutureResult<ReturnType> result = publish(priority, delay, timeout);
    return result;
  }
  FutureResult<ReturnType> publish(VAR_ARGS_MEMBERS(ARGUMENT_UPPER_LIMIT, arg, COMMA), int priority = 0, long delay = 0, long timeout = 0) {
    FutureResult<ReturnType> result(new FutureObject<ReturnType>());
    DelegateBase::Ptr pDelegate(new DelegateType(_context, _method, VAR_NAMED_ARGS(ARGUMENT_UPPER_LIMIT, arg), result));
    _sch->schedule(pDelegate, priority, delay, timeout, _guardId, _conditionId);
  this->notify(VAR_NAMED_ARGS(ARGUMENT_UPPER_LIMIT, arg), priority, delay, timeout);
    return result;
  }
private:
  Caller* _context;
  Scheduler<Caller>* _sch;
  Callback   _method;
};

template <class Caller, class ReturnType>
class Active <Caller, ReturnType, void> : public ActiveConstraintUID, public MulticastDelegate<ReturnType> {
public:
  typedef Delegate<Caller, ReturnType, void> DelegateType;
  typedef typename MethodCallbackSignature<Caller, ReturnType>::Method Callback;
  Active(Caller* caller, Scheduler<Caller>* sch, Callback method) :_context(caller), _sch(sch), _method(method) {}
  FutureResult<ReturnType> publish(int priority = 0, long delay = 0, long timeout = 0) {
    FutureResult<ReturnType>  result(new FutureObject<ReturnType>());
    DelegateBase::Ptr pDelegate(new DelegateType(_context, _method, result));
    _sch->schedule(pDelegate, priority, delay, timeout, _guardId, _conditionId);
    this->notify(priority, delay, timeout);
    return result;
  }
private:
  Caller* _context;
  Scheduler<Caller>* _sch;
  Callback   _method;
};
GENERATE_ACTIVE_METHOD(ARGUMENT_UPPER_LIMIT)

template <class Caller>
class AsyncMethod : protected Runnable, public ActiveConstraintUID {
public:
  typedef Delegate<Caller, void, void> DelegateType;
  typedef Active<Caller, void> ActiveType;
  typedef typename MethodCallbackSignature<Caller>::Method Callback;
  AsyncMethod(Caller* caller, Callback method, long interval = 0, long delay = 0, long timeout = 0) :_context(caller), _delegate(new DelegateType(_context, method, new FutureObject<void>())), _delay(delay), _timeout(timeout), _interval(interval), _active(false){}
  AsyncMethod(Caller* caller, Scheduler<Caller>* sch, Callback method, long interval = 0, long delay = 0, long timeout = 0) :_context(caller), _delegate(new DelegateType(_context, method, new FutureObject<void>())), _delay(delay), _timeout(timeout), _interval(interval), _sch(sch), _active(true) {}
  virtual ~AsyncMethod() { try { stop();  _thread.join(); } catch (...) {} }
  void start() {
    _run = true;
    _thread.start(this);
  }
  void stop() {
    _run = false;
  }
protected:
  void run() {
    while (_run) {
      if (!_active && _delay > 0) {
        Thread::sleep(_delay);
      }
      if (_interval > 0) {
        if (_active) {
          _sch->schedule(_delegate, -1, _delay, _timeout, _guardId, _conditionId);
        }
        else {
          _delegate->run();
          if (_timeout > 0)
            _timeoutEvent.wait(_timeout, true);
        }
        Thread::sleep(_interval);
      }
    }
  }
private:
  bool        _run;
  long        _interval;
  long        _delay;
  long        _timeout;
  bool        _active;
  Thread        _thread;
  Caller*        _context;
  DelegateBase::Ptr  _delegate;
  Scheduler<Caller>*  _sch;
  Signal        _timeoutEvent;
};


//A template function to get the index of an item for a given vector. It returns -1 if the
//item was not found
template <typename InputIterator, typename EqualityComparable>
  int IndexOf(const InputIterator& begin,
  const InputIterator& end, const EqualityComparable& item) {
    if(begin == end )
      return -1;

    InputIterator fnd = std::find(begin, end, item);
    unsigned int index = std::distance(begin, fnd);
    return fnd != end ? index : -1;
};

//Used as a function pointer to safely destroy elements or collections of elements
//Example: 
//  std::for_each( arr->begin(), arr->end(), delete_pointer_element());
//  delete arr;
struct deleteElement{
template< typename T >
void operator()( T element ) const{
  delete element;
  }
};

template<typename T>
unsigned int compare(T c1, T c2, unsigned int sz ) {
  if(!is_ptr<T>::value) {
    return std::memcmp(&c1,&c2, sz);
  }
  return std::memcmp((void*)c1, (void*)c2, sz);
};

template<typename T>
void copyObject(T* object1, T* object2, unsigned int sz ) {
  if(!is_ptr<T>::value) {
    std::memcpy(&object2,&object1, sz);
  }
  std::memcpy((void*)object2, (void*)object1, sz);
};


//A template function to copy vector
template<typename InputIterator, typename T>
void copyVector(InputIterator& it, InputIterator& end ,T* vectorObj) {  
  for (; it != end; ++it) {
    vectorObj->push_back(*it);
  }
};

#endif




//%% NEW FILE User.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#define DEF__USER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <User.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <User.h>
#include <Stand.h>
#include <Vote.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
User::User(const string aId, Stand* aStand):
		stand(NULL){
  this->id= aId;
  this->votes= new vector<Vote*>();
  if (!setStand(aStand)){
    throw "Unable to create User due to aStand";
  }  
}

User::User(User& other):
		stand(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void User::toOstream(ostream& os) const{
  User* thisptr = const_cast<User*>(this);
  os << "[" << "id:" << thisptr->getId() << "]" << endl;
  (thisptr->getVotes()!= NULL ?  os << "votes:" << thisptr->getVotes() : os << "votes:" << "NULL")<< endl;
      (thisptr->getStand()!= NULL ?  os << "stand:" << thisptr->getStand() : os << "stand:" << "NULL");  
}

ostream& operator<<(ostream& os, const User& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (User& Right, User& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.id.compare(Left.id) != 0){
     return false;
  }
  if(!std::equal(Right.votes->begin(), Right.votes->end(), Left.votes->begin())){
     return false;
  }
  if(!compare(Right.stand, Left.stand, sizeof Right.stand)){
    return false;
  }  
}

User& User::operator=(User& other){
  internalCopy(other);
  return *this;  
}

void User::internalCopy(User& other){
  this->id.assign(other.id);
  this->votes = new vector<Vote*>();
  vector<Vote*>::iterator votesBeginIterator(other.votes->begin());
  vector<Vote*>::iterator votesEndIterator(other.votes->end());
  copyVector(votesBeginIterator, votesEndIterator, this->votes);
  copyObject(other.stand, this->stand, sizeof other.stand);  
}

bool User::setId(const string aNewId){
  bool wasSet= false;
  this->id = aNewId;
  wasSet= true;
  return wasSet;  
}

bool User::setStand(Stand* aNewStand){
  bool wasSet= false;
  if (aNewStand == NULL){
    return wasSet;
  }
  
  Stand* existingStand = this->stand;
  this->stand = aNewStand;
  
  if (existingStand != NULL && existingStand != aNewStand){
      existingStand->removeUser(this);
  }
  this->stand->addUser(this);
  wasSet = true;
  return wasSet;  
}

// line 0 ""
string User::getId(void) const{
  return this->id;  
}

// line 0 ""
Stand* User::getStand(void){
  return this->stand;  
}

// line 0 ""
int User::minimumNumberOfVotes() const{
  //TODO Add code body to minimumNumberOfVotes
  return 0;  
}

// line 0 ""
int User::numberOfVotes(void) const{
  int number=this->votes->size();
  return number;  
}

// line 0 ""
bool User::hasVotes() const{
  //TODO Add code body to hasVotes
  return NULL;  
}

// line 0 ""
bool User::addVote(Vote* aVote) const{
  //TODO Add code body to addVote
  return NULL;  
}

// line 0 ""
bool User::removeVote(Vote* aVote) const{
  bool wasRemoved= false;
  int index= IndexOf(this->votes->begin(), this->votes->end(), aVote);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aVote, as it must always have a User
  if (this== aVote->getUser()){
      return wasRemoved;
  }
  wasRemoved= this->removeVoteAt(index);
  return wasRemoved;  
}

// line 0 ""
int User::indexOfVote(Vote* aVote) const{
  return IndexOf(this->votes->begin(), this->votes->end(), aVote);  
}

// line 0 ""
bool User::addVoteAt(Vote* aVote, const int index) const{
  bool wasAdded= false;
  if(addVote(aNewVote)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfVotes();
      if(size>0){
          this->votes->erase(this->votes->begin()+IndexOf(this->votes->begin(), this->votes->end(),aNewVote));    
      }
    
      size= this->numberOfVotes();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->votes->insert(this->votes->begin()+ newIndex, aNewVote);
      wasAdded = true;
  }
  return wasAdded;  
}

// line 0 ""
bool User::addOrMoveVoteAt(Vote* aVote, const int index) const{
  //TODO Add code body to addOrMoveVoteAt
  return NULL;  
}

// line 0 ""
Vote* User::getVote(const int index){
  Vote* aVote= (*(this->votes))[index];
  return aVote;  
}

// line 0 ""
vector<Vote*>* User::getVotes(void){
  vector<Vote*>* copyOfVotes = new vector<Vote*>();
  vector<Vote*>::iterator votesBeginIterator(this->votes->begin());
  vector<Vote*>::iterator votesEndIterator(this->votes->end());
  copyVector(votesBeginIterator, votesEndIterator, copyOfVotes);
  return copyOfVotes;  
}

bool User::hasVote(void){
  return this->numberOfVotes()>0;  
}

bool User::removeVoteAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfVotes();
  if(index> size){
      return false;
  }
  this->votes->erase(this->votes->begin()+index);
  wasRemoved= size== this->numberOfVotes()+1;
  return wasRemoved;  
}

bool User::addVote(Vote* aNewVote){
  bool wasAdded= false;
  if (IndexOf(this->votes->begin(), this->votes->end(), aNewVote)> -1) {
    return wasAdded;
  }
  User* existingUser = aNewVote->getUser();
  bool isNewUser= existingUser != NULL && this!=existingUser;
  if(isNewUser){
    aNewVote->setUser(this);
  }else{
    this->votes->push_back(aNewVote);
  }
  wasAdded= true;
  return wasAdded;  
}

bool User::addOrMoveVoteAt(Vote* aNewVote, int index){
  bool wasAdded= false;
  if(IndexOf(this->votes->begin(), this->votes->end(), aNewVote) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfVotes();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeVote(aNewVote)| this->addVoteAt(aNewVote, index);
  }else{
    wasAdded= this->addVoteAt(aNewVote, index);
  }
  
  return wasAdded;  
}

Vote* User::addVote(const int aScore, const string aTime, Stand* aStand){
  return new Vote(aScore, aTime, aStand, this);  
}

size_t User::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
User::~User(){
  this->deleteAssociatedObjects();
  
  std::for_each(votes->begin(), votes->end(), /*std::default_delete<Vote>*/ deleteElement());
  votes->clear();
  delete votes;
  delete stand;  
}

void User::deleteAssociatedObjects(void){
  for(unsigned int index = votes->size(); index > 0 ; index--){
    Vote* aVote= (*(this->votes))[index-1];
    aVote->deleteAssociatedObjects();
  }
  Stand* placeholderStand = this->stand;
  this->stand = NULL;
  placeholderStand->removeUser(this);  
}
;





//%% NEW FILE Stand.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#define DEF__STAND_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Stand.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Stand.h>
#include <Vote.h>
#include <User.h>
#include <Statistics.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Stand::Stand(const string aNr, const int aTotalScore, Statistics* aStatistics):
		statistics(NULL){
  this->nr= aNr;
  this->totalScore= aTotalScore;
  this->votes= new vector<Vote*>();
  this->users= new vector<User*>();
  if (!setStatistic(aStatistic)){
    throw "Unable to create Stand due to aStatistic";
  }  
}

Stand::Stand(Stand& other):
		statistics(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Stand::toOstream(ostream& os) const{
  Stand* thisptr = const_cast<Stand*>(this);
  os << "[" << "nr:" << thisptr->getNr()<< ", " <<
      "totalScore:" << thisptr->getTotalScore() << "]" << endl;
  (thisptr->getVotes()!= NULL ?  os << "votes:" << thisptr->getVotes() : os << "votes:" << "NULL")<< endl;
      (thisptr->getUsers()!= NULL ?  os << "users:" << thisptr->getUsers() : os << "users:" << "NULL")<< endl;
      (thisptr->getStatistic()!= NULL ?  os << "statistics:" << thisptr->getStatistic() : os << "statistics:" << "NULL");  
}

ostream& operator<<(ostream& os, const Stand& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Stand& Right, Stand& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.nr.compare(Left.nr) != 0){
     return false;
  }
  if(Right.totalScore!= Left.totalScore){
     return false;
  }
  if(!std::equal(Right.votes->begin(), Right.votes->end(), Left.votes->begin())){
     return false;
  }
  if(!std::equal(Right.users->begin(), Right.users->end(), Left.users->begin())){
     return false;
  }
  if(!compare(Right.statistics, Left.statistics, sizeof Right.statistics)){
    return false;
  }  
}

Stand& Stand::operator=(Stand& other){
  internalCopy(other);
  return *this;  
}

void Stand::internalCopy(Stand& other){
  this->nr.assign(other.nr);
  this->totalScore= other.totalScore;
  this->votes = new vector<Vote*>();
  vector<Vote*>::iterator votesBeginIterator(other.votes->begin());
  vector<Vote*>::iterator votesEndIterator(other.votes->end());
  copyVector(votesBeginIterator, votesEndIterator, this->votes);
  this->users = new vector<User*>();
  vector<User*>::iterator usersBeginIterator(other.users->begin());
  vector<User*>::iterator usersEndIterator(other.users->end());
  copyVector(usersBeginIterator, usersEndIterator, this->users);
  copyObject(other.statistics, this->statistics, sizeof other.statistics);  
}

bool Stand::setNr(const string aNewNr){
  bool wasSet= false;
  this->nr = aNewNr;
  wasSet= true;
  return wasSet;  
}

bool Stand::setTotalScore(const int aNewTotalScore){
  bool wasSet= false;
  this->totalScore = aNewTotalScore;
  wasSet= true;
  return wasSet;  
}

bool Stand::setStatistic(Statistics* aNewStatistic){
  bool wasSet= false;
  if (aNewStatistic == NULL){
    return wasSet;
  }
  
  Statistics* existingStatistics = this->statistics;
  this->statistics = aNewStatistic;
  
  if (existingStatistics != NULL && existingStatistics != aNewStatistic){
      existingStatistics->removeStand(this);
  }
  this->statistics->addStand(this);
  wasSet = true;
  return wasSet;  
}

// line 0 ""
string Stand::getNr(void) const{
  return this->nr;  
}

// line 0 ""
int Stand::getTotalScore(void) const{
  return this->totalScore;  
}

// line 0 ""
int Stand::minimumNumberOfVotes() const{
  //TODO Add code body to minimumNumberOfVotes
  return 0;  
}

// line 0 ""
int Stand::numberOfVotes(void) const{
  int number=this->votes->size();
  return number;  
}

// line 0 ""
bool Stand::hasVotes() const{
  //TODO Add code body to hasVotes
  return NULL;  
}

// line 0 ""
bool Stand::addVote(Vote* aVote) const{
  //TODO Add code body to addVote
  return NULL;  
}

// line 0 ""
bool Stand::removeVote(Vote* aVote) const{
  bool wasRemoved= false;
  int index= IndexOf(this->votes->begin(), this->votes->end(), aVote);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aVote, as it must always have a Stand
  if (this== aVote->getStand()){
      return wasRemoved;
  }
  wasRemoved= this->removeVoteAt(index);
  return wasRemoved;  
}

// line 0 ""
int Stand::indexOfVote(Vote* aVote) const{
  return IndexOf(this->votes->begin(), this->votes->end(), aVote);  
}

// line 0 ""
bool Stand::addVoteAt(Vote* aVote, const int index) const{
  bool wasAdded= false;
  if(addVote(aNewVote)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfVotes();
      if(size>0){
          this->votes->erase(this->votes->begin()+IndexOf(this->votes->begin(), this->votes->end(),aNewVote));    
      }
    
      size= this->numberOfVotes();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->votes->insert(this->votes->begin()+ newIndex, aNewVote);
      wasAdded = true;
  }
  return wasAdded;  
}

// line 0 ""
bool Stand::addOrMoveVoteAt(Vote* aVote, const int index) const{
  //TODO Add code body to addOrMoveVoteAt
  return NULL;  
}

// line 0 ""
Vote* Stand::getVote(const int index){
  Vote* aVote= (*(this->votes))[index];
  return aVote;  
}

// line 0 ""
vector<Vote*>* Stand::getVotes(void){
  vector<Vote*>* copyOfVotes = new vector<Vote*>();
  vector<Vote*>::iterator votesBeginIterator(this->votes->begin());
  vector<Vote*>::iterator votesEndIterator(this->votes->end());
  copyVector(votesBeginIterator, votesEndIterator, copyOfVotes);
  return copyOfVotes;  
}

// line 0 ""
int Stand::minimumNumberOfUsers() const{
  //TODO Add code body to minimumNumberOfUsers
  return 0;  
}

// line 0 ""
int Stand::numberOfUsers(void) const{
  int number=this->users->size();
  return number;  
}

// line 0 ""
bool Stand::hasUsers() const{
  //TODO Add code body to hasUsers
  return NULL;  
}

// line 0 ""
bool Stand::addUser(User* aUser) const{
  //TODO Add code body to addUser
  return NULL;  
}

// line 0 ""
bool Stand::removeUser(User* aUser) const{
  bool wasRemoved= false;
  int index= IndexOf(this->users->begin(), this->users->end(), aUser);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aUser, as it must always have a Stand
  if (this== aUser->getStand()){
      return wasRemoved;
  }
  wasRemoved= this->removeUserAt(index);
  return wasRemoved;  
}

// line 0 ""
int Stand::indexOfUser(User* aUser) const{
  return IndexOf(this->users->begin(), this->users->end(), aUser);  
}

// line 0 ""
bool Stand::addUserAt(User* aUser, const int index) const{
  bool wasAdded= false;
  if(addUser(aNewUser)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfUsers();
      if(size>0){
          this->users->erase(this->users->begin()+IndexOf(this->users->begin(), this->users->end(),aNewUser));    
      }
    
      size= this->numberOfUsers();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->users->insert(this->users->begin()+ newIndex, aNewUser);
      wasAdded = true;
  }
  return wasAdded;  
}

// line 0 ""
bool Stand::addOrMoveUserAt(User* aUser, const int index) const{
  //TODO Add code body to addOrMoveUserAt
  return NULL;  
}

// line 0 ""
User* Stand::getUser(const int index){
  User* aUser= (*(this->users))[index];
  return aUser;  
}

// line 0 ""
vector<User*>* Stand::getUsers(void){
  vector<User*>* copyOfUsers = new vector<User*>();
  vector<User*>::iterator usersBeginIterator(this->users->begin());
  vector<User*>::iterator usersEndIterator(this->users->end());
  copyVector(usersBeginIterator, usersEndIterator, copyOfUsers);
  return copyOfUsers;  
}

// line 0 ""
Statistics* Stand::getStatistics(){
  //TODO Add code body to getStatistics
  return NULL;  
}

// line 0 ""
bool Stand::setStatistics(Statistic aStatistics) const{
  //TODO Add code body to setStatistics
  return NULL;  
}

bool Stand::hasVote(void){
  return this->numberOfVotes()>0;  
}

bool Stand::removeVoteAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfVotes();
  if(index> size){
      return false;
  }
  this->votes->erase(this->votes->begin()+index);
  wasRemoved= size== this->numberOfVotes()+1;
  return wasRemoved;  
}

bool Stand::addVote(Vote* aNewVote){
  bool wasAdded= false;
  if (IndexOf(this->votes->begin(), this->votes->end(), aNewVote)> -1) {
    return wasAdded;
  }
  Stand* existingStand = aNewVote->getStand();
  bool isNewStand= existingStand != NULL && this!=existingStand;
  if(isNewStand){
    aNewVote->setStand(this);
  }else{
    this->votes->push_back(aNewVote);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Stand::addOrMoveVoteAt(Vote* aNewVote, int index){
  bool wasAdded= false;
  if(IndexOf(this->votes->begin(), this->votes->end(), aNewVote) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfVotes();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeVote(aNewVote)| this->addVoteAt(aNewVote, index);
  }else{
    wasAdded= this->addVoteAt(aNewVote, index);
  }
  
  return wasAdded;  
}

Vote* Stand::addVote(const int aScore, const string aTime, User* aUser){
  return new Vote(aScore, aTime, this, aUser);  
}

bool Stand::hasUser(void){
  return this->numberOfUsers()>0;  
}

bool Stand::removeUserAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfUsers();
  if(index> size){
      return false;
  }
  this->users->erase(this->users->begin()+index);
  wasRemoved= size== this->numberOfUsers()+1;
  return wasRemoved;  
}

bool Stand::addUser(User* aNewUser){
  bool wasAdded= false;
  if (IndexOf(this->users->begin(), this->users->end(), aNewUser)> -1) {
    return wasAdded;
  }
  Stand* existingStand = aNewUser->getStand();
  bool isNewStand= existingStand != NULL && this!=existingStand;
  if(isNewStand){
    aNewUser->setStand(this);
  }else{
    this->users->push_back(aNewUser);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Stand::addOrMoveUserAt(User* aNewUser, int index){
  bool wasAdded= false;
  if(IndexOf(this->users->begin(), this->users->end(), aNewUser) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfUsers();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeUser(aNewUser)| this->addUserAt(aNewUser, index);
  }else{
    wasAdded= this->addUserAt(aNewUser, index);
  }
  
  return wasAdded;  
}

User* Stand::addUser(const string aId){
  return new User(aId, this);  
}

Statistics* Stand::getStatistic(void){
  return this->statistics;  
}

size_t Stand::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Stand::~Stand(){
  this->deleteAssociatedObjects();
  
  std::for_each(votes->begin(), votes->end(), /*std::default_delete<Vote>*/ deleteElement());
  votes->clear();
  delete votes;
  
  std::for_each(users->begin(), users->end(), /*std::default_delete<User>*/ deleteElement());
  users->clear();
  delete users;
  delete statistics;  
}

void Stand::deleteAssociatedObjects(void){
  for(unsigned int index = votes->size(); index > 0 ; index--){
    Vote* aVote= (*(this->votes))[index-1];
    aVote->deleteAssociatedObjects();
  }
  for(unsigned int index = users->size(); index > 0 ; index--){
    User* aUser= (*(this->users))[index-1];
    aUser->deleteAssociatedObjects();
  }
  Statistics* placeholderStatistics = this->statistics;
  this->statistics = NULL;
  placeholderStatistics->removeStand(this);  
}
;





//%% NEW FILE CMakeLists.txt BEGINS HERE %%

cmake_minimum_required(VERSION 3.0)
project(model)

set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR})


set(SOURCE_FILES
model_Model.h
model_Main.cpp
Stand.h
Stand.cpp
Vote.h
Vote.cpp
User.h
User.cpp
Jury.h
Jury.cpp
Statistics.h
Statistics.cpp)

add_executable(model ${SOURCE_FILES})



//%% NEW FILE Vote.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#define DEF__VOTE_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Vote.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Vote.h>
#include <Stand.h>
#include <User.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Vote::Vote(const int aScore, const string aTime, Stand* aStand, User* aUser):
		stand(NULL),
		user(NULL){
  this->score= aScore;
  this->time= aTime;
  if (!setStand(aStand)){
    throw "Unable to create Vote due to aStand";
  }
  if (!setUser(aUser)){
    throw "Unable to create Vote due to aUser";
  }  
}

Vote::Vote(Vote& other):
		stand(NULL),
		user(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Vote::toOstream(ostream& os) const{
  Vote* thisptr = const_cast<Vote*>(this);
  os << "[" << "score:" << thisptr->getScore()<< ", " <<
      "time:" << thisptr->getTime() << "]" << endl;
  (thisptr->getStand()!= NULL ?  os << "stand:" << thisptr->getStand() : os << "stand:" << "NULL")<< endl;
      (thisptr->getUser()!= NULL ?  os << "user:" << thisptr->getUser() : os << "user:" << "NULL");  
}

ostream& operator<<(ostream& os, const Vote& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Vote& Right, Vote& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.score!= Left.score){
     return false;
  }
  if(Right.time.compare(Left.time) != 0){
     return false;
  }
  if(!compare(Right.stand, Left.stand, sizeof Right.stand)){
    return false;
  }
  if(!compare(Right.user, Left.user, sizeof Right.user)){
    return false;
  }  
}

Vote& Vote::operator=(Vote& other){
  internalCopy(other);
  return *this;  
}

void Vote::internalCopy(Vote& other){
  this->score= other.score;
  this->time.assign(other.time);
  copyObject(other.stand, this->stand, sizeof other.stand);
  copyObject(other.user, this->user, sizeof other.user);  
}

bool Vote::setScore(const int aNewScore){
  bool wasSet= false;
  this->score = aNewScore;
  wasSet= true;
  return wasSet;  
}

bool Vote::setTime(const string aNewTime){
  bool wasSet= false;
  this->time = aNewTime;
  wasSet= true;
  return wasSet;  
}

bool Vote::setStand(Stand* aNewStand){
  bool wasSet= false;
  if (aNewStand == NULL){
    return wasSet;
  }
  
  Stand* existingStand = this->stand;
  this->stand = aNewStand;
  
  if (existingStand != NULL && existingStand != aNewStand){
      existingStand->removeVote(this);
  }
  this->stand->addVote(this);
  wasSet = true;
  return wasSet;  
}

bool Vote::setUser(User* aNewUser){
  bool wasSet= false;
  if (aNewUser == NULL){
    return wasSet;
  }
  
  User* existingUser = this->user;
  this->user = aNewUser;
  
  if (existingUser != NULL && existingUser != aNewUser){
      existingUser->removeVote(this);
  }
  this->user->addVote(this);
  wasSet = true;
  return wasSet;  
}

// line 0 ""
int Vote::getScore(void) const{
  return this->score;  
}

// line 0 ""
string Vote::getTime(void) const{
  return this->time;  
}

// line 0 ""
Stand* Vote::getStand(void){
  return this->stand;  
}

// line 0 ""
User* Vote::getUser(void){
  return this->user;  
}

size_t Vote::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Vote::~Vote(){
  this->deleteAssociatedObjects();
  delete stand;
  delete user;  
}

void Vote::deleteAssociatedObjects(void){
  Stand* placeholderStand = this->stand;
  this->stand = NULL;
  placeholderStand->removeVote(this);
  User* placeholderUser = this->user;
  this->user = NULL;
  placeholderUser->removeVote(this);  
}
;





//%% NEW FILE Stand.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__STAND_H
#define DEF__STAND_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Stand.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Stand.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Vote;
class User;
class Statistics;
/*
 * Positioning
 */
// line 2 "model.ump"
// line 39 "model.ump"
class Stand{
	
	private:
		
		//Stand Attributes
		string nr;
		int totalScore;
		//Stand Associations
		// line 6 "model.ump"
		vector<Vote*>* votes;
		// line 7 "model.ump"
		vector<User*>* users;
		// line 32 "model.ump"
		Statistics* statistics;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Stand(const string aNr, const int aTotalScore, Statistics* aStatistics);
		Stand(Stand& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Stand& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Stand& Right, Stand& Left);
		friend bool operator != (Stand& Right, Stand& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Stand& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Stand& Right) const{
		  return this != &Right;  
		}
		Stand& operator=(Stand& other);
		
		void internalCopy(Stand& other);
		bool setNr(const string aNewNr);
		bool setTotalScore(const int aNewTotalScore);
		bool setStatistic(Statistics* aNewStatistic);
		inline unsigned int minimumNumberOfStatistics(void){
		  return 1;  
		}
		// line 0 ""
		string getNr(void) const;
		// line 0 ""
		int getTotalScore(void) const;
		// line 0 ""
		int minimumNumberOfVotes() const;
		// line 0 ""
		int numberOfVotes(void) const;
		// line 0 ""
		bool hasVotes() const;
		// line 0 ""
		bool addVote(Vote* aVote) const;
		// line 0 ""
		bool removeVote(Vote* aVote) const;
		// line 0 ""
		int indexOfVote(Vote* aVote) const;
		// line 0 ""
		bool addVoteAt(Vote* aVote, const int index) const;
		// line 0 ""
		bool addOrMoveVoteAt(Vote* aVote, const int index) const;
		// line 0 ""
		Vote* getVote(const int index);
		// line 0 ""
		vector<Vote*>* getVotes(void);
		// line 0 ""
		int minimumNumberOfUsers() const;
		// line 0 ""
		int numberOfUsers(void) const;
		// line 0 ""
		bool hasUsers() const;
		// line 0 ""
		bool addUser(User* aUser) const;
		// line 0 ""
		bool removeUser(User* aUser) const;
		// line 0 ""
		int indexOfUser(User* aUser) const;
		// line 0 ""
		bool addUserAt(User* aUser, const int index) const;
		// line 0 ""
		bool addOrMoveUserAt(User* aUser, const int index) const;
		// line 0 ""
		User* getUser(const int index);
		// line 0 ""
		vector<User*>* getUsers(void);
		// line 0 ""
		Statistics* getStatistics();
		// line 0 ""
		bool setStatistics(Statistic aStatistics) const;
		bool hasVote(void);
		bool removeVoteAt(int index);
		bool addVote(Vote* aNewVote);
		bool addOrMoveVoteAt(Vote* aNewVote, int index);
		Vote* addVote(const int aScore, const string aTime, User* aUser);
		bool hasUser(void);
		bool removeUserAt(int index);
		bool addUser(User* aNewUser);
		bool addOrMoveUserAt(User* aNewUser, int index);
		User* addUser(const string aId);
		Statistics* getStatistic(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Stand();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
using namespace __gnu_cxx;
namespace __gnu_cxx{
  template<> struct hash<Stand*>{
    size_t operator()(Stand* ptr ) const {
        return ptr->hashCode();
    }
  };
}
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#endif



//%% NEW FILE User.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__USER_H
#define DEF__USER_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "User.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <User.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Stand;
class Vote;
// line 16 "model.ump"
// line 52 "model.ump"
class User{
	
	private:
		
		//User Attributes
		string id;
		//User Associations
		// line 19 "model.ump"
		vector<Vote*>* votes;
		// line 7 "model.ump"
		Stand* stand;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		User(const string aId, Stand* aStand);
		User(User& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const User& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (User& Right, User& Left);
		friend bool operator != (User& Right, User& Left){
		  return !( Right == Left);  
		}
		bool operator == (const User& Right) const{
		  return this == &Right;  
		}
		bool operator != (const User& Right) const{
		  return this != &Right;  
		}
		User& operator=(User& other);
		
		void internalCopy(User& other);
		bool setId(const string aNewId);
		bool setStand(Stand* aNewStand);
		inline unsigned int minimumNumberOfStands(void){
		  return 1;  
		}
		// line 0 ""
		string getId(void) const;
		// line 0 ""
		Stand* getStand(void);
		// line 0 ""
		int minimumNumberOfVotes() const;
		// line 0 ""
		int numberOfVotes(void) const;
		// line 0 ""
		bool hasVotes() const;
		// line 0 ""
		bool addVote(Vote* aVote) const;
		// line 0 ""
		bool removeVote(Vote* aVote) const;
		// line 0 ""
		int indexOfVote(Vote* aVote) const;
		// line 0 ""
		bool addVoteAt(Vote* aVote, const int index) const;
		// line 0 ""
		bool addOrMoveVoteAt(Vote* aVote, const int index) const;
		// line 0 ""
		Vote* getVote(const int index);
		// line 0 ""
		vector<Vote*>* getVotes(void);
		bool hasVote(void);
		bool removeVoteAt(int index);
		bool addVote(Vote* aNewVote);
		bool addOrMoveVoteAt(Vote* aNewVote, int index);
		Vote* addVote(const int aScore, const string aTime, Stand* aStand);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~User();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
using namespace __gnu_cxx;
namespace __gnu_cxx{
  template<> struct hash<User*>{
    size_t operator()(User* ptr ) const {
        return ptr->hashCode();
    }
  };
}
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#endif



//%% NEW FILE Vote.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__VOTE_H
#define DEF__VOTE_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Vote.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Vote.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Stand;
class User;
// line 10 "model.ump"
// line 47 "model.ump"
class Vote{
	
	private:
		
		//Vote Attributes
		int score;
		string time;
		//Vote Associations
		// line 6 "model.ump"
		Stand* stand;
		// line 19 "model.ump"
		User* user;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Vote(const int aScore, const string aTime, Stand* aStand, User* aUser);
		Vote(Vote& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Vote& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Vote& Right, Vote& Left);
		friend bool operator != (Vote& Right, Vote& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Vote& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Vote& Right) const{
		  return this != &Right;  
		}
		Vote& operator=(Vote& other);
		
		void internalCopy(Vote& other);
		bool setScore(const int aNewScore);
		bool setTime(const string aNewTime);
		bool setStand(Stand* aNewStand);
		inline unsigned int minimumNumberOfStands(void){
		  return 1;  
		}
		bool setUser(User* aNewUser);
		inline unsigned int minimumNumberOfUsers(void){
		  return 1;  
		}
		// line 0 ""
		int getScore(void) const;
		// line 0 ""
		string getTime(void) const;
		// line 0 ""
		Stand* getStand(void);
		// line 0 ""
		User* getUser(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Vote();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
using namespace __gnu_cxx;
namespace __gnu_cxx{
  template<> struct hash<Vote*>{
    size_t operator()(Vote* ptr ) const {
        return ptr->hashCode();
    }
  };
}
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#endif



//%% NEW FILE Statistics.h BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#ifndef DEF__STATISTICS_H
#define DEF__STATISTICS_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Statistics.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Statistics.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Stand;
class Jury;
// line 28 "model.ump"
// line 65 "model.ump"
class Statistics{
	
	private:
		
		//Statistics Attributes
		string password;
		//Statistics Associations
		// line 32 "model.ump"
		vector<Stand*>* stands;
		// line 33 "model.ump"
		vector<Jury*>* juries;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Statistics(const string aPassword);
		Statistics(Statistics& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Statistics& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Statistics& Right, Statistics& Left);
		friend bool operator != (Statistics& Right, Statistics& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Statistics& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Statistics& Right) const{
		  return this != &Right;  
		}
		Statistics& operator=(Statistics& other);
		
		void internalCopy(Statistics& other);
		bool setPassword(const string aNewPassword);
		// line 0 ""
		string getPassword(void) const;
		// line 0 ""
		int minimumNumberOfStands() const;
		// line 0 ""
		int numberOfStands(void) const;
		// line 0 ""
		bool hasStands() const;
		// line 0 ""
		bool addStand(Stand* aStand) const;
		// line 0 ""
		bool removeStand(Stand* aStand) const;
		// line 0 ""
		int indexOfStand(Stand* aStand) const;
		// line 0 ""
		bool addStandAt(Stand* aStand, const int index) const;
		// line 0 ""
		bool addOrMoveStandAt(Stand* aStand, const int index) const;
		// line 0 ""
		Stand* getStand(const int index);
		// line 0 ""
		vector<Stand*>* getStands(void);
		// line 0 ""
		int minimumNumberOfJuries() const;
		// line 0 ""
		int numberOfJuries(void) const;
		// line 0 ""
		bool hasJuries() const;
		// line 0 ""
		bool addJury(Jury* aJury) const;
		// line 0 ""
		bool removeJury(Jury* aJury) const;
		// line 0 ""
		int indexOfJury(Jury* aJury) const;
		// line 0 ""
		bool addJuryAt(Jury* aJury, const int index) const;
		// line 0 ""
		bool addOrMoveJuryAt(Jury* aJury, const int index) const;
		// line 0 ""
		Jury* getJury(const int index);
		// line 0 ""
		vector<Jury*>* getJuries(void);
		bool hasStand(void);
		bool removeStandAt(int index);
		bool addStand(Stand* aNewStand);
		bool addOrMoveStandAt(Stand* aNewStand, int index);
		Stand* addStand(const string aNr, const int aTotalScore);
		bool hasJury(void);
		bool removeJuryAt(int index);
		bool addJury(Jury* aNewJury);
		bool addOrMoveJuryAt(Jury* aNewJury, int index);
		Jury* addJury(const string aId, Stand* aStand);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Statistics();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
using namespace __gnu_cxx;
namespace __gnu_cxx{
  template<> struct hash<Statistics*>{
    size_t operator()(Statistics* ptr ) const {
        return ptr->hashCode();
    }
  };
}
#include <ext/hash_map>
#else
#include <hash_map>
#endif
#endif



//%% NEW FILE Statistics.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#define DEF__STATISTICS_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Statistics.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Statistics.h>
#include <Stand.h>
#include <Jury.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Statistics::Statistics(const string aPassword){
  this->password= aPassword;
  this->stands= new vector<Stand*>();
  this->juries= new vector<Jury*>();  
}

Statistics::Statistics(Statistics& other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Statistics::toOstream(ostream& os) const{
  Statistics* thisptr = const_cast<Statistics*>(this);
  os << "[" << "password:" << thisptr->getPassword() << "]" << endl;
  (thisptr->getStands()!= NULL ?  os << "stands:" << thisptr->getStands() : os << "stands:" << "NULL")<< endl;
      (thisptr->getJuries()!= NULL ?  os << "juries:" << thisptr->getJuries() : os << "juries:" << "NULL");  
}

ostream& operator<<(ostream& os, const Statistics& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Statistics& Right, Statistics& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.password.compare(Left.password) != 0){
     return false;
  }
  if(!std::equal(Right.stands->begin(), Right.stands->end(), Left.stands->begin())){
     return false;
  }
  if(!std::equal(Right.juries->begin(), Right.juries->end(), Left.juries->begin())){
     return false;
  }  
}

Statistics& Statistics::operator=(Statistics& other){
  internalCopy(other);
  return *this;  
}

void Statistics::internalCopy(Statistics& other){
  this->password.assign(other.password);
  this->stands = new vector<Stand*>();
  vector<Stand*>::iterator standsBeginIterator(other.stands->begin());
  vector<Stand*>::iterator standsEndIterator(other.stands->end());
  copyVector(standsBeginIterator, standsEndIterator, this->stands);
  this->juries = new vector<Jury*>();
  vector<Jury*>::iterator juriesBeginIterator(other.juries->begin());
  vector<Jury*>::iterator juriesEndIterator(other.juries->end());
  copyVector(juriesBeginIterator, juriesEndIterator, this->juries);  
}

bool Statistics::setPassword(const string aNewPassword){
  bool wasSet= false;
  this->password = aNewPassword;
  wasSet= true;
  return wasSet;  
}

// line 0 ""
string Statistics::getPassword(void) const{
  return this->password;  
}

// line 0 ""
int Statistics::minimumNumberOfStands() const{
  //TODO Add code body to minimumNumberOfStands
  return 0;  
}

// line 0 ""
int Statistics::numberOfStands(void) const{
  int number=this->stands->size();
  return number;  
}

// line 0 ""
bool Statistics::hasStands() const{
  //TODO Add code body to hasStands
  return NULL;  
}

// line 0 ""
bool Statistics::addStand(Stand* aStand) const{
  //TODO Add code body to addStand
  return NULL;  
}

// line 0 ""
bool Statistics::removeStand(Stand* aStand) const{
  bool wasRemoved= false;
  int index= IndexOf(this->stands->begin(), this->stands->end(), aStand);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aStand, as it must always have a Statistics
  if (this== aStand->getStatistic()){
      return wasRemoved;
  }
  wasRemoved= this->removeStandAt(index);
  return wasRemoved;  
}

// line 0 ""
int Statistics::indexOfStand(Stand* aStand) const{
  return IndexOf(this->stands->begin(), this->stands->end(), aStand);  
}

// line 0 ""
bool Statistics::addStandAt(Stand* aStand, const int index) const{
  bool wasAdded= false;
  if(addStand(aNewStand)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfStands();
      if(size>0){
          this->stands->erase(this->stands->begin()+IndexOf(this->stands->begin(), this->stands->end(),aNewStand));    
      }
    
      size= this->numberOfStands();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->stands->insert(this->stands->begin()+ newIndex, aNewStand);
      wasAdded = true;
  }
  return wasAdded;  
}

// line 0 ""
bool Statistics::addOrMoveStandAt(Stand* aStand, const int index) const{
  //TODO Add code body to addOrMoveStandAt
  return NULL;  
}

// line 0 ""
Stand* Statistics::getStand(const int index){
  Stand* aStand= (*(this->stands))[index];
  return aStand;  
}

// line 0 ""
vector<Stand*>* Statistics::getStands(void){
  vector<Stand*>* copyOfStands = new vector<Stand*>();
  vector<Stand*>::iterator standsBeginIterator(this->stands->begin());
  vector<Stand*>::iterator standsEndIterator(this->stands->end());
  copyVector(standsBeginIterator, standsEndIterator, copyOfStands);
  return copyOfStands;  
}

// line 0 ""
int Statistics::minimumNumberOfJuries() const{
  //TODO Add code body to minimumNumberOfJuries
  return 0;  
}

// line 0 ""
int Statistics::numberOfJuries(void) const{
  int number=this->juries->size();
  return number;  
}

// line 0 ""
bool Statistics::hasJuries() const{
  //TODO Add code body to hasJuries
  return NULL;  
}

// line 0 ""
bool Statistics::addJury(Jury* aJury) const{
  //TODO Add code body to addJury
  return NULL;  
}

// line 0 ""
bool Statistics::removeJury(Jury* aJury) const{
  bool wasRemoved= false;
  int index= IndexOf(this->juries->begin(), this->juries->end(), aJury);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aJury, as it must always have a Statistics
  if (this== aJury->getStatistic()){
      return wasRemoved;
  }
  wasRemoved= this->removeJuryAt(index);
  return wasRemoved;  
}

// line 0 ""
int Statistics::indexOfJury(Jury* aJury) const{
  return IndexOf(this->juries->begin(), this->juries->end(), aJury);  
}

// line 0 ""
bool Statistics::addJuryAt(Jury* aJury, const int index) const{
  bool wasAdded= false;
  if(addJury(aNewJury)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfJuries();
      if(size>0){
          this->juries->erase(this->juries->begin()+IndexOf(this->juries->begin(), this->juries->end(),aNewJury));    
      }
    
      size= this->numberOfJuries();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->juries->insert(this->juries->begin()+ newIndex, aNewJury);
      wasAdded = true;
  }
  return wasAdded;  
}

// line 0 ""
bool Statistics::addOrMoveJuryAt(Jury* aJury, const int index) const{
  //TODO Add code body to addOrMoveJuryAt
  return NULL;  
}

// line 0 ""
Jury* Statistics::getJury(const int index){
  Jury* aJury= (*(this->juries))[index];
  return aJury;  
}

// line 0 ""
vector<Jury*>* Statistics::getJuries(void){
  vector<Jury*>* copyOfJuries = new vector<Jury*>();
  vector<Jury*>::iterator juriesBeginIterator(this->juries->begin());
  vector<Jury*>::iterator juriesEndIterator(this->juries->end());
  copyVector(juriesBeginIterator, juriesEndIterator, copyOfJuries);
  return copyOfJuries;  
}

bool Statistics::hasStand(void){
  return this->numberOfStands()>0;  
}

bool Statistics::removeStandAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfStands();
  if(index> size){
      return false;
  }
  this->stands->erase(this->stands->begin()+index);
  wasRemoved= size== this->numberOfStands()+1;
  return wasRemoved;  
}

bool Statistics::addStand(Stand* aNewStand){
  bool wasAdded= false;
  if (IndexOf(this->stands->begin(), this->stands->end(), aNewStand)> -1) {
    return wasAdded;
  }
  Statistics* existingStatistic = aNewStand->getStatistic();
  bool isNewStatistic= existingStatistic != NULL && this!=existingStatistic;
  if(isNewStatistic){
    aNewStand->setStatistic(this);
  }else{
    this->stands->push_back(aNewStand);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Statistics::addOrMoveStandAt(Stand* aNewStand, int index){
  bool wasAdded= false;
  if(IndexOf(this->stands->begin(), this->stands->end(), aNewStand) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfStands();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeStand(aNewStand)| this->addStandAt(aNewStand, index);
  }else{
    wasAdded= this->addStandAt(aNewStand, index);
  }
  
  return wasAdded;  
}

Stand* Statistics::addStand(const string aNr, const int aTotalScore){
  return new Stand(aNr, aTotalScore, this);  
}

bool Statistics::hasJury(void){
  return this->numberOfJuries()>0;  
}

bool Statistics::removeJuryAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfJuries();
  if(index> size){
      return false;
  }
  this->juries->erase(this->juries->begin()+index);
  wasRemoved= size== this->numberOfJuries()+1;
  return wasRemoved;  
}

bool Statistics::addJury(Jury* aNewJury){
  bool wasAdded= false;
  if (IndexOf(this->juries->begin(), this->juries->end(), aNewJury)> -1) {
    return wasAdded;
  }
  Statistics* existingStatistic = aNewJury->getStatistic();
  bool isNewStatistic= existingStatistic != NULL && this!=existingStatistic;
  if(isNewStatistic){
    aNewJury->setStatistic(this);
  }else{
    this->juries->push_back(aNewJury);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Statistics::addOrMoveJuryAt(Jury* aNewJury, int index){
  bool wasAdded= false;
  if(IndexOf(this->juries->begin(), this->juries->end(), aNewJury) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfJuries();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeJury(aNewJury)| this->addJuryAt(aNewJury, index);
  }else{
    wasAdded= this->addJuryAt(aNewJury, index);
  }
  
  return wasAdded;  
}

Jury* Statistics::addJury(const string aId, Stand* aStand){
  return new Jury(aId, aStand, this);  
}

size_t Statistics::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Statistics::~Statistics(){
  this->deleteAssociatedObjects();
  
  std::for_each(stands->begin(), stands->end(), /*std::default_delete<Stand>*/ deleteElement());
  stands->clear();
  delete stands;
  
  std::for_each(juries->begin(), juries->end(), /*std::default_delete<Jury>*/ deleteElement());
  juries->clear();
  delete juries;  
}

void Statistics::deleteAssociatedObjects(void){
  for(unsigned int index = stands->size(); index > 0 ; index--){
    Stand* aStand= (*(this->stands))[index-1];
    aStand->deleteAssociatedObjects();
  }
  for(unsigned int index = juries->size(); index > 0 ; index--){
    Jury* aJury= (*(this->juries))[index-1];
    aJury->deleteAssociatedObjects();
  }  
}
;





//%% NEW FILE Jury.cpp BEGINS HERE %%

//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.29.1.4448.81a70243a modeling language
#define DEF__JURY_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Jury.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Jury.h>
#include <User.h>
#include <Statistics.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Jury::Jury(const string aId, Stand* aStand, Statistics* aStatistics):
		statistics(NULL),
    User(aId, aStand){
  if (!setStatistic(aStatistic)){
    throw "Unable to create Jury due to aStatistic";
  }  
}

Jury::Jury(Jury& other):
		statistics(NULL),
    User(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Jury::toOstream(ostream& os) const{
  User::toOstream(os);
  Jury* thisptr = const_cast<Jury*>(this);
  (thisptr->getStatistic()!= NULL ?  os << "statistics:" << thisptr->getStatistic() : os << "statistics:" << "NULL");  
}

ostream& operator<<(ostream& os, const Jury& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Jury& Right, Jury& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(!compare(Right.statistics, Left.statistics, sizeof Right.statistics)){
    return false;
  }  
}

Jury& Jury::operator=(Jury& other){
  internalCopy(other);
  return *this;  
}

void Jury::internalCopy(Jury& other){
  copyObject(other.statistics, this->statistics, sizeof other.statistics);  
}

bool Jury::setStatistic(Statistics* aNewStatistic){
  bool wasSet= false;
  if (aNewStatistic == NULL){
    return wasSet;
  }
  
  Statistics* existingStatistics = this->statistics;
  this->statistics = aNewStatistic;
  
  if (existingStatistics != NULL && existingStatistics != aNewStatistic){
      existingStatistics->removeJury(this);
  }
  this->statistics->addJury(this);
  wasSet = true;
  return wasSet;  
}

// line 0 ""
Statistics* Jury::getStatistics(){
  //TODO Add code body to getStatistics
  return NULL;  
}

// line 0 ""
bool Jury::setStatistics(Statistic aStatistics) const{
  //TODO Add code body to setStatistics
  return NULL;  
}

Statistics* Jury::getStatistic(void){
  return this->statistics;  
}

size_t Jury::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Jury::~Jury(){
  //User::~User();
  this->deleteAssociatedObjects();
  delete statistics;  
}

void Jury::deleteAssociatedObjects(void){
  Statistics* placeholderStatistics = this->statistics;
  this->statistics = NULL;
  placeholderStatistics->removeJury(this);  
}
;
