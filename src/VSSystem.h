//=======================================================================================
//							VIRUAL SHOCK ENGINE
//=======================================================================================
//
//     Copyright (c) 2013-2015 Carlo Meroni
//
//     This software is provided 'as-is', without any express or implied warranty.
//     In no event will the authors be held liable for any damages arising from
//     the use of this software.
//
//     Permission is granted to anyone to use this software for any purpose,
//     including commercial applications, and to alter it and redistribute it freely,
//     subject to the following restrictions:
//
//     1. The origin of this software must not be misrepresented;
//        you must not claim that you wrote the original software.
//        If you use this software in a product, an acknowledgment
//        in the product documentation would be appreciated but is
//        not required.
//
//     2. Altered source versions must be plainly marked as such,
//        and must not be misrepresented as being the original software.
//
//     3. This notice may not be removed or altered from any source
//        distribution.
//=======================================================================================

////////////////////////////////////////////////////////////
///	HEADER
////////////////////////////////////////////////////////////
#ifndef VS_SYSTEM_H
#define VS_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////
///	OS
////////////////////////////////////////////////////////////

// Identify the operating system
#if defined(_WIN32)
    //Windows
    #define VS_SYS_WINDOWS
#elif defined(__APPLE__)
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
        #define VS_SYS_IOS
    #elif TARGET_OS_IPHONE
        // iOS device
        #define VS_SYS_IOS
    #elif TARGET_OS_MAC
        //Mac
        #define VS_SYS_MAC
    #else
        //Error
        #error This operating system is not supported!
    #endif
    
#elif defined(__linux__)
    //Linux
    #define VS_SYS_LINUX
#else
    //Other systems
    #error This operating system is not supported!
#endif

//Define import / export macros
#if defined(VS_SYS_WINDOWS)

    #if defined(VSSYSTEM_EXPORTS)
        #define VSSYSTEM_API __declspec(dllexport)
    #else
        #define VSSYSTEM_API __declspec(dllimport)
    #endif

#else

    #define VSSYSTEM_API

#endif



////////////////////////////////////////////////////////////
///	MODULE MANAGER
////////////////////////////////////////////////////////////

/*
 
 Modules:
	SYSTEM
	WINDOW
	TIME
	KEY
	MOUSE
 
 By default all moudules are exported.
 To export only one specific module, you should
 define VS_ONLY_$MODULE before including this file.
 
 If you want just the OS defines you should
 define VS_NO_EXPORT before including this file
 
 */
    
#if defined(VS_ONLY_SYSTEM) || defined(VS_ONLY_WINDOW) || defined(VS_ONLY_TIME)||\
    defined(KEY) || defined(MOUSE)
    
#ifdef VS_ONLY_SYSTEM
    #define VS_EXPORT_SYSTEM
#endif
    
#ifdef VS_ONLY_WINDOW
    #define VS_EXPORT_WINDOW
#endif
    
#ifdef VS_ONLY_TIME
    #define VS_EXPORT_TIME
#endif
    
#ifdef VS_ONLY_KEY
    #define VS_EXPORT_KEY
#endif

#ifdef VS_ONLY_MOUSE
	#define VS_EXPORT_MOUSE
#endif
    
#else
    
    //Define all modules
    #define VS_EXPORT_SYSTEM
    #define VS_EXPORT_WINDOW
    #define VS_EXPORT_TIME
    #define VS_EXPORT_KEY
	#define VS_EXPORT_MOUSE
    
#endif
    
#if defined(VS_NO_EXPORT)
    
    //Undefine all modules
    #undef VS_EXPORT_SYSTEM
    #undef VS_EXPORT_WINDOW
    #undef VS_EXPORT_TIME
    #undef VS_EXPORT_KEY
	#undef VS_EXPORT_MOUSE
    
#endif

