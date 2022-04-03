#pragma once

#include "Main.h"

jobject getMinecraft();
jobject getPlayer();

bool isOnGround();

void setSprinting(jboolean);
void sendChatMessage(jstring message);
void playerJump(bool);

