typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
float10
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct SkinManage SkinManage, *PSkinManage;

typedef struct Skin Skin, *PSkin;

typedef struct CSTR CSTR, *PCSTR;

typedef enum SKINTYPE {
    SKINTYPE_7KEYS=0,
    SKINTYPE_5KEYS=1,
    SKINTYPE_14KEYS=2,
    SKINTYPE_10KEYS=3,
    SKINTYPE_9KEYS=4,
    SKINTYPE_SELECT=5,
    SKINTYPE_DECIDE=6,
    SKINTYPE_RESULT=7,
    SKINTYPE_KEYCONFIG=8,
    SKINTYPE_SKINSELECT=9,
    SKINTYPE_SOUNDSET=10,
    SKINTYPE_THEME=11,
    SKINTYPE_5KEYSBATTLE=12,
    SKINTYPE_7KEYSBATTLE=13,
    SKINTYPE_COURSEEDIT=14,
    SKINTYPE_COURSERESULT=15,
    SKINTYPE_9KEYSBATTLE=16,
    SKINTYPE_OPENING=17,
    SKINTYPE_MODESELECT=18,
    SKINTYPE_MODEDECIDE=19,
    SKINTYPE_COURSESELECT=20
} SKINTYPE;

typedef struct SkinCustom SkinCustom, *PSkinCustom;

struct SkinManage {
    struct Skin * Data; /* 453d0=b14*64 */
    int Count;
    int Max;
    int skinID[100];
    int select;
    int previewID;
    int previewCustomID;
};

struct CSTR {
    char * body;
};

struct SkinCustom {
    struct CSTR title;
    struct CSTR * op_label; /* *100d */
    int dst_op_selected;
    int dst_op_start;
    int dst_op_count;
    int labelCapacity; /* 100 */
    int undefined; /* 0 */
};

struct Skin {
    struct CSTR skinFile;
    struct CSTR thumbnail;
    struct CSTR title;
    struct CSTR maker;
    enum SKINTYPE type;
    int undefined1;
    int undefined2;
    int custom_count;
    struct SkinCustom customs[100];
    int scroll_count;
};

