#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(25, 20, 30) == TOO_NORMAL);
}

TEST_CASE("classify the Temperature Breach according to type of cooling") {
  classifyTemperatureBreach(PASSIVE_COOLING, 20);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,46) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,30) == NORMAL);
}

TEST_CASE("Check and alert temperature breach according to target") {
  BatteryCharacter stBatChar={0};
  stBatChar.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER, stBatChar, 50);
  checkAndAlert(TO_EMAIL, stBatChar, 50);
}