#if defined(VS_SYSTEM_IMPLEMENTATION)
    
    //Undefine all modules
    #undef VS_EXPORT_SYSTEM
    #undef VS_EXPORT_WINDOW
    #undef VS_EXPORT_TIME
    #undef VS_EXPORT_KEY
	#undef VS_EXPORT_MOUSE
    
#endif



////////////////////////////////////////////////////////////
///	COSTANTS
////////////////////////////////////////////////////////////

//Boolean
#define VS_FALSE 0
#define VS_TRUE 1

//Window style bitmasks
#define VS_WINSTYLE_HIDDEN (1 << 1)
#define VS_WINSTYLE_RESIZABLE (1 << 2)
#define VS_WINSTYLE_FULLSCREEN (1 << 3)
#define VS_WINSTYLE_ALLOW_HIGHDPI (1 << 4)

//Keys
enum
{
    VS_KEY_UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    VS_KEY_A = 4,
    VS_KEY_B = 5,
    VS_KEY_C = 6,
    VS_KEY_D = 7,
    VS_KEY_E = 8,
    VS_KEY_F = 9,
    VS_KEY_G = 10,
    VS_KEY_H = 11,
    VS_KEY_I = 12,
    VS_KEY_J = 13,
    VS_KEY_K = 14,
    VS_KEY_L = 15,
    VS_KEY_M = 16,
    VS_KEY_N = 17,
    VS_KEY_O = 18,
    VS_KEY_P = 19,
    VS_KEY_Q = 20,
    VS_KEY_R = 21,
    VS_KEY_S = 22,
    VS_KEY_T = 23,
    VS_KEY_U = 24,
    VS_KEY_V = 25,
    VS_KEY_W = 26,
    VS_KEY_X = 27,
    VS_KEY_Y = 28,
    VS_KEY_Z = 29,

    VS_KEY_1 = 30,
    VS_KEY_2 = 31,
    VS_KEY_3 = 32,
    VS_KEY_4 = 33,
    VS_KEY_5 = 34,
    VS_KEY_6 = 35,
    VS_KEY_7 = 36,
    VS_KEY_8 = 37,
    VS_KEY_9 = 38,
    VS_KEY_0 = 39,

    VS_KEY_RETURN = 40,
    VS_KEY_ESCAPE = 41,
    VS_KEY_BACKSPACE = 42,
    VS_KEY_TAB = 43,
    VS_KEY_SPACE = 44,

    VS_KEY_MINUS = 45,
    VS_KEY_EQUALS = 46,
    VS_KEY_LEFTBRACKET = 47,
    VS_KEY_RIGHTBRACKET = 48,
    VS_KEY_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    VS_KEY_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate VS_KEY_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    VS_KEY_SEMICOLON = 51,
    VS_KEY_APOSTROPHE = 52,
    VS_KEY_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    VS_KEY_COMMA = 54,
    VS_KEY_PERIOD = 55,
    VS_KEY_SLASH = 56,

    VS_KEY_CAPSLOCK = 57,

    VS_KEY_F1 = 58,
    VS_KEY_F2 = 59,
    VS_KEY_F3 = 60,
    VS_KEY_F4 = 61,
    VS_KEY_F5 = 62,
    VS_KEY_F6 = 63,
    VS_KEY_F7 = 64,
    VS_KEY_F8 = 65,
    VS_KEY_F9 = 66,
    VS_KEY_F10 = 67,
    VS_KEY_F11 = 68,
    VS_KEY_F12 = 69,

    VS_KEY_PRINTSCREEN = 70,
    VS_KEY_SCROLLLOCK = 71,
    VS_KEY_PAUSE = 72,
    VS_KEY_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    VS_KEY_HOME = 74,
    VS_KEY_PAGEUP = 75,
    VS_KEY_DELETE = 76,
    VS_KEY_END = 77,
    VS_KEY_PAGEDOWN = 78,
    VS_KEY_RIGHT = 79,
    VS_KEY_LEFT = 80,
    VS_KEY_DOWN = 81,
    VS_KEY_UP = 82,

