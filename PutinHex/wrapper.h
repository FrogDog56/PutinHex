#pragma once

#include "Main.h"

jobject getMinecraft();
jobject getPlayer();
jobject getWorld();
jobject getGameSettings();
jobject getRenderManager();

bool isOnGround();
double getPosX();
double getPosY();
double getPosZ();
float getYaw();
float getPitch();

void setPitch(jfloat value);
void setYaw(jfloat value);
void setSprinting(jboolean);
void sendChatMessage(jstring message);
void playerJump();
void setGammaSetting(jfloat value);
void setRightClickDelayTimer(jint value);
void setTimer(jfloat value); //broken
void logout(); //test on mp

