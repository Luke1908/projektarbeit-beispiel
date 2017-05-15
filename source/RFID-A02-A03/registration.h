/**@file registration.h */

#ifndef REGISTRATION_H // Falls REGISTRATION_H nicht vorhanden ist,...
#define REGISTRATION_H // fuege REGISTRATION_H und den Inhalt dieses Headers hinzu
                       // Damit wird verhindert, dass dieser Header zweimal
                       // hinzugefuegt wird.

const int TAG_SIZE = 4;

#pragma pack(1)
///  Struct, das ein char-Array für ein RFID-Tag beinhaltet
struct TagId{
 
  char id[TAG_SIZE]; ///< Beinhaltet das Tag
  char nullChar = '\0'; ///< Null-Zeichen für eine einfachere Ausgabe als String
};
#pragma pack()


  /** @brief Klasse für die Registrierung von RFID-Tags
 * 
 * Die Klasse Registrierung erlaubt die Registration von bis zu 100 RFID-Tags\n 
 * Diese werden in ein Array abgespeichert. 
 * 
 */  
class Registration{
public:
  Registration();

  int deletePerson(const char * strin, int str_size);
  int countTags() const;
  int findPersonId(const char * tagId) const;
  void listRegisteredPersons() const;
  void registerPerson(const char * strin, int str_size);

private:
  int m_tagIdCount;
  TagId m_tagIdList[100];
};




#endif // Schiesst die ifndef Abfrage ab siehe Zeile 1