    VS_KEY_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    VS_KEY_KP_DIVIDE = 84,
    VS_KEY_KP_MULTIPLY = 85,
    VS_KEY_KP_MINUS = 86,
    VS_KEY_KP_PLUS = 87,
    VS_KEY_KP_ENTER = 88,
    VS_KEY_KP_1 = 89,
    VS_KEY_KP_2 = 90,
    VS_KEY_KP_3 = 91,
    VS_KEY_KP_4 = 92,
    VS_KEY_KP_5 = 93,
    VS_KEY_KP_6 = 94,
    VS_KEY_KP_7 = 95,
    VS_KEY_KP_8 = 96,
    VS_KEY_KP_9 = 97,
    VS_KEY_KP_0 = 98,
    VS_KEY_KP_PERIOD = 99,

    VS_KEY_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    VS_KEY_APPLICATION = 101, /**< windows contextual menu, compose */
    VS_KEY_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    VS_KEY_KP_EQUALS = 103,
    VS_KEY_F13 = 104,
    VS_KEY_F14 = 105,
    VS_KEY_F15 = 106,
    VS_KEY_F16 = 107,
    VS_KEY_F17 = 108,
    VS_KEY_F18 = 109,
    VS_KEY_F19 = 110,
    VS_KEY_F20 = 111,
    VS_KEY_F21 = 112,
    VS_KEY_F22 = 113,
    VS_KEY_F23 = 114,
    VS_KEY_F24 = 115,
    VS_KEY_EXECUTE = 116,
    VS_KEY_HELP = 117,
    VS_KEY_MENU = 118,
    VS_KEY_SELECT = 119,
    VS_KEY_STOP = 120,
    VS_KEY_AGAIN = 121,   /**< redo */
    VS_KEY_UNDO = 122,
    VS_KEY_CUT = 123,
    VS_KEY_COPY = 124,
    VS_KEY_PASTE = 125,
    VS_KEY_FIND = 126,
    VS_KEY_MUTE = 127,
    VS_KEY_VOLUMEUP = 128,
    VS_KEY_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     VS_KEY_LOCKINGCAPSLOCK = 130,  */
/*     VS_KEY_LOCKINGNUMLOCK = 131, */
/*     VS_KEY_LOCKINGSCROLLLOCK = 132, */
    VS_KEY_KP_COMMA = 133,
    VS_KEY_KP_EQUALSAS400 = 134,

    VS_KEY_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    VS_KEY_INTERNATIONAL2 = 136,
    VS_KEY_INTERNATIONAL3 = 137, /**< Yen */
    VS_KEY_INTERNATIONAL4 = 138,
    VS_KEY_INTERNATIONAL5 = 139,
    VS_KEY_INTERNATIONAL6 = 140,
    VS_KEY_INTERNATIONAL7 = 141,
    VS_KEY_INTERNATIONAL8 = 142,
    VS_KEY_INTERNATIONAL9 = 143,
    VS_KEY_LANG1 = 144, /**< Hangul/English toggle */
    VS_KEY_LANG2 = 145, /**< Hanja conversion */
    VS_KEY_LANG3 = 146, /**< Katakana */
    VS_KEY_LANG4 = 147, /**< Hiragana */
    VS_KEY_LANG5 = 148, /**< Zenkaku/Hankaku */
    VS_KEY_LANG6 = 149, /**< reserved */
    VS_KEY_LANG7 = 150, /**< reserved */
    VS_KEY_LANG8 = 151, /**< reserved */
    VS_KEY_LANG9 = 152, /**< reserved */

    VS_KEY_ALTERASE = 153, /**< Erase-Eaze */
    VS_KEY_SYSREQ = 154,
    VS_KEY_CANCEL = 155,
    VS_KEY_CLEAR = 156,
    VS_KEY_PRIOR = 157,
    VS_KEY_RETURN2 = 158,
    VS_KEY_SEPARATOR = 159,
    VS_KEY_OUT = 160,
    VS_KEY_OPER = 161,
    VS_KEY_CLEARAGAIN = 162,
    VS_KEY_CRSEL = 163,
    VS_KEY_EXSEL = 164,

