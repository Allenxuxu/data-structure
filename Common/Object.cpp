#include "Object.h"
#include <cstdlib>

namespace XXLib
{
  void *Object::operator new(size_t size) throw()
  {
    return malloc(size);
  }

  void Object::operator delete(void *p)
  {
    free(p);
  }

  void* Object::operator new[](size_t size) throw()
  {
    return malloc(size);
  }

  void Object::operator delete[](void *p)
  {
    free(p);
  }

  bool Object::operator ==(const Object &obj)
  {
    return (this == &obj);
  }

  bool Object::operator !=(const Object &obj)
  {
    return (this != &obj);
  }

  Object::~Object()
  {

  }

}
