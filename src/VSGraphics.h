//=======================================================================================
//								VIRUAL SHOCK ENGINE
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
#ifndef VS_GRAPHICS_H
#define VS_GRAPHICS_H

#ifdef __cplusplus
extern "C" {
#endif

// ================================
// ====>> OS
// ================================

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

    #if defined(VSGRAPHICS_EXPORTS)
        #define VSGRAPHICS_API __declspec(dllexport)
    #else
        #define VSGRAPHICS_API __declspec(dllimport)
    #endif

#else

    #define VSGRAPHICS_API

#endif
    
    
    
    
// ================================
// ====>> MODULE MANAGER
// ================================

/*
 
 Modules:
    VECTOR2
    RECT
    COLOR
    GRAPHICS
    VIEW
    BITMAP
    TEXTURE
    SHADER
    SPRITE
    FONT
	TEXT
	RENDERER
 
 By default all moudules are exported.
 To export only one specific module, you should
 define VS_ONLY_$MODULE before including this file.
 
 Example:
    #define VS_ONLY_TEXTURE
    #include "VSGraphics.h"
 
 You can pick also multiple specific modules.
 
 Example:
    #define VS_ONLY_TEXTURE
    #define VS_ONLY_VIEW
    #define VS_ONLY_RENDERER
    #include "VSGraphics.h"
 
 If you want just the OS defines you should
 define VS_NO_EXPORT before including this file
 
 */
    
#if defined(VS_ONLY_VECTOR2) || defined(VS_ONLY_RECT) || defined(VS_ONLY_COLOR)||\
    defined(VS_ONLY_GRAPHICS) || defined(VS_ONLY_VIEW) || defined(VS_ONLY_BITMAP) ||\
	defined(VS_ONLY_TEXTURE) || defined(VS_ONLY_SHADER) || defined(VS_ONLY_SPRITE) ||\
	defined(VS_ONLY_FONT) || defined(VS_ONLY_TEXT) || defined(VS_ONLY_RENDERER)
    
#ifdef VS_ONLY_VECTOR2
    #define VS_EXPORT_VECTOR2
#endif
    
#ifdef VS_ONLY_RECT
    #define VS_EXPORT_RECT
#endif
    
#ifdef VS_ONLY_COLOR
    #define VS_EXPORT_COLOR
#endif
    
#ifdef VS_ONLY_GRAPHICS
    #define VS_EXPORT_GRAPHICS
#endif
    
#ifdef VS_ONLY_VIEW
    #define VS_EXPORT_RECT
    #define VS_EXPORT_VIEW
#endif

#ifdef VS_ONLY_BITMAP
	#define VS_EXPORT_BITMAP
#endif
    
#ifdef VS_ONLY_TEXTURE
    #define VS_EXPORT_VECTOR2
    #define VS_EXPORT_TEXTURE
	#define VS_EXPORT_BITMAP
#endif
    
#ifdef VS_ONLY_SHADER
    #define VS_EXPORT_SHADER
#endif
    
#ifdef VS_ONLY_SPRITE
    #define VS_EXPORT_SPRITE
	#define VS_EXPORT_TEXTURE
	#define VS_EXPORT_BITMAP
#endif

#ifdef VS_ONLY_FONT
	#define VS_EXPORT_RECT
	#define VS_EXPORT_FONT
	#define VS_EXPORT_TEXTURE
	#define VS_EXPORT_BITMAP
#endif

#ifdef VS_ONLY_TEXT
	#define VS_EXPORT_FONT
	#define VS_EXPORT_TEXT
#endif	

#ifdef VS_ONLY_RENDERER
    #define VS_EXPORT_RENDERER
    #define VS_EXPORT_SPRITE
    #define VS_EXPORT_TEXTURE
	#define VS_EXPORT_BITMAP
#endif
    
#else
    
    //Define all modules
    #define VS_EXPORT_VECTOR2
    #define VS_EXPORT_RECT
    #define VS_EXPORT_COLOR
    #define VS_EXPORT_GRAPHICS
    #define VS_EXPORT_VIEW
    #define VS_EXPORT_BITMAP
    #define VS_EXPORT_TEXTURE
    #define VS_EXPORT_SHADER
    #define VS_EXPORT_SPRITE
	#define VS_EXPORT_FONT
	#define VS_EXPORT_TEXT
	#define VS_EXPORT_RENDERER
    
#endif
 
//Undefine all modules
#if defined(VS_NO_EXPORT)
    
    #undef VS_EXPORT_VECTOR2
    #undef VS_EXPORT_RECT
    #undef VS_EXPORT_COLOR
    #undef VS_EXPORT_GRAPHICS
    #undef VS_EXPORT_VIEW
    #undef VS_EXPORT_BITMAP
    #undef VS_EXPORT_TEXTURE
    #undef VS_EXPORT_SHADER
    #undef VS_EXPORT_SPRITE
	#undef VS_EXPORT_FONT
	#undef VS_EXPORT_TEXT
    #undef VS_EXPORT_RENDERER
    
#endif

//For the implementation we need only
//3 modules
#if defined(VS_GRAPHICS_IMPLEMENTATION)
    
    #define VS_EXPORT_VECTOR2
    #define VS_EXPORT_RECT
    #define VS_EXPORT_COLOR
    #undef VS_EXPORT_GRAPHICS
    #undef VS_EXPORT_VIEW
    #undef VS_EXPORT_BITMAP
    #undef VS_EXPORT_TEXTURE
    #undef VS_EXPORT_SHADER
    #undef VS_EXPORT_SPRITE
	#undef VS_EXPORT_FONT
	#undef VS_EXPORT_TEXT
    #undef VS_EXPORT_RENDERER
    
#endif



    
// ================================
// ====>> CONSTANTS
// ================================

//This macro allow to use fonts
//for text rendering.
//It require the freetype library.
//#define VS_FREETYPE

//Boolean values
#define VS_FALSE 0
#define VS_TRUE 1

//Shaders types
#define VS_SHADER_VERTEX 0
#define VS_SHADER_FRAGMENT 1

//Shader parameters types
#define VS_SHADER_PARAM_UNIFORM 2
#define VS_SHADER_PARAM_ATTRIBUTE 3

//Font start and end characters
#define VS_FONT_CH_START 32
#define VS_FONT_CH_END 127
#define VS_FONT_CH_COUNT (VS_FONT_CH_END - VS_FONT_CH_START)

//Text alignment
#define VS_TEXT_ALIGN_LEFT 0
#define VS_TEXT_ALIGN_CENTER 1

#ifdef VS_EXPORT_VECTOR2

// ================================
// ====>> VECTOR2
// ================================ 

////////////////////////////////////////////////////////////
/// \brief	2 dimensional vector	
///
////////////////////////////////////////////////////////////
typedef struct vsVector2 { float x, y; } vsVector2;

////////////////////////////////////////////////////////////
/// \brief Create a vector from its base components
///
////////////////////////////////////////////////////////////
#define VSVECTOR2(x, y) (vsVector2){x, y}
    
#endif // VS_EXPORT_VECTOR2
    


    
#ifdef VS_EXPORT_RECT

// ================================
// ====>> RECT
// ================================
    
////////////////////////////////////////////////////////////
/// \brief	2 dimensional area		
///
////////////////////////////////////////////////////////////
typedef struct vsRect { float x, y, w, h; } vsRect;
    
////////////////////////////////////////////////////////////
/// \brief Create a rect from its base components
///
////////////////////////////////////////////////////////////
#define VSRECT(x, y, w, h) (vsRect){x, y, w, h}
    
#endif // VS_EXPORT_RECT
    
    
    
    
#ifdef VS_EXPORT_COLOR
    
// ================================
// ====>> COLOR
// ================================

///////////////////////////////////////////////////////////
/// \brief RGBA Color
///
///////////////////////////////////////////////////////////
typedef struct vsColor { unsigned char r, g, b, a; } vsColor;

////////////////////////////////////////////////////////////
/// \brief Create a vector from its base components
///
////////////////////////////////////////////////////////////
#define VSCOLOR(r, g, b, a) (vsColor){r, g, b, a}

#define VS_COLOR_WHITE	VSCOLOR( 255, 255, 255, 255 )
#define VS_COLOR_RED	VSCOLOR( 255, 0, 0, 255 )
#define VS_COLOR_GREEN	VSCOLOR( 0, 255, 0, 255 )
#define VS_COLOR_BLUE	VSCOLOR( 0, 0, 255, 255 )
#define VS_COLOR_BLACK	VSCOLOR( 0, 0, 0, 255 )

#endif // VS_EXPORT_COLOR




#ifdef VS_EXPORT_GRAPHICS

// ================================
// ====>> VSGRAPHICS
// ================================ 

////////////////////////////////////////////////////////////
/// \brief	Initialize the library. Must be called after
/// a opengl context is created
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsGraphicsInit();

////////////////////////////////////////////////////////////
/// \brief	Destroy the library	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsGraphicsDestroy();

#endif // VS_EXPORT_GRAPHICS




#ifdef VS_EXPORT_VIEW

// ================================
// ====>> VIEW
// ================================ 

////////////////////////////////////////////////////////////
/// \brief	The view allow to controll what part of the
/// virtual space is rendered on the screen
///
////////////////////////////////////////////////////////////
typedef struct vsView
{
	vsRect viewport;
	vsVector2 center;
	vsVector2 size;
	float rotation;
	float matrix[16];
} vsView;

////////////////////////////////////////////////////////////
/// \brief	Apply view changes	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsViewSet(vsView view);

////////////////////////////////////////////////////////////
/// \brief	Set the specified view as current
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsViewCreate(vsRect viewport, vsVector2 center,
									vsVector2 size, float angle);

////////////////////////////////////////////////////////////
/// \brief	Get the view center position in space
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsVector2 vsViewGetCenter();

////////////////////////////////////////////////////////////
/// \brief	Get the view size
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsVector2 vsViewGetSize();

////////////////////////////////////////////////////////////
/// \brief	Get the view rotation	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API float vsViewGetRotation();

#endif // VS_EXPORT_VIEW




#ifdef VS_EXPORT_BITMAP

// ================================
// ====>> BITMAP
// ================================

////////////////////////////////////////////////////////////
/// \brief	A bitmap defines a display space and the color
///	for each pixel or "bit" in the display space	
///
////////////////////////////////////////////////////////////
typedef struct vsBitmap vsBitmap;

////////////////////////////////////////////////////////////
/// \brief	Initialize the bitmap	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsBitmap* vsBitmapInit();

////////////////////////////////////////////////////////////
/// \brief	Unload the bitmap	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsBitmapUnload(vsBitmap* bitmap);

////////////////////////////////////////////////////////////
/// \brief	Destroy the bitmap	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsBitmapDestroy(vsBitmap* bitmap);

////////////////////////////////////////////////////////////
/// \brief	Load bitmap from file	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsBitmapLoad(vsBitmap* bitmap, const char* filepath);

////////////////////////////////////////////////////////////
/// \brief	Load bitmap from data	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsBitmapLoadFromData(vsBitmap* bitmap, unsigned char* data,
							int width, int height, int channels);

