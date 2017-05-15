/**@file registration.h */

#ifndef REGISTRATION_H // Falls REGISTRATION_H nicht vorhanden ist,...
#define REGISTRATION_H // fuege REGISTRATION_H und den Inhalt dieses Headers hinzu
                       // Damit wird verhindert, dass dieser Header zweimal
                       // hinzugefuegt wird.
                       
///  Maximale Länge eines Tag-Ids
const int TAG_SIZE = 4;

#pragma pack(1)
///  Struct, das ein char-Array für ein RFID-Tag beinhaltet
struct TagId{
 
  char id[TAG_SIZE]; ///< Beinhaltet das Tag
  char nullChar = '\0'; ///< Null-Zeichen für eine einfachere Ausgabe als String
};
#pragma pack()


  /** \brief Klasse für die Registrierung von RFID-Tags
 * 
 * Die Klasse Registrierung erlaubt die Registration von bis zu 100 RFID-Tags\n 
 * Diese werden in ein Array abgespeichert. 
 * 
 */  
class Registration{
public:

/** \brief Constructor für Registrierung
 * Initialisierung der Variable m_tagIdCount
 */  
  Registration();

/** \brief Entfernt ein bestehendes RFID-Tag 
 *  
 * Falls vorhanden, wird das RFID-Tag gelöscht und 
 * alle dahinter befindlichen Tags werden um ein Tag 
 * zurück verschoben.
 * \param strin String als Tag-Identifikation
 * \param str_size Länge des Strings
 * \return 1, wenn ein RFID-Tag gelöscht wurde und 
 * 0 falls das RFID-Tag nicht vorhanden ist.
 */  
  int deletePerson(const char * strin, int str_size);

/** \brief Gibt die Anzahl der registrierten RFID-Tags zurück
 *  
 *  \return Anzahl registrierter Tags
 */  
  int countTags() const;

/** \brief Gibt die die Id des gesuchten RFID-Tags zurück
 *  
 *  \param tagId Gesuchte Tag-Identifikation
 *  \return Id des gesuchten Tags oder -1, falls die Id nicht registriert ist.
 */  
  int findPersonId(const char * tagId) const;
  
/** \brief Gibt die registrierten Tags über die serielle Schnittstelle zurück
 *  
 *  Format:\n
 *  [Anzahl] Tag(s): Tag1 Tag2 ...
 */  
  void listRegisteredPersons() const;

/** \brief Fügt ein bestehendes RFID-Tag hinzu, falls dieses noch nicht registriert ist.
 *  
 * Falls noch nicht vorhanden, wird das RFID-Tag hinzugefügt.
 * Ist dieses Tag bereits registriert, wird dieses Tag über deletePerson() gelöscht.
 * \param strin String als Tag-Identifikation
 * \param str_size Länge des Strings
 */  
  void registerPerson(const char * strin, int str_size);

private:
  int m_tagIdCount;
  TagId m_tagIdList[100];
};




#endif // Schiesst die ifndef Abfrage ab siehe Zeile 1
