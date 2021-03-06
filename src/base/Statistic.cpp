//------------------------------------------------------------------------------
// Statistic
//------------------------------------------------------------------------------
#include "openeaagles/base/Statistic.h"

#include <limits>

namespace oe {
namespace base {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(Statistic,"Statistic")
EMPTY_SERIALIZER(Statistic)

//------------------------------------------------------------------------------
// Constructor(s)
//------------------------------------------------------------------------------
Statistic::Statistic()
{
   STANDARD_CONSTRUCTOR()
   clear();
}

//------------------------------------------------------------------------------
// copyData() -- copy member data
//------------------------------------------------------------------------------
void Statistic::copyData(const Statistic& org, const bool)
{
   BaseClass::copyData(org);

   n = org.n;
   maximum = org.maximum;
   minimum = org.minimum;
   sum = org.sum;
   absSum = org.absSum;
   sumSq  = org.sumSq ; 
   value1 = org.value1;
}

//------------------------------------------------------------------------------
// deleteData() -- delete member data
//------------------------------------------------------------------------------
void Statistic::deleteData()
{
}

//------------------------------------------------------------------------------
// clear() -- resets/clears object state
//------------------------------------------------------------------------------
void Statistic::clear()
{
  n = 0;
  maximum = -std::numeric_limits<double>::max();
  minimum =  std::numeric_limits<double>::max(); // DDH? why is both max, flip min/max?
  sum = 0.0;
  absSum = 0.0;
  sumSq  = 0.0;
  value1 = 0.0;
}

}
}