////////////////////////////////////////////////////////////
/// \brief	Get bitmap size	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsVector2 vsBitmapGetSize(vsBitmap* bitmap);

////////////////////////////////////////////////////////////
/// \brief	Get bitmap channels	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API int vsBitmapGetChannels(vsBitmap* bitmap);

////////////////////////////////////////////////////////////
/// \brief	Get bitmap data	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API const unsigned char* vsBitmapGetData(vsBitmap* bitmap);

#endif // VS_EXPORT_BITMAP
    
    
    

#ifdef VS_EXPORT_TEXTURE

// ================================
// ====>> TEXTURE
// ================================

////////////////////////////////////////////////////////////
/// \brief Image living on the graphics card that can be 
/// used for drawing
///
////////////////////////////////////////////////////////////
typedef struct vsTexture
{
	unsigned int id;
	vsVector2 size;
	int smooth;
	int repeated;
} vsTexture;

////////////////////////////////////////////////////////////
/// \brief	Initialize the texture	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsTexture* vsTextureInit();

////////////////////////////////////////////////////////////
/// \brief	Destroy the texture	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureDestroy(vsTexture* texture);

////////////////////////////////////////////////////////////
/// \brief	Load the texture from file	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureLoad(vsTexture* texture, const char* filepath);
    
///////////////////////////////////////////////////////////
/// \brief Load the texture from data
///
///////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureLoadFromData(vsTexture* texture, vsBitmap* bitmap);

////////////////////////////////////////////////////////////
/// \brief	Unload the texture	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureUnload(vsTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Enable or disable the smooth filter
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureSetSmooth(vsTexture* texture, const int smooth);

////////////////////////////////////////////////////////////
/// \brief	Enable or disable repeating	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsTextureSetRepeated(vsTexture* texture, const int repeated);

////////////////////////////////////////////////////////////
/// \brief	Get the texture with and height	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsVector2 vsTextureGetSize(vsTexture* texture);

////////////////////////////////////////////////////////////
/// \brief	Check if the smooth filter is enabled or not	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API int vsTextureIsSmooth(vsTexture* texture);

////////////////////////////////////////////////////////////
/// \brief	Check if the texture is repeated or not	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API int vsTextureIsRepeated(vsTexture* texture);

#endif // VS_EXPORT_TEXTURE




#ifdef VS_EXPORT_SHADER

// ================================
// ====>> SHADER
// ================================

////////////////////////////////////////////////////////////
/// \brief	Vertex and Fragment shader program	
///
////////////////////////////////////////////////////////////
typedef struct vsShader vsShader;

////////////////////////////////////////////////////////////
/// \brief	Initialize the shader	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsShader* vsShaderInit();

////////////////////////////////////////////////////////////
/// \brief	Destroy the shader	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderDestroy(vsShader* shader);

////////////////////////////////////////////////////////////
/// \brief	Load shader from file	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderLoad(vsShader* shader, const char* filepath, int shadertype);

////////////////////////////////////////////////////////////
/// \brief	Load shader from file
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderLoad2(vsShader* shader, const char* vertexshader_path,
                                  const char* fragmentshader_path);
    
///////////////////////////////////////////////////////////
/// \brief Bind the shader as current
///
///////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderBind(vsShader* shader);
    
////////////////////////////////////////////////////////////
/// \brief Compile shader from source
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderCompile(vsShader* shader, const char* source, int shadertype);
    
////////////////////////////////////////////////////////////
/// \brief Compile shader from source
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderCompile2(vsShader* shader, const char* vertexsource,
                                     const char* fragmentsource);

////////////////////////////////////////////////////////////
/// \brief	Unload the shader	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderUnload(vsShader* shader);

////////////////////////////////////////////////////////////
/// \brief	Get the shader identifier
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API unsigned int vsShaderGetID(vsShader* shader);

////////////////////////////////////////////////////////////
/// \brief	Set shader parameter	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderSetParam1(vsShader* shader, const char* paramname, int paramtype,
										const float x);

////////////////////////////////////////////////////////////
/// \brief	Set shader parameters	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderSetParam2(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y);

////////////////////////////////////////////////////////////
/// \brief	Set shader parameters	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderSetParam3(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y, const float z);

////////////////////////////////////////////////////////////
/// \brief	Set shader parameters	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsShaderSetParam4(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y, const float z,
										const float w);


#endif // VS_EXPORT_SHADER




