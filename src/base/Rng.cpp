
#include "openeaagles/base/Rng.h"
#include "openeaagles/base/Number.h"

namespace oe {
namespace base {

IMPLEMENT_SUBCLASS(Rng,"Rng")
EMPTY_SERIALIZER(Rng)
EMPTY_COPYDATA(Rng)
EMPTY_DELETEDATA(Rng)

//-----
// slot table for this class type
//-----
BEGIN_SLOTTABLE(Rng)
   "seed",     // seed
END_SLOTTABLE(Rng)

//-----
// Map slot table to handles 
//-----
BEGIN_SLOT_MAP(Rng)
   ON_SLOT(1,setSlotSeed,Number)
END_SLOT_MAP()


//==============================================================================
// initialization of static private members
//==============================================================================

unsigned int Rng::state[n] = {0x0};
int Rng::p = 0;
bool Rng::init = false;


//==============================================================================
// Rng class constructors
//==============================================================================

//-----
// default constructor: uses default seed only if this is the first instance
//-----
Rng::Rng()
{
   STANDARD_CONSTRUCTOR()
   if (!init) {
      seed(5489);
   }
   init = true;
}

//-----
// constructor with 32 bit int as seed
//-----
Rng::Rng(unsigned int s)
{
   seed(s);
   init = true;
}

//-----
// constructor with array of size 32 bit ints as seed
//-----
Rng::Rng(const unsigned int* array, int size)
{
   seed(array, size);
   init = true;
}


//==============================================================================
// Rng class member functions
//==============================================================================

//-----
// draw() -- this will be defined in the distribution classes
//-----
double Rng::draw()
{
   return 0.0;
}

//-----
// generate new state vector
//-----
void Rng::gen_state()
{
   for (int i = 0; i < (n - m); ++i) {
      state[i] = state[i + m] ^ twiddle(state[i], state[i + 1]);
   }
   
   for (int i = n - m; i < (n - 1); ++i) {
      state[i] = state[i + m - n] ^ twiddle(state[i], state[i + 1]);
   }
   
   state[n - 1] = state[m - 1] ^ twiddle(state[n - 1], state[0]);
   p = 0; // reset position
}

//-----
// init by 32 bit seed
//-----
void Rng::seed(unsigned int s)
{
   state[0] = s & 0xFFFFFFFF; // for > 32 bit machines
  
   for (int i = 1; i < n; ++i) {
      state[i] = 1812433253 * (state[i - 1] ^ (state[i - 1] >> 30)) + i;
      // see Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier
      // in the previous versions, MSBs of the seed affect only MSBs of 
      // the array state 2002/01/09 modified by Makoto Matsumoto
      state[i] &= 0xFFFFFFFF; // for > 32 bit machines
   }
   
   p = n; // force gen_state() to be called for next random number
}

//-----
// init by array
//-----
void Rng::seed(const unsigned int* array, int size)
{
   seed(19650218);
   int i = 1;
   int j = 0;
   for (int k = ((n > size) ? n : size); k; --k) {
      state[i] = (state[i] ^ ((state[i - 1] ^ (state[i - 1] >> 30)) * 1664525))
         + array[j] + j; // non linear
      state[i] &= 0xFFFFFFFF; // for > 32 bit machines
      ++j; j %= size;
      if ((++i) == n) { 
         state[0] = state[n - 1]; i = 1;
      }
   }
   
   for (int k = n - 1; k > 0; --k) {
      state[i] = (state[i] ^ ((state[i - 1] ^ (state[i - 1] >> 30)) * 1566083941)) - i;
      state[i] &= 0xFFFFFFFF; // for > 32 bit machines
      if ((++i) == n) { state[0] = state[n - 1]; i = 1; }
   }
   
   state[0] = 0x80000000; // MSB is 1; assuring non-zero initial array
   p = n; // force gen_state() to be called for next random number
}

//-----
// setSlotSeed()
//-----
bool Rng::setSlotSeed(const Number* const x)
{
   bool ok = false;
   if(x != nullptr) {
      seed(x->getInt());
      ok = true;
   }
   return ok;
}

//-----
// getSlotByIndex()
//-----
Object* Rng::getSlotByIndex(const int si)
{
   return BaseClass::getSlotByIndex(si);
}


}
}


