#include "registration.h"

#include <Arduino.h>

using namespace std;


Registration::Registration(){
  m_tagIdCount = 0;
}

int Registration::countTags() const{
  return m_tagIdCount;
}

int Registration::deletePerson(const char * strin, int str_size){
  if(str_size == 4){
    int personId = findPersonId(strin);
   
    if(personId == -1){
      return 0;
    }

    if(personId < m_tagIdCount-1){ 
      TagId *destination = &m_tagIdList[personId];
      TagId *source = &m_tagIdList[personId+1];
      int sizeOfTags = (m_tagIdCount - personId - 1) * sizeof(TagId);
      memcpy(destination, source, sizeOfTags);
    }

    m_tagIdCount--;
    Serial.print("Tag removed");
    Serial.println();

    listRegisteredPersons();
    return 1;
  }
  return 0;
}


int Registration::findPersonId(const char * tagId) const{
  int personId = 0;
  while(personId < m_tagIdCount){
    if(strncmp(m_tagIdList[personId].id, tagId, TAG_SIZE) == 0){
      return personId;
    }
    personId++;
  }
  return -1;
}


void Registration::listRegisteredPersons() const{
  int personId = 0;

  Serial.print(m_tagIdCount);
  Serial.print(" Tag(s):");

  while(personId < m_tagIdCount){
    Serial.print(" ");
    Serial.print(m_tagIdList[personId].id);
    personId++;
  }
  Serial.println();
  Serial.println();
}


void Registration::registerPerson(const char * strin, int str_size){
  if(str_size == TAG_SIZE){ 
    if(deletePerson(strin, str_size)){
      return;
    }
    
    strncpy(m_tagIdList[m_tagIdCount].id, strin, TAG_SIZE);
    m_tagIdCount++;
    
    Serial.print("Tag registered");
    Serial.println();

    listRegisteredPersons();
  }
}