    VS_KEY_KP_00 = 176,
    VS_KEY_KP_000 = 177,
    VS_KEY_THOUSANDSSEPARATOR = 178,
    VS_KEY_DECIMALSEPARATOR = 179,
    VS_KEY_CURRENCYUNIT = 180,
    VS_KEY_CURRENCYSUBUNIT = 181,
    VS_KEY_KP_LEFTPAREN = 182,
    VS_KEY_KP_RIGHTPAREN = 183,
    VS_KEY_KP_LEFTBRACE = 184,
    VS_KEY_KP_RIGHTBRACE = 185,
    VS_KEY_KP_TAB = 186,
    VS_KEY_KP_BACKSPACE = 187,
    VS_KEY_KP_A = 188,
    VS_KEY_KP_B = 189,
    VS_KEY_KP_C = 190,
    VS_KEY_KP_D = 191,
    VS_KEY_KP_E = 192,
    VS_KEY_KP_F = 193,
    VS_KEY_KP_XOR = 194,
    VS_KEY_KP_POWER = 195,
    VS_KEY_KP_PERCENT = 196,
    VS_KEY_KP_LESS = 197,
    VS_KEY_KP_GREATER = 198,
    VS_KEY_KP_AMPERSAND = 199,
    VS_KEY_KP_DBLAMPERSAND = 200,
    VS_KEY_KP_VERTICALBAR = 201,
    VS_KEY_KP_DBLVERTICALBAR = 202,
    VS_KEY_KP_COLON = 203,
    VS_KEY_KP_HASH = 204,
    VS_KEY_KP_SPACE = 205,
    VS_KEY_KP_AT = 206,
    VS_KEY_KP_EXCLAM = 207,
    VS_KEY_KP_MEMSTORE = 208,
    VS_KEY_KP_MEMRECALL = 209,
    VS_KEY_KP_MEMCLEAR = 210,
    VS_KEY_KP_MEMADD = 211,
    VS_KEY_KP_MEMSUBTRACT = 212,
    VS_KEY_KP_MEMMULTIPLY = 213,
    VS_KEY_KP_MEMDIVIDE = 214,
    VS_KEY_KP_PLUSMINUS = 215,
    VS_KEY_KP_CLEAR = 216,
    VS_KEY_KP_CLEARENTRY = 217,
    VS_KEY_KP_BINARY = 218,
    VS_KEY_KP_OCTAL = 219,
    VS_KEY_KP_DECIMAL = 220,
    VS_KEY_KP_HEXADECIMAL = 221,

    VS_KEY_LCTRL = 224,
    VS_KEY_LSHIFT = 225,
    VS_KEY_LALT = 226, /**< alt, option */
    VS_KEY_LGUI = 227, /**< windows, command (apple), meta */
    VS_KEY_RCTRL = 228,
    VS_KEY_RSHIFT = 229,
    VS_KEY_RALT = 230, /**< alt gr, option */
    VS_KEY_RGUI = 231, /**< windows, command (apple), meta */

    VS_KEY_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    VS_KEY_AUDIONEXT = 258,
    VS_KEY_AUDIOPREV = 259,
    VS_KEY_AUDIOSTOP = 260,
    VS_KEY_AUDIOPLAY = 261,
    VS_KEY_AUDIOMUTE = 262,
    VS_KEY_MEDIASELECT = 263,
    VS_KEY_WWW = 264,
    VS_KEY_MAIL = 265,
    VS_KEY_CALCULATOR = 266,
    VS_KEY_COMPUTER = 267,
    VS_KEY_AC_SEARCH = 268,
    VS_KEY_AC_HOME = 269,
    VS_KEY_AC_BACK = 270,
    VS_KEY_AC_FORWARD = 271,
    VS_KEY_AC_STOP = 272,
    VS_KEY_AC_REFRESH = 273,
    VS_KEY_AC_BOOKMARKS = 274,

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    VS_KEY_BRIGHTNESSDOWN = 275,
    VS_KEY_BRIGHTNESSUP = 276,
    VS_KEY_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    VS_KEY_KBDILLUMTOGGLE = 278,
    VS_KEY_KBDILLUMDOWN = 279,
    VS_KEY_KBDILLUMUP = 280,
    VS_KEY_EJECT = 281,
    VS_KEY_SLEEP = 282,

