#include <iostream>
#include "SceneAssignment.h"
#include "LoadTGA.h"
#include "GL\glew.h"
#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"
#include "MeshBuilder.h"
#include "Utility.h"
#include "functions.h"

#include "windows.h"
#include <MMSystem.h>

#pragma comment (lib, "irrKlang.lib")

using namespace std;
using namespace irrklang;


bool SceneAssignment::bReset = false;

/******************************************************************************/
/*!
\file	SceneAssignment.cpp
\author Andy Chan, Lim Wei Heng, Rayner Tay, Almeda Glenn, Lee Chun Kiat
\par	
\brief
		All items are rendered here
*/
/******************************************************************************/
ISoundEngine* engine = createIrrKlangDevice(ESOD_AUTO_DETECT,ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS);

ISoundEngine* engine2 = createIrrKlangDevice(ESOD_AUTO_DETECT,ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS); 

ISoundEngine* engine3 = createIrrKlangDevice(ESOD_AUTO_DETECT,ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS); 

ISoundEngine* engine4 = createIrrKlangDevice(ESOD_AUTO_DETECT,ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS); 

ISoundEngine* engine5 = createIrrKlangDevice(ESOD_AUTO_DETECT,ESEO_MULTI_THREADED | ESEO_LOAD_PLUGINS | ESEO_USE_3D_BUFFERS); 


