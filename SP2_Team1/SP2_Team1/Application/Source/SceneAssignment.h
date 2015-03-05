#ifndef SCENEASSIGNMENT_H
#define SCENEASSIGNMENT_H

#include "Scene.h"

#include "Mesh.h"
#include"MatrixStack.h"
#include "Light.h"
#include "global.h"
#include "FPC.h"
#include "Objects.h"
#include "MoveAI.h"
#include <sstream>
#include <fstream>
#include <irrKlang.h>

/******************************************************************************/
/*!
\file	SceneAssignment.h
\author Lim Wei Heng, Andy Chan, Almeda Glenn, Lee Chun Kiat, Rayner Tay
\par	
\brief
		Logic and asthetics of application
*/
/******************************************************************************/
/******************************************************************************/
/*!
		Class SceneAssignment: Scene
\brief SceneAssignment class
*/
/******************************************************************************/
class SceneAssignment : public Scene
{
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		
		//light1
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,

		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		//light2
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHTENABLED,

		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		U_NUMLIGHTS,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_UI_ENABLED,
		U_UI_COLOR,

		U_TOTAL
	};
	enum GEOMETRY_TYPE
	{
		//level 1 for the supermarket
		GEO_BOTTOM_L1,
		GEO_LEFT_L1,
		GEO_RIGHT_L1,
		GEO_FRONT_L1,
		GEO_BACK_L1,
		GEO_APPLE,
		GEO_ORANGE,
		GEO_WATERMELON,
		GEO_CABBAGE,
		GEO_COCONUT,
		GEO_LODIN,
		GEO_ICECREAM,
		GEO_REGISTER,
		GEO_BASKET,
		GEO_COOLER,
		GEO_CEILING,
		GEO_CASHIER,
		GEO_UI,
		GEO_MOUTAIN,
		//level 2 for the supermarket - Rayner's work
		GEO_TOP2,
		GEO_LEFT2,
		GEO_RIGHT2,
		GEO_FRONT2,
		GEO_BACK2,
		GEO_CHAR,
		GEO_TENT,	
		GEO_DOORMAN,
		GEO_SHELF,
		GEO_TRAVELATORUP,
		GEO_TRAVELATORDN,
		GEO_BARRIER,
		GEO_PACKET,
		GEO_BOX1,
		GEO_CAN1,
		GEO_ARROW,
		GEO_SWITCH,
		GEO_LIFT,
		GEO_DOOR,
		GEO_ALARM,
		GEO_LIGHTBALL,

		GEO_BUILDING,

		GEO_PINKAI,
		GEO_BLUEAI,
		GEO_ORANGEAI,
		GEO_YELLOWAI,
		GEO_REDAI,
		GEO_TEXT,

		GEO_CAR,
		GEO_CAR2,
		GEO_CAR3,
		GEO_CAR4,
		GEO_TRUCK,
		GEO_BUS,

		NUM_GEOMETRY
	};

	enum SKYBOX_TYPE
	{
		SKYBOX_FRONT,
		SKYBOX_BACK,
		SKYBOX_LEFT,
		SKYBOX_RIGHT,
		SKYBOX_UP,
		SKYBOX_DOWN,
		SKYBOX_EXTEBANNER,
		SKYBOX_EXTESIDE,
		NUM_SKYBOX
	};

	enum CAMERA_TYPE
	{
		PLAYER_CAM,
		NOCLIP_CAM,
		NUM_CAMERA
	};

	//for the model blue
	enum MODEL_TYPE_BLUE
	{
		MODEL_BODY_BLUE = 0,
		MODEL_LEFTARM_BLUE,
		MODEL_LEFTFIST_BLUE,
		MODEL_LEFT_LEG_UPPER_BLUE,
		MODEL_LEFT_LEG_LOWER_BLUE,
		MODEL_RIGHTARM_BLUE,
		MODEL_RIGHTFIST_BLUE,
		MODEL_RIGHT_LEG_UPPER_BLUE,
		MODEL_RIGHT_LEG_LOWER_BLUE,
		NUM_MODEL_BLUE,
	};

	//for the model orange
	enum MODEL_TYPE_ORANGE
	{
		MODEL_BODY_ORANGE = 0,
		MODEL_LEFTARM_ORANGE,
		MODEL_LEFTFIST_ORANGE,
		MODEL_LEFT_LEG_UPPER_ORANGE,
		MODEL_LEFT_LEG_LOWER_ORANGE,
		MODEL_RIGHTARM_ORANGE,
		MODEL_RIGHTFIST_ORANGE,
		MODEL_RIGHT_LEG_UPPER_ORANGE,
		MODEL_RIGHT_LEG_LOWER_ORANGE,
		NUM_MODEL_ORANGE,
	};

	//for the model
	enum MODEL_TYPE_PINK
	{
		MODEL_BODY_PINK = 0,
		MODEL_LEFTARM_PINK,
		MODEL_LEFTFIST_PINK,
		MODEL_LEFT_LEG_UPPER_PINK,
		MODEL_LEFT_LEG_LOWER_PINK,
		MODEL_RIGHTARM_PINK,
		MODEL_RIGHTFIST_PINK,
		MODEL_RIGHT_LEG_UPPER_PINK,
		MODEL_RIGHT_LEG_LOWER_PINK,
		NUM_MODEL_PINK,
	};

	enum MODEL_TYPE_RED
	{
		MODEL_BODY_RED = 0,
		MODEL_LEFTARM_RED,
		MODEL_LEFTFIST_RED,
		MODEL_LEFT_LEG_UPPER_RED,
		MODEL_LEFT_LEG_LOWER_RED,
		MODEL_RIGHTARM_RED,
		MODEL_RIGHTFIST_RED,
		MODEL_RIGHT_LEG_UPPER_RED,
		MODEL_RIGHT_LEG_LOWER_RED,
		NUM_MODEL_RED,
	};

	enum MODEL_TYPE_YELLOW
	{
		MODEL_BODY_YELLOW = 0,
		MODEL_LEFTARM_YELLOW,
		MODEL_LEFTFIST_YELLOW,
		MODEL_LEFT_LEG_UPPER_YELLOW,
		MODEL_LEFT_LEG_LOWER_YELLOW,
		MODEL_RIGHTARM_YELLOW,
		MODEL_RIGHTFIST_YELLOW,
		MODEL_RIGHT_LEG_UPPER_YELLOW,
		MODEL_RIGHT_LEG_LOWER_YELLOW,
		NUM_MODEL_YELLOW,
	};