    VS_KEY_APP1 = 283,
    VS_KEY_APP2 = 284,

    /* @} *//* Walther keys */

    /* Add any other keys here. */

    VS_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
};

//Mouse buttons
#define VS_BTN_LEFT 1
#define VS_BTN_MIDDLE 2
#define VS_BTN_RIGHT 3



#ifdef VS_EXPORT_SYSTEM

////////////////////////////////////////////////////////////
///	VSSYSTEM
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief	Initialize the library and create a window
///	with opengl context
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsSystemInit(const char* title, int w, int h, int fps, int style);

////////////////////////////////////////////////////////////
/// \brief	Poll events, must be called once per frame.
/// Update key and mouse states and update elapsed time
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemPollEvents();

////////////////////////////////////////////////////////////
/// \brief	Bind a function to the mouse moved event	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemBindEventMouseMoved(void(*mouseMoved)(int x, int y));

////////////////////////////////////////////////////////////
/// \brief	Bind a function to the mouse click event	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemBindEventMouseClick(void(*mouseClick)(int btn));

////////////////////////////////////////////////////////////
/// \brief	Bind a function to the key press event	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemBindEventKeyPress(void(*keyPress)(int key));

////////////////////////////////////////////////////////////
/// \brief	Bind a function to the quit event	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemBindEventQuit(void(*quit)());

////////////////////////////////////////////////////////////
/// \brief	Unbind all the callbacks	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemUnbindAll();

////////////////////////////////////////////////////////////
/// \brief	Destroy the library	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsSystemDestroy();

#endif //VS_EXPORT_SYSTEM



#ifdef VS_EXPORT_WINDOW

////////////////////////////////////////////////////////////
///	WINDOW
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief	Swap window buffers	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsWindowSwapBuffers();

////////////////////////////////////////////////////////////
/// \brief	Set window title	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsWindowSetTitle(const char* title);

////////////////////////////////////////////////////////////
/// \brief	Set window size	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsWindowSetSize(int w, int h);

////////////////////////////////////////////////////////////
/// \brief	Close the window, vsWindowIsOpen will return 0	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsWindowClose();

////////////////////////////////////////////////////////////
/// \brief	Get window title	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API const char* vsWindowGetTitle();

////////////////////////////////////////////////////////////
/// \brief	Get window Width	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsWindowGetWidth();

////////////////////////////////////////////////////////////
/// \brief	Get window height	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsWindowGetHeight();

////////////////////////////////////////////////////////////
/// \brief	Verify if the window is open	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsWindowIsOpen();

////////////////////////////////////////////////////////////
/// \brief	Get window style	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsWindowGetStyle();

#endif //VS_EXPORT_WINDOW



#ifdef VS_EXPORT_TIME

////////////////////////////////////////////////////////////
///	TIME
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief	Get time in milliseconds from the start of the
/// program
///
////////////////////////////////////////////////////////////
VSSYSTEM_API double vsTimeGetFromStart();

////////////////////////////////////////////////////////////
/// \brief	Get elapsed time between frames in milliseconds
///
////////////////////////////////////////////////////////////
VSSYSTEM_API double vsTimeGetElapsed();

////////////////////////////////////////////////////////////
/// \brief	Sleep for X ammount of time, in milliseconds	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API void vsTimeSleep(double millisecs);

#endif //VS_EXPORT_TIME



