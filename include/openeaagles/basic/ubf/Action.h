//------------------------------------------------------------------------------
// Class: Action
//------------------------------------------------------------------------------
#ifndef __Eaagles_Basic_Action_H__
#define __Eaagles_Basic_Action_H__

#include "openeaagles/basic/Object.h"

namespace Eaagles {

namespace Basic {
   class Component;

//
// Class: Action
//
// Description:
//    Abstract base class for all Actions. They are responsible for
//    their own execution.
//
class Action : public Basic::Object
{
   DECLARE_SUBCLASS(Action, Basic::Object)
public:
   Action();

   void setVote(const unsigned int x);
   unsigned int getVote() const;

   virtual bool execute(Basic::Component* actor)=0;

private:
   unsigned int vote;
};

inline void Action::setVote(const unsigned int x)      { vote = x; return; }
inline unsigned int Action::getVote() const            { return vote; }

} // End Basic namespace
} // End Eaagles namespace

#endif
