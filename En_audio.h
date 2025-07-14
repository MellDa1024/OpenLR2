#include "structure.h"
#include "FMODex/fmod.h"

// const char * GetFMODerror(int errCode);

// //file
// int IsAltSoundExist(CSTR * filepath);

// int ReleaseSound(AUDIO * aud, SOUNDDATA * sound);

// int StopSound(AUDIO * aud, SOUNDDATA * sound);

// int SetSoundVolume(AUDIO * aud, SOUNDDATA * sound, float volume);

// int SoundGetCurrentTime(AUDIO * aud, SOUNDDATA * sound);

// //fmod close
// int EndSound(AUDIO * aud); 

// int SOUND_dxlibFx(SOUNDDATA sound, int v_master, int v_BGA, int pitch, double freq);

// int SetFadeOut(AUDIO * aud, int fadetime);
// int SetFadePreview(AUDIO * aud, int fadeintime, char flag);

// //write file
// int GetSoundBuffer(AUDIO * aud, double runtime, int volume);
// void WriteSoundFile(AUDIO * aud, CSTR filename, uint size);

// int SOUND_normalize(AUDIO * aud, SOUNDDATA * sound);

// //sound to write buffer
// int RecordSound(AUDIO * aud, SOUNDDATA * sound, double time, double len);
// int RecordFadeout(AUDIO * aud, double from, double length);

// int LoadSound(AUDIO * aud, SOUNDDATA * sound, CSTR filepath, int loop, int disableDSP, int previewFlag);

// int PlaySound(AUDIO * aud, SOUNDDATA * sound, FMOD_CHANNELGROUP *channelgroup, int stage);

// int SOUND_FmodToDxlib(AUDIO * aud);
// int ApplySoundFX(AUDIO * aud, int flag, char disable);

// int InitFade(AUDIO * aud);
// int SetVolumeByFade(AUDIO * aud);

// //fmod open
// int InitSound(AUDIO *aud, uint bufferLength, int numBuffer, char fDisable, int outputType, int driver);


// //need 'game'
// int FxByMIDI(game *g); //more about input reaction..
// int UpdateSoundFX(game *g, int *value, int objectID, int min, int max);
// int InitFxParam(game *g, int fxNum);
// int StopSysSound(game * g);
// int ReleaseSysSound(game * g);
// int ReadLR2SoundSet(game * g, CSTR filepath, char reFlag);



const char * GetFMODerror(int errCode);

//fmod init / end
int InitSound(AUDIO *aud, uint bufferLength, int numBuffer, char fDisable, int outputType, int driver);
int EndSound(AUDIO * aud); 

//load file
int IsAltSoundExist(CSTR * filepath);
int SOUND_normalize(AUDIO * aud, SOUNDDATA * sound);
int LoadSound(AUDIO * aud, SOUNDDATA * sound, CSTR filepath, int loop, int disableDSP, int previewFlag);

//unload
int ReleaseSound(AUDIO * aud, SOUNDDATA * sound);

//apply param
int SetSoundVolume(AUDIO * aud, SOUNDDATA * sound, float volume);

int InitFade(AUDIO * aud);
int SetFadeOut(AUDIO * aud, int fadetime);
int SetFadePreview(AUDIO * aud, int fadeintime, char flag);
int SetVolumeByFade(AUDIO * aud);

int SOUND_FmodToDxlib(AUDIO * aud);
int SOUND_dxlibFx(SOUNDDATA sound, int v_master, int v_BGA, int pitch, double freq);
int ApplySoundFX(AUDIO * aud, int flag, char disable);

//play
int PlaySound(AUDIO * aud, SOUNDDATA * sound, FMOD_CHANNELGROUP *channelgroup, int stage);
int StopSound(AUDIO * aud, SOUNDDATA * sound);

int SoundGetCurrentTime(AUDIO * aud, SOUNDDATA * sound);

//write file
int GetSoundBuffer(AUDIO * aud, double runtime, int volume);
void WriteSoundFile(AUDIO * aud, CSTR filename, uint size);
int RecordSound(AUDIO * aud, SOUNDDATA * sound, double time, double len);
int RecordFadeout(AUDIO * aud, double from, double length);