SceneAssignment::SceneAssignment()
{
	bReset = false;
}
SceneAssignment::~SceneAssignment()
{
}
SceneAssignment car1, car2, car4, truck1, bus1;
/******************************************************************************/
/*!
\brief
Initialize the walls and doors used for level 1
/******************************************************************************/
void SceneAssignment::InitLevel1()
{
	//Level1 of the supermarket

	//Bottom
	meshList[GEO_BOTTOM_L1] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f);
	meshList[GEO_BOTTOM_L1]->textureID = LoadTGA("Image//lvl1_top.tga");
	meshList[GEO_BOTTOM_L1]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BOTTOM_L1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BOTTOM_L1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BOTTOM_L1]->material.kShininess = 50.f;

	//Left
	meshList[GEO_LEFT_L1] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT_L1]->textureID = LoadTGA("Image//green_side_lift.tga");
	meshList[GEO_LEFT_L1]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_LEFT_L1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LEFT_L1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_LEFT_L1]->material.kShininess = 50.f;

	//right
	meshList[GEO_RIGHT_L1] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT_L1]->textureID = LoadTGA("Image//green_side.tga");
	meshList[GEO_RIGHT_L1]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_RIGHT_L1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_RIGHT_L1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_RIGHT_L1]->material.kShininess = 50.f;

	//Front
	meshList[GEO_FRONT_L1] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT_L1]->textureID = LoadTGA("Image//green_side.tga");
	meshList[GEO_FRONT_L1]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_FRONT_L1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_FRONT_L1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_FRONT_L1]->material.kShininess = 50.f;

	//back
	meshList[GEO_BACK_L1] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK_L1]->textureID = LoadTGA("Image//supermarket texture_blue_front.tga");
	meshList[GEO_BACK_L1]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BACK_L1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BACK_L1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BACK_L1]->material.kShininess = 50.f;

	//Door
	meshList[GEO_DOOR] = MeshBuilder::GenerateQuad("Door", Color(1, 1, 1), 1.f);
	meshList[GEO_DOOR]->textureID = LoadTGA("Image//door.tga");
	meshList[GEO_DOOR]->material.kAmbient.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOOR]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOOR]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOOR]->material.kShininess = 50.f;
	//Lightball
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1 ,1, 1), 10, 10, 1);
	
}
/******************************************************************************/
/*!
\brief
Initialize the walls and doors used for level 2
/******************************************************************************/
void SceneAssignment::InitLevel2()
{
	//Lv 2 of supermarket
	//Top
	meshList[GEO_TOP2] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f);
	meshList[GEO_TOP2]->textureID = LoadTGA("Image//blue_top.tga");
	meshList[GEO_TOP2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TOP2]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TOP2]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TOP2]->material.kShininess = 50.f;

	//Left
	meshList[GEO_LEFT2] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f);
	meshList[GEO_LEFT2]->textureID = LoadTGA("Image//blue_dnup_lift.tga");
	meshList[GEO_LEFT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LEFT2]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LEFT2]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_LEFT2]->material.kShininess = 50.f;
	
	//right
	meshList[GEO_RIGHT2] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f);
	meshList[GEO_RIGHT2]->textureID = LoadTGA("Image//blue_dnup.tga");
	meshList[GEO_RIGHT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_RIGHT2]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_RIGHT2]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_RIGHT2]->material.kShininess = 50.f;
	
	//Front
	meshList[GEO_FRONT2] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f);
	meshList[GEO_FRONT2]->textureID = LoadTGA("Image//blue_updn.tga");
	meshList[GEO_FRONT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_FRONT2]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_FRONT2]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_FRONT2]->material.kShininess = 50.f;

	//back
	meshList[GEO_BACK2] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f);
	meshList[GEO_BACK2]->textureID = LoadTGA("Image//blue_updn.tga");
	meshList[GEO_BACK2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BACK2]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BACK2]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BACK2]->material.kShininess = 50.f;
}
/******************************************************************************/
/*!
\brief
Initialize all the objects that are going to be used in the program
/******************************************************************************/
void SceneAssignment::InitObjects()
{
	meshList[GEO_ARROW] = MeshBuilder::GenerateOBJ("tent", "OBJ//arrow.obj");
	meshList[GEO_ARROW]->textureID = LoadTGA("Image//firealarm_m.tga");
	meshList[GEO_ARROW]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_ARROW]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ARROW]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ARROW]->material.kShininess = 50.f;
	//lift
	meshList[GEO_TENT] = MeshBuilder::GenerateOBJ("tent", "OBJ//lift.obj");
	meshList[GEO_TENT]->textureID = LoadTGA("Image//lift_m.tga");
	meshList[GEO_TENT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_TENT]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TENT]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TENT]->material.kShininess = 50.f;

	meshList[GEO_MOUTAIN] = MeshBuilder::GenerateOBJ("tent", "OBJ//moutain.obj");
	meshList[GEO_MOUTAIN]->textureID = LoadTGA("Image//moutain.tga");
	meshList[GEO_MOUTAIN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MOUTAIN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MOUTAIN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_MOUTAIN]->material.kShininess = 50.f;

	meshList[GEO_DOORMAN] = MeshBuilder::GenerateOBJ("doorman", "OBJ//doorman.obj");
	meshList[GEO_DOORMAN]->textureID = LoadTGA("Image//doorman.tga");
	meshList[GEO_DOORMAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOORMAN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOORMAN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_DOORMAN]->material.kShininess = 50.f;

	//apple
	meshList[GEO_APPLE] = MeshBuilder::GenerateOBJ("apple", "OBJ//apple.obj");
	meshList[GEO_APPLE]->textureID = LoadTGA("Image//apple.tga");
	meshList[GEO_APPLE]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_APPLE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_APPLE]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_APPLE]->material.kShininess = 50.f;

	//orange
	meshList[GEO_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange.obj");
	meshList[GEO_ORANGE]->textureID = LoadTGA("Image//orange.tga");
	meshList[GEO_ORANGE]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ORANGE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ORANGE]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_ORANGE]->material.kShininess = 50.f;

	//watermelon
	meshList[GEO_WATERMELON] = MeshBuilder::GenerateOBJ("watermelon", "OBJ//watermelon.obj");
	meshList[GEO_WATERMELON]->textureID = LoadTGA("Image//watermelon.tga");
	meshList[GEO_WATERMELON]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_WATERMELON]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_WATERMELON]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_WATERMELON]->material.kShininess = 50.f;

	//cabbage
	meshList[GEO_CABBAGE] = MeshBuilder::GenerateOBJ("cabbage", "OBJ//cabbage.obj");
	meshList[GEO_CABBAGE]->textureID = LoadTGA("Image//cabbage.tga");
	meshList[GEO_CABBAGE]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CABBAGE]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CABBAGE]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CABBAGE]->material.kShininess = 50.f;
	//fruit basket
	meshList[GEO_BASKET] = MeshBuilder::GenerateOBJ("friutbasket", "OBJ//fruitbasket.obj");
	meshList[GEO_BASKET]->textureID = LoadTGA("Image//fruitbasket.tga");
	meshList[GEO_BASKET]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BASKET]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BASKET]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BASKET]->material.kShininess = 50.f;
	//register
	meshList[GEO_REGISTER] = MeshBuilder::GenerateOBJ("register", "OBJ//cashregister.obj");
	meshList[GEO_REGISTER]->textureID = LoadTGA("Image//cashregister.tga");
	meshList[GEO_REGISTER]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_REGISTER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_REGISTER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_REGISTER]->material.kShininess = 50.f;
	//cooler
	meshList[GEO_COOLER] = MeshBuilder::GenerateOBJ("cooler", "OBJ//cooler.obj");
	meshList[GEO_COOLER]->textureID = LoadTGA("Image//combine-cooler.tga");
	meshList[GEO_COOLER]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COOLER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COOLER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_COOLER]->material.kShininess = 50.f;

	//coconut
	meshList[GEO_COCONUT] = MeshBuilder::GenerateOBJ("coconut", "OBJ//coconut.obj");
	meshList[GEO_COCONUT]->textureID = LoadTGA("Image//coconut.tga");
	meshList[GEO_COCONUT]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COCONUT]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COCONUT]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COCONUT]->material.kShininess = 50.f;

	//lodin packet
	meshList[GEO_LODIN] = MeshBuilder::GenerateOBJ("lodin", "OBJ//lodin.obj");
	meshList[GEO_LODIN]->textureID = LoadTGA("Image//lodin.tga");
	meshList[GEO_LODIN]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LODIN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_LODIN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_LODIN]->material.kShininess = 50.f;

	//ice cream
	meshList[GEO_ICECREAM] = MeshBuilder::GenerateOBJ("icecream", "OBJ//icecream.obj");
	meshList[GEO_ICECREAM]->textureID = LoadTGA("Image//icecream.tga");
	meshList[GEO_ICECREAM]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ICECREAM]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ICECREAM]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ICECREAM]->material.kShininess = 50.f;

	//shelf
	meshList[GEO_SHELF] = MeshBuilder::GenerateOBJ("shelf", "OBJ//shelf.obj");
	meshList[GEO_SHELF]->textureID = LoadTGA("Image//shelf.tga");
	meshList[GEO_SHELF]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_SHELF]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_SHELF]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_SHELF]->material.kShininess = 50.f;

	//travelator up
	meshList[GEO_TRAVELATORUP] = MeshBuilder::GenerateOBJ("cooler", "OBJ//travelatorup.obj");
	meshList[GEO_TRAVELATORUP]->textureID = LoadTGA("Image//travelator.tga");
	meshList[GEO_TRAVELATORUP]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
	meshList[GEO_TRAVELATORUP]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TRAVELATORUP]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TRAVELATORUP]->material.kShininess = 50.f;
	//travelator down
	meshList[GEO_TRAVELATORDN] = MeshBuilder::GenerateOBJ("cooler", "OBJ//travelatordn.obj");
	meshList[GEO_TRAVELATORDN]->textureID = LoadTGA("Image//travelator.tga");
	meshList[GEO_TRAVELATORDN]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
	meshList[GEO_TRAVELATORDN]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_TRAVELATORDN]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_TRAVELATORDN]->material.kShininess = 50.f;

	//barrier
	meshList[GEO_BARRIER] = MeshBuilder::GenerateOBJ("cooler", "OBJ//barrier.obj");
	meshList[GEO_BARRIER]->textureID = LoadTGA("Image//combine-cooler.tga");
	meshList[GEO_BARRIER]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BARRIER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BARRIER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BARRIER]->material.kShininess = 50.f;
	//packet
	meshList[GEO_PACKET] = MeshBuilder::GenerateOBJ("packet", "OBJ//packet chips.obj");
	meshList[GEO_PACKET]->textureID = LoadTGA("Image//packet.tga");
	meshList[GEO_PACKET]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_PACKET]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_PACKET]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_PACKET]->material.kShininess = 50.f;
	//cerel1
	meshList[GEO_BOX1] = MeshBuilder::GenerateOBJ("box1", "OBJ//box1.obj");
	meshList[GEO_BOX1]->textureID = LoadTGA("Image//box1.tga");
	meshList[GEO_BOX1]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BOX1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_BOX1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_BOX1]->material.kShininess = 50.f;
	//can1
	meshList[GEO_CAN1] = MeshBuilder::GenerateOBJ("can1", "OBJ//can1.obj");
	meshList[GEO_CAN1]->textureID = LoadTGA("Image//can1.tga");
	meshList[GEO_CAN1]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CAN1]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CAN1]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CAN1]->material.kShininess = 50.f;

	meshList[GEO_BUILDING] = MeshBuilder::GenerateOBJ("house", "OBJ//house.obj"); 
	meshList[GEO_BUILDING] ->textureID = LoadTGA("Image//house.tga"); 
	meshList[GEO_BUILDING]->material.kAmbient.Set(0.1f, 0.1f, 0.1f); 
	meshList[GEO_BUILDING]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f); 
	meshList[GEO_BUILDING]->material.kSpecular.Set(1.0f, 1.0f, 1.0f); 
	meshList[GEO_BUILDING]->material.kShininess = 50.f; 

	//FireAlarm
	meshList[GEO_ALARM] = MeshBuilder::GenerateOBJ("pink", "OBJ//Firealarm.obj");
	meshList[GEO_ALARM] ->textureID = LoadTGA("Image//firealarm_m.tga");\
	meshList[GEO_ALARM]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ALARM]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_ALARM]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_ALARM]->material.kShininess = 50.f;

	meshList[GEO_CEILING] = MeshBuilder::GenerateOBJ("ceiling", "OBJ//ceiling.obj");
	meshList[GEO_CEILING]->textureID = LoadTGA("Image//ceiling.tga");
	meshList[GEO_CEILING]->material.kAmbient.Set(0.8f,0.8f, 0.8f);
	meshList[GEO_CEILING]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CEILING]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CEILING]->material.kShininess = 50.f;

	meshList[GEO_CAR] = MeshBuilder::GenerateOBJ("redcar", "OBJ//yellowcar.obj");
	meshList[GEO_CAR] ->textureID = LoadTGA("Image//yellowcar.tga");

	meshList[GEO_CAR2] = MeshBuilder::GenerateOBJ("yellowcar", "OBJ//redcar.obj");
	meshList[GEO_CAR2] ->textureID = LoadTGA("Image//redcar.tga");

	meshList[GEO_CAR3] = MeshBuilder::GenerateOBJ("greencar", "OBJ//greencar.obj");
	meshList[GEO_CAR3] ->textureID = LoadTGA("Image//greencar.tga");

	meshList[GEO_CAR4] = MeshBuilder::GenerateOBJ("bluecar", "OBJ//bluecar.obj");
	meshList[GEO_CAR4] ->textureID = LoadTGA("Image//bluecar.tga");

	meshList[GEO_TRUCK] = MeshBuilder::GenerateOBJ("truck", "OBJ//truck.obj");
	meshList[GEO_TRUCK] ->textureID = LoadTGA("Image//truck.tga");

	meshList[GEO_BUS] = MeshBuilder::GenerateOBJ("bus", "OBJ//bus.obj");
	meshList[GEO_BUS] ->textureID = LoadTGA("Image//bus.tga");

	//cashier
	meshList[GEO_CASHIER] = MeshBuilder::GenerateOBJ("tent", "OBJ//black.obj");
	meshList[GEO_CASHIER]->textureID = LoadTGA("Image//black.tga");
	meshList[GEO_CASHIER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CASHIER]->material.kDiffuse.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CASHIER]->material.kSpecular.Set(1.0f, 1.0f, 1.0f);
	meshList[GEO_CASHIER]->material.kShininess = 50.f;

	meshList[GEO_UI] = MeshBuilder::GenerateQuad("UI", Color(1, 1, 1), 1);
	meshList[GEO_UI] ->textureID = LoadTGA("Image//UI.tga");

	meshList[GEO_PINKAI] = MeshBuilder::GenerateOBJ("pink", "OBJ//pink.obj");
	meshList[GEO_PINKAI] ->textureID = LoadTGA("Image//pink.tga");

	meshList[GEO_ORANGEAI] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange.obj");
	meshList[GEO_ORANGEAI] ->textureID = LoadTGA("Image//orange.tga");

	meshList[GEO_REDAI] = MeshBuilder::GenerateOBJ("red", "OBJ//red.obj");
	meshList[GEO_REDAI] ->textureID = LoadTGA("Image//red.tga");

	meshList[GEO_YELLOWAI] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow.obj");
	meshList[GEO_YELLOWAI] ->textureID = LoadTGA("Image//yellow.tga");

	meshList[GEO_SWITCH] = MeshBuilder::GenerateOBJ("switch", "OBJ//power.obj");
	meshList[GEO_SWITCH] ->textureID = LoadTGA("Image//power.tga");

}
/******************************************************************************/
/*!
\brief
Initialize the individual parts of the body for our blue NPC
/******************************************************************************/
void SceneAssignment::InitModelBlue()
{
	//body
	modelList2[MODEL_BODY_BLUE] = MeshBuilder::GenerateOBJ("body", "OBJ//model_body.obj");
	modelList2[MODEL_BODY_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left arm
	modelList2[MODEL_LEFTARM_BLUE] = MeshBuilder::GenerateOBJ("left arm", "OBJ//model_left_arm.obj");
	modelList2[MODEL_LEFTARM_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left fist
	modelList2[MODEL_LEFTFIST_BLUE] = MeshBuilder::GenerateOBJ("left fist", "OBJ//model_left_fist.obj");
	modelList2[MODEL_LEFTFIST_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left leg upper
	modelList2[MODEL_LEFT_LEG_UPPER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_left_leg_upper.obj");
	modelList2[MODEL_LEFT_LEG_UPPER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//left leg lower
	modelList2[MODEL_LEFT_LEG_LOWER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_left_leg_lower.obj");
	modelList2[MODEL_LEFT_LEG_LOWER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right arm
	modelList2[MODEL_RIGHTARM_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_arm.obj");
	modelList2[MODEL_RIGHTARM_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right fist
	modelList2[MODEL_RIGHTFIST_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_fist.obj");
	modelList2[MODEL_RIGHTFIST_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right leg upper
	modelList2[MODEL_RIGHT_LEG_UPPER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_leg_upper.obj");
	modelList2[MODEL_RIGHT_LEG_UPPER_BLUE] ->textureID = LoadTGA("Image//blue.tga");

	//right leg lower
	modelList2[MODEL_RIGHT_LEG_LOWER_BLUE] = MeshBuilder::GenerateOBJ("blue", "OBJ//model_right_leg_lower.obj");
	modelList2[MODEL_RIGHT_LEG_LOWER_BLUE] ->textureID = LoadTGA("Image//blue.tga");
}
/******************************************************************************/
/*!
\brief
Initialize the individual parts of the body for our orange NPC
/******************************************************************************/
void SceneAssignment::InitModelOrange()
{
	//body
	modelList6[MODEL_BODY_ORANGE] = MeshBuilder::GenerateOBJ("body", "OBJ//orange_body.obj");
	modelList6[MODEL_BODY_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//left arm
	modelList6[MODEL_LEFTARM_ORANGE] = MeshBuilder::GenerateOBJ("left arm", "OBJ//orange_left_arm.obj");
	modelList6[MODEL_LEFTARM_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//left fist
	modelList6[MODEL_LEFTFIST_ORANGE] = MeshBuilder::GenerateOBJ("left fist", "OBJ//orange_left_fist.obj");
	modelList6[MODEL_LEFTFIST_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//left leg upper
	modelList6[MODEL_LEFT_LEG_UPPER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_left_leg_upper.obj");
	modelList6[MODEL_LEFT_LEG_UPPER_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//left leg lower
	modelList6[MODEL_LEFT_LEG_LOWER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_left_leg_lower.obj");
	modelList6[MODEL_LEFT_LEG_LOWER_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//right arm
	modelList6[MODEL_RIGHTARM_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_arm.obj");
	modelList6[MODEL_RIGHTARM_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//right fist
	modelList6[MODEL_RIGHTFIST_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_fist.obj");
	modelList6[MODEL_RIGHTFIST_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//right leg upper
	modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_leg_upper.obj");
	modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");

	//right leg lower
	modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE] = MeshBuilder::GenerateOBJ("orange", "OBJ//orange_right_leg_lower.obj");
	modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE] ->textureID = LoadTGA("Image//orange_.tga");
}
/******************************************************************************/
/*!
\brief
Initialize the individual parts of the body for our pink NPC
/******************************************************************************/
void SceneAssignment::InitModelPink()
{
	//body
	modelList7[MODEL_BODY_PINK] = MeshBuilder::GenerateOBJ("body", "OBJ//model_body.obj");
	modelList7[MODEL_BODY_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left arm
	modelList7[MODEL_LEFTARM_PINK] = MeshBuilder::GenerateOBJ("left arm", "OBJ//model_left_arm.obj");
	modelList7[MODEL_LEFTARM_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left fist
	modelList7[MODEL_LEFTFIST_PINK] = MeshBuilder::GenerateOBJ("left fist", "OBJ//model_left_fist.obj");
	modelList7[MODEL_LEFTFIST_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left leg upper
	modelList7[MODEL_LEFT_LEG_UPPER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_left_leg_upper.obj");
	modelList7[MODEL_LEFT_LEG_UPPER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//left leg lower
	modelList7[MODEL_LEFT_LEG_LOWER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_left_leg_lower.obj");
	modelList7[MODEL_LEFT_LEG_LOWER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right arm
	modelList7[MODEL_RIGHTARM_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_arm.obj");
	modelList7[MODEL_RIGHTARM_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right fist
	modelList7[MODEL_RIGHTFIST_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_fist.obj");
	modelList7[MODEL_RIGHTFIST_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right leg upper
	modelList7[MODEL_RIGHT_LEG_UPPER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_leg_upper.obj");
	modelList7[MODEL_RIGHT_LEG_UPPER_PINK] ->textureID = LoadTGA("Image//pink.tga");

	//right leg lower
	modelList7[MODEL_RIGHT_LEG_LOWER_PINK] = MeshBuilder::GenerateOBJ("pink", "OBJ//model_right_leg_lower.obj");
	modelList7[MODEL_RIGHT_LEG_LOWER_PINK] ->textureID = LoadTGA("Image//pink.tga");
}
/******************************************************************************/
/*!
\brief
Initialize the individual parts of the body for our red NPC
/******************************************************************************/
void SceneAssignment::InitModelRed()
{
		//body
	modelList3[MODEL_BODY_RED] = MeshBuilder::GenerateOBJ("body", "OBJ//red_body.obj");
	modelList3[MODEL_BODY_RED] ->textureID = LoadTGA("Image//red.tga");

	//left arm
	modelList3[MODEL_LEFTARM_RED] = MeshBuilder::GenerateOBJ("left arm", "OBJ//red_left_arm.obj");
	modelList3[MODEL_LEFTARM_RED] ->textureID = LoadTGA("Image//red.tga");

	//left fist
	modelList3[MODEL_LEFTFIST_RED] = MeshBuilder::GenerateOBJ("left fist", "OBJ//red_left_fist.obj");
	modelList3[MODEL_LEFTFIST_RED] ->textureID = LoadTGA("Image//red.tga");

	//left leg upper
	modelList3[MODEL_LEFT_LEG_UPPER_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_left_leg_upper.obj");
	modelList3[MODEL_LEFT_LEG_UPPER_RED] ->textureID = LoadTGA("Image//red.tga");

	//left leg lower
	modelList3[MODEL_LEFT_LEG_LOWER_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_left_leg_lower.obj");
	modelList3[MODEL_LEFT_LEG_LOWER_RED] ->textureID = LoadTGA("Image//red.tga");

	//right arm
	modelList3[MODEL_RIGHTARM_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_right_arm.obj");
	modelList3[MODEL_RIGHTARM_RED] ->textureID = LoadTGA("Image//red.tga");

	//right fist
	modelList3[MODEL_RIGHTFIST_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_right_fist.obj");
	modelList3[MODEL_RIGHTFIST_RED] ->textureID = LoadTGA("Image//red.tga");

	//right leg upper
	modelList3[MODEL_RIGHT_LEG_UPPER_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_right_leg_upper.obj");
	modelList3[MODEL_RIGHT_LEG_UPPER_RED] ->textureID = LoadTGA("Image//red.tga");

	//right leg lower
	modelList3[MODEL_RIGHT_LEG_LOWER_RED] = MeshBuilder::GenerateOBJ("red", "OBJ//red_right_leg_lower.obj");
	modelList3[MODEL_RIGHT_LEG_LOWER_RED] ->textureID = LoadTGA("Image//red.tga");
}/******************************************************************************/
/*!
\brief
Initialize the individual parts of the body for our yellow NPC
/******************************************************************************/
void SceneAssignment::InitModelYellow()
{
		//body
	modelList4[MODEL_BODY_YELLOW] = MeshBuilder::GenerateOBJ("body", "OBJ//yellow_body.obj");
	modelList4[MODEL_BODY_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//left arm
	modelList4[MODEL_LEFTARM_YELLOW] = MeshBuilder::GenerateOBJ("left arm", "OBJ//yellow_left_arm.obj");
	modelList4[MODEL_LEFTARM_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//left fist
	modelList4[MODEL_LEFTFIST_YELLOW] = MeshBuilder::GenerateOBJ("left fist", "OBJ//yellow_left_fist.obj");
	modelList4[MODEL_LEFTFIST_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//left leg upper
	modelList4[MODEL_LEFT_LEG_UPPER_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_left_leg_upper.obj");
	modelList4[MODEL_LEFT_LEG_UPPER_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//left leg lower
	modelList4[MODEL_LEFT_LEG_LOWER_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_left_leg_lower.obj");
	modelList4[MODEL_LEFT_LEG_LOWER_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//right arm
	modelList4[MODEL_RIGHTARM_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_right_arm.obj");
	modelList4[MODEL_RIGHTARM_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//right fist
	modelList4[MODEL_RIGHTFIST_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_right_fist.obj");
	modelList4[MODEL_RIGHTFIST_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//right leg upper
	modelList4[MODEL_RIGHT_LEG_UPPER_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_right_leg_upper.obj");
	modelList4[MODEL_RIGHT_LEG_UPPER_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");

	//right leg lower
	modelList4[MODEL_RIGHT_LEG_LOWER_YELLOW] = MeshBuilder::GenerateOBJ("yellow", "OBJ//yellow_right_leg_lower.obj");
	modelList4[MODEL_RIGHT_LEG_LOWER_YELLOW] ->textureID = LoadTGA("Image//yellow.tga");
}
/******************************************************************************/
/*!
\brief
Initialize the quards that produce the landscape ooutside of the suermarket
/******************************************************************************/
void SceneAssignment::InitExtSkybox()
{
	//external skybox
	skyboxList[SKYBOX_FRONT] = MeshBuilder::GenerateQuad("skybox_front", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_FRONT]->textureID = LoadTGA("Image//hills_ft.tga");

	skyboxList[SKYBOX_BACK] = MeshBuilder::GenerateQuad("skybox_back", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_BACK]->textureID = LoadTGA("Image//hills_bk.tga");

	skyboxList[SKYBOX_LEFT] = MeshBuilder::GenerateQuad("skybox_left", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_LEFT]->textureID = LoadTGA("Image//hills_lf.tga");

	skyboxList[SKYBOX_RIGHT] = MeshBuilder::GenerateQuad("skybox_right", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_RIGHT]->textureID = LoadTGA("Image//hills_rt.tga");

	skyboxList[SKYBOX_UP] = MeshBuilder::GenerateQuad("skybox_up", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_UP]->textureID = LoadTGA("Image//hills_up.tga");

	skyboxList[SKYBOX_DOWN] = MeshBuilder::GenerateQuad("skybox_down", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_DOWN]->textureID = LoadTGA("Image//exterior_floor.tga");

	skyboxList[SKYBOX_EXTEBANNER] = MeshBuilder::GenerateQuad("ext_banner", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_EXTEBANNER]->textureID = LoadTGA("Image//supermarket_banner_front.tga");

	skyboxList[SKYBOX_EXTESIDE] = MeshBuilder::GenerateQuad("ext_banner", Color(1, 1, 1), 1.f);
	skyboxList[SKYBOX_EXTESIDE]->textureID = LoadTGA("Image//supermarket_banner_side.tga");
}
/******************************************************************************/
/*!
\brief
Initialize add some collision for most of our large objects
/******************************************************************************/
void SceneAssignment::InitCollision()
{
	//Objects

	//Lv 1
	/*--BOT--*/
	Skybox1.translateVal.push_back(Vector3(0, 1, 0));
	Skybox1.rotateVal.push_back(-90);
	Skybox1.rotateAxis.push_back(Vector3(1,0,0));
	Skybox1.scaleVal.push_back(Vector3(800, 650, 1000));
	/*--LEFT--*/
	Skybox1.translateVal.push_back(Vector3(399, 74, 0));
	Skybox1.rotateVal.push_back(-90);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--RIGHT--*/
	Skybox1.translateVal.push_back(Vector3(-399,74, 0));
	Skybox1.rotateVal.push_back(90);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--FRONT--*/
	Skybox1.translateVal.push_back(Vector3(0, 74, -324));
	Skybox1.rotateVal.push_back(0);
	Skybox1.rotateAxis.push_back(Vector3(1,0,0));
	Skybox1.scaleVal.push_back(Vector3(800, 150, 1000));
	/*--BACK--*/
	Skybox1.translateVal.push_back(Vector3(0, 74, 324));
	Skybox1.rotateVal.push_back(180);
	Skybox1.rotateAxis.push_back(Vector3(0,1,0));
	Skybox1.scaleVal.push_back(Vector3(800, 150, 1000));

	//from -200 to -500, the left side of supermarket
	for(int i = 0; i < 16; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(-200 - (i*20), 30, 340));
	}
	//from 340 to -340, side of supermarket
	for(int i = 0; i < 34; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(-500 + (i*30), 30, -350));
		Skybox1.collisionPos.push_back(Vector3(-500, 30, 340 - (i*20)));
		Skybox1.collisionPos.push_back(Vector3(500, 30, 340 - (i*20)));
	}

	//from 200 to 500, the right side of lv 1 supermarket
	for(int i = 0; i < 16; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(200 + (i*20), 30, 340));
	}
	for(int i = 0; i < 12; i++)
	{
		Skybox1.collisionPos.push_back(Vector3(410, 30, 70 + (i*20)));
		Skybox1.collisionPos.push_back(Vector3(410, 30, -70 - (i*20)));
	}

	//for the lift doors
	Skybox1.collisionPos.push_back(Vector3(440, 30, -50));

	//middle platform
	Skybox1.collisionPos.push_back(Vector3(0, 30, 340));

	Skybox1.collisionRad = 20;

	ObjectList.push_back(Skybox1);

	//firealarm
	firealarm.translateVal.push_back(Vector3(400,-41,-100));
	firealarm.rotateVal.push_back(270);
	firealarm.rotateAxis.push_back(Vector3(0,1,0));
	firealarm.scaleVal.push_back(Vector3(15,14,15));
	//switch
	light.translateVal.push_back(Vector3(-418,130,50));
	light.rotateVal.push_back(90);
	light.rotateAxis.push_back(Vector3(0,1,0));
	light.scaleVal.push_back(Vector3(15,14,15));
	//Skybox2
	/*--TOP--*/
	Skybox2.translateVal.push_back(Vector3(0,296,0));
	Skybox2.rotateVal.push_back(90);
	Skybox2.rotateAxis.push_back(Vector3(1,0,0));
	Skybox2.scaleVal.push_back(Vector3(800, 655, 1000));
	/*--LEFT--*/
	Skybox2.translateVal.push_back(Vector3(400,225,0));
	Skybox2.rotateVal.push_back(-90);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--RIGHT--*/
	Skybox2.translateVal.push_back(Vector3(-400,225,0));
	Skybox2.rotateVal.push_back(90);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(650, 150, 1000));
	/*--FRONT--*/
	Skybox2.translateVal.push_back(Vector3(0,225,-325));
	Skybox2.rotateVal.push_back(0);
	Skybox2.rotateAxis.push_back(Vector3(1,0,0));
	Skybox2.scaleVal.push_back(Vector3(800, 150, 1000));
	/*--BACK--*/
	Skybox2.translateVal.push_back(Vector3(0,225,325));
	Skybox2.rotateVal.push_back(180);
	Skybox2.rotateAxis.push_back(Vector3(0,1,0));
	Skybox2.scaleVal.push_back(Vector3(800, 150, 1000));

	//from 340 to -340, side of supermarket
	for(int i = 0; i < 34; i++)
	{
		Skybox2.collisionPos.push_back(Vector3(-500 + (i*30), 180, 340));
		Skybox2.collisionPos.push_back(Vector3(-500 + (i*30), 180, -350));
		Skybox2.collisionPos.push_back(Vector3(-410, 180, 340 - (i*20)));
	}
	
	for(int i = 0; i < 12; i++)
	{
		Skybox2.collisionPos.push_back(Vector3(410, 180, 70 + (i*20)));
		Skybox2.collisionPos.push_back(Vector3(410, 180, -70 - (i*20)));
	}
	
	Skybox2.collisionRad = 30;

	ObjectList.push_back(Skybox2);

	//Basket
	for (int i = 0; i < 6;i++)
	{
		Basket.translateVal.push_back(Vector3(-220 + (95*i), 0, -305.5));
		Basket.rotateVal.push_back(-90);
		Basket.rotateAxis.push_back(Vector3(0,1,0));
		Basket.scaleVal.push_back(Vector3(5, 5, 7));

		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x,30,Basket.translateVal[2*i].z));
		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x+25,30,Basket.translateVal[2*i].z));
		Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i].x-25,30,Basket.translateVal[2*i].z));

		if ( i < 5 )
		{
			Basket.translateVal.push_back(Vector3(-385, 0, -220 + (95*i)));
			Basket.rotateVal.push_back(0);
			Basket.rotateAxis.push_back(Vector3(1,0,0));
			Basket.scaleVal.push_back(Vector3(5, 5, 7));

			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z));
			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z+25));
			Basket.collisionPos.push_back(Vector3(Basket.translateVal[2*i+1].x,30,Basket.translateVal[2*i+1].z-25));
		}
	}

	Basket.collisionRad = 15;
	ObjectList.push_back(Basket);

	//Cooler
	for(int i = 0; i < 2; ++i)
	{
		Cooler.translateVal.push_back(Vector3(-200, 0, 115*i));
		Cooler.scaleVal.push_back(Vector3(5, 5, 12));

		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z+35));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2].x,30,Cooler.translateVal[i*2].z-35));

		Cooler.translateVal.push_back(Vector3(200, 0, 115*i));
		Cooler.scaleVal.push_back(Vector3(5, 5, 12));

		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z+35));
		Cooler.collisionPos.push_back(Vector3(Cooler.translateVal[i*2+1].x,30,Cooler.translateVal[i*2+1].z-35));
	}

	Cooler.collisionRad = 20;
	ObjectList.push_back(Cooler);

	//Shelves
	//i = spheres
	for (int i = 0; i < 2; ++i)
	{
		int temp = -220;
		int temp1 = -220;
		Shelf.translateVal.push_back(Vector3(70*i-250, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i-250 + 25,30,-220));
		Shelf.collisionPos.push_back(Vector3(70*i-250 - 25,30,-220));

		Shelf.translateVal.push_back(Vector3(70*i+200, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,30, -220));
		Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,30,-220));
		
		//left shelves
		for (int j = 0; j < 6; j++)
		{
			Shelf.translateVal.push_back(Vector3(70*i+200, 150, temp));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,180,temp));
			Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,180,temp));
			temp+=100;
		}
		//right shelves
		for (int j = 0; j < 6; j++)
		{
			Shelf.translateVal.push_back(Vector3(70*i-300, 150, temp1));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i-300 + 25,180,temp1));
			Shelf.collisionPos.push_back(Vector3(70*i-300 - 25,180,temp1));
			temp1+=100;
		}
	}
	//for middle and box blocking travelator
	for (int i = 0; i < 3; ++i)
	{
		int temp1 = 200;
		Shelf.translateVal.push_back(Vector3(70*i-250, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i-250 + 25,30,-220));
		Shelf.collisionPos.push_back(Vector3(70*i-250 - 25,30,-220));

		Shelf.translateVal.push_back(Vector3(70*i+200, 0, -220));
		Shelf.scaleVal.push_back(Vector3(15,5,4));

		Shelf.collisionPos.push_back(Vector3(70*i+200 + 25,30, -220));
		Shelf.collisionPos.push_back(Vector3(70*i+200 - 25,30,-220));

		
	
		//middle shelves
		for (int k = 0; k < 4; k++)
		{
			Shelf.translateVal.push_back(Vector3(70*i-70, 150, temp1));
			Shelf.scaleVal.push_back(Vector3(15,5,4));

			Shelf.collisionPos.push_back(Vector3(70*i-70 + 25,180,temp1));
			Shelf.collisionPos.push_back(Vector3(70*i-70 - 25,180,temp1));
			temp1 -=100;
		}
		
	}
	Shelf.collisionRad = 15;
	
	ObjectList.push_back(Shelf);

	//Register
	for(int i = 0; i < 4; i++)
	{
		Register.translateVal.push_back(Vector3(70*i-300, 0, 240));
		Register.scaleVal.push_back(Vector3(3.5, 3.6, 3));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z-15));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x,30,Register.translateVal[i].z+15));
		Register.collisionPos.push_back(Vector3(Register.translateVal[i].x-15,30,Register.translateVal[i].z+15));
	}

	Register.collisionRad = 8;
	ObjectList.push_back(Register);

	int tempT = 40;
	for (int i = 0; i < 2; ++i)
	{
		Travellator.translateVal.push_back(Vector3(tempT, -10, -60));
		Travellator.rotateVal.push_back(-90);
		Travellator.rotateAxis.push_back(Vector3(0, 1, 0));
		Travellator.scaleVal.push_back(Vector3(26, 18, 13));
		tempT -= 80;
	}


	int tempX = -80;
	for (int i = 0; i < 2; ++i)
	{
		int tempZ = 160;
		for (int j = 0; j < 5; ++j)
		{
			Travellator.collisionPos.push_back(Vector3(tempX,30,tempZ));
			tempZ -= 30;
		}
		tempX += 58;
	}

	int tempX2 = 8;
	for (int i = 0; i < 2; ++i)
	{
		int tempZ = 160;
		for (int j = 0; j < 5; ++j)
		{
			Travellator.collisionPos.push_back(Vector3(tempX2,30,tempZ));
			tempZ -= 30;
		}
		tempX2 += 58;
	}
/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	Travellator.collisionPos.push_back(Vector3(-47,30,100));
/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	Travellator.collisionPos.push_back(Vector3(35, 180,-205));

	Travellator.collisionRad = 10;
	ObjectList.push_back(Travellator);

	//Cashier
	for (int i = 0; i < 4; ++i)
	{
		Cashier.translateVal.push_back(Vector3(70*i-312,0,240));
		Cashier.rotateVal.push_back(90);
		Cashier.rotateAxis.push_back(Vector3(0,1,0));
		Cashier.scaleVal.push_back(Vector3(5, 5, 5));
	}

	ObjectList.push_back(Cashier);

	//Elevator
	Elevator.translateVal.push_back(Vector3(455,0,1));
	Elevator.rotateVal.push_back(270);
	Elevator.rotateAxis.push_back(Vector3(0,1,0));
	Elevator.scaleVal.push_back(Vector3(12.5,12,13));

	ObjectList.push_back(Elevator);

	Barrier.translateVal.push_back(Vector3(10,150,-200));
	Barrier.rotateVal.push_back(-90);
	Barrier.rotateAxis.push_back(Vector3(0,1,0));
	Barrier.scaleVal.push_back(Vector3(10, 5, 18));

		//updated from Glenn
	for(int i = 0; i < 4; i++)
	{
		Barrier.collisionPos.push_back(Vector3(-80, 180, -140 - (i*32.5)));
		Barrier.collisionPos.push_back(Vector3(-90, 180, -140 - (i*32.5)));

		Barrier.collisionPos.push_back(Vector3(80, 180, -140 - (i*32.5)));
		Barrier.collisionPos.push_back(Vector3(90, 180, -140 - (i*32.5)));
	}

	Barrier.collisionPos.push_back(Vector3(-5, 180, -240));

	
	Barrier.scaleVal.push_back(Vector3(10,7,20));
	
	Barrier.collisionRad = 20;
	ObjectList.push_back(Barrier);

		//Houses on left side
	for(int i = 0; i < 2; i++)
	{
		if(i < 2)
		{
		House.translateVal.push_back(Vector3(-920 + (200*i), 0, 250));
		House.rotateVal.push_back(90);
		House.rotateAxis.push_back(Vector3(0,1,0));
		House.scaleVal.push_back(Vector3(20, 20, 20));

		House.collisionPos.push_back(Vector3(-920+(200*i), 30, 250));
		House.collisionPos.push_back(Vector3(-920+60+(200*i), 30, 250));

		House.collisionPos.push_back(Vector3(-920+(200*i), 30, 250 - 30));
		House.collisionPos.push_back(Vector3(-920+60+(200*i), 30, 250-30));
	}
	
	//Houses on right side
	for(int i = 0; i < 2; i++)
	{
	
		if(i < 2)
		{
		House.translateVal.push_back(Vector3(620 + (200*i), 0, 250));
		House.rotateVal.push_back(90);
		House.rotateAxis.push_back(Vector3(0,1,0));
		House.scaleVal.push_back(Vector3(20, 20, 20));

		
		House.collisionPos.push_back(Vector3(620+(200*i), 30, 250));
		House.collisionPos.push_back(Vector3(620+60+(200*i), 30, 250));

		House.collisionPos.push_back(Vector3(620+(200*i), 30, 250 - 30));
		House.collisionPos.push_back(Vector3(620+60+(200*i), 30, 250-30));
	}
	
	House.collisionRad = 50;
	ObjectList.push_back(House);

	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	PickUp1.translateVal.push_back(Vector3(-151,13,-215));
	PickUp1.rotateVal.push_back(-180);
	PickUp1.rotateAxis.push_back(Vector3(0,1,0));
	PickUp1.scaleVal.push_back(Vector3(6,6,6));

	PickUp2.translateVal.push_back(Vector3(-380.5,16,135));
	PickUp2.scaleVal.push_back(Vector3(5,5,5));

	PickUp3.translateVal.push_back(Vector3(200,35.5,35.5));
	PickUp3.rotateVal.push_back(-90);
	PickUp3.rotateAxis.push_back(Vector3(0,1,0));
	PickUp3.scaleVal.push_back(Vector3(5,5,5));

	PickUp4.translateVal.push_back(Vector3(315,17,-220)); 
	PickUp4.scaleVal.push_back(Vector3(5,5,5)); 

	PickUp5.translateVal.push_back(Vector3(-210,165,-127)); 
	PickUp5.scaleVal.push_back(Vector3(5,5,5)); 

	PickUp6.translateVal.push_back(Vector3(295,141,-20)); 
	PickUp6.scaleVal.push_back(Vector3(5,5,5)); 

	PickUp7.translateVal.push_back(Vector3(100,154,200)); 
	PickUp7.scaleVal.push_back(Vector3(5,5,5)); 
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
}
	}
}
/******************************************************************************/
/*!
\brief
Initialize the combined parts of the body for our scripted movement NPCs
/******************************************************************************/
void SceneAssignment::InitAI()
{
	openStart = 0; 
	speedAI = 1;

	InitModelPink();

	modelPink.translateVal.push_back(Vector3(90,0,500));
	modelPink.rotateVal.push_back(0);
	modelPink.rotateAxis.push_back(Vector3(0,1,0));
	modelPink.scaleVal.push_back(Vector3(5,5,5));
	pinkSize = 100;
	pinkTime0 = pinkTime1 = pinkTime2 = 0; 

	for(int i=0;i<pinkSize;++i) {pinkCheck.push_back(true); pinkMove.push_back(0);}

	InitModelBlue();

	modelBlue.translateVal.push_back(Vector3(160,0,550));
	modelBlue.rotateVal.push_back(0);
	modelBlue.rotateAxis.push_back(Vector3(0,1,0));
	modelBlue.scaleVal.push_back(Vector3(5,5,5));
	blueSize = 100;
	blueTime0 = blueTime1 = blueTime2 = 0; 

	for(int i=0;i<blueSize;++i) {blueCheck.push_back(true); blueMove.push_back(0);}

	InitModelOrange();

	modelOrange.translateVal.push_back(Vector3(90,0,600));
	modelOrange.rotateVal.push_back(0);
	modelOrange.rotateAxis.push_back(Vector3(0,1,0));
	modelOrange.scaleVal.push_back(Vector3(5,5,5));
	orangeSize = 100;
	orangeTime1 = orangeTime2 = 0; 

	for(int i=0;i<orangeSize;++i) {orangeCheck.push_back(true); orangeMove.push_back(0);}

	InitModelYellow();
	
	modelYellow.translateVal.push_back(Vector3(640,0,200));
	modelYellow.rotateVal.push_back(180);
	modelYellow.rotateAxis.push_back(Vector3(0,1,0));
	modelYellow.scaleVal.push_back(Vector3(5,5,5));
	yellowSize = 100;

	for(int i=0;i<yellowSize;++i) {yellowCheck.push_back(true); yellowMove.push_back(0);}

	InitModelRed();

	modelRed.translateVal.push_back(Vector3(-660,0,200));
	modelRed.rotateVal.push_back(180);
	modelRed.rotateAxis.push_back(Vector3(0,1,0));
	modelRed.scaleVal.push_back(Vector3(5,5,5));
	redSize = 100;

	for(int i=0;i<redSize;++i) {redCheck.push_back(true); redMove.push_back(0);}
}
/******************************************************************************/
/*!
\brief
Initialize define our variables and also call all other Init and initialise our lights
/******************************************************************************/
void SceneAssignment::Init()
{
	//Pause
	isPaused = false;
	iChoice = 1;

	//car, truck and bus
	car1.translateX = 0;
	car1.translateZ = 0;
	car2.translateX = 0;
	car4.translateX = 0;
	truck1.translateX = 0;
	bus1.translateX = 0;
	//arrow on top of game master
	transarrowY = 0;

	//scene2
	gameStart = false; 
	gameEnd = false;
	//scene3
	game3 = true;
	renderscenerio3 = true;
	gameover1 = true;
	startgame = true;
	//travelator
	travel = false;
	travelDwn = false;

	//Character X,Y,Z
	charPos.Set(0,5,0);
	charDir.Set(0,0,1);

	//Door
	DX = -75;
	DX2 = -144;
	D2X = 142;
	D2X2 = 68 ;
	open = false;
	close = false;
	open2 = false;
	close2 = false;

	//ele
	eley =0;
	up = false;
	down = false;
	Lopen = false;
	Lclose = false;
	Lopen2 = false;
	Lclose2 = false;
	waitTime = waitTime2 = waitTime3 = waitTime4 = 0;
	buttonPress = buttonPress2 = buttonPress3 = buttonPress4 =  false;
	//music
	musicAlarm = coin = false; 
 	musicBGM = musicCrowd = Mission = Mission2 = true;

	lightson = lightsoff = false;
	loop1 = startfire = endfire = false;
	loop2 = musicStop = musicStop2 = false;
	entrance = exit1 = false;
	timerez = 0;
	//debug
	debug = false;

	render1 = render2 = render3 = render4 = render5 = render6 = render7 = render8 = true; 

	ai1 = ai2 = ai3 = true;
	renderai1text = renderai2text = renderai3text = false;
	renderai1text_2 = renderai2text_2 = renderai3text_2 = false;
	aitimer1 = aitimer2 = aitimer3 = 0;
	start1= start2 = start3 = false;

	LiftDoor = LiftDoor2 = 0;

	// Set background color to dark blue
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//Enable depth buffer and depth testing
	glEnable(GL_DEPTH_TEST);

	//Enable back face culling
	glEnable(GL_CULL_FACE);

	// Enable blending(Practical 9)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Default to fill mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//Load vertex and fragment shaders
	//new shaders(Practical 9)
	m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//MultiLight.fragmentshader" );

	// Use our shader
	//glUseProgram(m_programID);
	// Get a handle for our "MVP" uniform
	
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	//1st light
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	//2nd light
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	////3rd light
	//m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
	//m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
	//m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
	//m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
	//m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
	//m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
	
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	//m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
	//m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
	//m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");

	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	// Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	glUseProgram(m_programID);
	//DIR Light
	lights[0].type = Light::LIGHT_DIRECTIONAL;
	lights[0].position.Set(0, 10, 0);
	lights[0].color.Set(1, 1, 1);
	lights[0].power = 1;
	lights[0].kC = 1.f;
	lights[0].kL = 0.0f;
	lights[0].kQ = 0.00f;
	lights[0].exponent = 3.f;
	lights[0].spotDirection.Set(0.f, 0.f, 0.f);
	//SPOT Light
	lights[1].type = Light::LIGHT_SPOT;
	lights[1].position.Set(0, 20, 0);
	lights[1].color.Set(1, 1, 1);
	lights[1].power = 0.5;
	lights[1].kC = 1.f;
	lights[1].kL = 0.01f;
	lights[1].kQ = 0.001f;
	lights[1].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[1].cosInner = cos(Math::DegreeToRadian(30));
	lights[1].exponent = 3.f;
	lights[1].spotDirection.Set(0.f, 1.f, 0.f);

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], lights[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], lights[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], lights[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], lights[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], lights[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], lights[0].exponent);

	glUniform1i(m_parameters[U_LIGHT1_TYPE], lights[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &lights[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], lights[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], lights[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], lights[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], lights[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], lights[1].exponent);

	//glUniform1i(m_parameters[U_LIGHT2_TYPE], lights[2].type);
	//glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &lights[2].color.r);
	//glUniform1f(m_parameters[U_LIGHT2_POWER], lights[2].power);
	//glUniform1f(m_parameters[U_LIGHT2_KC], lights[2].kC);
	//glUniform1f(m_parameters[U_LIGHT2_KL], lights[2].kL);
	//glUniform1f(m_parameters[U_LIGHT2_KQ], lights[2].kQ);
	//glUniform1f(m_parameters[U_LIGHT2_EXPONENT], lights[2].exponent);


	glUniform1i(m_parameters[U_NUMLIGHTS],3);

	//Initialize camera settings
	camType = PLAYER_CAM;
	playerCamera.Init(Vector3(37, 30, 462), Vector3(0, 1, 0), Vector3(0, 1, 0));
	playerCamera.SetSensitivity(13, 13);
	playerCamera.SetSpeed(150, 800);
	

	InitCollision();
	InitLevel1();
	InitLevel2();
	InitObjects();
	InitAI();
	InitExtSkybox();

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 100000.f);
	projectionStack.LoadMatrix(projection);

	collideT = collideG = false;

	FPS = ET = 0;

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//Consolas.tga");
}
static float LSPEED = 20.f;
static float ROT_LIMIT = 45.f;
static float SCALE_LIMIT = 5.f;
static float CSPEED = 20.f;
static float RSPEED = 145.f;
static float ROTATE_SPEED = 30.f;
/******************************************************************************/
/*!
\brief
Update all of our different viewmode such as wireframe mode
/******************************************************************************/
void SceneAssignment::UpdateViewMode(double dt)
{
	if(Application::IsKeyPressed('1')) //enable back face culling
		glEnable(GL_CULL_FACE);
	if(Application::IsKeyPressed('2')) //disable back face culling
		glDisable(GL_CULL_FACE);
	if(Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if(Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
}
/******************************************************************************/
/*!
\brief
Update the lift movement and the lift door also
/******************************************************************************/
void SceneAssignment::UpdateLift(double dt)
{
	//Elevator codes============================================================================================================
	if(up)
	{
		eley +=(float)(60 * dt);
		playerCamera.position.y +=(float)(60 * dt);
		playerCamera.target.y +=(float)(60 * dt);
		playerCamera.move = false;
	}
	if(down)
	{
		eley -=(float)(60 * dt);
		playerCamera.position.y -=(float)(60 * dt);
		playerCamera.target.y -=(float)(60 * dt);
		playerCamera.move = false;
	}
	if(Lopen)
	{
		LiftDoor +=(float)(100* dt);
	}
	if(Lclose)
	{
		LiftDoor -=(float)(100* dt);
	}
	if(Lopen2)
	{
		LiftDoor2 +=(float)(100* dt);
	}
	if(Lclose2)
	{
		LiftDoor2 -=(float)(100* dt);
	}
	//Lift Door
	if(((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390))&&(eley <=100))
	{
		Lopen = true;
	}
	if(((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390))&&(eley >=100))
	{
		Lopen2 = true;
	}
	else if(!((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390)))
	{
		Lopen = false;
		Lclose = true;
	}
	if(!((playerCamera.position.z >=-65)&&(playerCamera.position.z <=45))&&((playerCamera.position.x >=280)&&(playerCamera.position.x <=390)))
	{
		Lopen2 = false;
		Lclose2 = true;
	}


	if (LiftDoor <= 0)
		Lclose = false;

	if (LiftDoor >= 118) {
		Lopen = false;
	}

	if (LiftDoor2 >= 118)
	{
		Lopen2 = false;
	}
	if (LiftDoor2 <= 0)
	{
		Lclose2 = false;
	}
	

	//level1-2
	if (Application::IsKeyPressed('C')&&(playerCamera.position.y <= 180)&& playerCamera.position.x > 395 && (down == false))
	{ 
			Lclose = true;
			buttonPress = true;
	}

	if (buttonPress == true)
	{
		if (waitTime < 75)
			waitTime+=1;
		else if (playerCamera.position.y <= 179)
			up = true;

		if (up == true)
		{
			eley +=1;
			playerCamera.position.y +=1;
			playerCamera.target.y +=1;
			buttonPress = false;
			waitTime = 0;
		}
	}

	
	if ((playerCamera.position.y>=180)&&(up == true))
	{
		up = false;
		Lopen2 = true;
		eley +=1;
		charPos.y+=1;
		playerCamera.move = true;
	}

	//level2-1
	if (Application::IsKeyPressed('V')&&(playerCamera.position.y >= 30)&& playerCamera.position.x > 395 && up == false)
	{ 
			Lclose2 = true;
			buttonPress2 = true;
	}

	if (buttonPress2 == true)
	{
		if (waitTime2 < 75)
			waitTime2+=1;
		else if (playerCamera.position.y >= 31)
			down = true;

		if (down == true)
		{
			eley -=1;
			playerCamera.position.y -=1;
			playerCamera.target.y -=1;
			buttonPress2 = false;
			waitTime2 = 0;
		}
	}



	if ((playerCamera.position.y<=30)&&(down == true))
	{
		down = false;
		Lopen = true;
		eley -=1;
		charPos.y-=1;
		playerCamera.move = true;
		
	}
}
/******************************************************************************/
/*!
\brief
Update the exit and entrance door for the player and moving NPCs to enter and exit
/******************************************************************************/
void SceneAssignment::UpdateDoor(double dt)
{
	openStart += dt; 
	pinkTime1 += dt; 
	pinkTime2 += dt; 
	blueTime1 += dt; 
	blueTime2 += dt; 
	orangeTime1 += dt; 
	orangeTime2 += dt; 
 		 

	if(loop1 == true)
	{
		open = true;
		open2 = true;
	}

//==========================================================Door EXIT Start=====================================
	if(open)
	{
		DX +=(float)(30 * dt);
		DX2 -=(float)(30 * dt);
	}
	if(close)
	{
		DX -=(float)(30 * dt);
		DX2 +=(float)(30 * dt);
	}

	if (((playerCamera.position.z >= 250)&&(playerCamera.position.z <= 300))&&((playerCamera.position.x >= -166)&&(playerCamera.position.x <= -60))&&(close == false))
	{
		open = true;

		if (exit1 == false) {
			engine5->play2D("../irrKlang/media/bye.wav",false);
			exit1 = true;
			entrance = false;
		}
	}

	if (buttonPress3 == false) {

		if (pinkTime1 >= 61 && pinkTime1 <= 63) { 
			open = true; 
		} 

		if (pinkTime1 >= 61) 
			pinkTime0 += dt; 

		if (pinkTime0 >= 72) { 
			open = true; 
			pinkTime0 = 0; 
		} 

		if (blueTime1 >= 38 && blueTime1 <= 40) { 
			open = true; 
		} 

		if (blueTime1 >= 38) 
			blueTime0 += dt; 

		if (blueTime0 >= 50) { 
			open = true; 
			blueTime0 = 0; 
		} 

		if (orangeTime1 >= 54 && orangeTime1 <= 56) { 
			open = true; 
		} 

		if (orangeTime1 >= 53) 
			orangeTime0 += dt; 

		if (orangeTime0 >= 66) { 
			open = true; 
			orangeTime0 = 0; 
		} 
	}

	if (((DX >=-8)&&(DX2 <=-210)))
	{
		open = false;
		close = true;
	}
	if(((DX <=-75)&&(DX2>=-144))&&(close == true))
	{
		close = false;
	}
//============================================================END========================

//==========================================================Door Entrance Start===================
	if(open2)
	{
		D2X +=(float)(30 * dt);
		D2X2 -=(float)(30 * dt);
	}
	if(close2)
	{
		D2X -=(float)(30 * dt);
		D2X2 +=(float)(30 * dt);
	}
	if (((playerCamera.position.z >= 350)&&(playerCamera.position.z <= 465))&&((playerCamera.position.x >= 70)&&(playerCamera.position.x <= 150))&&(close2 == false))
	{
		open2 = true;
		if (entrance == false) {
			engine5->play2D("../irrKlang/media/welcome.wav",false);
			entrance = true;
			exit1 = false;
		}
	}

	if (buttonPress3 == false) {

		if (pinkTime2 >= 72) { 
			open2 = true; 
			pinkTime2 = 0; 
		} 

		if (blueTime2 >= 50) { 
			open2 = true; 
			blueTime2 = 0; 
		} 

		if (orangeTime2 >= 66) { 
			open2 = true; 
			orangeTime2 = 0; 
		} 
	}

	if (openStart >= 1 && openStart <= 3) { 
		open2 = true; 
	} 

	if(((D2X >=221) && (D2X2<=-11)))
	{
		open2 = false;
		close2 = true;
	}
	if(((D2X <=142)&&(D2X2 >=68))&&(close2 == true))
	{
		close2 = false;
	}
	//==============================================firealarm===================================================================
	
	
//============================================================END===============================================================================================

}
/******************************************************************************/
/*!
\brief
Update the light effect when there is fire alarm
/******************************************************************************/
void SceneAssignment::UpdateLight(double dt)
{
	if(Application::IsKeyPressed('I'))
		lights[0].position.z -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('K'))
		lights[0].position.z += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('J'))
		lights[0].position.x -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('L'))
		lights[0].position.x += (float)(LSPEED * dt);
	if(Application::IsKeyPressed('O'))
		lights[0].position.y -= (float)(LSPEED * dt);
	if(Application::IsKeyPressed('P'))
		lights[0].position.y += (float)(LSPEED * dt);
}
/******************************************************************************/
/*!
\brief
Update the player and moving NPCs to be able to use the travelator
/******************************************************************************/
void SceneAssignment::UpdateTravel(double dt)
{
	//========================================================Travelator Up========================================================================================

	if (travel)
	{
		playerCamera.position.z -=(float)(25 * dt * 3);
		playerCamera.position.y +=(float)(11 * dt* 3);
		playerCamera.target.z -=(float)(25 * dt* 3);
		playerCamera.target.y +=(float)(11 * dt* 3);
		playerCamera.move = false;
	}
	else if (playerCamera.position.x <= 395)
	{
		playerCamera.move = true;
	}
	if (travelDwn)
	{
		playerCamera.position.z +=(float)(25 * dt* 3);
		playerCamera.position.y -=(float)(11 * dt* 3);
		playerCamera.target.z +=(float)(25 * dt* 3);
		playerCamera.target.y -=(float)(11 * dt* 3);
		playerCamera.move = false;
	}

	//=========================================================Boolean End=========================================================================================
	if (((playerCamera.position.z >= 123)&&(playerCamera.position.z <=130)) && ((playerCamera.position.x >=22) && (playerCamera.position.x <=44)))
	{
		travel = true;
	}
	if(playerCamera.position.y >= 180)
	{
		travel = false;
	}
	//=========================================================UP END===============================================================================================
	
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	if (((playerCamera.position.z >= -225)&&(playerCamera.position.z <=-210)) && ((playerCamera.position.x >= -60) && (playerCamera.position.x <=-36))&&(playerCamera.position.y >= 180))
	/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/
	{
		travelDwn = true;
	}
	if(playerCamera.position.y <= 30)
	{
		travelDwn = false;
	}
	//============================================================END===============================================================================================

}	
/******************************************************************************/
/*!
\brief
Walking animation of moving NPCs
/******************************************************************************/
void SceneAssignment::UpdateModelGlenn(double dt)
{
	static int rotateDir = 1;

	if(rotateAngle * rotateDir > 10)
		rotateDir = -rotateDir;
	rotateAngle += (float)(rotateDir * ROTATE_SPEED * dt);
}
/******************************************************************************/
/*!
\brief
Update to call all other update functions and also update the games and scenerios in our program
/******************************************************************************/
void SceneAssignment::Update(double dt)
{
	if(Application::IsKeyPressed(VK_ESCAPE)) {
		isPaused = true;
		engine->setAllSoundsPaused(true);
		engine2->setAllSoundsPaused(true);
		engine3->setAllSoundsPaused(true);
		engine4->setAllSoundsPaused(true);
		engine5->setAllSoundsPaused(true);
	}


	if (isPaused == false) {

		playerCamera.Update(dt,ObjectList);

		//car, bus, truck
		car1.translateZ += (float)(50 * dt);
		car1.rotateAngle += (float)(10 * dt);
		car2.translateX += (float)(300 * dt);
		car4.translateX += (float)(300 * dt);
		truck1.translateX += (float)(300 * dt);
		bus1.translateX += (float)(300 * dt);

		//arrow
		transarrowY -=(float)(10*dt);
		bool collideALL = Collision(charPos,ObjectList);

		FPS = 1/dt;
		ET += dt;

		UpdateModelGlenn(dt);
		UpdateViewMode(dt);
		UpdateDoor(dt);
		UpdateLift(dt);
		UpdateLift(dt);
		UpdateTravel(dt);

		if(Application::IsKeyPressed('Q')) {
			debug = true;
		}
		if(Application::IsKeyPressed('E')) {
			debug = false;
		}
		/*-------------------------------------------------!! UPDATE NEEDED (WEI HENG) !!----------------------------------------------------*/

	if(transarrowY <0)
	{
		transarrowY=10;
	}
	
		if (gameStart == true && gameEnd == false) {
			if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,4,28))
			{
				if (render1 == true)
					coin = true;

				render1 = false;


			}

			if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,2,29))
			{
				if (render2 == true)
					coin = true;

				render2 = false;
			}

			if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,3,4))
			{
				if (render3 == true)
					coin = true;

				render3 = false;
			}

			if ( Application::IsKeyPressed('F') && ( Collision(playerCamera.position,ObjectList,4,83) || Collision(playerCamera.position,ObjectList,4,30) ) )
			{
				if (render5 == true)
					coin = true;

				render5 = false;
			}

			if ( Application::IsKeyPressed('F') &&  Collision(playerCamera.position,ObjectList,4,46) )
			{
				if (render6 == true)
					coin = true;
				render6 = false;
			}

			if ( Application::IsKeyPressed('F') &&  Collision(playerCamera.position,ObjectList,4,36) )
			{
				if (render7 == true)
					coin = true;

				render7 = false;
			}

			if ( Application::IsKeyPressed('F') &&  Collision(playerCamera.position,ObjectList,4,84) )
			{
				if (render8 == true)
					coin = true;

				render8 = false;
			}
		}

		if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,5,1) && loop1==false)
		{
			render4 = false;
		}

		if (Application::IsKeyPressed('F') && Collision(playerCamera.position,ObjectList,5,1) && gameStart == true)
		{
			musicStop = true; 
			gameEnd = true;
		}

		if (gameStart == true)
			gameTime += dt;

		//=================================================!! UPDATE NEEDED (ANDY)1/3/15!!===================================================
		if(loop1)
		{
			lights[0].color.Set(1, 0, 0);
			glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
			meshList[GEO_LEFT_L1]->material.kAmbient.Set(1.0f, 0.f, 0.f);
			meshList[GEO_RIGHT_L1]->material.kAmbient.Set(1.0f, 0.f, 0.f);
			meshList[GEO_BOTTOM_L1]->material.kAmbient.Set(1.0f, 0.f, 0.f);
			meshList[GEO_FRONT_L1]->material.kAmbient.Set(1.0f, 0.f, 0.f);
			meshList[GEO_BACK_L1]->material.kAmbient.Set(1.0f, 0.f, 0.f);
			meshList[GEO_CEILING]->material.kAmbient.Set(1.0f, 0.f, 0.f);

		}
		if (loop2)
		{
			lights[0].color.Set(1, 1, 1);
			glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
			meshList[GEO_LEFT_L1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
			meshList[GEO_RIGHT_L1]->material.kAmbient.Set(0.10f, 0.1f, 0.1f);
			meshList[GEO_BOTTOM_L1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
			meshList[GEO_FRONT_L1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
			meshList[GEO_BACK_L1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
			meshList[GEO_CEILING]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
		}


		if (Application::IsKeyPressed('F') && (playerCamera.position.x >= 350 &&((playerCamera.position.z >= -150)&&(playerCamera.position.z <= -130))&&(playerCamera.position.y <= 50)) && (musicAlarm == false)&&(buttonPress3 ==false))
		{
			lightson = false;
			lightsoff = false;
			musicStop = false; 
 			musicAlarm = true; 
			buttonPress3 = true;
			startfire = true;
		}
		if(buttonPress3 == true)
		{

			if (waitTime3 < 1500)
				waitTime3++;
			else{
				musicStop = true;
				loop1 = false;
				loop2 = true;
			}
		}


		//=================================================!! UPDATE NEEDED (ANDY)1/3/15!!===================================================





	if (Application::IsKeyPressed('F') && (playerCamera.position.x >= 350 && playerCamera.position.x <= 400 && ((playerCamera.position.z >= -150)&&(playerCamera.position.z <= -130))&&(playerCamera.position.y <= 50)) && (musicAlarm == false)&&(buttonPress3 ==false))
	{
		lightson = false;
		lightsoff = false;
		musicStop = false; 
 		musicAlarm = true; 
		buttonPress3 = true;
		startfire = true;
		
	}
	if(buttonPress3 == true)
	{
		
		if (waitTime3 < 1500){
			
			timerez++;
			if(timerez %8 != 0)
			{
				loop2= false;
				loop1 = true;
			}
			if(timerez %8 == 0)
			{
				loop2= true;
				loop1 = false;
			}
			waitTime3++;
		}
		else{
			musicStop = true;
			loop1 = false;
			loop2 = true;
			endfire = true;
		}
		
	}

	//=================================================!! UPDATE NEEDED (ANDY)1/3/15!!===================================================
	if(lightson)
	{
		lights[0].power = 0.8;
		glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
		glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
		meshList[GEO_LEFT_L1]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_RIGHT_L1]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_BOTTOM_L1]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_FRONT_L1]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_BACK_L1]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_CEILING]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		meshList[GEO_LEFT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
		meshList[GEO_RIGHT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
		meshList[GEO_TOP2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
		meshList[GEO_FRONT2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
		meshList[GEO_BACK2]->material.kAmbient.Set(0.5f, 0.5f, 0.5f);
		
	}
	if(lightsoff)
	{
		lights[0].power = 0.1;
		glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
		meshList[GEO_LEFT_L1]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_RIGHT_L1]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_BOTTOM_L1]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_FRONT_L1]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_BACK_L1]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_CEILING]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_LEFT2]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_RIGHT2]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_TOP2]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_FRONT2]->material.kAmbient.Set(0.0f, 0.f, 0.f);
		meshList[GEO_BACK2]->material.kAmbient.Set(0.0f, 0.f, 0.f);
	}//switchlights
	if(Application::IsKeyPressed('F') && playerCamera.position.z >20 && playerCamera.position.z <40 && playerCamera.position.x <-370 && lightson == true)
	{
		lightson = false;
		lightsoff = true;
		Sleep(100);
	}
	if(Application::IsKeyPressed('F') && playerCamera.position.z >20 && playerCamera.position.z <40 && playerCamera.position.x <-370 && lightson == false)
	{
		lightsoff = false;
		lightson = true;
		Sleep(100);
	}
	//scenerio3
	if(game3 == true)
	{
	if ((playerCamera.position.x<=545 && playerCamera.position.x>=525) && (playerCamera.position.z<=262 && playerCamera.position.z>=245) && (renderscenerio3== true)&& (startgame == true))
	{
		renderscenerio3text = false;
	}
	else
	{
		renderscenerio3text = true;
	}
	if (renderscenerio3text == false && Application::IsKeyPressed('F'))
	{
		renderscenerio3 = false;

	}
	if(renderscenerio3 == false && Application::IsKeyPressed('E'))
	{
		startgame = false;
		renderscenerio3 = true;
		Mission2 == true;
		RenderMission2();
	}
	if(startgame == false)
	{
		timer += dt;
	if(timer<=20)
	{
		place1 = false;
	}
	else
	{
		place1 = true;
	}
	if(timer<=40 && timer>=20)
	{
		place2 = false;
	}
	else
	{
		place2 = true;
	}
	if(timer<=60 && timer>=40)
	{
		place3 = false;
	}
	else
	{
		place3 = true;
	}
	if(timer<=80 && timer>=60)
	{
		place4 = false;
	}
	else
	{
		place4 = true;
	}
	if(timer<=100 && timer>=80)
	{
		place5 = false;
	}
	else
	{
		place5 = true;
	}
	if(timer >=10 && timer < 10.1)
	{
		gameover = false;

		musicStop2= true;

		if(musicStop2 == true){ 
			engine4->stopAllSounds();
			engine4->play2D("../irrKlang/media/fail.wav",false); 
			engine->setAllSoundsPaused(false);
			musicStop2 = false; 
		} 
	}
	
	if(timer>13)
	{
		gameover = true;
	}
	//place1
	if((playerCamera.position.x<=352 && playerCamera.position.x>=332) && (playerCamera.position.z<=-272 && playerCamera.position.z>=-292)&& timer<=20)
	{
		caught = false;	 
	}
	//place2
	else if((playerCamera.position.x<=-45 && playerCamera.position.x>=-65) && (playerCamera.position.z<=428 && playerCamera.position.z>=408)&&(timer<=40 && timer>=20))
	{
		caught = false;
	}
	//place3
	else if((playerCamera.position.x<=-20 && playerCamera.position.x>=-40) && (playerCamera.position.z<=292 && playerCamera.position.z>=272)&&(timer<=60 && timer>=40))
	{
		caught = false;
	}
	//place4
	else if((playerCamera.position.x<=-766 && playerCamera.position.x>=-746) && (playerCamera.position.z<=203 && playerCamera.position.z>=183)&&(timer<=80 && timer>=60))
	{
		caught = false;
	}
	//place5
	else if((playerCamera.position.x<=-35 && playerCamera.position.x>=-15) && (playerCamera.position.z<=169 && playerCamera.position.z>=149)&&(timer<=100 && timer>=80))
	{
		caught = false;
	}
	else
	{
		caught = true;
	}
	if(caught == false && Application::IsKeyPressed('F'))
	{
		congrat = false;
		caught = true;
		startgame = true;
	}
	
	}
	if(congrat == false && Application::IsKeyPressed('E')&& buttonPress4 == false)
	{
		game3 = false;

		musicStop2= true;

		if(musicStop2 == true){ 
			engine4->stopAllSounds();
			engine4->play2D("../irrKlang/media/win.wav",false); 
			engine->setAllSoundsPaused(false);
			musicStop2 = false; 
		} 
		congrat = true;
	}
}
	engine->setListenerPosition(vec3df(playerCamera.position.x,playerCamera.position.y,playerCamera.position.z),vec3df(0,0,0),vec3df(playerCamera.up.x,playerCamera.up.y,playerCamera.up.z));


		//go out of carpark
		if (car1.translateZ < 150)
		{
			car1.rotateAngle = 0;
		}
		if (car1.translateZ > 150)
		{
			car1.rotateAngle -= (float)100*dt;
			car1.translateZ = 150;

			if(car1.rotateAngle < -90)
			{
				car1.rotateAngle = -90;
			}
			if(car1.rotateAngle == -90)
			{
				car1.translateX -= (float)300*dt;
			}
		}
		if(car1.translateX <= -2000)
		{
			car1.translateX = 2000;
			car1.translateX += (float)300*dt;

			if(car1.translateX <= 0)
			{
				car1.translateX = 0;
			}
		}

		//test test
		if (car2.translateX > 3600)
		{
			car2.translateX = -3600;
		}
		if (-car4.translateX < -3600)
		{
			car4.translateX = -3600;
		}
		if (truck1.translateX > 3600)
		{
			truck1.translateX = -3600;
		}
		if (-bus1.translateX < -3600)
		{
			bus1.translateX = -3600;
		}
	}

	else {
		double midScreenX = (Application::returnWindowSize(true)/2);
		double midScreenY = (Application::returnWindowSize(false)/2);
		Application::SetMouseinput(midScreenX, midScreenY);
	}
	
	
	//static ai 1 work
	if ((playerCamera.position.x<= 270 && playerCamera.position.x>=160) && (playerCamera.position.z<= -160 && playerCamera.position.z>= -190 ) && playerCamera.position.y >= 179 && renderai1text_2==false)
	{
		renderai1text = true;
	}
	else
	{
		renderai1text = false;
	}
	if (renderai1text == true && Application::IsKeyPressed('F'))
	{
		renderai1text_2 = true;
		start1 = true;
		engine5->play2D("../irrKlang/media/pinky.wav",false); 
		Sleep(100);

	}
	
	if(start1 == true)
	{
		aitimer1 += dt;
		
		if(aitimer1 >= 2)
		{
			renderai1text_2 = false;
			renderai1text = false;
			start1 = false;
			aitimer1 = 0;
		}
	}

	//static ai 2 work
	if ((playerCamera.position.x<= 20 && playerCamera.position.x>=-80) && (playerCamera.position.z<= 75 && playerCamera.position.z>= 35 ) && playerCamera.position.y >= 180 && renderai2text_2==false)
	{
		renderai2text = true;
	}
	else
	{
		renderai2text = false;
	}
	if (renderai2text == true && Application::IsKeyPressed('F'))
	{
		renderai2text_2 = true;
		start2 = true;
		engine5->play2D("../irrKlang/media/red.wav",false); 
		Sleep(100);
	}
	
	if(start2 == true)
	{
		aitimer2 += dt;
		
		if(aitimer2 >= 2)
		{
			renderai2text_2 = false;
			renderai2text = false;
			start2 = false;
			aitimer2 = 0;
		}
	}

	//static ai 3 work
	if ((playerCamera.position.x<= 280 && playerCamera.position.x>= 230) && (playerCamera.position.z<= 150 && playerCamera.position.z>= 90 ) && (playerCamera.position.y >= 29 && playerCamera.position.y < 178) && renderai3text_2==false)
	{
		renderai3text = true;
	}
	else
	{
		renderai3text = false;
	}
	if (renderai3text == true && Application::IsKeyPressed('F'))
	{
		renderai3text_2 = true;
		start3 = true;
		engine5->play2D("../irrKlang/media/yellow.wav",false); 
		Sleep(100);
	}
	
	if(start3 == true)
	{
		aitimer3 += dt;
		
		if(aitimer3 >= 2)
		{
			renderai3text_2 = false;
			renderai3text = false;
			aitimer3 = 0;
			start3 = false;
		}
	}
	//arrow animation on top of game master head
	
}
/******************************************************************************/
/*!
\brief
Render out lightings on all of our materials
/******************************************************************************/
void SceneAssignment::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	if(enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render(); //this line should only be called once 
	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
/******************************************************************************/
/*!
\brief
Render the walls and doors for level 1
/******************************************************************************/
void SceneAssignment::RenderLevel1()
{
	//ExitLeft
	modelStack.PushMatrix();
	modelStack.Translate(DX, 53, 324.5);
	modelStack.Scale(70, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();

	//ExitRight
	modelStack.PushMatrix();
	modelStack.Translate(DX2, 53, 324.5);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(70, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//entrance right
	modelStack.PushMatrix();
	modelStack.Translate(D2X2, 53, 325.5);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(74, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//entranceleft
	modelStack.PushMatrix();
	modelStack.Translate(D2X, 53, 325.5);
	modelStack.Scale(74, 105, 0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//Level 1 Skybox
	int temp = GEO_BOTTOM_L1;
	for (int i = 0; i < Skybox1.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Skybox1.translateVal[i].x,Skybox1.translateVal[i].y,Skybox1.translateVal[i].z);
		modelStack.Rotate(Skybox1.rotateVal[i],Skybox1.rotateAxis[i].x,Skybox1.rotateAxis[i].y,Skybox1.rotateAxis[i].z);
		modelStack.Scale(Skybox1.scaleVal[i].x, Skybox1.scaleVal[i].y, Skybox1.scaleVal[i].z);
		RenderMesh(meshList[temp], true);
		modelStack.PopMatrix();
		temp++;
	}
	//=============================================================RenderDoor=============================Credit:Andy===========================================

	modelStack.PushMatrix();
	modelStack.Translate(-260,transarrowY+30,227);
	modelStack.Scale(25, 30, 25);
	RenderMesh(meshList[GEO_ARROW], false);
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render out the walls and doors for level 2
/******************************************************************************/
void SceneAssignment::RenderLevel2()
{
	//Level 2 Skybox
	int temp = GEO_TOP2;
	for (int i = 0; i < Skybox2.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Skybox2.translateVal[i].x,Skybox2.translateVal[i].y,Skybox2.translateVal[i].z);
		modelStack.Rotate(Skybox2.rotateVal[i],Skybox2.rotateAxis[i].x,Skybox2.rotateAxis[i].y,Skybox2.rotateAxis[i].z);
		modelStack.Scale(Skybox2.scaleVal[i].x, Skybox2.scaleVal[i].y, Skybox2.scaleVal[i].z);
		RenderMesh(meshList[temp], true);
		modelStack.PopMatrix();
		temp++;
	}

	for (int i = 0; i < Barrier.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Barrier.translateVal[i].x,Barrier.translateVal[i].y,Barrier.translateVal[i].z);
		modelStack.Rotate(Barrier.rotateVal[i],Barrier.rotateAxis[i].x,Barrier.rotateAxis[i].y,Barrier.rotateAxis[i].z);
		modelStack.Scale(Barrier.scaleVal[i].x, Barrier.scaleVal[i].y, Barrier.scaleVal[i].z);
		RenderMesh(meshList[GEO_BARRIER], true);
		modelStack.PopMatrix();
	}
	modelStack.PushMatrix();
	modelStack.Translate(-225,148,-500);
	modelStack.Scale(130, 10, 109);
	RenderMesh(meshList[GEO_CEILING], true);
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render out all the large objects such as the shelves and cashier for both levels
/******************************************************************************/
void SceneAssignment::RenderLargeObjects()
{

	//basket for fruits and vegetables
	for (int i = 0; i < Basket.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Basket.translateVal[i].x,Basket.translateVal[i].y,Basket.translateVal[i].z);
		modelStack.Rotate(Basket.rotateVal[i],Basket.rotateAxis[i].x,Basket.rotateAxis[i].y,Basket.rotateAxis[i].z);
		modelStack.Scale(Basket.scaleVal[i].x, Basket.scaleVal[i].y, Basket.scaleVal[i].z);
		RenderMesh(meshList[GEO_BASKET], true);
		modelStack.PopMatrix();
	}

	//cooler
	for (int i = 0; i < Cooler.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Cooler.translateVal[i].x,Cooler.translateVal[i].y,Cooler.translateVal[i].z);
		modelStack.Scale(Cooler.scaleVal[i].x, Cooler.scaleVal[i].y, Cooler.scaleVal[i].z);
		RenderMesh(meshList[GEO_COOLER], true);
		modelStack.PopMatrix();
	}

	//Shelf
	for (int i = 0; i < Shelf.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Shelf.translateVal[i].x,Shelf.translateVal[i].y,Shelf.translateVal[i].z);
		modelStack.Scale(Shelf.scaleVal[i].x, Shelf.scaleVal[i].y, Shelf.scaleVal[i].z);
		RenderMesh(meshList[GEO_SHELF], true);
		modelStack.PopMatrix();
	}

	int temp2 = GEO_TRAVELATORUP;
	for (int i = 0; i < Travellator.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Travellator.translateVal[i].x,Travellator.translateVal[i].y,Travellator.translateVal[i].z);
		modelStack.Rotate(Travellator.rotateVal[i],Travellator.rotateAxis[i].x,Travellator.rotateAxis[i].y,Travellator.rotateAxis[i].z);
		modelStack.Scale(Travellator.scaleVal[i].x, Travellator.scaleVal[i].y, Travellator.scaleVal[i].z);
		RenderMesh(meshList[temp2], true);
		modelStack.PopMatrix();
		temp2++;
	}

	//4 cash register
	for (int i = 0; i < Register.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(Register.translateVal[i].x,Register.translateVal[i].y,Register.translateVal[i].z);
		modelStack.Scale(Register.scaleVal[i].x,Register.scaleVal[i].y,Register.scaleVal[i].z);
		RenderMesh(meshList[GEO_REGISTER], true);
		modelStack.PopMatrix();
	}
}
/******************************************************************************/
/*!
\brief
Render the cereal boxes at the right column of level 2
/******************************************************************************/
void SceneAssignment::RenderRightColumn()
{
	//right/last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -117);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -17);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 83);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 183);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/6 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 283);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 141, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/6 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 153, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//right/6 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num+160, 165, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}

}
/******************************************************************************/
/*!
\brief
Render the cereal boxes at the leftr column of level 2
/******************************************************************************/
void SceneAssignment::RenderLeftColumn()
{
	//left/last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -217);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -221);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -224);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -117);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -117);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -121);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -124);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -17);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -17);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -21);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, -24);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 83);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 83);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 79);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 76);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 183);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 183);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 179);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 176);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/6 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 283);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 141, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/6 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 153, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	//left/6 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 283);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 279);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 30; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(4.5*num-340, 165, 276);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_BOX1], true);
		modelStack.PopMatrix();
	}

}
/******************************************************************************/
/*!
\brief
Render the cereal boxes at the middle column of level 2
/******************************************************************************/
void SceneAssignment::RenderMiddleColumn()
{
	//middle/ 2 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -97);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/2 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, -97);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/2 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, -97);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, -102);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/ 3 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 3);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/3 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, 3);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/3 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, 3);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, -2);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 103);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, 103);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/4 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, 103);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, 98);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/bottom row//////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 203);//-217
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 154, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/middle row///////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, 203);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 167, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	//middle/5 last from back/top row////////////////////////////////////////////////
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, 203);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
	for(int num = 0; num < 40; num++)
	{
		modelStack.PushMatrix();
		//modelStack.Rotate(90, 0, 1, 0);
		modelStack.Translate(5*num-105, 179, 198);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CAN1], true);
		modelStack.PopMatrix();
	}
}
/******************************************************************************/
/*!
\brief
Render the fruits and ice cream at level 1
/******************************************************************************/
void SceneAssignment::RenderSmallObjects()
{
	//left column
	//apples on one basket..
	for(int numA = 0; numA < 36; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 12)
		{
			modelStack.Translate(-390, 20, -190 + (-5*numA));
		}
		if(numA >= 12 && numA < 24)
		{
			modelStack.Translate(-385, 18, -130 + (-5*numA));
		}
		if(numA >= 24 && numA < 36)
		{
			modelStack.Translate(-380, 16, -70 + (-5*numA));
		}
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_APPLE], true);
		modelStack.PopMatrix();
	}

	//cabbages
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-390, 20, -95 + (-7*numA));
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-385, 18, -32 + (-7*numA));
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(-380, 16, 31 + (-7*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_CABBAGE], true);
		modelStack.PopMatrix();
	}

	//oranges
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-390, 20, (-7*numA));
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-385, 18, 65 + (-7*numA));
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(-380, 16, 125 + (-7*numA));
		}
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_ORANGE], true);
		modelStack.PopMatrix();
	}

	//watermelon
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(-390, 20, 90 + (-5*numA));
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(-385, 18, 140 + (-5*numA));
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(-380, 16, 190 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_WATERMELON], true);
		modelStack.PopMatrix();
	}
	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(-390, 20, 190 + (-5*numA));
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(-385, 18, 240 + (-5*numA));
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(-380, 16, 290 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], true);
		modelStack.PopMatrix();
	}

	//middle column
	//apples on one basket..
	for(int numA = 0; numA < 36; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 12)
		{
			modelStack.Translate(-195 + (-5*numA), 18, -310);
		}
		if(numA >= 12 && numA < 24)
		{
			modelStack.Translate(-135 + (-5*numA), 16, -305);
		}
		if(numA >= 24 && numA < 36)
		{
			modelStack.Translate(-75 + (-5*numA), 14, -300);
		}
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_APPLE], true);
		modelStack.PopMatrix();
	}

	//cabbages
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();

		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate(-100 + (-7*numA), 20, -310);
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(-37 + (-7*numA), 18, -305);
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(26 + (-7*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_CABBAGE], true);
		modelStack.PopMatrix();
	}
	//oranges
	for(int numA = 0; numA < 27; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 9)
		{
			modelStack.Translate( -5 +(-7*numA), 20, -310);
		}
		if(numA >= 9 && numA < 18)
		{
			modelStack.Translate(60 +(-7*numA), 18, -305);
		}
		if(numA >= 18 && numA < 27)
		{
			modelStack.Translate(120 + (-7*numA), 16, -300);
		}
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_ORANGE], true);
		modelStack.PopMatrix();
	}

	//watermelon
	for(int numA = 0; numA < 24; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 8)
		{
			modelStack.Translate(90 + (-7*numA), 20, -310);
		}
		if(numA >= 8 && numA < 16)
		{
			modelStack.Translate(145 + (-7*numA), 18, -305);
		}
		if(numA >= 16 && numA < 24)
		{
			modelStack.Translate(200 + (-7*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_WATERMELON], true);
		modelStack.PopMatrix();
	}

	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(180 + (-5*numA), 20, -310);
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(230 + (-5*numA), 18, -305);
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(280 + (-5*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], true);
		modelStack.PopMatrix();
	}

	//coconut
	for(int numA = 0; numA < 30; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 10)
		{
			modelStack.Translate(280 + (-5*numA), 20, -310);
		}
		if(numA >= 10 && numA < 20)
		{
			modelStack.Translate(330 + (-5*numA), 18, -305);
		}
		if(numA >= 20 && numA < 30)
		{
			modelStack.Translate(380 + (-5*numA), 16, -300);
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_COCONUT], true);
		modelStack.PopMatrix();
	}

	//lodin packet
	for(int numA = 0; numA < 120; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 30)
		{
			modelStack.Translate(165 + (4*numA), 15, -225);
		}
		if(numA >= 30 && numA < 60)
		{
			modelStack.Translate(50 + (4*numA), 15, -220);
		}
		if(numA >= 60 && numA < 90)
		{
			modelStack.Translate(-60 + (4*numA), 3, -225);
		}
		if(numA >= 90 && numA < 120)
		{
			modelStack.Translate(-180 + (4*numA), 3, -220);
		}
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_LODIN], true);
		modelStack.PopMatrix();
	}
	//lodin packet
	for(int numA = 0; numA < 120; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 30)
		{
			modelStack.Translate(-270 + (4*numA), 15, -225);
		}
		if(numA >= 30 && numA < 60)
		{
			modelStack.Translate(-400 + (4*numA), 15, -220);
		}
		if(numA >= 60 && numA < 90)
		{
			modelStack.Translate(-510 + (4*numA), 3, -225);
		}
		if(numA >= 90 && numA < 120)
		{
			modelStack.Translate(-630 + (4*numA), 3, -220);
		}
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(6, 6, 6);
		RenderMesh(meshList[GEO_LODIN], true);
		modelStack.PopMatrix();
	}	

	//ice cream
	for(int numA = 0; numA < 40; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 20)
		{
			modelStack.Translate(-200, 15, 47 + (-5*numA));	
		}
		if(numA >= 20 && numA < 40)
		{
			modelStack.Translate(-200, 15, 260 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_ICECREAM], true);
		modelStack.PopMatrix();
	}

	//ice cream
	for(int numA = 0; numA < 40; numA++)
	{
		modelStack.PushMatrix();
		if(numA >= 0 && numA < 20)
		{
			modelStack.Translate(200, 15, 47 + (-5*numA));	
		}
		if(numA >= 20 && numA < 40)
		{
			modelStack.Translate(200, 15, 260 + (-5*numA));
		}
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_ICECREAM], true);
		modelStack.PopMatrix();
	}

}
/******************************************************************************/
/*!
\brief
Render the exterior skyboxes,moutains and houses outside of the supermarket
/******************************************************************************/
void SceneAssignment::RenderOut_Skybox()
{
	modelStack.PushMatrix();
	modelStack.Translate(0, 0, -2650);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Scale(5320, 5320, 5320);
	RenderMesh(skyboxList[SKYBOX_FRONT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0,0,2650);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(180, 0, 1, 0);
	modelStack.Scale(5320, 5320, 5320);
	RenderMesh(skyboxList[SKYBOX_BACK], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-2650, 0, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(5320, 5320, 5320);
	RenderMesh(skyboxList[SKYBOX_RIGHT], false);
	modelStack.PopMatrix();


	modelStack.PushMatrix();
	modelStack.Translate(2650,0, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(5320, 5320, 5320);
	RenderMesh(skyboxList[SKYBOX_LEFT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 2650, 0);
	modelStack.Translate(playerCamera.position.x, 0, playerCamera.position.z);;
	modelStack.Rotate(90, 1, 0, 0);
	modelStack.Rotate(-90, 0, 0, 1);
	modelStack.Scale(5320, 5320, 5320);
	RenderMesh(skyboxList[SKYBOX_UP], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Rotate(90, 0, 0, 1);
	modelStack.Scale(4100, 4100, 4100);
	RenderMesh(skyboxList[SKYBOX_DOWN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 210, 329);
	modelStack.Scale(1015, 205, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTEBANNER], false);
	modelStack.PopMatrix();
	//left side
	modelStack.PushMatrix();
	modelStack.Translate(-507, 122, 0);
	modelStack.Rotate(90, 0, 1,0 );
	modelStack.Scale(658, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//ride side
	modelStack.PushMatrix();
	modelStack.Translate(507, 122, 0);
	modelStack.Rotate(90, 0, 1,0 );
	modelStack.Scale(658, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//back
	modelStack.PushMatrix();
	modelStack.Translate(0, 122, -329);
	modelStack.Scale(1015, 380, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//small right
	modelStack.PushMatrix();
	modelStack.Translate(452.8, 0, 327);
	modelStack.Scale(108, 260, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();
	//small left
	modelStack.PushMatrix();
	modelStack.Translate(-452.8, 0, 327);
	modelStack.Scale(108, 260, 1000);
	RenderMesh(skyboxList[SKYBOX_EXTESIDE], false);
	modelStack.PopMatrix();

	//houses
	for (int i = 0; i < House.getTotal(); ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(House.translateVal[i].x,House.translateVal[i].y,House.translateVal[i].z);
		modelStack.Rotate(House.rotateVal[i],House.rotateAxis[i].x,House.rotateAxis[i].y,House.rotateAxis[i].z);
		modelStack.Scale(House.scaleVal[i].x, House.scaleVal[i].y, House.scaleVal[i].z);
		RenderMesh(meshList[GEO_BUILDING], false);
		modelStack.PopMatrix();
	}

	//scenerio 3
	modelStack.PushMatrix();
	modelStack.Translate(536,0,210);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(5,5,5);
	RenderMesh(meshList[GEO_PINKAI], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-600,-1850,-400);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(1200,1300,1200);
	RenderMesh(meshList[GEO_MOUTAIN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-6000,-1850,-400);
	modelStack.Rotate(180,0,1,0);
	modelStack.Scale(1200,1300,1200);
	RenderMesh(meshList[GEO_MOUTAIN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(590,transarrowY+10,195);
	modelStack.Scale(25, 30, 25);
	RenderMesh(meshList[GEO_ARROW], false);
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render static NPCs at the cash register
/******************************************************************************/
void SceneAssignment::RenderChar()
{
	//cashier
	for(int num = 0; num < 4; num++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(70*num-312,0,240);
		modelStack.Rotate(-90, 0, 1, 0);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_CASHIER], false);
		modelStack.PopMatrix();
	}
}
/******************************************************************************/
/*!
\brief
Render the moving pink NPC 
/******************************************************************************/
void SceneAssignment::RenderModelPink()
{
	modelStack.PushMatrix(); 

	if (buttonPress3 == true && endfire == true) {
		if (pinkCheck[45]==false) pinkCheck[46]= AImoveZ(modelStack,pinkMove[45],-290);
		if (pinkCheck[44]==false) pinkCheck[45]= AIrotate(modelStack,Vector3(-660,0,500),pinkMove[44],'y',-90);
		if (pinkCheck[43]==false) pinkCheck[44]= AImoveX(modelStack,pinkMove[43],-732);
		pinkCheck[42] = pinkCheck[43]=AIrotate(modelStack,Vector3(90,0,500),pinkMove[42],'y',90);
	}

	if (buttonPress3 == false)
		if (pinkCheck[41] == false) for(int i=0;i<pinkSize;++i) {pinkCheck[i] = true; pinkMove[i] = 0;}

	if (pinkCheck[40]==false) pinkCheck[41]= AIrotate(modelStack,Vector3(90,0,500),pinkMove[41],'y',90,speedAI*2);
	if (pinkCheck[39]==false) pinkCheck[40]= AImoveX(modelStack,pinkMove[40],200,speedAI);
	if (pinkCheck[38]==false) pinkCheck[39]= AIrotate(modelStack,Vector3(-110,0,500),pinkMove[39],'y',90,speedAI*2);
	if (pinkCheck[37]==false) pinkCheck[38]= AImoveZ(modelStack,pinkMove[38],215,speedAI);
	if (pinkCheck[36]==false) pinkCheck[37]= AIrotate(modelStack,Vector3(-110,0,285),pinkMove[37],'y',90,speedAI*2);
	if (pinkCheck[35]==false) pinkCheck[36]= AImoveX(modelStack,pinkMove[36],-110,speedAI);
	if (pinkCheck[34]==false) pinkCheck[35]= AIrotate(modelStack,Vector3(0,0,285),pinkMove[35],'y',-90,speedAI*2);
	if (pinkCheck[33]==false) pinkCheck[34]= AImoveZ(modelStack,pinkMove[34],385,speedAI);
	if (pinkCheck[32]==false) pinkCheck[33]= AIrotate(modelStack,Vector3(0,0,-100),pinkMove[33],'y',-90,speedAI*2);
	if (pinkCheck[31]==false) pinkCheck[32]= AImoveX(modelStack,pinkMove[32],250,speedAI);
	if (pinkCheck[30]==false) pinkCheck[31]= AIrotate(modelStack,Vector3(-250,0,-100),pinkMove[31],'y',-90,speedAI*2);
	if (pinkCheck[29]==false) pinkCheck[30]= AImoveZ(modelStack,pinkMove[30],-75,speedAI);
	if (pinkCheck[28]==false) pinkCheck[29]= AIrotate(modelStack,Vector3(-250,0,-25),pinkMove[29],'y',90,speedAI*2);
	if (pinkCheck[27]==false) pinkCheck[28]= AImoveX(modelStack,pinkMove[28],100,speedAI);
	if (pinkCheck[26]==false) pinkCheck[27]= AIrotate(modelStack,Vector3(-350,0,-25),pinkMove[27],'y',180,speedAI*2);
	if (pinkCheck[25]==false) pinkCheck[26]= AIstop(pinkMove[26],80,speedAI);
	if (pinkCheck[24]==false) pinkCheck[25]= AIrotate(modelStack,Vector3(-350,0,-25),pinkMove[25],'y',-90,speedAI*2);
	if (pinkCheck[23]==false) pinkCheck[24]= AImoveZ(modelStack,pinkMove[24],100,speedAI);
	if (pinkCheck[22]==false) pinkCheck[23]= AIrotate(modelStack,Vector3(-350,0,-125),pinkMove[23],'y',90,speedAI*2);
	if (pinkCheck[21]==false) pinkCheck[22]= AIstop(pinkMove[22],80,speedAI);
	if (pinkCheck[20]==false) pinkCheck[21]= AIrotate(modelStack,Vector3(-350,0,-125),pinkMove[21],'y',-90,speedAI*2);
	if (pinkCheck[19]==false) pinkCheck[20]= AImoveZ(modelStack,pinkMove[20],100,speedAI);
	if (pinkCheck[18]==false) pinkCheck[19]= AIrotate(modelStack,Vector3(-350,0,-225),pinkMove[19],'y',90,speedAI*2);
	if (pinkCheck[17]==false) pinkCheck[18]= AIstop(pinkMove[18],80,speedAI);
	if (pinkCheck[16]==false) pinkCheck[17]= AIrotate(modelStack,Vector3(-350,0,-225),pinkMove[17],'y',-90,speedAI*2);
	if (pinkCheck[15]==false) pinkCheck[16]= AImoveZ(modelStack,pinkMove[16],50,speedAI);
	if (pinkCheck[14]==false) pinkCheck[15]= AIrotate(modelStack,Vector3(-350,0,-275),pinkMove[15],'y',90,speedAI*2);
	if (pinkCheck[13]==false) pinkCheck[14]= AImoveX(modelStack,pinkMove[14],-140,speedAI);
	if (pinkCheck[12]==false) pinkCheck[13]= AIrotate(modelStack,Vector3(-210,0,-275),pinkMove[13],'y',90,speedAI*2);
	if (pinkCheck[11]==false) pinkCheck[12]= AIstop(pinkMove[12],80,speedAI);
	if (pinkCheck[10]==false) pinkCheck[11]= AIrotate(modelStack,Vector3(-210,0,-275),pinkMove[11],'y',-90,speedAI*2);
	if (pinkCheck[9]==false) pinkCheck[10]= AImoveX(modelStack,pinkMove[10],-90,speedAI);
	if (pinkCheck[8]==false) pinkCheck[9]= AIrotate(modelStack,Vector3(-120,0,-275),pinkMove[9],'y',90,speedAI*2);
	if (pinkCheck[7]==false) pinkCheck[8]= AIstop(pinkMove[8],80,speedAI);
	if (pinkCheck[6]==false) pinkCheck[7]= AIrotate(modelStack,Vector3(-120,0,-275),pinkMove[7],'y',-90,speedAI*2);
	if (pinkCheck[5]==false) pinkCheck[6]= AImoveX(modelStack,pinkMove[6],-90,speedAI);
	if (pinkCheck[4]==false) pinkCheck[5]= AIrotate(modelStack,Vector3(-30,0,-275),pinkMove[5],'y',90,speedAI*2);
	if (pinkCheck[3]==false) pinkCheck[4]= AIstop(pinkMove[4],80,speedAI);
	if (pinkCheck[2]==false) pinkCheck[3]= AIrotate(modelStack,Vector3(-30,0,-275),pinkMove[3],'y',-90,speedAI*2);
	if (pinkCheck[1]==false) pinkCheck[2]= AImoveX(modelStack,pinkMove[2],-120,speedAI);
	if (pinkCheck[0]==false) pinkCheck[1]= AIrotate(modelStack,Vector3(90,0,-275),pinkMove[1],'y',90,speedAI*2); 
	    pinkCheck[0] = AImoveZ(modelStack,pinkMove[0],-775,speedAI);

	modelStack.Translate(modelPink.translateVal[0].x,modelPink.translateVal[0].y,modelPink.translateVal[0].z);
	modelStack.Rotate(modelPink.rotateVal[0],modelPink.rotateAxis[0].x,modelPink.rotateAxis[0].y,modelPink.rotateAxis[0].z);
	modelStack.Scale(modelPink.scaleVal[0].x,modelPink.scaleVal[0].y,modelPink.scaleVal[0].z);
	RenderMesh(modelList7[MODEL_BODY_PINK], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_LEFTARM_PINK], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList7[MODEL_LEFTFIST_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHTARM_PINK], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHTFIST_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_LEFT_LEG_UPPER_PINK], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList7[MODEL_LEFT_LEG_LOWER_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList7[MODEL_RIGHT_LEG_UPPER_PINK], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList7[MODEL_RIGHT_LEG_LOWER_PINK], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render the moving blue NPC 
/******************************************************************************/
void SceneAssignment::RenderModelBlue()
{
	modelStack.PushMatrix();

	if (buttonPress3 == true && endfire == true) {
		if (blueCheck[26]==false) blueCheck[27]= AImoveZ(modelStack,blueMove[27],-350);
		if (blueCheck[25]==false) blueCheck[26]= AIrotate(modelStack,Vector3(625,0,550),blueMove[26],'y',90); 
		if (blueCheck[24]==false) blueCheck[25]= AImoveX(modelStack,blueMove[25],465);
		if (blueCheck[23]==false) blueCheck[24]= AIrotate(modelStack,Vector3(160,0,550),blueMove[24],'y',-90); 
		blueCheck[23] = AIstop(blueMove[23],80);
	}

	if (buttonPress3 == false)
		if (blueCheck[22] == false) for(int i=0;i<blueSize;++i) {blueCheck[i] = true; blueMove[i] = 0;}

	if (blueCheck[21]==false) blueCheck[22]= AIrotate(modelStack,Vector3(160,0,550),blueMove[22],'y',90,speedAI*2); 
	if (blueCheck[20]==false) blueCheck[21]= AImoveX(modelStack,blueMove[21],290,speedAI*2);
	if (blueCheck[19]==false) blueCheck[20]= AIrotate(modelStack,Vector3(-130,0,550),blueMove[20],'y',90,speedAI*2); 
	if (blueCheck[18]==false) blueCheck[19]= AImoveZ(modelStack,blueMove[19],320,speedAI);
	if (blueCheck[17]==false) blueCheck[18]= AIrotate(modelStack,Vector3(-130,0,230),blueMove[18],'y',90,speedAI*2); 
	if (blueCheck[16]==false) blueCheck[17]= AIstop(blueMove[17],80,speedAI);
	if (blueCheck[15]==false) blueCheck[16]= AIrotate(modelStack,Vector3(-130,0,230),blueMove[16],'y',-90,speedAI*2); 
	if (blueCheck[14]==false) blueCheck[15]= AImoveZ(modelStack,blueMove[15],415,speedAI);
	if (blueCheck[13]==false) blueCheck[14]= AIrotate(modelStack,Vector3(-130,0,-185),blueMove[14],'y',180,speedAI*2); 
	if (blueCheck[12]==false) blueCheck[13]= AIstop(blueMove[13],80,speedAI);
	if (blueCheck[11]==false) blueCheck[12]= AIrotate(modelStack,Vector3(-130,0,-185),blueMove[12],'y',-90,speedAI*2); 
	if (blueCheck[10]==false) blueCheck[11]= AImoveX(modelStack,blueMove[11],-290,speedAI);
	if (blueCheck[9]==false) blueCheck[10]= AIrotate(modelStack,Vector3(160,0,-185),blueMove[10],'y',90,speedAI*2); 
	if (blueCheck[8]==false) blueCheck[9]= AIstop(blueMove[9],80,speedAI);
	if (blueCheck[7]==false) blueCheck[8]= AImoveZ(modelStack,blueMove[8],-190,speedAI);
	if (blueCheck[6]==false) blueCheck[7]= AIrotate(modelStack,Vector3(160,0,5),blueMove[7],'y',90,speedAI*2); 
	if (blueCheck[5]==false) blueCheck[6]= AIstop(blueMove[6],80,speedAI);
	if (blueCheck[4]==false) blueCheck[5]= AIrotate(modelStack,Vector3(160,0,5),blueMove[5],'y',-90,speedAI*2); 
	if (blueCheck[3]==false) blueCheck[4]= AImoveZ(modelStack,blueMove[4],-105,speedAI);
	if (blueCheck[2]==false) blueCheck[3]= AIrotate(modelStack,Vector3(160,0,110),blueMove[3],'y',90,speedAI*2); 
	if (blueCheck[1]==false) blueCheck[2]= AIstop(blueMove[2],80,speedAI);
	if (blueCheck[0]==false) blueCheck[1]= AIrotate(modelStack,Vector3(160,0,110),blueMove[1],'y',-90,speedAI*2); 
	blueCheck[0] = AImoveZ(modelStack,blueMove[0],-440,speedAI);

	modelStack.Translate(modelBlue.translateVal[0].x,modelBlue.translateVal[0].y,modelBlue.translateVal[0].z);
	modelStack.Rotate(modelBlue.rotateVal[0],modelBlue.rotateAxis[0].x,modelBlue.rotateAxis[0].y,modelBlue.rotateAxis[0].z);
	modelStack.Scale(modelBlue.scaleVal[0].x,modelBlue.scaleVal[0].y,modelBlue.scaleVal[0].z);
	RenderMesh(modelList2[MODEL_BODY_BLUE], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_LEFTARM_BLUE], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList2[MODEL_LEFTFIST_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHTARM_BLUE], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHTFIST_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_LEFT_LEG_UPPER_BLUE], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList2[MODEL_LEFT_LEG_LOWER_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList2[MODEL_RIGHT_LEG_UPPER_BLUE], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList2[MODEL_RIGHT_LEG_LOWER_BLUE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render the moving orange NPC 
/******************************************************************************/
void SceneAssignment::RenderModelOrange()
{
	modelStack.PushMatrix();

	if (buttonPress3 == true && endfire == true) {
		if (orangeCheck[27]==false) AImoveZ(modelStack,orangeMove[28],2410);
		if (orangeCheck[26]==false) orangeCheck[27] = AIrotate(modelStack,Vector3(90,0,600),orangeMove[27],'y',-180);
		orangeCheck[26] = AIstop(orangeMove[26],160);
	}

	if (buttonPress3 == false)
		if (orangeCheck[25] == false) for(int i=0;i<orangeSize;++i) {orangeCheck[i] = true; orangeMove[i] = 0;}

	if (orangeCheck[24]==false) orangeCheck[25]= AIrotate(modelStack,Vector3(90,0,600),orangeMove[25],'y',90,speedAI*2);
	if (orangeCheck[23]==false) orangeCheck[24]= AImoveX(modelStack,orangeMove[24],134,speedAI);
	if (orangeCheck[22]==false) orangeCheck[23]= AIrotate(modelStack,Vector3(-44,0,600),orangeMove[23],'y',90,speedAI*2);
	if (orangeCheck[20]==false) orangeCheck[22]= AImoveZ(modelStack,orangeMove[22],480,speedAI);
	if (orangeCheck[19]==false) {
		orangeCheck[20]= AImoveY (modelStack,orangeMove[20],-150,speedAI);
					     AImoveZ (modelStack,orangeMove[21],345,speedAI);
	}
	if (orangeCheck[18]==false) orangeCheck[19]= AImoveZ(modelStack,orangeMove[19],75,speedAI);
	if (orangeCheck[17]==false) orangeCheck[18]= AIrotate(modelStack,Vector3(-44,0,-300),orangeMove[18],'y',-90,speedAI*2);
	if (orangeCheck[16]==false) orangeCheck[17]= AImoveX(modelStack,orangeMove[17],111,speedAI);
	if (orangeCheck[15]==false) orangeCheck[16]= AIrotate(modelStack,Vector3(-155,0,-300),orangeMove[16],'y',-90,speedAI*2);
	if (orangeCheck[14]==false) orangeCheck[15]= AImoveZ(modelStack,orangeMove[15],-230,speedAI);
	if (orangeCheck[13]==false) orangeCheck[14]= AIrotate(modelStack,Vector3(-155,0,-70),orangeMove[14],'y',-90,speedAI*2);
	if (orangeCheck[12]==false) orangeCheck[13]= AImoveX(modelStack,orangeMove[13],-505,speedAI);
	if (orangeCheck[11]==false) orangeCheck[12]= AIrotate(modelStack,Vector3(350,0,-70),orangeMove[12],'y',-90,speedAI*2);
	if (orangeCheck[10]==false) orangeCheck[11]= AImoveZ(modelStack,orangeMove[11],230,speedAI);
	if (orangeCheck[9]==false) orangeCheck[10]= AIrotate(modelStack,Vector3(350,0,-300),orangeMove[10],'y',-90,speedAI*2);
	if (orangeCheck[8]==false) orangeCheck[9]= AImoveX(modelStack,orangeMove[9],315,speedAI);
	if (orangeCheck[7]==false) orangeCheck[8]= AIrotate(modelStack,Vector3(35,0,-300),orangeMove[8],'y',-90,speedAI*2); 
	if (orangeCheck[5]==false) orangeCheck[7]= AImoveZ(modelStack,orangeMove[7],-85,speedAI);
	if (orangeCheck[4]==false) {
		orangeCheck[5]= AImoveY (modelStack,orangeMove[5],150,speedAI);
					    AImoveZ (modelStack,orangeMove[6],-345,speedAI);
	}
	if (orangeCheck[3]==false) orangeCheck[4]= AImoveZ(modelStack,orangeMove[4],-90,speedAI);
	if (orangeCheck[2]==false) orangeCheck[3]= AIrotate(modelStack,Vector3(35,0,220),orangeMove[3],'y',-90,speedAI*2); 
	if (orangeCheck[1]==false) orangeCheck[2]= AImoveX(modelStack,orangeMove[2],-55,speedAI);
	if (orangeCheck[0]==false) orangeCheck[1]= AIrotate(modelStack,Vector3(90,0,220),orangeMove[1],'y',90,speedAI*2); 
	orangeCheck[0] = AImoveZ(modelStack,orangeMove[0],-380,speedAI);
	modelStack.Translate(modelOrange.translateVal[0].x,modelOrange.translateVal[0].y,modelOrange.translateVal[0].z);
	modelStack.Rotate(modelOrange.rotateVal[0],modelOrange.rotateAxis[0].x,modelOrange.rotateAxis[0].y,modelOrange.rotateAxis[0].z);
	modelStack.Scale(modelOrange.scaleVal[0].x,modelOrange.scaleVal[0].y,modelOrange.scaleVal[0].z);
	RenderMesh(modelList6[MODEL_BODY_ORANGE], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_LEFTARM_ORANGE], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList6[MODEL_LEFTFIST_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHTARM_ORANGE], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHTFIST_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_LEFT_LEG_UPPER_ORANGE], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList6[MODEL_LEFT_LEG_LOWER_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList6[MODEL_RIGHT_LEG_UPPER_ORANGE], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList6[MODEL_RIGHT_LEG_LOWER_ORANGE], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render the moving red NPC 
/******************************************************************************/
void SceneAssignment::RenderModelRed()
{
	modelStack.PushMatrix(); 

		if (redCheck[14] == false) for(int i=0;i<redSize;++i) {redCheck[i] = true; redMove[i] = 0;}
		if (redCheck[13]==false) redCheck[14]= AIrotate(modelStack,Vector3(-660,0,220),redMove[14],'y',-180,speedAI*2); 
		if (redCheck[12]==false) redCheck[13]= AImoveZ(modelStack,redMove[13],-205,speedAI);
		if (redCheck[11]==false) redCheck[12]= AIrotate(modelStack,Vector3(-660,0,425),redMove[12],'y',-90,speedAI*2); 
		if (redCheck[10]==false) redCheck[11]= AImoveX(modelStack,redMove[11],-1300,speedAI);
		if (redCheck[9]==false) redCheck[10]= AIrotate(modelStack,Vector3(640,0,425),redMove[10],'y',-90,speedAI*2);  
		if (redCheck[8]==false) redCheck[9]= AImoveZ(modelStack,redMove[9],225,speedAI);
		if (redCheck[7]==false) redCheck[8]= AIrotate(modelStack,Vector3(640,0,200),redMove[8],'y',180,speedAI*2); 
		if (redCheck[6]==false) redCheck[7]= AImoveZ(modelStack,redMove[7],-225,speedAI);
		if (redCheck[5]==false) redCheck[6]= AIrotate(modelStack,Vector3(640,0,425),redMove[6],'y',90,speedAI*2);  
		if (redCheck[4]==false) redCheck[5]= AImoveX(modelStack,redMove[5],1300,speedAI);
		if (redCheck[3]==false) redCheck[4]= AIrotate(modelStack,Vector3(-660,0,425),redMove[4],'y',-180,speedAI*2);  
		if (redCheck[2]==false) redCheck[3]= AIstop(redMove[3],160,speedAI);
		if (redCheck[1]==false) redCheck[2]= AIrotate(modelStack,Vector3(-660,0,425),redMove[2],'y',-90,speedAI*2); 
		if (redCheck[0]==false) redCheck[1]= AImoveZ(modelStack,redMove[1],225,speedAI);
		redCheck[0] = AIstop(redMove[0],1350,speedAI);

	modelStack.Translate(modelRed.translateVal[0].x,modelRed.translateVal[0].y,modelRed.translateVal[0].z);
	modelStack.Rotate(modelRed.rotateVal[0],modelRed.rotateAxis[0].x,modelRed.rotateAxis[0].y,modelRed.rotateAxis[0].z);
	modelStack.Scale(modelRed.scaleVal[0].x,modelRed.scaleVal[0].y,modelRed.scaleVal[0].z);
	RenderMesh(modelList3[MODEL_BODY_RED], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList3[MODEL_LEFTARM_RED], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList3[MODEL_LEFTFIST_RED], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList3[MODEL_RIGHTARM_RED], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList3[MODEL_RIGHTFIST_RED], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList3[MODEL_LEFT_LEG_UPPER_RED], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList3[MODEL_LEFT_LEG_LOWER_RED], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList3[MODEL_RIGHT_LEG_UPPER_RED], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList3[MODEL_RIGHT_LEG_LOWER_RED], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render the moving yellow NPC 
/******************************************************************************/
void SceneAssignment::RenderModelYellow()
{
	modelStack.PushMatrix(); 
		if (redCheck[14] == false) for(int i=0;i<yellowSize;++i) {yellowCheck[i] = true; yellowMove[i] = 0;}
		if (yellowCheck[8]==false) yellowCheck[9]= AIrotate(modelStack,Vector3(640,0,200),yellowMove[9],'y',180,speedAI*2); 
		if (yellowCheck[7]==false) yellowCheck[8]= AImoveZ(modelStack,yellowMove[8],-250,speedAI);
		if (yellowCheck[6]==false) yellowCheck[7]= AIrotate(modelStack,Vector3(640,0,450),yellowMove[7],'y',90,speedAI*2); 
		if (yellowCheck[5]==false) yellowCheck[6]= AImoveX(modelStack,yellowMove[6],1300,speedAI);
		if (yellowCheck[4]==false) yellowCheck[5]= AIrotate(modelStack,Vector3(-660,0,450),yellowMove[5],'y',180,speedAI*2);  
		if (yellowCheck[3]==false) yellowCheck[4]= AIstop(yellowMove[4],150,speedAI);
		if (yellowCheck[2]==false) yellowCheck[3]= AIstop(yellowMove[3],30,speedAI);
		if (yellowCheck[1]==false) yellowCheck[2]= AImoveX(modelStack,yellowMove[2],-1300,speedAI); 
		if (yellowCheck[0]==false) yellowCheck[1]= AIrotate(modelStack,Vector3(640,0,450),yellowMove[1],'y',-90,speedAI*2); 
		yellowCheck[0] = AImoveZ(modelStack,yellowMove[0],250,speedAI);

	modelStack.Translate(modelYellow.translateVal[0].x,modelYellow.translateVal[0].y,modelYellow.translateVal[0].z);
	modelStack.Rotate(modelYellow.rotateVal[0],modelYellow.rotateAxis[0].x,modelYellow.rotateAxis[0].y,modelYellow.rotateAxis[0].z);
	modelStack.Scale(modelYellow.scaleVal[0].x,modelYellow.scaleVal[0].y,modelYellow.scaleVal[0].z);
	RenderMesh(modelList4[MODEL_BODY_YELLOW], false);

	//left arm
	modelStack.PushMatrix();
	RenderMesh(modelList4[MODEL_LEFTARM_YELLOW], false);

	//left fist
	modelStack.PushMatrix();
	modelStack.Rotate(rotateAngle, 1, 0, 0);
	RenderMesh(modelList4[MODEL_LEFTFIST_YELLOW], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right arm
	modelStack.PushMatrix();
	//modelStack.Rotate(30, 1, 0, 0);
	RenderMesh(modelList4[MODEL_RIGHTARM_YELLOW], false);

	//right fist
	modelStack.PushMatrix();
	modelStack.Rotate(-rotateAngle, 1, 0, 0);
	RenderMesh(modelList4[MODEL_RIGHTFIST_YELLOW], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//left leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList4[MODEL_LEFT_LEG_UPPER_YELLOW], false);

	//left leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(-rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList4[MODEL_LEFT_LEG_LOWER_YELLOW], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//right leg upper
	modelStack.PushMatrix();
	RenderMesh(modelList4[MODEL_RIGHT_LEG_UPPER_YELLOW], false);

	//right leg lower
	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	modelStack.Rotate(rotateAngle + 180, 1, 0, 0);
	RenderMesh(modelList4[MODEL_RIGHT_LEG_LOWER_YELLOW], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();
}
/******************************************************************************/
/*!
\brief
Render  the vehicles and its animations 
/******************************************************************************/
void SceneAssignment::RenderModelVehicles()
{
	//cars, bus and truck
	{
		//glDisable(GL_CULL_FACE);
		modelStack.PushMatrix();
		modelStack.Translate(car1.translateX, 17, 800 + car1.translateZ);
		modelStack.Scale(15, 10, 10);
		modelStack.Rotate(car1.rotateAngle, 0, 1, 0);
		RenderMesh(meshList[GEO_CAR], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(car2.translateX, 17, -1000);
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_CAR2], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(-390, 17, 800);
		modelStack.Scale(15, 10, 10);
		RenderMesh(meshList[GEO_CAR3], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(-car4.translateX, 17, -1120);
		modelStack.Rotate(-90, 0, 1, 0);
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_CAR4], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(700 + truck1.translateX, -12, -1000);
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_TRUCK], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(-bus1.translateX + 900, 0, -1120);
		modelStack.Scale(10, 10, 10);
		RenderMesh(meshList[GEO_BUS], false);
		modelStack.PopMatrix();
	}
}
/******************************************************************************/
/*!
\brief
Render call the render model functions at the top in here like a compile
/******************************************************************************/
void SceneAssignment::RenderModels()
{
	if (loop1 == true)
		speedAI = 5;
	else
		speedAI = 1;

	if (isPaused==true)
		speedAI=0;

	RenderModelPink();
	RenderModelBlue();
	RenderModelOrange();
	RenderModelRed();
	RenderModelYellow();
	RenderModelVehicles();
	
}
/******************************************************************************/
/*!
\brief
Render a function that enable text rendering in the world space
/******************************************************************************/
void SceneAssignment::RenderText(Mesh* mesh, std::string text, Color color)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.5f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}
/******************************************************************************/
/*!
\brief
Render a function that enable text rendering on screen
/******************************************************************************/
void SceneAssignment::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 0.5f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}
/******************************************************************************/
/*!
\brief
Render music for siren and pickup sound
/******************************************************************************/
void SceneAssignment::RenderMusic()
{
	engine2->setRolloffFactor(0.1);

	if (musicAlarm == true)
	{
		engine->stopAllSounds();
		engine2->play3D("../irrKlang/media/siren.wav",vec3df(0,0,0),true);
		engine2->play3D("../irrKlang/media/panic.mp3",vec3df(10,10,10),true);
		musicAlarm = false;
	}
	if (coin == true)
	{
		engine3->play2D("../irrKlang/media/coin.wav",false);
		coin = false;
	}

	if(musicStop == true)
	{
		engine->stopAllSounds();
		engine2->stopAllSounds();
	}
}
/******************************************************************************/
/*!
\brief
Render music for the background
/******************************************************************************/
void SceneAssignment::RenderBGM()
{ 


	engine->setRolloffFactor(0.01); 

	if (musicBGM == true) {
		
		engine->play3D("../irrKlang/media/crowd.wav",vec3df(0,0,0),true); 
		engine->play3D("../irrKlang/media/LifeofRiley.mp3",vec3df(0,0,0),true); 

		musicBGM = false; 
		musicCrowd = false; 
	}  
}
/******************************************************************************/
/*!
\brief
Render music for the games
/******************************************************************************/
void SceneAssignment::RenderMission() 
{
	engine->setAllSoundsPaused(true);
	engine3->setRolloffFactor(0.1); 
	if (Mission == true) 
	{ 
		engine3->play2D("../irrKlang/media/mission.mp3",true); 
		Mission = false; 
	}

}
void SceneAssignment::RenderMission2()
{
	engine->setAllSoundsPaused(true);
	engine4->setRolloffFactor(0.1); 
	if (Mission2 == true) 
	{ 
		engine4->play2D("../irrKlang/media/mission.mp3",true); 
		Mission2 = false; 
	}
}
//update is required for read from text. the code is working.
/******************************************************************************/
/*!
\brief
Render allow read text file
/******************************************************************************/
void SceneAssignment::ReadFromText()
{
	string line;
	ifstream myfile("Text//sample.txt");

	if(myfile.is_open())
	{
		while(getline(myfile, line, ' '))
		{
			std::ostringstream lines;
			lines << '\n' << line;
			modelStack.PushMatrix();
			
			for(int i = 0; i < 2; i++)
			{
				line.clear();
				//RenderTextOnScreen(meshList[GEO_TEXT], lines.str(), Color(0.7, 0, 1), 3, 0, 15);
			}
			modelStack.PopMatrix();	
		}
	}
	myfile.close();
}
/******************************************************************************/
/*!
\brief
Render out all the dailogue boxes adn UI
/******************************************************************************/
void SceneAssignment::RenderQuadOnScreen(Mesh* mesh, float x_size, float y_size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(x_size, y_size, 1);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_UI_ENABLED], 1);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	
	Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	mesh->Render();
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_UI_ENABLED], 0);


	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}
/******************************************************************************/
/*!
\brief
Render  the static NPCs where u can talk to
/******************************************************************************/
void SceneAssignment::RenderStaticAIGlenn()
{
		modelStack.PushMatrix();
		modelStack.Translate(210, 150,-190);
		//modelStack.Rotate(180,0,1,0);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_PINKAI], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(-30, 150, 50);
		//modelStack.Rotate(180,0,1,0);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_REDAI], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(250, 0, 100);
		modelStack.Rotate(90,0,1,0);
		modelStack.Scale(5,5,5);
		RenderMesh(meshList[GEO_YELLOWAI], false);
		modelStack.PopMatrix();

	if(renderai1text == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to talk." , Color(0, 0.7, 1), 4, 6.3, 6);
	}
	if(renderai1text_2 == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "So many to choose from...!" , Color(0, 0.7, 1), 4, 6, 6);
	}

	if(renderai2text == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to talk." , Color(0, 0.7, 1), 4, 6.3, 6);
	}
	if(renderai2text_2 == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "I forgot what I want to buy..." , Color(0, 0.7, 1), 4, 4.5, 6);
	}

	if(renderai3text == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to talk." , Color(0, 0.7, 1), 4, 6.3, 6);
	}
	if(renderai3text_2 == true)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Ice cream should be cheaper." , Color(0, 0.7, 1), 4, 4.5, 6);
	}
}
/******************************************************************************/
/*!
\brief
Render all of our games and a combine of all render fuctions in here
/******************************************************************************/
void SceneAssignment::Render()
{
	// Render VBO here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	viewStack.LoadIdentity();

	//Set view matrix using camera settings
	switch (camType)
	{
	case PLAYER_CAM:
		viewStack.LookAt(
			playerCamera.position.x, playerCamera.position.y, playerCamera.position.z,
			playerCamera.target.x, playerCamera.target.y, playerCamera.target.z,
			playerCamera.up.x, playerCamera.up.y, playerCamera.up.z
			);
		break;
	case NOCLIP_CAM:
		viewStack.LookAt(
			noClipCamera.position.x, noClipCamera.position.y, noClipCamera.position.z,
			noClipCamera.target.x, noClipCamera.target.y, noClipCamera.target.z,
			noClipCamera.up.x, noClipCamera.up.y, noClipCamera.up.z
			);
		break;
	}

	modelStack.LoadIdentity();

	//Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;

	//glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);

	if(lights[0].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[0].position.x, lights[0].position.y, lights[0].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[0].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Elevator
	modelStack.PushMatrix();
	modelStack.Translate(455,eley,1);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(12.5,12,13);
	RenderMesh(meshList[GEO_TENT], false);
	modelStack.PopMatrix();
	//Lift door==================================================================
	modelStack.PushMatrix();
	modelStack.Translate(401,55,LiftDoor);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(115,110,0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();
	//LiftDoor2
	modelStack.PushMatrix();
	modelStack.Translate(401,205,LiftDoor2);
	modelStack.Rotate(270,0,1,0);
	modelStack.Scale(115,110,0);
	RenderMesh(meshList[GEO_DOOR], false);
	modelStack.PopMatrix();

	for(int i = 0;i<firealarm.getTotal();++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(firealarm.translateVal[i].x,firealarm.translateVal[i].y,firealarm.translateVal[i].z);
		modelStack.Rotate(firealarm.rotateVal[i],firealarm.rotateAxis[i].x,firealarm.rotateAxis[i].y,firealarm.rotateAxis[i].z);
		modelStack.Scale(firealarm.scaleVal[i].x,firealarm.scaleVal[i].y,firealarm.scaleVal[i].z);
		RenderMesh(meshList[GEO_ALARM], false);
		modelStack.PopMatrix();
	}


	for(int i = 0;i<light.getTotal();++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(light.translateVal[i].x,light.translateVal[i].y,light.translateVal[i].z);
		modelStack.Rotate(light.rotateVal[i],light.rotateAxis[i].x,light.rotateAxis[i].y,light.rotateAxis[i].z);
		modelStack.Scale(light.scaleVal[i].x,light.scaleVal[i].y,light.scaleVal[i].z);
		RenderMesh(meshList[GEO_SWITCH], false);
		modelStack.PopMatrix();
	}


	RenderLevel2();
	RenderLargeObjects();
	RenderChar();
	RenderModels();
	RenderOut_Skybox();
	RenderRightColumn();
	RenderLeftColumn();
	RenderMiddleColumn();
	RenderSmallObjects();
	RenderLevel1();
	RenderChar();
	RenderStaticAIGlenn();
	// FOR VISUAL DEBUGGING, IGNORE THE DOORMAN
	if (debug == true)
	{
		for (int i = 0; i < ObjectList.size(); ++i)
		{
			for (int j = 0; j < ObjectList[i].collisionPos.size(); ++j)
			{
				modelStack.PushMatrix();
				modelStack.Translate(ObjectList[i].collisionPos[j].x,ObjectList[i].collisionPos[j].y,ObjectList[i].collisionPos[j].z);
				modelStack.Scale(2, 2, 2);
				RenderMesh(meshList[GEO_DOORMAN], false);
				modelStack.PopMatrix();
			}
		}
	}

	if (render1 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp1.translateVal[0].x,PickUp1.translateVal[0].y,PickUp1.translateVal[0].z);
		modelStack.Rotate(PickUp1.rotateVal[0],PickUp1.rotateAxis[0].x,PickUp1.rotateAxis[0].y,PickUp1.rotateAxis[0].z);
		modelStack.Scale(PickUp1.scaleVal[0].x,PickUp1.scaleVal[0].y,PickUp1.scaleVal[0].z);
		RenderMesh(meshList[GEO_PACKET], false);
		modelStack.PopMatrix();
	}

	if (render2 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp2.translateVal[0].x,PickUp2.translateVal[0].y,PickUp2.translateVal[0].z);
		modelStack.Scale(PickUp2.scaleVal[0].x,PickUp2.scaleVal[0].y,PickUp2.scaleVal[0].z);
		RenderMesh(meshList[GEO_COCONUT], false);
		modelStack.PopMatrix();
	}

	if (render3 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp3.translateVal[0].x,PickUp3.translateVal[0].y,PickUp3.translateVal[0].z);
		modelStack.Rotate(PickUp3.rotateVal[0],PickUp3.rotateAxis[0].x,PickUp3.rotateAxis[0].y,PickUp3.rotateAxis[0].z);
		modelStack.Scale(PickUp3.scaleVal[0].x,PickUp3.scaleVal[0].y,PickUp3.scaleVal[0].z);
		RenderMesh(meshList[GEO_ICECREAM], false);
		modelStack.PopMatrix();
	}

	if (render5 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp4.translateVal[0].x,PickUp4.translateVal[0].y,PickUp4.translateVal[0].z);
		modelStack.Scale(PickUp4.scaleVal[0].x,PickUp4.scaleVal[0].y,PickUp4.scaleVal[0].z);
		RenderMesh(meshList[GEO_ORANGE], false);
		modelStack.PopMatrix();
	}

	if (render6 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp5.translateVal[0].x,PickUp5.translateVal[0].y,PickUp5.translateVal[0].z);
		modelStack.Scale(PickUp5.scaleVal[0].x,PickUp5.scaleVal[0].y,PickUp5.scaleVal[0].z);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}

	if (render7 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp6.translateVal[0].x,PickUp6.translateVal[0].y,PickUp6.translateVal[0].z);
		modelStack.Scale(PickUp6.scaleVal[0].x,PickUp6.scaleVal[0].y,PickUp6.scaleVal[0].z);
		RenderMesh(meshList[GEO_BOX1], false);
		modelStack.PopMatrix();
	}

	if (render8 == true) {
		modelStack.PushMatrix();
		modelStack.Translate(PickUp7.translateVal[0].x,PickUp7.translateVal[0].y,PickUp7.translateVal[0].z);
		modelStack.Scale(PickUp7.scaleVal[0].x,PickUp7.scaleVal[0].y,PickUp7.scaleVal[0].z);
		RenderMesh(meshList[GEO_CAN1], false);
		modelStack.PopMatrix();
	}
	if(renderscenerio3text == false)
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to talk." , Color(0, 0.7, 1), 4, 6.3, 6);
	}
	if(congrat == false)
	{
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 80, 120, 0.5, 0.6);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Congratulation!!" , Color(0, 0.7, 1), 6, 3.2, 6.6);
		RenderTextOnScreen(meshList[GEO_TEXT], "Press [E] to continue" , Color(0, 0.7, 1), 4, 5.7, 5.5);
	}


	std::ostringstream ss, ss2, ss3, ss4, ss5, ss6;
	ss << "FPS:" << FPS;
	ss2 << "ET:" << ET;
	ss3 << "X:" << playerCamera.position.x;
	ss4 << "Y:" << playerCamera.position.y;
	ss5 << "Z:" << playerCamera.position.z;
	if(renderscenerio3 == false)
	{
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 80, 100, 0.5, 0.7);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "Instructions." , Color(0, 0.7, 1), 4, 7, 11);
		RenderTextOnScreen(meshList[GEO_TEXT], "1)find the green kid and press [F] catch it" , Color(0, 0.7, 1), 3.5, 1.1, 10.2);
		RenderTextOnScreen(meshList[GEO_TEXT], "press [E] to start game" , Color(0, 0.7, 1), 3.5, 6, 8.2);

	}

	modelStack.PushMatrix();
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0.7, 0, 1), 3, 0.5, 19.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss2.str(), Color(0.7, 0, 1), 3, 0.5, 18.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss3.str(), Color(0.7, 0, 1), 3, 0.5, 2.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss4.str(), Color(0.7, 0, 1), 3, 0.5, 1.5);
	RenderTextOnScreen(meshList[GEO_TEXT], ss5.str(), Color(0.7, 0, 1), 3, 0.5, 0.5);

	if ((Collision(playerCamera.position,ObjectList,5,1)) == 0 && render4 == false && gameEnd == false) { 
		gameStart = true;
		RenderMission();
	}
	if (gameStart == true && gameEnd == false) 
	{
		if (render1 == false && render2 == false && render3 == false && render5 == false && render6 == false && render7 == false && render8 == false)
		{
			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 38, 60, 1.6, 0.5);
			modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Checklist:", Color(0, 1 ,0), 3, 15.3, 5.3);
		}
		else
		{

			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 38, 60, 1.6, 0.5);
			modelStack.PopMatrix();

			RenderTextOnScreen(meshList[GEO_TEXT], "Checklist:", Color(1, 0 ,0), 3, 15.3, 5.3);
		}
		if (render1 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "yaL's", Color(1, 0, 0), 2.5, 25.3, 6.5);
		if (render1 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "yaL's", Color(0, 1, 0), 2.5, 25.3, 6.5);
		if (render2 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "Coconut", Color(1, 0, 0), 2.5, 25.3, 5.5);
		if (render2 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "Coconut", Color(0, 1, 0), 2.5, 25.3, 5.5);
		if (render3 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "Ice cream", Color(1, 0, 0), 2.5, 25.3, 4.5);
		if (render3 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "Ice cream", Color(0, 1, 0), 2.5, 25.3, 4.5);
		if (render5 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "Orange", Color(1, 0, 0), 2.5, 25.3, 3.5);
		if (render5 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "Orange", Color(0, 1, 0), 2.5, 25.3, 3.5);
		if (render6 == true && render7 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "Macaroni x2", Color(1, 0, 0), 2.5, 25.3, 2.5);
		if ( (render6 == false || render7 == false) && (render6 == true || render7 == true) )
			RenderTextOnScreen(meshList[GEO_TEXT], "Macaroni x1", Color(1, 0, 0), 2.5, 25.3, 2.5);
		if (render6 == false && render7 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "Macaroni", Color(0, 1, 0), 2.5, 25.3, 2.5);
		if (render8 == true)
			RenderTextOnScreen(meshList[GEO_TEXT], "Tomato Can", Color(1, 0, 0), 2.5, 25.3, 1.5);
		if (render8 == false)
			RenderTextOnScreen(meshList[GEO_TEXT], "Tomato Can", Color(0, 1, 0), 2.5, 25.3, 1.5);
		modelStack.PopMatrix();

		if (Collision(playerCamera.position,ObjectList,4,28))
		{
			if (render1 == true)
			{
				//template for 'F' function triggers
				modelStack.PushMatrix();
				RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
				modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
		if (Collision(playerCamera.position,ObjectList,2,29))
		{
			if (render2 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
		if (Collision(playerCamera.position,ObjectList,3,4))
		{
			if (render3 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
		if (Collision(playerCamera.position,ObjectList,4,83) ||Collision(playerCamera.position,ObjectList,4,30)  )
		{
			if (render5 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
		if (Collision(playerCamera.position,ObjectList,4,46))
		{
			if (render6 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
		if (Collision(playerCamera.position,ObjectList,4,36))
		{
			if (render7 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}

		if (Collision(playerCamera.position,ObjectList,4,84))
		{
			if (render8 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to pick up the item." , Color(0, 0.7, 1), 4, 3.6, 6);
			}
		}
	}

	if (Collision(playerCamera.position,ObjectList,5,1))
	{
		if (gameStart == false) {

			if (loop1 == true && loop2 == false)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Please make your way out." , Color(1, 0, 0), 4, 3.6, 6);
			}
			else if (render4 == true)
			{
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to start the game." , Color(0, 0.7, 1), 4, 3.7, 6);
			}	

			if (render4 == false)
			{
				//template for 'F' function triggers
				modelStack.PushMatrix();
				RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.57, 1.6);
				modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "Complete the checklist within 80 seconds!" , Color(0, 0.7, 1), 3, 3.7, 12.5);
			}
		}

		else if (gameEnd == false) {
			//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to end the game." , Color(0, 0.7, 1), 4, 3.6, 6);
		}

		else if (gameEnd == true) 
		{

			if (render1 == true || render2 == true || render3 == true || render5 == true || render6 == true || render7 == true || render8 == true || gameTime > 80) 
			{

				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();

				RenderTextOnScreen(meshList[GEO_TEXT], "You lose. Try again next time!" , Color(1, 0.0, 0), 4, 3.6, 6);
				if(musicStop == true){ 
					engine3->stopAllSounds();
					engine3->play2D("../irrKlang/media/fail.wav",false); 
					engine->setAllSoundsPaused(false);
					musicStop = false; 
				} 
			}

			else {
				//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
				RenderTextOnScreen(meshList[GEO_TEXT], "You win. Thanks for playing!" , Color(0, 1, 0), 4, 3.6, 6);
				if(musicStop == true){ 
					engine3->stopAllSounds();
					engine3->play2D("../irrKlang/media/win.wav",false); 
					engine->setAllSoundsPaused(false);
					musicStop = false; 
				} 
			}
		}
	}

	std::ostringstream ss7;
	ss7 << "Time:" << gameTime;
	if(startgame == false)
	{
		ss6 << "Time:" << timer;
	}
	if(startgame ==false)
	{
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 21, 30, 1.8, 2.3);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], ss6.str(), Color(0, 0.7, 1), 3, 10, 19.5);
	}
	if (gameStart == true && gameEnd == false)
	{
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 21, 30, 1.8, 2.3);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], ss7.str(), Color(0, 0.7, 1), 3, 10, 19.5);
	}
	if(playerCamera.position.x >= 350 && playerCamera.position.x <= 400 && ((playerCamera.position.z >= -150)&&(playerCamera.position.z <= -130))&&(playerCamera.position.y <= 50)&&buttonPress3==false) 
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
		RenderTextOnScreen(meshList[GEO_TEXT], "PRESS 'F' TO ACTIVATE ALARM!!!" , Color(1, 0, 0), 4, 3.6, 6); 
	}


	if( playerCamera.position.z >20 && playerCamera.position.z <40 && playerCamera.position.x <-370) 
	{
		//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1);
		modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press 'F' to flick the switch." , Color(1, 0, 0), 4, 3.6, 5); 
	}
		
	RenderBGM();
	RenderMusic();
		

	if(startgame == false)
	{
		if(place1 == false)
		{
			modelStack.PushMatrix();
			modelStack.Translate(342,0,-282);
			modelStack.Rotate(180,0,1,0);
			modelStack.Scale(5,5,5);
			RenderMesh(meshList[GEO_PINKAI], false);
			modelStack.PopMatrix();
		}
		if(place2 == false)
		{
			modelStack.PushMatrix();
			modelStack.Translate(-55,0,418);
			modelStack.Rotate(180,0,1,0);
			modelStack.Scale(5,5,5);
			RenderMesh(meshList[GEO_PINKAI], false);
			modelStack.PopMatrix();
		}
		if(place3 == false)
		{
			modelStack.PushMatrix();
			modelStack.Translate(-33,150,282);
			modelStack.Rotate(180,0,1,0);
			modelStack.Scale(5,5,5);
			RenderMesh(meshList[GEO_PINKAI], false);
			modelStack.PopMatrix();
		}
		if(place4 == false)
		{
			modelStack.PushMatrix();
			modelStack.Translate(-756,0,193);
			modelStack.Rotate(180,0,1,0);
			modelStack.Scale(5,5,5);
			RenderMesh(meshList[GEO_PINKAI], false);
			modelStack.PopMatrix();
		}
		if(place5 == false)
		{
			modelStack.PushMatrix();
			modelStack.Translate(-25,150,159);
			modelStack.Rotate(180,0,1,0);
			modelStack.Scale(5,5,5);
			RenderMesh(meshList[GEO_PINKAI], false);
			modelStack.PopMatrix();
		}
		if(gameover == false)
		{
			//template for 'F' function triggers
			modelStack.PushMatrix();
			RenderQuadOnScreen(meshList[GEO_UI], 50, 40, 0.8, 0.9);
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "GameOver" , Color(0, 0.7, 1), 6, 5.2, 3.8);
			modelStack.PopMatrix();
		}
		//need to add collision detection for this UI to work properly - Glenn
		if(caught == false)
		{
			//template for 'F' function triggers
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 70, 30, 0.6, 1.15);
		modelStack.PopMatrix();
			RenderTextOnScreen(meshList[GEO_TEXT], "Press [F] to catch" , Color(0, 0.7, 1), 4, 5.9, 6);
		}
	}

	if (isPaused == true) {
		modelStack.PushMatrix();
		RenderQuadOnScreen(meshList[GEO_UI], 40, 150,1.05, 0.55);
		modelStack.PopMatrix();
		if (iChoice == 1)
			RenderTextOnScreen(meshList[GEO_TEXT], "Reset" , Color(0, 1, 0), 4, 9.9, 10.2);
		else 
			RenderTextOnScreen(meshList[GEO_TEXT], "Reset" , Color(1, 0, 0), 4, 9.9, 10.2);

		if (iChoice == 2)
			RenderTextOnScreen(meshList[GEO_TEXT], "Exit" , Color(0, 1, 0), 4, 9.9, 8.2);
		else 
			RenderTextOnScreen(meshList[GEO_TEXT], "Exit" , Color(1, 0, 0), 4, 9.9, 8.2);

		if (iChoice == 3)
			RenderTextOnScreen(meshList[GEO_TEXT], "Back" , Color(0, 1, 0), 4, 9.9, 6.2);
		else 
			RenderTextOnScreen(meshList[GEO_TEXT], "Back" , Color(1, 0, 0), 4, 9.9, 6.2);
	}


	int oldChoice = iChoice;

	if (Application::IsKeyPressed(VK_DOWN))
		if (iChoice < 3 ){
			iChoice++;
			Sleep(150);	
		}


		if (Application::IsKeyPressed(VK_UP)) 
			if (iChoice > 1){
				iChoice--;
				Sleep(150);	
			}

		if (Application::IsKeyPressed(VK_RETURN)) {
			if (iChoice == 1) {
				engine->stopAllSounds();
				engine2->stopAllSounds();
				engine3->stopAllSounds();
				engine4->stopAllSounds();
				engine5->stopAllSounds();
				bReset = true;
			}
			if (iChoice == 2) {
				exit(0);
			}
			if (iChoice == 3) {
				isPaused = false;
				engine->setAllSoundsPaused(false);
				engine2->setAllSoundsPaused(false);
				engine3->setAllSoundsPaused(false);
				engine4->setAllSoundsPaused(false);
				engine5->setAllSoundsPaused(false);
			}
		}

}
/******************************************************************************/
/*!
\brief
Render Exit program
/******************************************************************************/
void SceneAssignment::Exit()
{
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}