public:
	SceneAssignment();
	~SceneAssignment();
	static bool bReset;

	//Init functions
	void InitLevel1();
	void InitLevel2();
	void InitObjects();
	void InitExtSkybox();
	void InitCollision();
	void InitAI();
	void InitModelBlue();
	void InitModelOrange();
	void InitModelPink();
	void InitModelRed();
	void InitModelYellow();

	//Update functions
	void UpdateViewMode(double dt);
	void UpdateDoor(double dt);
	void UpdateLift(double dt);
	void UpdateLight(double dt);
	void UpdateModel(double dt);
	void UpdateTravel(double dt);
	void UpdateModelGlenn(double dt);
	void UpdateStaticAIGlenn(double dt);

	//Render functions
	void RenderLevel1();
	void RenderLevel2();
	void RenderChar();
	void RenderLargeObjects();
	void RenderRightColumn();
	void RenderLeftColumn();
	void RenderMiddleColumn();
	void RenderSmallObjects();
	void RenderModels();
	void RenderOut_Skybox();
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderMusic();
	void RenderBGM(); 
	void RenderMission();
	void RenderMission2();
	void RenderModelGlenn();
	void RenderQuadOnScreen(Mesh* mesh, float x_size, float y_size, float x, float y);
	void ReadFromText();	//this should be linked to RenderTextOnScreen function
	//slot in all AI movements here and call to RenderModels();
	void RenderModelBlue();
	void RenderModelOrange();
	void RenderModelPink();
	void RenderModelRed();
	void RenderModelYellow();
	void RenderModelVehicles();
	void RenderStaticAIGlenn();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	Mesh* meshList[NUM_GEOMETRY];
	Mesh* skyboxList[NUM_SKYBOX];		//for the skybox
	Mesh* modelList2[NUM_MODEL_BLUE];	//blue model animation
	Mesh* modelList6[NUM_MODEL_ORANGE];	//orange model animation
	Mesh* modelList7[NUM_MODEL_PINK];	//pink model animation
	Mesh* modelList3[NUM_MODEL_RED];	//red model animation
	Mesh* modelList4[NUM_MODEL_YELLOW];	//yellow model animation
	unsigned m_vertexArrayID;
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	//Char movement
	Vector3 charPos;
	Vector3 charDir;
	float yaw, yaw2;
	Mtx44 rot;

	//Door movement
	bool open;
	bool close;
	float DX;
	float DX2;

	//elevator - Andy's work
	float eley;
	float LiftDoor;
	float LiftDoor2;
	float waitTime, waitTime2,waitTime3,waitTime4;
	bool up;
	bool down;
	bool Lopen;
	bool Lclose;
	bool Lopen2;
	bool Lclose2;
	bool buttonPress, buttonPress2,buttonPress3,buttonPress4;

	//travelator - Andy's work
	bool travel;
	bool travelDwn;
	//music
	bool musicAlarm, loop1, loop2,musicStop, musicStop2, musicBGM, musicCrowd, Mission,Mission2 , coin, lightson,lightsoff;
	bool startfire, endfire;
	bool entrance, exit1;
	int timerez;
	
	//entrance
	bool open2;
	bool close2;
	float D2X;
	float D2X2;

	//model-related variables
	float rotateAngle;
	float translateX;
	float translateY;
	float translateZ;
	float transarrowY;
	//collision
	vector<Vector3> sphere;
	vector<float> radius;
	bool collideT, collideG;

	CAMERA_TYPE camType;
	FPC noClipCamera;
	FPC playerCamera;
	Light lights[2];

	void RenderMesh(Mesh *mesh, bool enableLight);

	MS modelStack, viewStack, projectionStack;

	vector<CObjects> ObjectList;

	CObjects Skybox1, Skybox2, Basket, Cooler, Shelf, Travellator, Cashier, Elevator, Register, Barrier,firealarm, House,
		     PickUp1, PickUp2, PickUp3, PickUp4, PickUp5, PickUp6, PickUp7,scenerio3, light;	


	int FPS;
	float ET,timer, aitimer1, aitimer2, aitimer3;

	bool render1, render2, render3, render4, render5, render6, render7, render8,renderscenerio3,renderscenerio3text,startgame,game3,gameover1;	
	bool place1,place2,place3,place4,place5,gameover,congrat,caught;
	bool ai1, ai2, ai3;
	bool renderai1text, renderai1text_2, renderai2text, renderai2text_2, renderai3text, renderai3text_2;
	bool start1, start2, start3;
	/*-----------------------AI-------------------------------------------*/
	float openStart;

	CObjects modelPink;
	int pinkSize; // size of  vector
	vector <bool> pinkCheck; //Give each transformation a bool, and set it to true
	vector <float> pinkMove; //Give each transformation a value, and set it to 0
	float pinkTime0, pinkTime1,pinkTime2;

	CObjects modelBlue;
	int blueSize; 
	vector <bool> blueCheck; 
	vector <float> blueMove; 
	float blueTime0, blueTime1, blueTime2;

	CObjects modelOrange;
	int orangeSize; 
	vector <bool> orangeCheck; 
	vector <float> orangeMove; 
	float orangeTime0, orangeTime1, orangeTime2;

	CObjects modelYellow;
	int yellowSize; 
	vector <bool> yellowCheck; 
	vector <float> yellowMove; 

	CObjects modelRed;
	int redSize; 
	vector <bool> redCheck; 
	vector <float> redMove; 


	//Scene1
	double speedAI;

	//Scene2
	bool gameStart, gameEnd;
	float gameTime;


	//Pause menu
	bool isPaused;
	int iChoice;

};

#endif