#ifdef VS_EXPORT_SPRITE

// ================================
// ====>> SPRITE
// ================================ 

typedef struct vsSprite
{
    vsTexture* texture;
    vsRect texsource;
    vsVector2 position;
    vsVector2 size;
    vsVector2 origin;
	float rotation;
    vsColor color;
} vsSprite;

#endif // VS_EXPORT_SPRITE




#if defined(VS_EXPORT_FONT) && defined(VS_FREETYPE)

// ================================
// ====>> FONT
// ================================ 

typedef struct vsFont
{
	vsTexture* texture;
	unsigned int ch_height;
	unsigned int *ch_widths;
	vsRect *texcoords_table;
} vsFont;

////////////////////////////////////////////////////////////
/// \brief	Initialize font	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsFont* vsFontInit();

////////////////////////////////////////////////////////////
/// \brief	Destroy font	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsFontDestroy(vsFont* bmf);

////////////////////////////////////////////////////////////
/// \brief	Load font from file	
///
///////////////////////////////////////////////////////////int/
VSGRAPHICS_API void vsFontLoad(vsFont* font, const char* filepath, unsigned int size);

////////////////////////////////////////////////////////////
/// \brief	Get font texture	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API vsTexture* vsFontGetTexture(vsFont* font);

////////////////////////////////////////////////////////////
/// \brief	Get rect texture coordinates of a character	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API const vsRect* vsFontGetTexCoord(vsFont* font, const char ch);

////////////////////////////////////////////////////////////
/// \brief	Get text lenght	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API unsigned int vsFontGetLenght(vsFont* font, const char* text, float scalex);

#endif // VS_EXPORT_FONT




#if defined(VS_EXPORT_TEXT) && defined(VS_FREETYPE)

// ================================
// ====>> TEXT
// ================================ 

typedef struct vsText
{
	vsFont* font;
	char* text;
	vsVector2 pos;
	vsVector2 scale;
	unsigned int alignment;
	vsColor color;
} vsText;

#endif




#ifdef VS_EXPORT_RENDERER
    
// ================================
// ====>> RENDERER
// ================================

////////////////////////////////////////////////////////////
/// \brief Clear the screen
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererClear();
    
////////////////////////////////////////////////////////////
/// \brief	Draw on the screen things that are in queue	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererDisplay();

////////////////////////////////////////////////////////////
/// \brief	Draw a sprite on the screen	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererDrawSprite(vsSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief	Draw a quad on the screen
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererDrawRect(vsTexture* texture, float tx, float ty, float tw, float th,
										float x, float y, float w, float h, vsColor color);

#if defined(VS_FREETYPE)

////////////////////////////////////////////////////////////
/// \brief	Draw text on the screen	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererDrawTextRaw(vsFont* font, const char* text, float x, float y,
											float scalex, float scaley, unsigned int alignment,
											vsColor color);

////////////////////////////////////////////////////////////
/// \brief	Draw text on the screen	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererDrawText(vsText* text);

#endif

////////////////////////////////////////////////////////////
/// \brief	Enable/Disable wireframe	
///
////////////////////////////////////////////////////////////
VSGRAPHICS_API void vsRendererToggleWireFrame();

#endif // VS_EXPORT_RENDERER

#ifdef __cplusplus
} // extern C 
#endif

#endif // VS_GRAPHICS_H



////////////////////////////////////////////////////////////
///	IMPLEMENTATION
////////////////////////////////////////////////////////////
#ifdef VS_GRAPHICS_IMPLEMENTATION

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define STBI_NO_PSD
#define STBI_NO_GIF
#define STBI_NO_HDR
#define STBI_NO_PIC
#define STBI_NO_PNM
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#if defined(VS_FREETYPE)
	#include <ft2build.h>
	#include FT_FREETYPE_H
#endif

#if defined(VS_SYS_LINUX)
	#define GL_GLEXT_PROTOTYPES
	#include <GL/gl.h>
	#include <GL/glext.h>
#elif defined(VS_SYS_MAC)
    #include <Opengl/gl.h>
#elif defined(VS_SYS_IOS)
    #include <OpenglES/ES1/gl.h>
#elif defined(VS_SYS_WINDOWS)
    #include <GL/glew.h>
#endif




// ================================
// ====>> STRUCTURES
// ================================

////////////////////////////////////////////////////////////
typedef struct vsGLState
{
	unsigned int currentTexture;
	unsigned int currentShader;
	unsigned int currentArrayBuffer;
} vsGLState;

////////////////////////////////////////////////////////////
typedef struct vsView
{
	vsRect viewport;
	vsVector2 center;
	vsVector2 size;
	float rotation;
	float matrix[16];
} vsView;

////////////////////////////////////////////////////////////
typedef struct vsBitmap
{
	unsigned char* data;
	int width, height;
	int channels;
} vsBitmap;

////////////////////////////////////////////////////////////
typedef struct vsTexture
{
	unsigned int id;
	vsVector2 size;
	int smooth;
	int repeated;
} vsTexture;

////////////////////////////////////////////////////////////
typedef struct vsShader
{
	unsigned int id;
	const char** paramnames;
	int* parampos;
	int paramcount;
	int paramcapacity;
} vsShader;

////////////////////////////////////////////////////////////
typedef struct vsSprite
{
    vsTexture* texture;
    vsRect texsource;
    vsVector2 position;
    vsVector2 size;
    vsVector2 origin;
	float rotation;
    vsColor color;
} vsSprite;

////////////////////////////////////////////////////////////
typedef struct vsFont
{
	vsTexture* texture;
	unsigned int ch_height;
	unsigned int *ch_widths;
	vsRect *texcoords_table;
} vsFont;

////////////////////////////////////////////////////////////
typedef struct vsText
{
	vsFont* font;
	char* text;
	vsVector2 pos;
	vsVector2 scale;
	unsigned int alignment;
	vsColor color;
} vsText;

////////////////////////////////////////////////////////////
typedef struct vsRenderer
{
	float vertexbuf[1024][2];
	float texsourcebuf[1024][2];
	unsigned char colorbuf[1024][4];
	unsigned int ibo;
	int buffersize;
	int countverts;
	int wireframe;
} vsRenderer;

static vsGLState glstate;
static vsView currentView;
static vsRenderer renderer;

#if defined(VS_FREETYPE)
static FT_Library ftlib;
#endif



// ================================
// ====>> GLSTATE
// ================================ 

////////////////////////////////////////////////////////////
void vsGLStateBindTexture(unsigned int id)
{
	if (glstate.currentTexture == id) return;
	glBindTexture(GL_TEXTURE_2D, id);
	glstate.currentTexture = id;
}

////////////////////////////////////////////////////////////
void vsGLStateBindShader(unsigned int id)
{
    #if !defined(VS_SYS_IOS)
    if (glstate.currentShader == id) return;
    glUseProgram(id);
    glstate.currentShader = id;
    #endif
}

////////////////////////////////////////////////////////////
void vsGLStateBindBuffer(unsigned int id, unsigned int type)
{
	if (glstate.currentArrayBuffer == id) return;
	glBindBuffer(type, id);
	glstate.currentArrayBuffer = id;
}

////////////////////////////////////////////////////////////
void vsGLStateReset()
{
	vsGLStateBindTexture(0);
	vsGLStateBindShader(0);
	vsGLStateBindBuffer(0, GL_ARRAY_BUFFER);
}





// ================================
// ====>> VSGRAPHICS
// ================================ 

