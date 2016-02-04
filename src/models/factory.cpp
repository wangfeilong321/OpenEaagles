
#include "openeaagles/models/factory.h"

#include "openeaagles/basic/Object.h"

// dynamics models
#include "openeaagles/models/dynamics/JSBSimModel.h"
#include "openeaagles/models/dynamics/RacModel.h"
#include "openeaagles/models/dynamics/LaeroModel.h"

// sensor models
#include "openeaagles/models/sensor/Gmti.h"
#include "openeaagles/models/sensor/Tws.h"
#include "openeaagles/models/sensor/Stt.h"

#include <cstring>

namespace oe {
namespace models {

basic::Object* factory(const char* name)
{
   basic::Object* obj = nullptr;

   // dynamics models
   if (std::strcmp(name, RacModel::getFactoryName()) == 0) {              // RAC
      obj = new RacModel();
   }
   else if (std::strcmp(name, JSBSimModel::getFactoryName()) == 0) {      // JSBSim
      obj = new JSBSimModel();
   }
   else if (std::strcmp(name, LaeroModel::getFactoryName()) == 0) {       // Laero
      obj = new LaeroModel();
   }

   // sensor models
   if (std::strcmp(name, Gmti::getFactoryName()) == 0) {
      obj = new Gmti();
   }
   else if (std::strcmp(name, Stt::getFactoryName()) == 0) {
      obj = new Stt();
   }
   else if (std::strcmp(name, Tws::getFactoryName()) == 0) {
      obj = new Tws();
   }

   return obj;
}

}
}
