////////////////////////////////////////////////////////////
///	INCLUDES
////////////////////////////////////////////////////////////
#include "Celegans.h"
#include "brain.h"
#include <unistd.h>
#define VS_SYSTEM_IMPLEMENTATION
#define VS_GRAPHICS_IMPLEMENTATION
#include "VSSystem.h"
#include "VSGraphics.h"


////////////////////////////////////////////////////////////
///	CONSTANTS
////////////////////////////////////////////////////////////
#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 700
#define BODY_WIDTH 64
#define BODY_HEIGHT 32
#define RADIAS_TO_DEGREE 57.2957


////////////////////////////////////////////////////////////
///	C.ELEGANS
////////////////////////////////////////////////////////////
typedef struct Celegans
{
	brain* soul;
	vsSprite body;
} Celegans;

Celegans* Celegans_init()
{
	Celegans* ce = (Celegans*)malloc(sizeof(Celegans));
	ce->soul = Celegans_brain_init();
	ce->body.texture = NULL;
	ce->body.origin = VSVECTOR2(BODY_WIDTH/2, BODY_HEIGHT/2);
	ce->body.position = VSVECTOR2(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
	ce->body.size = VSVECTOR2(BODY_WIDTH, BODY_HEIGHT);
	ce->body.rotation = 0;
	ce->body.color = VS_COLOR_GREEN;
	return ce;
}

void Celegans_free(Celegans* ce)
{
	Celegans_brain_free(ce->soul);
	free(ce);
}

void Celegans_update(Celegans* ce)
{
	ce->soul->neurons[MVULVA]->state = 0;
	
	//Calculate right side muscle contraction
	int rightAcc = 0;
	for (int i = MUSCLE_RIGHT_START; i < MUSCLE_RIGHT_END; i++) {
		rightAcc += ce->soul->neurons[i]->state; 
		ce->soul->neurons[i]->state *= 0.7; //Decrease the muscle contraction over time 
	}

	//Calculate left side muscle contraction
	int leftAcc = 0;
	for (int i = MUSCLE_LEFT_START; i < MUSCLE_LEFT_END; i++) {
		leftAcc += ce->soul->neurons[i]->state;
		ce->soul->neurons[i]->state *= 0.7; //Decrease the muscle contraction over time
	}
		
	//Calculate speed based on muscle contraction
	float speed = leftAcc + rightAcc;
	speed = speed/200.0 * 3.0;

	//Adjust orientation and position based on muscle contraction
	if (rightAcc > leftAcc) ce->body.rotation -= 5;
	else if (leftAcc > rightAcc) ce->body.rotation += 5;
	float changex = cosf(ce->body.rotation / RADIAS_TO_DEGREE) * speed;
	float changey = sinf(ce->body.rotation / RADIAS_TO_DEGREE) * speed;
	ce->body.position.x += changex;
	ce->body.position.y += changey;

	//Update brain
	Celegans_brain_update(ce->soul);
}

void Celegans_draw(Celegans* ce)
{
	vsRendererDrawSprite(&ce->body);
}


////////////////////////////////////////////////////////////
///	PROGRAM
////////////////////////////////////////////////////////////

static int drawbraindata = 0;

//Close application event
void quit() {
	exit(0);
}

//Press key event
void presskey(int key) {
	if (key == VS_KEY_S) drawbraindata = !drawbraindata;
	if (key == VS_KEY_Q) quit();
}

int main()
{
	//Create C.elegans
	Celegans* ce = Celegans_init();
	
	//Initialize libraryes
	vsSystemInit("C. elegans simulation", WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
	vsSystemBindEventQuit(quit);
	vsSystemBindEventKeyPress(presskey);
	vsGraphicsInit();
	
	//Create the view
	vsViewCreate(VSRECT(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT), 
				VSVECTOR2(WINDOW_WIDTH/2, WINDOW_HEIGHT/2),
				VSVECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT), 0);
	
	//Application loop
	for (;;)
	{
		////////////////////////////////////////////////////////////
		///	UPDATE
		////////////////////////////////////////////////////////////

		//Update each neuron of the brain
		Celegans_update(ce);

		//Check window limits for collision detection
		int collision = 0;
		if (ce->body.position.x <= 0) {ce->body.position.x = 0; collision = 1;}
		if (ce->body.position.x >= WINDOW_WIDTH-BODY_HEIGHT) {ce->body.position.x = WINDOW_WIDTH-BODY_HEIGHT; collision = 1;}
		if (ce->body.position.y <= 0) {ce->body.position.y = 0; collision = 1;}
		if (ce->body.position.y >= WINDOW_HEIGHT-BODY_HEIGHT) {ce->body.position.y = WINDOW_HEIGHT-BODY_HEIGHT; collision = 1;}
		if (collision) Celegans_brain_touchnose(ce->soul); //Trigget nose neurons
		
		//Some manual controlls
		if (vsKeyGetState(VS_KEY_F)) Celegans_brain_givefood(ce->soul);			//F = give food
		if (vsKeyGetState(VS_KEY_N)) Celegans_brain_touchnose(ce->soul);		//N = touch nose
		if (vsKeyGetState(VS_KEY_A)) Celegans_brain_touchanterior(ce->soul);	//A = touch anterior
		if (vsKeyGetState(VS_KEY_P)) Celegans_brain_touchposterior(ce->soul);	//P = touch posterior

		////////////////////////////////////////////////////////////
		///	DRAW
		////////////////////////////////////////////////////////////

		//Clear the screen
		vsRendererClear();
		
		//Draw brain and muscle data on the screen
		if (drawbraindata)
		{
			//Draw neurons activity
			for (int i = 0; i < NEURON_END; i++) {
				int x = i % 32;
				int y = i / 32.0;
				if (Celegans_brain_fired(ce->soul, i)) 
					vsRendererDrawRect(NULL, 0, 0, 0, 0, x * 16 + 1, y * 16 + 1, 16, 16, VS_COLOR_WHITE);
			}

			//Draw right side muscle activity
			for (int i = MUSCLE_RIGHT_START; i < MUSCLE_RIGHT_END; i++) {
				int x = i - MUSCLE_RIGHT_START;
				int y = 200;
				if (ce->soul->neurons[i]->state > 0) vsRendererDrawRect(NULL, 0, 0, 0, 0, x * 8 + 1, y, 8, 8, VSCOLOR(255, 0, 0, (unsigned char)(ce->soul->neurons[i]->state * 8.2)));
				else vsRendererDrawRect(NULL, 0, 0, 0, 0, x * 8 + 1, y, 8, 8, VSCOLOR(0, 0, 255, (unsigned char)(ce->soul->neurons[i]->state * -8.2))); 
			}
		
			//Draw left side muscle activity
			for (int i = MUSCLE_LEFT_START; i < MUSCLE_LEFT_END; i++) {
				int x = i - MUSCLE_LEFT_START;
				int y = 216;
				if (ce->soul->neurons[i]->state > 0) vsRendererDrawRect(NULL, 0, 0, 0, 0, x * 8 + 1, y, 8, 8, VSCOLOR(255, 0, 0, (unsigned char)(ce->soul->neurons[i]->state * 8.2)));
				else vsRendererDrawRect(NULL, 0, 0, 0, 0, x * 8 + 1, y, 8, 8, VSCOLOR(0, 0, 255, (unsigned char)(ce->soul->neurons[i]->state * -8.2)));
			}
		}

		//Draw the C.elegans body
		Celegans_draw(ce);

		//Draw
		vsRendererDisplay();
		vsWindowSwapBuffers();
		
		//Update events
		vsSystemPollEvents();
		
		usleep(8000);
	}
	
	//Close all the libraryes
	vsGraphicsDestroy();
	vsSystemDestroy();

	//Free brain
	Celegans_free(ce);

	return 0;
}