////////////////////////////////////////////////////////////
void vsGraphicsInit()
{
	//Clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	//Init opengl
	//Enable textures
	glEnable(GL_TEXTURE_2D);

	//Enable Alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Enable vertex array
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//Reset glstate
	vsGLStateReset();

	//Setup renderer
	renderer.buffersize = 0;
	renderer.countverts = 0;
	renderer.wireframe = 0;

	//Generate indices buffer object
	glGenBuffers(1, &renderer.ibo);
     
	//Calculate indices data
	const int buffersize = 1536;
	unsigned short indsbuf[buffersize];
	unsigned short ind = 0;
	int i;
	for (i = 0; i < buffersize - 5; i+=6)
	{
		indsbuf[i] = ind;
        indsbuf[i + 1] = ind + 1;
        indsbuf[i + 2] = ind + 2;
        indsbuf[i + 3] = ind + 2;
        indsbuf[i + 4] = ind + 3;
        indsbuf[i + 5] = ind;
        ind += 4;	
	}
    
	//Send indices data to the graphics card
	vsGLStateBindBuffer(renderer.ibo, GL_ELEMENT_ARRAY_BUFFER);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned short) * buffersize,
				indsbuf, GL_STATIC_DRAW);

	//We don't need ArrayBuffer
	vsGLStateBindBuffer(0, GL_ARRAY_BUFFER);

	//Initialize freetype
	#if defined(VS_FREETYPE)
	if (FT_Init_FreeType(&ftlib)) {
		printf("Error: can't initialize the freetype library\n");
		return;
	}
	#endif
}

////////////////////////////////////////////////////////////
void vsGraphicsDestroy()
{
	//Disable opengl stuff
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	//Delete indices buffer object
	vsGLStateBindBuffer(renderer.ibo, GL_ELEMENT_ARRAY_BUFFER);
	glDeleteBuffers(1, &renderer.ibo);

	//Destroy freetype
	#if defined(VS_FREETYPE)
	FT_Done_FreeType(ftlib);
	#endif
}




// ================================
// ====>> VIEW
// ================================


////////////////////////////////////////////////////////////
void vsViewSet(vsView view)
{
	vsVector2 NCenter;
	NCenter.x = floor(view.center.x);
	NCenter.y = floor(view.center.y);

	// Rotation components
	float angle = view.rotation * 3.141592654f / 180.f;
	float cosine = cosf(angle);
	float sine = sinf(angle);
	float tx = -NCenter.x * cosine - NCenter.y * sine + NCenter.x;
	float ty = NCenter.x * sine - NCenter.y * cosine + NCenter.y;

	// Projection components
	float a = 2.f / view.size.x;
	float b = -2.f / view.size.y;
	float c = -a * NCenter.x;
	float d = -b * NCenter.y;

	const float zNear = 0;
	const float zFar = 10;
	const float e = 2.f / (zFar - zNear);
	const float f = -(zFar + zNear) / (zFar - zNear);

	//Update matrix
	view.matrix[0] = a * cosine;
	view.matrix[1] = -b * sine;
    view.matrix[2] = 0.f;
    view.matrix[3] = 0.f;
	view.matrix[4] = a * sine;
	view.matrix[5] = b * cosine;
	view.matrix[6] = 0.f;
	view.matrix[7] = 0.f;
	view.matrix[8] = 0.f;
	view.matrix[9] = 0.f;
	view.matrix[10] = e;
	view.matrix[11] = 0.f;
	view.matrix[12] = a * tx + c;
	view.matrix[13] = b * ty + d;
	view.matrix[14] = f;
	view.matrix[15] = 1.f;
	
	//Update view
	currentView = view;

	//Set viewport
	glViewport(view.viewport.x, view.viewport.y, view.viewport.w, view.viewport.h);
    
	//Apply view
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(view.matrix);
    glMatrixMode(GL_MODELVIEW);
}

////////////////////////////////////////////////////////////
void vsViewCreate(vsRect viewport, vsVector2 center,
					vsVector2 size, float angle)
{
	vsView view;
	view.viewport = viewport;
	view.size = size;
	view.center = center;
	view.rotation = angle;
	vsViewSet(view);	
}

////////////////////////////////////////////////////////////
vsVector2 vsViewGetCenter()
{
	vsVector2 center;
	center.x = currentView.center.x;
	center.y = currentView.center.y;
	return center;
}

////////////////////////////////////////////////////////////
vsVector2 vsViewGetSize()
{
	vsVector2 size;
	size.x = currentView.size.x;
	size.y = currentView.size.y;
	return size;
}

////////////////////////////////////////////////////////////
float vsViewGetRotation()
{
	return currentView.rotation;
}



// ================================
// ====>> BITMAP
// ================================

////////////////////////////////////////////////////////////
vsBitmap* vsBitmapInit()
{
	vsBitmap* bm = (vsBitmap*)malloc(sizeof(vsBitmap));
	bm->width = 0;
	bm->height = 0;
	bm->channels = 0;
	bm->data = NULL;
	return bm;
}

////////////////////////////////////////////////////////////
void vsBitmapDestroy(vsBitmap* bitmap)
{
	if (bitmap->data)
		free(bitmap->data);
	free(bitmap);
}

////////////////////////////////////////////////////////////
void vsBitmapUnload(vsBitmap* bitmap)
{
	if (bitmap->data != NULL)
		free(bitmap->data);
	bitmap->data = NULL;
	bitmap->width = 0;
	bitmap->height = 0;
	bitmap->channels = 0;
}

////////////////////////////////////////////////////////////
void vsBitmapLoad(vsBitmap* bitmap, const char* filepath)
{
    //Unload bitmap
    vsBitmapUnload(bitmap);
    
	//Variables
	int stbi_fmt = STBI_rgb_alpha;
	int fsize = 0;
	
	//Open file
	FILE* file = fopen(filepath, "rb");

	if (!file) {
		printf("Error in vsTexture : can't open the file\n");
		fclose(file);
		return;
	}
	
	//Get file size
	fseek(file, 0L, SEEK_END);
	fsize = (int)ftell(file);

	//Seek to the beginning
	fseek(file, 0L, SEEK_SET);
	
	//Read all the file into filedata
	stbi_uc* fileData = (stbi_uc*)malloc(sizeof(stbi_uc) * fsize);
	fread(fileData, sizeof(stbi_uc) * fsize, 1, file);
	fclose(file);

	//Get the image data
	bitmap->data = stbi_load_from_memory(fileData, fsize, &bitmap->width, &bitmap->height,
										&bitmap->channels, stbi_fmt);
    
    //Free the filedata
    free(fileData);
    
    //Check for stb_image fail
    if (bitmap->data == NULL) {
        printf("Error in vsTexture : can't generate texture\n");
        printf("Details : %s\n", stbi_failure_reason());
        return;
    }

}

////////////////////////////////////////////////////////////
void vsBitmapLoadFromData(vsBitmap* bitmap, unsigned char* data,
							int width, int height, int channels)
{
	bitmap->data = data;
	bitmap->width = width;
	bitmap->height = height;
	bitmap->channels = channels;
}

////////////////////////////////////////////////////////////
vsVector2 vsBitmapGetSize(vsBitmap* bitmap)
{
	return VSVECTOR2((float)bitmap->width, (float)bitmap->height);
}

////////////////////////////////////////////////////////////
int vsBitmapGetChannels(vsBitmap* bitmap)
{
	return bitmap->channels;
}

////////////////////////////////////////////////////////////
const unsigned char* vsBitmapGetData(vsBitmap* bitmap)
{
	return bitmap->data;
}




// ================================
// ====>> TEXTURE
// ================================ 

////////////////////////////////////////////////////////////
vsTexture* vsTextureInit()
{
    vsTexture* texture = (vsTexture*)malloc(sizeof(vsTexture));
    texture->id = 0;
    texture->repeated = 0;
    texture->smooth = 0;
    texture->size = (vsVector2){0, 0};
    return texture;
}

////////////////////////////////////////////////////////////
void vsTextureDestroy(vsTexture* texture)
{
	if (texture) free(texture);
}

