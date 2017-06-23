#ifndef TESTDEFINITIONEN_H
#define TESTDEFINITIONEN_H

#ifdef TEST

#include "test.h"
#include "registration.h"




void testAnmeldung(){ // Name frei waehlbar
  // Funktion muss in der Funktion runTests() aufgerufen werden
  // siehe weiter unten

  bool testResult = false;

  // Der folgende Teil kann nicht uebernommen werden:
  // ---------------------------------------------------------
  // Eine Fake-Id zum Test:
  char testRFIDCode[4] = {'a','b','c','d'};
  Registration reg;

  int registeredTagCountBefore = reg.countTags();
  
  // Registrierung der Fake-Id
  reg.registerPerson(testRFIDCode, 4);

  int registeredTagCountAfter = reg.countTags();
  
  // testResult kann bei einem erfolgreichen Test 
  // auf true gesetzt werden

  // Wenn die Anzahl der Registrierten Tags um eins hoeher ist als
  // vorher gilt der Test als bestanden -> testResult = true;
  if(registeredTagCountBefore + 1 == registeredTagCountAfter)
  {
    testResult = true;
  }


  // Bis hierhin ist eine eigene Implementierung erforderlich
  // Nicht vergessen:  testResult = true; bei erfolgreichem Test
  // ---------------------------------------------------------  

  // Der folgende Teil erzeugt eine verwendbare Ausgabe
  // Diese kann direkt in das Wiki kopiert werden
  APITest::printTestResult(testResult, 
  "Anmeldung eines Studierenden", 
  "Paul Frost",
  "Anmeldung der Studierenden Prototyp A02, Pruefung der Anzahl von Registrierungen", 
  "testDefinitionen.h");
}


void runTests(){
  APITest::printTestStartHeader(); // Nicht modifizieren
  
  // Hier sollen die eigenen Tests hinzugefuegt werden
  testAnmeldung();

  APITest::printTestEndFooter(); // Nicht modifizieren
}
#endif //TEST

#ifdef TEST  // Nicht modifizieren
  #define RUNTEST runTests();
#else
  #define RUNTEST
#endif


#endif //TESTDEFINITIONEN_H
