#pragma once
#include "tinyxml/tinyxml.h"
#include "sqlite/sqlite3.h"

#include "structure.h"

//43c060
int ReadXml_Int(const char *level1, const char *level2, const char *level3, int initvalue, int *oBuf, TiXmlDocument *xmlData);
int ReadXml_Str(const char *level1, const char *level2, const char *level3, const CSTR initvalue, CSTR* oBuf, TiXmlDocument *xmlData);
int Read_JukeboxPath(CONFIG_JUKEBOX *box, TiXmlDocument *xml);
int ReadXml_Int_Multi(const char * level1, const char * level2, const char * level3, int * oBuf, TiXmlDocument * xmlData);
int ReadKeyConfig(game * game, const char * FilePath);
int ReadMIDI(game *gs, const char *filepath);
void WriteXML_Tab2Int(FILE * hFile, const char * tag, int value);
void WriteXML_Tab2Str(FILE * hFile, const char * tag, CSTR str);
int WriteConfigXml(game * g, const char * filename);
void WriteXML_KeyConfig(FILE * hFile, CONFIG_INPUT cfg_in, char * tag, int num);
int WriteKeyConfig(game * param_1, const char * filepath, int key);
int WriteMidiXml(game * g, const char * filename);
//43f6d0
int ReadSkinCustomize(SkinUser * sku, char * FilePath);
//441340
int WriteSkinCustomizeXml(SkinUser * sku, char * filepath);
//441d30
int ReadConfig(game* gs, const char* filepath);
//443550 _ need simplification
void MD5byte(char **iStr, uint len, char *oByte);
//443ff0
char* MD5str(char *iStr);