////////////////////////////////////////////////////////////
void vsTextureUnload(vsTexture* texture)
{
    if (texture->id)
        glDeleteTextures(1, &texture->id);
    texture->id = 0;
}

///////////////////////////////////////////////////////////
void vsTextureLoadFromData(vsTexture* texture, vsBitmap* bitmap)
{
	if (!texture) return;

	//Unload texture
    vsTextureUnload(texture);
    
    //Get the texture format
    unsigned int fmt = GL_RGBA;
    switch (bitmap->channels) {
        case 1: fmt = GL_ALPHA; break;
        case 3: fmt = GL_RGB; break;
        case 4: fmt = GL_RGBA; break;
        default:
            printf("Error in vsTexture : data file format [%d] not recognized\n", fmt);
            return;
    }
    
    //Create texture
    glGenTextures(1, &texture->id);
    
    vsGLStateBindTexture(texture->id);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D, 0, fmt, bitmap->width, bitmap->height, 0, fmt,
                 GL_UNSIGNED_BYTE, bitmap->data);
    
    //Check for opengl errors
    GLenum glerr = glGetError();
    if (glerr != GL_NO_ERROR) {
        printf("Error in vsTexture : opengl error %d\n", glerr);
    }
    
    //Set the default values
    texture->size.x = bitmap->width;
    texture->size.y = bitmap->height;
    texture->smooth = VS_TRUE;
    texture->repeated = VS_FALSE;
}

////////////////////////////////////////////////////////////
void vsTextureLoad(vsTexture* texture, const char* filepath)
{
	//Load bitmap
    vsBitmap* bm = vsBitmapInit();
    vsBitmapLoad(bm, filepath);

	//Check for errors
    if (bm->data == NULL) return;
	
	//Load from bitmap
	vsTextureLoadFromData(texture, bm);
	 
    //Destroy bitmap
    vsBitmapDestroy(bm);
}

////////////////////////////////////////////////////////////
void vsTextureSetSmooth(vsTexture* texture, const int smooth)
{
	if (!texture) return;
	if (smooth == texture->smooth) return;
	
	vsGLStateBindTexture(texture->id);

	if (smooth)
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		texture->smooth = VS_TRUE;
	}
	else
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		texture->smooth = VS_FALSE;
	}

}

////////////////////////////////////////////////////////////
void vsTextureSetRepeated(vsTexture* texture, const int repeated)
{
	if (!texture) return;
	if (repeated == texture->repeated) return;

	vsGLStateBindTexture(texture->id);

	if (repeated)
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		texture->repeated = VS_TRUE;
	}
	else
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		texture->repeated = VS_FALSE;
	}
}

////////////////////////////////////////////////////////////
vsVector2 vsTextureGetSize(vsTexture* texture)
{
	if (!texture) return VSVECTOR2(0, 0);
	return texture->size;
}

////////////////////////////////////////////////////////////
int vsTextureIsSmooth(vsTexture* texture)
{
	if (!texture) return -1;
	return texture->smooth;
}

////////////////////////////////////////////////////////////
int vsTextureIsRepeated(vsTexture* texture)
{
	if (!texture) return -1;
	return texture->repeated;
}




// ================================
// ====>> SHADER
// ================================

//IOS dont support shaders
#if !defined(VS_SYS_IOS)

////////////////////////////////////////////////////////////
vsShader* vsShaderInit()
{
    vsShader* shader = (vsShader*)malloc(sizeof(vsShader));
	shader->id = 0;
	shader->paramcount = 0;
	shader->paramcapacity = 4;
	shader->parampos = (int*)malloc(sizeof(int) * 4);
	shader->paramnames = (const char**)malloc(sizeof(char*) * 4);
    return shader;
}

////////////////////////////////////////////////////////////
void vsShaderDestroy(vsShader* shader)
{
	free(shader->paramnames);
	free(shader->parampos);
	free(shader);
}

////////////////////////////////////////////////////////////
void vsShaderParamCacheResize(vsShader* shader, int size)
{
    shader->paramnames = (const char**)realloc(shader->paramnames, sizeof(char*) * size);
    shader->parampos = (int*)realloc(shader->parampos, sizeof(int) * size);
    shader->paramcapacity = size;
}

////////////////////////////////////////////////////////////
void vsShaderParamCachePush(vsShader* shader, const char* name, int location)
{
    if (shader->paramcount == shader->paramcapacity)
        vsShaderParamCacheResize(shader, shader->paramcapacity * 2);
    
    shader->paramnames[shader->paramcount] = name;
    shader->parampos[shader->paramcount] = location;
    shader->paramcount++;
}

////////////////////////////////////////////////////////////
void vsShaderUnload(vsShader* shader)
{
	if (shader->id) {
		glDeleteProgram(shader->id);
		shader->id = 0;
	}
}

////////////////////////////////////////////////////////////
int vsShaderCompileShader(const char* source, int shadertype)
{
    unsigned int sp = 0;
    
    //Create shader
    if (shadertype == VS_SHADER_VERTEX) sp = glCreateShader(GL_VERTEX_SHADER);
    else if (shadertype == VS_SHADER_FRAGMENT) sp = glCreateShader(GL_FRAGMENT_SHADER);
    else
    {
        printf("Error in vsShader : unknown shader type\n");
        return -1;
    }
    
    //Compile shader
    glShaderSource(sp, 1, &source, NULL);
    glCompileShader(sp);                        //Crash here... Why?

    //Check the compile log
    GLint success;
    glGetShaderiv(sp, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        char log[1024];
        glGetShaderInfoLog(sp, sizeof(char) * 1024, 0, log);
        printf("Error in vsShader : failed while compiling the shader\n");
        printf("%s\n", log);
        return -1;
    }
    
    return sp;
}

////////////////////////////////////////////////////////////
void vsShaderCompile(vsShader* shader, const char* source, int shadertype)
{
    //Unload shader
    vsShaderUnload(shader);
    
    //Create program
    shader->id = glCreateProgram();
    
    //Compile shader from source
    int sp = vsShaderCompileShader(source, shadertype);
    
    //Check for errors
    if (sp == -1) {
        vsShaderUnload(shader);
        return;
    }
    
    //Attach shader
    glAttachShader(shader->id, sp);
    
    //Delete shader
    glDeleteShader(sp);
    
    //Link the program
    glLinkProgram(shader->id);
    
    //Check the link log
    GLint success;
    glGetProgramiv(shader->id, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        char log[1024];
        glGetProgramInfoLog(shader->id, sizeof(char) * 1024, 0, log);
        printf("Error in vsShader : failed to link the shader\n");
        printf("%s\n", log);
        vsShaderUnload(shader);
    }
}

////////////////////////////////////////////////////////////
void vsShaderCompile2(vsShader* shader, const char* vertexsource, const char* fragmentsource)
{
    //Unload shader
    vsShaderUnload(shader);
    
    //Create program
    shader->id = glCreateProgram();
    
    //Compile shader from source
    int vertexshader = vsShaderCompileShader(vertexsource, VS_SHADER_VERTEX);
    
    //Check for errors
    if (vertexshader == -1) {
        vsShaderUnload(shader);
        return;
    }
    
    //Attach shader
    glAttachShader(shader->id, vertexshader);
    
    //Delete shader
    glDeleteShader(vertexshader);
    
    //Compile shader from source
    int fragmentshader = vsShaderCompileShader(fragmentsource , VS_SHADER_FRAGMENT);
    
    //Check for errors
    if (fragmentshader == -1) {
        vsShaderUnload(shader);
        return;
    }
    
    //Attach shader
    glAttachShader(shader->id, fragmentshader);
    
    //Delete shader
    glDeleteShader(fragmentshader);
    
    //Link the program
    glLinkProgram(shader->id);
    
    //Check the link log
    GLint success;
    glGetProgramiv(shader->id, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        char log[1024];
        glGetProgramInfoLog(shader->id, sizeof(char) * 1024, 0, log);
        printf("Error in vsShader : failed to link the shader\n");
        printf("%s\n", log);
        vsShaderUnload(shader);
    }
}

