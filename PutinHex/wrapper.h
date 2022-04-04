#pragma once

#include "Main.h"

jobject getMinecraft();
jobject getPlayer();

bool isOnGround();
double getPosX();
double getPosY();
double getPosZ();

void setSprinting(jboolean);
void sendChatMessage(jstring message);
void playerJump();

