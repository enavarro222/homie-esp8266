#ifndef Homie_h
#define Homie_h

#include <Arduino.h>
#include "Homie/Logger.hpp"
#include "Homie/Config.hpp"
#include "Homie/Datatypes/ConfigStruct.hpp"
#include "Homie/Constants.hpp"
#include "Homie/Helpers.hpp"
#include "Homie/Boot/Boot.hpp"
#include "Homie/Boot/BootNormal.hpp"
#include "Homie/Boot/BootConfig.hpp"
#include "Homie/Boot/BootOta.hpp"

#include "HomieNode.h"

namespace HomieInternals {
  class HomieClass {
    public:
      HomieClass();
      ~HomieClass();
      void setup();
      void loop();

      void enableLogging(bool logging);
      void setFirmware(const char* name, const char* version);
      void registerNode(HomieNode& node);
      void setGlobalInputHandler(bool (*callback)(String node, String property, String message));
      void setResettable(bool resettable);
      void setResetHook(void (*callback)(void));
      void setResetTrigger(uint8_t pin, byte state, uint16_t time);
      void disableResetTrigger();
      void setResetFunction(bool (*callback)(void));
      void setSetupFunction(void (*callback)(void));
      void setLoopFunction(void (*callback)(void));
      bool isReadyToOperate();
      bool setNodeProperty(HomieNode& node, String property, String value, bool retained = true) {
        return this->setNodeProperty(node, property.c_str(), value.c_str(), retained);
      }
      bool setNodeProperty(HomieNode& node, const char* property, const char* value, bool retained = true);
    private:
      Boot* _boot;
      SharedInterface _shared_interface;
  };
}

extern HomieInternals::HomieClass Homie;

#endif