////////////////////////////////////////////////////////////
void vsShaderLoad(vsShader* shader, const char* filepath, int shadertype)
{
	//Variables
	int fsize = 0;
		
	//Open the shader file
	FILE* file = fopen(filepath, "rb");
	
	//Check for errors
	if (!file) {
		printf("Error in vsShader : can't open the file");
		fclose(file);
		return;
	}

	//Get file size
	fseek(file, 0L, SEEK_END);
	fsize = (int)ftell(file);

	//Seek to the beginning
	fseek(file, 0L, SEEK_SET);
    
    //Allocate text buffer
    char source[fsize];
	
	//Read all the file into filedata
	fread(source, sizeof(char) * fsize, 1, file);
    
    //Close the shader file
    fclose(file);
    
    //Compile shader and attach to the program
    vsShaderCompile(shader, source, shadertype);
}

////////////////////////////////////////////////////////////
void vsShaderLoad2(vsShader* shader, const char* vertexshader_path, const char* fragmentshader_path)
{
    //Variables
    int fsize = 0;
    char* vertexsh_source = NULL;
    char* fragmentsh_source = NULL;
    
    //Open the shader file
    FILE* vertexsh_file = fopen(vertexshader_path, "rb");
    
    //Check for errors
    if (!vertexsh_file) {
        printf("Error in vsShader : can't open the file");
        fclose(vertexsh_file);
        return;
    }
    
    //Get file size
    fseek(vertexsh_file, 0L, SEEK_END);
    fsize = (int)ftell(vertexsh_file);
    
    //Seek to the beginning
    fseek(vertexsh_file, 0L, SEEK_SET);
    
    //Read all the file into filedata
    fread(vertexsh_source, sizeof(char) * fsize, 1, vertexsh_file);
    
    //Close the shader file
    fclose(vertexsh_file);
    
    
    
    //Open the shader file
    FILE* fragmentsh_file = fopen(fragmentshader_path, "rb");
    
    //Check for errors
    if (!fragmentsh_file) {
        printf("Error in vsShader : can't open the file");
        fclose(fragmentsh_file);
        return;
    }
    
    //Get file size
    fseek(fragmentsh_file, 0L, SEEK_END);
    fsize = (int)ftell(fragmentsh_file);
    
    //Seek to the beginning
    fseek(fragmentsh_file, 0L, SEEK_SET);
    
    //Read all the file into filedata
    fread(fragmentsh_source, sizeof(char) * fsize, 1, fragmentsh_file);
    
    //Close the shader file
    fclose(fragmentsh_file);
    
    //Compile shaders
    vsShaderCompile2(shader, vertexsh_source, fragmentsh_source);
    
}

///////////////////////////////////////////////////////////
void vsShaderBind(vsShader* shader)
{
    vsGLStateBindShader(shader->id);
}

////////////////////////////////////////////////////////////
unsigned int vsShaderGetID(vsShader* shader)
{
	return shader->id;
}

////////////////////////////////////////////////////////////
int vsShaderGetParamLocation(vsShader* shader, int paramtype, const char* paramname)
{
    //Search in the cache
	int i;
	for (i = 0; i < shader->paramcount; i++) {
        if (strcmp(paramname, shader->paramnames[i]) == 0)
            return shader->parampos[i];
	}
    
    //Not in cache, request location from OpenGL
    int location = -1;
    
    if (paramtype == VS_SHADER_PARAM_UNIFORM)
    {
        location = glGetUniformLocation(shader->id, paramname);
    }
    else if (paramtype == VS_SHADER_PARAM_ATTRIBUTE)
    {
        location = glGetAttribLocation(shader->id, paramname);
    }
    else
    {
        printf("Error in vsShader : unknown parameter type\n");
        return -1;
    }
    
    //Check for errors
    if (location == -1) {
        printf("Error in vsShader : parameter %s not found\n", paramname);
        return -1;
    }
    
    //Add the location to the cache
    vsShaderParamCachePush(shader, paramname, location);
	
	return location;
}

////////////////////////////////////////////////////////////
void vsShaderSetParam1(vsShader* shader, const char* paramname, int paramtype,
										const float x)
{
    //Check for errors
    if (!shader->id) {
        printf("Error in vsShader : can't set parameter to an empty shader\n");
        return;
    }
    
    //Bind shader if needed
    vsGLStateBindShader(shader->id);
    
    //Get param location
    GLint location = vsShaderGetParamLocation(shader, paramtype, paramname);
    if (location == -1) {
        printf("Error in vsShader : null parameter location");
        return;
    }
    
    //Assign new value
    if (paramtype == VS_SHADER_PARAM_UNIFORM) glUniform1f(location, x);
    else if (paramtype == VS_SHADER_PARAM_ATTRIBUTE) glVertexAttrib1f(location, x);
}

////////////////////////////////////////////////////////////
void vsShaderSetParam2(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y)
{
    //Check for errors
    if (!shader->id) {
        printf("Error in vsShader : can't set parameter to an empty shader\n");
        return;
    }
    
    //Bind shader if needed
    vsGLStateBindShader(shader->id);
    
    //Get param location
    GLint location = vsShaderGetParamLocation(shader, paramtype, paramname);
    if (location == -1) {
        printf("Error in vsShader : null parameter location");
        return;
    }
    
    //Assign new value
    if (paramtype == VS_SHADER_PARAM_UNIFORM) glUniform2f(location, x, y);
    else if (paramtype == VS_SHADER_PARAM_ATTRIBUTE) glVertexAttrib2f(location, x, y);
}

////////////////////////////////////////////////////////////
void vsShaderSetParam3(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y, const float z)
{
    //Check for errors
    if (!shader->id) {
        printf("Error in vsShader : can't set parameter to an empty shader\n");
        return;
    }
    
    //Bind shader if needed
    vsGLStateBindShader(shader->id);
    
    //Get param location
    GLint location = vsShaderGetParamLocation(shader, paramtype, paramname);
    if (location == -1) {
        printf("Error in vsShader : null parameter location");
        return;
    }
    
    //Assign new value
    if (paramtype == VS_SHADER_PARAM_UNIFORM) glUniform3f(location, x, y, z);
    else if (paramtype == VS_SHADER_PARAM_ATTRIBUTE) glVertexAttrib3f(location, x, y, z);
}

////////////////////////////////////////////////////////////
void vsShaderSetParam4(vsShader* shader, const char* paramname, int paramtype,
										const float x, const float y, const float z,
										const float w)
{
    //Check for errors
    if (!shader->id) {
        printf("Error in vsShader : can't set parameter to an empty shader\n");
        return;
    }
    
    //Bind shader if needed
    vsGLStateBindShader(shader->id);
    
    //Get param location
    GLint location = vsShaderGetParamLocation(shader, paramtype, paramname);
    if (location == -1) {
        printf("Error in vsShader : null parameter location");
        return;
    }
    
    //Assign new value
    if (paramtype == VS_SHADER_PARAM_UNIFORM) glUniform4f(location, x, y, z, w);
    else if (paramtype == VS_SHADER_PARAM_ATTRIBUTE) glVertexAttrib4f(location, x, y, z, w);
}

#endif



// ================================
// ====>> FONT
// ================================

#if defined(VS_FREETYPE)