#ifdef VS_EXPORT_KEY

////////////////////////////////////////////////////////////
///	KEY
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief	Get key state (released, pressed, down)
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsKeyGetState(int key);

#endif //VS_ESPORT_KEY



#ifdef VS_EXPORT_MOUSE

////////////////////////////////////////////////////////////
///	MOUSE
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// \brief	Get mouse button state (released, pressed, down)	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsMouseGetState(int button);

////////////////////////////////////////////////////////////
/// \brief	Get mouse x position in the window	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsMouseGetX();

////////////////////////////////////////////////////////////
/// \brief	Get mouse y position in the window	
///
////////////////////////////////////////////////////////////
VSSYSTEM_API int vsMouseGetY();

#endif //VS_EXPORT_MOUSE

#ifdef __cplusplus
} //extern C
#endif

#endif //VS_SYSTEM_H



////////////////////////////////////////////////////////////
///	IMPLEMENTATION
////////////////////////////////////////////////////////////
#if defined(VS_SYSTEM_IMPLEMENTATION)

////////////////////////////////////////////////////////////
///	INCLUDES
////////////////////////////////////////////////////////////
#include <SDL2/SDL.h>



////////////////////////////////////////////////////////////
///	LOG
////////////////////////////////////////////////////////////
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__) 
#define ERROR(msg) printf("[ERROR] in %s l%d: %s\n", __FILENAME__, __LINE__, msg)



////////////////////////////////////////////////////////////
///	GLOBAL DATA
////////////////////////////////////////////////////////////
SDL_Window* window = NULL;
SDL_GLContext glcontext = NULL;
double elapsed_time = 16.6;
double old_time = 0;
int winwidth = 0;
int winheight = 0;
int winstyle = 0;
int winopen = 0;
const unsigned char* keys;
void(*mouseMovedEvent)(int x, int y) = NULL;
void(*mouseClickEvent)(int btn) = NULL;
void(*keyPressEvent)(int key) = NULL;
void(*quitEvent)() = NULL;



////////////////////////////////////////////////////////////
///	SYSTEM
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
int vsSystemInit(const char* title, int w, int h, int fps, int style)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0) {
		ERROR("can't initialize SDL2 libray");
		return VS_FALSE;
	}
	
	//Shortcut
	#define CHECK_BITMASK(var, mask) ((var & mask) == mask) ? 1 : 0

	//Create window
	if (CHECK_BITMASK(style, VS_WINSTYLE_HIDDEN)) winstyle |= SDL_WINDOW_HIDDEN;
	if (CHECK_BITMASK(style, VS_WINSTYLE_RESIZABLE)) winstyle |= SDL_WINDOW_RESIZABLE;
	if (CHECK_BITMASK(style, VS_WINSTYLE_FULLSCREEN)) winstyle |= SDL_WINDOW_FULLSCREEN;
	if (CHECK_BITMASK(style, VS_WINSTYLE_ALLOW_HIGHDPI)) winstyle |= SDL_WINDOW_ALLOW_HIGHDPI;
	winstyle |= SDL_WINDOW_OPENGL;
	winwidth = w;
	winheight = h;
	winopen = VS_TRUE;
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								w, h, winstyle);
	if (!window) {
		ERROR("can't create the window");
		return VS_FALSE;
	}

	//Create opengl context
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);	
	glcontext = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(fps);
		
	//Get key state address
	keys = SDL_GetKeyboardState(NULL);

	return VS_TRUE;
}

////////////////////////////////////////////////////////////
void vsSystemPollEvents()
{
	//Update time
	elapsed_time = SDL_GetTicks() - old_time;
	old_time = SDL_GetTicks();

	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
			case SDL_MOUSEMOTION:
				if (mouseMovedEvent) mouseMovedEvent(ev.motion.x, ev.motion.y);	
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (mouseClickEvent) mouseClickEvent(ev.button.button);	
				break;

			case SDL_KEYDOWN:
				if (keyPressEvent) keyPressEvent(ev.key.keysym.scancode);
				break;

			case SDL_QUIT:
				if (quitEvent) quitEvent();
				break;
		}
	}
}

