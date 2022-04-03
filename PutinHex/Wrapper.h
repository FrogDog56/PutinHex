#pragma once

#include "Main.h"

jobject getMinecraft();
jobject getPlayer();
void setSprinting(jboolean);
void sendChatMessage(jstring message);
bool isOnGround();
void playerJump(bool);