////////////////////////////////////////////////////////////
vsFont* vsFontInit()
{
	vsFont* font = (vsFont*)malloc(sizeof(vsFont));
	font->texture = NULL;
	font->texcoords_table = (vsRect*)malloc(sizeof(vsRect) * VS_FONT_CH_COUNT);
	font->ch_widths = (unsigned int*)malloc(sizeof(unsigned int) * VS_FONT_CH_COUNT);
	font->ch_height = 0;
	return font;
}

////////////////////////////////////////////////////////////
void vsFontDestroy(vsFont* font)
{
	if (font->texture) vsTextureDestroy(font->texture);
	if (font->texcoords_table) free(font->texcoords_table);
	if (font->ch_widths) free(font->ch_widths);
	font->ch_height = 0;
	free(font);
}

////////////////////////////////////////////////////////////
void vsFontLoad(vsFont* font, const char* filepath, unsigned int size)
{	
	static const size_t margin = 3;
	
	//Step 1: Open the font using FreeType
	FT_Face face;
	if (FT_New_Face(ftlib, filepath, 0, &face) != 0) {
		printf("Error: can't load font file\n");
		return;
	}

	//Abort if this is not a scalable font
	if (!(face->face_flags & FT_FACE_FLAG_SCALABLE) ||
		!(face->face_flags & FT_FACE_FLAG_HORIZONTAL))
	{
		printf("Error: the font is not a scalable font\n");
		return;
	}
	
	//Set the font size
	FT_Set_Pixel_Sizes(face, 0, size);
	
	//Step 2: Find maxAscent/Descent to calculate imageHeight
	int imageHeight = 0;
	int imageWidth = 256;
	int maxDescent = 0;
	int maxAscent = 0;
	size_t lineSpace = imageWidth - margin;
	size_t lines = 1;
	char charIndex;

	for (unsigned int ch = 0; ch < VS_FONT_CH_COUNT; ch++) {
		
		// Look up the character in the font file.
		charIndex = FT_Get_Char_Index(face, ch + VS_FONT_CH_START);

		// Render the current glyph.
		FT_Load_Glyph(face, charIndex, FT_LOAD_RENDER);

		font->ch_widths[ch] = (face->glyph->metrics.horiAdvance >> 6) + margin;
        
		// If the line is full go to the next line
		if (font->ch_widths[ch] > lineSpace) {
            lineSpace = imageWidth - margin;
            ++lines;
        }
		lineSpace -= font->ch_widths[ch];

		maxAscent = (face->glyph->bitmap_top > maxAscent) ? face->glyph->bitmap_top : maxAscent;
		maxDescent = (face->glyph->bitmap.rows - face->glyph->bitmap_top > maxDescent) ? face->glyph->bitmap.rows - face->glyph->bitmap_top : maxDescent;
	}
	
	//font->ch_height = maxAscent + maxDescent;   // calculate height for text
	font->ch_height = size;

    // Compute how high the texture has to be.
    size_t neededHeight = (maxAscent + maxDescent + margin) * lines + margin;
        
	// Get the first power of two in which it will fit
    imageHeight = 16;
    while(imageHeight < (int)neededHeight)
		imageHeight <<= 1;

    // Step 3: Generation of the actual texture //

    // create and zero the memory
    unsigned char* image = (unsigned char*)malloc(imageHeight * imageWidth);
    memset(image, 0, imageHeight * imageWidth);

    // These are the position at which to draw the next glyph
    size_t x = margin;
    size_t y = margin + maxAscent;

    // Drawing loop
	for (unsigned int ch = 0; ch < VS_FONT_CH_COUNT; ++ch)
    {
        unsigned int charIndex = FT_Get_Char_Index(face, ch + VS_FONT_CH_START);

		// Render the glyph
        FT_Load_Glyph(face, charIndex, FT_LOAD_DEFAULT);
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

        // See whether the character fits on the current line
		if (font->ch_widths[ch] > imageWidth - x)
        {
			x = margin;
			y += (font->ch_height + margin);
        }

        // calculate texture coordinates of the character
		font->texcoords_table[ch].x = (float)x;
		font->texcoords_table[ch].w = (float)font->ch_widths[ch] - margin;
		font->texcoords_table[ch].y = (float)y - maxAscent;
		font->texcoords_table[ch].h = (float)size;
            
        // copy image generated by FreeType to the texture
        for(int row = 0; row < face->glyph->bitmap.rows; ++row)
        {
            for(int pixel = 0; pixel < face->glyph->bitmap.width; ++pixel)
            {
                // set pixel at position to intensity (0-255) at the position
				image[(x + face->glyph->bitmap_left + pixel) +
					(y - face->glyph->bitmap_top + row) * imageWidth] =
					face->glyph->bitmap.buffer[pixel + row * face->glyph->bitmap.pitch];
            }
        }

		x += font->ch_widths[ch];
    }
	
    //Create bitmap
	vsBitmap* bm = vsBitmapInit();
	vsBitmapLoadFromData(bm, image, imageWidth, imageHeight, 1);
	
	//Destroy texture
	if (font->texture) 
		vsTextureDestroy(font->texture);
	
	//Generate opengl texture from bitmap
	font->texture = vsTextureInit();
	vsTextureLoadFromData(font->texture, bm);

	//Destroy bitmap
	vsBitmapDestroy(bm);

	//Done
    FT_Done_Face(face); // free the face data
}

////////////////////////////////////////////////////////////
vsTexture* vsFontGetTexture(vsFont* font)
{
	return font->texture;
}

////////////////////////////////////////////////////////////
const vsRect* vsFontGetTexCoord(vsFont* font, const char ch)
{
	return &font->texcoords_table[(int)ch];	
}

////////////////////////////////////////////////////////////
unsigned int vsFontGetLenght(vsFont* font, const char* text, float scalex)
{
	const int char_count = strlen(text);
	unsigned int old_lenght = 0;
	unsigned int lenght = 0;
	for (int i = 0; i < char_count; i++) {
		
		//Newline
		if (text[i] == '\n')
		{
			if (lenght > old_lenght) old_lenght = lenght;
			lenght = 0;
			continue;
		}
		
		//Unsupported characters and space
		if (text[i] < VS_FONT_CH_START || text[i] > VS_FONT_CH_END || text[i] == ' ')
		{
			lenght += font->ch_widths[0] * scalex;
			continue;
		}
		
		lenght += font->ch_widths[(int)text[i] - VS_FONT_CH_START] * scalex;
	}
	return lenght > old_lenght ? lenght : old_lenght;
}

#endif //VS_FREETYPE




// ================================
// ====>> RENDERER
// ================================

////////////////////////////////////////////////////////////
void vsRendererClear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

////////////////////////////////////////////////////////////
void vsRendererDisplay()
{
	if (!renderer.countverts) return;
    
    //Draw
    glVertexPointer(2, GL_FLOAT, 0, renderer.vertexbuf);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, renderer.colorbuf);
    glTexCoordPointer(2, GL_FLOAT, 0, renderer.texsourcebuf);
    vsGLStateBindBuffer(renderer.ibo, GL_ELEMENT_ARRAY_BUFFER);
	glDrawElements(GL_TRIANGLES, renderer.countverts, GL_UNSIGNED_SHORT, 0);
	
	renderer.buffersize = 0;
	renderer.countverts = 0;
}