////////////////////////////////////////////////////////////
void vsSystemBindEventMouseMoved(void(*mouseMoved)(int x, int y))
{
	mouseMovedEvent = mouseMoved;
}

////////////////////////////////////////////////////////////
void vsSystemBindEventMouseClick(void(*mouseClick)(int btn))
{
	mouseClickEvent = mouseClick;
}

////////////////////////////////////////////////////////////
void vsSystemBindEventKeyPress(void(*keyPress)(int key))
{
	keyPressEvent = keyPress;
}

////////////////////////////////////////////////////////////
void vsSystemBindEventQuit(void(*quit)())
{
	quitEvent = quit;
}

////////////////////////////////////////////////////////////
void vsSystemUnbindAll()
{
	mouseMovedEvent = NULL;
	mouseClickEvent = NULL;
	keyPressEvent = NULL;
	quitEvent = NULL;
}

////////////////////////////////////////////////////////////
void vsSystemDestroy()
{
	//Destroy opengl context
	SDL_GL_DeleteContext(glcontext);
	
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL
	SDL_Quit();
}



////////////////////////////////////////////////////////////
///	WINDOW
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
void vsWindowSwapBuffers()
{
	SDL_GL_SwapWindow(window);
}

////////////////////////////////////////////////////////////
void vsWindowSetTitle(const char* title)
{
	SDL_SetWindowTitle(window, title);
}

////////////////////////////////////////////////////////////
void vsWindowSetSize(int w, int h)
{
	SDL_SetWindowSize(window, w, h);
	winwidth = w;
	winheight = h;
}

////////////////////////////////////////////////////////////
void vsWindowClose()
{
	winopen = VS_FALSE;
}

////////////////////////////////////////////////////////////
const char* vsWindowGetTitle()
{
	return SDL_GetWindowTitle(window);
}

////////////////////////////////////////////////////////////
int vsWindowGetWidth()
{
	return winwidth;
}

////////////////////////////////////////////////////////////
int vsWindowGetHeight()
{
	return winheight;
}

////////////////////////////////////////////////////////////
int vsWindowIsOpen()
{
	return winopen;
}

////////////////////////////////////////////////////////////
int vsWindowGetStyle()
{
	return winstyle;
}



////////////////////////////////////////////////////////////
///	TIME
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
double vsTimeGetFromStart()
{
	return SDL_GetTicks();
}

////////////////////////////////////////////////////////////
double vsTimeGetElapsed()
{
	return elapsed_time;
}

////////////////////////////////////////////////////////////
void vsTimeSleep(double millisecs)
{
	SDL_Delay(millisecs);
}



////////////////////////////////////////////////////////////
///	KEY
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
int vsKeyGetState(int key)
{
	return keys[key];
}



////////////////////////////////////////////////////////////
///	MOUSE
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
int vsMouseGetState(int button)
{
	unsigned int bitmask = SDL_GetMouseState(NULL, NULL);
	switch (button)
	{
		case VS_BTN_LEFT: return (bitmask & SDL_BUTTON(SDL_BUTTON_LEFT));
		case VS_BTN_MIDDLE: return (bitmask & SDL_BUTTON(SDL_BUTTON_MIDDLE));
		case VS_BTN_RIGHT: return (bitmask & SDL_BUTTON(SDL_BUTTON_RIGHT));
		default: return 0;
	}
}

////////////////////////////////////////////////////////////
int vsMouseGetX()
{
	int x;
	SDL_GetMouseState(&x, NULL);
	return x;
}
////////////////////////////////////////////////////////////
int vsMouseGetY()
{
	int y;
	SDL_GetMouseState(NULL, &y);
	return y;
}

#endif //VS_SYSTEM_IMPLEMENTATION
