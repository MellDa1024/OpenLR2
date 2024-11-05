// -------------------------------------------------------------------------------
// 
// 		ＤＸライブラリ		ヘッ?フ?イル
// 
// 				Ver 3.12a
// 
// -------------------------------------------------------------------------------

#ifndef __DXLIB
#define __DXLIB

#include "DxCompileConfig.h"
#include "DxDirectX.h"

// ＤＸライブラリのバ?ジョン
#define DXLIB_VERSION 0x312a
#define DXLIB_VERSION_STR _T( "3.12a" )

// 設定 -----------------------------------------------------------------------

// ＤＸライブラリに必要な lib フ?イルを、プロジェクトのカレントフォル?や
// コンパイラのデフォルト LIB パスに設定せずに使用される場合は以下の
// コメントを外してください
//#define DX_LIB_NOT_DEFAULTPATH

#ifndef __DX_MAKE

// ?画関連の関数を一切使用されない場合は以下のコメントを外して下さい
//#define DX_NOTUSE_DRAWFUNCTION

#endif // __DX_MAKE

// ライブラリリンク定?--------------------------------------------------------

#if !defined( __ANDROID ) && !defined( DX_GCC_COMPILE )

#ifndef __DX_MAKE
	#ifndef DX_LIB_NOT_DEFAULTPATH
		#ifndef DX_SRC_COMPILE
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_x64_d.lib"		)		//  ?画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64_d.lib"		)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_x64_d.lib"	)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#else
							#pragma comment( lib, "DxLib_x64_d.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_x64_d.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc_x64.lib"			)		//  ?画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_x64.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#else
							#pragma comment( lib, "DxLib_x64.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_x64.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#endif
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_d.lib"		)		//  ?画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_d.lib"		)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_d.lib"	)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#else
							#pragma comment( lib, "DxLib_d.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_d.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc.lib"			)		//  ?画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#else
							#pragma comment( lib, "DxLib.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib.lib"		)		//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "DxDrawFunc.lib"		)			//  ?画部分の抜き出し
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLibW.lib"	)			//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#else
					#pragma comment( lib, "DxLib.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLib.lib"	)			//  標?Ｃライブラリを使用する部分の lib フ?イルの使用指定
				#endif
			#endif

			#ifdef _DEBUG
				#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#else
				#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#endif
		#endif
		//#pragma comment( lib, "libcmt.lib"		)				//  C標??ル?スレッド対応ライブラリ
		#pragma comment( lib, "kernel32.lib"		)			//  Win32カ?ネルライブラリ
		//#pragma comment( lib, "comctl32.lib"		)			//?Win32APIライブラリ
		#pragma comment( lib, "user32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "gdi32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "advapi32.lib"		)			//  Win32APIライブラリ
		//#pragma comment( lib, "ole32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "shell32.lib"		)				//  ?ル?メディアライブラリ
		//#pragma comment( lib, "winmm.lib"		)				//  ?ル?メディアライブラリ
		#ifndef DX_NON_MOVIE
			//#pragma comment( lib, "Strmiids.lib" )			//?DirectShowライブラリ
		#endif
		#ifndef DX_NON_NETWORK
			//#pragma comment( lib, "wsock32.lib" )				//  WinSocketsライブラリ
		#endif
		#ifndef DX_NON_KEYEX
			//#pragma comment( lib, "imm32.lib" )					// ＩＭＥ?作用ライブラリ
		#endif
		#ifndef DX_NON_ACM
			//#pragma comment( lib, "msacm32.lib" )				// ?ＣＭ?作用ライブラリ 
		#endif
		#ifndef DX_NON_BULLET_PHYSICS
			#ifdef _MSC_VER
				#ifdef DX_USE_VC8_BULLET_PHYSICS_LIB
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8.lib" )
							#pragma comment( lib, "libbulletmath_vc8.lib" )
						#endif
					#endif
				#else
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc6_d.lib" )	// Visual C++ 6.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc6_d.lib" )
							#pragma comment( lib, "libbulletmath_vc6_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc6.lib" )	// Visual C++ 6.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc6.lib" )
							#pragma comment( lib, "libbulletmath_vc6.lib" )
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "libbulletcollision.lib" )	// Bullet Physics ライブラリ 
				#pragma comment( lib, "libbulletdynamics.lib" )
				#pragma comment( lib, "libbulletmath.lib" )
			#endif
		#endif
		#ifndef DX_NON_PNGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_x64_d.lib" )		// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_x64_d.lib" )
					#else
						#pragma comment( lib, "libpng_x64.lib" )		// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_d.lib" )			// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_d.lib" )
					#else
						#pragma comment( lib, "libpng.lib" )			// ＰＮＧライブラリ
						#pragma comment( lib, "zlib.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "libpng.lib" )			// ＰＮＧライブラリ
				#pragma comment( lib, "zlib.lib" )
			#endif
		#endif
		#ifndef DX_NON_JPEGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_x64_d.lib" )		// ＪＰＥＧライブラリ
					#else
						#pragma comment( lib, "libjpeg_x64.lib" )		// ＪＰＥＧライブラリ
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_d.lib" )			// ＪＰＥＧライブラリ
					#else
						#pragma comment( lib, "libjpeg.lib" )			// ＪＰＥＧライブラリ
					#endif
				#endif
			#else
				#pragma comment( lib, "libjpeg.lib" )			// ＪＰＥＧライブラリ
			#endif
		#endif
		#ifndef DX_NON_OGGVORBIS								// ＯｇｇＶｏｒｂｉｓライブラリ
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )
			#endif
		#endif
		#ifndef DX_NON_OGGTHEORA								// ＯｇｇＴｈｅｏｒａライブラリ
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )

						#pragma comment( lib, "libtheora_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )

						#pragma comment( lib, "libtheora_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )

						#pragma comment( lib, "libtheora_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )

						#pragma comment( lib, "libtheora_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )

				#pragma comment( lib, "libtheora_static.lib" )
			#endif
		#endif
	#endif
#endif

#endif // !defined( __ANDROID ) && !defined( DDX_GCC_COMPILE )

// 定?---------------------------------------------------------------------------

// π
#define DX_PI										(3.1415926535897932384626433832795 )
#define DX_PI_F										(3.1415926535897932384626433832795f)
#define DX_TWO_PI									(3.1415926535897932384626433832795  * 2.0 )
#define DX_TWO_PI_F									(3.1415926535897932384626433832795f * 2.0f)

#define DX_CHAR										char

#define DX_DEFINE_START

#define MAX_IMAGE_NUM								(32768)				// 同時に持てるグラフィックハンドルの最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_2DSURFACE_NUM							(32768)				// ２Ｄサ?フェスデ??の最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_3DSURFACE_NUM							(65536)				// ３Ｄサ?フェスデ??の最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_IMAGE_DIVNUM							(64)				// 画像分割の最大数
#define MAX_SURFACE_NUM								(65536)				// サ?フェスデ??の最大数
#define MAX_SHADOWMAP_NUM							(8192)				// シャドウ?ップデ??の最大数
#define MAX_SOFTIMAGE_NUM							(8192)				// 同時に持てる?フトイメ?ジハンドルの最大数( ハンドルエラ??ェックの?スクに使用しているので 65536 以下の 2 のべき乗にして下さい )

#define MAX_SOUND_NUM								(32768)				// 同時に持てるサウンドハンドルの最大数
#define MAX_SOFTSOUND_NUM							(8192)				// 同時に持てる?フトウエアサウンドハンドルの最大数
#define MAX_MUSIC_NUM								(256)				// 同時に持てる?ュ?ジックハンドルの最大数
#define MAX_MOVIE_NUM								(100)				// 同時に持てる??ビ?ハンドルの最大数
#define MAX_MASK_NUM								(512)				// 同時に持てる?スクハンドルの最大数
#define MAX_FONT_NUM								(40)				// 同時に持てるフォントハンドルの最大数
#define MAX_INPUT_NUM								(256)				// 同時に持てる文字列入力ハンドルの最大数
#define MAX_SOCKET_NUM								(8192)				// 同時に持てる通信ハンドルの最大数
#define MAX_LIGHT_NUM								(4096)				// 同時に持てるライトハンドルの最大数
#define MAX_SHADER_NUM								(4096)				// 同時に持てるシェ???ハンドルの最大数
#define MAX_MODEL_BASE_NUM							(32768)				// 同時に持てる３Ｄモデル基?デ??ハンドルの最大数
#define MAX_MODEL_NUM								(32768)				// 同時に持てる３Ｄモデルデ??ハンドルの最大数
#define MAX_VERTEX_BUFFER_NUM						(16384)				// 同時に持てる頂?バッフ?ハンドルの最大数
#define MAX_INDEX_BUFFER_NUM						(16384)				// 同時に持てるインデックスバッフ?の最大数
#define MAX_FILE_NUM								(32768)				// 同時に持てるフ?イルハンドルの最大数

#define MAX_JOYPAD_NUM								(16)				// ジョイパッドの最大数
#define MAX_EVENTPROCESS_NUM						(5)					// 一度に処理するイベントの最大数

#define DEFAULT_SCREEN_SIZE_X						(640)				// デフォルトの画面の幅
#define DEFAULT_SCREEN_SIZE_Y						(480)				// デフォルトの画面の高さ
#define DEFAULT_COLOR_BITDEPTH						(16)				// デフォルトの色ビット?度
#define DEFAULT_ZBUFFER_BITDEPTH					(16)				// デフォルトのＺバッフ?ビット?度

#define DEFAULT_FOV									(60.0F * 3.1415926535897932384626433832795F / 180.0F)	// デフォルトの視野角
#define DEFAULT_TAN_FOV_HALF						(0.57735026918962576450914878050196F) // tan( FOV * 0.5 )
#define DEFAULT_NEAR								(0.0F)				// NEARクリップ面
#define DEFAULT_FAR									(20000.0F)			// FARクリップ面

#define DX_DEFAULT_FONT_HANDLE						(-2)				// デフォルトフォントを示す値

#define DEFAULT_FONT_SIZE							(16)				// フォントのデフォルトのサイズ
#define DEFAULT_FONT_THINCK							(6)					// フォントのデフォルトの太さ
#define DEFAULT_FONT_TYPE							( DX_FONTTYPE_NORMAL )	// フォントのデフォルトの?態
#define DEFAULT_FONT_EDGESIZE						(1)					// フォントのデフォルトの太さ

#define FONT_CACHE_MAXNUM							(2024)				// フォントキャッシュに格?できる最大文字数
#define FONT_CACHE_MEMORYSIZE						(0x50000)			// フォントキャッシュの最大容量
#define FONT_CACHE_MAX_YLENGTH						(0x4000)			// フォントキャッシュサ?フェスの最大縦幅

#define MAX_USERIMAGEREAD_FUNCNUM					(10)				// ユ?ザ?が登?できるグラフィックロ?ド関数の最大数


// ＷＩＮＤＯＷＳのバ?ジョン?クロ
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_8							(0x10A)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// ＤｉｒｅｃｔＸのバ?ジョン?クロ
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)

// 文字セット
#define DX_CHARSET_DEFAULT							(0)				// デフォルト文字セット
#define DX_CHARSET_SHFTJIS							(1)				// 日?語文字セット
#define DX_CHARSET_HANGEUL							(2)				// 韓国語文字セット
#define DX_CHARSET_BIG5								(3)				// 繁体文字セット
#define DX_CHARSET_GB2312							(4)				// 簡体文字セット

// ＭＩＤＩの再生モ?ド定?
#define DX_MIDIMODE_MCI								(0)				// ＭＣＩによる再生
#define DX_MIDIMODE_DM								(1)				// ＤｉｒｅｃｔＭｕｓｉｃによる再生

// ?画モ?ド定?
#define DX_DRAWMODE_NEAREST							(0)				// ネアレストネイバ??で?画
#define DX_DRAWMODE_BILINEAR						(1)				// バイリニア?で?画する
#define DX_DRAWMODE_ANISOTROPIC						(2)				// 異方性フィル?リング?で?画する
#define DX_DRAWMODE_OTHER							(3)				// それ以外

// フォントの?イプ
#define DX_FONTTYPE_NORMAL							(0x00)				// ノ??ルフォント
#define DX_FONTTYPE_EDGE							(0x01)				// エッジつきフォント
#define DX_FONTTYPE_ANTIALIASING					(0x02)				// アン?エイリアスフォント( 標???アン?エイリアス )
#define DX_FONTTYPE_ANTIALIASING_4X4				(0x12)				// アン?エイリアスフォント( 4x4サンプリング )
#define DX_FONTTYPE_ANTIALIASING_8X8				(0x22)				// アン?エイリアスフォント( 8x8サンプリング )
#define DX_FONTTYPE_ANTIALIASING_EDGE				(0x03)				// アン?エイリアス＆エッジ付きフォント( 標???アン?エイリアス )
#define DX_FONTTYPE_ANTIALIASING_EDGE_4X4			(0x13)				// アン?エイリアス＆エッジ付きフォント( 4x4サンプリング )
#define DX_FONTTYPE_ANTIALIASING_EDGE_8X8			(0x23)				// アン?エイリアス＆エッジ付きフォント( 8x8サンプリング )

// ?画ブレンドモ?ド定?
#define DX_BLENDMODE_NOBLEND						(0)				// ノ?ブレンド
#define DX_BLENDMODE_ALPHA							(1)				// αブレンド
#define DX_BLENDMODE_ADD							(2)				// 加算ブレンド
#define DX_BLENDMODE_SUB							(3)				// 減算ブレンド
#define DX_BLENDMODE_MUL							(4)				// 乗算ブレンド
   // (内部処理用)
#define DX_BLENDMODE_SUB2							(5)				// 内部処理用減算ブレンド２
//#define DX_BLENDMODE_BLINEALPHA					(7)				// 境界線ぼかし
#define DX_BLENDMODE_XOR							(6)				// XORブレンド( ?フトウエアレン?リングモ?ドでのみ有効 )
#define DX_BLENDMODE_DESTCOLOR						(8)				// カラ?は更新されない
#define DX_BLENDMODE_INVDESTCOLOR					(9)				// ?画先の色の反?値を?ける
#define DX_BLENDMODE_INVSRC							(10)			// ?画元の色を反?する
#define DX_BLENDMODE_MULA							(11)			// アルフ??ャンネル考慮付き乗算ブレンド
#define DX_BLENDMODE_ALPHA_X4						(12)			// αブレンドの?画元の輝度を最大４?にできるモ?ド
#define DX_BLENDMODE_ADD_X4							(13)			// 加算ブレンドの?画元の輝度を最大４?にできるモ?ド
#define DX_BLENDMODE_SRCCOLOR						(14)			// ?画元のカラ?でそのまま?画される
#define DX_BLENDMODE_HALF_ADD						(15)			// 半加算ブレンド
#define DX_BLENDMODE_SUB1							(16)			// 内部処理用減算ブレンド１
#define DX_BLENDMODE_PMA_ALPHA						(17)			// 乗算済みαブレンドモ?ドのαブレンド
#define DX_BLENDMODE_PMA_ADD						(18)			// 乗算済みαブレンドモ?ドの加算ブレンド
#define DX_BLENDMODE_PMA_SUB						(19)			// 乗算済みαブレンドモ?ドの減算ブレンド
#define DX_BLENDMODE_PMA_INVSRC						(20)			// 乗算済みαブレンドモ?ドの?画元の色を反?する
#define DX_BLENDMODE_PMA_ALPHA_X4					(21)			// 乗算済みαブレンドモ?ドのαブレンドの?画元の輝度を最大４?にできるモ?ド
#define DX_BLENDMODE_PMA_ADD_X4						(22)			// 乗算済みαブレンドモ?ドの加算ブレンドの?画元の輝度を最大４?にできるモ?ド
#define DX_BLENDMODE_NUM							(23)			// ブレンドモ?ドの数

// 画像合成?イプ
#define DX_BLENDGRAPHTYPE_NORMAL					(0)				// 通常合成
#define DX_BLENDGRAPHTYPE_WIPE						(1)				// ワイプ処理
#define DX_BLENDGRAPHTYPE_ALPHA						(2)				// ブレンド画像のα値と元画像のα値を?け合わせる

// グラフィックフィル???イプ
#define DX_GRAPH_FILTER_MONO						(0)				// モノト?ンフィル?
#define DX_GRAPH_FILTER_GAUSS						(1)				// ガウスフィル?
#define DX_GRAPH_FILTER_DOWN_SCALE					(2)				// 縮小フィル?
#define DX_GRAPH_FILTER_BRIGHT_CLIP					(3)				// 明るさクリップフィル?
#define DX_GRAPH_FILTER_HSB							(4)				// 色相・彩度・明度フィル?
#define DX_GRAPH_FILTER_INVERT						(5)				// 階調の反?フィル?
#define DX_GRAPH_FILTER_LEVEL						(6)				// レベル補正フィル?
#define DX_GRAPH_FILTER_TWO_COLOR					(7)				// ２階調化フィル?
#define DX_GRAPH_FILTER_GRADIENT_MAP				(8)				// グラデ?ション?ップフィル?
#define DX_GRAPH_FILTER_PREMUL_ALPHA				(9)				// 通常のアルフ??ャンネル付き画像を乗算済みアルフ?画像に変換するフィル?
#define DX_GRAPH_FILTER_INTERP_ALPHA				(10)			// 乗算済みアルフ?画像を通常のアルフ??ャンネル付き画像に変換するフィル?
#define DX_GRAPH_FILTER_NUM							(11)

// グラフィックブレンド?イプ
#define DX_GRAPH_BLEND_NORMAL						(0)				// 通常
#define DX_GRAPH_BLEND_RGBA_SELECT_MIX				(1)				// RGBAの要素を選択して合成
#define DX_GRAPH_BLEND_MULTIPLE						(2)				// 乗算
#define DX_GRAPH_BLEND_DIFFERENCE					(3)				// 減算
#define DX_GRAPH_BLEND_ADD							(4)				// 加算
#define DX_GRAPH_BLEND_SCREEN						(5)				// スクリ?ン
#define DX_GRAPH_BLEND_OVERLAY						(6)				// オ?バ?レイ
#define DX_GRAPH_BLEND_DODGE						(7)				// 覆い焼き
#define DX_GRAPH_BLEND_BURN							(8)				// 焼き込み
#define DX_GRAPH_BLEND_DARKEN						(9)				// 比較(暗)
#define DX_GRAPH_BLEND_LIGHTEN						(10)			// 比較(明)
#define DX_GRAPH_BLEND_SOFTLIGHT					(11)			// ?フトライト
#define DX_GRAPH_BLEND_HARDLIGHT					(12)			// ハ?ドライト
#define DX_GRAPH_BLEND_EXCLUSION					(13)			// 除外
#define DX_GRAPH_BLEND_NORMAL_ALPHACH				(14)			// α?ャンネル付き画像の通常合成
#define DX_GRAPH_BLEND_ADD_ALPHACH					(15)			// α?ャンネル付き画像の加算合成
#define DX_GRAPH_BLEND_MULTIPLE_A_ONLY				(16)			// アルフ??ャンネルのみの乗算
#define DX_GRAPH_BLEND_NUM							(17)

// DX_GRAPH_BLEND_RGBA_SELECT_MIX 用の色選択用定?
#define DX_RGBA_SELECT_SRC_R						(0)				// 元画像の赤成分
#define DX_RGBA_SELECT_SRC_G						(1)				// 元画像の緑成分
#define DX_RGBA_SELECT_SRC_B						(2)				// 元画像の青成分
#define DX_RGBA_SELECT_SRC_A						(3)				// 元画像のα成分
#define DX_RGBA_SELECT_BLEND_R						(4)				// ブレンド画像の赤成分
#define DX_RGBA_SELECT_BLEND_G						(5)				// ブレンド画像の緑成分
#define DX_RGBA_SELECT_BLEND_B						(6)				// ブレンド画像の青成分
#define DX_RGBA_SELECT_BLEND_A						(7)				// ブレンド画像のα成分

// ?リゴンカリングモ?ド
#define DX_CULLING_NONE								(0)				// カリングなし
#define DX_CULLING_LEFT								(1)				// 背面を左回りでカリング
#define DX_CULLING_RIGHT							(2)				// 背面を右回りでカリング

// クリッピング方向
#define DX_CAMERACLIP_LEFT							(0x01)			// 画面左方向にクリップ
#define DX_CAMERACLIP_RIGHT							(0x02)			// 画面右方向にクリップ
#define DX_CAMERACLIP_BOTTOM						(0x04)			// 画面下方向にクリップ
#define DX_CAMERACLIP_TOP							(0x08)			// 画面上方向にクリップ
#define DX_CAMERACLIP_BACK							(0x10)			// 画面後方向にクリップ
#define DX_CAMERACLIP_FRONT							(0x20)			// 画面前方向にクリップ

// MV1モデルの頂??イプ
#define DX_MV1_VERTEX_TYPE_1FRAME					(0)				// １フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_4FRAME					(1)				// １?４フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_8FRAME					(2)				// ５?８フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_FREE_FRAME				(3)				// ９フレ??以上の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_NMAP_1FRAME				(4)				// ?線?ップ用の情報が含まれる１フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_NMAP_4FRAME				(5)				// ?線?ップ用の情報が含まれる１?４フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_NMAP_8FRAME				(6)				// ?線?ップ用の情報が含まれる５?８フレ??の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME			(7)				// ?線?ップ用の情報が含まれる９フレ??以上の影響を受ける頂?
#define DX_MV1_VERTEX_TYPE_NUM						(8)				// 頂??イプの数

// メッシュの種類
#define DX_MV1_MESHCATEGORY_NORMAL					(0)				// 普通のメッシュ
#define DX_MV1_MESHCATEGORY_OUTLINE					(1)				// 輪郭線?画用メッシュ
#define DX_MV1_MESHCATEGORY_OUTLINE_ORIG_SHADER		(2)				// 輪郭線?画用メッシュ( オリジナルシェ???での?画用 )
#define DX_MV1_MESHCATEGORY_NUM						(3)				// メッシュの種類の数

// MV1フ?イルの保存?イプ
#define MV1_SAVETYPE_MESH							(0x0001)		// メッシュ情報のみ保存
#define MV1_SAVETYPE_ANIM							(0x0002)		// アニメ?ション情報のみ保存
#define MV1_SAVETYPE_NORMAL							( MV1_SAVETYPE_MESH | MV1_SAVETYPE_ANIM )	// 通常保存

// アニメ?ションキ?デ???イプ
#define MV1_ANIMKEY_DATATYPE_ROTATE					(0)				// 回?
#define MV1_ANIMKEY_DATATYPE_ROTATE_X				(1)				// 回?Ｘ
#define MV1_ANIMKEY_DATATYPE_ROTATE_Y				(2)				// 回?Ｙ
#define MV1_ANIMKEY_DATATYPE_ROTATE_Z				(3)				// 回?Ｚ
#define MV1_ANIMKEY_DATATYPE_SCALE					(5)				// 拡大
#define MV1_ANIMKEY_DATATYPE_SCALE_X				(6)				// スケ?ルＸ
#define MV1_ANIMKEY_DATATYPE_SCALE_Y				(7)				// スケ?ルＹ
#define MV1_ANIMKEY_DATATYPE_SCALE_Z				(8)				// スケ?ルＺ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE				(10)			// 平行移動
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_X			(11)			// 平行移動Ｘ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_Y			(12)			// 平行移動Ｙ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_Z			(13)			// 平行移動Ｚ
#define MV1_ANIMKEY_DATATYPE_MATRIX4X4C				(15)			// ４?４行列の４列目( 0,0,0,1 )固定版
#define MV1_ANIMKEY_DATATYPE_MATRIX3X3				(17)			// ３?３行列
#define MV1_ANIMKEY_DATATYPE_SHAPE					(18)			// シェイプ
#define MV1_ANIMKEY_DATATYPE_OTHRE					(20)			// その他

// ?イ??イプ
#define MV1_ANIMKEY_TIME_TYPE_ONE					(0)				// 時間情報は全体で一つ
#define MV1_ANIMKEY_TIME_TYPE_KEY					(1)				// 時間情報は各キ?に一つ

// アニメ?ションキ??イプ
#define MV1_ANIMKEY_TYPE_QUATERNION_X				(0)				// クォ??ニオン( Xフ?イル?イプ )
#define MV1_ANIMKEY_TYPE_VECTOR						(1)				// ベク??
#define MV1_ANIMKEY_TYPE_MATRIX4X4C					(2)				// ４?４行列の４列目( 0,0,0,1 )固定版
#define MV1_ANIMKEY_TYPE_MATRIX3X3					(3)				// ３?３行列
#define MV1_ANIMKEY_TYPE_FLAT						(4)				// フラット
#define MV1_ANIMKEY_TYPE_LINEAR						(5)				// 線?補間
#define MV1_ANIMKEY_TYPE_BLEND						(6)				// 混合
#define MV1_ANIMKEY_TYPE_QUATERNION_VMD				(7)				// クォ??ニオン( VMD?イプ )

// ?画先画面指定用定?
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe) 
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffffb)

#define DX_NONE_GRAPH								(0xfffffffb)	// グラフィックなしハンドル

// グラフィック減色時の画像劣化緩和処理モ?ド
#define DX_SHAVEDMODE_NONE							(0)				// 画像劣化緩和処理を行わない
#define DX_SHAVEDMODE_DITHER						(1)				// ディザリング
#define DX_SHAVEDMODE_DIFFUS						(2)				// 誤差拡散

// 画像の保存?イプ
#define DX_IMAGESAVETYPE_BMP						(0)				// bitmap
#define DX_IMAGESAVETYPE_JPEG						(1)				// jpeg
#define DX_IMAGESAVETYPE_PNG						(2)				// Png

// サウンド再生?態指定用定?
#define DX_PLAYTYPE_LOOPBIT							(0x0002)		// ル?プ再生ビット
#define DX_PLAYTYPE_BACKBIT							(0x0001)		// バックグラウンド再生ビット

#define DX_PLAYTYPE_NORMAL							(0)												// ノ??ル再生
#define DX_PLAYTYPE_BACK				  			( DX_PLAYTYPE_BACKBIT )							// バックグラウンド再生
#define DX_PLAYTYPE_LOOP							( DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT )	// ル?プ再生

// 動画再生?イプ定?
#define DX_MOVIEPLAYTYPE_BCANCEL					(0)				// ??ンキャンセルあり
#define DX_MOVIEPLAYTYPE_NORMAL						(1)				// ??ンキャンセルなし

// サウンドの?イプ
#define DX_SOUNDTYPE_NORMAL							(0)				// ノ??ルサウンド?式
#define DX_SOUNDTYPE_STREAMSTYLE					(1)				// ストリ??風サウンド?式

// サウンドデ???イプの?クロ
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)				// 圧縮された全デ??は再生が始まる前にサウンドメモリにすべて解?され、格?される
#define DX_SOUNDDATATYPE_MEMNOPRESS_PLUS			(1)				// 圧縮された全デ??はシステ?メモリに格?され、再生しながら?次解?され、最終的にすべてサウンドメモリに格?される(その後システ?メモリに存在する圧縮デ??は破棄される)
#define DX_SOUNDDATATYPE_MEMPRESS					(2)				// 圧縮された全デ??はシステ?メモリに格?され、再生する部分だけ?次解?しながらサウンドメモリに格?する(鳴らし終わると解?したデ??は破棄されるので何度も解?処理が行われる)
#define DX_SOUNDDATATYPE_FILE						(3)				// 圧縮されたデ??の再生する部分だけフ?イルから?次読み込み解?され、サウンドメモリに格?される(鳴らし終わると解?したデ??は破棄されるので何度も解?処理が行われる)

// 読み込み処理の?イプ
#define DX_READSOUNDFUNCTION_PCM					(0x0001)		// PCM の読み込み処理
#define DX_READSOUNDFUNCTION_ACM					(0x0002)		// ACM を使用した読み込み処理
#define DX_READSOUNDFUNCTION_OGG					(0x0004)		// Ogg Vorbis の読み込み処理
#define DX_READSOUNDFUNCTION_MP3					(0x0008)		// ACM を使用した MP3 の読み込み処理
#define DX_READSOUNDFUNCTION_DSMP3					(0x0010)		// DirectShow を使用した MP3 の読み込み処理

// ３Ｄサウンドリバ?ブエフェクトのプリセット
#define DX_REVERB_PRESET_DEFAULT					(0)				// デフォルト
#define DX_REVERB_PRESET_GENERIC					(1)				// 一般的な空間
#define DX_REVERB_PRESET_PADDEDCELL					(2)				// 精?病患者室(？)
#define DX_REVERB_PRESET_ROOM						(3)				// 部屋
#define DX_REVERB_PRESET_BATHROOM					(4)				// バスル??
#define DX_REVERB_PRESET_LIVINGROOM					(5)				// リビングル??
#define DX_REVERB_PRESET_STONEROOM					(6)				// 石の部屋
#define DX_REVERB_PRESET_AUDITORIUM					(7)				// 講堂
#define DX_REVERB_PRESET_CONCERTHALL				(8)				// コンサ?トホ?ル
#define DX_REVERB_PRESET_CAVE						(9)				// 洞穴
#define DX_REVERB_PRESET_ARENA						(10)			// 舞台
#define DX_REVERB_PRESET_HANGAR						(11)			// 格?庫
#define DX_REVERB_PRESET_CARPETEDHALLWAY			(12)			// カ?ペットが?かれた玄関
#define DX_REVERB_PRESET_HALLWAY					(13)			// 玄関
#define DX_REVERB_PRESET_STONECORRIDOR				(14)			// 石の廊下
#define DX_REVERB_PRESET_ALLEY						(15)			// 裏通り
#define DX_REVERB_PRESET_FOREST						(16)			// 森
#define DX_REVERB_PRESET_CITY						(17)			// 都市
#define DX_REVERB_PRESET_MOUNTAINS					(18)			// 山
#define DX_REVERB_PRESET_QUARRY						(19)			// 採石場
#define DX_REVERB_PRESET_PLAIN						(20)			// 平原
#define DX_REVERB_PRESET_PARKINGLOT					(21)			// 駐車場
#define DX_REVERB_PRESET_SEWERPIPE					(22)			// 下水管
#define DX_REVERB_PRESET_UNDERWATER					(23)			// 水面下
#define DX_REVERB_PRESET_SMALLROOM					(24)			// 小部屋
#define DX_REVERB_PRESET_MEDIUMROOM					(25)			// 中部屋
#define DX_REVERB_PRESET_LARGEROOM					(26)			// 大部屋
#define DX_REVERB_PRESET_MEDIUMHALL					(27)			// 中ホ?ル
#define DX_REVERB_PRESET_LARGEHALL					(28)			// 大ホ?ル
#define DX_REVERB_PRESET_PLATE						(29)			// 板

#define DX_REVERB_PRESET_NUM						(30)			// プリセットの数

// ?スク透過色モ?ド
#define DX_MASKTRANS_WHITE							(0)				// ?スク画像の白い部分を透過色とする
#define DX_MASKTRANS_BLACK							(1)				// ?スク画像の黒い部分を透過色とする
#define DX_MASKTRANS_NONE							(2) 			// 透過色なし

// Ｚバッフ?書き込みモ?ド
#define DX_ZWRITE_MASK								(0)				// 書き込めないように?スクする
#define DX_ZWRITE_CLEAR								(1)				// 書き込めるように?スクをクリアする

// 比較モ?ド
#define DX_CMP_NEVER								(1)				// FALSE
#define DX_CMP_LESS									(2)				// Src <  Dest		DrawAlpha <  TestParam
#define DX_CMP_EQUAL								(3)				// Src == Dest		DrawAlpha == TestParam
#define DX_CMP_LESSEQUAL							(4)				// Src <= Dest		DrawAlpha <= TestParam
#define DX_CMP_GREATER								(5)				// Src >  Dest		DrawAlpha >  TestParam
#define DX_CMP_NOTEQUAL								(6)				// Src != Dest		DrawAlpha != TestParam
#define DX_CMP_GREATEREQUAL							(7)				// Src >= Dest		DrawAlpha >= TestParam
#define DX_CMP_ALWAYS								(8)				// TRUE
#define DX_ZCMP_DEFAULT								( DX_CMP_LESSEQUAL )
#define DX_ZCMP_REVERSE								( DX_CMP_GREATEREQUAL )

// シェ?ディングモ?ド
#define DX_SHADEMODE_FLAT							D_D3DSHADE_FLAT
#define DX_SHADEMODE_GOURAUD						D_D3DSHADE_GOURAUD

// フォグモ?ド
#define DX_FOGMODE_NONE								D_D3DFOG_NONE
#define DX_FOGMODE_EXP								D_D3DFOG_EXP
#define DX_FOGMODE_EXP2								D_D3DFOG_EXP2
#define DX_FOGMODE_LINEAR							D_D3DFOG_LINEAR

// ?テリアル?イプ
#define DX_MATERIAL_TYPE_NORMAL						(0)				// 標??テリアル
#define DX_MATERIAL_TYPE_TOON						(1)				// トゥ?ンレン?リング用?テリアル
#define DX_MATERIAL_TYPE_TOON_2						(2)				// トゥ?ンレン?リング用?テリアル_?イプ２( MMD互換 )

// ?テリアルブレンド?イプ
#define DX_MATERIAL_BLENDTYPE_TRANSLUCENT			(0)				// アルフ?合成
#define DX_MATERIAL_BLENDTYPE_ADDITIVE				(1)				// 加算
#define DX_MATERIAL_BLENDTYPE_MODULATE				(2)				// 乗算
#define DX_MATERIAL_BLENDTYPE_NONE					(3)				// 無効

// テクス?ャアドレス?イプ
#define DX_TEXADDRESS_WRAP							D_D3DTADDRESS_WRAP
#define DX_TEXADDRESS_MIRROR						D_D3DTADDRESS_MIRROR
#define DX_TEXADDRESS_CLAMP							D_D3DTADDRESS_CLAMP
#define DX_TEXADDRESS_BORDER						D_D3DTADDRESS_BORDER

// 頂?デ???イプ
#define DX_VERTEX_TYPE_NORMAL_3D					(0)				// VERTEX3D?造体?式
#define DX_VERTEX_TYPE_SHADER_3D					(1)				// VERTEX3DSHADER?造体?式
#define DX_VERTEX_TYPE_NUM							(2)

// インデックスデ???イプ
#define DX_INDEX_TYPE_16BIT							(0)				// 16bitインデックス
#define DX_INDEX_TYPE_32BIT							(1)				// 32bitインデックス

// モデルフ?イル読み込み時の物理演算モ?ド
#define DX_LOADMODEL_PHYSICS_DISABLE				(1)				// 物理演算を使用しない
#define DX_LOADMODEL_PHYSICS_LOADCALC				(0)				// 読み込み時に計算
#define DX_LOADMODEL_PHYSICS_REALTIME				(2)				// 実行時計算

// モデルの半透明要素がある箇所に関する?画モ?ド
#define DX_SEMITRANSDRAWMODE_ALWAYS					(0)				// 半透明かどうか関係なく?画する
#define DX_SEMITRANSDRAWMODE_SEMITRANS_ONLY			(1)				// 半透明のもののみ?画する
#define DX_SEMITRANSDRAWMODE_NOT_SEMITRANS_ONLY		(2)				// 半透明ではないもののみ?画する

// キュ?ブ?ップの面番号
#define DX_CUBEMAP_FACE_POSITIVE_X					(0)
#define DX_CUBEMAP_FACE_NEGATIVE_X					(1)
#define DX_CUBEMAP_FACE_POSITIVE_Y					(2)
#define DX_CUBEMAP_FACE_NEGATIVE_Y					(3)
#define DX_CUBEMAP_FACE_POSITIVE_Z					(4)
#define DX_CUBEMAP_FACE_NEGATIVE_Z					(5)

// ?リゴン?画?イプ
#define DX_PRIMTYPE_POINTLIST						D_D3DPT_POINTLIST
#define DX_PRIMTYPE_LINELIST						D_D3DPT_LINELIST
#define DX_PRIMTYPE_LINESTRIP						D_D3DPT_LINESTRIP
#define DX_PRIMTYPE_TRIANGLELIST					D_D3DPT_TRIANGLELIST
#define DX_PRIMTYPE_TRIANGLESTRIP					D_D3DPT_TRIANGLESTRIP
#define DX_PRIMTYPE_TRIANGLEFAN						D_D3DPT_TRIANGLEFAN

// ライト?イプ
#define DX_LIGHTTYPE_D3DLIGHT_POINT					D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_D3DLIGHT_SPOT					D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL			D_D3DLIGHT_DIRECTIONAL
#define DX_LIGHTTYPE_D3DLIGHT_FORCEDWORD			D_D3DLIGHT_FORCE_DWORD
#define DX_LIGHTTYPE_POINT							D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_SPOT							D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_DIRECTIONAL					D_D3DLIGHT_DIRECTIONAL

// グラフィックイメ?ジフォ??ットの定?
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB16					(0)		// １６ビットカラ?標?
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB32					(1)		// ３２ビットカラ?標?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16				(2)		// α?ャンネル付き１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32				(3)		// α?ャンネル付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16			(4)		// αテスト付き１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32			(5)		// αテスト付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT1						(6)		// ＤＸＴ１
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT2						(7)		// ＤＸＴ２
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT3						(8)		// ＤＸＴ３
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT4						(9)		// ＤＸＴ４
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT5 					(10)	// ＤＸＴ５
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16			(11)	// ?画可?１６ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32			(12)	// ?画可?３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32	(13)	// ?画可?α付き３２ビットカラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_I16		(14)	// ?画可?ARGB整数16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F16		(15)	// ?画可?ARGB浮動小数?16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F32		(16)	// ?画可?ARGB浮動小数?32ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I8			(17)	// ?画可?１?ャンネル整数8ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I16		(18)	// ?画可?１?ャンネル整数16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F16		(19)	// ?画可?１?ャンネル浮動少数16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F32		(20)	// ?画可?１?ャンネル浮動少数32ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I8			(21)	// ?画可?２?ャンネル整数8ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I16		(22)	// ?画可?２?ャンネル整数16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F16		(23)	// ?画可?２?ャンネル浮動少数16ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F32		(24)	// ?画可?２?ャンネル浮動少数32ビット?カラ?
#define DX_GRAPHICSIMAGE_FORMAT_3D_NUM						(25)
#define DX_GRAPHICSIMAGE_FORMAT_2D							(26)	// 標?( DirectDrawSurface の場合はこれのみ )
#define DX_GRAPHICSIMAGE_FORMAT_R5G6B5						(27)	// R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5					(28)	// X8A8R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8					(29)	// X8R8G8B8( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8					(30)	// A8R8G8B8( MEMIMG 用 )

#define DX_GRAPHICSIMAGE_FORMAT_NUM							(31)	// グラフィックフォ??ットの種類の数

// 基?イメ?ジのピクセルフォ??ット
#define DX_BASEIMAGE_FORMAT_NORMAL					(0)			// 普通の画像
#define DX_BASEIMAGE_FORMAT_DXT1					(1)			// ＤＸＴ１
#define DX_BASEIMAGE_FORMAT_DXT2					(2)			// ＤＸＴ２
#define DX_BASEIMAGE_FORMAT_DXT3					(3)			// ＤＸＴ３
#define DX_BASEIMAGE_FORMAT_DXT4					(4)			// ＤＸＴ４
#define DX_BASEIMAGE_FORMAT_DXT5					(5)			// ＤＸＴ５

// ツ?ルバ?の??ンの状態
#define TOOLBUTTON_STATE_ENABLE						(0)			// 入力可?な状態
#define TOOLBUTTON_STATE_PRESSED					(1)			// 押されている状態
#define TOOLBUTTON_STATE_DISABLE					(2)			// 入力不可?な状態
#define TOOLBUTTON_STATE_PRESSED_DISABLE			(3)			// 押されている状態で、入力不可?な状態
#define TOOLBUTTON_STATE_NUM						(4)			// ツ?ルバ?の??ンの状態の数

// ツ?ルバ?の??ンの?イプ
#define TOOLBUTTON_TYPE_NORMAL						(0)			// 普通の??ン
#define TOOLBUTTON_TYPE_CHECK						(1)			// 押すごとにＯＮ?ＯＦＦが切り替わる??ン
#define TOOLBUTTON_TYPE_GROUP						(2)			// 別の TOOLBUTTON_TYPE_GROUP ?イプの??ンが押されるとＯＦＦになる?イプの??ン(グル?プの区切りは隙間で)
#define TOOLBUTTON_TYPE_SEP							(3)			// 隙間(??ンではありません)
#define TOOLBUTTON_TYPE_NUM							(4)			// ツ?ルバ?の??ンの?イプの数

// 親メニュ?のＩＤ
#define MENUITEM_IDTOP								(0xabababab)

// メニュ?に追加する際の?イプ
#define MENUITEM_ADD_CHILD							(0)				// 指定の?目の子として追加する
#define MENUITEM_ADD_INSERT							(1)				// 指定の?目と指定の?目より一つ上の?目の間に追加する

// メニュ?の横に付く??ク?イプ
#define MENUITEM_MARK_NONE							(0)				// 何も付け無い
#define MENUITEM_MARK_CHECK							(1)				// ?ェック??ク
#define MENUITEM_MARK_RADIO							(2)				// ラジオ??ン

// 文字変換?イプ定?
#define DX_NUMMODE_10								(0)				// １０進数
#define DX_NUMMODE_16								(1)				// １６進数
#define DX_STRMODE_NOT0								(2)				// 空きを０で埋めない
#define DX_STRMODE_USE0								(3)				// 空きを０で埋める

// CheckHitKeyAll で調べる入力?イプ
#define DX_CHECKINPUT_KEY							(0x0001)		// キ?入力を調べる
#define DX_CHECKINPUT_PAD							(0x0002)		// パッド入力を調べる
#define DX_CHECKINPUT_MOUSE							(0x0004)		// ?ウス??ン入力を調べる
#define DX_CHECKINPUT_ALL							(DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE)	// すべての入力を調べる

// パッド入力取得パラメ??
#define DX_INPUT_KEY_PAD1							(0x1001)		// キ?入力とパッド１入力
#define DX_INPUT_PAD1								(0x0001)		// パッド１入力
#define DX_INPUT_PAD2								(0x0002)		// パッド２入力
#define DX_INPUT_PAD3								(0x0003)		// パッド３入力
#define DX_INPUT_PAD4								(0x0004)		// パッド４入力
#define DX_INPUT_PAD5								(0x0005)		// パッド５入力
#define DX_INPUT_PAD6								(0x0006)		// パッド６入力
#define DX_INPUT_PAD7								(0x0007)		// パッド７入力
#define DX_INPUT_PAD8								(0x0008)		// パッド８入力
#define DX_INPUT_PAD9								(0x0009)		// パッド９入力
#define DX_INPUT_PAD10								(0x000a)		// パッド１０入力
#define DX_INPUT_PAD11								(0x000b)		// パッド１１入力
#define DX_INPUT_PAD12								(0x000c)		// パッド１２入力
#define DX_INPUT_PAD13								(0x000d)		// パッド１３入力
#define DX_INPUT_PAD14								(0x000e)		// パッド１４入力
#define DX_INPUT_PAD15								(0x000f)		// パッド１５入力
#define DX_INPUT_PAD16								(0x0010)		// パッド１６入力
#define DX_INPUT_KEY								(0x1000)		// キ?入力

// ??ビ?のサ?フェスモ?ド
#define DX_MOVIESURFACE_NORMAL						(0)
#define DX_MOVIESURFACE_OVERLAY						(1)
#define DX_MOVIESURFACE_FULLCOLOR					(2)

// パッド入力定?
#define PAD_INPUT_DOWN								(0x00000001)	// ↓?ェック?スク
#define PAD_INPUT_LEFT								(0x00000002)	// ←?ェック?スク
#define PAD_INPUT_RIGHT								(0x00000004)	// →?ェック?スク
#define PAD_INPUT_UP								(0x00000008)	// ↑?ェック?スク
#define PAD_INPUT_A									(0x00000010)	// ???ン?ェック?スク
#define PAD_INPUT_B									(0x00000020)	// Ｂ??ン?ェック?スク
#define PAD_INPUT_C									(0x00000040)	// Ｃ??ン?ェック?スク
#define PAD_INPUT_X									(0x00000080)	// Ｘ??ン?ェック?スク
#define PAD_INPUT_Y									(0x00000100)	// Ｙ??ン?ェック?スク
#define PAD_INPUT_Z									(0x00000200)	// Ｚ??ン?ェック?スク
#define PAD_INPUT_L									(0x00000400)	// Ｌ??ン?ェック?スク
#define PAD_INPUT_R									(0x00000800)	// Ｒ??ン?ェック?スク
#define PAD_INPUT_START								(0x00001000)	// ＳＴ?ＲＴ??ン?ェック?スク
#define PAD_INPUT_M									(0x00002000)	// Ｍ??ン?ェック?スク
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)

#define PAD_INPUT_1									(0x00000010)
#define PAD_INPUT_2									(0x00000020)
#define PAD_INPUT_3									(0x00000040)
#define PAD_INPUT_4									(0x00000080)
#define PAD_INPUT_5									(0x00000100)
#define PAD_INPUT_6									(0x00000200)
#define PAD_INPUT_7									(0x00000400)
#define PAD_INPUT_8									(0x00000800)
#define PAD_INPUT_9									(0x00001000)
#define PAD_INPUT_10								(0x00002000)
#define PAD_INPUT_11								(0x00004000)
#define PAD_INPUT_12								(0x00008000)
#define PAD_INPUT_13								(0x00010000)
#define PAD_INPUT_14								(0x00020000)
#define PAD_INPUT_15								(0x00040000)
#define PAD_INPUT_16								(0x00080000)
#define PAD_INPUT_17								(0x00100000)
#define PAD_INPUT_18								(0x00200000)
#define PAD_INPUT_19								(0x00400000)
#define PAD_INPUT_20								(0x00800000)
#define PAD_INPUT_21								(0x01000000)
#define PAD_INPUT_22								(0x02000000)
#define PAD_INPUT_23								(0x04000000)
#define PAD_INPUT_24								(0x08000000)
#define PAD_INPUT_25								(0x10000000)
#define PAD_INPUT_26								(0x20000000)
#define PAD_INPUT_27								(0x40000000)
#define PAD_INPUT_28								(0x80000000)

// XInput??ン入力定?
#define XINPUT_BUTTON_DPAD_UP						(0)					// デジ?ル方向??ン上
#define XINPUT_BUTTON_DPAD_DOWN						(1)					// デジ?ル方向??ン下
#define XINPUT_BUTTON_DPAD_LEFT						(2)					// デジ?ル方向??ン左
#define XINPUT_BUTTON_DPAD_RIGHT					(3)					// デジ?ル方向??ン右
#define XINPUT_BUTTON_START							(4)					// START??ン
#define XINPUT_BUTTON_BACK							(5)					// BACK??ン
#define XINPUT_BUTTON_LEFT_THUMB					(6)					// 左スティック押し込み
#define XINPUT_BUTTON_RIGHT_THUMB					(7)					// 右スティック押し込み
#define XINPUT_BUTTON_LEFT_SHOULDER					(8)					// LB??ン
#define XINPUT_BUTTON_RIGHT_SHOULDER				(9)					// RB??ン
#define XINPUT_BUTTON_A								(12)				// A??ン
#define XINPUT_BUTTON_B								(13)				// B??ン
#define XINPUT_BUTTON_X								(14)				// X??ン
#define XINPUT_BUTTON_Y								(15)				// Y??ン

// ?ウス入力定?
#define MOUSE_INPUT_LEFT							(0x0001)			// ?ウス左??ン
#define MOUSE_INPUT_RIGHT							(0x0002)			// ?ウス右??ン
#define MOUSE_INPUT_MIDDLE							(0x0004)			// ?ウス中央??ン
#define MOUSE_INPUT_1								(0x0001)			// ?ウス１??ン
#define MOUSE_INPUT_2								(0x0002)			// ?ウス２??ン
#define MOUSE_INPUT_3								(0x0004)			// ?ウス３??ン
#define MOUSE_INPUT_4								(0x0008)			// ?ウス４??ン
#define MOUSE_INPUT_5								(0x0010)			// ?ウス５??ン
#define MOUSE_INPUT_6								(0x0020)			// ?ウス６??ン
#define MOUSE_INPUT_7								(0x0040)			// ?ウス７??ン
#define MOUSE_INPUT_8								(0x0080)			// ?ウス８??ン

// キ?定?
#define KEY_INPUT_BACK								D_DIK_BACK			// バックスペ?スキ?
#define KEY_INPUT_TAB								D_DIK_TAB			// ?ブキ?
#define KEY_INPUT_RETURN							D_DIK_RETURN		// エン??キ?

#define KEY_INPUT_LSHIFT							D_DIK_LSHIFT		// 左シフトキ?
#define KEY_INPUT_RSHIFT							D_DIK_RSHIFT		// 右シフトキ?
#define KEY_INPUT_LCONTROL							D_DIK_LCONTROL		// 左コントロ?ルキ?
#define KEY_INPUT_RCONTROL							D_DIK_RCONTROL		// 右コントロ?ルキ?
#define KEY_INPUT_ESCAPE							D_DIK_ESCAPE		// エスケ?プキ?
#define KEY_INPUT_SPACE								D_DIK_SPACE			// スペ?スキ?
#define KEY_INPUT_PGUP								D_DIK_PGUP			// ＰａｇｅＵＰキ?
#define KEY_INPUT_PGDN								D_DIK_PGDN			// ＰａｇｅＤｏｗｎキ?
#define KEY_INPUT_END								D_DIK_END			// エンドキ?
#define KEY_INPUT_HOME								D_DIK_HOME			// ホ??キ?
#define KEY_INPUT_LEFT								D_DIK_LEFT			// 左キ?
#define KEY_INPUT_UP								D_DIK_UP			// 上キ?
#define KEY_INPUT_RIGHT								D_DIK_RIGHT			// 右キ?
#define KEY_INPUT_DOWN								D_DIK_DOWN			// 下キ?
#define KEY_INPUT_INSERT							D_DIK_INSERT		// インサ?トキ?
#define KEY_INPUT_DELETE							D_DIK_DELETE		// デリ?トキ?

#define KEY_INPUT_MINUS								D_DIK_MINUS			// ?キ?
#define KEY_INPUT_YEN								D_DIK_YEN			// ￥キ?
#define KEY_INPUT_PREVTRACK							D_DIK_PREVTRACK		// ＾キ?
#define KEY_INPUT_PERIOD							D_DIK_PERIOD		// ．キ?
#define KEY_INPUT_SLASH								D_DIK_SLASH			// ?キ?
#define KEY_INPUT_LALT								D_DIK_LALT			// 左?ＬＴキ?
#define KEY_INPUT_RALT								D_DIK_RALT			// 右?ＬＴキ?
#define KEY_INPUT_SCROLL							D_DIK_SCROLL		// ScrollLockキ?
#define KEY_INPUT_SEMICOLON							D_DIK_SEMICOLON		// ；キ?
#define KEY_INPUT_COLON								D_DIK_COLON			// ：キ?
#define KEY_INPUT_LBRACKET							D_DIK_LBRACKET		// ［キ?
#define KEY_INPUT_RBRACKET							D_DIK_RBRACKET		// ］キ?
#define KEY_INPUT_AT								D_DIK_AT			// ＠キ?
#define KEY_INPUT_BACKSLASH							D_DIK_BACKSLASH		// ?キ?
#define KEY_INPUT_COMMA								D_DIK_COMMA			// ，キ?
#define KEY_INPUT_KANJI								D_DIK_KANJI			// 漢字キ?
#define KEY_INPUT_CONVERT							D_DIK_CONVERT		// 変換キ?
#define KEY_INPUT_NOCONVERT							D_DIK_NOCONVERT		// 無変換キ?
#define KEY_INPUT_KANA								D_DIK_KANA			// カナキ?
#define KEY_INPUT_APPS								D_DIK_APPS			// アプリケ?ションメニュ?キ?
#define KEY_INPUT_CAPSLOCK							D_DIK_CAPSLOCK		// CaspLockキ?
#define KEY_INPUT_SYSRQ								D_DIK_SYSRQ			// PrintScreenキ?
#define KEY_INPUT_PAUSE								D_DIK_PAUSE			// PauseBreakキ?
#define KEY_INPUT_LWIN								D_DIK_LWIN			// 左Ｗｉｎキ?
#define KEY_INPUT_RWIN								D_DIK_RWIN			// 右Ｗｉｎキ?

#define KEY_INPUT_NUMLOCK							D_DIK_NUMLOCK		// テンキ?０
#define KEY_INPUT_NUMPAD0							D_DIK_NUMPAD0		// テンキ?０
#define KEY_INPUT_NUMPAD1							D_DIK_NUMPAD1		// テンキ?１
#define KEY_INPUT_NUMPAD2							D_DIK_NUMPAD2		// テンキ?２
#define KEY_INPUT_NUMPAD3							D_DIK_NUMPAD3		// テンキ?３
#define KEY_INPUT_NUMPAD4							D_DIK_NUMPAD4		// テンキ?４
#define KEY_INPUT_NUMPAD5							D_DIK_NUMPAD5		// テンキ?５
#define KEY_INPUT_NUMPAD6							D_DIK_NUMPAD6		// テンキ?６
#define KEY_INPUT_NUMPAD7							D_DIK_NUMPAD7		// テンキ?７
#define KEY_INPUT_NUMPAD8							D_DIK_NUMPAD8		// テンキ?８
#define KEY_INPUT_NUMPAD9							D_DIK_NUMPAD9		// テンキ?９
#define KEY_INPUT_MULTIPLY							D_DIK_MULTIPLY		// テンキ?＊キ?
#define KEY_INPUT_ADD								D_DIK_ADD			// テンキ??キ?
#define KEY_INPUT_SUBTRACT							D_DIK_SUBTRACT		// テンキ??キ?
#define KEY_INPUT_DECIMAL							D_DIK_DECIMAL		// テンキ?．キ?
#define KEY_INPUT_DIVIDE							D_DIK_DIVIDE		// テンキ??キ?
#define KEY_INPUT_NUMPADENTER						D_DIK_NUMPADENTER	// テンキ?のエン??キ?

#define KEY_INPUT_F1								D_DIK_F1			// Ｆ１キ?
#define KEY_INPUT_F2								D_DIK_F2			// Ｆ２キ?
#define KEY_INPUT_F3								D_DIK_F3			// Ｆ３キ?
#define KEY_INPUT_F4								D_DIK_F4			// Ｆ４キ?
#define KEY_INPUT_F5								D_DIK_F5			// Ｆ５キ?
#define KEY_INPUT_F6								D_DIK_F6			// Ｆ６キ?
#define KEY_INPUT_F7								D_DIK_F7			// Ｆ７キ?
#define KEY_INPUT_F8								D_DIK_F8			// Ｆ８キ?
#define KEY_INPUT_F9								D_DIK_F9			// Ｆ９キ?
#define KEY_INPUT_F10								D_DIK_F10			// Ｆ１０キ?
#define KEY_INPUT_F11								D_DIK_F11			// Ｆ１１キ?
#define KEY_INPUT_F12								D_DIK_F12			// Ｆ１２キ?

#define KEY_INPUT_A									D_DIK_A			// ?キ?
#define KEY_INPUT_B									D_DIK_B			// Ｂキ?
#define KEY_INPUT_C									D_DIK_C			// Ｃキ?
#define KEY_INPUT_D									D_DIK_D			// Ｄキ?
#define KEY_INPUT_E									D_DIK_E			// Ｅキ?
#define KEY_INPUT_F									D_DIK_F			// Ｆキ?
#define KEY_INPUT_G									D_DIK_G			// Ｇキ?
#define KEY_INPUT_H									D_DIK_H			// Ｈキ?
#define KEY_INPUT_I									D_DIK_I			// Ｉキ?
#define KEY_INPUT_J									D_DIK_J			// Ｊキ?
#define KEY_INPUT_K									D_DIK_K			// Ｋキ?
#define KEY_INPUT_L									D_DIK_L			// Ｌキ?
#define KEY_INPUT_M									D_DIK_M			// Ｍキ?
#define KEY_INPUT_N									D_DIK_N			// Ｎキ?
#define KEY_INPUT_O									D_DIK_O			// Ｏキ?
#define KEY_INPUT_P									D_DIK_P			// Ｐキ?
#define KEY_INPUT_Q									D_DIK_Q			// Ｑキ?
#define KEY_INPUT_R									D_DIK_R			// Ｒキ?
#define KEY_INPUT_S									D_DIK_S			// Ｓキ?
#define KEY_INPUT_T									D_DIK_T			// Ｔキ?
#define KEY_INPUT_U									D_DIK_U			// Ｕキ?
#define KEY_INPUT_V									D_DIK_V			// Ｖキ?
#define KEY_INPUT_W									D_DIK_W			// Ｗキ?
#define KEY_INPUT_X									D_DIK_X			// Ｘキ?
#define KEY_INPUT_Y									D_DIK_Y			// Ｙキ?
#define KEY_INPUT_Z									D_DIK_Z			// Ｚキ?

#define KEY_INPUT_0 								D_DIK_0			// ０キ?
#define KEY_INPUT_1									D_DIK_1			// １キ?
#define KEY_INPUT_2									D_DIK_2			// ２キ?
#define KEY_INPUT_3									D_DIK_3			// ３キ?
#define KEY_INPUT_4									D_DIK_4			// ４キ?
#define KEY_INPUT_5									D_DIK_5			// ５キ?
#define KEY_INPUT_6									D_DIK_6			// ６キ?
#define KEY_INPUT_7									D_DIK_7			// ７キ?
#define KEY_INPUT_8									D_DIK_8			// ８キ?
#define KEY_INPUT_9									D_DIK_9			// ９キ?

// アスキ?コントロ?ルキ?コ?ド
#define CTRL_CODE_BS								(0x08)				// バックスペ?ス
#define CTRL_CODE_TAB								(0x09)				// ?ブ
#define CTRL_CODE_CR								(0x0d)				// 改行
#define CTRL_CODE_DEL								(0x10)				// ＤＥＬキ?

#define CTRL_CODE_COPY								(0x03)				// コピ?
#define CTRL_CODE_PASTE								(0x16)				// ペ?スト
#define CTRL_CODE_CUT								(0x18)				// カット
#define CTRL_CODE_ALL								(0x01)				// 全て選択

#define CTRL_CODE_LEFT								(0x1d)				// ←キ?
#define CTRL_CODE_RIGHT								(0x1c)				// →キ?
#define CTRL_CODE_UP								(0x1e)				// ↑キ?
#define CTRL_CODE_DOWN								(0x1f)				// ↓キ?

#define CTRL_CODE_HOME								(0x1a)				// ＨＯＭＥ??ン
#define CTRL_CODE_END								(0x19)				// ＥＮＤ??ン
#define CTRL_CODE_PAGE_UP							(0x17)				// Ｐ?ＧＥ ＵＰ
#define CTRL_CODE_PAGE_DOWN							(0x15)				// Ｐ?ＧＥ ＤＯＷＮ

#define CTRL_CODE_ESC								(0x1b)				// ＥＳＣキ?
#define CTRL_CODE_CMP								(0x20)				// 制御コ?ド?居値

// SetGraphMode 戻り値定?
#define DX_CHANGESCREEN_OK							(0)					// 画面変更は成功した
#define DX_CHANGESCREEN_RETURN						(-1)				// 画面の変更は失敗し、元の画面モ?ドに戻された
#define DX_CHANGESCREEN_DEFAULT						(-2)				// 画面の変更は失敗しデフォルトの画面モ?ドに変更された
#define DX_CHANGESCREEN_REFRESHNORMAL				(-3)				// 画面の変更は成功したが、リフレッシュレ?トの変更は失敗した

// ストリ??デ??読み込み処理コ?ド簡略化関連
#define STTELL( st )								((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type )						((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st )				((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st )				((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st )									((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )								((st)->ReadShred.Close( (st)->DataPoint ))

// ストリ??デ??制御のシ?ク?イプ定?
#define STREAM_SEEKTYPE_SET							(SEEK_SET)
#define STREAM_SEEKTYPE_END							(SEEK_END)
#define STREAM_SEEKTYPE_CUR							(SEEK_CUR)

// グラフィックロ?ド時のイメ?ジ?イプ
#define LOADIMAGE_TYPE_FILE							(0)				// イメ?ジはフ?イルである
#define LOADIMAGE_TYPE_MEM							(1)				// イメ?ジはメモリである
#define LOADIMAGE_TYPE_NONE							(-1)			// イメ?ジは無い



#ifndef DX_NON_NETWORK

// HTTP エラ?
#define HTTP_ERR_SERVER								(0)				// サ?バ?エラ?
#define HTTP_ERR_NOTFOUND							(1)				// フ?イルが見つからなかった
#define HTTP_ERR_MEMORY								(2)				// メモリ確保の失敗
#define HTTP_ERR_LOST								(3)				// 途中で切断された
#define HTTP_ERR_NONE								(-1)			// エラ?は報告されていない

// HTTP 処理の結果
#define HTTP_RES_COMPLETE							(0)				// 処理完了
#define HTTP_RES_STOP								(1)				// 処理中?
#define HTTP_RES_ERROR								(2)				// エラ?終了
#define HTTP_RES_NOW								(-1)			// 現在進行中

#endif // DX_NON_NETWORK

#define DX_DEFINE_END

// デ???定?-------------------------------------------------------------------

namespace DxLib
{

#define DX_STRUCT_START

// ＩＭＥ入力文字列の?画に必要な情報の内の文節情報
typedef struct tagIMEINPUTCLAUSEDATA
{
	int						Position ;				// 何バイト目から
	int						Length ;				// 何バイトか
} IMEINPUTCLAUSEDATA, *LPIMEINPUTCLAUSEDATA ;

// ＩＭＥ入力文字列の?画に必要な情報
typedef struct tagIMEINPUTDATA
{
	const TCHAR *				InputString ;			// 入力中の文字列

	int							CursorPosition ;		// カ??ルの入力文字列中の位置(バイト単位)

	const IMEINPUTCLAUSEDATA *	ClauseData ;			// 文節情報
	int							ClauseNum ;				// 文節情報の数
	int							SelectClause ;			// 選択中の分節( -1 の場合はどの文節にも属していない( 末尾にカ??ルがある ) )

	int							CandidateNum ;			// 変換候補の数( 0の場合は変換中ではない )
	const TCHAR **				CandidateList ;			// 変換候補文字列リスト( 例：ｎ番目の候補を?画する場合  DrawString( 0, 0, data.CandidateList[ n ], GetColor(255,255,255) ); )
	int							SelectCandidate ;		// 選択中の変換候補

	int							ConvertFlag ;			// 文字変換中かどうか( TRUE:変換中  FALSE:変換中ではない( 文字単位でカ??ルが移動できる状態 ) )
} IMEINPUTDATA, *LPIMEINPUTDATA ;

// 画面モ?ド情報デ???
typedef struct tagDISPLAYMODEDATA
{
	int						Width ;				// 水平解像度
	int						Height ;			// 垂直解像度
	int						ColorBitDepth ;		// 色ビット?度
	int						RefreshRate ;		// リフレッシュレ?ト( -1 の場合は規定値 )
} DISPLAYMODEDATA, *LPDISPLAYMODEDATA ;

// ?イ?デ???
typedef struct tagDATEDATA
{
	int						Year ;							// 年
	int						Mon ;							// 月
	int						Day ;							// 日
	int						Hour ;							// 時間
	int						Min ;							// 分
	int						Sec ;							// 秒
} DATEDATA, *LPDATEDATA ;

// フ?イル情報?造体
typedef struct tagFILEINFO
{
	TCHAR					Name[260] ;			// オブジェクト名
	int						DirFlag ;			// ディレクトリかどうか( TRUE:ディレクトリ  FALSE:フ?イル )
	LONGLONG				Size ;				// サイズ
	DATEDATA				CreationTime ;		// 作成日時
	DATEDATA				LastWriteTime ;		// 最終更新日時
} FILEINFO, *LPFILEINFO ;

#ifndef DX_NOTUSE_DRAWFUNCTION

// 行列?造体
typedef struct tagMATRIX
{
	float					m[4][4] ;
} MATRIX, *LPMATRIX ;

// ベクトルデ???
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, XYZ, *LPXYZ ;

// FLOAT2個デ???
typedef struct tagFLOAT2
{
	float					u, v ;
} UV ;

// float ?のカラ?値
typedef struct tagCOLOR_F
{
	float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;

// unsigned char ?のカラ?値
typedef struct tagCOLOR_U8
{
	BYTE					b, g, r, a ;
} COLOR_U8 ;

// FLOAT4個デ???
typedef struct tagFLOAT4
{
	float					x, y, z, w ;
} FLOAT4, *LPFLOAT4 ;

// INT4個デ???
typedef struct tagINT4
{
	int						x, y, z, w ;
} INT4 ;

// ２Ｄ?画に使用する頂?デ???(DrawPrimitive2D用)
typedef struct tagVERTEX2D
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	float					u, v ;
} VERTEX2D, *LPVERTEX2D ; 

// ２Ｄ?画に使用する頂?デ???(DrawPrimitive2DToShader用)
typedef struct tagVERTEX2DSHADER
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX2DSHADER, *LPVERTEX2DSHADER ; 

// ２Ｄ?画に使用する頂?デ???(公開用)
typedef struct tagVERTEX
{
	float					x, y ;
	float					u, v ;
	unsigned char			b, g, r, a ;
} VERTEX ;

// ３Ｄ?画に使用する頂?デ???( テクス?ャなし )( 旧バ?ジョンのもの )
typedef struct tagVERTEX_NOTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
} VERTEX_NOTEX_3D, *LPVERTEX_NOTEX_3D ;

// ３Ｄ?画に使用する頂?デ???( 旧バ?ジョンのもの )
typedef struct tagVERTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
	float					u, v ;
} VERTEX_3D, *LPVERTEX_3D ;

// ３Ｄ?画に使用する頂?デ???
typedef struct tagVERTEX3D
{
	VECTOR					pos ;						// 座標
	VECTOR					norm ;						// ?線
	COLOR_U8				dif ;						// ディフュ?ズカラ?
	COLOR_U8				spc ;						// スペキュラカラ?
	float					u, v ;						// テクス?ャ座標
	float					su, sv ;					// 補助テクス?ャ座標
} VERTEX3D, *LPVERTEX3D ;

// ３Ｄ?画に使用する頂?デ???( DrawPrimitive3DToShader用 )
// 注意…メンバ変数に追加があるかもしれませんので、宣言時の初期化( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... というようなもの )はしない方が良いです
typedef struct tagVERTEX3DSHADER
{
	VECTOR					pos ;						// 座標
	FLOAT4					spos ;						// 補助座標
	VECTOR					norm ;						// ?線
	VECTOR					tan ;						// 接線
	VECTOR					binorm ;					// ??線
	COLOR_U8				dif ;						// ディフュ?ズカラ?
	COLOR_U8				spc ;						// スペキュラカラ?
	float					u, v ;						// テクス?ャ座標
	float					su, sv ;					// 補助テクス?ャ座標
} VERTEX3DSHADER, *LPVERTEX3DSHADER ;

// ライトパラメ??
typedef struct tagLIGHTPARAM
{
	int						LightType ;					// ライトの?イプ( DX_LIGHTTYPE_D3DLIGHT_POINT 等 )
	COLOR_F					Diffuse ;					// ディフュ?ズカラ?
	COLOR_F					Specular ;					// スペキュラカラ?
	COLOR_F					Ambient ;					// アンビエント色
	VECTOR					Position ;					// 位置
	VECTOR					Direction ;					// 方向
	float					Range ;						// 有効距離
	float					Falloff ;					// フォ?ルオフ 1.0f にしておくのが好ましい
	float					Attenuation0 ;				// 距離による減衰係数０
	float					Attenuation1 ;				// 距離による減衰係数１
	float					Attenuation2 ;				// 距離による減衰係数２
	float					Theta ;						// ス?ットライトの内部コ?ンの照明角度( ラジアン )
	float					Phi ;						// ス?ットライトの外部コ?ンの照明角度
} LIGHTPARAM ;

// ?テリアルパラメ??
typedef struct tagMATERIALPARAM
{
	COLOR_F					Diffuse ;					// ディフュ?ズカラ?
	COLOR_F					Ambient ;					// アンビエントカラ?
	COLOR_F					Specular ;					// スペキュラカラ?
	COLOR_F					Emissive ;					// エ?ッシブカラ?
	float					Power ;						// スペキュラハイライトの鮮明度
} MATERIALPARAM ;

// ラインヒット?ェック結果格?用?造体
typedef struct tagHITRESULT_LINE
{
	int						HitFlag ;					// 当たったかどうか( 1:当たった  0:当たらなかった )
	VECTOR					Position ;					// 当たった座標
} HITRESULT_LINE ;

// 関数 Segment_Segment_Analyse の結果を受け取る為の?造体
typedef struct tagSEGMENT_SEGMENT_RESULT
{
	float					SegA_SegB_MinDist_Square ;	// 線分?と線分Ｂが最も接近する座標間の距離の二乗

	float					SegA_MinDist_Pos1_Pos2_t ;	// 線分?と線分Ｂに最も接近する座標の線分?の t ( 0.0f ? 1.0f 、最近?座標 = ( SegAPos2 - SegAPos1 ) * t + SegAPos1 )
	float					SegB_MinDist_Pos1_Pos2_t ;	// 線分Ｂが線分?に最も接近する座標の線分Ｂの t ( 0.0f ? 1.0f 、最近?座標 = ( SegBPos2 - SegBPos1 ) * t + SegBPos1 )

	VECTOR					SegA_MinDist_Pos ;			// 線分?が線分Ｂに最も接近する線分?上の座標
	VECTOR					SegB_MinDist_Pos ;			// 線分Ｂが線分?に最も接近する線分Ｂ上の座標
} SEGMENT_SEGMENT_RESULT ;

// 関数 Segment_Point_Analyse の結果を受け取る為の?造体
typedef struct tagSEGMENT_POINT_RESULT
{
	float					Seg_Point_MinDist_Square ;	// 線分と?が最も接近する座標間の距離の二乗
	float					Seg_MinDist_Pos1_Pos2_t ;	// 線分が?に最も接近する座標の線分の t ( 0.0f ? 1.0f 、最近?座標 = ( SegPos2 - SegPos1 ) * t + SegPos1 )
	VECTOR					Seg_MinDist_Pos ;			// 線分が?に最も接近する線分上の座標
} SEGMENT_POINT_RESULT ;

// 関数 Segment_Triangle_Analyse の結果を受け取る為の?造体
typedef struct tagSEGMENT_TRIANGLE_RESULT
{
	float					Seg_Tri_MinDist_Square ;	// 線分と三角?が最も接近する座標間の距離の二乗

	float					Seg_MinDist_Pos1_Pos2_t ;	// 線分が三角?に最も接近する座標の線分の t ( 0.0f ? 1.0f 、最近?座標 = ( SegPos2 - SegPos1 ) * t + SegPos1 )
	VECTOR					Seg_MinDist_Pos ;			// 線分が三角?に最も接近する線分上の座標

	float					Tri_MinDist_Pos1_w ;		// 三角?が線分に最も接近する座標の三角?座標１の重み( 最近?座標 = TriPos1 * TriPos1_w + TriPos2 * TriPos2_w + TriPos3 * TriPos3_w )
	float					Tri_MinDist_Pos2_w ;		// 三角?が線分に最も接近する座標の三角?座標２の重み
	float					Tri_MinDist_Pos3_w ;		// 三角?が線分に最も接近する座標の三角?座標３の重み
	VECTOR					Tri_MinDist_Pos ;			// 三角?が線分に最も接近する三角?上の座標
} SEGMENT_TRIANGLE_RESULT ;

// 関数 Triangle_Point_Analyse の結果を受け取る為の?造体
typedef struct tagTRIANGLE_POINT_RESULT
{
	float					Tri_Pnt_MinDist_Square ;	// 三角?と?が最も接近する座標間の距離の二乗

	float					Tri_MinDist_Pos1_w ;		// 三角?が?に最も接近する座標の三角?座標１の重み( 最近?座標 = TriPos1 * TriPos1_w + TriPos2 * TriPos2_w + TriPos3 * TriPos3_w )
	float					Tri_MinDist_Pos2_w ;		// 三角?が?に最も接近する座標の三角?座標２の重み
	float					Tri_MinDist_Pos3_w ;		// 三角?が?に最も接近する座標の三角?座標３の重み
	VECTOR					Tri_MinDist_Pos ;			// 三角?が?に最も接近する三角?上の座標
} TRIANGLE_POINT_RESULT ;

// 関数 Plane_Point_Analyse の結果を受け取る為の?造体
typedef struct tagPLANE_POINT_RESULT
{
	int						Pnt_Plane_Normal_Side ;		// ?が平面の?線の側にあるかどうか( 1:?線の側にある  0:?線と反対側にある )
	float					Plane_Pnt_MinDist_Square ;	// 平面と?の距離
	VECTOR					Plane_MinDist_Pos ;			// 平面上の?との最近?座標
} PLANE_POINT_RESULT ;

// コリジョン結果代入用?リゴン
typedef struct tagMV1_COLL_RESULT_POLY
{
	int						HitFlag ;							// ( MV1CollCheck_Line でのみ有効 )ヒットフラグ( 1:ヒットした  0:ヒットしなかった )
	VECTOR					HitPosition ;						// ( MV1CollCheck_Line でのみ有効 )ヒット座標

	int						FrameIndex ;						// 当たった?リゴンが含まれるフレ??の番号
	int						PolygonIndex ;						// 当たった?リゴンの番号
	int						MaterialIndex ;						// 当たった?リゴンが使用している?テリアルの番号
	VECTOR					Position[ 3 ] ;						// 当たった?リゴンを?成する三?の座標
	VECTOR					Normal ;							// 当たった?リゴンの?線
} MV1_COLL_RESULT_POLY ;

// コリジョン結果代入用?リゴン配列
typedef struct tagMV1_COLL_RESULT_POLY_DIM
{
	int						HitNum ;							// ヒットした?リゴンの数
	MV1_COLL_RESULT_POLY *	Dim ;								// ヒットした?リゴンの配列( HitNum個分存在する )
} MV1_COLL_RESULT_POLY_DIM ;

// 参照用頂??造体
typedef struct tagMV1_REF_VERTEX
{
	VECTOR					Position ;							// 位置
	VECTOR					Normal ;							// ?線
	UV						TexCoord[ 2 ] ;						// テクス?ャ座標
	COLOR_U8				DiffuseColor ;						// ディフュ?ズカラ?
	COLOR_U8				SpecularColor ;						// スペキュラカラ?
} MV1_REF_VERTEX ;

// 参照用?リゴン?造体
typedef struct tagMV1_REF_POLYGON
{
	unsigned short			FrameIndex ;						// この?リゴンが属しているフレ??
	unsigned short			MaterialIndex ;						// 使用している?テリアル
	int						VIndexTarget ;						// VIndex が指すインデックスの参照先( 1:フレ??  0:モデル全体 )
	int						VIndex[ 3 ] ;						// ３角??リゴンを成す参照頂?のインデックス
	VECTOR					MinPosition ;						// ?リゴンを成す頂?座標の最小値
	VECTOR					MaxPosition ;						// ?リゴンを成す頂?座標の最大値
} MV1_REF_POLYGON ;

// 参照用?リゴンデ???造体
typedef struct tagMV1_REF_POLYGONLIST
{
	int						PolygonNum ;						// 参照用?リゴンの数
	int						VertexNum ;							// 頂?の数
	VECTOR					MinPosition ;						// 頂?座標の最小値
	VECTOR					MaxPosition ;						// 頂?座標の最大値
	MV1_REF_POLYGON	*		Polygons ;							// 参照用?リゴン配列
	MV1_REF_VERTEX *		Vertexs ;							// 参照用頂?配列
} MV1_REF_POLYGONLIST ;

#endif // DX_NOTUSE_DRAWFUNCTION




// ３Ｄサウンドリバ?ブエフェクトパラメ???造体
// ( 注釈は MSDN の XAUDIO2FX_REVERB_PARAMETERS ?造体の解説をほぼ引用しています )
typedef struct tagSOUND3D_REVERB_PARAM
{
	float					WetDryMix ;							// リバ?ブとなる出力の割合( 指定可?範囲 0.0f ? 100.0f )

	unsigned int			ReflectionsDelay ;					// ?イレクト パスに対する初期反射の遅延時間、単位は?リ秒( 指定可?範囲 0 ? 300 )
	BYTE					ReverbDelay ;						// 初期反射に対するリバ?ブの遅延時間、単位は?リ秒( 指定可?範囲 0 ? 85 )
	BYTE					RearDelay ;							// 左後方出力および右後方出力の遅延時間、単位は?リ秒( 指定可?範囲 0 ? 5 )

	BYTE					PositionLeft ;						// シ?ュレ?ション空間における視聴者に対する左入力の位置( 指定可?範囲 0 ? 30 )
																// PositionLeft を最小値に設定した場合、左入力は視聴者の近くに配置されます。
																// この位置では、サウンド フィ?ルドにおいて初期反射が優勢になり、残響減衰は弱まって、振幅が小さくなります。
																// PositionLeft を最大値に設定した場合、左入力はシ?ュレ?ション室内で視聴者から最大限遠い位置に配置されます。
																// PositionLeft は残響減衰時間 (部屋の残響効果) に影響せず、視聴者に対する音源の見かけの位置のみに影響します。
	BYTE					PositionRight ;						// PositionLeft と同効果の右入力値( 指定可?範囲 0 ? 30 )、右入力にのみ影響を?える
	BYTE					PositionMatrixLeft ;				// 音源から視聴者までの距離によるインプレッションを増減させる値( 指定可?範囲 0 ? 30 )
	BYTE					PositionMatrixRight ;				// 音源から視聴者までの距離によるインプレッションを増減させま値( 指定可?範囲 0 ? 30 )
	BYTE					EarlyDiffusion ;					// 個々の壁の反射特性値( 指定可?範囲 0 ? 15 )、( 堅く平らな?面をシ?ュレ?トするには小さな値を設定し、散乱性の?面をシ?ュレ?トするには大きな値を設定します。)
	BYTE					LateDiffusion ;						// 個々の壁のリバ?ブ特性値( 指定可?範囲 0 ? 15 )、( 堅く平らな?面をシ?ュレ?トするには小さな値を設定し、散乱性の?面をシ?ュレ?トするには大きな値を設定します。)
	BYTE					LowEQGain ;							// 1 kHz における減衰時間を基?にして低周波数の減衰時間調整値( 指定可?範囲 0 ? 12 )
																// 値とゲイン (dB) の関係
																// 値          0  1  2  3  4  5  6  7  8  9 10 11 12
																// ゲイン(dB) -8 -7 -6 -5 -4 -3 -2 -1  0 +1 +2 +3 +4
																// LowEQGain の値が 8 の場合、低周波数の減衰時間と 1 kHz における減衰時間が等しくなることに注意してください
	BYTE					LowEQCutoff ;						// LowEQGain パラメ???により制御されるロ?パス フィル??の折?周波数の設定値( 指定可?範囲 0 ? 9 )
																// 値と周波数 (Hz) の関係
																// 値          0   1   2   3   4   5   6   7   8   9
																// 周波数(Hz) 50 100 150 200 250 300 350 400 450 500
	BYTE					HighEQGain ;						// 1 kHz における減衰時間を基?にして高周波数の減衰時間調整値( 指定可?範囲 0 ? 8 )
																// 値とゲイン (dB) の関係
																// 値          0  1  2  3  4  5  6  7 8
																// ゲイン(dB) -8 -7 -6 -5 -4 -3 -2 -1 0
																// 0 に設定すると、高周波数の音が 1 kHz の場合と同じ割合で減衰します。最大値に設定すると、高周波数の音が 1 kHz の場合よりもはるかに高い割合で減衰します。
	BYTE					HighEQCutoff ;						// HighEQGain パラメ???により制御されるハイパス フィル??の折?周波数設定値( 指定可?範囲 0 ? 14 )
																// 値と周波数 (kHz) の関係
																// 値          0    1    2     3    4     5    6     7    8     9   10    11   12    13   14
																// 周波数(kHz) 1  1.5    2   2.5    3   3.5    4   4.5    5   5.5    6   6.5    7   7.5    8

	float					RoomFilterFreq ;					// 室内エフェクトのロ?パス フィル??の折?周波数、単位は Hz ( 指定可?範囲 20.0f ? 20000.0f )
	float					RoomFilterMain ;					// 初期反射と後期フィ?ルド残響の両方に適用されるロ?パス フィル??のパス バンド強度レベル、単位は dB ( 指定可?範囲 -100.0f ? 0.0f )
	float					RoomFilterHF ;						// 折?周波数 (RoomFilterFreq) での初期反射と後期フィ?ルド残響の両方に適用されるロ?パス フィル??のパス バンド強度レベル、単位は dB ( 指定可?範囲 -100.0f ? 0.0f )
	float					ReflectionsGain ;					// 初期反射の強度/レベルを調整値、単位は dB ( 指定可?範囲 -100.0f ? 20.0f )
	float					ReverbGain ;						// リバ?ブの強度/レベルを調整値、単位は dB ( 指定可?範囲 -100.0f ? 20.0f )
	float					DecayTime ;							// 1 kHz における残響減衰時間、単位は秒 ( 指定可?範囲 0.1f ? 上限値特になし )、これは、フル スケ?ルの入力信号が 60 dB 減衰するまでの時間です。
	float					Density ;							// 後期フィ?ルド残響のモ?ド密度を制御値、単位はパ?セント( 指定可?範囲 0.0f ? 100.0f )
																// 無色 (colorless) の空間では、Density を最大値 (100.0f ) に設定する必要があります。
																// Density を小さくすると、サウンドはくぐもった音 (くし?フィル??が適用された音) になります。
																// これはサイロをシ?ュレ?ションするときに有効なエフェクトです。
	float					RoomSize ;							// 音響空間の見かけ上のサイズ、単位はフィ?ト( 指定可?範囲 1.0f (30.48 cm) ? 100.0f (30.48 m) )
} SOUND3D_REVERB_PARAM ;





// ストリ??デ??制御用関数?イン??造体?イプ２
typedef struct tagSTREAMDATASHREDTYPE2
{
	DWORD_PTR				(*Open		)( const TCHAR *Path, int UseCacheFlag, int BlockReadFlag, int UseASyncReadFlag ) ;
	int						(*Close		)( DWORD_PTR Handle ) ;
	LONGLONG				(*Tell		)( DWORD_PTR Handle ) ;
	int						(*Seek		)( DWORD_PTR Handle, LONGLONG SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, DWORD_PTR Handle ) ;
	int						(*Eof		)( DWORD_PTR Handle ) ;
	int						(*IdleCheck	)( DWORD_PTR Handle ) ;
	int						(*ChDir		)( const TCHAR *Path ) ;
	int						(*GetDir	)( TCHAR *Buffer ) ;
	DWORD_PTR				(*FindFirst	)( const TCHAR *FilePath, FILEINFO *Buffer ) ;		// 戻り値: -1=エラ?  -1以外=FindHandle
	int						(*FindNext	)( DWORD_PTR FindHandle, FILEINFO *Buffer ) ;			// 戻り値: -1=エラ?  0=成功
	int						(*FindClose	)( DWORD_PTR FindHandle ) ;							// 戻り値: -1=エラ?  0=成功
} STREAMDATASHREDTYPE2 ;

// ストリ??デ??制御用関数?イン??造体
typedef struct tagSTREAMDATASHRED
{
	LONGLONG				(*Tell		)( void *StreamDataPoint ) ;
	int						(*Seek		)( void *StreamDataPoint, LONGLONG SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
//	size_t					(*Write		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
	int						(*Eof		)( void *StreamDataPoint ) ;
	int						(*IdleCheck	)( void *StreamDataPoint ) ;
	int						(*Close		)( void *StreamDataPoint ) ;
} STREAMDATASHRED, *LPSTREAMDATASHRED ;

// ストリ??デ??制御用デ???造体
typedef struct tagSTREAMDATA
{
	STREAMDATASHRED			ReadShred ;
	void					*DataPoint ;
} STREAMDATA ;




#ifndef DX_NOTUSE_DRAWFUNCTION

// パレット情報?造体
typedef struct tagCOLORPALETTEDATA
{
	unsigned char			Blue ;
	unsigned char			Green ;
	unsigned char			Red ;
	unsigned char			Alpha ;
} COLORPALETTEDATA ;

// カラ??造情報?造体
typedef struct tagCOLORDATA
{
	unsigned char			Format ;										// フォ??ット( DX_BASEIMAGE_FORMAT_NORMAL 等 )

	unsigned char			ChannelNum ;									// ?ャンネル数
	unsigned char			ChannelBitDepth ;								// １?ャンネル辺りのビット?度
	unsigned char			FloatTypeFlag ;									// 浮動小数??かどうか( TRUE:浮動小数??  FALSE:整数? )
	unsigned char			PixelByte ;										// １ピクセルあたりのバイト数

	// 以下は ChannelNum 又は ChannelBitDepth が 0 の時のみ有効
	unsigned char			ColorBitDepth ;									// ビット?度
	unsigned char			NoneLoc, NoneWidth ;							// 使われていないビットのアドレスと幅
	unsigned char			RedWidth, GreenWidth, BlueWidth, AlphaWidth ;	// 各色のビット幅
	unsigned char			RedLoc	, GreenLoc  , BlueLoc  , AlphaLoc   ;	// 各色の配置されているビットアドレス
	unsigned int			RedMask , GreenMask , BlueMask , AlphaMask  ;	// 各色のビット?スク
	unsigned int			NoneMask ;										// 使われていないビットの?スク
	COLORPALETTEDATA		Palette[ 256 ] ;								// パレット( ColorBitDepth が８以下の場合のみ有効 )
} COLORDATA, *LPCOLORDATA ;

// 基?イメ?ジデ???造体
typedef struct tagBASEIMAGE
{
	COLORDATA				ColorData ;							// 色情報
	int						Width, Height, Pitch ;				// 幅、高さ、ピッ?
	void					*GraphData ;						// グラフィックイメ?ジ
	int						MipMapCount ;						// ?ップ?ップの数
	int						GraphDataCount ;					// グラフィックイメ?ジの数
} BASEIMAGE, GRAPHIMAGE, *LPGRAPHIMAGE ;

// ラインデ???
typedef struct tagLINEDATA
{
	int						x1, y1, x2, y2 ;					// 座標
	int						color ;								// 色
	int						pal ;								// パラメ??
} LINEDATA, *LPLINEDATA ;

// 座標デ???
typedef struct tagPOINTDATA
{
	int						x, y ;								// 座標
	int						color ;								// 色
	int						pal ;								// パラメ??
} POINTDATA, *LPPOINTDATA ;

// イメ?ジフォ??ットデ??
typedef struct tagIMAGEFORMATDESC
{
	unsigned char			TextureFlag ;					// テクス?ャか、フラグ( TRUE:テクス?ャ  FALSE:標?サ?フェス )
	unsigned char			CubeMapTextureFlag ;			// キュ?ブ?ップテクス?ャか、フラグ( TRUE:キュ?ブ?ップテクス?ャ?FALSE:それ以外 )
	unsigned char			AlphaChFlag ;					// α?ャンネルはあるか、フラグ	( TRUE:ある  FALSE:ない )
	unsigned char			DrawValidFlag ;					// ?画可?か、フラグ( TRUE:可?  FALSE:不可? )
	unsigned char			SystemMemFlag ;					// システ?メモリ上に存在しているか、フラグ( TRUE:システ?メモリ上  FALSE:ＶＲ?Ｍ上 )( 標?サ?フェスの時のみ有効 )
	unsigned char			UseManagedTextureFlag ;			// ?ネ?ジドテクス?ャを使用するか、フラグ

	unsigned char			BaseFormat ;					// 基?フォ??ット( DX_BASEIMAGE_FORMAT_NORMAL 等 )
	unsigned char			MipMapCount ;					// ?ップ?ップの数
	unsigned char			AlphaTestFlag ;					// αテスト?ャンネルはあるか、フラグ( TRUE:ある  FALSE:ない )( テクス?ャの場合のみ有効 )
	unsigned char			FloatTypeFlag ;					// 浮動小数??かどうか
	unsigned char			ColorBitDepth ;					// 色?度( テクス?ャの場合のみ有効 )
	unsigned char			ChannelNum ;					// ?ャンネルの数
	unsigned char			ChannelBitDepth ;				// １?ャンネル辺りのビット?度( テクス?ャの場合のみ有効、0 の場合は ColorBitDepth が使用される )
	unsigned char			BlendGraphFlag ;				// ブレンド用画像か、フラグ
	unsigned char			UsePaletteFlag ;				// パレットを使用しているか、フラグ( SystemMemFlag が TRUE の場合のみ有効 )

	unsigned char			MSSamples ;						// ?ル?サンプリング数( ?画対象の場合使用 )
	unsigned char			MSQuality ;						// ?ル?サンプリングクオリティ( ?画対象の場合使用 )
} IMAGEFORMATDESC ;

#endif // DX_NOTUSE_DRAWFUNCTION

// DirectInput のジョイパッド入力情報
typedef struct tagDINPUT_JOYSTATE
{
	int						X ;								// スティックのＸ軸パラメ??( -1000?1000 )
	int						Y ;								// スティックのＹ軸パラメ??( -1000?1000 )
	int						Z ;								// スティックのＺ軸パラメ??( -1000?1000 )
	int						Rx ;							// スティックのＸ軸回?パラメ??( -1000?1000 )
	int						Ry ;							// スティックのＹ軸回?パラメ??( -1000?1000 )
	int						Rz ;							// スティックのＺ軸回?パラメ??( -1000?1000 )
	int						Slider[ 2 ] ;					// スライ??二つ
	unsigned int			POV[ 4 ] ;						// ハットスイッ?４つ( 0xffffffff:入力なし 0:上 4500:右上 9000:右 13500:右下 18000:下 22500:左下 27000:左 31500:左上 )
	unsigned char			Buttons[ 32 ] ;					// ??ン３２個( 押された??ンは 128 になる )
} DINPUT_JOYSTATE ;

// XInput のジョイパッド入力情報
typedef struct tagXINPUT_STATE
{
	unsigned char			Buttons[ 16 ] ;					// ??ン１６個( 添字には XINPUT_BUTTON_DPAD_UP 等を使用する、0:押されていない  1:押されている )
	unsigned char			LeftTrigger ;					// 左トリガ?( 0?255 )
	unsigned char			RightTrigger ;					// 右トリガ?( 0?255 )
	short					ThumbLX ;						// 左スティックの横軸値( -32768 ? 32767 )
	short					ThumbLY ;						// 左スティックの縦軸値( -32768 ? 32767 )
	short					ThumbRX ;						// 右スティックの横軸値( -32768 ? 32767 )
	short					ThumbRY ;						// 右スティックの縦軸値( -32768 ? 32767 )
} XINPUT_STATE ;






// WinSockets使用時のアドレス指定用?造体
typedef struct tagIPDATA
{
	unsigned char			d1, d2, d3, d4 ;				// アドレス値
} IPDATA, *LPIPDATA ;

typedef struct tagIPDATA_IPv6
{
	union
	{
		unsigned char			Byte[ 16 ] ;
		unsigned short			Word[ 8 ] ;
	} ;
} IPDATA_IPv6 ;

#define DX_STRUCT_END

}

// 関数プロト?イプ宣言------------------------------------------------------------------

namespace DxLib
{

#define DX_FUNCTION_START

// DxSystem.cpp関数プロト?イプ宣言

// 初期化終了系関数
extern	int			DxLib_Init( void ) ;													// ライブラリ初期化を行う
extern	int			DxLib_End( void ) ;														// ライブラリ使用の後始末を行う

extern	int			DxLib_GlobalStructInitialize( void ) ;									// ライブラリの内部で使用している?造体を?ロ初期化して、DxLib_Init の前に行った設定を無効化する( DxLib_Init の前でのみ有効 )
extern	int			DxLib_IsInit( void ) ;													// ライブラリが初期化されているかどうかを取得する( 戻り値: TRUE=初期化されている  FALSE=されていない )

// メッセ?ジ処理関数
extern	int			ProcessMessage( void ) ;												// ウインドウズのメッセ?ジル?プに代わる処理を行う

// ウエイト系関数
extern	int			WaitTimer( int WaitTime ) ;												// 指定の時間だけ処理をとめる
#ifndef DX_NON_INPUT
extern	int			WaitKey( void ) ;														// キ?の入力待ちを行う
#endif // DX_NON_INPUT

// カウン?及び時刻取得系関数
extern	int			GetNowCount(				int UseRDTSCFlag = FALSE ) ;				// ?リ秒単位の精度を持つカウン?の現在値を得る
extern	LONGLONG	GetNowHiPerformanceCount(	int UseRDTSCFlag = FALSE ) ;				// GetNowCountの高精度バ?ジョン
extern	int			GetDateTime(				DATEDATA *DateBuf ) ;						// 現在時刻を取得する 

// 乱数取得
extern	int			GetRand( int RandMax ) ;												// 乱数を取得する( RandMax : 返って来る値の最大値 )
extern	int			SRand(	 int Seed ) ;													// 乱数の初期値を設定する








// DxLog.cpp関数プロト?イプ宣言

#ifndef DX_NON_LOG
// エラ?処理関数
extern	int			ErrorLogAdd(		 const TCHAR *ErrorStr ) ;							// ログフ?イル( Log.txt ) に文字列を出力する
extern 	int			ErrorLogFmtAdd(		 const TCHAR *FormatString , ... ) ;				// 書式付きで ログフ?イル( Log.txt ) に文字列を出力する( 書式は printf と同じ )
extern	int			ErrorLogTabAdd(		 void ) ;											// ログフ?イル( Log.txt ) に出力する文字列の前に付ける?ブの数を一つ増やす
extern	int			ErrorLogTabSub(		 void ) ;											// ログフ?イル( Log.txt ) に出力する文字列の前に付ける?ブの数を一つ減らす
extern	int			SetUseTimeStampFlag( int UseFlag ) ;									// ログフ?イル( Log.txt ) に出力する文字列の前に起動してからの時間を付けるかどうかを設定する( TRUE:付ける( デフォルト)  FALSE:付けない )
extern 	int			AppLogAdd(			 const TCHAR *String , ... ) ;						// ErrorLogFmtAdd と同じ??の関数

#ifndef DX_NON_PRINTF_DX

// ログ出力??関数
extern	int			SetLogDrawOutFlag(	 int DrawFlag ) ;									// printfDx の結果を画面に出力するかどうかを設定する、TRUE:出力を行う  FALSE:出力を行わない( printfDx を実行すると内部で SetLogDrawOutFlag( TRUE ) ; が呼ばれます )
extern 	int			GetLogDrawFlag(		 void ) ;											// printfDx の結果を画面に出力するかどうかの設定を取得する( 戻り値  TRUE:出力を行う  FALSE:出力を行わない )
extern	int			SetLogFontSize(		 int Size ) ;										// printfDx の結果を画面に出力する際に使用するフォントのサイズを設定する

// 簡易画面出力関数
extern 	int			printfDx(			 const TCHAR *FormatString , ... ) ;				// printf と同じ引数で画面に文字列を?示するための関数
extern	int			clsDx(				 void ) ;											// printfDx の結果をリセットするための関数
#endif // DX_NON_PRINTF_DX

#endif // DX_NON_LOG












#ifndef DX_NON_ASYNCLOAD

// DxASyncLoad.cpp関数プロト?イプ宣言

// 非同期読み込み関係
extern	int			SetUseASyncLoadFlag(		int Flag ) ;								// 読み込み処理系の関数で非同期読み込みを行うかどうかを設定する( 非同期読み込みに対応している関数のみ有効 )( TRUE:非同期読み込みを行う  FALSE:非同期読み込みを行わない( デフォルト ) )
extern	int			CheckHandleASyncLoad(		int Handle ) ;								// ハンドルの非同期読み込みが完了しているかどうかを取得する( TRUE:まだ完了していない  FALSE:完了している  -1:エラ? )
extern	int			GetHandleASyncLoadResult(	int Handle ) ;								// ハンドルの非同期読み込み処理の戻り値を取得する( 非同期読み込み中の場合は一つ前の非同期読み込み処理の戻り値が返ってきます )
extern	int			GetASyncLoadNum(			void ) ;									// 非同期読み込み中の処理の数を取得する

#endif // DX_NON_ASYNCLOAD











// DxHandle.cpp関数プロト?イプ宣言

extern	int			SetDeleteHandleFlag(		int Handle, int *DeleteFlag ) ;				// ハンドルが削除されたときに?１が設定される変数を登?する














// DxWindow.cpp関数プロト?イプ宣言

#ifdef __WINDOWS__

// 便利関数
extern	int			GetResourceInfo(		const TCHAR *ResourceName , const TCHAR *ResourceType , void **DataPointerP , int *DataSizeP ) ;		// 指定の名前、?イプのリ??スのアドレスとサイズを取得する( 戻り値  -1:失敗  0:成功 )
extern	const TCHAR* GetResourceIDString(	int ResourceID ) ;																						// リ??スＩＤ値からリ??ス名を取得する

// ウインドウ関係情報取得関数
extern	int			GetWindowCRect(					RECT *RectBuf ) ;										// メインウインドウのクライアント領域を取得する
extern	int			GetWindowActiveFlag(			void ) ;												// メインウインドウがアクティブかどうかを取得する( 戻り値  TRUE:アクティブ  FALSE:非アクティブ )
extern	int			GetWindowMinSizeFlag(			void ) ;												// メインウインドウが最小化されているかどうかを取得する( 戻り値  TRUE:最小化されている  FALSE:最小化されていない )
extern	int			GetActiveFlag(					void ) ;												// GetWindowActiveFlag の別名関数
extern	HWND		GetMainWindowHandle(			void ) ;												// メインウインドウのウインドウハンドルを取得する
extern	int			GetWindowModeFlag(				void ) ;												// ウインドウモ?ドで起動しているかどうかを取得する( 戻り値  TRUE:ウインドウモ?ド  FALSE:フルスクリ?ンモ?ド )
extern	int			GetDefaultState(				int *SizeX , int *SizeY , int *ColorBitDepth ) ;		// 起動時のデスクトップの画面情報を取得する( SizeX:デスクトップの横解像度を格?する変数の?イン?  SizeY:縦解像度を格?する変数の?イン?  ColorBitDepth:画面カラ?ビット数を格?する変数の?イン? )
extern	int			GetNoActiveState(				int ResetFlag = TRUE ) ;								// メインウインドウが非アクティブになり、処理が一時停?していたかどうかを取得する(引数 ResetFlag=TRUE:状態をリセット FALSE:状態をリセットしない    戻り値: 0=一時停?はしていない  1=一時停?していた )
extern	int			GetMouseDispFlag(				void ) ;												// ?ウス?イン?を?示するかどうかの設定を取得する( 戻り値  TRUE:?示する  FALSE:?示しない )
extern	int			GetAlwaysRunFlag(				void ) ;												// メインウインドウが非アクティブになっても処理を実行し続けるかどうかの設定を取得する( TRUE:実行する  FALSE:停?する )
extern	int			_GetSystemInfo(					int *DxLibVer , int *DirectXVer , int *WindowsVer ) ;	// ＤＸライブラリと DirectX のバ?ジョンと Windows のバ?ジョン番号を取得する
extern	int			GetPcInfo(						TCHAR *OSString , TCHAR *DirectXString , TCHAR *CPUString , int *CPUSpeed /* 単位MHz */ , double *FreeMemorySize /* 単位MByte */ , double *TotalMemorySize , TCHAR *VideoDriverFileName , TCHAR *VideoDriverString , double *FreeVideoMemorySize /* 単位MByte */ , double *TotalVideoMemorySize ) ;	// ＰＣの情報を取得する
extern	int			GetUseMMXFlag(					void ) ;												// ＭＭＸが使えるかどうかの情報を得る
extern	int			GetUseSSEFlag(					void ) ;												// ＳＳＥが使えるかどうかの情報を得る
extern	int			GetUseSSE2Flag(					void ) ;												// ＳＳＥ２が使えるかどうかの情報を得る
extern	int			GetWindowCloseFlag(				void ) ;												// ウインドウを閉じようとしているかの情報を得る
extern	HINSTANCE	GetTaskInstance(				void ) ;												// ?フトのインス?ンスを取得する
extern	int			GetUseWindowRgnFlag(			void ) ;												// リ?ジョンを使っているかどうかを取得する
extern	int			GetWindowSizeChangeEnableFlag(	int *FitScreen = NULL ) ;								// ウインドウのサイズを変更できる設定になっているかどうかを取得する( 戻り値  TRUE:変更できるようになっている  FALSE:変更できないようになっている )
extern	double		GetWindowSizeExtendRate(		double *ExRateX = NULL , double *ExRateY = NULL ) ;		// ?画画面のサイズに対するウインドウサイズの比率を取得する( 戻り値は ExRateX に代入される値と同じです )
extern	int			GetWindowSize(					int *Width, int *Height ) ;								// メインウインドウのクライアント領域のサイズを取得する
extern	int			GetWindowPosition(				int *x, int *y ) ;										// メインウインドウのデスクトップ上の左上?座標を取得する( 枠も含める )
extern	int			GetWindowUserCloseFlag(			int StateResetFlag = FALSE ) ;							// メインウインドウの閉じる??ンが押されたかどうかを取得する
extern	int			GetNotDrawFlag(					void ) ;												// ＤＸライブラリの?画??を使うかどうかの設定を取得する
extern	int			GetPaintMessageFlag(			void ) ;												// WM_PAINT メッセ?ジが来たかどうかを取得する(戻り値  TRUE:WM_PAINTメッセ?ジが来た(一度取得すると以後、再び WM_PAINTメッセ?ジが来るまで FALSE が返ってくるようになる)  FALSE:WM_PAINT メッセ?ジは来ていない)
extern	int			GetValidHiPerformanceCounter(	void ) ;												// パフォ??ンスカウン?が有効かどうかを取得する(戻り値  TRUE:有効  FALSE:無効)

// 設定系関数
extern	int			ChangeWindowMode(						int Flag ) ;																		// ウインドウモ?ドを変更する
extern	int			SetUseCharSet(							int CharSet /* = DX_CHARSET_SHFTJIS 等 */ ) ;										// ＤＸライブラリの文字列処理で前提とする文字列セットを設定する
extern	int			LoadPauseGraph(							const TCHAR *FileName ) ;															// アクティブウインドウが他の?フトに移っている際に?示する画像をフ?イルから読み込む( FileName に NULL を渡すことで解除)
extern	int			LoadPauseGraphFromMem(					const void *MemImage , int MemImageSize ) ;											// アクティブウインドウが他の?フトに移っている際に?示する画像をメモリから読み込む( MemImage:フ?イルイメ?ジの先頭アドレス,NULL にすることで設定解除  MemImageSize:フ?イルイメ?ジのサイズ( 単位:Byte ) )
extern	int			SetActiveStateChangeCallBackFunction(	int (* CallBackFunction )( int ActiveState , void *UserData ) , void *UserData ) ;	// メインウインドウのアクティブ状態に変化があったときに呼ばれるコ?ルバック関数を設定する( CallBackFunction:呼ばれるコ?ルバック関数、NULL を渡すと設定解除  UserData:CallBackFunction の第２引数に渡される値 )
extern	int			SetWindowText(							const TCHAR *WindowText ) ;															// メインウインドウのウインドウテキストを変更する
extern	int			SetMainWindowText(						const TCHAR *WindowText ) ;															// SetWindowText の別名関数
extern	int			SetMainWindowClassName(					const TCHAR *ClassName ) ;															// メインウインドウのクラス名を設定する( DxLib_Init の前でのみ使用可? )
#ifndef DX_NON_LOG
extern	int			SetOutApplicationLogValidFlag(			int Flag ) ;																		// ログフ?イル( Log.txt ) を作成するかどうかを設定する( TRUE:作成する( デフォルト )  FALSE:作成しない )、DxLib_Init の前でのみ使用可??
extern	int			SetApplicationLogSaveDirectory(			const TCHAR *DirectoryPath ) ;														// ログフ?イル( Log.txt ) を保存するディレクトリパスを設定する
extern	int			SetUseDateNameLogFile(					int Flag ) ;																		// ログフ?イル名に日付をつけるかどうかをセットする( TRUE:付ける  FALSE:付けない( デフォルト ) )
#endif // DX_NON_LOG
extern	int			SetAlwaysRunFlag(						int Flag ) ;																		// メインウインドウが非アクティブ状態でも処理を実行するかどうかを設定する( TRUE:実行する  FALSE:停?する( デフォルト ) )
extern	int			SetWindowIconID(						int ID ) ;																			// メインウインドウで使用するアイコンのＩＤをセットする
extern	int			SetWindowIconHandle(					HICON Icon ) ;																		// メインウインドウで使用するアイコンのハンドルをセットする
extern	int			SetUseASyncChangeWindowModeFunction(	int Flag , void (* CallBackFunction )( void * ) , void *Data ) ;					// 最大化??ンやALT+ENTERキ?による非同期なウインドウモ?ドの変更の??の設定を行う( Flag:非同期ウインドウモ?ド変更を有効にするかどうかのフラグ( TRUE:有効にする  FALSE:無効にする( デフォルト ) )   CallBackFunction:非同期ウインドウモ?ド変更が行われた場合に呼ばれるコ?ルバック関数のアドレス   Data:CallBackFunction の引数に渡される void ?の?イン? )
extern	int			SetWindowStyleMode(						int Mode ) ;																		// メインウインドウのス?イルを変更する
extern	int			SetWindowSizeChangeEnableFlag(			int Flag, int FitScreen = TRUE ) ;													// メインウインドウの?を掴んでウインドウのサイズを変更できるようにするかどうかの設定を行う( Flag:変更を可?にするかどうか( TRUE:可?にする  FALSE:不可?にする( デフォルト ) )  FitScreen:ウインドウのクライアント領域に画面をフィットさせる(拡大させる)かどうか  TRUE:フィットさせる  FALSE:フィットさせない )
extern	int			SetWindowSizeExtendRate(				double ExRateX, double ExRateY = -1.0 ) ;											// ?画画面のサイズに対するメインウインドウサイズの比率を設定する( ExRateY が?イナスの場合は ExRateX の値が ExRateY にも使用されます )
extern	int			SetWindowSize(							int Width, int Height ) ;															// メインウインドウのクライアント領域のサイズを設定する
extern	int			SetWindowPosition(						int x, int y ) ;																	// メインウインドウの位置を設定する( 枠も含めた左上座標 )
extern	int			SetSysCommandOffFlag(					int Flag , const TCHAR *HookDllPath = NULL ) ;										// ?スクスイッ?を有効にするかどうかを設定する
extern	int			SetHookWinProc(							WNDPROC WinProc ) ;																	// メインウインドウへのメッセ?ジをフックするウインドウプロ?ジャを登?する
extern	int			SetUseHookWinProcReturnValue(			int UseFlag ) ;																		// SetHookWinProc で設定したウインドウプロ?ジャの戻り値を使用するかどうかを設定する、SetHookWinProc で設定したウインドウプロ?ジャの中でのみ使用可?( UseFlag TRUE:戻り値を使用して、ＤＸライブラリのウインドウプロ?ジャの処理は行わない  FALSE:戻り値は使用せず、ウインドウプロ?ジャから出た後、ＤＸライブラリのウインドウプロ?ジャの処理を行う )
extern	int			SetDoubleStartValidFlag(				int Flag ) ;																		// ＤＸライブラリを使用した?フトの二重起動を可?にするかどうかの設定を行う( TRUE:可?にする  FALSE:不可?にする( デフォルト ) )
extern	int			AddMessageTakeOverWindow(				HWND Window ) ;																		// メッセ?ジ処理をＤＸライブラリに肩代わりしてもらうウインドウを追加する
extern	int			SubMessageTakeOverWindow(				HWND Window ) ;																		// メッセ?ジ処理をＤＸライブラリに肩代わりしてもらうウインドウを減らす

extern	int			SetWindowInitPosition(					int x , int y ) ;																	// メインウインドウの初期位置を設定する
extern	int			SetNotWinFlag(							int Flag ) ;																		// ＤＸライブラリのウインドウ関連の??を使用しないかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotDrawFlag(							int Flag ) ;																		// ＤＸライブラリの?画??を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotSoundFlag(						int Flag ) ;																		// ＤＸライブラリのサウンド??を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotInputFlag(						int Flag ) ;																		// ＤＸライブラリの入力状態の取得??を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetDialogBoxHandle(						HWND WindowHandle ) ;																// ＤＸライブラリでメッセ?ジ処理を行う?イアログ?ックスを登?する
extern	int			SetWindowVisibleFlag(					int Flag ) ;																		// メインウインドウを?示するかどうかを設定する( TRUE:?示する  FALSE:?示しない )
extern	int			SetWindowMinimizeFlag(					int Flag ) ;																		// メインウインドウを最小化するかどうかを設定する( TRUE:最小化する  FALSE:最小化を解除 )
extern	int			SetWindowUserCloseEnableFlag(			int Flag ) ;																		// メインウインドウの???ンを押した時にＤＸライブラリが自動的にウインドウを閉じるかどうかを設定する( TRUE:自動的に閉じる( デフォルト )  FALSE:閉じない )
extern	int			SetDxLibEndPostQuitMessageFlag(			int Flag ) ;																		// ＤＸライブラリ終了時に PostQuitMessage を呼ぶかどうかを設定する( TRUE:PostQuitMessage を呼ぶ( デフォルト )  FALSE:呼ばない )
extern	int			SetUserWindow(							HWND WindowHandle ) ;																// ＤＸライブラリで使用するウインドウのハンドルをセットする( DxLib_Init を実行する以前でのみ有効 )
extern	int			SetUserChildWindow(						HWND WindowHandle ) ;																// ＤＸライブラリで使用する?示用の子ウインドウのハンドルをセットする( DxLib_Init を実行する以前でのみ有効 )
extern	int			SetUserWindowMessageProcessDXLibFlag(	int Flag ) ;																		// SetUseWindow で設定したウインドウのメッセ?ジル?プ処理をＤＸライブラリで行うかどうかを設定する( TRUE:ＤＸライブラリで行う( デフォルト )  FALSE:ＤＸライブラリでは行わない )
extern	int			SetBackgroundColor(						int Red, int Green, int Blue ) ;													// メインウインドウの背景色を設定する( Red,Green,Blue:それぞれ ０?２５５ )
extern	int			SetUseFPUPreserveFlag(					int Flag ) ;																		// FPUの精度を落とさない設定を使用するかどうかを設定する、DxLib_Init を呼び出す前のみ有効( TRUE:使用する(精度が落ちない)  FALSE:使用しない(精度を落とす(デフォルト) )
extern	int			SetValidMousePointerWindowOutClientAreaMoveFlag( int Flag ) ;																// ?ウス?イン?がウインドウのクライアントエリアの外にいけるかどうかを設定する( TRUE:いける( デフォルト設定 )  FALSE:いけない )
extern	int			SetUseBackBufferTransColorFlag(			int Flag ) ;																		// バックバッフ?の透過色の部分を透過させるかどうかを設定する( TRUE:透過させる  FALSE:透過させない( デフォルト ) )
extern	int			SetUseUpdateLayerdWindowFlag(			int Flag ) ;																		// UpdateLayerdWindowForBaseImage や UpdateLayerdWindowForSoftImage を使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない )
extern	int			SetResourceModule(						HMODULE ResourceModule ) ;															// リ??スを読み込む際に使用するモジュ?ルを設定する( NULL を指定すると初期状態に戻ります、デフォルトでは NULL )

// クリップ??ド関係
extern	int			GetClipboardText(			TCHAR *DestBuffer ) ;															// クリップ??ドに格?されているテキストデ??を読み出す( DestBuffer:文字列を格?するバッフ?の先頭アドレス   戻り値  -1:クリップ??ドにテキストデ??が無い  -1以外:クリップ??ドに格?されている文字列デ??のサイズ( 単位:byte ) ) 
extern	int			SetClipboardText(			const TCHAR *Text ) ;															// クリップ??ドにテキストデ??を格?する

// ドラッグ＆ドロップされたフ?イル関係
extern	int			SetDragFileValidFlag(		int Flag ) ;																	// フ?イルのメインウインドウへのドラッグ＆ドロップ??を有効にするかどうかのフラグをセットする
extern	int			DragFileInfoClear(			void ) ;																		// メインウインドウへドラッグ＆ドロップされたフ?イルの情報をリセットする
extern	int			GetDragFilePath(			TCHAR *FilePathBuffer ) ;														// メインウインドウへドラッグ＆ドロップされたフ?イル名を取得する( FilePathBuffer:フ?イル名を格?するバッフ?の先頭アドレス??戻り値?-1:取得できなかった  0:取得できた )
extern	int			GetDragFileNum(				void ) ;																		// メインウインドウへドラッグ＆ドロップされたフ?イルの数を取得する

// ウインドウ?画領域設定系関数
extern	HRGN		CreateRgnFromGraph(			int Width , int Height , const void *MaskData , int Pitch , int Byte ) ;		// 任意の画像イメ?ジからRGNハンドルを作成する( Width:横ドット数  Height:縦ドット数  MaskData:ドット情報配列の先頭アドレス  Pitch:１ラインあたりのbyteサイズ  Byte:１ドット辺りのbyteサイズ( 対応しているのは 1?4 )、ドットの数値が0かそれ以外かで判別 )
extern	HRGN		CreateRgnFromBaseImage(		BASEIMAGE *BaseImage, int TransColorR, int TransColorG, int TransColorB ) ;		// 任意の基?イメ?ジデ??と透過色からRGNハンドルを作成する( BaseImage:基?イメ?ジデ??のアドレス  TransColorR,TransColorG,TransColorB:透過色( それぞれ０?２５５ )
extern	int			SetWindowRgnGraph(			const TCHAR *FileName ) ;														// 任意の画像フ?イルからＲＧＮをセットする
extern	int			UpdateTransColorWindowRgn(	void ) ;																		// ?画先の画面の透過色の部分を透過させるＲＧＮをセットする( 使用される透過色は関数 SetTransColor で設定した色 )

// ツ?ルバ?関係
extern	int			SetupToolBar(				const TCHAR *BitmapName , int DivNum , int ResourceID = -1 ) ;															// ツ?ルバ?の?備、BitmapName に NULL, ResourceID に -1 を渡すとツ?ルバ?を解除( BitmapName:ツ?ルバ?の??ンに使用する画像フ?イルパス、ResourceID に -1 以外を渡す場合は NULL にする  DivNum:??ン画像中の??ンの数  ResourceID:ツ?ルバ?の??ンに使用するビット?ップリ??スのＩＤ、BitmapName に NULL を渡すとこの引数が使用される )
extern	int			AddToolBarButton(			int Type /* TOOLBUTTON_TYPE_NORMAL 等 */ , int State /* TOOLBUTTON_STATE_ENABLE 等 */ , int ImageIndex, int ID ) ;		// ツ?ルバ?に??ンを追加する( Type:??ン?イプ( TOOLBUTTON_TYPE_NORMAL 等( 解説は #define の定?を参照してください ) )  State:初期状態( TOOLBUTTON_STATE_ENABLE 等( 解説は #define の定?を参照してください ) )  ImageIndex:使用する??ンの画像番号  ID:??ンに割り当てる識別番号  )
extern	int			AddToolBarSep(				void ) ;																												// ツ?ルバ?に隙間を追加する
extern	int			GetToolBarButtonState(		int ID ) ;																												// ツ?ルバ?の??ンの状態を取得する( ID:AddToolBarButtonで設定した??ンの識別番号??戻り値?TRUE:押されている or 押された  FALSE:押されていない )
extern	int			SetToolBarButtonState(		int ID , int State /* TOOLBUTTON_STATE_ENABLE 等 */ ) ;																	// ツ?ルバ?の??ンの状態を設定する( ID:AddToolBarButtonで設定した??ンの識別番号?State:設定する状態( TOOLBUTTON_STATE_ENABLE 等( 解説は #define の定?を参照してください ) )
extern	int			DeleteAllToolBarButton(		void ) ;																												// ツ?ルバ?の??ンを全て削除する

// メニュ?関係
extern	int			SetUseMenuFlag(				int Flag ) ;																						// メニュ?を有効にするかどうかを設定する( TRUE:使用する  FALSE:使用しない )
extern	int			SetUseKeyAccelFlag(			int Flag ) ;																						// キ???ドアクセラレ???を使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない )

extern	int			AddKeyAccel(				const TCHAR *ItemName , int ItemID , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// ショ?トカットキ?を追加する( ItemName:ショ?トカットキ?を割り当てるメニュ?のアイテ?名( AddMenuItem で NewItemName に渡した名前 )、ItemID を使用する場合は NULL を渡す  ItemID:メニュ??目の識別番号( AddMenuItem の引数 NewItemID で指定したもの )、ItemName を使用する場合は -1 を渡す  KeyCode:ショ?トカットキ?のキ?( KEY_INPUT_L 等 )  CtrlFlag:同時にCTRLキ?を押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )  AltFlag:同時にALTキ?を押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )  ShiftFlag:同時にSHIFTキ?を押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )
extern	int			AddKeyAccel_Name(			const TCHAR *ItemName , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;				// ショ?トカットキ?を追加する( 各引数の解説は AddKeyAccel と同じ、ItemID が無くなっただけ )
extern	int			AddKeyAccel_ID(				int ItemID, int KeyCode, int CtrlFlag, int AltFlag, int ShiftFlag ) ;								// ショ?トカットキ?を追加する( 各引数の解説は AddKeyAccel と同じ、ItemName が無くなっただけ )
extern	int			ClearKeyAccel(				void ) ;																							// ショ?トカットキ?の情報をリセットする

extern	int			AddMenuItem(				int AddType /* MENUITEM_ADD_CHILD等 */ , const TCHAR *ItemName, int ItemID, int SeparatorFlag, const TCHAR *NewItemName = NULL , int NewItemID = -1 ) ;	// メニュ?に?目を追加する( AddType:?目?イプ( MENUITEM_ADD_CHILD 等( 解説は #define の定?を参照してください ) )    ItemName:AddType が MENUITEM_ADD_CHILDの場合は親となる?目の名前、MENUITEM_ADD_INSERTの場合は?入位置となる?目の名前、NULL を指定すると ItemID が使用される   ItemID:ItemName の代わりに識別番号で指定するもの、AddType毎の違いは ItemName の解説の通り、-1を指定すると ItemName が使用される??SeparatorFlag:区切り線を追加するかどうか( TRUE:区切り線を追加、この場合 NewItemName と NewItemID は無視される  FALSE:追加するのは区切り線ではない )??NewItemName:新しい?目の名前  NewItemID:新しい?目の識別番号、-1を指定すると内部で適当な番号が割り当てられる )
extern	int			DeleteMenuItem(				const TCHAR *ItemName, int ItemID ) ;																// メニュ?から選択?目を削除する( ItemName:削除する?目の名前( AddMenuItem で NewItemName に渡した名前 )、NULL を指定すると ItemID が使用される  ItemID:削除する?目の識別番号( AddMenuItem で NewItemID に渡した番号 )、-1 を指定すると ItemName が使用される )
extern	int			CheckMenuItemSelect(		const TCHAR *ItemName, int ItemID ) ;																// メニュ?が選択されたかどうかを取得する( 戻り値? 0:選択されていない  1:選択された   ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください )
extern	int			SetMenuItemEnable(			const TCHAR *ItemName, int ItemID, int EnableFlag ) ;												// メニュ?の?目を選択出来るかどうかを設定する( EnableFlag:?目が選択できるかどうか( TRUE:選択できる   FALSE:選択できない )   ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください )
extern	int			SetMenuItemMark(			const TCHAR *ItemName, int ItemID, int Mark ) ;														// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( Mark:設定する??ク( MENUITEM_MARK_NONE 等( 解説は #define の定?を参照してください )    ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください ) )
extern	int			CheckMenuItemSelectAll(		void ) ;																							// メニュ?の?目がどれか選択されたかどうかを取得する( 戻り値  TRUE:どれか選択された  FALSE:選択されていない )

extern	int			AddMenuItem_Name(			const TCHAR *ParentItemName, const TCHAR *NewItemName ) ;											// メニュ?に選択?目を追加する( ParentItemName:親となる?目の名前、親が持つリストの末?に新しい?目を追加します  NewItemName:新しい?目の名前 )
extern	int			AddMenuLine_Name(			const TCHAR *ParentItemName ) ;																		// メニュ?のリストに区切り線を追加する( ParentItemName:区切り線を付ける?目リストの親の名前、リストの末?に区切り線を追加します )
extern	int			InsertMenuItem_Name(		const TCHAR *ItemName, const TCHAR *NewItemName ) ;													// 指定の?目と、指定の?目の一つ上の?目との間に新しい?目を追加する
extern	int			InsertMenuLine_Name(		const TCHAR *ItemName ) ;																			// 指定の?目と、指定の?目の一つ上の?目との間に区切り線を追加する
extern	int			DeleteMenuItem_Name(		const TCHAR *ItemName ) ;																			// メニュ?から選択?目を削除する
extern	int			CheckMenuItemSelect_Name(	const TCHAR *ItemName ) ;																			// メニュ?が選択されたかどうかを取得する( 戻り値?0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_Name(		const TCHAR *ItemName, int EnableFlag ) ;															// メニュ?の?目を選択出来るかどうかを設定する( EnableFlag?1:選択できる  0:選択できない )
extern	int			SetMenuItemMark_Name(		const TCHAR *ItemName, int Mark ) ;																	// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( Mark:設定する??ク( MENUITEM_MARK_NONE 等 ) )

extern	int			AddMenuItem_ID(				int ParentItemID, const TCHAR *NewItemName, int NewItemID = -1 ) ;									// メニュ?に選択?目を追加する
extern	int			AddMenuLine_ID(				int ParentItemID ) ;																				// メニュ?のリストに区切り線を追加する
extern	int			InsertMenuItem_ID(			int ItemID, int NewItemID ) ;																		// 指定の?目と、指定の?目の一つ上の?目との間に新しい?目を追加する
extern	int			InsertMenuLine_ID(			int ItemID, int NewItemID ) ;																		// 指定の?目と、指定の?目の一つ上の?目との間に区切り線を追加する
extern	int			DeleteMenuItem_ID(			int ItemID ) ;																						// メニュ?から選択?目を削除する
extern	int			CheckMenuItemSelect_ID(		int ItemID ) ;																						// メニュ?が選択されたかどうかを取得する( 戻り値??0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_ID(		int ItemID, int EnableFlag ) ;																		// メニュ?の?目を選択出来るかどうかを設定する( EnableFlag?1:選択できる  0:選択できない )
extern	int			SetMenuItemMark_ID(			int ItemID, int Mark ) ;																			// メニュ?の?目に?ェック??クやラジオ??ンを?示するかどうかを設定する( Mark:設定する??ク( MENUITEM_MARK_NONE 等 ) )

extern	int			DeleteMenuItemAll(			void ) ;																							// メニュ?の全ての選択?目を削除する
extern	int			ClearMenuItemSelect(		void ) ;																							// メニュ?が選択されたかどうかの情報をリセット
extern	int			GetMenuItemID(				const TCHAR *ItemName ) ;																			// メニュ?の?目名から?目識別番号を取得する
extern	int			GetMenuItemName(			int ItemID, TCHAR *NameBuffer ) ;																	// メニュ?の?目識別番号から?目名を取得する
extern	int 		LoadMenuResource(			int MenuResourceID ) ;																				// メニュ?をリ??スから読み込む
extern	int			SetMenuItemSelectCallBackFunction(		void (* CallBackFunction )( const TCHAR *ItemName, int ItemID ) ) ;						// メニュ?の選択?目が選択されたときに呼ばれるコ?ルバック関数を設定する( CallBackFunction:?目が選択されたときに呼ばれるコ?ルバック関数、引数に?目名と?目の識別番号を渡されて呼ばれる )

extern	int			SetWindowMenu(				int MenuID, int (* MenuProc )( WORD ID ) ) ;														// (古い関数)ウインドウにメニュ?を設定する
extern	int			SetDisplayMenuFlag(			int Flag ) ;																						// メニュ?を?示するかどうかをセットする
extern	int			GetDisplayMenuFlag(			void ) ;																							// メニュ?を?示しているかどうかを取得する
extern	int			GetUseMenuFlag(				void ) ;																							// メニュ?を使用しているかどうかを得る
extern	int			SetAutoMenuDisplayFlag(		int Flag ) ;																						// フルスクリ?ン時にメニュ?を自動で?示したり非?示にしたりするかどうかのフラグをセットする

#endif // __WINDOWS__

// ?ウス関係関数
extern	int			SetMouseDispFlag(		int DispFlag ) ;												// ?ウス?イン?の?示状態を設定する( DispFlag:?ウス?イン?を?示するかどうか( TRUE:?示する  FALSE:?示しない )
extern	int			GetMousePoint(			int *XBuf, int *YBuf ) ;										// ?ウス?イン?の位置を取得する
extern	int			SetMousePoint(			int PointX, int PointY ) ;										// ?ウス?イン?の位置を設定する
#ifndef DX_NON_INPUT
extern	int			GetMouseInput(			void ) ;														// ?ウスの??ンの押下状態を取得する
extern	int			GetMouseWheelRotVol(	int CounterReset = TRUE ) ;										// 垂直?ウスホイ?ルの回?量を取得する
extern	int			GetMouseHWheelRotVol(	int CounterReset = TRUE ) ;										// 水平?ウスホイ?ルの回?量を取得する
extern	float		GetMouseWheelRotVolF(	int CounterReset = TRUE ) ;										// 垂直?ウスホイ?ルの回?量を取得する( 戻り値が float ? )
extern	float		GetMouseHWheelRotVolF(	int CounterReset = TRUE ) ;										// 水平?ウスホイ?ルの回?量を取得する( 戻り値が float ? )
extern	int			GetMouseInputLog(		int *Button, int *ClickX, int *ClickY, int LogDelete = TRUE ) ;	// ?ウスのクリック情報を一つ取得する( Button:クリックされた??ン( MOUSE_INPUT_LEFT 等 )を格?する変数のアドレス  ClickX:クリックされた時のＸ座標を格?する変数のアドレス  ClickY:クリックされた時のＹ座標を格?する変数のアドレス   LogDelete:取得したクリック情報一つ分をログから削除するかどうか( TRUE:削除する  FALSE:削除しない、つまり次にこの関数が呼ばれたときに同じ値を取得することになる )??戻り値  0:クリック情報取得できた?-1:クリック情報が無かった、つまり前回の呼び出し( または起動時から最初の呼び出し )の間に一度も?ウスの??ンがクリックされなかった )
#endif // DX_NON_INPUT














// DxMemory.cpp関数プロト?イプ宣言

// メモリ確保系関数
extern	void*		DxAlloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// 指定のサイズのメモリを確保する( AllocSize:確保するメモリのサイズ( 単位:byte )  File:DxAllocを呼んだ??スフ?イル名( デバッグ用 )  Line:DxAllocを呼んだ??スフ?イル中の行番号( デバッグ用 )??戻り値  NULL:メモリの確保失敗   NULL以外:確保したメモリ領域の先頭アドレス )
extern	void*		DxCalloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// 指定のサイズのメモリを確保して、０で埋める、初期化後に０で埋める以外は DxAlloc と動作は同じ
extern	void*		DxRealloc(						void *Memory , size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// メモリの再確保を行う( Memory:再確保を行うメモリ領域の先頭アドレス( DxAlloc の戻り値 )  AllocSize:新しい確保サイズ?FileとLine の説明は DxAlloc の注釈の通り ?戻り値 NULL:メモリの再確保失敗?NULL以外:再確保した新しいメモリ領域の先頭アドレス?)
extern	void		DxFree(							void *Memory ) ;																// メモリを解放する( Memory:解放するメモリ領域の先頭アドレス( DxAlloc の戻り値 ) )
extern	size_t		DxSetAllocSizeTrap(				size_t Size ) ;																	// 列挙対象にするメモリの確保容量をセットする
extern	int			DxSetAllocPrintFlag(			int Flag ) ;																	// ＤＸライブラリ内でメモリ確保が行われる時に情報を出力するかどうかをセットする
extern	size_t		DxGetAllocSize(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリサイズを取得する
extern	int			DxGetAllocNum(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリの数を取得する
extern	void		DxDumpAlloc(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリを列挙する
extern	int			DxErrorCheckAlloc(				void ) ;																		// 確保したメモリ情報が破壊されていないか調べる( -1:破壊あり  0:なし )
extern	int			DxSetAllocSizeOutFlag(			int Flag ) ;																	// メモリが確保、解放が行われる度に確保しているメモリの容量を出力するかどうかのフラグをセットする
extern	int			DxSetAllocMemoryErrorCheckFlag(	int Flag ) ;																	// メモリの確保、解放が行われる度に確保しているメモリ確保情報が破損していないか調べるかどうかのフラグをセットする
















// DxNetwork.cpp関数プロト?イプ宣言

#ifndef DX_NON_NETWORK

// 通信関係
extern	int			ProcessNetMessage(				int RunReleaseProcess = FALSE ) ;														// 通信メッセ?ジの処理をする関数

extern	int			GetHostIPbyName(				const TCHAR *HostName, IPDATA      *IPDataBuf ) ;										// ＤＮＳサ?バ?を使ってホスト名からＩＰアドレスを取得する( IPv4版 )
extern	int			GetHostIPbyName_IPv6(			const TCHAR *HostName, IPDATA_IPv6 *IPDataBuf ) ;										// ＤＮＳサ?バ?を使ってホスト名からＩＰアドレスを取得する( IPv6版 )
extern 	int			ConnectNetWork(					IPDATA      IPData, int Port = -1 ) ;													// 他?シンに接続する( IPv4版 )
extern	int			ConnectNetWork_IPv6(			IPDATA_IPv6 IPData, int Port = -1 ) ;													// 他?シンに接続する( IPv6版 )
extern 	int			ConnectNetWork_ASync(			IPDATA      IPData, int Port = -1 ) ;													// 他?シンに接続する( IPv4版 )、非同期版
extern	int			ConnectNetWork_IPv6_ASync(		IPDATA_IPv6 IPData, int Port = -1 ) ;													// 他?シンに接続する( IPv6版 )、非同期版
extern 	int			PreparationListenNetWork(		int Port = -1 ) ;																		// 接続を受けられる状態にする( IPv4版 )
extern 	int			PreparationListenNetWork_IPv6(	int Port = -1 ) ;																		// 接続を受けられる状態にする( IPv6版 )
extern 	int			StopListenNetWork(				void ) ;																				// 接続を受けつけ状態の解除
extern 	int			CloseNetWork(					int NetHandle ) ;																		// 接続を終了する

extern 	int			GetNetWorkAcceptState(			int NetHandle ) ;																		// 接続状態を取得する
extern 	int			GetNetWorkDataLength(			int NetHandle ) ;																		// 受信デ??の量を得る
extern	int			GetNetWorkSendDataLength(		int NetHandle ) ;																		// 未送信のデ??の量を得る 
extern 	int			GetNewAcceptNetWork(			void ) ;																				// 新たに接続した通信回線を得る
extern 	int			GetLostNetWork(					void ) ;																				// 接続を切断された通信回線を得る
extern 	int			GetNetWorkIP(					int NetHandle, IPDATA      *IpBuf ) ;													// 接続先のＩＰを得る( IPv4版 )
extern 	int			GetNetWorkIP_IPv6(				int NetHandle, IPDATA_IPv6 *IpBuf ) ;													// 接続先のＩＰを得る( IPv6版 )
extern	int			GetMyIPAddress(					IPDATA *IpBuf ) ;																		// 自分のＩＰを得る
extern	int			SetConnectTimeOutWait(			int Time ) ;																			// 接続の?イ?アウトまでの時間を設定する
extern	int			SetUseDXNetWorkProtocol(		int Flag ) ;																			// ＤＸライブラリの通信?態を使うかどうかをセットする
extern	int			GetUseDXNetWorkProtocol(		void ) ; 																				// ＤＸライブラリの通信?態を使うかどうかを取得する
extern	int			SetUseDXProtocol(				int Flag ) ;																			// SetUseDXNetWorkProtocol の別名
extern	int			GetUseDXProtocol(				void ) ; 																				// GetUseDXNetWorkProtocol の別名
extern	int			SetNetWorkCloseAfterLostFlag(	int Flag ) ;																			// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグをセットする
extern	int			GetNetWorkCloseAfterLostFlag(	void ) ;																				// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグを取得する
//extern	int			SetProxySetting( int UseFlag, const char *Address, int Port ) ;														// ＨＴＴＰ通信で使用するプロキシ設定を行う
//extern	int			GetProxySetting( int *UseFlagBuffer, char *AddressBuffer, int *PortBuffer ) ;										// ＨＴＴＰ通信で使用するプロキシ設定を取得する
//extern	int			SetIEProxySetting( void ) ;																							// ＩＥのプロキシ設定を適応する

extern 	int			NetWorkRecv(			int NetHandle, void *Buffer, int Length ) ;														// 受信したデ??を読み込む
extern	int			NetWorkRecvToPeek(		int NetHandle, void *Buffer, int Length ) ;														// 受信したデ??を読み込む、読み込んだデ??はバッフ?から削除されない
extern	int			NetWorkRecvBufferClear(	int NetHandle ) ;																				// 受信したデ??をクリアする
extern 	int			NetWorkSend(			int NetHandle, const void *Buffer, int Length ) ;												// デ??を送信する

extern	int			MakeUDPSocket(			int RecvPort = -1 ) ;																			// UDPを使用した通信を行う?ケットハンドルを作成する( RecvPort を -1 にすると送信専用の?ケットハンドルになります )
extern	int			MakeUDPSocket_IPv6(		int RecvPort = -1 ) ;																			// UDPを使用した通信を行う?ケットハンドルを作成する( RecvPort を -1 にすると送信専用の?ケットハンドルになります )( IPv6版 )
extern	int			DeleteUDPSocket(		int NetUDPHandle ) ;																			// UDPを使用した通信を行う?ケットハンドルを削除する
extern	int			NetWorkSendUDP(			int NetUDPHandle, IPDATA       SendIP, int SendPort,  const void *Buffer, int Length ) ;			// UDPを使用した通信で指定のＩＰにデ??を送信する、Length は最大65507、SendPort を -1 にすると MakeUDPSocket に RecvPort で渡した??トが使用されます( 戻り値  0以上;送信できたデ??サイズ  -1:エラ?  -2:送信デ??が大きすぎる  -3:送信?備ができていない  )
extern	int			NetWorkSendUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6  SendIP, int SendPort,  const void *Buffer, int Length ) ;			// UDPを使用した通信で指定のＩＰにデ??を送信する、Length は最大65507、SendPort を -1 にすると MakeUDPSocket に RecvPort で渡した??トが使用されます( 戻り値  0以上;送信できたデ??サイズ  -1:エラ?  -2:送信デ??が大きすぎる  -3:送信?備ができていない  )( IPv6版 )
extern	int			NetWorkRecvUDP(			int NetUDPHandle, IPDATA      *RecvIP, int *RecvPort,       void *Buffer, int Length, int Peek ) ;	// UDPを使用した通信でデ??を受信する、Peek に TRUE を渡すと受信に成功してもデ??を受信キュ?から削除しません( 戻り値  0以上:受信したデ??のサイズ  -1:エラ?  -2:バッフ?のサイズが足りない  -3:受信デ??がない )
extern	int			NetWorkRecvUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6 *RecvIP, int *RecvPort,       void *Buffer, int Length, int Peek ) ;	// UDPを使用した通信でデ??を受信する、Peek に TRUE を渡すと受信に成功してもデ??を受信キュ?から削除しません( 戻り値  0以上:受信したデ??のサイズ  -1:エラ?  -2:バッフ?のサイズが足りない  -3:受信デ??がない )( IPv6版 )
//extern int		CheckNetWorkSendUDP(	int NetUDPHandle ) ;																			// UDPを使用した通信でデ??が送信できる状態かどうかを調べる( 戻り値  -1:エラ?  TRUE:送信可?  FALSE:送信不可? )
extern	int			CheckNetWorkRecvUDP(	int NetUDPHandle ) ;																			// UDPを使用した通信で新たな受信デ??が存在するかどうかを調べる( 戻り値  -1:エラ?  TRUE:受信デ??あり  FALSE:受信デ??なし )

/*	使用不可
extern	int			HTTP_FileDownload(			const char *FileURL, const char *SavePath = NULL , void **SaveBufferP = NULL , int *FileSize = NULL , char **ParamList = NULL ) ;						// HTTP を使用してネットワ?ク上のフ?イルを?ウンロ?ドする
extern	int			HTTP_GetFileSize(			const char *FileURL ) ;																		// HTTP を使用してネットワ?ク上のフ?イルのサイズを得る

extern	int			HTTP_StartFileDownload(		const char *FileURL, const char *SavePath, void **SaveBufferP = NULL , char **ParamList = NULL ) ;	// HTTP を使用したネットワ?ク上のフ?イルを?ウンロ?ドする処理を開始する
extern	int			HTTP_StartGetFileSize(		const char *FileURL ) ;																		// HTTP を使用したネットワ?ク上のフ?イルのサイズを得る処理を開始する
extern	int			HTTP_Close(					int HttpHandle ) ;																			// HTTP の処理を終了し、ハンドルを解放する
extern	int			HTTP_CloseAll(				void ) ;																					// 全てのハンドルに対して HTTP_Close を行う
extern	int			HTTP_GetState(				int HttpHandle ) ;																			// HTTP 処理の現在の状態を得る( NET_RES_COMPLETE 等 )
extern	int			HTTP_GetError(				int HttpHandle ) ;																			// HTTP 処理でエラ?が発生した場合、エラ?の内容を得る( HTTP_ERR_NONE 等 )
extern	int			HTTP_GetDownloadFileSize(	int HttpHandle ) ;																			// HTTP 処理で対象となっているフ?イルのサイズを得る( 戻り値: -1 = エラ?・若しくはまだフ?イルのサイズを取得していない  0以上 = フ?イルのサイズ )
extern	int			HTTP_GetDownloadedFileSize( int HttpHandle ) ;																			// HTTP 処理で既に?ウンロ?ドしたフ?イルのサイズを取得する

extern	int			fgetsForNetHandle(			int NetHandle, char *strbuffer ) ;															// fgets のネットワ?クハンドル版( -1:取得できず 0:取得できた )
extern	int			URLAnalys(					const char *URL, char *HostBuf = NULL , char *PathBuf = NULL , char *FileNameBuf = NULL , int *PortBuf = NULL ) ;	// ＵＲＬを解析する
extern	int			URLConvert(					char *URL, int ParamConvert = TRUE , int NonConvert = FALSE ) ;								// HTTP に渡せない記号が使われた文字列を渡せるような文字列に変換する( 戻り値: -1 = エラ?  0以上 = 変換後の文字列のサイズ )
extern	int			URLParamAnalysis(			char **ParamList, char **ParamStringP ) ;													// HTTP 用パラメ??リストから一つのパラメ??文字列を作成する( 戻り値:  -1 = エラ?  0以上 = パラメ??の文字列の長さ )
*/

#endif // DX_NON_NETWORK
















// DxInputString.cpp関数プロト?イプ宣言

#ifndef DX_NON_INPUTSTRING

// 文字コ?ドバッフ??作関係
extern	int			StockInputChar(		TCHAR CharCode ) ;								// 文字コ?ドバッフ?に文字コ?ドをストックする
extern	int			ClearInputCharBuf(	void ) ;										// 文字コ?ドバッフ?をクリアする
extern	TCHAR		GetInputChar(		int DeleteFlag ) ;								// 文字コ?ドバッフ?に溜まったデ??から文字コ?ドを一つ取得する
extern	TCHAR		GetInputCharWait(	int DeleteFlag ) ;								// 文字コ?ドバッフ?に溜まったデ??から文字コ?ドを一つ取得する、バッフ?になにも文字コ?ドがない場合は文字コ?ドがバッフ?に一文字分溜まるまで待つ

extern	int			GetOneChar(			TCHAR *CharBuffer, int DeleteFlag ) ;			// 文字コ?ドバッフ?に溜まったデ??から１文字分取得する
extern	int			GetOneCharWait(		TCHAR *CharBuffer, int DeleteFlag ) ;			// 文字コ?ドバッフ?に溜まったデ??から１文字分取得する、バッフ?に何も文字コ?ドがない場合は文字コ?ドがバッフ?に一文字分溜まるまで待つ
extern	int			GetCtrlCodeCmp(		TCHAR Char ) ;									// 指定の文字コ?ドがアスキ?コントロ?ルコ?ドか調べる

#endif // DX_NON_INPUTSTRING

#ifndef DX_NON_KEYEX

extern	int			DrawIMEInputString(				int x, int y, int SelectStringNum ) ;	// 画面上に入力中の文字列を?画する
extern	int			SetUseIMEFlag(					int UseFlag ) ;							// ＩＭＥを使用するかどうかを設定する
extern	int			SetInputStringMaxLengthIMESync(	int Flag ) ;							// ＩＭＥで入力できる最大文字数を MakeKeyInput の設定に合わせるかどうかをセットする( TRUE:あわせる  FALSE:あわせない(デフォルト) )
extern	int			SetIMEInputStringMaxLength(		int Length ) ;							// ＩＭＥで一度に入力できる最大文字数を設定する( 0:制限なし  1以上:指定の文字数で制限 )

#endif // DX_NON_KEYEX

extern	int			GetStringPoint(				const TCHAR *String, int Point ) ;			// 全角文字、半角文字入り乱れる中から指定の文字数での半角文字数を得る
extern	int			GetStringPoint2(			const TCHAR *String, int Point ) ;			// 全角文字、半角文字入り乱れる中から指定の文字数での全角文字数を得る
extern	int			GetStringLength(			const TCHAR *String ) ;						// 全角文字、半角文字入り乱れる中から文字数を取得する

#ifndef DX_NON_FONT
extern	int			DrawObtainsString(			int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;		// ?画可?領域に収まるように改行しながら文字列を?画
extern	int			DrawObtainsString_CharClip(	int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;		// ?画可?領域に収まるように改行しながら文字列を?画( クリップが文字単位 )
#endif // DX_NON_FONT
extern	int			DrawObtainsBox(				int x1, int y1, int x2, int y2, int AddY, int Color, int FillFlag ) ;																																										// ?画可?領域に収まるように補正を加えながら矩?を?画

#ifndef DX_NON_KEYEX

extern	int			InputStringToCustom(		int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;		// 文字列の入力取得

extern	int			KeyInputString(				int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// 文字列の入力取得
extern	int			KeyInputSingleCharString(	int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// 半角文字列のみの入力取得
extern	int			KeyInputNumber(				int x, int y, int MaxNum, int MinNum, int CancelValidFlag ) ;																	// 数値の入力取得

extern	int			GetIMEInputModeStr(			TCHAR *GetBuffer ) ;																											// IMEの入力モ?ド文字列を取得する
extern	const IMEINPUTDATA* GetIMEInputData(	void ) ;																														// IMEで入力中の文字列の情報を取得する
#if defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStrBack, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffffULL ,	ULONGLONG IMESelectWinF = 0xffffffffffffffffULL , ULONGLONG SelectStrBackColor = 0xffffffffffffffffULL , ULONGLONG SelectStrColor = 0xffffffffffffffffULL , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffffULL, ULONGLONG IMEStr = 0xffffffffffffffffULL, ULONGLONG IMEStrE = 0xffffffffffffffffULL  ) ;	// InputString関数使用時の文字の各色を変更する
#else // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStrBack, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff, ULONGLONG IMEStr = 0xffffffffffffffff, ULONGLONG IMEStrE = 0xffffffffffffffff ) ;	// InputString関数使用時の文字の各色を変更する
#endif // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringFont(		int FontHandle ) ;																												// キ?入力文字列?画関連で使用するフォントのハンドルを変更する(-1でデフォルトのフォントハンドル)
extern	int			DrawKeyInputModeString(		int x, int y ) ;																												// 入力モ?ド文字列を?画する

extern	int			InitKeyInput(				void ) ;																														// キ?入力デ??初期化
extern	int			MakeKeyInput(				int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;			// 新しいキ?入力ハンドルの作成
extern	int			DeleteKeyInput(				int InputHandle ) ;																												// キ?入力ハンドルの削除
extern	int			SetActiveKeyInput(			int InputHandle ) ;																												// 指定のキ?入力ハンドルをアクティブにする( -1 を指定するとアクティブなキ?入力ハンドルが無い状態になります )
extern	int			GetActiveKeyInput(			void ) ;																														// 現在アクティブになっているキ?入力ハンドルを取得する
extern	int			CheckKeyInput(				int InputHandle ) ;																												// キ?入力ハンドルの入力が終了しているか取得する
extern	int			ReStartKeyInput(			int InputHandle ) ;																												// 入力が完了したキ?入力ハンドルを再度編集状態に戻す
extern	int			ProcessActKeyInput(			void ) ;																														// キ?入力ハンドル処理関数
extern	int			DrawKeyInputString(			int x, int y, int InputHandle ) ;																								// キ?入力ハンドルの入力中情報の?画

extern	int			SetKeyInputSelectArea(		int  SelectStart, int  SelectEnd, int InputHandle ) ;																			// キ?入力ハンドルの指定の領域を選択状態にする( SelectStart と SelectEnd に -1 を指定すると選択状態が解除されます )
extern	int			GetKeyInputSelectArea(		int *SelectStart, int *SelectEnd, int InputHandle ) ;																			// キ?入力ハンドルの選択領域を取得する
extern	int			SetKeyInputDrawStartPos(	int DrawStartPos, int InputHandle ) ;																							// キ?入力ハンドルの?画開始文字位置を設定する
extern	int			GetKeyInputDrawStartPos(	int InputHandle ) ;																												// キ?入力ハンドルの?画開始文字位置を取得する
extern	int			SetKeyInputCursorBrinkTime(	int Time ) ;																													// キ?入力ハンドルのキ?入力時のカ??ルの?滅する早さをセットする
extern	int			SetKeyInputCursorBrinkFlag(	int Flag ) ;																													// キ?入力ハンドルのキ?入力時のカ??ルを?滅させるかどうかをセットする
extern	int			SetKeyInputString(			const TCHAR *String, int InputHandle ) ;																						// キ?入力ハンドルに指定の文字列をセットする
extern	int			SetKeyInputNumber(			int   Number,        int InputHandle ) ;																						// キ?入力ハンドルに指定の数値を文字に置き換えてセットする
extern	int			SetKeyInputNumberToFloat(	float Number,        int InputHandle ) ;																						// キ?入力ハンドルに指定の浮動小数?値を文字に置き換えてセットする
extern	int			GetKeyInputString(			TCHAR *StrBuffer,    int InputHandle ) ;																						// キ?入力ハンドルの入力中の文字列を取得する
extern	int			GetKeyInputNumber(			int InputHandle ) ;																												// キ?入力ハンドルの入力中の文字列を整数値として取得する
extern	float		GetKeyInputNumberToFloat(	int InputHandle ) ;																												// キ?入力ハンドルの入力中の文字列を浮動小数?値として取得する
extern	int			SetKeyInputCursorPosition(	int Position,        int InputHandle ) ;																						// キ?入力ハンドルの現在のカ??ル位置を設定する
extern	int			GetKeyInputCursorPosition(	int InputHandle ) ;																												// キ?入力ハンドルの現在のカ??ル位置を取得する

#endif // DX_NON_KEYEX











// DxFile.cpp関数プロト?イプ宣言

// フ?イルアクセス関数
extern	int			FileRead_open(				const TCHAR *FilePath , int ASync = FALSE ) ;					// フ?イルを開く
extern	LONGLONG	FileRead_size(				const TCHAR *FilePath ) ;										// フ?イルのサイズを取得する
extern	int			FileRead_close(				int FileHandle ) ;												// フ?イルを閉じる
extern	LONGLONG	FileRead_tell(				int FileHandle ) ;												// フ?イル?イン?の読み込み位置を取得する
extern	int			FileRead_seek(				int FileHandle , LONGLONG Offset , int Origin ) ;				// フ?イル?イン?の読み込み位置を変更する
extern	int			FileRead_read(				void *Buffer , int ReadSize , int FileHandle ) ;				// フ?イルからデ??を読み込む
extern	int			FileRead_idle_chk(			int FileHandle ) ;												// フ?イル読み込みが完了しているかどうかを取得する
extern	int			FileRead_eof(				int FileHandle ) ;												// フ?イルの読み込み位置が終?に達しているかどうかを取得する
extern	int			FileRead_gets(				TCHAR *Buffer , int BufferSize , int FileHandle ) ;				// フ?イルから文字列を読み出す
extern	TCHAR		FileRead_getc(				int FileHandle ) ;												// フ?イルから一文字読み出す
extern	int			FileRead_scanf(				int FileHandle , const TCHAR *Format , ... ) ;					// フ?イルから書式化されたデ??を読み出す

extern	DWORD_PTR	FileRead_createInfo(		const TCHAR *ObjectPath ) ;										// フ?イル情報ハンドルを作成する( 戻り値  -1:エラ?  -1以外:フ?イル情報ハンドル )
extern	int			FileRead_getInfoNum(		DWORD_PTR FileInfoHandle ) ;									// フ?イル情報ハンドル中のフ?イルの数を取得する
extern	int			FileRead_getInfo(			int Index , FILEINFO *Buffer , DWORD_PTR FileInfoHandle ) ;		// フ?イル情報ハンドル中のフ?イルの情報を取得する
extern	int			FileRead_deleteInfo(		DWORD_PTR FileInfoHandle ) ;									// フ?イル情報ハンドルを削除する

extern	DWORD_PTR	FileRead_findFirst(			const TCHAR *FilePath, FILEINFO *Buffer ) ;						// 指定のフ?イル又はフォル?の情報を取得し、フ?イル検索ハンドルも作成する( 戻り値: -1=エラ?  -1以外=フ?イル検索ハンドル )
extern	int			FileRead_findNext(			DWORD_PTR FindHandle, FILEINFO *Buffer ) ;						// 条件の合致する次のフ?イルの情報を取得する( 戻り値: -1=エラ?  0=成功 )
extern	int			FileRead_findClose(			DWORD_PTR FindHandle ) ;										// フ?イル検索ハンドルを閉じる( 戻り値: -1=エラ?  0=成功 )

extern	int			FileRead_fullyLoad(			const TCHAR *FilePath ) ;										// 指定のフ?イルの内容を全てメモリに読み込み、その情報のアクセスに必要なハンドルを返す( 戻り値  -1:エラ?  -1以外:ハンドル )、使い終わったらハンドルは FileRead_fullyLoad_delete で削除する必要があります
extern	int			FileRead_fullyLoad_delete(	int FLoadHandle ) ;												// FileRead_fullyLoad で読み込んだフ?イルのハンドルを削除する
extern	const void*	FileRead_fullyLoad_getImage( int FLoadHandle ) ;											// FileRead_fullyLoad で読み込んだフ?イルの内容を格?したメモリアドレスを取得する
extern	LONGLONG	FileRead_fullyLoad_getSize(	int FLoadHandle ) ;												// FileRead_fullyLoad で読み込んだフ?イルのサイズを取得する

// 設定関係関数
extern	int			GetStreamFunctionDefault(	void ) ;														// ＤＸライブラリでストリ??デ??アクセスに使用する関数がデフォルトのものか調べる( TRUE:デフォルトのもの  FALSE:デフォルトではない )
extern	int			ChangeStreamFunction(		const STREAMDATASHREDTYPE2 *StreamThread ) ;					// ＤＸライブラリでストリ??デ??アクセスに使用する関数を変更する

// 補助関係関数
extern int			ConvertFullPath( const TCHAR *Src, TCHAR *Dest, const TCHAR *CurrentDir = NULL ) ;			// フルパスではないパス文字列をフルパスに変換する( CurrentDir はフルパスである必要がある(語尾に『\』があっても無くても良い) )( CurrentDir が NULL の場合は現在のカレントディレクトリを使用する )












// DxInput.cpp関数プロト?イプ宣言

#ifndef DX_NON_INPUT

// 入力状態取得関数
extern	int			CheckHitKey(							int KeyCode ) ;															// キ???ドの押下状態を取得する
extern	int			CheckHitKeyAll(							int CheckType = DX_CHECKINPUT_ALL ) ;									// どれか一つでもキ?が押されているかどうかを取得( 押されていたら戻り値が 0 以外になる )
extern	int			GetHitKeyStateAll(						DX_CHAR *KeyStateBuf ) ;												// すべてのキ?の押下状態を取得する( KeyStateBuf:char?256個分の配列の先頭アドレス )
extern	int			SetKeyExclusiveCooperativeLevelFlag(	int Flag ) ;															// DirectInput のキ???ドの協調レベルを排他レベルにするかどうかを設定する( TRUE:排他レベルにする  FALSE:標?レベルにする( デフォルト ) )、DxLib_Init の呼び出し前でのみ実行可??
extern	int			GetJoypadNum(							void ) ;																// ジョイパッドが接続されている数を取得する
extern	int			GetJoypadInputState(					int InputType ) ;														// ジョイパッドの入力状態を取得する
extern	int			GetJoypadAnalogInput(					int *XBuf, int *YBuf, int InputType ) ;									// ジョイパッドのアナログ的なスティック入力情報を得る
extern	int			GetJoypadAnalogInputRight(				int *XBuf, int *YBuf, int InputType ) ;									// ( 使用非推奨 )ジョイパッドのアナログ的なスティック入力情報を得る(右スティック用)
extern	int			GetJoypadDirectInputState(				int InputType, DINPUT_JOYSTATE *DInputState ) ;							// DirectInput から得られるジョイパッドの生のデ??を取得する( DX_INPUT_KEY や DX_INPUT_KEY_PAD1 など、キ???ドが絡む?イプを InputType に渡すとエラ?となり -1 を返す )
extern	int			CheckJoypadXInput(						int InputType ) ;														// 指定の入力デバイスが XInput に対応しているかどうかを取得する( 戻り値  TRUE:XInput対応の入力デバイス  FALSE:XInput非対応の入力デバイス   -1:エラ? )( DX_INPUT_KEY や DX_INPUT_KEY_PAD1 など、キ???ドが絡む?イプを InputType に渡すとエラ?となり -1 を返す )
extern	int			GetJoypadXInputState(					int InputType, XINPUT_STATE *XInputState ) ;							// XInput から得られる入力デバイス( Xbox360コントロ?ラ等 )の生のデ??を取得する( XInput非対応のパッドの場合はエラ?となり -1 を返す、DX_INPUT_KEY や DX_INPUT_KEY_PAD1 など、キ???ドが絡む?イプを InputType に渡すとエラ?となり -1 を返す )
extern	int			KeyboradBufferProcess(					void ) ;																// キ???ドのバッフ?からデ??を取得する処理
extern	int			GetJoypadGUID(							int PadIndex, GUID *GuidBuffer ) ;										// ジョイパッドのＧＵIＤを得る
extern	int			ConvertKeyCodeToVirtualKey(				int KeyCode ) ;															// ＤＸライブラリのキ?コ?ド( KEY_INPUT_A など )に対応する Windows の仮想キ?コ?ド( VK_LEFT など ) を取得する( KeyCode:変換したいＤＸライブラリのキ?コ?ド?戻り値：Windowsの仮想キ?コ?ド )
extern	int			ConvertVirtualKeyToKeyCode(				int VirtualKey ) ;														//  Windows の仮想キ?コ?ド( VK_LEFT など ) に対応するＤＸライブラリのキ?コ?ド( KEY_INPUT_A など )を取得する( VirtualKey:変換したいWindowsの仮想キ?コ?ド?戻り値：ＤＸライブラリのキ?コ?ド )
extern	int			SetJoypadInputToKeyInput(				int InputType, int PadInput, int KeyInput1, int KeyInput2 = -1 , int KeyInput3 = -1 , int KeyInput4 = -1  ) ; // ジョイパッドの入力に対応したキ???ドの入力を設定する( InputType:設定を変更するパッドの識別子( DX_INPUT_PAD1等 )??PadInput:設定を変更するパッド??ンの識別子( PAD_INPUT_1 等 )??KeyInput1:PadInput を押下したことにするキ?コ?ド( KEY_INPUT_A など )その１??KeyInput2:その２、-1で設定なし??KeyInput3:その３、-1で設定なし??KeyInput4:その４、-1で設定なし )
extern	int			SetJoypadDeadZone(						int InputType, double Zone ) ;											// ジョイパッドの無効??ンの設定を行う( InputType:設定を変更するパッドの識別子( DX_INPUT_PAD1等 )   Zone:新しい無効??ン( 0.0 ? 1.0 )、デフォルト値は 0.35 )
extern	int			StartJoypadVibration(					int InputType, int Power, int Time ) ;									// ジョイパッドの振動を開始する
extern	int			StopJoypadVibration(					int InputType ) ;														// ジョイパッドの振動を停?する
extern	int			GetJoypadPOVState(						int InputType, int POVNumber ) ;										// ジョイパッドのＰＯＶ入力の状態を得る( 戻り値?指定のPOVデ??の角度、単位は角度の１００?( 90度なら 9000 ) 中心位置にある場合は -1 が返る )
extern	int			GetJoypadName(							int InputType, TCHAR *InstanceNameBuffer, TCHAR *ProductNameBuffer ) ;	// ジョイパッドのデバイス登?名と製品登?名を取得する
extern	int			ReSetupJoypad(							void ) ;																// ジョイパッドの再セットアップを行う( 新たに接続されたジョイパッドがあったら検出される )

extern	int			SetKeyboardNotDirectInputFlag(			int Flag ) ;															// キ???ドの入力処理に DirectInput を使わないかどうかを設定する( TRUE:DirectInput を使わず、Windows標???を使用する??FALSE:DirectInput を使用する )
extern	int			SetUseDirectInputFlag(					int Flag ) ;															// 入力処理に DirectInput を使用するかどうかを設定する( TRUE:DirectInput を使用する??FALSE:DirectInput を使わず、Windows標???を使用する )
extern	int			SetUseXInputFlag(						int Flag ) ;															// Xbox360コントロ?ラの入力処理に XInput を使用するかどうかを設定する( TRUE:XInput を使用する( デフォルト )??FALSE:XInput を使用しない )
extern	int			SetUseJoypadVibrationFlag(				int Flag ) ;															// ジョイパッドの振動??を使用するかどうかを設定する( TRUE:使用する??FALSE:使用しない )

#endif // DX_NON_INPUT







#ifndef DX_NOTUSE_DRAWFUNCTION

// 画像処理系関数プロト?イプ宣言

// グラフィックハンドル作成関係関数
extern	int			MakeGraph(						int SizeX, int SizeY, int NotUse3DFlag = FALSE ) ;							// 指定サイズのグラフィックハンドルを作成する
extern	int			MakeScreen(						int SizeX, int SizeY, int UseAlphaChannel = FALSE ) ;						// SetDrawScreen で?画対象にできるグラフィックハンドルを作成する
extern	int			DerivationGraph(				int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle ) ;			// 指定のグラフィックハンドルの指定部分だけを抜き出して新たなグラフィックハンドルを作成する
extern	int			DeleteGraph(					int GrHandle, int LogOutFlag = FALSE ) ;									// グラフィックハンドルを削除する
extern	int			DeleteSharingGraph(				int GrHandle ) ;															// 指定のグラフィックハンドルと、同じグラフィックハンドルから派生しているグラフィックハンドル( DerivationGraph で派生したハンドル、LoadDivGraph 読み込んで作成された複数のハンドル )を一度に削除する
extern	int			GetGraphNum(					void ) ;																	// 有効なグラフィックハンドルの数を取得する
extern	int			FillGraph(						int GrHandle, int Red, int Green, int Blue, int Alpha = 255 ) ;				// グラフィックハンドルを指定の色で塗りつぶす
extern	int			SetGraphLostFlag(				int GrHandle, int *LostFlag ) ;												// 指定のグラフィックハンドルが削除された際に 1 にする変数のアドレスを設定する
extern	int			InitGraph(						int LogOutFlag = FALSE ) ;													// すべてのグラフィックハンドルを削除する
extern	int			ReloadFileGraphAll(				void ) ;																	// フ?イルから画像を読み込んだ全てのグラフィックハンドルについて、再度フ?イルから画像を読み込む

// シャドウ?ップハンドル関係関数
extern	int			MakeShadowMap(					int SizeX, int SizeY ) ;													// シャドウ?ップハンドルを作成する
extern	int			DeleteShadowMap(				int SmHandle ) ;															// シャドウ?ップハンドルを削除する
extern	int			SetShadowMapLightDirection(		int SmHandle, VECTOR Direction ) ;											// シャドウ?ップが想定するライトの方向を設定する
extern	int			ShadowMap_DrawSetup(			int SmHandle ) ;															// シャドウ?ップへの?画の?備を行う
extern	int			ShadowMap_DrawEnd(				void ) ;																	// シャドウ?ップへの?画を終了する
extern	int			SetUseShadowMap(				int SmSlotIndex, int SmHandle ) ;											// ?画で使用するシャドウ?ップを指定する、有効なスロットは０?２、SmHandle に -1 を渡すと指定のスロットのシャドウ?ップを解除
extern	int			SetShadowMapDrawArea(			int SmHandle, VECTOR MinPosition, VECTOR MaxPosition ) ;					// シャドウ?ップに?画する際の範囲を設定する( この関数で?画範囲を設定しない場合は視錐台を拡大した範囲が?画範囲となる )
extern	int			ResetShadowMapDrawArea(			int SmHandle ) ;															// SetShadowMapDrawArea の設定を解除する
extern	int			SetShadowMapAdjustDepth(		int SmHandle, float Depth ) ;												// シャドウ?ップを使用した?画時の補正?度を設定する
extern	int			TestDrawShadowMap(				int SmHandle, int x1, int y1, int x2, int y2 ) ;							// シャドウ?ップを画面にテスト?画する

// グラフィックハンドルへの画像?送関数
extern	int			BltBmpToGraph(					const COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp,                                                                      int CopyPointX, int CopyPointY,                              int  GrHandle ) ;					// ＢＭＰの内容をグラフィックハンドルに?送
extern	int			BltBmpToDivGraph(				const COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp,                                                                      int AllNum, int XNum, int YNum, int Width, int Height, const int *GrHandle, int ReverseFlag ) ;	// ＢＭＰの内容を分割作成したグラフィックハンドルたちに?送
extern	int			BltBmpOrGraphImageToGraph(		const COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, const BASEIMAGE *RgbImage, const BASEIMAGE *AlphaImage, int CopyPointX, int CopyPointY,                              int  GrHandle ) ;					// ＢＭＰ か BASEIMAGE をグラフィックハンドルに?送
extern	int			BltBmpOrGraphImageToGraph2(		const COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, const BASEIMAGE *RgbImage, const BASEIMAGE *AlphaImage, const RECT *SrcRect, int DestX, int DestY,                   int  GrHandle ) ;					// ＢＭＰ か BASEIMAGE の指定の領域をグラフィックハンドルに?送
extern	int			BltBmpOrGraphImageToDivGraph(	const COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, const BASEIMAGE *RgbImage, const BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int Width, int Height, const int *GrHandle, int ReverseFlag ) ;	// ＢＭＰ か BASEIMAGE を分割作成したグラフィックハンドルたちに?送

// 画像からグラフィックハンドルを作成する関数
extern	int			LoadBmpToGraph(					const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL ) ;								// 画像フ?イルからグラフィックハンドルを作成する
extern	int			LoadGraph(						const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// 画像フ?イルからグラフィックハンドルを作成する
extern	int			LoadReverseGraph(				const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// 画像フ?イルを反?したものでグラフィックハンドルを作成する
extern	int			LoadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// 画像フ?イルを分割してグラフィックハンドルを作成する
extern	int			LoadDivBmpToGraph(				const TCHAR *FileName, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag, int ReverseFlag ) ;	// 画像フ?イルを分割してグラフィックハンドルを作成する
extern	int			LoadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// 画像フ?イルを反?したものを分割してグラフィックハンドルを作成する
extern	int			LoadBlendGraph(					const TCHAR *FileName ) ;																											// 画像フ?イルからブレンド用グラフィックハンドルを作成する
#ifdef __WINDOWS__
extern	int			LoadGraphToResource(			int ResourceID ) ;																													// 画像リ??スからグラフィックハンドルを作成する
extern	int			LoadDivGraphToResource(			int ResourceID, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;											// 画像リ??スを分割してグラフィックハンドルを作成する
extern	int			LoadGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType ) ;																			// 画像リ??スからグラフィックハンドルを作成する
extern	int			LoadDivGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;		// 画像リ??スを分割してグラフィックハンドルを作成する
#endif // __WINDOWS__

extern	int			CreateGraphFromMem(				const void *RGBFileImage, int RGBFileImageSize,               const void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,                  int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																			// メモリ上の画像イメ?ジからグラフィックハンドルを作成する
extern	int			ReCreateGraphFromMem(           const void *RGBFileImage, int RGBFileImageSize, int GrHandle, const void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,                  int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																			// メモリ上の画像イメ?ジから既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromMem(          const void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY,       int *HandleBuf,                     int TextureFlag = TRUE , int ReverseFlag = FALSE , const void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;			// メモリ上の画像イメ?ジから分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromMem(        const void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, const int *HandleBuf,                     int TextureFlag = TRUE , int ReverseFlag = FALSE , const void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;			// メモリ上の画像イメ?ジから既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateGraphFromBmp(             const BITMAPINFO *RGBBmpInfo, const void *RGBBmpImage,               const BITMAPINFO *AlphaBmpInfo = NULL , const void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																			// ビット?ップデ??からグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBmp(           const BITMAPINFO *RGBBmpInfo, const void *RGBBmpImage, int GrHandle, const BITMAPINFO *AlphaBmpInfo = NULL , const void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																			// ビット?ップデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromBmp(          const BITMAPINFO *RGBBmpInfo, const void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY,       int *HandleBuf,              int TextureFlag = TRUE , int ReverseFlag = FALSE , const BITMAPINFO *AlphaBmpInfo = NULL , const void *AlphaBmpImage = NULL ) ;	// ビット?ップデ??から分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromBmp(        const BITMAPINFO *RGBBmpInfo, const void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, const int *HandleBuf,              int TextureFlag = TRUE , int ReverseFlag = FALSE , const BITMAPINFO *AlphaBmpInfo = NULL , const void *AlphaBmpImage = NULL ) ;	// ビット?ップデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateDXGraph(					const BASEIMAGE *RgbImage, const BASEIMAGE *AlphaImage,																				int TextureFlag ) ;																									// 基?イメ?ジデ??からサイズを割り出し、それに合ったグラフィックハンドルを作成する
extern	int			CreateGraphFromGraphImage(      const BASEIMAGE *RGBImage,                                                                                                          int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??からグラフィックハンドルを作成する
extern	int			CreateGraphFromGraphImage(      const BASEIMAGE *RGBImage, const BASEIMAGE *AlphaImage,                                                                             int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??からグラフィックハンドルを作成する
extern	int			ReCreateGraphFromGraphImage(    const BASEIMAGE *RGBImage,                              int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			ReCreateGraphFromGraphImage(    const BASEIMAGE *RGBImage, const BASEIMAGE *AlphaImage, int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から既存のグラフィックハンドルにデ??を?送する
extern	int			CreateDivGraphFromGraphImage(         BASEIMAGE *RGBImage,                              int AllNum, int XNum, int YNum, int SizeX, int SizeY,       int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から分割グラフィックハンドルを作成する
extern	int			CreateDivGraphFromGraphImage(         BASEIMAGE *RGBImage, const BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY,       int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromGraphImage(       BASEIMAGE *RGBImage,                              int AllNum, int XNum, int YNum, int SizeX, int SizeY, const int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			ReCreateDivGraphFromGraphImage(       BASEIMAGE *RGBImage, const BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, const int *HandleBuf, int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基?イメ?ジデ??から既存の分割グラフィックハンドルにデ??を?送する
extern	int			CreateGraph(                    int Width, int Height, int Pitch, const void *RGBImage, const void *AlphaImage = NULL , int GrHandle = -1 ) ;																																			// メモリ上のビット?ップイメ?ジからグラフィックハンドルを作成する
extern	int			CreateDivGraph(                 int Width, int Height, int Pitch, const void *RGBImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, const void *AlphaImage = NULL ) ;																							// メモリ上のビット?ップイメ?ジから分割グラフィックハンドルを作成する
extern	int			ReCreateGraph(                  int Width, int Height, int Pitch, const void *RGBImage, int GrHandle, const void *AlphaImage = NULL ) ;																																					// メモリ上のビット?ップイメ?ジからグラフィックハンドルを再作成する
#ifndef DX_NON_SOFTIMAGE
extern	int			CreateBlendGraphFromSoftImage(  int SIHandle ) ;																													// ?フトウエアで扱うイメ?ジからブレンド用画像グラフィックハンドルを作成する( -1:エラ?  -1以外:ブレンド用グラフィックハンドル )
extern	int			CreateGraphFromSoftImage(       int SIHandle ) ;																													// ?フトウエアで扱うイメ?ジからグラフィックハンドルを作成する( -1:エラ?  -1以外:グラフィックハンドル )
extern	int			CreateGraphFromRectSoftImage(   int SIHandle, int x, int y, int SizeX, int SizeY ) ;																				// ?フトウエアで扱うイメ?ジの指定の領域を使ってグラフィックハンドルを作成する( -1:エラ?  -1以外:グラフィックハンドル )
extern	int			ReCreateGraphFromSoftImage(     int SIHandle, int GrHandle ) ;																										// ?フトウエアで扱うイメ?ジから既存のグラフィックハンドルに画像デ??を?送する
extern	int			ReCreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle ) ;																	// ?フトウエアで扱うイメ?ジから既存のグラフィックハンドルに画像デ??を?送する
extern	int			CreateDivGraphFromSoftImage(    int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;												// ?フトウエアで扱うイメ?ジから分割グラフィックハンドルを作成する
#endif // DX_NON_SOFTIMAGE
extern	int			CreateGraphFromBaseImage(       const BASEIMAGE *BaseImage ) ;																										// 基?イメ?ジデ??からグラフィックハンドルを作成する
extern	int			CreateGraphFromRectBaseImage(   const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY ) ;																	// 基?イメ?ジデ??の指定の領域を使ってグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBaseImage(     const BASEIMAGE *BaseImage,                                     int GrHandle ) ;													// 基?イメ?ジデ??から既存のグラフィックハンドルに画像デ??を?送する
extern	int			ReCreateGraphFromRectBaseImage( const BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, int GrHandle ) ;													// 基?イメ?ジデ??の指定の領域を使って既存のグラフィックハンドルに画像デ??を?送する
extern	int			CreateDivGraphFromBaseImage(          BASEIMAGE *BaseImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;								// 基?イメ?ジデ??から分割グラフィックハンドルを作成する
extern	int			ReloadGraph(					const TCHAR *FileName, int GrHandle, int ReverseFlag = FALSE ) ;																	// 画像フ?イルからグラフィックハンドルへ画像デ??を?送する
extern	int			ReloadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, const int *HandleBuf, int ReverseFlag = FALSE ) ;		// 画像フ?イルからグラフィックハンドルたちへ画像デ??を分割?送する
extern	int			ReloadReverseGraph(				const TCHAR *FileName, int GrHandle ) ;																								// ReloadGraph の画像反?処理追加版
extern	int			ReloadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, const int *HandleBuf ) ;								// ReloadDivGraph の画像反?処理追加版

// グラフィックハンドル作成時設定係関数
extern	int			SetGraphColorBitDepth(						int ColorBitDepth ) ;							// SetCreateGraphColorBitDepth の旧名称
extern 	int			GetGraphColorBitDepth(						void ) ;										// GetCreateGraphColorBitDepth の旧名称
extern	int			SetCreateGraphColorBitDepth(				int BitDepth ) ;								// 作成するグラフィックハンドルの色?度を設定する
extern	int			GetCreateGraphColorBitDepth(				void ) ;										// 作成するグラフィックハンドルの色?度を取得する
extern	int			SetCreateGraphChannelBitDepth(				int BitDepth ) ;								// 作成するグラフィックハンドルの１?ャンネル辺りのビット?度を設定する
extern	int			GetCreateGraphChannelBitDepth(				void ) ;										// 作成するグラフィックハンドルの１?ャンネル辺りのビット?度を取得する
extern	int			SetDrawValidGraphCreateFlag(				int Flag ) ;									// SetDrawScreen に引数として渡せる( ?画対象として使用できる )グラフィックハンドルを作成するかどうかを設定する( TRUE:?画可?グラフィックハンドルを作成する  FLASE:通常のグラフィックハンドルを作成する( デフォルト ) )
extern	int			GetDrawValidGraphCreateFlag(				void ) ;										// SetDrawScreen に引数として渡せる( ?画対象として使用できる )グラフィックハンドルを作成するかどうかを設定を取得する
extern	int			SetDrawValidFlagOf3DGraph(					int Flag ) ;									// SetDrawValidGraphCreateFlag の旧名称
extern	int			SetLeftUpColorIsTransColorFlag(				int Flag ) ;									// 画像フ?イルからグラフィックハンドルを作成する際に画像左上の色を透過色として扱うかどうかを設定する( TRUE:透過色として扱う ?FALSE:透過色として扱わない( デフォルト ) )
extern	int			SetUseBlendGraphCreateFlag(					int Flag ) ;									// ブレンド処理用画像を作成するかどうか( 要は画像の赤成分をα成分として扱うかどうか )の設定を行う( TRUE:ブレンド画像として読み込む  FALSE:通常画像として読み込む( デフォルト ) )
extern	int			GetUseBlendGraphCreateFlag(					void ) ;										// ブレンド処理用画像を作成するかどうか( 要は画像の赤成分をα成分として扱うかどうか )の設定を取得する
extern	int			SetUseAlphaTestGraphCreateFlag(				int Flag ) ;									// アルフ?テストを使用するグラフィックハンドルを作成するかどうかを設定する( TRUE:アルフ?テストを使用する( デフォルト )  FALSE:アルフ?テストを使用しない )
extern	int			GetUseAlphaTestGraphCreateFlag(				void ) ;										// アルフ?テストを使用するグラフィックハンドルを作成するかどうかを取得する
extern	int			SetUseAlphaTestFlag(						int Flag ) ;									// SetUseAlphaTestGraphCreateFlag の旧名称
extern	int			GetUseAlphaTestFlag(						void ) ;										// GetUseAlphaTestGraphCreateFlag の旧名称
extern	int			SetCubeMapTextureCreateFlag(				int Flag ) ;									// キュ?ブ?ップテクス?ャを作成するかどうかのフラグを設定する
extern	int			GetCubeMapTextureCreateFlag(				void ) ;										// キュ?ブ?ップテクス?ャを作成するかどうかのフラグを取得する
extern	int			SetUseNoBlendModeParam(						int Flag ) ;									// SetDrawBlendMode 関数の第一引数に DX_BLENDMODE_NOBLEND を代入した際に、デフォルトでは第二引数は内部で２５５を指定したことになるが、その自動２５５化をしないかどうかを設定する( TRUE:しない(第二引数の値が使用される)   FALSE:する(第二引数の値は無視されて 255 が常に使用される)(デフォルト) )α?ャンネル付き画像に対して?画を行う場合のみ意味がある関数
extern	int			SetDrawValidAlphaChannelGraphCreateFlag(	int Flag ) ;									// SetDrawScreen の引数として渡せる( ?画対象として使用できる )α?ャンネル付きグラフィックハンドルを作成するかどうかを設定する( SetDrawValidGraphCreateFlag 関数で?画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )( TRUE:α?ャンネル付き   FALSE:α?ャンネルなし( デフォルト ) )
extern	int			GetDrawValidAlphaChannelGraphCreateFlag(	void ) ;										// SetDrawScreen の引数として渡せる( ?画対象として使用できる )α?ャンネル付きグラフィックハンドルを作成するかどうかを取得する
extern	int			SetDrawValidFloatTypeGraphCreateFlag(		int Flag ) ;									// SetDrawScreen の引数として渡せる( ?画対象として使用できる )ピクセルフォ??ットが浮動小数??のグラフィックハンドルを作成するかどうかを設定する( SetDrawValidGraphCreateFlag 関数で?画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )、グラフィックスデバイスが浮動小数??のピクセルフォ??ットに対応していない場合はグラフィックハンドルの作成に失敗する( TRUE:浮動小数????FALSE:整数?( デフォルト ) )
extern	int			GetDrawValidFloatTypeGraphCreateFlag(		void ) ;										// SetDrawScreen の引数として渡せる( ?画対象として使用できる )ピクセルフォ??ットが浮動小数??のグラフィックハンドルを作成するかどうかを取得する
extern	int			SetDrawValidGraphCreateZBufferFlag(			int Flag ) ;									// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルを作成する際に専用のＺバッフ?も作成するかどうかを設定する( TRUE:専用のＺバッフ?を作成する( デフォルト )  FALSE:専用のＺバッフ?は作成しない )
extern	int			GetDrawValidGraphCreateZBufferFlag(			void ) ;										// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルを作成する際に専用のＺバッフ?も作成するかどうかを取得する
extern	int			SetCreateDrawValidGraphZBufferBitDepth(		int BitDepth ) ;								// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルに適用するＺバッフ?のビット?度を設定する( BitDepth:ビット?度( 指定可?な値は 16, 24, 32 の何れか( SetDrawValidGraphCreateFlag 関数で?画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )
extern	int			GetCreateDrawValidGraphZBufferBitDepth(		void ) ;										// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルに適用するＺバッフ?のビット?度を取得する
extern	int			SetCreateDrawValidGraphChannelNum(			int ChannelNum ) ;								// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルに適用する色の?ャンネル数を設定する( ChannelNum:?ャンネル数( 指定可?な値は 1, 2, 4 の何れか( SetDrawValidGraphCreateFlag 関数で?画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )
extern	int			GetCreateDrawValidGraphChannelNum(			void ) ;										// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルに適用する色の?ャンネル数を取得する
extern	int			SetDrawValidMultiSample(					int Samples, int Quality ) ;					// SetDrawScreen の引数として渡せる( ?画対象として使用できる )グラフィックハンドルに適用する?ル?サンプリング( アン?エイリアシング )設定を行う( Samples:?ル?サンプル処理に使用するドット数( 多いほど重くなります )  Quality:?ル?サンプル処理の品質 )
extern	int			GetMultiSampleQuality(						int Samples ) ;									// 指定の?ル?サンプル数で使用できる最大クオリティ値を取得する( 戻り値が?イナスの場合は引数のサンプル数が使用できないことを示します )
extern	int			SetUseTransColor(							int Flag ) ;									// 透過色??を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseTransColorGraphCreateFlag(			int Flag ) ;									// 透過色??を使用することを前提とした画像デ??の読み込み処理を行うかどうかを設定する( TRUE にすると SetDrawMode( DX_DRAWMODE_BILINEAR ); をした状態で DrawGraphF 等の浮動小数??座標を受け取る関数で小数?以下の値を指定した場合に発生する?画結果の不自然を緩和する効果があります ( デフォルトは FALSE ) )
extern 	int			SetUseGraphAlphaChannel(					int Flag ) ;									// SetUseAlphaChannelGraphCreateFlag の旧名称
extern 	int			GetUseGraphAlphaChannel(					void ) ;										// GetUseAlphaChannelGraphCreateFlag の旧名称
extern 	int			SetUseAlphaChannelGraphCreateFlag(			int Flag ) ;									// α?ャンネル付きグラフィックハンドルを作成するかどうかを設定する( TRUE:α?ャンネル付き   FALSE:α?ャンネル無し )
extern 	int			GetUseAlphaChannelGraphCreateFlag(			void ) ;										// α?ャンネル付きグラフィックハンドルを作成するかどうかを取得する( TRUE:α?ャンネル付き   FALSE:α?ャンネル無し )
extern	int			SetUseNotManageTextureFlag(					int Flag ) ;									// Direct3D の管理テクス?ャ??を使用するグラフィックハンドルを作成するかどうかを設定する( TRUE:管理??を使用する( デフォルト )  FALSE:管理??を使用しない )、管理??を使用するとグラフィックスデバイスのＶＲ?Ｍ容量以上の画像を扱うことができる代わりにシステ?メモリの使用量が増えます
extern	int			GetUseNotManageTextureFlag(					void ) ;										// Direct3D の管理テクス?ャ??を使用するグラフィックハンドルを作成するかどうかを取得する
extern	int			SetTransColor(								int Red, int Green, int Blue ) ;				// 作成するグラフィックハンドルに適用する透過色を設定する( Red,Green,Blue:透過色を光の３原色で?したもの( 各色０?２５５ ) )
extern	int			GetTransColor(								int *Red, int *Green, int *Blue ) ;				// 作成するグラフィックハンドルに適用する透過色を取得する
extern	int			SetUseDivGraphFlag(							int Flag ) ;									// ２のｎ乗ではないサイズの画像を複数のテクス?ャを使用してＶＲ?Ｍの無駄を省くかどうかを設定する( TRUE:複数のテクス?ャを使用する   FALSE:なるべく一枚のテクス?ャで済ます( デフォルト ) )、複数のテクス?ャを使用する場合はＶＲ?Ｍ容量の節約ができる代わりに速度の低下やバイリニアフィル?リング?画時にテクス?ャとテクス?ャの境目が良く見るとわかる等の弊害があります
extern	int			SetUseMaxTextureSize(						int Size ) ;									// 使用するテクス?ャ?の最大サイズを設定する( デフォルトではグラフィックスデバイスが対応している最大テクス?ャ?サイズ、引数に 0 を渡すとデフォルト設定になります )
extern	int			SetUseGraphBaseDataBackup(					int Flag ) ;									// グラフィックハンドルを作成する際に使用した画像デ??のバックアップをして Direct3DDevice のデバイスロスト時に使用するかどうかを設定する( TRUE:バックアップをする( デフォルト )  FALSE:バックアップをしない )、バックアップをしないとメモリの節約になりますが、復帰に?かる時間が長くなり、メモリ上のフ?イルイメ?ジからグラフィックハンドルを作成した場合は自動復帰ができないなどの弊害があります
extern	int			GetUseGraphBaseDataBackup(					void ) ;										// グラフィックハンドルを作成する際に使用した画像デ??のバックアップをして Direct3DDevice のデバイスロスト時に使用するかどうかを取得する
extern	int			SetUseSystemMemGraphCreateFlag(				int Flag ) ;									// ( 現在効果なし )グラフィックハンドルが持つ画像デ??をシステ?メモリ上に作成するかどうかを設定する( TRUE:システ?メモリ上に作成  FALSE:ＶＲ?Ｍ上に作成( デフォルト ) )
extern	int			GetUseSystemMemGraphCreateFlag(				void ) ;										// ( 現在効果なし )グラフィックハンドルが持つ画像デ??をシステ?メモリ上に作成するかどうかを取得する

// 画像情報関係関数
extern	const DWORD* GetFullColorImage(				int GrHandle ) ;																		// 指定のグラフィックハンドルの?ＲＧＢ８イメ?ジを取得する( 現在動画フ?イルをグラフィックハンドルで読み込んだ場合のみ使用可? )

extern	int			GraphLock(						int GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = NULL ) ;	// グラフィックメモリ領域のロック
extern	int			GraphUnLock(					int GrHandle ) ;																		// グラフィックメモリ領域のロック解除

extern	int			SetUseGraphZBuffer(				int GrHandle, int UseFlag, int BitDepth = -1 ) ;										// グラフィックハンドル専用のＺバッフ?を持つかどうかを設定する( GrHandle:対象となるグラフィックハンドル( ?画対象として使用可?なグラフィックハンドルのみ有効 )  UseFlag:専用のＺバッフ?を持つかどうか( TRUE:持つ( デフォルト )  FALSE:持たない )  BitDepth:ビット?度( 16 or 24 or 32 ) )
extern	int			CopyGraphZBufferImage(			int DestGrHandle, int SrcGrHandle ) ;													// グラフィックハンドルのＺバッフ?の状態を別のグラフィックハンドルのＺバッフ?にコピ?する( DestGrHandle も SrcGrHandle もＺバッフ?を持っている?画対象にできるグラフィックハンドルで、サイズが同じであり、且つ?ル?サンプリング( アン?エイリアス )設定が無いことが条件 )

extern	int			SetDeviceLostDeleteGraphFlag(	int GrHandle, int DeleteFlag ) ;														// グラフィックスデバイスのデバイスロスト発生時に指定のグラフィックハンドルを削除するかどうかを設定する( TRUE:デバイスロスト時に削除する  FALSE:デバイスロストが発生しても削除しない )

extern	int			GetGraphSize(					int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// グラフィックハンドルが持つ画像のサイズを得る
extern	int			GetGraphTextureSize(			int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// グラフィックハンドルが持つ一つ目のテクス?ャのサイズを得る
extern	int			GetGraphMipmapCount(			int GrHandle ) ;																		// グラフィックハンドルが持つテクス?ャの?ップ?ップレベル数を取得する
extern	int			GetGraphFilePath(				int GrHandle, TCHAR *FilePathBuffer ) ;													// グラフィックハンドルが画像フ?イルから読み込まれていた場合、その画像のフ?イルパスを取得する

extern	const COLORDATA* GetTexColorData(			int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;				// カラ?デ??を得る
extern	const COLORDATA* GetTexColorData(			const IMAGEFORMATDESC *Format ) ;														// フォ??ットに基づいたカラ?デ??を得る
extern	const COLORDATA* GetTexColorData(			int FormatIndex ) ;																		// 指定のフォ??ットインデックスのカラ?デ??を得る
extern	int			GetMaxGraphTextureSize(			int *SizeX, int *SizeY ) ;																// グラフィックスデバイスが対応している最大テクス?ャサイズを取得する
extern	int			GetValidRestoreShredPoint(		void ) ;																				// グラフィックハンドルの画像を復元する関数が登?されているかどうかを取得する( TRUE:登?されている  FALSE:登?されていない )
extern	int			GetCreateGraphColorData(		COLORDATA *ColorData, IMAGEFORMATDESC *Format ) ;										// これから新たにグラフィックを作成する場合に使用するカラ?情報を取得する

// 画像パレット?作関係関数( ?フトウエア画像のみ使用可? )
extern	int			GetGraphPalette(				int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// グラフィックハンドルのパレットを取得する( ?フトウエアレン?リングモ?ドで、且つパレット画像の場合のみ使用可? )
extern  int			GetGraphOriginalPalette(		int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// グラフィックハンドルの SetGraphPalette で変更する前のパレットを取得する( ?フトウエアレン?リングモ?ドで、且つパレット画像の場合のみ使用可? )
extern	int			SetGraphPalette(				int GrHandle, int ColorIndex, int Color ) ;												// グラフィックハンドルのパレットを変更する( ?フトウエアレン?リングモ?ドで、且つパレット画像の場合のみ使用可? )
extern	int			ResetGraphPalette(				int GrHandle ) ;																		// SetGraphPalette で変更したパレットを全て元に戻す( ?フトウエアレン?リングモ?ドで、且つパレット画像の場合のみ使用可? )

// ???画関数
extern	int			DrawLine(       int x1, int y1, int x2, int y2,                                 int Color, int Thickness = 1 ) ;		// 線を?画する
extern	int			DrawBox(        int x1, int y1, int x2, int y2,                                 int Color, int FillFlag ) ;				// 四角?の?画する
extern	int			DrawFillBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// 中身を塗りつぶす四角?を?画する
extern	int			DrawLineBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// 枠だけの四角?の?画 する
extern	int			DrawCircle(     int x, int y, int r,                                            int Color, int FillFlag = TRUE, int LineThickness = 1 ) ;	// ?を?画する
extern	int			DrawOval(       int x, int y, int rx, int ry,                                   int Color, int FillFlag,        int LineThickness = 1 ) ;	// 楕?を?画する
extern	int			DrawTriangle(   int x1, int y1, int x2, int y2, int x3, int y3,                 int Color, int FillFlag ) ;				// 三角?を?画する
extern	int			DrawQuadrangle( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Color, int FillFlag ) ;				// 四角?を?画する
extern 	int			DrawPixel(      int x, int y,                                                   int Color ) ;							// ?を?画する

extern	int			Paint(			int x, int y, int FillColor, int BoundaryColor = -1 ) ;													// 指定?から境界色があるところまで塗りつぶす(境界色を -1 にすると指定?の色の領域を塗りつぶす)

extern 	int			DrawPixelSet(   const POINTDATA *PointData, int Num ) ;																	// ?の集合を?画する
extern	int			DrawLineSet(    const LINEDATA *LineData,   int Num ) ;																	// 線の集合を?画する

extern	int			DrawPixel3D(    VECTOR Pos,                                                                       int Color ) ;						// ３Ｄの?を?画する
extern	int			DrawLine3D(     VECTOR Pos1, VECTOR Pos2,                                                         int Color ) ;						// ３Ｄの線分を?画する
extern	int			DrawTriangle3D( VECTOR Pos1, VECTOR Pos2, VECTOR Pos3,                                            int Color, int FillFlag ) ;		// ３Ｄの三角?を?画する
extern	int			DrawCube3D(     VECTOR Pos1, VECTOR Pos2,                                        int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの立方体を?画する
extern	int			DrawSphere3D(   VECTOR CenterPos,                float r,            int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの球体を?画する
extern	int			DrawCapsule3D(  VECTOR Pos1, VECTOR Pos2,        float r,            int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄのカプセルを?画する
extern	int			DrawCone3D(     VECTOR TopPos, VECTOR BottomPos, float r,            int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの?錐を?画する

// 画像?画関数
extern	int			LoadGraphScreen(          int x, int y, const TCHAR *GraphName, int TransFlag ) ;										// 画像フ?イルを読みこんで画面に?画する

extern	int			DrawGraph(                int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// 画像の等??画
extern	int			DrawExtendGraph(          int x1, int y1, int x2, int y2,                                               int GrHandle, int TransFlag ) ;										// 画像の拡大?画
extern	int			DrawRotaGraph(            int x, int y,                 double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// 画像の回??画
extern	int			DrawRotaGraph2(           int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// 画像の回??画２( 回?中心指定付き )
extern	int			DrawRotaGraph3(           int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 				// 画像の回??画３( 回?中心指定付き?縦横拡大率別指定版 )
extern	int			DrawModiGraph(            int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int TransFlag ) ;										// 画像の自由変??画
extern	int			DrawTurnGraph(            int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// 画像の左右反??画

extern	int			DrawGraphF(               float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// 画像の?画( 座標指定が float 版 )
extern	int			DrawExtendGraphF(         float x1f, float y1f, float x2f, float y2,                                                int GrHandle, int TransFlag ) ;							// 画像の拡大?画( 座標指定が float 版 )
extern	int			DrawRotaGraphF(           float xf, float yf,                       double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// 画像の回??画( 座標指定が float 版 )
extern	int			DrawRotaGraph2F(          float xf, float yf, float cxf, float cyf, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// 画像の回??画２( 回?中心指定付き )( 座標指定が float 版 )
extern	int			DrawRotaGraph3F(          float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 	// 画像の回??画３( 回?中心指定付き?縦横拡大率別指定版 )( 座標指定が float 版 )
extern	int			DrawModiGraphF(           float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,           int GrHandle, int TransFlag ) ;							// 画像の自由変??画( 座標指定が float 版 )
extern	int			DrawTurnGraphF(           float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// 画像の左右反??画( 座標指定が float 版 )

extern	int			DrawChipMap(              int Sx, int Sy, int XNum, int YNum, const int *MapData, int ChipTypeNum, int MapDataPitch, const int *ChipGrHandle, int TransFlag ) ;																											// ?ップ画像を使った２Ｄ?ップ?画
extern	int			DrawChipMap(              int MapWidth, int MapHeight,        const int *MapData, int ChipTypeNum,                   const int *ChipGrHandle, int TransFlag, int MapDrawPointX, int MapDrawPointY, int MapDrawWidth, int MapDrawHeight, int ScreenX, int ScreenY ) ;	// ?ップ画像を使った２Ｄ?ップ?画
extern	int			DrawTile(                 int x1, int y1, int x2, int y2, int Tx, int Ty, double ExtRate, double Angle, int GrHandle, int TransFlag ) ;																																	// 画像を指定領域に?イル状に?画する

extern	int			DrawRectGraph(            int DestX,  int DestY,                          int SrcX, int SrcY, int    Width, int    Height,                         int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩?部分のみを等??画
extern	int			DrawRectExtendGraph(      int DestX1, int DestY1, int DestX2, int DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                         int GraphHandle, int TransFlag ) ;							// 画像の指定矩?部分のみを拡大?画
extern	int			DrawRectRotaGraph(        int x, int y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle,                                   int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩?部分のみを回??画
extern	int			DrawRectRotaGraph2(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRate,  double Angle,                  int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩?部分のみを回??画２( 回?中心指定付き )
extern	int			DrawRectRotaGraph3(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩?部分のみを回??画３( 回?中心指定付き?縦横拡大率別指定版 )

extern	int			DrawRectGraphF(           float DestX,  float DestY,                              int SrcX, int SrcY, int    Width, int    Height,                           int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩?部分のみを等??画( 座標指定が float 版 )
extern	int			DrawRectExtendGraphF(     float DestX1, float DestY1, float DestX2, float DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                           int GraphHandle, int TransFlag ) ;					// 画像の指定矩?部分のみを拡大?画( 座標指定が float 版 )
extern	int			DrawRectRotaGraphF(       float x, float y, int SrcX, int SrcY, int Width, int Height,                       double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩?部分のみを回??画( 座標指定が float 版 )
extern	int			DrawRectRotaGraph2F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩?部分のみを回??画２( 回?中心指定付き )( 座標指定が float 版 )
extern	int			DrawRectRotaGraph3F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩?部分のみを回??画３( 回?中心指定付き?縦横拡大率別指定版 )( 座標指定が float 版 )

extern	int			DrawBlendGraph(           int x, int y, int GrHandle, int TransFlag,                 int BlendGraph, int BorderParam, int BorderRange ) ;									// ブレンド画像と合成して画像を等??画する
extern	int			DrawBlendGraphPos(        int x, int y, int GrHandle, int TransFlag, int bx, int by, int BlendGraph, int BorderParam, int BorderRange ) ;									// ブレンド画像と合成して画像を等??画する( ブレンド画像の起?座標を指定する引数付き )

extern	int			DrawCircleGauge(          int CenterX, int CenterY, double Percent, int GrHandle, double StartPercent = 0.0 ) ;																				// ?グラフ的な?画を行う( GrHandle の画像の上下左右の?は透過色にしておく必要があります )

extern	int			DrawGraphToZBuffer(       int X, int Y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して画像の等??画
extern	int			DrawTurnGraphToZBuffer(   int x, int y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して画像の左右反??画
extern	int			DrawExtendGraphToZBuffer( int x1, int y1, int x2, int y2,                                               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して画像の拡大?画
extern	int			DrawRotaGraphToZBuffer(   int x, int y, double ExRate, double Angle,                                    int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ;		// Ｚバッフ?に対して画像の回??画
extern	int			DrawRotaGraph2ToZBuffer(  int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ;		// Ｚバッフ?に対して画像の回??画２( 回?中心指定付き )
extern	int			DrawRotaGraph3ToZBuffer(  int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ; 	// Ｚバッフ?に対して画像の回??画３( 回?中心指定付き?縦横拡大率別指定版 )
extern	int			DrawModiGraphToZBuffer(   int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して画像の自由変??画
extern	int			DrawBoxToZBuffer(         int x1, int y1, int x2, int y2,                                               int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して矩?の?画
extern	int			DrawCircleToZBuffer(      int x, int y, int r,                                                          int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッフ?に対して?の?画

extern	int			DrawPolygon(                             const VERTEX    *Vertex, int PolygonNum,                                                                                                    int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// ２Ｄ?リゴンを?画する( Vertex:三角?を?成する頂?配列の先頭アドレス( 頂?の数は?リゴンの数?３ )  PolygonNum:?画する?リゴンの数  GrHandle:使用するグラフィックハンドル  TransFlag:透過色処理を行うかどうか( TRUE:行う  FALSE:行わない )  UVScaling:基?FALSEでOK )
extern	int			DrawPolygon2D(                           const VERTEX2D  *Vertex, int PolygonNum,                                                                                                    int GrHandle, int TransFlag ) ;							// ２Ｄ?リゴンを?画する
extern	int			DrawPolygon3D(                           const VERTEX3D  *Vertex, int PolygonNum,                                                                                                    int GrHandle, int TransFlag ) ;							// ３Ｄ?リゴンを?画する
extern	int			DrawPolygonIndexed2D(                    const VERTEX2D  *Vertex, int VertexNum, const unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// ２Ｄ?リゴンを?画する( 頂?インデックスを使用 )
extern	int			DrawPolygonIndexed3D(                    const VERTEX3D  *Vertex, int VertexNum, const unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// ３Ｄ?リゴンを?画する( 頂?インデックスを使用 )
extern	int			DrawPolygonIndexed3DBase(                const VERTEX_3D *Vertex, int VertexNum, const unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄ?リゴンを?画する( 頂?インデックスを使用 )( 旧バ?ジョン用 )
extern	int			DrawPolygon3DBase(                       const VERTEX_3D *Vertex, int VertexNum,                                                int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄ?リゴンを?画する( 旧バ?ジョン用 )
extern	int			DrawPolygon3D(                           const VERTEX_3D *Vertex, int PolygonNum,                                                                                                    int GrHandle, int TransFlag ) ;							// ３Ｄ?リゴンを?画する( 旧バ?ジョン用 )

extern	int			DrawPolygonBase(                         const VERTEX    *Vertex, int VertexNum,                                                int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// ２Ｄプリ?ティブを?画する
extern	int			DrawPrimitive2D(                         const VERTEX2D  *Vertex, int VertexNum,                                                int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ２Ｄプリ?ティブを?画する
extern	int			DrawPrimitive3D(                         const VERTEX3D  *Vertex, int VertexNum,                                                int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed2D(                  const VERTEX2D  *Vertex, int VertexNum, const unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ２Ｄプリ?ティブを?画する(頂?インデックス使用)
extern	int			DrawPrimitiveIndexed3D(                  const VERTEX3D  *Vertex, int VertexNum, const unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄプリ?ティブを?画する(頂?インデックス使用)

extern	int			DrawPolygon3D_UseVertexBuffer(           int VertexBufHandle,                                                                                                                                                               int GrHandle, int TransFlag ) ;		// 頂?バッフ?を使用して３Ｄ?リゴンを?画する
extern	int			DrawPrimitive3D_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                                                                                     int GrHandle, int TransFlag ) ;		// 頂?バッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPrimitive3D_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                 int StartVertex, int UseVertexNum,                                  int GrHandle, int TransFlag ) ;		// 頂?バッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPolygonIndexed3D_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle,                                                                                                                                           int GrHandle, int TransFlag ) ;		// 頂?バッフ?とインデックスバッフ?を使用して３Ｄ?リゴンを?画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                                                                                     int GrHandle, int TransFlag ) ;		// 頂?バッフ?とインデックスバッフ?を使用して３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum, int GrHandle, int TransFlag ) ;		// 頂?バッフ?とインデックスバッフ?を使用して３Ｄプリ?ティブを?画する

extern	int			DrawGraph3D(                             float x, float y, float z,                                                                     int GrHandle, int TransFlag ) ;								// 画像の３Ｄ?画
extern	int			DrawExtendGraph3D(                       float x, float y, float z, double ExRateX, double ExRateY,                                     int GrHandle, int TransFlag ) ;								// 画像の拡大３Ｄ?画
extern	int			DrawRotaGraph3D(                         float x, float y, float z, double ExRate, double Angle,                                        int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// 画像の回?３Ｄ?画
extern	int			DrawRota2Graph3D(                        float x, float y, float z, float cx, float cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// 画像の回?３Ｄ?画(回?中心指定?)
extern	int			DrawModiBillboard3D(                     VECTOR Pos, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,    int GrHandle, int TransFlag ) ;								// 画像の自由変?３Ｄ?画
extern	int			DrawBillboard3D(                         VECTOR Pos, float cx, float cy, float Size, float Angle,                                       int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// ３Ｄ空間上に画像を?画


// ?画設定関係関数
extern	int			SetDrawMode(						int DrawMode ) ;												// ?画モ?ドを設定する
extern	int			GetDrawMode(						void ) ;														// ?画モ?ドを取得する
extern	int			SetDrawBlendMode(					int BlendMode, int BlendParam ) ;								// ?画ブレンドモ?ドを設定する
extern	int			GetDrawBlendMode(					int *BlendMode, int *BlendParam ) ;								// ?画ブレンドモ?ドを取得する
extern	int			SetDrawAlphaTest(					int TestMode, int TestParam ) ;									// ?画時のアルフ?テストの設定を行う( TestMode:テストモ?ド( DX_CMP_GREATER等 -1でデフォルト動作に戻す )  TestParam:?画アルフ?値との比較に使用する値( 0?255 ) )
extern	int			SetBlendGraph(						int BlendGraph, int BorderParam, int BorderRange ) ;			// ( SetBlendGraphParam の BlendType = DX_BLENDGRAPHTYPE_WIPE の処理を行う旧関数 )?画処理時に?画する画像とブレンドするα?ャンネル付き画像をセットする( BlendGraph を -1 でブレンド??を無効 )
extern	int			SetBlendGraphParam(					int BlendGraph, int BlendType, ... ) ;							// ?画処理時に?画する画像とブレンドする画像のブレンド設定を行う、BlendGraph を -1 にすれば設定を解除、その場合 BlendType とその後ろのパラメ??は無視される
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_NORMAL, int Ratio = ( 0( ブレンド率０％ )?255( ブレンド率１００％ ) ) ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_WIPE, int BorderParam, int BorderRange ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_ALPHA ) ;
extern	int			SetBlendGraphPosition(				int x, int y ) ;												// ブレンド画像の起?座標をセットする
extern	int			SetDrawBright(						int RedBright, int GreenBright, int BlueBright ) ;				// ?画輝度を設定する
extern	int			GetDrawBright(						int *Red, int *Green, int *Blue ) ;								// ?画輝度を取得する
extern	int			SetIgnoreDrawGraphColor(			int EnableFlag ) ;												// ?画する画像のＲＧＢ成分を無視するかどうかを指定する( EnableFlag:この??を使うかどうか( TRUE:使う  FALSE:使わない( デフォルト ) ) )
extern	int			SetMaxAnisotropy(					int MaxAnisotropy ) ;											// 最大異方性値を設定する

extern	int			SetUseZBufferFlag(					int Flag ) ;													// Ｚバッフ?を使用するかどうかを設定する( ２Ｄと３Ｄ?画に影響 )( TRUE:Ｚバッフ?を使用する  FALSE:Ｚバッフ?を使用しない( デフォルト ) )
extern	int			SetWriteZBufferFlag(				int Flag ) ;													// Ｚバッフ?に書き込みを行うかどうかを設定する( ２Ｄと３Ｄ?画に影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )
extern	int			SetZBufferCmpType(					int CmpType /* DX_CMP_NEVER 等 */ ) ;							// Ｚバッフ?のＺ値と書き込むＺ値との比較モ?ドを設定する( ２Ｄと３Ｄ?画に影響 )( CmpType:DX_CMP_NEVER等( デフォルト:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias(							int Bias ) ;													// 書き込むＺ値のバイアスを設定する( ２Ｄと３Ｄ?画に影響 )( Bias:バイアス値( デフォルト:0 ) )
extern	int			SetUseZBuffer3D(					int Flag ) ;													// Ｚバッフ?を使用するかどうかを設定する( ３Ｄ?画のみに影響 )( TRUE:Ｚバッフ?を使用する  FALSE:Ｚバッフ?を使用しない( デフォルト ) )
extern	int			SetWriteZBuffer3D(					int Flag ) ;													// Ｚバッフ?に書き込みを行うかどうかを設定する( ３Ｄ?画のみに影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )
extern	int			SetZBufferCmpType3D(				int CmpType /* DX_CMP_NEVER 等 */ ) ;							// Ｚバッフ?のＺ値と書き込むＺ値との比較モ?ドを設定する( ３Ｄ?画のみに影響 )( CmpType:DX_CMP_NEVER等( デフォルト:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias3D(							int Bias ) ;													// 書き込むＺ値のバイアスを設定する( ３Ｄ?画のみに影響 )( Bias:バイアス値( デフォルト:0 ) )
extern	int			SetDrawZ(							float Z ) ;														// ２Ｄ?画でＺバッフ?に書き込むＺ値を設定する( Z:書き込むＺ値( デフォルト:0.2f ) )

extern	int			SetDrawArea(						int x1, int y1, int x2, int y2 ) ;								// ?画可?領域の設定する
extern	int			GetDrawArea(						RECT *Rect ) ;													// ?画可?領域を取得する
extern	int			SetDrawAreaFull(					void ) ;														// ?画可?領域を?画対象画面全体にする
extern	int			SetDraw3DScale(						float Scale ) ;													// ３Ｄ?画の拡大率を設定する

extern	int			SetRestoreShredPoint(				void (* ShredPoint )( void ) ) ;								// SetRestoreGraphCallback の旧名
extern	int			SetRestoreGraphCallback(			void (* Callback )( void ) ) ;									// グラフィックハンドル復元関数を登?する
extern	int			RunRestoreShred(					void ) ;														// グラフィック復元関数を実行する
extern	int			SetGraphicsDeviceRestoreCallbackFunction( void (* Callback )( void *Data ), void *CallbackData ) ;	// グラフィックスデバイスがロストから復帰した際に呼ばれるコ?ルバック関数を設定する
extern	int			SetGraphicsDeviceLostCallbackFunction(    void (* Callback )( void *Data ), void *CallbackData ) ;	// グラフィックスデバイスがロストから復帰する前に呼ばれるコ?ルバック関数を設定する

extern	int			SetTransformToWorld(				const MATRIX *Matrix ) ;										// ロ?カル座標からワ?ルド座標に変換するための行列を設定する
extern	int			GetTransformToWorldMatrix(			      MATRIX *MatBuf ) ;										// ロ?カル座標からワ?ルド座標に変換するための行列を取得する
extern	int			SetTransformToView(					const MATRIX *Matrix ) ;										// ワ?ルド座標からビュ?座標に変換するための行列を設定する
extern	int			GetTransformToViewMatrix(			      MATRIX *MatBuf ) ;										// ワ?ルド座標からビュ?座標に変換するための行列を取得する
extern	int			SetTransformToProjection(			const MATRIX *Matrix ) ;										// ビュ?座標からプロジェクション座標に変換するための行列を設定する
extern	int			GetTransformToProjectionMatrix(		      MATRIX *MatBuf ) ;										// ビュ?座標からプロジェクション座標に変換するための行列を取得する
extern	int			SetTransformToViewport(				const MATRIX *Matrix ) ;										// ビュ???ト行列を設定する
extern	int			GetTransformToViewportMatrix(		      MATRIX *MatBuf ) ;										// ビュ???ト行列を取得する
extern	int			GetTransformToAPIViewportMatrix(	      MATRIX *MatBuf ) ;										// Direct3Dで自動適用されるビュ???ト行列を取得する
extern	int			SetDefTransformMatrix(				void ) ;														// デフォルトの変換行列を設定する
extern	int			GetTransformPosition(				VECTOR *LocalPos, float *x, float *y ) ;						// ロ?カル座標からスクリ?ン座標を取得する
extern	float		GetBillboardPixelSize(				VECTOR WorldPos, float WorldSize ) ;							// ワ?ルド空間上のビル??ドのサイズからスクリ?ンに投影した場合のピクセル単位のサイズを取得する
extern	VECTOR		ConvWorldPosToViewPos(				VECTOR WorldPos ) ;												// ワ?ルド座標をビュ?座標に変換する
extern	VECTOR		ConvWorldPosToScreenPos(			VECTOR WorldPos ) ;												// ワ?ルド座標をスクリ?ン座標に変換する
extern	FLOAT4		ConvWorldPosToScreenPosPlusW(		VECTOR WorldPos ) ;												// ワ?ルド座標をスクリ?ン座標に変換する、最後のＸＹＺ座標をＷで割る前の値を得る
extern	VECTOR		ConvScreenPosToWorldPos(			VECTOR ScreenPos ) ;											// スクリ?ン座標をワ?ルド座標に変換する
extern	VECTOR		ConvScreenPosToWorldPos_ZLinear(	VECTOR ScreenPos ) ;											// スクリ?ン座標をワ?ルド座標に変換する( Z座標が線? )

extern	int			SetUseCullingFlag(					int Flag ) ;													// SetUseBackCulling の旧名称
extern	int			SetUseBackCulling(					int Flag /* DX_CULLING_LEFT 等 */ ) ;							// ?リゴンカリングモ?ドを設定する

extern	int			SetTextureAddressMode(				int Mode /* DX_TEXADDRESS_WRAP 等 */ , int Stage = -1 ) ;		// テクス?ャアドレスモ?ドを設定する
extern	int			SetTextureAddressModeUV(			int ModeU, int ModeV, int Stage = -1 ) ;						// テクス?ャアドレスモ?ドを設定する( U と V を別々に設定する )
extern	int			SetTextureAddressTransform(			float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// テクス?ャ座標変換パラメ??を設定する
extern	int			SetTextureAddressTransformMatrix(	MATRIX Matrix ) ;												// テクス?ャ座標変換行列を設定する
extern	int			ResetTextureAddressTransform(		void ) ;														// テクス?ャ座標変換設定をリセットする

extern	int			SetFogEnable(						int Flag ) ;													// フォグを有効にするかどうかを設定する( TRUE:有効  FALSE:無効 )
extern	int			SetFogMode(							int Mode /* DX_FOGMODE_NONE 等 */ ) ;							// フォグモ?ドを設定する
extern	int			SetFogColor(						int r, int g, int b ) ;											// フォグカラ?を設定する
extern	int			SetFogStartEnd(						float start, float end ) ;										// フォグが始まる距離と終了する距離を設定する( 0.0f ? 1.0f )
extern	int			SetFogDensity(						float density ) ;												// フォグの密度を設定する( 0.0f ? 1.0f )


// 画面関係関数
extern	int				GetPixel(									int x, int y ) ;																// 指定座標の色を取得する
extern	int				GetDrawScreenGraph(							                             int x1, int y1, int x2, int y2,                       int GrHandle, int UseClientFlag = TRUE ) ;	// ?画先の画面から指定領域の画像情報をグラフィックハンドルに?送する
extern	int				BltDrawValidGraph(							int TargetDrawValidGrHandle, int x1, int y1, int x2, int y2, int DestX, int DestY, int DestGrHandle ) ;							// SetDrawScreen で?画対象にできるグラフィックハンドルから指定領域の画像情報を別のグラフィックハンドルに?送する
extern	int				ScreenFlip(									void ) ;																		// 裏画面と?画面の内容を交換する
extern 	int				ScreenCopy(									void ) ;																		// 裏画面の内容を?画面に?送する
extern	int				WaitVSync(									int SyncNum ) ;																	// 垂直同期信号を待つ
extern	int				ClearDrawScreen(					        const RECT *ClearRect = NULL ) ;												// 画面をクリアする
extern	int				ClearDrawScreenZBuffer(						const RECT *ClearRect = NULL ) ;												// 画面のＺバッフ?をクリアする
extern	int				ClsDrawScreen(								void ) ;																		// ClearDrawScreenの旧名称
extern	int				SetDrawScreen(								int DrawScreen ) ;																// ?画先画面を設定する( MakeScreen で作成したグラフィックハンドルも渡すことができます )
extern	int				GetDrawScreen(								void ) ;																		// ?画先画面を取得する
extern	int				GetActiveGraph(								void ) ;																		// GetDrawScreen の旧名称
extern	int				SetDrawZBuffer(								int DrawScreen ) ;																// ?画先Ｚバッフ?のセット( DrawScreen 付属のＺバッフ?を?画先Ｚバッフ?にする、DrawScreen を -1 にするとデフォルトの?画先Ｚバッフ?に戻る )
#ifdef __WINDOWS__
extern	int				BltBackScreenToWindow(						HWND Window, int ClientX, int ClientY ) ;										// 裏画面の内容を指定のウインドウに?送する
extern	int				BltRectBackScreenToWindow(					HWND Window, RECT BackScreenRect, RECT WindowClientRect ) ;						// 裏画面の指定の領域をウインドウのクライアント領域の指定の領域に?送する
#endif // __WINDOWS__
extern	int				SetGraphMode(								int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int RefreshRate = 60 ) ;	// 画面モ?ドを設定する
extern	int				SetEmulation320x240(						int Flag ) ;																	// ６４０ｘ４８０の画面で３２０ｘ２４０の画面解像度にするかどうかを設定する、６４０ｘ４８０以外の解像度では無効( TRUE:有効  FALSE:無効 )
extern	int				SetZBufferSize(								int ZBufferSizeX, int ZBufferSizeY ) ;											// 画面用のＺバッフ?のサイズを設定する
extern	int				SetZBufferBitDepth(							int BitDepth ) ;																// 画面用のＺバッフ?のビット?度を設定する( 16 or 24 or 32 )
extern	int				SetWaitVSyncFlag(							int Flag ) ;																	// ScreenFlip 実行時にＶＳＹＮＣ待ちをするかどうかを設定する
extern	int				GetWaitVSyncFlag(							void ) ;																		// ScreenFlip 実行時にＶＳＹＮＣ待ちをするかどうかを取得する
extern	int				SetFullSceneAntiAliasingMode(				int Samples, int Quality ) ;													// 画面のフルスクリ?ンアン?エイリアスモ?ドの設定を行う( DxLib_Init の前でのみ使用可? )
extern	int				SetGraphDisplayArea(						int x1, int y1, int x2, int y2 ) ;												// ScreenFlip 時に?画面全体に?送する裏画面の領域を設定する( DxLib_Init の前でのみ使用可? )
extern	int				SetChangeScreenModeGraphicsSystemResetFlag(	int Flag ) ;																	// 画面モ?ド変更時( とウインドウモ?ド変更時 )にグラフィックスシステ?の設定やグラフィックハンドルをリセットするかどうかを設定する( TRUE:リセットする( デフォルト )  FALSE:リセットしない )
extern	int				GetScreenState(								int *SizeX, int *SizeY, int *ColorBitDepth ) ;									// 現在の画面の解像度とカラ?ビット数を得る 
extern	int				GetDrawScreenSize(							int *XBuf, int *YBuf ) ;														// ?画先のサイズを取得する
extern	int				GetScreenBitDepth(							void ) ;																		// 画面のカラ?ビット数を取得する
extern	int				GetColorBitDepth(							void ) ;																		// GetScreenBitDepth の旧名称
extern	int				GetChangeDisplayFlag(						void ) ;																		// 画面モ?ドが変更されているかどうかを取得する
extern	int				GetVideoMemorySize(							int *AllSize, int *FreeSize ) ;													// ( 現在正常に動作しません )ビデオメモリの容量を得る
extern	int				GetRefreshRate(								void ) ;																		// 現在の画面のリフレッシュレ?トを取得する
extern	int				GetDisplayModeNum(							void ) ;																		// 変更可?なディスプレイモ?ドの数を取得する
extern	DISPLAYMODEDATA	GetDisplayMode(								int ModeIndex ) ;																// 変更可?なディスプレイモ?ドの情報を取得する( ModeIndex は 0 ? GetDisplayModeNum の戻り値-1 )
extern	const COLORDATA* GetDispColorData(							void ) ;																		// ディスプレイのカラ?デ??アドレスを取得する
extern	int				GetMultiDrawScreenNum(						void ) ;																		// 同時に?画を行うことができる画面の数を取得する
extern	int				SetDisplayRefreshRate(						int RefreshRate ) ;																// ( 現在効果なし )フルスクリ?ン時の画面のリフレッシュレ?トを変更する

// その他設定関係関数
extern	int			SetUseNormalDrawShader(						int Flag ) ;									// 通常?画にプログラ?ブルシェ???を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseSoftwareRenderModeFlag(				int Flag ) ;									// ?フトウエアレン?リングモ?ドを使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない( デフォルト ) )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetNotUse3DFlag(							int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )３Ｄ??を使わないかどうかを設定する
extern	int			SetUse3DFlag(								int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )３Ｄ??を使うかどうかを設定する
extern	int			GetUse3DFlag(								void ) ;										// ?画に３Ｄ??を使うかどうかを取得する
extern	int			SetScreenMemToVramFlag(						int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )画面のピクセルデ??をＶＲ?Ｍに置くかどうかを設定する
extern	int			GetScreenMemToSystemMemFlag(				void ) ;										// 画面のピクセルデ??がシステ?メモリ上に存在するかを取得する

extern	int			SetWindowDrawRect(							const RECT *DrawRect ) ;						// 通常使用しない
extern	int			RestoreGraphSystem(							void ) ;										// ＤＸライブラリのグラフィックス処理関連の復帰処理を行う
extern	int			SetAeroDisableFlag(							int Flag ) ;									// Vista,7 の Windows Aero を無効にするかどうかを設定する( TRUE:無効にする( デフォルト )  FALSE:有効にする )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetUseDirect3D9Ex(							int Flag ) ;									// Vista以?の環境で Direct3D9Ex を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetUseHardwareVertexProcessing(				int Flag ) ;									// ハ?ドウエアの頂?演算処理??を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetUsePixelLighting(						int Flag ) ;									// ピクセル単位でライティングを行うかどうかを設定する、要 ShaderModel 3.0( TRUE:ピクセル単位のライティングを行う  FALSE:頂?単位のライティングを行う( デフォルト ) )
extern	int			SetMultiThreadFlag(							int Flag ) ;									// DirectDraw や Direct3D の協調レベルを?ル?スレッド対応にするかどうかをセットする( TRUE:?ル?スレッド対応にする  FALSE:?ル?スレッド対応にしない( デフォルト ) )
extern	int			SetUseDirectDrawDeviceIndex(				int Index ) ;									// 使用する DirectDraw デバイスのインデックスを設定する
extern	int			SetUseOldDrawModiGraphCodeFlag(				int Flag ) ;									// 古いバ?ジョンの DrawModiGraph 関数のコ?ドを使用するかどうかを設定する
extern	int			SetUseVramFlag(								int Flag ) ;									// ( 現在効果なし )ＶＲ?Ｍを使用するかのフラグをセットする
extern	int			GetUseVramFlag(								void ) ;										// ( 現在効果なし )２Ｄグラフィックサ?フェス作成時にシステ?メモリ?を使用するかのフラグ取得
extern	int			SetBasicBlendFlag(							int Flag ) ;									// ( 現在効果なし )簡略化ブレンド処理を行うか否かのフラグをセットする
extern	int			SetUseBasicGraphDraw3DDeviceMethodFlag(		int Flag ) ;									// ( 現在効果なし )単純??の?画に３Ｄデバイスの??を使用するかどうかを設定する
#ifdef __WINDOWS__
extern	int			SetUseDirectDrawFlag(						int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )DirectDrawを使用するかどうかを設定する
extern	int			SetUseGDIFlag(								int Flag ) ;									// GDI?画を使用するかどうかを設定する
extern	int			GetUseGDIFlag(								void ) ;										// GDI?画を使用するかどうかを取得する
extern	int			SetDDrawUseGuid(							const GUID *Guid ) ;							// DirectDrawが使用するGUIDを設定する
extern	const void*	GetUseDDrawObj(								void ) ;										// 現在使用しているDirectDrawオブジェクトのアドレスを取得する( 戻り値を IDirectDraw7 * にキャストして下さい )
extern	const GUID*	GetDirectDrawDeviceGUID(					int Number ) ;									// 有効な DirectDraw デバイスの GUID を取得する
extern	int			GetDirectDrawDeviceDescription(				int Number, char *StringBuffer ) ;				// 有効な DirectDraw デバイスの名前を取得する
extern	int			GetDirectDrawDeviceNum(						void ) ;										// 有効な DirectDraw デバイスの数を取得する
extern	const DX_DIRECT3DDEVICE9*  GetUseDirect3DDevice9(				void ) ;								// 使用中のDirect3DDevice9オブジェクトを取得する
extern	const DX_DIRECT3DSURFACE9* GetUseDirect3D9BackBufferSurface(	void ) ;								// 使用中のバックバッフ?のDirect3DSurface9オブジェクトを取得する
#endif // __WINDOWS__
extern	int			RefreshDxLibDirect3DSetting(				void ) ;										// ＤＸライブラリが行ったDirect3Dの設定を再度行う( 特殊用途 )
extern	int			RenderVertex(								void ) ;										// 頂?バッフ?に溜まった頂?デ??を?画する( 特殊用途 )

#ifndef DX_NON_SAVEFUNCTION

// ?画先画面保存関数
// Jpeg_Quality         = 0:低画質?100:高画質
// Png_CompressionLevel = 0:無圧縮?  9:最高圧縮
extern	int			SaveDrawScreen(       int x1, int y1, int x2, int y2, const TCHAR *FileName, int SaveType = DX_IMAGESAVETYPE_BMP , int Jpeg_Quality = 80 , int Jpeg_Sample2x1 = TRUE , int Png_CompressionLevel = -1 ) ;		// 現在?画対象になっている画面をフ?イルで保存する
extern	int			SaveDrawScreenToBMP(  int x1, int y1, int x2, int y2, const TCHAR *FileName ) ;																																	// 現在?画対象になっている画面をＢＭＰ?式で保存する
extern	int			SaveDrawScreenToJPEG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int Quality = 80 , int Sample2x1 = TRUE ) ;																						// 現在?画対象になっている画面をＪＰＥＧ?式で保存する Quality = 画質、値が大きいほど低圧縮高画質,0?100 
extern	int			SaveDrawScreenToPNG(  int x1, int y1, int x2, int y2, const TCHAR *FileName, int CompressionLevel = -1 ) ;																										// 現在?画対象になっている画面をＰＮＧ?式で保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0?9

#endif // DX_NON_SAVEFUNCTION

// 頂?バッフ?関係関数
extern	int			CreateVertexBuffer(		int VertexNum, int VertexType /* DX_VERTEX_TYPE_NORMAL_3D 等 */ ) ;						// 頂?バッフ?を作成する( -1:エラ?  0以上:頂?バッフ?ハンドル )
extern	int			DeleteVertexBuffer(		int VertexBufHandle ) ;																	// 頂?バッフ?を削除する
extern	int			InitVertexBuffer(		void ) ;																				// すべての頂?バッフ?を削除する
extern	int			SetVertexBufferData(	int SetIndex, const void *VertexData, int VertexNum, int VertexBufHandle ) ;			// 頂?バッフ?に頂?デ??を?送する
extern	int			CreateIndexBuffer(		int IndexNum, int IndexType /* DX_INDEX_TYPE_16BIT 等 */  ) ;							// インデックスバッフ?を作成する( -1:エラ??0以上：インデックスバッフ?ハンドル )
extern	int			DeleteIndexBuffer(		int IndexBufHandle ) ;																	// インデックスバッフ?を削除する
extern	int			InitIndexBuffer(		void ) ;																				// すべてのインデックスバッフ?を削除する
extern	int			SetIndexBufferData(		int SetIndex, const void *IndexData, int IndexNum, int IndexBufHandle ) ;				// インデックスバッフ?にインデックスデ??を?送する
extern	int			GetMaxPrimitiveCount(	void ) ;																				// グラフィックスデバイスが対応している一度に?画できるプリ?ティブの最大数を取得する
extern	int			GetMaxVertexIndex(		void ) ;																				// グラフィックスデバイスが対応している一度に使用することのできる最大頂?数を取得する

// シェ???関係関数
extern	int			GetValidShaderVersion(		void ) ;												// 使用できるシェ???のバ?ジョンを取得する( 0=使えない  200=シェ???モデル２．０が使用可?  300=シェ???モデル３．０が使用可? )

extern	int			LoadVertexShader(			const TCHAR *FileName ) ;								// 頂?シェ???バイナリをフ?イルから読み込み頂?シェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadPixelShader(			const TCHAR *FileName ) ;								// ピクセルシェ???バイナリをフ?イルから読み込みピクセルシェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadVertexShaderFromMem(	const void *ImageAddress, int ImageSize ) ;				// メモリに読み込まれた頂?シェ???バイナリから頂?シェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			LoadPixelShaderFromMem(		const void *ImageAddress, int ImageSize ) ;				// メモリに読み込まれたピクセルシェ???バイナリからピクセルシェ???ハンドルを作成する( 戻り値 -1:エラ?  -1以外:シェ???ハンドル )
extern	int			DeleteShader(				int ShaderHandle ) ;									// シェ???ハンドルの削除( 頂?シェ???・ピクセルシェ???共通 )
extern	int			InitShader(					void ) ;												// シェ???ハンドルを全て削除する( 頂?シェ???ハンドル・ピクセルシェ???ハンドルどちらもすべて削除 )

extern	int			GetConstIndexToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ定数が使用するシェ???定数の番号を取得する
extern	int			GetConstCountToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ定数が使用するシェ???定数の数を取得する
extern	const FLOAT4 *GetConstDefaultParamFToShader( const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ浮動小数?数定数のデフォルトパラメ??が格?されているメモリアドレスを取得する
extern	int			SetVSConstSF(         int ConstantIndex,       float  Param ) ;						// 頂?シェ???の float ?定数を設定する
extern	int			SetVSConstF(          int ConstantIndex,       FLOAT4 Param ) ;						// 頂?シェ???の float ?定数を設定する
extern	int			SetVSConstFMtx(       int ConstantIndex,       MATRIX Param ) ;						// 頂?シェ???の float ?定数に行列を設定する
extern	int			SetVSConstFMtxT(      int ConstantIndex,       MATRIX Param ) ;						// 頂?シェ???の float ?定数に?置した行列を設定する
extern	int			SetVSConstSI(         int ConstantIndex,       int    Param ) ;						// 頂?シェ???の int   ?定数を設定する
extern	int			SetVSConstI(          int ConstantIndex,       INT4   Param ) ;						// 頂?シェ???の int   ?定数を設定する
extern	int			SetVSConstB(          int ConstantIndex,       BOOL   Param ) ;						// 頂?シェ???の BOOL  ?定数を設定する
extern	int			SetVSConstSFArray(    int ConstantIndex, const float  *ParamArray, int ParamNum ) ;	// 頂?シェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFArray(     int ConstantIndex, const FLOAT4 *ParamArray, int ParamNum ) ;	// 頂?シェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFMtxArray(  int ConstantIndex, const MATRIX *ParamArray, int ParamNum ) ;	// 頂?シェ???の float ?定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFMtxTArray( int ConstantIndex, const MATRIX *ParamArray, int ParamNum ) ;	// 頂?シェ???の float ?定数に?置した行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstSIArray(    int ConstantIndex, const int    *ParamArray, int ParamNum ) ;	// 頂?シェ???の int   ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstIArray(     int ConstantIndex, const INT4   *ParamArray, int ParamNum ) ;	// 頂?シェ???の int   ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstBArray(     int ConstantIndex, const BOOL   *ParamArray, int ParamNum ) ;	// 頂?シェ???の BOOL  ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			ResetVSConstF(        int ConstantIndex, int ParamNum ) ;							// 頂?シェ???の float ?定数の設定をリセットする
extern	int			ResetVSConstI(        int ConstantIndex, int ParamNum ) ;							// 頂?シェ???の int   ?定数の設定をリセットする
extern	int			ResetVSConstB(        int ConstantIndex, int ParamNum ) ;							// 頂?シェ???の BOOL  ?定数の設定をリセットする

extern	int			SetPSConstSF(         int ConstantIndex,       float  Param ) ;						// ピクセルシェ???の float ?定数を設定する
extern	int			SetPSConstF(          int ConstantIndex,       FLOAT4 Param ) ;						// ピクセルシェ???の float ?定数を設定する
extern	int			SetPSConstFMtx(       int ConstantIndex,       MATRIX Param ) ;						// ピクセルシェ???の float ?定数に行列を設定する
extern	int			SetPSConstFMtxT(      int ConstantIndex,       MATRIX Param ) ;						// ピクセルシェ???の float ?定数に?置した行列を設定する
extern	int			SetPSConstSI(         int ConstantIndex,       int    Param ) ;						// ピクセルシェ???の int   ?定数を設定する
extern	int			SetPSConstI(          int ConstantIndex,       INT4   Param ) ;						// ピクセルシェ???の int   ?定数を設定する
extern	int			SetPSConstB(          int ConstantIndex,       BOOL   Param ) ;						// ピクセルシェ???の BOOL  ?定数を設定する
extern	int			SetPSConstSFArray(    int ConstantIndex, const float  *ParamArray, int ParamNum ) ;	// ピクセルシェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFArray(     int ConstantIndex, const FLOAT4 *ParamArray, int ParamNum ) ;	// ピクセルシェ???の float ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFMtxArray(  int ConstantIndex, const MATRIX *ParamArray, int ParamNum ) ;	// ピクセルシェ???の float ?定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFMtxTArray( int ConstantIndex, const MATRIX *ParamArray, int ParamNum ) ;	// ピクセルシェ???の float ?定数に?置した行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstSIArray(    int ConstantIndex, const int    *ParamArray, int ParamNum ) ;	// ピクセルシェ???の int   ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstIArray(     int ConstantIndex, const INT4   *ParamArray, int ParamNum ) ;	// ピクセルシェ???の int   ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstBArray(     int ConstantIndex, const BOOL   *ParamArray, int ParamNum ) ;	// ピクセルシェ???の BOOL  ?定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			ResetPSConstF(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェ???の float ?定数の設定をリセットする
extern	int			ResetPSConstI(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェ???の int   ?定数の設定をリセットする
extern	int			ResetPSConstB(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェ???の BOOL  ?定数の設定をリセットする

extern	int			SetRenderTargetToShader( int TargetIndex, int DrawScreen, int SurfaceIndex = 0 ) ;	// シェ???を使用した?画での?画先を設定する( DrawScreen に -1 を渡すと無効化 )
extern	int			SetUseTextureToShader(   int StageIndex, int GraphHandle ) ;						// シェ???を使用した?画で使用するグラフィックハンドルを設定する
extern	int			SetUseVertexShader(      int ShaderHandle ) ;										// シェ???を使用した?画に使用する頂?シェ???を設定する( -1を渡すと解除 )
extern	int			SetUsePixelShader(       int ShaderHandle ) ;										// シェ???を使用した?画に使用するピクセルシェ???を設定する( -1を渡すと解除 )

extern	int			CalcPolygonBinormalAndTangentsToShader(        VERTEX3DSHADER *Vertex, int PolygonNum ) ;													// ?リゴンの頂?の接線と??線をＵＶ座標から計算してセットする
extern	int			CalcPolygonIndexedBinormalAndTangentsToShader( VERTEX3DSHADER *Vertex, int VertexNum, const unsigned short *Indices, int PolygonNum ) ;		// ?リゴンの頂?の接線と??線をＵＶ座標から計算してセットする( 頂?インデックスを使用する )

extern	int			DrawPolygon2DToShader(          const VERTEX2DSHADER *Vertex, int PolygonNum ) ;																										// シェ???を使って２Ｄ?リゴンを?画する
extern	int			DrawPolygon3DToShader(          const VERTEX3DSHADER *Vertex, int PolygonNum ) ;																										// シェ???を使って３Ｄ?リゴンを?画する
extern	int			DrawPolygonIndexed2DToShader(   const VERTEX2DSHADER *Vertex, int VertexNum, const unsigned short *Indices, int PolygonNum ) ;															// シェ???を使って２Ｄ?リゴンを?画する( 頂?インデックスを使用する )
extern	int			DrawPolygonIndexed3DToShader(   const VERTEX3DSHADER *Vertex, int VertexNum, const unsigned short *Indices, int PolygonNum ) ;															// シェ???を使って３Ｄ?リゴンを?画する( 頂?インデックスを使用する )
extern	int			DrawPrimitive2DToShader(        const VERTEX2DSHADER *Vertex, int VertexNum,                                              int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;		// シェ???を使って２Ｄプリ?ティブを?画する
extern	int			DrawPrimitive3DToShader(        const VERTEX3DSHADER *Vertex, int VertexNum,                                              int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;		// シェ???を使って３Ｄプリ?ティブを?画する
extern	int			DrawPrimitiveIndexed2DToShader( const VERTEX2DSHADER *Vertex, int VertexNum, const unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;		// シェ???を使って２Ｄプリ?ティブを?画する( 頂?インデックスを使用する )
extern	int			DrawPrimitiveIndexed3DToShader( const VERTEX3DSHADER *Vertex, int VertexNum, const unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;		// シェ???を使って３Ｄプリ?ティブを?画する( 頂?インデックスを使用する )
extern	int			DrawPolygon3DToShader_UseVertexBuffer(           int VertexBufHandle ) ;																												// シェ???を使って３Ｄ?リゴンを?画する( 頂?バッフ?使用版 )
extern	int			DrawPolygonIndexed3DToShader_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle ) ;																							// シェ???を使って３Ｄ?リゴンを?画する( 頂?バッフ?とインデックスバッフ?使用版 )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;										// シェ???を使って３Ｄプリ?ティブを?画する( 頂?バッフ?使用版 )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int StartVertex, int UseVertexNum ) ;	// シェ???を使って３Ｄプリ?ティブを?画する( 頂?バッフ?使用版 )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;										// シェ???を使って３Ｄプリ?ティブを?画する( 頂?バッフ?とインデックスバッフ?使用版 )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum ) ;	// シェ???を使って３Ｄプリ?ティブを?画する( 頂?バッフ?とインデックスバッフ?使用版 )

// フィル??関係関数
#ifndef DX_NON_FILTER
extern	int			GraphFilter(         int    GrHandle,                                                                                                               int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像にフィル??処理を行う
extern	int			GraphFilterBlt(      int SrcGrHandle, int DestGrHandle,                                                                                             int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像のフィル??付き?送を行う
extern	int			GraphFilterRectBlt(  int SrcGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int DestX,  int DestY,                          int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像のフィル??付き?送を行う( 矩?指定 )
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_MONO, int Cb = 青色差( -255 ? 255 ), int Cr = 赤色差( -255 ? 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GAUSS, int PixelWidth = 使用ピクセル幅( 8 , 16 , 32 の何れか ), int Param = ぼかしパラメ??( 100 で約1ピクセル分の幅 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_DOWN_SCALE, int DivNum = 元のサイズの何分の１か、という値( 2 , 4 , 8 の何れか ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_BRIGHT_CLIP, int CmpType = クリップ?イプ( DX_CMP_LESS:CmpParam以下をクリップ  又は  DX_CMP_GREATER:CmpParam以上をクリップ ), int CmpParam = クリップパラメ??( 0 ? 255 ), int ClipFillFlag = クリップしたピクセルを塗りつぶすかどうか( TRUE:塗りつぶす  FALSE:塗りつぶさない ), int ClipFillColor = クリップしたピクセルに塗る色値( GetColor で取得する )( ClipFillFlag が FALSE の場合は使用しない ), int ClipFillAlpha = クリップしたピクセルに塗るα値( 0 ? 255 )( ClipFillFlag が FALSE の場合は使用しない ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_HSB, int HueType = Hue の意味( 0:相対値  1:絶対値 ), int Hue = 色相パラメ??( HueType が 0 の場合 = ピクセルの色相に対する相対値( -180 ? 180 )   HueType が 1 の場合 = 色相の絶対値( 0 ? 360 ) ), int Saturation = 彩度( -255 ? ), int Bright = 輝度( -255 ? 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_INVERT ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_LEVEL, int Min = 変換元の下限値( 0 ? 255 ), int Max = 変換元の上限値( 0 ? 255 ), int Gamma = ガン?値( 100 でガン?補正無し、0 とそれ以下の値は不可 ), int AfterMin = 変換後の最低値( 0 ? 255 ), int AfterMax = 変換後の最大値( 0 ? 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_TWO_COLOR, int Threshold = ?値( 0 ? 255 ), int LowColor = ?値より値が低かったピクセルの変換後の色値( GetColor で取得する ), int LowAlpha = ?値より値が低かったピクセルの変換後のα値( 0 ? 255 ), int HighColor = ?値より値が高かったピクセルの変換後の色値( GetColor で取得する ), int HighAlpha = ?値より値が高かったピクセルの変換後のα値( 0 ? 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GRADIENT_MAP, int MapGrHandle = グラデ?ション?ップのグラフィックハンドル( 元画像の輝度からグラデ?ション?ップ画像の x 座標を算出しますので縦幅は1dotでもＯＫ ), int Reverse = グラデ?ション?ップ左右反?フラグ( TRUE : グラデ?ション?ップを左右反?して使う  FALSE : 左右反?しない ) ) ;

extern	int			GraphBlend(         int    GrHandle, int BlendGrHandle,                                                                                                                                         int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドする
extern	int			GraphBlendBlt(      int SrcGrHandle, int BlendGrHandle, int DestGrHandle,                                                                                                                       int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドして結果を指定の画像に出力する
extern	int			GraphBlendRectBlt(  int SrcGrHandle, int BlendGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int BlendX,  int BlendY,                            int DestX, int DestY, int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドして結果を指定の画像に出力する( 矩?指定 )
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_NORMAL ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_RGBA_SELECT_MIX, int SelectR = ( 出力の赤分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectG = ( 出力の緑成分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectB = ( 出力の青成分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectA = ( 出力のα成分となる成分 DX_RGBA_SELECT_SRC_R 等 ) ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_MULTIPLE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DIFFERENCE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_ADD ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SCREEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_OVERLAY ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DODGE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BURN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DARKEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_LIGHTEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SOFTLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HARDLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_EXCLUSION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HUE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SATURATION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_COLOR ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BRIGHT ) ;
#endif // DX_NON_FILTER

#ifndef DX_NON_MOVIE
// ??ビ?グラフィック関係関数
extern	int			PlayMovie(						const TCHAR *FileName, int ExRate, int PlayType ) ;						// 動画フ?イルの再生
extern	int			OpenMovieToGraph(				const TCHAR *FileName, int FullColor = TRUE ) ;							// 動画フ?イルを開く
extern 	int			PlayMovieToGraph(				int GraphHandle, int PlayType = DX_PLAYTYPE_BACK , int SysPlay = 0 ) ;	// 動画フ?イルを使用するグラフィックハンドルの動画フ?イルの再生を開始する
extern 	int			PauseMovieToGraph(				int GraphHandle, int SysPause = 0 ) ;									// 動画フ?イルを使用するグラフィックハンドルの動画フ?イルの再生を停?する
extern	int			AddMovieFrameToGraph(			int GraphHandle, unsigned int FrameNum ) ;								// 動画フ?イルの再生フレ??を進める、戻すことは出来ない( 動画フ?イルが停?状態で、且つ Ogg Theora のみ有効 )
extern	int			SeekMovieToGraph(				int GraphHandle, int Time ) ;											// 動画フ?イルの再生位置を設定する(?リ秒単位)
extern 	int			GetMovieStateToGraph(			int GraphHandle ) ;														// 動画フ?イルの再生状態を得る
extern	int			SetMovieVolumeToGraph(			int Volume, int GraphHandle ) ;											// 動画フ?イルの音量を設定する(0?10000)
extern	int			ChangeMovieVolumeToGraph(		int Volume, int GraphHandle ) ;											// 動画フ?イルの音量を設定する(0?255)
extern	const BASEIMAGE* GetMovieBaseImageToGraph(	int GraphHandle, int *ImageUpdateFlag = NULL ) ;						// 動画フ?イルの基?イメ?ジデ??を取得する( ImageUpdateFlag に int ?変数のアドレスを渡すと、イメ?ジが更新された場合は 1 が、更新されていない場合は 0 が格?されます )
extern	int			GetMovieTotalFrameToGraph(		int GraphHandle ) ;														// 動画フ?イルの総フレ??数を得る( Ogg Theora でのみ有効 )
extern	int			TellMovieToGraph(				int GraphHandle ) ;														// 動画フ?イルの再生位置を取得する(?リ秒単位)
extern	int			TellMovieToGraphToFrame(		int GraphHandle ) ;														// 動画フ?イルの再生位置を取得する(フレ??単位)
extern	int			SeekMovieToGraphToFrame(		int GraphHandle, int Frame ) ;											// 動画フ?イルの再生位置を設定する(フレ??単位)
extern	LONGLONG	GetOneFrameTimeMovieToGraph(	int GraphHandle ) ;														// 動画フ?イルの１フレ??あたりの時間を取得する
extern	int			GetLastUpdateTimeMovieToGraph(	int GraphHandle ) ;														// 動画フ?イルのイメ?ジを最後に更新した時間を得る(?リ秒単位)
extern	int			SetMovieRightImageAlphaFlag(	int Flag ) ;															// 読み込む動画フ?イル映像の右半分の赤成分をα情報として扱うかどうかをセットする( TRUE:α情報として扱う  FALSE:α情報として扱わない( デフォルト ) )
extern	int			SetMovieColorA8R8G8B8Flag(		int Flag ) ;															// 読み込む動画フ?イルが32bitカラ?だった場合、A8R8G8B8 ?式として扱うかどうかをセットする、32bitカラ?ではない動画フ?イルに対しては無効( Flag  TRUE:A8R8G8B8として扱う  FALSE:X8R8G8B8として扱う( デフォルト ) )
#endif // DX_NON_MOVIE

// カメラ関係関数
extern	int			SetCameraNearFar(					float Near, float Far ) ;											// カメラの Nearクリップ面と Farクリップ面の距離を設定する
extern	int			SetCameraPositionAndTarget_UpVecY(  VECTOR Position, VECTOR Target ) ;									// カメラの視?、注視?、アップベクトルを設定する( アップベクトルはＹ軸方向から導き出す )
extern	int			SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR TargetPosition, VECTOR UpVector ) ;			// カメラの視?、注視?、アップベクトルを設定する
extern	int			SetCameraPositionAndAngle(			VECTOR Position, float VRotate, float HRotate, float TRotate ) ;	// カメラの視?、注視?、アップベクトルを設定する( 注視?とアップベクトルは垂直回?角度、水平回?角度、捻り回?角度から導き出す )
extern	int			SetCameraViewMatrix(				MATRIX ViewMatrix ) ;												// ビュ?行列を直接設定する
extern	int			SetCameraScreenCenter(				float x, float y ) ;												// 画面上におけるカメラが見ている映像の中心の座標を設定する

extern	int			SetupCamera_Perspective(			float Fov ) ;														// 遠近?カメラをセットアップする
extern	int			SetupCamera_Ortho(					float Size ) ;														// 正射影カメラをセットアップする
extern	int			SetupCamera_ProjectionMatrix(		MATRIX ProjectionMatrix ) ;											// 射影行列を直接設定する
extern	int			SetCameraDotAspect(					float DotAspect ) ;													// カメラのドットアスペクト比を設定する

extern	int			CheckCameraViewClip(				VECTOR CheckPos ) ;													// 指定の座標がカメラの視界に入っているかどうかを判定する( 戻り値 TRUE:視界に入っていない  FALSE:視界に入っている )
extern	int			CheckCameraViewClip_Dir(			VECTOR CheckPos ) ;													// 指定の座標がカメラの視界に入っているかどうかを判定する、戻り値で外れている方向も知ることができる( 戻り値 0:視界に入っている  0以外:視界に入っていない( DX_CAMERACLIP_LEFT や DX_CAMERACLIP_RIGHT が or 演算で混合されたもの、and 演算で方向を確認できる ) )
extern	int			CheckCameraViewClip_Box(			VECTOR BoxPos1, VECTOR BoxPos2 ) ;									// 二つの座標で?される?ックスがカメラの視界に入っているかどうかを判定する( 戻り値 TRUE:視界に入っていない  FALSE:視界に入っている )

extern	float		GetCameraNear(						void ) ;															// カメラの Near クリップ面の距離を取得する
extern	float		GetCameraFar(						void ) ;															// カメラの Far クリップ面の距離を取得する

extern	VECTOR		GetCameraPosition(					void ) ;															// カメラの位置を取得する
extern	VECTOR		GetCameraTarget(					void ) ;															// カメラの注視?を取得する
extern	VECTOR		GetCameraUpVector(					void ) ;															// カメラの視線に垂直な上方向のベクトルを取得する
extern	float		GetCameraAngleHRotate(				void ) ;															// カメラの水平方向の向きを取得する
extern	float		GetCameraAngleVRotate(				void ) ;															// カメラの垂直方向の向きを取得する
extern	float		GetCameraAngleTRotate(				void ) ;															// カメラの向きの捻り角度を取得する

extern	MATRIX		GetCameraViewMatrix(				void ) ;															// ビュ?行列を取得する
extern	MATRIX		GetCameraBillboardMatrix(			void ) ;															// ビル??ド行列を取得する
extern	float		GetCameraFov(						void ) ;															// カメラの視野角を取得する
extern	float		GetCameraSize(						void ) ;															// カメラの視野サイズを取得する
extern	MATRIX		GetCameraProjectionMatrix(			void ) ;															// 射影行列を取得する
extern	float		GetCameraDotAspect(					void ) ;															// カメラのドットアスペクト比を得る
extern	MATRIX		GetCameraViewportMatrix(			void ) ;															// ビュ???ト行列を取得する
extern	MATRIX		GetCameraAPIViewportMatrix(			void ) ;															// Direct3Dで自動適用されるビュ???ト行列を取得する

// ライト関係関数
extern	int			SetUseLighting(				int Flag ) ;																// ライティングを使用するかどうかを設定する
extern	int			SetMaterialUseVertDifColor( int UseFlag ) ;																// ３Ｄ?画のライティング計算で頂?カラ?のディフュ?ズカラ?を使用するかどうかを設定する
extern	int			SetMaterialUseVertSpcColor( int UseFlag ) ;																// ３Ｄ?画のライティング計算で頂?カラ?のスペキュラカラ?を使用するかどうかを設定する
extern	int			SetMaterialParam(			MATERIALPARAM Material ) ;													// ３Ｄ?画のライティング計算で使用する?テリアルパラメ??を設定する
extern	int			SetUseSpecular(				int UseFlag ) ;																// ３Ｄ?画にスペキュラを使用するかどうかを設定する
extern	int			SetGlobalAmbientLight(		COLOR_F Color ) ;															// グロ?バルアンビエントライトカラ?を設定する

extern	int			ChangeLightTypeDir(			VECTOR Direction ) ;														// デフォルトライトの?イプをディレクショナルライトにする
extern	int			ChangeLightTypeSpot(		VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// デフォルトライトの?イプをス?ットライトにする
extern	int			ChangeLightTypePoint(		VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// デフォルトライトの?イプを?イントライトにする
extern	int			GetLightType(				void ) ;																	// デフォルトライトの?イプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			SetLightEnable(				int EnableFlag ) ;															// デフォルトライトを使用するかどうかを設定する
extern	int			GetLightEnable(				void ) ;																	// デフォルトライトを使用するかどうかを取得する( 戻り値?TRUE:有効  FALSE:無効 )
extern	int			SetLightDifColor(			COLOR_F Color ) ;															// デフォルトライトのディフュ?ズカラ?を設定する
extern	COLOR_F		GetLightDifColor(			void ) ;																	// デフォルトライトのディフュ?ズカラ?を取得する
extern	int			SetLightSpcColor(			COLOR_F Color ) ;															// デフォルトライトのスペキュラカラ?を設定する
extern	COLOR_F		GetLightSpcColor(			void ) ;																	// デフォルトライトのスペキュラカラ?を取得する
extern	int			SetLightAmbColor(			COLOR_F Color ) ;															// デフォルトライトのアンビエントカラ?を設定する
extern	COLOR_F		GetLightAmbColor(			void ) ;																	// デフォルトライトのアンビエントカラ?を取得する
extern	int			SetLightDirection(			VECTOR Direction ) ;														// デフォルトライトの方向を設定する
extern	VECTOR		GetLightDirection(			void ) ;																	// デフォルトライトの方向を取得する
extern	int			SetLightPosition(			VECTOR Position ) ;															// デフォルトライトの位置を設定する
extern	VECTOR		GetLightPosition(			void ) ;																	// デフォルトライトの位置を取得する
extern	int			SetLightRangeAtten(			float Range, float Atten0, float Atten1, float Atten2 ) ;					// デフォルトライトの距離減衰パラメ??を設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightRangeAtten(			float *Range, float *Atten0, float *Atten1, float *Atten2 )	;				// デフォルトライトの距離減衰パラメ??を取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngle(				float OutAngle, float InAngle ) ;											// デフォルトライトのス?ットライトのパラメ??を設定する( 外部コ?ン角度、内部コ?ン角度 )
extern	int			GetLightAngle(				float *OutAngle, float *InAngle ) ;											// デフォルトライトのス?ットライトのパラメ??を取得する( 外部コ?ン角度、内部コ?ン角度 )
extern	int			SetLightUseShadowMap(		int SmSlotIndex, int UseFlag ) ;											// デフォルトライトに SetUseShadowMap で指定したシャドウ?ップを適用するかどうかを設定する( SmSlotIndex:シャドウ?ップスロット( SetUseShadowMap の第一引数に設定する値 ) UseFlag:適用にするかどうかのフラグ( TRUE:適用する( デフォルト )  FALSE:適用しない ) )

extern	int			CreateDirLightHandle(       VECTOR Direction ) ;														// ディレクショナルライトハンドルを作成する
extern	int			CreateSpotLightHandle(      VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ス?ットライトハンドルを作成する
extern	int			CreatePointLightHandle(     VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ?イントライトハンドルを作成する
extern	int			DeleteLightHandle(          int LHandle ) ;																// ライトハンドルを削除する
extern	int			DeleteLightHandleAll(       void ) ;																	// ライトハンドルを全て削除する
extern	int			SetLightTypeHandle(         int LHandle, int LightType ) ;												// ライトハンドルのライトの?イプを変更する( DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			SetLightEnableHandle(       int LHandle, int EnableFlag ) ;												// ライトハンドルのライト効果の有効、無効を設定する( TRUE:有効  FALSE:無効 )
extern	int			SetLightDifColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのディフュ?ズカラ?を設定する
extern	int			SetLightSpcColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのスペキュラカラ?を設定する
extern	int			SetLightAmbColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのアンビエントカラ?を設定する
extern	int			SetLightDirectionHandle(    int LHandle, VECTOR Direction ) ;											// ライトハンドルのライトの方向を設定する
extern	int			SetLightPositionHandle(     int LHandle, VECTOR Position ) ;											// ライトハンドルのライトの位置を設定する
extern	int			SetLightRangeAttenHandle(   int LHandle, float Range, float Atten0, float Atten1, float Atten2 ) ;		// ライトハンドルのライトの距離減衰パラメ??を設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngleHandle(        int LHandle, float OutAngle, float InAngle ) ;								// ライトハンドルのライトのス?ットライトのパラメ??を設定する( 外部コ?ン角度、内部コ?ン角度 )
extern	int			SetLightUseShadowMapHandle(	int LHandle, int SmSlotIndex, int UseFlag ) ;								// ライトハンドルのライトに SetUseShadowMap で指定したシャドウ?ップを適用するかどうかを設定する( SmSlotIndex:シャドウ?ップスロット( SetUseShadowMap の第一引数に設定する値 ) UseFlag:適用にするかどうかのフラグ( TRUE:適用する( デフォルト )  FALSE:適用しない ) )
extern	int			GetLightTypeHandle(         int LHandle ) ;																// ライトハンドルのライトの?イプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			GetLightEnableHandle(       int LHandle ) ;																// ライトハンドルのライト効果の有効、無効を取得する( TRUE:有効  FALSE:無効 )
extern	COLOR_F		GetLightDifColorHandle(     int LHandle ) ;																// ライトハンドルのライトのディフュ?ズカラ?を取得する
extern	COLOR_F		GetLightSpcColorHandle(     int LHandle ) ;																// ライトハンドルのライトのスペキュラカラ?を取得する
extern	COLOR_F		GetLightAmbColorHandle(     int LHandle ) ;																// ライトハンドルのライトのアンビエントカラ?を取得する
extern	VECTOR		GetLightDirectionHandle(    int LHandle ) ;																// ライトハンドルのライトの方向を取得する
extern	VECTOR		GetLightPositionHandle(     int LHandle ) ;																// ライトハンドルのライトの位置を取得する
extern	int			GetLightRangeAttenHandle(   int LHandle, float *Range, float *Atten0, float *Atten1, float *Atten2 ) ;	// ライトハンドルのライトの距離減衰パラメ??を取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightAngleHandle(        int LHandle, float *OutAngle, float *InAngle ) ;							// ライトハンドルのライトのス?ットライトのパラメ??を取得する( 外部コ?ン角度、内部コ?ン角度 )

extern	int			GetEnableLightHandleNum(	void ) ;																	// 有効になっているライトハンドルの数を取得する
extern	int			GetEnableLightHandle(		int Index ) ;																// 有効になっているライトハンドルを取得する

// 色情報取得用関数
extern	int			GetTexFormatIndex(			const IMAGEFORMATDESC *Format ) ;																									// テクス?ャフォ??ットのインデックスを得る
extern	int			ColorKaiseki(				const void *PixelData, COLORDATA* ColorData ) ;																				// 色ビット情報解析
#ifdef __WINDOWS__
extern	int			CreatePixelFormat(			D_DDPIXELFORMAT *PixelFormatBuf, int ColorBitDepth, DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;		// DDPIXELFORMATデ??を作成する
#endif // __WINDOWS__








// DxMask.cpp 関数プロト?イプ宣言

#ifndef DX_NON_MASK

// ?スク関係 
extern	int			CreateMaskScreen(				void ) ;																						// ?スクスクリ?ンを作成する
extern	int			DeleteMaskScreen(				void ) ;																						// ?スクスクリ?ンを削除する
extern	int			DrawMaskToDirectData(			int x, int y, int Width, int Height, const void *MaskData , int TransMode ) ;					// ?スクスクリ?ンにメモリ上のビット?ップデ??を?送する( MaskData は 1byte で 1dot ?す１ラインあたり Width byte のデ??配列の先頭アドレス )
extern	int			DrawFillMaskToDirectData(		int x1, int y1, int x2, int y2,  int Width, int Height, const void *MaskData ) ;				// ?スクスクリ?ンにメモリ上のビット?ップデ??で指定矩?内を塗りつぶすように?送する

extern	int			SetUseMaskScreenFlag(			int ValidFlag ) ;																				// ?スクスクリ?ンを使用するかどうかを設定する( ValidFlag:使用するかどうか( TRUE:使用する  FALSE:使用しない( デフォルト ) )
extern	int			GetUseMaskScreenFlag(			void ) ;																						// ?スクスクリ?ンを使用するかどうかを取得する
extern	int			FillMaskScreen(					int Flag ) ;																					// ?スクスクリ?ンを指定の色で塗りつぶす

extern	int			InitMask(						void ) ;																						// ?スクハンドルをすべて削除する
extern	int			MakeMask(						int Width, int Height ) ;																		// ?スクハンドルを作成する
extern	int			GetMaskSize(					int *WidthBuf, int *HeightBuf, int MaskHandle ) ;												// ?スクハンドルが持つ?スクイメ?ジのサイズを取得する
extern	int			SetDataToMask(					int Width, int Height, const void *MaskData, int MaskHandle ) ;									// ?スクハンドルにビット?ップイメ?ジを?送する
extern	int			DeleteMask(						int MaskHandle ) ;																				// ?スクハンドルを削除する
extern	int			BmpBltToMask(					HBITMAP Bmp, int BmpPointX, int BmpPointY, int MaskHandle ) ;									// ?スクハンドルにＢＭＰデ??を?送する
extern	int			LoadMask(						const TCHAR *FileName ) ;																		// 画像フ?イルを読み込み?スクハンドルを作成する
extern	int			LoadDivMask(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;	// 画像フ?イルを分割読み込みして?スクハンドルを作成する
extern	int			DrawMask(						int x, int y, int MaskHandle, int TransMode ) ;													// ?スクスクリ?ンに?スクハンドルの持つ?スクイメ?ジを書き込む
#ifndef DX_NON_FONT
extern	int			DrawFormatStringMask(			int x, int y, int Flag,                 const TCHAR *FormatString, ... ) ;						// 書式指定ありの文字列を?スクスクリ?ンに?画する
extern	int			DrawFormatStringMaskToHandle(	int x, int y, int Flag, int FontHandle, const TCHAR *FormatString, ... ) ;						// 書式指定ありの文字列を?スクスクリ?ンに?画する( フォントハンドル指定版 )( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可? )
extern	int			DrawStringMask(					int x, int y, int Flag,                 const TCHAR *String ) ;									// 文字列を?スクスクリ?ンに?画する
extern	int			DrawStringMaskToHandle(			int x, int y, int Flag, int FontHandle, const TCHAR *String ) ;									// 文字列を?スクスクリ?ンに?画する( フォントハンドル指定版 )( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可? )
#endif // DX_NON_FONT
extern	int			DrawFillMask(					int x1, int y1, int x2, int y2, int MaskHandle ) ;												// ?スクハンドルが持つ?スクイメ?ジを?スクスクリ?ンいっぱいに?画する( ?イル状に並べる )
extern	int			SetMaskReverseEffectFlag(		int ReverseFlag ) ;																				// ?スクイメ?ジ内の数値に対する効果を逆?させる( 旧バ?ジョンとの互換性の為の?? )

extern 	int			GetMaskScreenData(				int x1, int y1, int x2, int y2, int MaskHandle ) ;												// ?スクスクリ?ンの指定矩?部分を?スクハンドルに?送する
extern	int			GetMaskUseFlag(					void ) ;																						// ?スクスクリ?ンを使用する設定になっているかどうかを取得する

#endif // DX_NON_MASK
















// DxFont.cpp 関数プロト?イプ宣言

#ifndef DX_NON_FONT

// フォント、文字列?画関係関数
extern	int			EnumFontName(                           TCHAR *NameBuffer, int NameBufferNum, int JapanOnlyFlag = TRUE ) ;													// 使用可?なフォントの名前を列挙する( NameBuffer に 64バイト区切りで名前が格?されます )
extern	int			EnumFontNameEx(                         TCHAR *NameBuffer, int NameBufferNum,                            int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;	// 使用可?なフォントの名前を列挙する( NameBuffer に 64バイト区切りで名前が格?されます )( 文字セット指定版 )
extern	int			EnumFontNameEx2(						TCHAR *NameBuffer, int NameBufferNum, const TCHAR *EnumFontName, int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;	// 指定のフォント名のフォントを列挙する
extern	int			CheckFontName(							const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;												// 指定のフォント名のフォントが存在するかどうかを?ェックする( 戻り値  TRUE:存在する  FALSE:存在しない )

extern	int			InitFontToHandle(                       void ) ;																						// 全てのフォントハンドルを削除する

extern	int			CreateFontToHandle(                     const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE , int Handle = -1 ) ;		// フォントハンドルを作成する
extern	int			SetFontSpaceToHandle(                   int Point, int FontHandle ) ;																	// フォントハンドルの字間を変更する
extern	int			DeleteFontToHandle(                     int FontHandle ) ;																				// フォントハンドルを削除する
extern	int			SetFontLostFlag(                        int FontHandle, int *LostFlag ) ;																// フォントハンドルを削除した際に TRUE を代入する変数のアドレスを設定する

extern	int			ChangeFont(                             const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_SHFTJIS 等 */ ) ;							// デフォルトフォントハンドルで使用するフォントを変更
extern	int			ChangeFontType(                         int FontType ) ;																				// デフォルトフォントハンドルのフォント?イプの変更
extern	int			SetFontSize(                            int FontSize ) ;																				// デフォルトフォントハンドルのサイズを設定する
extern	int			GetFontSize(                            void ) ;																						// デフォルトフォントハンドルのサイズを取得する
extern	int			SetFontThickness(                       int ThickPal ) ;																				// デフォルトフォントハンドルの太さを設定する
extern	int			SetFontSpace(                           int Point ) ;																					// デフォルトフォントハンドルの字間を変更する
extern	int			GetFontSpace(                           void ) ;																						// デフォルトフォントハンドルの字間を取得する
extern	int			SetDefaultFontState(                    const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE ) ;	// デフォルトフォントハンドルの設定を変更する
extern	int			GetDefaultFontHandle(                   void ) ;																						// デフォルトフォントハンドルを取得する
extern	int			GetFontMaxWidth(                        void ) ;																						// デフォルトフォントハンドルの文字の最大幅を取得する
extern	int			GetDrawStringWidth(                     const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;									// デフォルトフォントハンドルを使用した文字列の?画幅を取得する
extern	int			GetDrawFormatStringWidth(               const TCHAR *FormatString, ... ) ;																// デフォルトフォントハンドルを使用した書式付き文字列の?画幅を取得する
extern	int			GetDrawExtendStringWidth(               double ExRateX, const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;					// デフォルトフォントハンドルを使用した文字列の?画幅を取得する( 拡大率付き )
extern	int			GetDrawExtendFormatStringWidth(         double ExRateX, const TCHAR *FormatString, ... ) ;												// デフォルトフォントハンドルを使用した書式付き文字列の?画幅を取得する( 拡大率付き )

extern	int			GetFontMaxWidthToHandle(                int FontHandle ) ;																				// フォントハンドルの文字の最大幅を取得する
extern	int			GetFontSizeToHandle(                    int FontHandle ) ;																				// フォントハンドルのサイズを取得する
extern	int			GetFontSpaceToHandle(                   int FontHandle ) ;																				// フォントハンドルの字間を取得する
extern	int			GetFontCharInfo(                        int FontHandle, const TCHAR *Char, int *DrawX, int *DrawY, int *NextCharX, int *SizeX, int *SizeY ) ;	// フォントハンドルの指定の文字の?画情報を取得する
extern	int			GetDrawStringWidthToHandle(             const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;					// フォントハンドルを使用した文字列の?画幅を取得する
extern	int			GetDrawFormatStringWidthToHandle(       int FontHandle, const TCHAR *FormatString, ... ) ;												// フォントハンドルを使用した書式付き文字列の?画幅を取得する
extern	int			GetDrawExtendStringWidthToHandle(       double ExRateX, const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// フォントハンドルを使用した文字列の?画幅を取得する
extern	int			GetDrawExtendFormatStringWidthToHandle( double ExRateX, int FontHandle, const TCHAR *FormatString, ... ) ;								// フォントハンドルを使用した書式付き文字列の?画幅を取得する
extern	int			GetFontStateToHandle(                   TCHAR *FontName, int *Size, int *Thick, int FontHandle, int *FontType = NULL , int *CharSet = NULL , int *EdgeSize = NULL , int *Italic = NULL ) ;		// フォントハンドルの情報を取得する
extern	int			CheckFontCacheToTextureFlag(            int FontHandle ) ;																				// フォントハンドルがテクス?ャキャッシュを使用しているかどうかを取得する
extern	int			CheckFontChacheToTextureFlag(           int FontHandle ) ;																				// CheckFontCacheToTextureFlag の誤字版
extern	int			CheckFontHandleValid(                   int FontHandle ) ;																				// フォントハンドルが有効かどうかを取得する

extern	int			SetFontCacheToTextureFlag(              int Flag ) ;																					// フォントのキャッシュにテクス?ャを使用するかどうかを設定する( TRUE:テクス?ャを使用する( デフォルト )  FALSE:テクス?ャは使用しない )
extern	int			GetFontCacheToTextureFlag(              void ) ;																						// フォントのキャッシュにテクス?ャを使用するかどうかを設定する
extern	int			SetFontChacheToTextureFlag(             int Flag ) ;																					// SetFontCacheToTextureFlag の誤字版
extern	int			GetFontChacheToTextureFlag(             void ) ;																						// GetFontCacheToTextureFlag の誤字版
extern	int			SetFontCacheTextureColorBitDepth(		int ColorBitDepth ) ;																			// フォントのキャッシュとして使用するテクス?ャのカラ?ビット?度を設定する( 16 又は 32 のみ指定可?  デフォルトは 32 )
extern	int			GetFontCacheTextureColorBitDepth(		void ) ;																						// フォントのキャッシュとして使用するテクス?ャのカラ?ビット?度を取得する
extern	int			SetFontCacheCharNum(                    int CharNum ) ;																					// フォントキャッシュでキャッシュできる文字数を設定する
extern	int			GetFontCacheCharNum(                    void ) ;																						// フォントキャッシュでキャッシュできる文字数を取得する( 戻り値  0:デフォルト  1以上:指定文字数 )
extern	int			SetFontCacheUsePremulAlphaFlag(         int Flag ) ;																					// フォントキャッシュとして保存する画像の?式を乗算済みα?ャンネル付き画像にするかどうかを設定する( TRUE:乗算済みαを使用する  FLASE:乗算済みαを使用しない( デフォルト ) )
extern	int			GetFontCacheUsePremulAlphaFlag(         void ) ;																						// フォントキャッシュとして保存する画像の?式を乗算済みα?ャンネル付き画像にするかどうかを取得する

// FontCacheStringDraw の代わりに DrawString を使ってください
extern	int			FontCacheStringDrawToHandle(            int x, int y, const TCHAR *StrData, int Color, int EdgeColor, BASEIMAGE *DestImage, const RECT *ClipRect /* NULL 可 */ , int FontHandle, int VerticalFlag = FALSE , SIZE *DrawSizeP = NULL ) ;
extern	int			FontBaseImageBlt(                       int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,                 int VerticalFlag = FALSE ) ;	// 基?イメ?ジに文字列を?画する( デフォルトフォントハンドルを使用する )
extern	int			FontBaseImageBltToHandle(               int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage, int FontHandle, int VerticalFlag = FALSE ) ;	// 基?イメ?ジに文字列を?画する

extern	int			MultiByteCharCheck(                     const char *Buf, int CharSet /* DX_CHARSET_SHFTJIS */ ) ;										// ２バイト文字か調べる( TRUE:２バイト文字  FALSE:１バイト文字 )

// 文字列?画関数
extern	int			DrawString(                             int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// デフォルトフォントハンドルを使用して文字列を?画する
extern	int			DrawVString(                            int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// デフォルトフォントハンドルを使用して文字列を?画する( 縦書き )
extern	int			DrawFormatString(                       int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// デフォルトフォントハンドルを使用して書式指定文字列を?画する
extern	int			DrawFormatVString(                      int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// デフォルトフォントハンドルを使用して書式指定文字列を?画する( 縦書き )
extern	int			DrawExtendString(                       int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// デフォルトフォントハンドルを使用して文字列の拡大?画
extern	int			DrawExtendVString(                      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// デフォルトフォントハンドルを使用して文字列の拡大?画( 縦書き )
extern	int			DrawExtendFormatString(                 int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// デフォルトフォントハンドルを使用して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVString(                int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// デフォルトフォントハンドルを使用して書式指定文字列を拡大?画する( 縦書き )

extern	int			DrawStringF(                            float x, float y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																			// デフォルトフォントハンドルを使用して文字列を?画する( 座標指定が float 版 )
extern	int			DrawVStringF(                           float x, float y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																			// デフォルトフォントハンドルを使用して文字列を?画する( 縦書き )( 座標指定が float 版 )
extern	int			DrawFormatStringF(                      float x, float y, int Color,                 const TCHAR *FormatString, ... ) ;																					// デフォルトフォントハンドルを使用して書式指定文字列を?画する( 座標指定が float 版 )
extern	int			DrawFormatVStringF(                     float x, float y, int Color,                 const TCHAR *FormatString, ... ) ;																					// デフォルトフォントハンドルを使用して書式指定文字列を?画する( 縦書き )( 座標指定が float 版 )
extern	int			DrawExtendStringF(                      float x, float y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;											// デフォルトフォントハンドルを使用して文字列の拡大?画( 座標指定が float 版 )
extern	int			DrawExtendVStringF(                     float x, float y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;											// デフォルトフォントハンドルを使用して文字列の拡大?画( 縦書き )( 座標指定が float 版 )
extern	int			DrawExtendFormatStringF(                float x, float y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;													// デフォルトフォントハンドルを使用して書式指定文字列を拡大?画する( 座標指定が float 版 )
extern	int			DrawExtendFormatVStringF(               float x, float y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;													// デフォルトフォントハンドルを使用して書式指定文字列を拡大?画する( 縦書き )( 座標指定が float 版 )

extern	int			DrawNumberToI(                          int x, int y,                          int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して整数?の数値を?画する
extern	int			DrawNumberToF(                          int x, int y,                          double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して浮動小数??の数値を?画する
extern	int			DrawNumberPlusToI(                      int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して整数?の数値とその説明の文字列を一度に?画する
extern 	int			DrawNumberPlusToF(                      int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して浮動小数??の数値とその説明の文字列を一度に?画する

extern	int			DrawStringToZBuffer(                    int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッフ?に対して文字列を?画する
extern	int			DrawVStringToZBuffer(                   int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッフ?に対して文字列を?画する( 縦書き )
extern	int			DrawFormatStringToZBuffer(              int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッフ?に対して書式指定文字列を?画する
extern	int			DrawFormatVStringToZBuffer(             int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッフ?に対して書式指定文字列を?画する( 縦書き )
extern	int			DrawExtendStringToZBuffer(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッフ?に対して文字列を拡大?画する
extern	int			DrawExtendVStringToZBuffer(             int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッフ?に対して文字列を拡大?画する( 縦書き )
extern	int			DrawExtendFormatStringToZBuffer(        int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToZBuffer(       int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッフ?に対して書式指定文字列を拡大?画する( 縦書き )


extern	int			DrawStringToHandle(                     int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;													// フォントハンドルを使用して文字列を?画する
extern	int			DrawVStringToHandle(                    int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;																				// フォントハンドルを使用して文字列を?画する( 縦書き )
extern	int			DrawFormatStringToHandle(               int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// フォントハンドルを使用して書式指定文字列を?画する
extern	int			DrawFormatVStringToHandle(              int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// フォントハンドルを使用して書式指定文字列を?画する( 縦書き )
extern	int			DrawExtendStringToHandle(               int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;					// フォントハンドルを使用して文字列を拡大?画する
extern	int			DrawExtendVStringToHandle(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して文字列を拡大?画する( 縦書き )
extern	int			DrawExtendFormatStringToHandle(         int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// フォントハンドルを使用して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToHandle(        int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// フォントハンドルを使用して書式指定文字列を拡大?画する( 縦書き )

extern	int			DrawStringFToHandle(                    float x, float y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;												// フォントハンドルを使用して文字列を?画する( 座標指定が float 版 )
extern	int			DrawVStringFToHandle(                   float x, float y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;																			// フォントハンドルを使用して文字列を?画する( 縦書き )( 座標指定が float 版 )
extern	int			DrawFormatStringFToHandle(              float x, float y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																					// フォントハンドルを使用して書式指定文字列を?画する( 座標指定が float 版 )
extern	int			DrawFormatVStringFToHandle(             float x, float y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																					// フォントハンドルを使用して書式指定文字列を?画する( 縦書き )( 座標指定が float 版 )
extern	int			DrawExtendStringFToHandle(              float x, float y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;				// フォントハンドルを使用して文字列を拡大?画する( 座標指定が float 版 )
extern	int			DrawExtendVStringFToHandle(             float x, float y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;											// フォントハンドルを使用して文字列を拡大?画する( 縦書き )( 座標指定が float 版 )
extern	int			DrawExtendFormatStringFToHandle(        float x, float y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;													// フォントハンドルを使用して書式指定文字列を拡大?画する( 座標指定が float 版 )
extern	int			DrawExtendFormatVStringFToHandle(       float x, float y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;													// フォントハンドルを使用して書式指定文字列を拡大?画する( 縦書き )( 座標指定が float 版 )

extern	int			DrawNumberToIToHandle(                  int x, int y,                          int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して整数?の数値を?画する
extern	int			DrawNumberToFToHandle(                  int x, int y,                          double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して浮動小数??の数値を?画する
extern	int			DrawNumberPlusToIToHandle(              int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して整数?の数値とその説明の文字列を一度に?画する
extern	int			DrawNumberPlusToFToHandle(              int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して浮動小数??の数値とその説明の文字列を一度に?画する

extern	int			DrawStringToHandleToZBuffer(            int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;		// フォントハンドルを使用してＺバッフ?に対して文字列を?画する
extern	int			DrawVStringToHandleToZBuffer(           int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// フォントハンドルを使用してＺバッフ?に対して文字列を?画する( 縦書き )
extern	int			DrawFormatStringToHandleToZBuffer(      int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッフ?に対して書式指定文字列を?画する
extern	int			DrawFormatVStringToHandleToZBuffer(     int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッフ?に対して書式指定文字列を?画する( 縦書き )
extern	int			DrawExtendStringToHandleToZBuffer(      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;		// フォントハンドルを使用してＺバッフ?に対して文字列を拡大?画する
extern	int			DrawExtendVStringToHandleToZBuffer(     int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// フォントハンドルを使用してＺバッフ?に対して文字列を拡大?画する( 縦書き )
extern	int			DrawExtendFormatStringToHandleToZBuffer(  int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッフ?に対して書式指定文字列を拡大?画する
extern	int			DrawExtendFormatVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッフ?に対して書式指定文字列を拡大?画する( 縦書き )

#endif // DX_NON_FONT








// DxMath.cpp 関数プロト?イプ宣言

// 演算ライブラリ
extern	int			CreateIdentityMatrix(         MATRIX *Out ) ;																				// 単位行列を作成する
extern	int			CreateLookAtMatrix(           MATRIX *Out, const VECTOR *Eye, const VECTOR *At, const VECTOR *Up ) ;						// ビュ?行列を作成する
extern	int			CreateLookAtMatrix2(          MATRIX *Out, const VECTOR *Eye, double XZAngle, double Oira ) ;								// ビュ?行列を作成する(方向を回?値で指定)
extern	int			CreateLookAtMatrixRH(         MATRIX *Out, const VECTOR *Eye, const VECTOR *At, const VECTOR *Up ) ;						// ビュ?行列を作成する(右手座標系用)
extern	int			CreateMultiplyMatrix(         MATRIX *Out, const MATRIX *In1, const MATRIX *In2 ) ;											// 行列の積を求める
extern	int			CreatePerspectiveFovMatrix(   MATRIX *Out, float fov,  float zn, float zf, float aspect = -1.0f ) ;							// 射影行列を作成する
extern	int			CreatePerspectiveFovMatrixRH( MATRIX *Out, float fov,  float zn, float zf, float aspect = -1.0f ) ;							// 射影行列を作成する(右手座標系用)
extern	int			CreateOrthoMatrix(            MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;							// 正射影行列を作成する
extern	int			CreateOrthoMatrixRH(          MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;							// 正射影行列を作成する(右手座標系用)
extern	int			CreateScalingMatrix(          MATRIX *Out, float sx, float sy, float sz ) ;													// スケ?リング行列を作成する
extern	int			CreateRotationXMatrix(        MATRIX *Out, float Angle ) ;																	// Ｘ軸を中心とした回?行列を作成する
extern	int			CreateRotationYMatrix(        MATRIX *Out, float Angle ) ;																	// Ｙ軸を中心とした回?行列を作成する
extern	int			CreateRotationZMatrix(        MATRIX *Out, float Angle ) ;																	// Ｚ軸を中心とした回?行列を作成する
extern	int			CreateTranslationMatrix(      MATRIX *Out, float x, float y, float z ) ;													// 平行移動行列を作成する
extern	int			CreateTransposeMatrix(        MATRIX *Out, const MATRIX *In ) ;																// ?置行列を作成する
extern	int			CreateInverseMatrix(          MATRIX *Out, const MATRIX *In ) ;																// 逆行列を作成する
extern	int			CreateViewportMatrix(         MATRIX *Out, float CenterX, float CenterY, float Width, float Height ) ;						// ビュ???ト行列を作成する
extern	int			CreateRotationXYZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｘ軸回?→Ｙ軸回?→Ｚ軸回?を合成した行列を作成する
extern	int			CreateRotationXZYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｘ軸回?→Ｚ軸回?→Ｙ軸回?を合成した行列を作成する
extern	int			CreateRotationYXZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｙ軸回?→Ｘ軸回?→Ｚ軸回?を合成した行列を作成する
extern	int			CreateRotationYZXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｙ軸回?→Ｚ軸回?→Ｘ軸回?を合成した行列を作成する
extern	int			CreateRotationZXYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｚ軸回?→Ｘ軸回?→Ｙ軸回?を合成した行列を作成する
extern	int			CreateRotationZYXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;											// Ｚ軸回?→Ｙ軸回?→Ｘ軸回?を合成した行列を作成する
extern	int			GetMatrixXYZRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＸＹＺ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixXZYRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＸＺＹ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYXZRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＹＸＺ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYZXRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＹＺＸ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZXYRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＺＸＹ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZYXRotation(         const MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;							// 行列からＺＹＸ軸回?の値を取得する( 戻り値?-1:ジンバルロック発生  0:成功 )
extern	int			VectorNormalize(              VECTOR *Out, const VECTOR *In ) ;																// ベクトルを正規化する
extern	int			VectorScale(                  VECTOR *Out, const VECTOR *In, float Scale ) ;												// ベクトルをスカラ??する
extern	int			VectorMultiply(               VECTOR *Out, const VECTOR *In1, const VECTOR *In2 ) ;											// ベクトルの?け算をする
extern	int			VectorSub(                    VECTOR *Out, const VECTOR *In1, const VECTOR *In2 ) ;											// Out = In1 - In2 のベクトル計算をする 
extern	int			VectorAdd(                    VECTOR *Out, const VECTOR *In1, const VECTOR *In2 ) ;											// Out = In1 + In2 のベクトル計算をする 
extern	int			VectorOuterProduct(           VECTOR *Out, const VECTOR *In1, const VECTOR *In2 ) ;											// In1とIn2の外積を計算する
extern	float		VectorInnerProduct(           const VECTOR *In1, const VECTOR *In2 ) ;														// In1とIn2の内積を計算する
extern	int			VectorRotationX(              VECTOR *Out, const VECTOR *In, double Angle ) ;												// ベクトルのＸ軸を軸にした回?を行う
extern	int			VectorRotationY(              VECTOR *Out, const VECTOR *In, double Angle ) ;												// ベクトルのＹ軸を軸にした回?を行う
extern	int			VectorRotationZ(              VECTOR *Out, const VECTOR *In, double Angle ) ;												// ベクトルのＺ軸を軸にした回?を行う
extern	int			VectorTransform(              VECTOR *Out, const VECTOR *InVec, const MATRIX *InMatrix ) ;									// ベクトル行列と4x4正方行列を乗算する( w は 1 と仮定 )
extern	int			VectorTransformSR(            VECTOR *Out, const VECTOR *InVec, const MATRIX *InMatrix ) ;									// ベクトル行列と4x4正方行列の回?部分のみを乗算する
extern	int			VectorTransform4(             VECTOR *Out, float *V4Out, const VECTOR *InVec, const float *V4In, const MATRIX *InMatrix ) ; // ベクトル行列と4x4正方行列を乗算する( w の要素を渡す )

extern	int			Segment_Segment_Analyse(      const VECTOR *SegmentAPos1, const VECTOR *SegmentAPos2, const VECTOR *SegmentBPos1, const VECTOR *SegmentBPos2, SEGMENT_SEGMENT_RESULT *Result ) ;								// 二つの線分の最接近?情報を解析する
extern	int			Segment_Point_Analyse(        const VECTOR *SegmentPos1, const VECTOR *SegmentPos2, const VECTOR *PointPos, SEGMENT_POINT_RESULT *Result ) ;																	// 線分と?の最接近?情報を解析する
extern	int			Segment_Triangle_Analyse(     const VECTOR *SegmentPos1, const VECTOR *SegmentPos2, const VECTOR *TrianglePos1, const VECTOR *TrianglePos2, const VECTOR *TrianglePos3, SEGMENT_TRIANGLE_RESULT *Result ) ;		// 線分と三角?の最接近?情報を解析する
extern	int			Triangle_Point_Analyse(       const VECTOR *TrianglePos1, const VECTOR *TrianglePos2, const VECTOR *TrianglePos3, const VECTOR *PointPos, TRIANGLE_POINT_RESULT *Result ) ;										// 三角?と?の最接近?情報を解析する
extern	int			Plane_Point_Analyse(          const VECTOR *PlanePos, const VECTOR *PlaneNormal, const VECTOR *PointPos, PLANE_POINT_RESULT *Result ) ;																			// 平面と?の最近?情報を解析する

extern	void		TriangleBarycenter(           VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR Position, float *TrianglePos1Weight, float *TrianglePos2Weight, float *TrianglePos3Weight ) ;	// 指定の座標から三角?の重心を求める

extern	float		Segment_Segment_MinLength(          VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;														// 二つの線分の最近?間の距離を得る
extern	float		Segment_Segment_MinLength_Square(   VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;														// 二つの線分の最近?間の距離の二乗を得る
extern	float		Segment_Triangle_MinLength(         VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;									// 線分と三角?の最近?間の距離を得る 
extern	float		Segment_Triangle_MinLength_Square(  VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;									// 線分と三角?の最近?間の距離の二乗を得る 
extern	float		Segment_Point_MinLength(            VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;																					// 線分と?の一番近い距離を得る
extern	float		Segment_Point_MinLength_Square(     VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;																					// 線分と?の一番近い距離の二乗を得る
extern	float		Triangle_Point_MinLength(           VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;															// 三角?と?の一番近い距離を得る
extern	float		Triangle_Point_MinLength_Square(    VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;															// 三角?と?の一番近い距離の二乗を得る
extern	float		Triangle_Triangle_MinLength(        VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;		// 二つの三角?の最近?間の距離を得る
extern	float		Triangle_Triangle_MinLength_Square( VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;		// 二つの三角?の最近?間の距離の二乗を得る
extern	VECTOR		Plane_Point_MinLength_Position(     VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;																					// ?に一番近い平面上の座標を得る
extern	float		Plane_Point_MinLength(              VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;																					// 平面と?の一番近い距離を得る

extern	HITRESULT_LINE HitCheck_Line_Triangle(          VECTOR LinePos1, VECTOR LinePos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;											// 三角?と線の当たり判定
extern	int			HitCheck_Triangle_Triangle(         VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;		// 三角?と三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	HITRESULT_LINE HitCheck_Line_Cube(              VECTOR LinePos1, VECTOR LinePos2, VECTOR CubePos1, VECTOR CubePos2 );																		// 線と箱の当たり判定
extern	int			HitCheck_Line_Sphere(               VECTOR LinePos1, VECTOR LinePos2, VECTOR SphereCenterPos, float SphereR ) ;																	// 線と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Sphere(             VECTOR Sphere1CenterPos, float Sphere1R, VECTOR Sphere2CenterPos, float Sphere2R ) ;														// 球と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Triangle(           VECTOR SphereCenterPos, float SphereR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;									// 球と三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Capsule(           VECTOR Cap1Pos1, VECTOR Cap1Pos2, float Cap1R, VECTOR Cap2Pos1, VECTOR Cap2Pos2, float Cap2R ) ;											// カプセル同士の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Triangle(          VECTOR CapPos1, VECTOR CapPos2, float CapR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;								// カプセルと三角?の当たり判定( TRUE:当たっている  FALSE:当たっていない )

// その他
extern	int			RectClipping( RECT *Rect, const RECT *ClippuRect ) ;						// 矩?のクリッピング
extern	int			RectAdjust(   RECT *Rect ) ;												// 矩?の left が right より値が大きい場合などの誤りを補正する
extern	int			GetRectSize(  const RECT *Rect, int *Width, int *Height ) ;					// 矩?の幅と高さを求める

// ?記簡略版
extern	MATRIX		MGetIdent(     void ) ;														// 単位行列を取得する
extern	MATRIX		MMult(         MATRIX In1, MATRIX In2 ) ;									// 行列の乗算を行う
extern	MATRIX		MScale(        MATRIX InM, float Scale ) ;									// 行列のスケ?リングを行う
extern	MATRIX		MAdd(          MATRIX In1, MATRIX In2 ) ;									// 行列の足し算を行う
extern	MATRIX		MGetScale(     VECTOR Scale ) ;												// 拡大行列を取得する
extern	MATRIX		MGetRotX(      float XAxisRotate ) ;										// Ｘ軸回?行列を取得する
extern	MATRIX		MGetRotY(      float YAxisRotate ) ;										// Ｙ軸回?行列を取得する
extern	MATRIX		MGetRotZ(      float ZAxisRotate ) ;										// Ｚ軸回?行列を取得する
extern	MATRIX		MGetRotAxis(   VECTOR RotateAxis, float Rotate ) ;							// 指定軸で指定角度回?する行列を取得する
extern	MATRIX		MGetRotVec2(   VECTOR In1, VECTOR In2 ) ;									// In1 の向きから In2 の向きへ変換する回?行列を取得する( In2 と In1 が?逆のベクトルの場合は回?軸は不定 )
extern	MATRIX		MGetTranslate( VECTOR Trans ) ;												// 平行移動行列を取得する
extern	MATRIX		MGetAxis1(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 指定の３軸ロ?カルのベクトルを基?軸上のベクトルに変換する行列を取得する( x' = XAxis.x * x + YAixs.x * y + ZAxis.z * z + Pos.x   y' = XAxis.y * x + YAixs.y * y + ZAxis.y * z + Pos.y      z' = XAxis.z * x + YAixs.z * y + ZAxis.z * z + Pos.z )
extern	MATRIX		MGetAxis2(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 基?軸上のベクトルを指定の３軸上に投影したベクトルに変換する行列を取得する( x' = XAxis.x * ( x - Pos.x ) + XAxis.y * ( x - Pos.x ) + XAxis.z * ( x - Pos.x )    y' = YAxis.x * ( x - Pos.x ) + YAxis.y * ( x - Pos.x ) + YAxis.z * ( x - Pos.x )    z' = ZAxis.x * ( x - Pos.x ) + ZAxis.y * ( x - Pos.x ) + ZAxis.z * ( x - Pos.x ) )
extern	MATRIX		MTranspose(    MATRIX InM ) ;												// ?置行列を取得する
extern	MATRIX		MInverse(      MATRIX InM ) ;												// 逆行列を取得する
extern  VECTOR		MGetSize(      MATRIX InM ) ;												// 拡大行列のＸ軸、Ｙ軸、Ｚ軸の拡大率を取得する

// ベクトル値の生成
__inline VECTOR VGet( float x, float y, float z )
{
	VECTOR Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	return Result ;
}

// ４要素ベクトル値の生成
__inline FLOAT4 F4Get( float x, float y, float z, float w )
{
	FLOAT4 Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	Result.w = w ;
	return Result ;
}

// ベクトルの加算
__inline VECTOR		VAdd( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	return Result ;
}

// ベクトルの減算
__inline VECTOR		VSub( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	return Result ;
}

// ４要素ベクトルの加算
__inline FLOAT4		F4Add( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	Result.w = In1.w + In2.w ;
	return Result ;
}

// ４要素ベクトルの減算
__inline FLOAT4		F4Sub( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	Result.w = In1.w - In2.w ;
	return Result ;
}

// ベクトルの内積
__inline float		VDot( const VECTOR &In1, const VECTOR &In2 )
{
	return In1.x * In2.x + In1.y * In2.y + In1.z * In2.z ;
}

// ベクトルの外積
__inline VECTOR		VCross( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.y * In2.z - In1.z * In2.y ;
	Result.y = In1.z * In2.x - In1.x * In2.z ;
	Result.z = In1.x * In2.y - In1.y * In2.x ;
	return Result ;
}

// ベクトルのスケ?リング
__inline VECTOR		VScale( const VECTOR &In, float Scale )
{
	VECTOR Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	return Result ;
}

// ４要素ベクトルのスケ?リング
__inline FLOAT4		F4Scale( const FLOAT4 &In, float Scale )
{
	FLOAT4 Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	Result.w = In.w * Scale ;
	return Result ;
}

// ベクトルの正規化
extern VECTOR		VNorm( VECTOR In ) ;

// ベクトルのサイズ
extern float		VSize( VECTOR In ) ;

// ベクトルのサイズの２乗
__inline float		VSquareSize( const VECTOR &In )
{
	return In.x * In.x + In.y * In.y + In.z * In.z ;
}

// 行列を使った座標変換
__inline VECTOR		VTransform( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] + InM.m[3][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] + InM.m[3][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] + InM.m[3][2] ;
	return Result ;
}

// 行列を使った座標変換( スケ?リング?回?成分のみ )
__inline VECTOR		VTransformSR( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] ;
	return Result ;
}

// 二つのベクトルが成す角のコサイン値を得る
extern	float		VCos( VECTOR In1, VECTOR In2 ) ;

// 二つのベクトルが成す角の角度を得る( 単位：ラジアン )
extern	float		VRad( VECTOR In1, VECTOR In2 ) ;








// DxBaseImage.cpp 関数プロト?イプ宣言

// 基?イメ?ジデ??のロ?ド?ＤＩＢ関係
extern	int			CreateGraphImageOrDIBGraph(    const TCHAR *FileName, const void *DataImage, int DataImageSize, int DataImageType /* LOADIMAGE_TYPE_FILE 等 */ , int BmpFlag, int ReverseFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ;					// 画像フ?イル若しくはメモリ上に展開された画像フ?イルイメ?ジを読み込み、基?イメ?ジデ??若しくはＢＭＰデ??を?築する
extern	int			CreateGraphImageType2(         STREAMDATA *Src, BASEIMAGE *Dest ) ;																																															// 画像デ??から?築したストリ??読み込み用デ??を使用して基?イメ?ジデ??を?築する
extern	int			CreateBmpInfo(                 BITMAPINFO *BmpInfo, int Width, int Height, int Pitch, const void *SrcGrData, void **DestGrData ) ;																															// 24bitカラ??式のビット?ップデ??からＢＭＰデ??を?築する
extern	DWORD		GetGraphImageFullColorCode(    const BASEIMAGE *GraphImage, int x, int y ) ;																																												// 基?イメ?ジデ??の指定座標のフルカラ?コ?ドを取得する
extern	int			CreateGraphImage_plus_Alpha(   const TCHAR *FileName, const void *RgbImage, int RgbImageSize, int RgbImageType, const void *AlphaImage, int AlphaImageSize, int AlphaImageType, BASEIMAGE *RgbGraphImage, BASEIMAGE *AlphaGraphImage, int ReverseFlag ) ;	// 画像フ?イル若しくはメモリ上に展開された画像フ?イルイメ?ジを読み込み、基?イメ?ジデ??を?築する
extern	int			ReverseGraphImage(             BASEIMAGE *GraphImage ) ;																																																	// 基?イメ?ジデ??を左右反?する
#ifdef __WINDOWS__
extern	HBITMAP		CreateDIBGraph(                const TCHAR *FileName,                                                                                                                                        int ReverseFlag,          COLORDATA *SrcColor ) ;					// 画像フ?イルからＤＩＢデ??を作成する
extern	HBITMAP		CreateDIBGraphToMem(           const BITMAPINFO *BmpInfo, const void *GraphData,                                                                                                             int ReverseFlag,          COLORDATA *SrcColor ) ;					// ＢＭＰデ??からＤＩＢデ??クを作成する
extern	int			CreateDIBGraph_plus_Alpha(     const TCHAR *FileName, HBITMAP *RGBBmp, HBITMAP *AlphaBmp,                                                                                                    int ReverseFlag = FALSE , COLORDATA *SrcColor = NULL ) ;				// 画像フ?イルからＤＩＢデ??と?スク用ＤＩＢデ??を作成する
extern	HBITMAP		CreateDIBGraphVer2(            const TCHAR *FileName, const void *MemImage, int MemImageSize,                                             int ImageType,                                     int ReverseFlag,          COLORDATA *SrcColor ) ;					// 画像フ?イル若しくはメモリ上に展開された画像フ?イルイメ?ジからＤＩＢデ??を作成する
extern	int			CreateDIBGraphVer2_plus_Alpha( const TCHAR *FileName, const void *MemImage, int MemImageSize, const void *AlphaImage, int AlphaImageSize, int ImageType, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag,          COLORDATA *SrcColor ) ;					// 画像フ?イル若しくはメモリ上に展開された画像フ?イルイメ?ジからＤＩＢデ??と?スク用ＤＩＢデ??を作成する
extern	int			ConvBitmapToGraphImage(        const BITMAPINFO *BmpInfo, void *GraphData, BASEIMAGE *GraphImage, int CopyFlag ) ;																																			// ＢＭＰデ??から基?イメ?ジデ??を?築する( Ret 0:正常終了  1:コピ?を行った  -1:エラ? )
extern	int			ConvGraphImageToBitmap(        const BASEIMAGE *GraphImage, BITMAPINFO *BmpInfo, void **GraphData, int CopyFlag, int FullColorConv = TRUE ) ;																												// 基?イメ?ジデ??をＢＭＰデ??に変換するGraphImage を ＢＭＰ に変換する(アルフ?デ??はあっても無視される)( 戻り値?0:正常終了  1:コピ?を行った  -1:エラ? )
#endif // __WINDOWS__

//extern int		AddUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユ?ザ?定?の画像デ??読み込み関数を登?する
//extern int		AddUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユ?ザ?定?の画像デ??読み込み関数を登?する
//extern int		AddUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユ?ザ?定?の画像デ??読み込み関数Ver3を登?する
extern	int			AddUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユ?ザ?定?の画像デ??読み込み関数Ver4を登?する
//extern int		SubUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユ?ザ?定?の画像デ??読み込み関数を登?から抹消する
//extern int		SubUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユ?ザ?定?の画像デ??読み込み関数を登?から抹消する
//extern int		SubUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユ?ザ?定?の画像デ??読み込み関数Ver3を登?から抹消する
extern	int			SubUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユ?ザ?定?の画像デ??読み込み関数Ver4を登?から抹消する

extern	int			SetUseFastLoadFlag(            int Flag ) ;														// 高速読み込みル??ンを使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetGraphDataShavedMode(        int ShavedMode /* DX_SHAVEDMODE_NONE 等 */ ) ;					// 画像減色時の画像劣化緩和処理モ?ドを設定する( デフォルトでは緩和処理無しの DX_SHAVEDMODE_NONE )
extern	int			GetGraphDataShavedMode(        void ) ;															// 画像減色時の画像劣化緩和処理モ?ドを取得する
extern	int			SetUsePremulAlphaConvertLoad(  int UseFlag ) ;													// 画像フ?イル読み込み時に乗算済みアルフ?画像に変換するかどうかを設定する( TRUE:変換処理を行う  FALSE:変換処理を行わない( デフォルト ) )

// 基?イメ?ジデ???造体関係
extern	int			CreateBaseImage(               const TCHAR *FileName, const void *FileImage, int FileImageSize, int DataType /*=LOADIMAGE_TYPE_FILE*/ , BASEIMAGE *BaseImage,  int ReverseFlag ) ;			// 画像フ?イル若しくはメモリ上に展開された画像フ?イルイメ?ジから基?イメ?ジデ??を?築する
extern	int			CreateGraphImage(              const TCHAR *FileName, const void *DataImage, int DataImageSize, int DataImageType,                      BASEIMAGE *GraphImage, int ReverseFlag ) ;			// CreateBaseImage の旧名称
extern	int			CreateBaseImageToFile(         const TCHAR *FileName,                                                                                   BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// 画像フ?イルから基?イメ?ジデ??を?築する
extern	int			CreateBaseImageToMem(                                 const void *FileImage, int FileImageSize,                                         BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// メモリ上に展開された画像フ?イルイメ?ジから基?イメ?ジデ??を?築する
extern	int			CreateARGB8ColorBaseImage(     int SizeX, int SizeY,                             BASEIMAGE *BaseImage ) ;																					// ?ＲＧＢ８カラ?の基?イメ?ジデ??を作成する
extern	int			CreateXRGB8ColorBaseImage(     int SizeX, int SizeY,                             BASEIMAGE *BaseImage ) ;																					// ＸＲＧＢ８カラ?の基?イメ?ジデ??を作成する
extern	int			CreateRGB8ColorBaseImage(      int SizeX, int SizeY,                             BASEIMAGE *BaseImage ) ;																					// ＲＧＢ８カラ?の基?イメ?ジデ??を作成する
extern	int			CreateARGB4ColorBaseImage(     int SizeX, int SizeY,                             BASEIMAGE *BaseImage ) ;																					// ?ＲＧＢ４カラ?の基?イメ?ジデ??を作成する
extern	int			CreatePAL8ColorBaseImage(      int SizeX, int SizeY,                             BASEIMAGE *BaseImage ) ;																					// パレット８ビットカラ?の基?イメ?ジデ??を作成する
extern	int			CreateColorDataBaseImage(      int SizeX, int SizeY, const COLORDATA *ColorData, BASEIMAGE *BaseImage ) ;																					// 指定のカラ?フォ??ットの基?イメ?ジデ??を作成する
extern	int			GetBaseImageGraphDataSize(     const BASEIMAGE *BaseImage ) ;																																// 基?イメ?ジデ??のイメ?ジサイズを取得する( 単位：byte )
extern	int			DerivationBaseImage(           const BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, BASEIMAGE *NewBaseImage ) ;																		// 基?イメ?ジデ??の指定の部分だけを使う基?イメ?ジデ??の情報を作成する( BaseImage にはフォ??ットが DX_BASEIMAGE_FORMAT_NORMAL で?ップ?ップを使用していない画像のみ使用可? )

extern	int			ReleaseBaseImage(              BASEIMAGE *BaseImage ) ;																																		// 基?イメ?ジデ??の後始末を行う
extern	int			ReleaseGraphImage(             BASEIMAGE *GraphImage ) ;																																	// ReleaseBaseImage の旧名称

extern	int			ConvertNormalFormatBaseImage(  BASEIMAGE *BaseImage ) ;																																		// DX_BASEIMAGE_FORMAT_NORMAL 以外の?式のイメ?ジを DX_BASEIMAGE_FORMAT_NORMAL ?式のイメ?ジに変換する
extern	int			ConvertPremulAlphaBaseImage(   BASEIMAGE *BaseImage ) ;																																		// 通常のα?ャンネル付き画像を乗算済みα?ャンネル付き画像に変換する( ピクセルフォ??ットが ARGB8 以外の場合は ARGB8 に変換されます )
extern	int			ConvertInterpAlphaBaseImage(   BASEIMAGE *BaseImage ) ;																																		// 乗算済みα?ャンネル付き画像を通常のα?ャンネル付き画像に変換する( ピクセルフォ??ットが ARGB8 以外の場合は ARGB8 に変換されます )

extern	int			GetDrawScreenBaseImage(        int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage ) ;																										// ?画対象の画面から指定領域を基?イメ?ジデ??に?送する
extern	int			GetDrawScreenBaseImageDestPos( int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage, int DestX, int DestY ) ;																				// ?画対象の画面から指定領域を基?イメ?ジデ??に?送する( ?送先座標指定版 )
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForBaseImage(                       const BASEIMAGE *BaseImage ) ;																										// 基?イメ?ジデ??を使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForBaseImageRect(                   const BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2 ) ;																		// 基?イメ?ジデ??の指定の範囲を使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForPremultipliedAlphaBaseImage(     const BASEIMAGE *BaseImage ) ;																										// 乗算済みアルフ?の基?イメ?ジデ??を使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForPremultipliedAlphaBaseImageRect( const BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2 ) ;																		// 乗算済みアルフ?の基?イメ?ジデ??の指定の範囲を使用して UpdateLayerdWindow を行う
#endif // __WINDOWS__
extern	int			FillBaseImage(                       BASEIMAGE *BaseImage, int r, int g, int b, int a ) ;																											// 基?イメ?ジデ??を指定の色で塗りつぶす
extern	int			FillRectBaseImage(                   BASEIMAGE *BaseImage, int x, int y, int w, int h, int r, int g, int b, int a ) ;																				// 基?イメ?ジデ??の指定の領域を指定の色で塗りつぶす
extern	int			ClearRectBaseImage(                  BASEIMAGE *BaseImage, int x, int y, int w, int h ) ;																											// 基?イメ?ジデ??の指定の領域を０クリアする
extern	int			GetPaletteBaseImage(           const BASEIMAGE *BaseImage, int PaletteNo, int *r, int *g, int *b, int *a ) ;																						// 基?イメ?ジデ??のパレットを取得する
extern	int			SetPaletteBaseImage(                 BASEIMAGE *BaseImage, int PaletteNo, int  r, int  g, int  b, int  a ) ;																						// 基?イメ?ジデ??のパレットをセットする
extern	int			SetPixelPalCodeBaseImage(            BASEIMAGE *BaseImage, int x, int y, int palNo ) ;																												// 基?イメ?ジデ??の指定の座標の色コ?ドを変更する(パレット画像用)
extern	int			GetPixelPalCodeBaseImage(      const BASEIMAGE *BaseImage, int x, int y ) ;																															// 基?イメ?ジデ??の指定の座標の色コ?ドを取得する(パレット画像用)
extern	int			SetPixelBaseImage(                   BASEIMAGE *BaseImage, int x, int y, int  r, int  g, int  b, int  a ) ;																							// 基?イメ?ジデ??の指定の座標の色を変更する(各色要素は０?２５５)
extern	int			GetPixelBaseImage(                   BASEIMAGE *BaseImage, int x, int y, int *r, int *g, int *b, int *a ) ;																							// 基?イメ?ジデ??の指定の座標の色を取得する(各色要素は０?２５５)
extern	int			DrawLineBaseImage(                   BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;																			// 基?イメ?ジデ??の指定の座標に線を?画する(各色要素は０?２５５)
extern	int			BltBaseImage(                        int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;									// 基?イメ?ジデ??を別の基?イメ?ジデ??に?送する
extern	int			BltBaseImage(                                                                        int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;									// 基?イメ?ジデ??を別の基?イメ?ジデ??に?送する
extern	int			BltBaseImageWithTransColor(          int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Tr, int Tg, int Tb, int Ta ) ;	// 基?イメ?ジデ??を別の基?イメ?ジデ??に透過色処理付きで?送する
extern	int			BltBaseImageWithAlphaBlend(          int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Opacity = 255 ) ;					// 基?イメ?ジデ??を別の基?イメ?ジデ??にアルフ?値のブレンドを考慮した上で?送する( Opacity は透明度 : 0( 完全透明 ) ? 255( 完全不透明 ) )( 出力先が ARGB8 ?式以外の場合はエラ?になります )
extern	int			ReverseBaseImageH(                   BASEIMAGE *BaseImage ) ;																																		// 基?イメ?ジデ??を左右反?する
extern	int			ReverseBaseImageV(                   BASEIMAGE *BaseImage ) ;																																		// 基?イメ?ジデ??を上下反?する
extern	int			ReverseBaseImage(                    BASEIMAGE *BaseImage ) ;																																		// 基?イメ?ジデ??を上下左右反?する
extern	int			CheckPixelAlphaBaseImage(      const BASEIMAGE *BaseImage ) ;																																		// 基?イメ?ジデ??に含まれるピクセルのアルフ?値を?ェックする( 戻り値   -1:エラ?  0:画像にアルフ?成分が無い  1:画像にアルフ?成分があり、すべて最大(255)値  2:画像にアルフ?成分があり、存在するアルフ?値は最小(0)と最大(255)もしくは最小(0)のみ?3:画像にアルフ?成分があり、最小と最大以外の中間の値がある )  

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveBaseImageToBmp(            const TCHAR *FilePath, const BASEIMAGE *BaseImage ) ;																										// 基?イメ?ジデ??をＢＭＰ画像として保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveBaseImageToPng(            const TCHAR *FilePath,       BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// 基?イメ?ジデ??をＰＮＧ画像として保存する
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveBaseImageToJpeg(           const TCHAR *FilePath,       BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																			// 基?イメ?ジデ??をＪＰＥＧ画像として保存する
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

// 基?イメ?ジ?画
extern	int			DrawBaseImage(					int x, int y, BASEIMAGE *BaseImage ) ;																														// 基?イメ?ジデ??を?画する

// カラ??ッ?ングしながらイメ?ジデ??間?送を行う Ver2
extern int			GraphColorMatchBltVer2(       void *DestGraphData, int DestPitch,  const COLORDATA *DestColorData,
											const void *SrcGraphData,  int SrcPitch,   const COLORDATA *SrcColorData,
											const void *AlphaMask,     int AlphaPitch, const COLORDATA *AlphaColorData,
											POINT DestPoint, const RECT *SrcRect, int ReverseFlag,
											int TransColorAlphaTestFlag, unsigned int TransColor,
											int ImageShavedMode, int AlphaOnlyFlag = FALSE ,
											int RedIsAlphaFlag = FALSE , int TransColorNoMoveFlag = FALSE ,
											int Pal8ColorMatch = FALSE ) ;


// 色情報取得関係
extern	COLOR_F		GetColorF(              float Red, float Green, float Blue, float Alpha ) ;												// 浮動小数??のカラ?値を作成する
extern	COLOR_U8	GetColorU8(             int Red, int Green, int Blue, int Alpha ) ;														// 符号なし整数８ビットのカラ?値を作成する
extern	DWORD		GetColor(               int Red, int Green, int Blue ) ;																// ３原色の値から現在の画面モ?ドに対応したカラ?値を得る
extern	int			GetColor2(              int Color, int *Red, int *Green, int *Blue ) ;													// 画面モ?ドに対応したカラ?値から個々の３原色の値を抜き出す
extern	int			GetColor3(              const COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255 ) ;					// ３原色の値から指定のピクセルフォ??ットに対応したカラ?値を得る
extern	int			GetColor4(              const COLORDATA *DestColorData, const COLORDATA* SrcColorData, int SrcColor ) ;					// 指定のカラ?フォ??ットのカラ?値を別のカラ?フォ??ットのカラ?値に変換する
extern	int			GetColor5(              const COLORDATA *ColorData, int Color, int *Red, int *Green, int *Blue, int *Alpha = NULL ) ;	// 指定のカラ?フォ??ットのカラ?値を３原色の値に変換する
extern	int			CreatePaletteColorData( COLORDATA *ColorDataBuf ) ;																		// パレットカラ?のカラ?フォ??ットを?築する
extern	int			CreateXRGB8ColorData(   COLORDATA *ColorDataBuf ) ;																		// ＸＲＧＢ８カラ?のカラ?フォ??ットを?築する
extern	int			CreateARGB8ColorData(   COLORDATA *ColorDataBuf ) ;																		// ?ＲＧＢ８カラ?のカラ?フォ??ットを?築する
extern	int			CreateARGB4ColorData(   COLORDATA *ColorDataBuf ) ;																		// ?ＲＧＢ４カラ?のカラ?フォ??ットを?築する
extern	int			CreateFullColorData(    COLORDATA *ColorDataBuf ) ;																		// ２４ビットカラ?のカラ?フォ??ットを?築する
extern	int			CreateGrayColorData(    COLORDATA *ColorDataBuf ) ;																		// グレ?スケ?ルのカラ?フォ??ットを?築する
extern	int			CreatePal8ColorData(    COLORDATA *ColorDataBuf ) ;																		// パレット２５６色のカラ?フォ??ットを?築する
extern	int			CreateColorData(        COLORDATA *ColorDataBuf, int ColorBitDepth,
									        DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask,
									        int ChannelNum = 0, int ChannelBitDepth = 0, int FloatTypeFlag = FALSE ) ;						// カラ?フォ??ットを作成する
extern	void		SetColorDataNoneMask(   COLORDATA *ColorData ) ;																		// NoneMask 以外の要素を埋めた COLORDATA ?造体の情報を元に NoneMask をセットする
extern	int			CmpColorData(           const COLORDATA *ColorData1, const COLORDATA *ColorData2 ) ;									// 二つのカラ?フォ??ットが等しいかどうか調べる( 戻り値?TRUE:等しい  FALSE:等しくない )

#endif // DX_NOTUSE_DRAWFUNCTION













// DxSoftImage.cpp関数プロト?イプ宣言
#ifndef DX_NON_SOFTIMAGE
extern	int			InitSoftImage(                   void ) ;																			// ?フトウエアイメ?ジハンドルを全て削除する
extern	int			LoadSoftImage(                   const TCHAR *FileName ) ;															// 画像フ?イルを読み込み?フトウエアイメ?ジハンドルを作成する( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			LoadSoftImageToMem(              const void *FileImage, int FileImageSize ) ;										// メモリ上に展開された画像フ?イルイメ?ジから?フトウエアイメ?ジハンドルを作成する( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			MakeSoftImage(                   int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( -1:エラ?  -1以外:イメ?ジハンドル )
extern	int			MakeARGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( RGBA8 カラ? )
extern	int			MakeXRGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( XRGB8 カラ? )
extern	int			MakeARGB4ColorSoftImage(         int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( ARGB4 カラ? )
extern	int			MakeRGB8ColorSoftImage(          int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( RGB8 カラ? )
extern	int			MakePAL8ColorSoftImage(          int SizeX, int SizeY ) ;															// ?フトウエアイメ?ジハンドルの作成( パレット２５６色 カラ? )

extern	int			DeleteSoftImage(                 int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルの削除する

extern	int			GetSoftImageSize(                int SIHandle, int *Width, int *Height ) ;											// ?フトウエアイメ?ジハンドルのサイズを取得する
extern	int			CheckPaletteSoftImage(           int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルがパレット画像かどうかを取得する( TRUE:パレット画像  FALSE:パレット画像じゃない )
extern	int			CheckAlphaSoftImage(             int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルのフォ??ットにα要素があるかどうかを取得する( TRUE:ある  FALSE:ない )
extern	int			CheckPixelAlphaSoftImage(        int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルに含まれるピクセルのα値を?ェックする( 戻り値   -1:エラ?  0:画像にα成分が無い  1:画像にα成分があり、すべて最大(255)値  2:画像にα成分があり、存在するα値は最小(0)と最大(255)もしくは最小(0)のみ?3:画像にα成分があり、最小と最大以外の中間の値がある )  

extern	int			GetDrawScreenSoftImage(          int x1, int y1, int x2, int y2, int SIHandle ) ;									// ?画対象の画面から指定領域を?フトウエアイメ?ジハンドルに?送する
extern	int			GetDrawScreenSoftImageDestPos(   int x1, int y1, int x2, int y2, int SIHandle, int DestX, int DestY ) ;				// ?画対象の画面から指定領域を?フトウエアイメ?ジハンドルに?送する( ?送先座標指定版 )
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForSoftImage(                       int SIHandle ) ;												// ?フトウエアイメ?ジハンドルを使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForSoftImageRect(                   int SIHandle, int x1, int y1, int x2, int y2 ) ;				// ?フトウエアイメ?ジハンドルの指定の範囲を使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForPremultipliedAlphaSoftImage(     int SIHandle ) ;												// 乗算済みアルフ?の?フトウエアイメ?ジハンドルを使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForPremultipliedAlphaSoftImageRect( int SIHandle, int x1, int y1, int x2, int y2 ) ;				// 乗算済みアルフ?の?フトウエアイメ?ジハンドルの指定の範囲を使用して UpdateLayerdWindow を行う
#endif // __WINDOWS__
extern	int			FillSoftImage(                   int SIHandle, int r, int g, int b, int a ) ;										// ?フトウエアイメ?ジハンドルを指定色で塗りつぶす(各色要素は０?２５５)
extern	int			ClearRectSoftImage(              int SIHandle, int x, int y, int w, int h ) ;										// ?フトウエアイメ?ジハンドルの指定の領域を０クリアする
extern	int			GetPaletteSoftImage(             int SIHandle, int PaletteNo, int *r, int *g, int *b, int *a ) ;					// ?フトウエアイメ?ジハンドルのパレットを取得する(各色要素は０?２５５)
extern	int			SetPaletteSoftImage(             int SIHandle, int PaletteNo, int  r, int  g, int  b, int  a ) ;					// ?フトウエアイメ?ジハンドルのパレットを設定する(各色要素は０?２５５)
extern	int			DrawPixelPalCodeSoftImage(       int SIHandle, int x, int y, int palNo ) ;											// ?フトウエアイメ?ジハンドルの指定座標にドットを?画する(パレット画像用、有効値は０?２５５)
extern	int			GetPixelPalCodeSoftImage(        int SIHandle, int x, int y ) ;														// ?フトウエアイメ?ジハンドルの指定座標の色コ?ドを取得する(パレット画像用、戻り値は０?２５５)
extern	void		*GetImageAddressSoftImage(       int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルの画像が格?されているメモリ領域の先頭アドレスを取得する
extern	int			GetPitchSoftImage(               int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルのメモリに格?されている画像デ??の1ライン辺りのバイト数を取得する
extern	int			DrawPixelSoftImage(              int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// ?フトウエアイメ?ジハンドルの指定座標にドットを?画する(各色要素は０?２５５)
extern	void		DrawPixelSoftImage_Unsafe_XRGB8( int SIHandle, int x, int y, int  r, int  g, int  b ) ;								// ?フトウエアイメ?ジハンドルの指定座標にドットを?画する(各色要素は０?２５５)、エラ??ェックをしない代わりに高速ですが、範囲外の座標や ARGB8 以外のフォ??ットの?フトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	void		DrawPixelSoftImage_Unsafe_ARGB8( int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// ?フトウエアイメ?ジハンドルの指定座標にドットを?画する(各色要素は０?２５５)、エラ??ェックをしない代わりに高速ですが、範囲外の座標や XRGB8 以外のフォ??ットの?フトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	int			GetPixelSoftImage(               int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// ?フトウエアイメ?ジハンドルの指定座標の色を取得する(各色要素は０?２５５)
extern	void		GetPixelSoftImage_Unsafe_XRGB8(  int SIHandle, int x, int y, int *r, int *g, int *b ) ;								// ?フトウエアイメ?ジハンドルの指定座標の色を取得する(各色要素は０?２５５)、エラ??ェックをしない代わりに高速ですが、範囲外の座標や XRGB8 以外のフォ??ットの?フトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	void		GetPixelSoftImage_Unsafe_ARGB8(  int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// ?フトウエアイメ?ジハンドルの指定座標の色を取得する(各色要素は０?２５５)、エラ??ェックをしない代わりに高速ですが、範囲外の座標や ARGB8 以外のフォ??ットの?フトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	int			DrawLineSoftImage(               int SIHandle, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;		// ?フトウエアイメ?ジハンドルの指定座標に線を?画する(各色要素は０?２５５)
extern	int			BltSoftImage(                    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle ) ;									// ?フトウエアイメ?ジハンドルを別の?フトウエアイメ?ジハンドルに?送する
extern	int			BltSoftImageWithTransColor(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Tr, int Tg, int Tb, int Ta ) ;	// ?フトウエアイメ?ジハンドルを別の?フトウエアイメ?ジハンドルに透過色処理付きで?送する
extern	int			BltSoftImageWithAlphaBlend(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Opacity = 255 ) ;					// ?フトウエアイメ?ジハンドルを別の?フトウエアイメ?ジハンドルにアルフ?値のブレンドを考慮した上で?送する( Opacity は透明度 : 0( 完全透明 ) ? 255( 完全不透明 ) )( 出力先が ARGB8 ?式以外の場合はエラ?になります )
extern	int			ReverseSoftImageH(               int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルを左右反?する
extern	int			ReverseSoftImageV(               int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルを上下反?する
extern	int			ReverseSoftImage(                int SIHandle ) ;																	// ?フトウエアイメ?ジハンドルを上下左右反?する

#ifndef DX_NON_FONT
extern	int			BltStringSoftImage(              int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle = -1 ,                                        int VerticalFlag = FALSE ) ;		// ?フトウエアイメ?ジハンドルに文字列を?画する( デフォルトフォントハンドルを使用する )
extern	int			BltStringSoftImageToHandle(      int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle /* 縁が必要ない場合は -1 */ , int FontHandle, int VerticalFlag = FALSE ) ;		// ?フトウエアイメ?ジハンドルに文字列を?画する( フォントハンドル使用版 )
#endif // DX_NON_FONT

extern	int			DrawSoftImage(                   int x, int y, int SIHandle ) ;														// ?フトウエアイメ?ジハンドルを画面に?画する

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveSoftImageToBmp(              const TCHAR *FilePath, int SIHandle ) ;											// ?フトウエアイメ?ジハンドルをＢＭＰ画像フ?イルとして保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveSoftImageToPng(              const TCHAR *FilePath, int SIHandle, int CompressionLevel ) ;						// ?フトウエアイメ?ジハンドルをＰＮＧ画像フ?イルとして保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0?9
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveSoftImageToJpeg(             const TCHAR *FilePath, int SIHandle, int Quality, int Sample2x1 ) ;				// ?フトウエアイメ?ジハンドルをＪＰＥＧ画像フ?イルとして保存する Quality = 画質、値が大きいほど低圧縮高画質,0?100 
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

#endif // DX_NON_SOFTIMAGE


















#ifndef DX_NON_SOUND

// DxSound.cpp関数プロト?イプ宣言

// サウンドデ??管理系関数
extern	int			InitSoundMem(                        int LogOutFlag = FALSE ) ;																	// 全てのサウンドハンドルを削除する

extern	int			AddSoundData(                        int Handle = -1 ) ;																										// サウンドハンドルを作成する
extern	int			AddStreamSoundMem(                   STREAMDATA *Stream, int LoopNum,  int SoundHandle, int StreamDataType, int *CanStreamCloseFlag, int UnionHandle = -1 ) ;	// ストリ??再生?イプのサウンドハンドルにストリ??デ??を再生対象に追加する
extern	int			AddStreamSoundMemToMem(              const void *FileImage, int FileImageSize, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;		// ストリ??再生?イプのサウンドハンドルにメモリ上に展開したサウンドフ?イルイメ?ジを再生対象に追加する
extern	int			AddStreamSoundMemToFile(             const TCHAR *WaveFile, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;							// ストリ??再生?イプのサウンドハンドルにサウンドフ?イルを再生対象に追加する
extern	int			SetupStreamSoundMem(                 int SoundHandle ) ;																		// ストリ??再生?イプのサウンドハンドルの再生?備をする
extern	int			PlayStreamSoundMem(                  int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP , int TopPositionFlag = TRUE ) ;			// ストリ??再生?イプのサウンドハンドルの再生を開始する
extern	int			CheckStreamSoundMem(                 int SoundHandle ) ;																		// ストリ??再生?イプのサウンドハンドルの再生状態を取得する
extern	int			StopStreamSoundMem(                  int SoundHandle ) ;																		// ストリ??再生?イプのサウンドハンドルの再生を停?する
extern	int			SetStreamSoundCurrentPosition(       int Byte, int SoundHandle ) ;																// サウンドハンドルの再生位置をバイト単位で変更する(再生が?まっている時のみ有効)
extern	int			GetStreamSoundCurrentPosition(       int SoundHandle ) ;																		// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetStreamSoundCurrentTime(           int Time, int SoundHandle ) ;																// サウンドハンドルの再生位置を?リ秒単位で設定する(圧縮?式の場合は正しく設定されない場合がある)
extern	int			GetStreamSoundCurrentTime(           int SoundHandle ) ;																		// サウンドハンドルの再生位置を?リ秒単位で取得する(圧縮?式の場合は正しい値が返ってこない場合がある)
extern	int			ProcessStreamSoundMem(               int SoundHandle ) ;																		// ストリ??再生?イプのサウンドハンドルの周期的な処理を行う関数( 内部で自動的に呼ばれます )
extern	int			ProcessStreamSoundMemAll(            void ) ;																					// 有効なストリ??再生?イプのサウンドハンドルに対して ProcessStreamSoundMem を実行する( 内部で自動的に呼ばれます )


extern	int			LoadSoundMem2(                       const TCHAR *FileName1, const TCHAR *FileName2 ) ;											// 前奏部とル?プ部に分かれたサウンドフ?イルを読み込みサウンドハンドルを作成する
extern	int			LoadBGM(                             const TCHAR *FileName ) ;																	// 主にＢＧＭを読み込みサウンドハンドルを作成するのに適した関数

extern	int			LoadSoundMemBase(                    const TCHAR *FileName, int BufferNum,      int UnionHandle = -1 ) ;						// サウンドフ?イルからサウンドハンドルを作成する
extern	int			LoadSoundMem(                        const TCHAR *FileName, int BufferNum = 3 , int UnionHandle = -1 ) ;						// LoadSoundMemBase の別名関数
extern	int			LoadSoundMemToBufNumSitei(           const TCHAR *FileName, int BufferNum ) ;													// LoadSoundMem を使用して下さい
extern	int			LoadSoundMemByResource(              const TCHAR *ResourceName, const TCHAR *ResourceType, int BufferNum = 1 ) ;				// サウンドリ??スからサウンドハンドルを作成する
extern	int			DuplicateSoundMem(                   int SrcSoundHandle, int BufferNum = 3 ) ;													// 同じサウンドデ??を使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS ?イプのサウンドハンドルのみ可? )

extern	int			LoadSoundMemByMemImageBase(          const void *FileImage, int FileImageSize, int BufferNum, int UnionHandle = -1 ) ;			// メモリ上に展開されたサウンドフ?イルイメ?ジからサウンドハンドルを作成する
extern	int			LoadSoundMemByMemImage(              const void *FileImage, int FileImageSize,                int UnionHandle = -1 ) ;			// メモリ上に展開されたサウンドフ?イルイメ?ジからサウンドハンドルを作成する( バッフ?数指定無し )
extern	int			LoadSoundMemByMemImage2(             const void *WaveImage, int WaveImageSize, const WAVEFORMATEX *WaveFormat, int WaveHeaderSize ) ;	// メモリ上に展開されたＰＣＭデ??からサウンドハンドルを作成する
extern	int			LoadSoundMemByMemImageToBufNumSitei( const void *FileImage, int FileImageSize, int BufferNum ) ;								// LoadSoundMemByMemImageBase を使用して下さい
extern	int			LoadSoundMem2ByMemImage(             const void *FileImage1, int FileImageSize1, const void *FileImage2, int FileImageSize2 ) ;	// 前奏部とル?プ部に分かれた二つのメモリ上に展開されたサウンドフ?イルイメ?ジからサウンドハンドルを作成する
extern	int			LoadSoundMemFromSoftSound(           int SoftSoundHandle, int BufferNum = 3 ) ;													// ?フトウエアサウンドハンドルが持つサウンドデ??からサウンドハンドルを作成する

extern	int			DeleteSoundMem(                      int SoundHandle, int LogOutFlag = FALSE ) ;												// サウンドハンドルを削除する

extern	int			PlaySoundMem(                        int SoundHandle, int PlayType, int TopPositionFlag = TRUE ) ;								// サウンドハンドルを再生する
extern	int			StopSoundMem(                                                                        int SoundHandle ) ;						// サウンドハンドルの再生を停?する
extern	int			CheckSoundMem(                                                                       int SoundHandle ) ;						// サウンドハンドルが再生中かどうかを取得する
extern	int			SetPanSoundMem(                      int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルのパンを設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangePanSoundMem(                   int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルのパンを設定する( -255 ? 255 )
extern	int			GetPanSoundMem(                                                                      int SoundHandle ) ;						// サウンドハンドルのパンを取得する
extern	int			SetVolumeSoundMem(                   int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの?リュ??を設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangeVolumeSoundMem(                int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの?リュ??を設定する( 0 ? 255 )
extern	int			GetVolumeSoundMem(                                                                   int SoundHandle ) ;						// サウンドハンドルの?リュ??を取得する
extern	int			SetChannelVolumeSoundMem(            int Channel, int VolumePal,                     int SoundHandle ) ;						// サウンドハンドルの指定の?ャンネルの?リュ??を設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangeChannelVolumeSoundMem(         int Channel, int VolumePal,                     int SoundHandle ) ;						// サウンドハンドルの指定の?ャンネルの?リュ??を設定する( 0 ? 255 )
extern	int			GetChannelVolumeSoundMem(            int Channel,                                    int SoundHandle ) ;						// サウンドハンドルの指定の?ャンネルの?リュ??を取得する
extern	int			SetFrequencySoundMem(                int FrequencyPal,                               int SoundHandle ) ;						// サウンドハンドルの再生周波数を設定する
extern	int			GetFrequencySoundMem(                                                                int SoundHandle ) ;						// サウンドハンドルの再生周波数を取得する
extern	int			ResetFrequencySoundMem(                                                              int SoundHandle ) ;						// サウンドハンドルの再生周波数を読み込み直後の状態に戻す

extern	int			SetNextPlayPanSoundMem(              int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用するパンを設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangeNextPlayPanSoundMem(           int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用するパンを設定する( -255 ? 255 )
extern	int			SetNextPlayVolumeSoundMem(           int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する?リュ??を設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangeNextPlayVolumeSoundMem(        int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する?リュ??を設定する( 0 ? 255 )
extern	int			SetNextPlayChannelVolumeSoundMem(    int Channel, int VolumePal,                     int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する?ャンネルの?リュ??を設定する( 100分の1デシベル単位 0 ? 10000 )
extern	int			ChangeNextPlayChannelVolumeSoundMem( int Channel, int VolumePal,                     int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する?ャンネルの?リュ??を設定する( 0 ? 255 )
extern	int			SetNextPlayFrequencySoundMem(        int FrequencyPal,                               int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する再生周波数を設定する

extern	int			SetCurrentPositionSoundMem(          int SamplePosition,                             int SoundHandle ) ;						// サウンドハンドルの再生位置をサンプル単位で設定する(再生が?まっている時のみ有効)
extern	int			GetCurrentPositionSoundMem(                                                          int SoundHandle ) ;						// サウンドハンドルの再生位置をサンプル単位で取得する
extern	int			SetSoundCurrentPosition(             int Byte,                                       int SoundHandle ) ;						// サウンドハンドルの再生位置をバイト単位で設定する(再生が?まっている時のみ有効)
extern	int			GetSoundCurrentPosition(                                                             int SoundHandle ) ;						// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetSoundCurrentTime(                 int Time,                                       int SoundHandle ) ;						// サウンドハンドルの再生位置を?リ秒単位で設定する(圧縮?式の場合は正しく設定されない場合がある)
extern	int			GetSoundCurrentTime(                                                                 int SoundHandle ) ;						// サウンドハンドルの再生位置を?リ秒単位で取得する(圧縮?式の場合は正しい値が返ってこない場合がある)
extern	int			GetSoundTotalSample(                                                                 int SoundHandle ) ;						// サウンドハンドルの音の総時間をサンプル単位で取得する
extern	int			GetSoundTotalTime(                                                                   int SoundHandle ) ;						// サウンドハンドルの音の総時間を?リ秒単位で取得する

extern	int			SetLoopPosSoundMem(                  int LoopTime,                                   int SoundHandle ) ;						// SetLoopTimePosSoundMem の別名関数
extern	int			SetLoopTimePosSoundMem(              int LoopTime,                                   int SoundHandle ) ;						// サウンドハンドルにル?プ位置を設定する(?リ秒単位)
extern	int			SetLoopSamplePosSoundMem(            int LoopSamplePosition,                         int SoundHandle ) ;						// サウンドハンドルにル?プ位置を設定する(サンプル単位)

extern	int			SetLoopStartTimePosSoundMem(         int LoopStartTime,                              int SoundHandle ) ;						// サウンドハンドルにル?プ開始位置を設定する(?リ秒単位)
extern	int			SetLoopStartSamplePosSoundMem(       int LoopStartSamplePosition,                    int SoundHandle ) ;						// サウンドハンドルにル?プ開始位置を設定する(サンプル単位)

extern	int			SetPlayFinishDeleteSoundMem(         int DeleteFlag,                                 int SoundHandle ) ;						// サウンドハンドルの再生が終了したら自動的にハンドルを削除するかどうかを設定する

extern	int			Set3DReverbParamSoundMem(            const SOUND3D_REVERB_PARAM *Param,              int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用のリバ?ブパラメ??を設定する
extern	int			Set3DPresetReverbParamSoundMem(      int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */ , int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用のリバ?ブパラメ??をプリセットを使用して設定する
extern	int			Set3DReverbParamSoundMemAll(         const SOUND3D_REVERB_PARAM *Param, int PlaySoundOnly = FALSE ) ;							// 全ての３Ｄサウンドのサウンドハンドルにリバ?ブパラメ??を設定する( PlaySoundOnly TRUE:再生中のサウンドにのみ設定する  FALSE:再生していないサウンドにも設定する )
extern	int			Set3DPresetReverbParamSoundMemAll(   int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */ , int PlaySoundOnly = FALSE  ) ;			// 全ての３Ｄサウンドのサウンドハンドルにリバ?ブパラメ??をプリセットを使用して設定する( PlaySoundOnly TRUE:再生中のサウンドにのみ設定する  FALSE:再生していないサウンドにも設定する )
extern	int			Get3DReverbParamSoundMem(            SOUND3D_REVERB_PARAM *ParamBuffer,              int SoundHandle ) ;						// サウンドハンドルに設定されている３Ｄサウンド用のリバ?ブパラメ??を取得する
extern	int			Get3DPresetReverbParamSoundMem(      SOUND3D_REVERB_PARAM *ParamBuffer, int PresetNo /* DX_REVERB_PRESET_DEFAULT 等 */ ) ;		// プリセットの３Ｄサウンド用のリバ?ブパラメ??を取得する

extern	int			Set3DPositionSoundMem(               VECTOR Position,                                int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の再生位置を設定する
extern	int			Set3DRadiusSoundMem(                 float Radius,                                   int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の音が聞こえる距離を設定する
extern	int			Set3DVelocitySoundMem(               VECTOR Velocity,                                int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の移動速度を設定する

extern	int			SetNextPlay3DPositionSoundMem(       VECTOR Position,                                int SoundHandle ) ;						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の再生位置を設定する
extern	int			SetNextPlay3DRadiusSoundMem(         float Radius,                                   int SoundHandle ) ;						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の音が聞こえる距離を設定する
extern	int			SetNextPlay3DVelocitySoundMem(       VECTOR Velocity,                                int SoundHandle ) ;						// サウンドハンドルの次の再生のみに使用する３Ｄサウンド用の移動速度を設定する

// 設定関係関数
extern	int			SetCreateSoundDataType(              int SoundDataType ) ;																		// 作成するサウンドハンドルの再生?イプを設定する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			GetCreateSoundDataType(              void ) ;																					// 作成するサウンドハンドルの再生?イプを取得する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			SetDisableReadSoundFunctionMask(     int Mask ) ;																				// 使用しないサウンドデ??読み込み処理の?スクを設定する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			GetDisableReadSoundFunctionMask(     void ) ;																					// 使用しないサウンドデ??読み込み処理の?スクを取得する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			SetEnableSoundCaptureFlag(           int Flag ) ;																				// サウンドキャプ?ャを前提とした動作をするかどうかを設定する
extern	int			SetUseSoftwareMixingSoundFlag(       int Flag ) ;																				// サウンドの処理を?フトウエアで行うかどうかを設定する( TRUE:?フトウエア  FALSE:ハ?ドウエア( デフォルト ) )
extern	int			SetEnableXAudioFlag(                 int Flag ) ;																				// サウンドの再生にXAudioを使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseOldVolumeCalcFlag(             int Flag ) ;																				// ChangeVolumeSoundMem, ChangeNextPlayVolumeSoundMem, ChangeMovieVolumeToGraph の音量計算式を Ver3.10c以前のものを使用するかどうかを設定する( TRUE:Ver3.10c以前の計算式を使用  FALSE:3.10d以?の計算式を使用( デフォルト ) )

extern	int			SetCreate3DSoundFlag(                     int Flag ) ;																			// 次に作成するサウンドハンドルを３Ｄサウンド用にするかどうかを設定する( TRUE:３Ｄサウンド用にする  FALSE:３Ｄサウンド用にしない( デフォルト ) )
extern	int			Set3DSoundOneMetre(                       float Distance ) ;																		// ３Ｄ空間の１メ?トルに相当する距離を設定する、DxLib_Init を呼び出す前でのみ呼び出し可?( デフォルト:1.0f )
extern	int			Set3DSoundListenerPosAndFrontPos_UpVecY(  VECTOR Position, VECTOR FrontPosition ) ;												// ３Ｄサウンドのリスナ?の位置とリスナ?の前方位置を設定する( リスナ?の上方向はＹ軸固定 )
extern	int			Set3DSoundListenerPosAndFrontPosAndUpVec( VECTOR Position, VECTOR FrontPosition, VECTOR UpVector ) ;								// ３Ｄサウンドのリスナ?の位置とリスナ?の前方位置とリスナ?の上方向を設定する
extern	int			Set3DSoundListenerVelocity(               VECTOR Velocity ) ;																	// ３Ｄサウンドのリスナ?の移動速度を設定する
extern	int			Set3DSoundListenerConeAngle(              float InnerAngle, float OuterAngle ) ;													// ３Ｄサウンドのリスナ?の可聴角度範囲を設定する
extern	int			Set3DSoundListenerConeVolume(             float InnerAngleVolume, float OuterAngleVolume ) ;										// ３Ｄサウンドのリスナ?の可聴角度範囲の音量?率を設定する

// 情報取得系関数
extern	const void*	GetDSoundObj(                        void ) ;	/* 戻り値を IDirectSound * にキャストして下さい */								// ＤＸライブラリが使用している DirectSound オブジェクトを取得する

#ifndef DX_NON_BEEP
// BEEP音再生用命令
extern	int			SetBeepFrequency(					int Freq ) ;																				// ビ?プ音周波数設定関数
extern	int			PlayBeep(							void ) ;																					// ビ?プ音を再生する
extern	int			StopBeep(							void ) ;																					// ビ?プ音を?める
#endif // DX_NON_BEEP

// ラッパ?関数
extern	int			PlaySoundFile(						const TCHAR *FileName, int PlayType ) ;														// サウンドフ?イルを再生する
extern	int			PlaySound(							const TCHAR *FileName, int PlayType ) ;														// PlaySoundFile の旧名称
extern	int			CheckSoundFile(						void ) ;																					// サウンドフ?イルの再生中かどうかを取得する
extern	int			CheckSound(							void ) ;																					// CheckSoundFile の旧名称
extern	int			StopSoundFile(						void ) ;																					// サウンドフ?イルの再生を停?する
extern	int			StopSound(							void ) ;																					// StopSoundFile の旧名称
extern	int			SetVolumeSoundFile(					int VolumePal ) ;																			// サウンドフ?イルの音量を設定する
extern	int			SetVolumeSound(						int VolumePal ) ;																			// SetVolumeSound の旧名称

// ?フトウエア制御サウンド系関数
extern	int			InitSoftSound(						void ) ;																					// ?フトウエアで扱う波?デ??ハンドルをすべて削除する
extern	int			LoadSoftSound(						const TCHAR *FileName ) ;																	// ?フトウエアで扱う波?デ??ハンドルをサウンドフ?イルから作成する
extern	int			LoadSoftSoundFromMemImage(			const void *FileImage, int FileImageSize ) ;												// ?フトウエアで扱う波?デ??ハンドルをメモリ上に展開されたサウンドフ?イルイメ?ジから作成する
extern	int			MakeSoftSound(						int UseFormat_SoftSoundHandle, int SampleNum ) ;											// ?フトウエアで扱う空の波?デ??ハンドルを作成する( フォ??ットは引数の?フトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSound2Ch16Bit44KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch16Bit22KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound2Ch8Bit44KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:2 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch8Bit22KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:2 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch16Bit44KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch16Bit22KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch8Bit44KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:1 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch8Bit22KHz(			int SampleNum ) ;																			// ?フトウエアで扱う空の波?デ??ハンドルを作成する( ?ャンネル数:1 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundCustom(				int ChannelNum, int BitsPerSample, int SamplesPerSec, int SampleNum );						// ?フトウエアで扱う空の波?デ??ハンドルを作成する
extern	int			DeleteSoftSound(					int SoftSoundHandle ) ;																		// ?フトウエアで扱う波?デ??ハンドルを削除する
#ifndef DX_NON_SAVEFUNCTION
extern	int			SaveSoftSound(						int SoftSoundHandle, const TCHAR *FileName ) ;												// ?フトウエアで扱う波?デ??ハンドルをWAVEフ?イル(PCM)?式で保存する
#endif // DX_NON_SAVEFUNCTION
extern	int			GetSoftSoundSampleNum(				int SoftSoundHandle ) ;																		// ?フトウエアで扱う波?デ??ハンドルのサンプル数を取得する
extern	int			GetSoftSoundFormat(					int SoftSoundHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;				// ?フトウエアで扱う波?デ??ハンドルのフォ??ットを取得する
extern	int			ReadSoftSoundData(					int SoftSoundHandle, int SamplePosition, int *Channel1, int *Channel2 ) ;					// ?フトウエアで扱う波?デ??ハンドルのサンプルを読み取る
extern	int			WriteSoftSoundData(					int SoftSoundHandle, int SamplePosition, int Channel1, int Channel2 ) ;						// ?フトウエアで扱う波?デ??ハンドルのサンプルを書き込む
extern	void*		GetSoftSoundDataImage(				int SoftSoundHandle ) ;																		// ?フトウエアで扱う波?デ??ハンドルの波?イメ?ジが格?されているメモリアドレスを取得する

extern	int			InitSoftSoundPlayer(				void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルをすべて解放する
extern	int			MakeSoftSoundPlayer(				int UseFormat_SoftSoundHandle ) ;															// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( フォ??ットは引数の?フトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSoundPlayer2Ch16Bit44KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch16Bit22KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit44KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:2 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit22KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:2 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit44KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit22KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit44KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:1 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit22KHz(	void ) ;																					// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する( ?ャンネル数:1 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayerCustom(			int ChannelNum, int BitsPerSample, int SamplesPerSec ) ;									// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを作成する
extern	int			DeleteSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルを削除する
extern	int			AddDataSoftSoundPlayer(				int SSoundPlayerHandle, int SoftSoundHandle, int AddSamplePosition, int AddSampleNum ) ;	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルに波?デ??を追加する( フォ??ットが同じではない場合はエラ? )
extern	int			AddDirectDataSoftSoundPlayer(		int SSoundPlayerHandle, const void *SoundData, int AddSampleNum ) ;							// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルにプレイヤ?が対応したフォ??ットの生波?デ??を追加する
extern	int			AddOneDataSoftSoundPlayer(			int SSoundPlayerHandle, int Channel1, int Channel2 ) ;										// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルに波?デ??を一つ追加する
extern	int			GetSoftSoundPlayerFormat(			int SSoundPlayerHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;			// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルが扱うデ??フォ??ットを取得する
extern	int			StartSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルの再生処理を開始する
extern	int			CheckStartSoftSoundPlayer(			int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルの再生処理が開始されているか取得する( TRUE:開始している  FALSE:停?している )
extern	int			StopSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルの再生処理を停?する
extern	int			ResetSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルの状態を初期状態に戻す( 追加された波?デ??は削除され、再生状態だった場合は停?する )
extern	int			GetStockDataLengthSoftSoundPlayer(	int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルに追加した波?デ??でまだ再生用サウンドバッフ?に?送されていない波?デ??のサンプル数を取得する
extern	int			CheckSoftSoundPlayerNoneData(		int SSoundPlayerHandle ) ;																	// ?フトウエアで扱う波?デ??のプレイヤ?ハンドルに再生用サウンドバッフ?に?送していない波?デ??が無く、再生用サウンドバッフ?にも無音デ??以外無いかどうかを取得する( TRUE:無音デ??以外無い  FALSE:有効デ??がある )




// ＭＩＤＩ制御関数
extern	int			DeleteMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルを削除する
extern	int			LoadMusicMem(						const TCHAR *FileName ) ;																	// ＭＩＤＩフ?イルを読み込みＭＩＤＩハンドルを作成する
extern	int			LoadMusicMemByMemImage(				const void *FileImage, int FileImageSize ) ;												// メモリ上に展開されたＭＩＤＩフ?イルイメ?ジからＭＩＤＩハンドルを作成する
extern	int			LoadMusicMemByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType ) ;									// リ??ス上のＭＩＤＩフ?イルからＭＩＤＩハンドルを作成する
extern	int			PlayMusicMem(						int MusicHandle, int PlayType ) ;															// ＭＩＤＩハンドルの演奏を開始する
extern	int			StopMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルの演奏を停?する
extern	int			CheckMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルが演奏中かどうかを取得する( TRUE:演奏中  FALSE:停?中 )
extern	int			SetVolumeMusicMem(					int Volume, int MusicHandle ) ;																// ＭＩＤＩハンドルの再生音量をセットする
extern	int			GetMusicMemPosition(				int MusicHandle ) ;																			// ＭＩＤＩハンドルの現在の再生位置を取得する
extern	int			InitMusicMem(						void ) ;																					// ＭＩＤＩハンドルをすべて削除する
extern	int			ProcessMusicMem(					void ) ;																					// ＭＩＤＩハンドルの周期的処理( 内部で呼ばれます )

extern	int			PlayMusic(							const TCHAR *FileName, int PlayType ) ;														// ＭＩＤＩフ?イルを演奏する
extern	int			PlayMusicByMemImage(				const void *FileImage, int FileImageSize, int PlayType ) ;									// メモリ上に展開されているＭＩＤＩフ?イルを演奏する
extern	int			PlayMusicByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType, int PlayType ) ;						// リ??スからＭＩＤＩフ?イルを読み込んで演奏する
extern	int			SetVolumeMusic(						int Volume ) ;																				// ＭＩＤＩの再生音量をセットする
extern	int			StopMusic(							void ) ;																					// ＭＩＤＩフ?イルの演奏停?
extern	int			CheckMusic(							void ) ;																					// ＭＩＤＩフ?イルが演奏中か否か情報を取得する
extern	int			GetMusicPosition(					void ) ;																					// ＭＩＤＩの現在の再生位置を取得する

extern	int			SelectMidiMode(						int Mode ) ;																				// ＭＩＤＩの再生?式を設定する

#endif // DX_NON_SOUND










// DxArchive_.cpp 関数 プロト?イプ宣言
extern	int			SetUseDXArchiveFlag(		int Flag ) ;													// ＤＸア?カイブフ?イルの読み込み??を使うかどうかを設定する( FALSE:使用しない  TRUE:使用する )
extern	int			SetDXArchivePriority(		int Priority = 0 ) ;											// 同名のＤＸア?カイブフ?イルとフォル?が存在した場合、どちらを優先させるかを設定する( 1:フォル?を優先? 0:ＤＸア?カイブフ?イルを優先( デフォルト ) )
extern	int			SetDXArchiveExtension(		const TCHAR *Extension = NULL ) ;								// 検索するＤＸア?カイブフ?イルの拡張子を設定する( Extension:拡張子名文字列 )
extern	int			SetDXArchiveKeyString(		const TCHAR *KeyString = NULL ) ;								// ＤＸア?カイブフ?イルの鍵文字列を設定する( KeyString:鍵文字列 )

extern	int			DXArchivePreLoad(			const TCHAR *FilePath , int ASync = FALSE ) ;					// 指定のＤＸ?フ?イルを丸ごとメモリに読み込む( 戻り値  -1:エラ?  0:成功 )
extern	int			DXArchiveCheckIdle(			const TCHAR *FilePath ) ;										// 指定のＤＸ?フ?イルの事前読み込みが完了したかどうかを取得する( 戻り値  TRUE:完了した FALSE:まだ )
extern	int			DXArchiveRelease(			const TCHAR *FilePath ) ;										// 指定のＤＸ?フ?イルをメモリから解放する
extern	int			DXArchiveCheckFile(			const TCHAR *FilePath, const TCHAR *TargetFilePath ) ;			// ＤＸ?フ?イルの中に指定のフ?イルが存在するかどうかを調べる、TargetFilePath はＤＸ?フ?イルをカレントフォル?とした場合のパス( 戻り値:  -1=エラ?  0:無い  1:ある )
extern	int			DXArchiveSetMemImage(		void *ArchiveImage, int ArchiveImageSize, const TCHAR *EmulateFilePath, int ArchiveImageCopyFlag = FALSE, int ArchiveImageReadOnly = TRUE ) ;	// メモリ上に展開されたＤＸ?フ?イルを指定のフ?イルパスにあることにする( EmulateFilePath は見立てる dxa フ?イルのパス、例えばＤＸ?フ?イルイメ?ジを Image.dxa というフ?イル名で c:\Temp にあることにしたい場合は EmulateFilePath に "c:\\Temp\\Image.dxa" を渡す、SetDXArchiveExtension で拡張子を変更している場合は EmulateFilePath に渡すフ?イルパスの拡張子もそれに合わせる必要あり )
extern	int			DXArchiveReleaseMemImage(	void *ArchiveImage ) ;											// DXArchiveSetMemImage の設定を解除する





















// DxModel.cpp 関数 プロト?イプ宣言

#ifndef DX_NON_MODEL

// モデルの読み込み・複製関係
extern	int			MV1LoadModel(						const TCHAR *FileName ) ;											// モデルの読み込み( -1:エラ?  0以上:モデルハンドル )
extern	int			MV1LoadModelFromMem(				const void *FileImage, int FileSize, int (* FileReadFunc )( const TCHAR *FilePath, void **FileImageAddr, int *FileSize, void *FileReadFuncData ), int (* FileReleaseFunc )( void *MemoryAddr, void *FileReadFuncData ), void *FileReadFuncData = NULL ) ;	// メモリ上のモデルフ?イルイメ?ジと独自の読み込みル??ンを使用してモデルを読み込む
extern	int			MV1DuplicateModel(					int SrcMHandle ) ;													// 指定のモデルと同じモデル基?デ??を使用してモデルを作成する( -1:エラ?  0以上:モデルハンドル )
extern	int			MV1CreateCloneModel(				int SrcMHandle ) ;													// 指定のモデルをモデル基?デ??も含め複製する( MV1DuplicateModel はモデル基?デ??は共有しますが、こちらは複製元のモデルとは一切共有デ??の無いモデルハンドルを作成します )( -1:エラ?  0以上:モデルハンドル )

extern	int			MV1DeleteModel(						int MHandle ) ;														// モデルを削除する
extern	int			MV1InitModel(						void ) ;															// すべてのモデルを削除する

extern	int			MV1SetLoadModelReMakeNormal(		int Flag ) ;														// モデルを読み込む際に?線の再計算を行うかどうかを設定する( TRUE:行う  FALSE:行わない( デフォルト ) )
extern	int			MV1SetLoadModelReMakeNormalSmoothingAngle( float SmoothingAngle = 1.562069f ) ;							// モデルを読み込む際に行う?泉の再計算で使用するス??ジング角度を設定する( 単位はラジアン )
extern	int			MV1SetLoadModelIgnoreScaling(       int Flag ) ;														// モデルを読み込む際にスケ?リングデ??を無視するかどうかを設定する( TRUE:無視する  FALSE:無視しない( デフォルト ) )
extern	int			MV1SetLoadModelPositionOptimize(	int Flag ) ;														// モデルを読み込む際に座標デ??の最適化を行うかどうかを設定する( TRUE:行う  FALSE:行わない( デフォルト ) )
extern	int			MV1SetLoadModelUsePhysicsMode(		int PhysicsMode /* DX_LOADMODEL_PHYSICS_LOADCALC 等 */ ) ;			// 読み込むモデルの物理演算モ?ドを設定する
extern	int			MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;													// 読み込むモデルの物理演算に適用する重力パラメ??を設定する
extern	int			MV1SetLoadCalcPhysicsWorldGravity(	int GravityNo, VECTOR Gravity ) ;									// 読み込むモデルの物理演算モ?ドが事前計算( DX_LOADMODEL_PHYSICS_LOADCALC )だった場合に適用される重力の設定をする
extern	int			MV1SetLoadModelAnimFilePath(		const TCHAR *FileName ) ;											// 読み込むモデルに適用するアニメ?ションフ?イルのパスを設定する、NULLを渡すと設定リセット( 現在は PMD,PMX のみに効果あり )

// モデル保存関係
extern	int			MV1SaveModelToMV1File( int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE , int Normal8BitFlag = 1 , int Position16BitFlag = 1 , int Weight8BitFlag = 0 , int Anim16BitFlag = 1 ) ;		// 指定のパスにモデルを保存する( 戻り値  0:成功  -1:メモリ不足  -2:使われていないアニメ?ションがあった )
#ifndef DX_NON_SAVEFUNCTION
extern	int			MV1SaveModelToXFile(   int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE ) ;	// 指定のパスにモデルをＸフ?イル?式で保存する( 戻り値  0:成功  -1:メモリ不足  -2:使われていないアニメ?ションがあった )
#endif // DX_NON_SAVEFUNCTION

// モデル?画関係
extern	int			MV1DrawModel(						int MHandle ) ;														// モデルを?画する
extern	int			MV1DrawFrame(						int MHandle, int FrameIndex ) ;										// モデルの指定のフレ??を?画する
extern	int			MV1DrawMesh(						int MHandle, int MeshIndex ) ;										// モデルの指定のメッシュを?画する
extern	int			MV1DrawTriangleList(				int MHandle, int TriangleListIndex ) ;								// モデルの指定のトライアングルリストを?画する
extern	int			MV1DrawModelDebug(					int MHandle, int Color, int IsNormalLine, float NormalLineLength, int IsPolyLine, int IsCollisionBox ) ;	// モデルのデバッグ?画

// ?画設定関係
extern	int			MV1SetUseOrigShader(				int UseFlag ) ;														// モデルの?画に SetUseVertexShader, SetUsePixelShader で指定したシェ???を使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない( デフォルト ) )
extern	int			MV1SetSemiTransDrawMode(			int DrawMode /* DX_SEMITRANSDRAWMODE_ALWAYS 等 */ ) ;				// モデルの半透明要素がある部分についての?画モ?ドを設定する

// モデル基?制御関係
extern	MATRIX		MV1GetLocalWorldMatrix(				int MHandle ) ;														// モデルのロ?カル座標からワ?ルド座標に変換する行列を得る
extern	int			MV1SetPosition(						int MHandle, VECTOR Position ) ;									// モデルの座標をセット
extern	VECTOR		MV1GetPosition(						int MHandle ) ;														// モデルの座標を取得
extern	int			MV1SetScale(						int MHandle, VECTOR Scale ) ;										// モデルの拡大値をセット
extern	VECTOR		MV1GetScale(						int MHandle ) ;														// モデルの拡大値を取得
extern	int			MV1SetRotationXYZ(					int MHandle, VECTOR Rotate ) ;										// モデルの回?値をセット( X軸回?→Y軸回?→Z軸回?方式 )
extern	VECTOR		MV1GetRotationXYZ(					int MHandle ) ;														// モデルの回?値を取得( X軸回?→Y軸回?→Z軸回?方式 )
extern	int			MV1SetRotationZYAxis(				int MHandle, VECTOR ZAxisDirection, VECTOR YAxisDirection, float ZAxisTwistRotate ) ;	// モデルのＺ軸とＹ軸の向きをセットする
extern	int			MV1SetRotationMatrix(				int MHandle, MATRIX Matrix ) ;										// モデルの回?用行列をセットする
extern	MATRIX		MV1GetRotationMatrix(				int MHandle ) ;														// モデルの回?用行列を取得する
extern	int			MV1SetMatrix(						int MHandle, MATRIX Matrix ) ;										// モデルの変?用行列をセットする
extern	MATRIX		MV1GetMatrix(						int MHandle ) ;														// モデルの変?用行列を取得する
extern	int			MV1SetVisible(						int MHandle, int VisibleFlag ) ;									// モデルの?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetVisible(						int MHandle ) ;														// モデルの?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetMeshCategoryVisible(			int MHandle, int MeshCategory, int VisibleFlag ) ;					// モデルのメッシュの種類( DX_MV1_MESHCATEGORY_NORMAL など )毎の?示、非?示を設定する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetMeshCategoryVisible(			int MHandle, int MeshCategory ) ;									// モデルのメッシュの種類( DX_MV1_MESHCATEGORY_NORMAL など )毎の?示、非?示を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetDifColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetDifColorScale(				int MHandle ) ;														// モデルのディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetSpcColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetSpcColorScale(				int MHandle ) ;														// モデルのスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetEmiColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetEmiColorScale(				int MHandle ) ;														// モデルのエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetAmbColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetAmbColorScale(				int MHandle ) ;														// モデルのアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetSemiTransState(				int MHandle ) ;														// モデルに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetOpacityRate(					int MHandle, float Rate ) ;											// モデルの不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetOpacityRate(					int MHandle ) ;														// モデルの不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetUseDrawMulAlphaColor(			int MHandle, int Flag ) ;											// モデルを?画する際にRGB値に対してA値を乗算するかどうかを設定する( ?画結果が乗算済みアルフ?画像になります )( Flag   TRUE:RGB値に対してA値を乗算する  FALSE:乗算しない(デフォルト) )
extern	int			MV1GetUseDrawMulAlphaColor(			int MHandle ) ;														// モデルを?画する際にRGB値に対してA値を乗算するかどうかを取得する( ?画結果が乗算済みアルフ?画像になります )( 戻り値 TRUE:RGB値に対してA値を乗算する  FALSE:乗算しない(デフォルト) )
extern	int			MV1SetUseZBuffer(					int MHandle, int Flag ) ;											// モデルを?画する際にＺバッフ?を使用するかどうかを設定する
extern	int			MV1SetWriteZBuffer(					int MHandle, int Flag ) ;											// モデルを?画する際にＺバッフ?に書き込みを行うかどうかを設定する
extern	int			MV1SetZBufferCmpType(				int MHandle, int CmpType /* DX_CMP_NEVER 等 */ ) ;					// モデルの?画時のＺ値の比較モ?ドを設定する
extern	int			MV1SetZBias(						int MHandle, int Bias ) ;											// モデルの?画時の書き込むＺ値のバイアスを設定する
extern	int			MV1SetUseVertDifColor(				int MHandle, int UseFlag ) ;										// モデルの含まれるメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetUseVertSpcColor(				int MHandle, int UseFlag ) ;										// モデルに含まれるメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetSampleFilterMode(				int MHandle, int FilterMode ) ;										// モデルのテクス?ャのサンプルフィル??モ?ドを変更する( FilterMode は DX_DRAWMODE_NEAREST 等 )
extern	int			MV1SetMaxAnisotropy(				int MHandle, int MaxAnisotropy ) ;									// モデルの異方性フィル?リングの最大次数を設定する
extern	int			MV1SetWireFrameDrawFlag(			int MHandle, int Flag ) ;											// モデルをワイヤ?フレ??で?画するかどうかを設定する
extern	int			MV1RefreshVertColorFromMaterial(	int MHandle ) ;														// モデルの頂?カラ?を現在設定されている?テリアルのカラ?にする
extern	int			MV1SetPhysicsWorldGravity(			int MHandle, VECTOR Gravity ) ;										// モデルの物理演算の重力を設定する
extern	int			MV1PhysicsCalculation(				int MHandle, float MillisecondTime ) ;								// モデルの物理演算を指定時間分経過したと仮定して計算する( MillisecondTime で指定する時間の単位は?リ秒 )
extern	int			MV1PhysicsResetState(				int MHandle ) ;														// モデルの物理演算の状態をリセットする( 位置がワ?プしたとき用 )
extern	int			MV1SetUseShapeFlag(					int MHandle, int UseFlag ) ;										// モデルのシェイプ??を使用するかどうかを設定する( UseFlag  TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			MV1GetMaterialNumberOrderFlag(		int MHandle ) ;														// モデルの?テリアル番号順にメッシュを?画するかどうかのフラグを取得する( TRUE:?テリアル番号順に?画  FALSE:不透明メッシュの後半透明メッシュ )

// アニメ?ション関係
extern	int			MV1AttachAnim(						int MHandle, int AnimIndex, int AnimSrcMHandle = -1 , int NameCheck = TRUE ) ;		// アニメ?ションをア?ッ?する( 戻り値  -1:エラ?  0以上:ア?ッ?インデックス )
extern	int			MV1DetachAnim(						int MHandle, int AttachIndex ) ;													// アニメ?ションをデ?ッ?する
extern	int			MV1SetAttachAnimTime(				int MHandle, int AttachIndex, float Time ) ;										// ア?ッ?しているアニメ?ションの再生時間を設定する
extern	float		MV1GetAttachAnimTime(				int MHandle, int AttachIndex ) ;													// ア?ッ?しているアニメ?ションの再生時間を取得する
extern	float		MV1GetAttachAnimTotalTime(			int MHandle, int AttachIndex ) ;													// ア?ッ?しているアニメ?ションの総時間を得る
extern	int			MV1SetAttachAnimBlendRate(			int MHandle, int AttachIndex, float Rate = 1.0f ) ;									// ア?ッ?しているアニメ?ションのブレンド率を設定する
extern	float		MV1GetAttachAnimBlendRate(			int MHandle, int AttachIndex ) ;													// ア?ッ?しているアニメ?ションのブレンド率を取得する
extern	int			MV1SetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex, float Rate, int SetChild = TRUE ) ;	// ア?ッ?しているアニメ?ションのブレンド率を設定する( フレ??単位 )
extern	float		MV1GetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex ) ;									// ア?ッ?しているアニメ?ションのブレンド率を設定する( フレ??単位 )
extern	int			MV1GetAttachAnim(					int MHandle, int AttachIndex ) ;													// ア?ッ?しているアニメ?ションのアニメ?ションインデックスを取得する
extern	int			MV1SetAttachAnimUseShapeFlag(		int MHandle, int AttachIndex, int UseFlag ) ;										// ア?ッ?しているアニメ?ションのシェイプを使用するかどうかを設定する( UseFlag  TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			MV1GetAttachAnimUseShapeFlag(		int MHandle, int AttachIndex ) ;													// ア?ッ?しているアニメ?ションのシェイプを使用するかどうかを取得する
extern	VECTOR		MV1GetAttachAnimFrameLocalPosition(	int MHandle, int AttachIndex, int FrameIndex ) ;									// ア?ッ?しているアニメ?ションの指定のフレ??の現在のロ?カル座標を取得する
extern	MATRIX		MV1GetAttachAnimFrameLocalMatrix(	int MHandle, int AttachIndex, int FrameIndex ) ;									// ア?ッ?しているアニメ?ションの指定のフレ??の現在のロ?カル変換行列を取得する

extern	int			MV1GetAnimNum(						int MHandle ) ;																		// アニメ?ションの数を取得する
extern	const TCHAR *MV1GetAnimName(					int MHandle, int AnimIndex ) ;														// 指定番号のアニメ?ション名を取得する( NULL:エラ? )
extern	int			MV1SetAnimName(						int MHandle, int AnimIndex, const TCHAR *AnimName ) ;								// 指定番号のアニメ?ション名を変更する
extern	int			MV1GetAnimIndex(					int MHandle, const TCHAR *AnimName ) ;												// 指定名のアニメ?ション番号を取得する( -1:エラ? )
extern	float		MV1GetAnimTotalTime(				int MHandle, int AnimIndex ) ;														// 指定番号のアニメ?ションの総時間を得る
extern	int			MV1GetAnimTargetFrameNum(			int MHandle, int AnimIndex ) ;														// 指定のアニメ?ションが??ゲットとするフレ??の数を取得する
extern	const TCHAR *MV1GetAnimTargetFrameName(			int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメ?ションが??ゲットとするフレ??の名前を取得する
extern	int			MV1GetAnimTargetFrame(				int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメ?ションが??ゲットとするフレ??の番号を取得する
extern	int			MV1GetAnimTargetFrameKeySetNum(		int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメ?ションが??ゲットとするフレ??用のアニメ?ションキ?セットの数を取得する
extern	int			MV1GetAnimTargetFrameKeySet(		int MHandle, int AnimIndex, int AnimFrameIndex, int Index ) ;						// 指定のアニメ?ションが??ゲットとするフレ??用のアニメ?ションキ?セットキ?セットインデックスを取得する

extern	int			MV1GetAnimKeySetNum(				int MHandle ) ;																		// モデルに含まれるアニメ?ションキ?セットの総数を得る
extern	int			MV1GetAnimKeySetType(				int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメ?ションキ?セットの?イプを取得する( MV1_ANIMKEY_TYPE_QUATERNION 等 )
extern	int			MV1GetAnimKeySetDataType(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメ?ションキ?セットのデ???イプを取得する( MV1_ANIMKEY_DATATYPE_ROTATE 等 )
extern	int			MV1GetAnimKeySetTimeType(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメ?ションキ?セットのキ?の時間デ???イプを取得する( MV1_ANIMKEY_TIME_TYPE_ONE 等 )
extern	int			MV1GetAnimKeySetDataNum(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメ?ションキ?セットのキ?の数を取得する
extern	float		MV1GetAnimKeyDataTime(				int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?の時間を取得する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternion(		int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternionFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する( 時間指定版 )
extern	VECTOR		MV1GetAnimKeyDataToVector(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する
extern	VECTOR		MV1GetAnimKeyDataToVectorFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する( 時間指定版 )
extern	MATRIX		MV1GetAnimKeyDataToMatrix(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する
extern	MATRIX		MV1GetAnimKeyDataToMatrixFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToFlat(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToFlatFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToLinear(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToLinearFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメ?ションキ?セットのキ?を取得する、キ??イプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する( 時間指定版 )

// ?テリアル関係
extern	int			MV1GetMaterialNum(					int MHandle ) ;															// モデルで使用している?テリアルの数を取得する
extern	const TCHAR *MV1GetMaterialName(				int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの名前を取得する
extern	int			MV1SetMaterialTypeAll(				int MHandle,                    int Type ) ;							// 全ての?テリアルの?イプを変更する( Type : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1SetMaterialType(					int MHandle, int MaterialIndex, int Type ) ;							// 指定の?テリアルの?イプを変更する( Type : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1GetMaterialType(					int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?イプを取得する( 戻り値 : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1SetMaterialDifColor(				int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定の?テリアルのディフュ?ズカラ?を設定する
extern	COLOR_F		MV1GetMaterialDifColor( 			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのディフュ?ズカラ?を取得する
extern	int			MV1SetMaterialSpcColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定の?テリアルのスペキュラカラ?を設定する
extern	COLOR_F		MV1GetMaterialSpcColor( 			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのスペキュラカラ?を取得する
extern	int			MV1SetMaterialEmiColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定の?テリアルのエ?ッシブカラ?を設定する
extern	COLOR_F		MV1GetMaterialEmiColor( 			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのエ?ッシブカラ?を取得する
extern	int			MV1SetMaterialAmbColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定の?テリアルのアンビエントカラ?を設定する
extern	COLOR_F		MV1GetMaterialAmbColor( 			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのアンビエントカラ?を取得する
extern	int			MV1SetMaterialSpcPower( 			int MHandle, int MaterialIndex, float Power ) ;							// 指定の?テリアルのスペキュラの強さを設定する
extern	float		MV1GetMaterialSpcPower( 			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのスペキュラの強さを取得する
extern	int			MV1SetMaterialDifMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定の?テリアルでディフュ?ズ?ップとして使用するテクス?ャを指定する
extern	int			MV1GetMaterialDifMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルでディフュ?ズ?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1SetMaterialSpcMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定の?テリアルでスペキュラ?ップとして使用するテクス?ャを指定する
extern	int			MV1GetMaterialSpcMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルでスペキュラ?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1GetMaterialNormalMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルで?線?ップとして使用されているテクス?ャのインデックスを取得する
extern	int			MV1SetMaterialDifGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定の?テリアルでトゥ?ンレン?リングのディフュ?ズグラデ?ション?ップとして使用するテクス?ャを設定する
extern	int			MV1GetMaterialDifGradTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルでトゥ?ンレン?リングのディフュ?ズグラデ?ション?ップとして使用するテクス?ャを取得する
extern	int			MV1SetMaterialSpcGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定の?テリアルでトゥ?ンレン?リングのスペキュラグラデ?ション?ップとして使用するテクス?ャを設定する
extern	int			MV1GetMaterialSpcGradTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルでトゥ?ンレン?リングのスペキュラグラデ?ション?ップとして使用するテクス?ャを取得する
extern	int			MV1SetMaterialSphereMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定の?テリアルでトゥ?ンレン?リングのスフィア?ップとして使用するテクス?ャを設定する
extern	int			MV1GetMaterialSphereMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルでトゥ?ンレン?リングのスフィア?ップとして使用するテクス?ャを取得する
extern	int			MV1SetMaterialDifGradBlendTypeAll(	int MHandle,                    int BlendType ) ;						// 全ての?テリアルのトゥ?ンレン?リングで使用するディフュ?ズグラデ?ション?ップとディフュ?ズカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialDifGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;						// 指定の?テリアルのトゥ?ンレン?リングで使用するディフュ?ズグラデ?ション?ップとディフュ?ズカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialDifGradBlendType(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用するディフュ?ズグラデ?ション?ップとディフュ?ズカラ?の合成方?を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSpcGradBlendTypeAll(	int MHandle,                    int BlendType ) ;						// 全ての?テリアルのトゥ?ンレン?リングで使用するスペキュラグラデ?ション?ップとスペキュラカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;						// 指定の?テリアルのトゥ?ンレン?リングで使用するスペキュラグラデ?ション?ップとスペキュラカラ?の合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用するスペキュラグラデ?ション?ップとスペキュラカラ?の合成方?を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSphereMapBlendTypeAll( int MHandle,                   int BlendType ) ;						// 全ての?テリアルのトゥ?ンレン?リングで使用するスフィア?ップの合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSphereMapBlendType(	int MHandle, int MaterialIndex, int BlendType ) ;						// 指定の?テリアルのトゥ?ンレン?リングで使用するスフィア?ップの合成方?を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialSphereMapBlendType(	int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用するスフィア?ップの合成方?を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialOutLineWidthAll(		int MHandle,                    float Width ) ;							// 全ての?テリアルのトゥ?ンレン?リングで使用する輪郭線の太さを設定する
extern	int			MV1SetMaterialOutLineWidth(			int MHandle, int MaterialIndex, float Width ) ;							// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の太さを設定する
extern	float		MV1GetMaterialOutLineWidth(			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の太さを取得する
extern	int			MV1SetMaterialOutLineDotWidthAll(	int MHandle,                    float Width ) ;							// 全ての?テリアルのトゥ?ンレン?リングで使用する輪郭線のドット単位の太さを設定する
extern	int			MV1SetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex, float Width ) ;							// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線のドット単位の太さを設定する
extern	float		MV1GetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線のドット単位の太さを取得する
extern	int			MV1SetMaterialOutLineColorAll(		int MHandle,                    COLOR_F Color ) ;						// 全ての?テリアルのトゥ?ンレン?リングで使用する輪郭線の色を設定する
extern	int			MV1SetMaterialOutLineColor(			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の色を設定する
extern	COLOR_F		MV1GetMaterialOutLineColor(			int MHandle, int MaterialIndex ) ;										// 指定の?テリアルのトゥ?ンレン?リングで使用する輪郭線の色を取得する
extern	int			MV1SetMaterialDrawBlendModeAll(		int MHandle,                    int BlendMode ) ;						// 全ての?テリアルの?画ブレンドモ?ドを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMaterialDrawBlendMode(		int MHandle, int MaterialIndex, int BlendMode ) ;						// 指定の?テリアルの?画ブレンドモ?ドを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMaterialDrawBlendMode(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?画ブレンドモ?ドを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMaterialDrawBlendParamAll(	int MHandle,                    int BlendParam ) ;						// 全ての?テリアルの?画ブレンドパラメ??を設定する
extern	int			MV1SetMaterialDrawBlendParam(		int MHandle, int MaterialIndex, int BlendParam ) ;						// 指定の?テリアルの?画ブレンドパラメ??を設定する
extern	int			MV1GetMaterialDrawBlendParam(		int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?画ブレンドパラメ??を設定する
extern	int			MV1SetMaterialDrawAlphaTestAll(		int MHandle,                    int Enable, int Mode, int Param ) ;		// 全ての?テリアルの?画時のアルフ?テストの設定を行う( Enable:αテストを行うかどうか( TRUE:行う  FALSE:行わない( デフォルト ) ) Mode:テストモ?ド( DX_CMP_GREATER等 )  Param:?画アルフ?値との比較に使用する値( 0?255 ) )
extern	int			MV1SetMaterialDrawAlphaTest(		int MHandle, int MaterialIndex,	int Enable, int Mode, int Param ) ;		// 指定の?テリアルの?画時のアルフ?テストの設定を行う( Enable:αテストを行うかどうか( TRUE:行う  FALSE:行わない( デフォルト ) ) Mode:テストモ?ド( DX_CMP_GREATER等 )  Param:?画アルフ?値との比較に使用する値( 0?255 ) )
extern	int			MV1GetMaterialDrawAlphaTestEnable(	int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?画時のアルフ?テストを行うかどうかを取得する( 戻り値  TRUE:アルフ?テストを行う  FALSE:アルフ?テストを行わない )
extern	int			MV1GetMaterialDrawAlphaTestMode(	int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?画時のアルフ?テストのテストモ?ドを取得する( 戻り値  テストモ?ド( DX_CMP_GREATER等 ) )
extern	int			MV1GetMaterialDrawAlphaTestParam(	int MHandle, int MaterialIndex ) ;										// 指定の?テリアルの?画時のアルフ?テストの?画アルフ?地との比較に使用する値( 0?255 )を取得する

// テクス?ャ関係
extern	int			MV1GetTextureNum(					int MHandle ) ;													// テクス?ャの数を取得
extern	const TCHAR *MV1GetTextureName(					int MHandle, int TexIndex ) ;									// テクス?ャの名前を取得
extern	int			MV1SetTextureColorFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// カラ?テクス?ャのフ?イルパスを変更する
extern	const TCHAR *MV1GetTextureColorFilePath(		int MHandle, int TexIndex ) ;									// カラ?テクス?ャのフ?イルパスを取得
extern	int			MV1SetTextureAlphaFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// アルフ?テクス?ャのフ?イルパスを変更する
extern	const TCHAR *MV1GetTextureAlphaFilePath(		int MHandle, int TexIndex ) ;									// アルフ?テクス?ャのフ?イルパスを取得
extern	int			MV1SetTextureGraphHandle(			int MHandle, int TexIndex, int GrHandle, int SemiTransFlag ) ;	// テクス?ャで使用するグラフィックハンドルを変更する( GrHandle を -1 にすると解除 )
extern	int			MV1GetTextureGraphHandle(			int MHandle, int TexIndex ) ;									// テクス?ャのグラフィックハンドルを取得する
extern	int			MV1SetTextureAddressMode(			int MHandle, int TexIndex, int AddrUMode, int AddrVMode ) ;		// テクス?ャのアドレスモ?ドを設定する( AddUMode の値は DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeU(			int MHandle, int TexIndex ) ;									// テクス?ャのＵ値のアドレスモ?ドを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeV(			int MHandle, int TexIndex ) ;									// テクス?ャのＶ値のアドレスモ?ドを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureWidth(					int MHandle, int TexIndex ) ;									// テクス?ャの幅を取得する
extern	int			MV1GetTextureHeight(				int MHandle, int TexIndex ) ;									// テクス?ャの高さを取得する
extern	int			MV1GetTextureSemiTransState(		int MHandle, int TexIndex ) ;									// テクス?ャに半透明要素があるかどうかを取得する( 戻り値  TRUE:ある  FALSE:ない )
extern	int			MV1SetTextureBumpImageFlag(			int MHandle, int TexIndex, int Flag ) ;							// テクス?ャで使用している画像がバンプ?ップかどうかを設定する
extern	int			MV1GetTextureBumpImageFlag(			int MHandle, int TexIndex ) ;									// テクス?ャがバンプ?ップかどうかを取得する( 戻り値  TRUE:バンプ?ップ  FALSE:違う )
extern	int			MV1SetTextureBumpImageNextPixelLength( int MHandle, int TexIndex, float Length ) ;					// バンプ?ップ画像の場合の隣のピクセルとの距離を設定する
extern	float		MV1GetTextureBumpImageNextPixelLength( int MHandle, int TexIndex ) ;								// バンプ?ップ画像の場合の隣のピクセルとの距離を取得する
extern	int			MV1SetTextureSampleFilterMode(		int MHandle, int TexIndex, int FilterMode ) ;					// テクス?ャのフィル?リングモ?ドを設定する
extern	int			MV1GetTextureSampleFilterMode(		int MHandle, int TexIndex ) ;									// テクス?ャのフィル?リングモ?ドを取得する( 戻り値  DX_DRAWMODE_BILINEAR等 )
extern	int			MV1LoadTexture(						const TCHAR *FilePath ) ;										// ３Ｄモデルに?り付けるのに向いた画像の読み込み方式で画像を読み込む( 戻り値  -1:エラ?  0以上:グラフィックハンドル )

// フレ??関係
extern	int			MV1GetFrameNum(						int MHandle ) ;															// フレ??の数を取得する
extern	int			MV1SearchFrame(						int MHandle, const TCHAR *FrameName ) ;									// フレ??の名前からモデル中のフレ??のフレ??インデックスを取得する( 無かった場合は戻り値が-1 )
extern	int			MV1SearchFrameChild(				int MHandle, int FrameIndex = -1 , const TCHAR *ChildName = NULL ) ;	// フレ??の名前から指定のフレ??の子フレ??のフレ??インデックスを取得する( 名前指定版 )( FrameIndex を -1 にすると親を持たないフレ??を ChildIndex で指定する )( 無かった場合は戻り値が-1 )
extern	const TCHAR *MV1GetFrameName(					int MHandle, int FrameIndex ) ;											// 指定のフレ??の名前を取得する( エラ?の場合は戻り値が NULL )
extern	int			MV1GetFrameName2(					int MHandle, int FrameIndex, TCHAR *StrBuffer ) ;						// 指定のフレ??の名前を取得する( 戻り値   -1:エラ?  -1以外:文字列のサイズ )
extern	int			MV1GetFrameParent(					int MHandle, int FrameIndex ) ;											// 指定のフレ??の親フレ??のインデックスを得る( 親がいない場合は -2 が返る )
extern	int			MV1GetFrameChildNum(				int MHandle, int FrameIndex = -1 ) ;									// 指定のフレ??の子フレ??の数を取得する( FrameIndex を -1 にすると親を持たないフレ??の数が返ってくる )
extern	int			MV1GetFrameChild(					int MHandle, int FrameIndex = -1 , int ChildIndex = 0 ) ;				// 指定のフレ??の子フレ??のフレ??インデックスを取得する( 番号指定版 )( FrameIndex を -1 にすると親を持たないフレ??を ChildIndex で指定する )( エラ?の場合は戻り値が-1 )
extern	VECTOR		MV1GetFramePosition(				int MHandle, int FrameIndex ) ;											// 指定のフレ??の座標を取得する
extern	MATRIX		MV1GetFrameBaseLocalMatrix(			int MHandle, int FrameIndex ) ;											// 指定のフレ??の初期状態での座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalMatrix(				int MHandle, int FrameIndex ) ;											// 指定のフレ??の座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalWorldMatrix(		int MHandle, int FrameIndex ) ;											// 指定のフレ??のロ?カル座標からワ?ルド座標に変換する行列を得る
extern	int			MV1SetFrameUserLocalMatrix(			int MHandle, int FrameIndex, MATRIX Matrix ) ;							// 指定のフレ??の座標変換行列を設定する
extern	int			MV1ResetFrameUserLocalMatrix(		int MHandle, int FrameIndex ) ;											// 指定のフレ??の座標変換行列をデフォルトに戻す
extern	VECTOR		MV1GetFrameMaxVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレ??が持つメッシュ頂?のロ?カル座標での最大値を得る
extern	VECTOR		MV1GetFrameMinVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレ??が持つメッシュ頂?のロ?カル座標での最小値を得る
extern	VECTOR		MV1GetFrameAvgVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレ??が持つメッシュ頂?のロ?カル座標での平均値を得る
extern	int			MV1GetFrameTriangleNum(				int MHandle, int FrameIndex ) ;											// 指定のフレ??に含まれる?リゴンの数を取得する
extern	int			MV1GetFrameMeshNum(					int MHandle, int FrameIndex ) ;											// 指定のフレ??が持つメッシュの数を取得する
extern	int			MV1GetFrameMesh(					int MHandle, int FrameIndex, int Index ) ;								// 指定のフレ??が持つメッシュのメッシュインデックスを取得する
extern	int			MV1SetFrameVisible(					int MHandle, int FrameIndex, int VisibleFlag ) ;						// 指定のフレ??の?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetFrameVisible(					int MHandle, int FrameIndex ) ;											// 指定のフレ??の?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetFrameDifColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレ??のディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameSpcColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレ??のスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameEmiColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレ??のエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameAmbColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレ??のアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameDifColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレ??のディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameSpcColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレ??のスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameEmiColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレ??のエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameAmbColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレ??のアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetFrameSemiTransState(			int MHandle, int FrameIndex ) ;											// 指定のフレ??に半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetFrameOpacityRate(				int MHandle, int FrameIndex, float Rate ) ;								// 指定のフレ??の不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetFrameOpacityRate(				int MHandle, int FrameIndex ) ;											// 指定のフレ??の不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetFrameBaseVisible(				int MHandle, int FrameIndex, int VisibleFlag ) ;						// 指定のフレ??の初期?示状態を設定する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetFrameBaseVisible(				int MHandle, int FrameIndex ) ;											// 指定のフレ??の初期?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetFrameTextureAddressTransform( int MHandle, int FrameIndex, float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// 指定のフレ??のテクス?ャ座標変換パラメ??を設定する
extern	int			MV1SetFrameTextureAddressTransformMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;					// 指定のフレ??のテクス?ャ座標変換行列をセットする
extern	int			MV1ResetFrameTextureAddressTransform( int MHandle, int FrameIndex ) ;										// 指定のフレ??のテクス?ャ座標変換パラメ??をリセットする

// メッシュ関係
extern	int			MV1GetMeshNum(						int MHandle ) ;															// モデルに含まれるメッシュの数を取得する
extern	int			MV1GetMeshMaterial(					int MHandle, int MeshIndex ) ;											// 指定メッシュが使用している?テリアルのインデックスを取得する
extern	int			MV1GetMeshTriangleNum(				int MHandle, int MeshIndex ) ;											// 指定メッシュに含まれる三角??リゴンの数を取得する
extern	int			MV1SetMeshVisible(					int MHandle, int MeshIndex, int VisibleFlag ) ;							// 指定メッシュの?示、非?示状態を変更する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetMeshVisible(					int MHandle, int MeshIndex ) ;											// 指定メッシュの?示、非?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetMeshDifColorScale(			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのディフュ?ズカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshSpcColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのスペキュラカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshEmiColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのエ?ッシブカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshAmbColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのアンビエントカラ?のスケ?ル値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshDifColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのディフュ?ズカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshSpcColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのスペキュラカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshEmiColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのエ?ッシブカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshAmbColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのアンビエントカラ?のスケ?ル値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetMeshOpacityRate( 				int MHandle, int MeshIndex, float Rate ) ;								// 指定のメッシュの不透明度を設定する( 不透明 1.0f ? 透明 0.0f )
extern	float		MV1GetMeshOpacityRate( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュの不透明度を取得する( 不透明 1.0f ? 透明 0.0f )
extern	int			MV1SetMeshDrawBlendMode( 			int MHandle, int MeshIndex, int BlendMode ) ;							// 指定のメッシュの?画ブレンドモ?ドを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMeshDrawBlendParam( 			int MHandle, int MeshIndex, int BlendParam ) ;							// 指定のメッシュの?画ブレンドパラメ??を設定する
extern	int			MV1GetMeshDrawBlendMode( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの?画ブレンドモ?ドを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMeshDrawBlendParam( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの?画ブレンドパラメ??を設定する
extern	int			MV1SetMeshBaseVisible( 				int MHandle, int MeshIndex, int VisibleFlag ) ;							// 指定のメッシュの初期?示状態を設定する( TRUE:?示  FALSE:非?示 )
extern	int			MV1GetMeshBaseVisible( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュの初期?示状態を取得する( TRUE:?示  FALSE:非?示 )
extern	int			MV1SetMeshBackCulling( 				int MHandle, int MeshIndex, int CullingFlag ) ;							// 指定のメッシュのバックカリングを行うかどうかを設定する( DX_CULLING_LEFT 等 )
extern	int			MV1GetMeshBackCulling( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュのバックカリングを行うかどうかを取得する( DX_CULLING_LEFT 等 )
extern	VECTOR		MV1GetMeshMaxPosition( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれる?リゴンの最大ロ?カル座標を取得する
extern	VECTOR		MV1GetMeshMinPosition( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれる?リゴンの最小ロ?カル座標を取得する
extern	int			MV1GetMeshTListNum( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれるトライアングルリストの数を取得する
extern	int			MV1GetMeshTList( 					int MHandle, int MeshIndex, int Index ) ;								// 指定のメッシュに含まれるトライアングルリストのインデックスを取得する
extern	int			MV1GetMeshSemiTransState( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetMeshUseVertDifColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// 指定のメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1SetMeshUseVertSpcColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// 指定のメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかを設定する( TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1GetMeshUseVertDifColor( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの頂?ディフュ?ズカラ?を?テリアルのディフュ?ズカラ?の代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1GetMeshUseVertSpcColor( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの頂?スペキュラカラ?を?テリアルのスペキュラカラ?の代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:?テリアルカラ?の代わりに使用する  FALSE:?テリアルカラ?を使用する )
extern	int			MV1GetMeshShapeFlag(				int MHandle, int MeshIndex ) ;											// 指定のメッシュがシェイプメッシュかどうかを取得する( 戻り値 TRUE:シェイプメッシュ  FALSE:通常メッシュ )

// シェイプ関係
extern	int			MV1GetShapeNum(						int MHandle ) ;															// モデルに含まれるシェイプの数を取得する
extern	int			MV1SearchShape(						int MHandle, const TCHAR *ShapeName ) ;									// シェイプの名前からモデル中のシェイプのシェイプインデックスを取得する( 無かった場合は戻り値が-1 )
extern	const TCHAR *MV1GetShapeName(					int MHandle, int ShapeIndex ) ;											// 指定シェイプの名前を取得する
extern	int			MV1GetShapeTargetMeshNum(			int MHandle, int ShapeIndex ) ;											// 指定シェイプが対象としているメッシュの数を取得する
extern	int			MV1GetShapeTargetMesh(				int MHandle, int ShapeIndex, int Index ) ;								// 指定シェイプが対象としているメッシュのメッシュインデックスを取得する
extern	int			MV1SetShapeRate(					int MHandle, int ShapeIndex, float Rate ) ;								// 指定シェイプの有効率を設定する( Rate  0.0f:0% ? 1.0f:100% )
extern	float		MV1GetShapeRate(					int MHandle, int ShapeIndex ) ;											// 指定シェイプの有効率を取得する( 戻り値  0.0f:0% ? 1.0f:100% )

// トライアングルリスト関係
extern	int			MV1GetTriangleListNum(				int MHandle ) ;															// モデルに含まれるトライアングルリストの数を取得する
extern	int			MV1GetTriangleListVertexType(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストの頂?デ???イプを取得する( DX_MV1_VERTEX_TYPE_1FRAME 等 )
extern	int			MV1GetTriangleListPolygonNum(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストに含まれる?リゴンの数を取得する
extern	int			MV1GetTriangleListVertexNum(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストに含まれる頂?デ??の数を取得する

// コリジョン関係
extern	int							MV1SetupCollInfo(				int MHandle, int FrameIndex = -1 , int XDivNum = 32 , int YDivNum = 8 , int ZDivNum = 32 ) ;	// コリジョン情報を?築する
extern	int							MV1TerminateCollInfo(			int MHandle, int FrameIndex = -1 ) ;															// コリジョン情報の後始末
extern	int							MV1RefreshCollInfo(				int MHandle, int FrameIndex = -1 ) ;															// コリジョン情報を更新する
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_Line(				int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// 線とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_LineDim(			int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// 線とモデルの当たり判定( 戻り値が MV1_COLL_RESULT_POLY_DIM )
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Sphere(			int MHandle, int FrameIndex, VECTOR CenterPos, float r ) ;										// 球とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Capsule(			int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, float r ) ;								// カプセルとモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Triangle(			int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, VECTOR Pos3 ) ;							// 三角?とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_GetResultPoly(		MV1_COLL_RESULT_POLY_DIM ResultPolyDim, int PolyNo ) ;											// コリジョン結果?リゴン配列から指定番号の?リゴン情報を取得する
extern	int							MV1CollResultPolyDimTerminate(	MV1_COLL_RESULT_POLY_DIM ResultPolyDim ) ;														// コリジョン結果?リゴン配列の後始末をする

// 参照用メッシュ関係
extern	int					MV1SetupReferenceMesh(		int MHandle, int FrameIndex, int IsTransform, int IsPositionOnly = FALSE ) ;						// 参照用メッシュのセットアップ
extern	int					MV1TerminateReferenceMesh(	int MHandle, int FrameIndex, int IsTransform, int IsPositionOnly = FALSE ) ;						// 参照用メッシュの後始末
extern	int					MV1RefreshReferenceMesh(	int MHandle, int FrameIndex, int IsTransform, int IsPositionOnly = FALSE ) ;						// 参照用メッシュの更新
extern	MV1_REF_POLYGONLIST	MV1GetReferenceMesh(		int MHandle, int FrameIndex, int IsTransform, int IsPositionOnly = FALSE ) ;						// 参照用メッシュを取得する

#endif // DX_NON_MODEL

#define DX_FUNCTION_END

}

// ネ??スペ?ス DxLib を使用する ------------------------------------------------------
using namespace DxLib ;

// ＤＸライブラリ内部でのみ使用するヘッ?フ?イルのインクル?ド -------------------------

#ifdef __DX_MAKE
//	#include "DxStatic.h"
#endif

#endif