////////////////////////////////////////////////////////////
void vsRendererDraw(vsTexture* texture, float x, float y, float x2, float y2,
					float x3, float y3, float x4, float y4, float tx_x, float tx_y,
                    float tx_w, float tx_h, vsColor color)
{
	if (texture == NULL)
	{
		if (glstate.currentTexture != 0) {
			vsRendererDisplay();
			vsGLStateBindTexture(0);
		}
	}
	else
	{
		if (glstate.currentTexture != texture->id) {
			vsRendererDisplay();
			vsGLStateBindTexture(texture->id);
		}
	}

	if (renderer.buffersize == 1024)
		vsRendererDisplay();
	
	//Vertex 1
	renderer.vertexbuf[renderer.buffersize][0] = x;
	renderer.vertexbuf[renderer.buffersize][1] = y;

	renderer.texsourcebuf[renderer.buffersize][0] = tx_x;
	renderer.texsourcebuf[renderer.buffersize][1] = tx_y;

	renderer.colorbuf[renderer.buffersize][0] = color.r;
	renderer.colorbuf[renderer.buffersize][1] = color.g;
	renderer.colorbuf[renderer.buffersize][2] = color.b;
	renderer.colorbuf[renderer.buffersize][3] = color.a;

	renderer.buffersize++;

	//Vertex 2
	renderer.vertexbuf[renderer.buffersize][0] = x2;
	renderer.vertexbuf[renderer.buffersize][1] = y2;

	renderer.texsourcebuf[renderer.buffersize][0] = tx_x + tx_w;
	renderer.texsourcebuf[renderer.buffersize][1] = tx_y;

	renderer.colorbuf[renderer.buffersize][0] = color.r;
	renderer.colorbuf[renderer.buffersize][1] = color.g;
	renderer.colorbuf[renderer.buffersize][2] = color.b;
	renderer.colorbuf[renderer.buffersize][3] = color.a;

	renderer.buffersize++;

	//Vertex 3
	renderer.vertexbuf[renderer.buffersize][0] = x3;
	renderer.vertexbuf[renderer.buffersize][1] = y3;

	renderer.texsourcebuf[renderer.buffersize][0] = tx_x + tx_w;
	renderer.texsourcebuf[renderer.buffersize][1] = tx_y + tx_h;

	renderer.colorbuf[renderer.buffersize][0] = color.r;
	renderer.colorbuf[renderer.buffersize][1] = color.g;
	renderer.colorbuf[renderer.buffersize][2] = color.b;
	renderer.colorbuf[renderer.buffersize][3] = color.a;

	renderer.buffersize++;
	
	//Vertex 4
	renderer.vertexbuf[renderer.buffersize][0] = x4;
	renderer.vertexbuf[renderer.buffersize][1] = y4;

	renderer.texsourcebuf[renderer.buffersize][0] = tx_x;
	renderer.texsourcebuf[renderer.buffersize][1] = tx_y + tx_h;

	renderer.colorbuf[renderer.buffersize][0] = color.r;
	renderer.colorbuf[renderer.buffersize][1] = color.g;
	renderer.colorbuf[renderer.buffersize][2] = color.b;
	renderer.colorbuf[renderer.buffersize][3] = color.a;

	renderer.buffersize++;
	
	renderer.countverts += 6;
}

////////////////////////////////////////////////////////////
void vsRendererDrawSprite(vsSprite* sprite)
{
    static vsVector2 v1;
    static vsVector2 v2;
    static vsVector2 v3;
    static vsVector2 v4;
    
    if (sprite->rotation)
    {
        const float ca = cosf(sprite->rotation * 3.14159 / 180);
        const float sa = sinf(sprite->rotation * 3.14159 / 180);
        
        const float cx = sprite->position.x + sprite->origin.x;
        const float cy = sprite->position.y + sprite->origin.y;
        
        const float x = sprite->position.x - cx;
        const float y = sprite->position.y - cy;
        const float w = sprite->position.x + sprite->size.x  - cx;
        const float h = sprite->position.y + sprite->size.y  - cy;
        
        v1.x = x*ca - y*sa + cx;
        v1.y = x*sa + y*ca + cy;
        
        v2.x = w*ca - y*sa + cx;
        v2.y = w*sa + y*ca + cy;
        
        v3.x = w*ca - h*sa + cx;
        v3.y = w*sa + h*ca + cy;
        
        v4.x = x*ca - h*sa + cx;
        v4.y = x*sa + h*ca + cy;
    }
    else
    {
        v1.x = sprite->position.x - sprite->origin.x;
        v1.y = sprite->position.y - sprite->origin.y;
        
        v2.x = sprite->position.x + sprite->size.x - sprite->origin.x;
        v2.y = sprite->position.y - sprite->origin.y;
        
        v3.x = sprite->position.x + sprite->size.x - sprite->origin.x;
        v3.y = sprite->position.y + sprite->size.y - sprite->origin.y;
        
        v4.x = sprite->position.x - sprite->origin.x;
        v4.y = sprite->position.y + sprite->size.y - sprite->origin.y;
    }
	
	if (sprite->texture)
	{
		vsRendererDraw(sprite->texture,
                   v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y,
                   sprite->texsource.x / sprite->texture->size.x,
                   sprite->texsource.y / sprite->texture->size.y,
                   sprite->texsource.w / sprite->texture->size.x,
                   sprite->texsource.h / sprite->texture->size.y,
                   sprite->color);
	}
	else
	{
		vsRendererDraw(NULL,
                   v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, v4.x, v4.y,
                   0, 0, 0, 0, sprite->color);
	}
}

////////////////////////////////////////////////////////////
void vsRendererDrawRect(vsTexture* texture, float tx, float ty, float tw, float th,
						float x, float y, float w, float h, vsColor color)
{
	if (texture == NULL) 
	{
		vsRendererDraw(NULL, x, y, x + w, y, x + w, y + h, x, y + h, 0, 0, 0, 0, color);
	}
	else
	{
		vsRendererDraw(texture, x, y, x + w, y, x + w, y + h, x, y + h,
			tx / texture->size.x, ty / texture->size.y, tw / texture->size.x,
			th / texture->size.y, color);
	}
}

#if defined(VS_FREETYPE)

////////////////////////////////////////////////////////////
void vsRendererDrawTextRaw(vsFont* font, const char* text, float x, float y,
						float scalex, float scaley, unsigned int alignment, vsColor color)
{
	static int char_count; char_count = strlen(text);
	static vsRect char_txc;
	static float xorigin = 0, yorigin = 0;
	static float xpos, ypos; xpos = x; ypos = y;
	static unsigned int text_lenght = 0;
	
	//Check text alignment
	if (alignment == VS_TEXT_ALIGN_CENTER) {
		text_lenght = vsFontGetLenght(font, text, scalex);
		xorigin = text_lenght/2;		
	}
	
	for (int i = 0; i < char_count; i++) {
		
		//Newline: update x and y position
		if (text[i] == '\n') {
			xpos = x;
			ypos += (font->ch_height + 1) * scaley;
			continue;
		}
		
		//Jump unsupported characters and space 
		if (text[i] < VS_FONT_CH_START || text[i] > VS_FONT_CH_END || text[i] == ' ') {
			xpos += font->ch_widths[0] * scalex;
			continue;
		}
		
		//Get character texture coordinates
		char_txc = *vsFontGetTexCoord(font, text[i] - VS_FONT_CH_START);
		
		//Draw character
		vsRendererDrawRect(font->texture,
							char_txc.x, char_txc.y, char_txc.w, char_txc.h,
							xpos - xorigin, ypos - yorigin,
							font->texcoords_table[text[i] - VS_FONT_CH_START].w * scalex,
							font->ch_height * scaley,
							color);
		//Update x position
		xpos += font->ch_widths[text[i] - VS_FONT_CH_START] * scalex;
	}
}

////////////////////////////////////////////////////////////
void vsRendererDrawText(vsText* text)
{
	vsRendererDrawTextRaw(text->font, text->text, text->pos.x, text->pos.y, text->scale.x,
							text->scale.y, text->alignment, text->color);
}

#endif

////////////////////////////////////////////////////////////
void vsRendererToggleWireFrame()
{
	renderer.wireframe = !renderer.wireframe;

	if (renderer.wireframe) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_TEXTURE_2D);
	}
}

#endif //VS_GRAPHICS_IMPLEMENTATION
