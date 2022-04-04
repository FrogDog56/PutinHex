#include "wrapper.h"

jobject getMinecraft()
{
	jclass minecraftClass = mc.env->FindClass("ave");
	jmethodID findMinecraft = mc.env->GetStaticMethodID(minecraftClass, "A", "()Lave;");
	return mc.env->CallStaticObjectMethod(minecraftClass, findMinecraft);
}

jobject getPlayer()
{
	jfieldID getPlayer = mc.env->GetFieldID(mc.env->GetObjectClass(getMinecraft()), "h", "Lbew;");
	return mc.env->GetObjectField(getMinecraft(), getPlayer);
}

bool isOnGround()
{
	jfieldID onGroundField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "C", "Z");
	jboolean onGround = mc.env->GetBooleanField(getPlayer(), onGroundField);
	return onGround ? false : true;
}

double getPosX()
{
	jfieldID posXField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "s", "D");
	jdouble posX = mc.env->GetDoubleField(getPlayer(), posXField);
	return posX;
}

double getPosY()
{
	jfieldID posYField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "t", "D");
	jdouble posY = mc.env->GetDoubleField(getPlayer(), posYField);
	return posY;
}

double getPosZ()
{
	jfieldID posZField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "u", "D");
	jdouble posZ = mc.env->GetDoubleField(getPlayer(), posZField);
	return posZ;
}

void setSprinting(jboolean sprinting)
{
	jmethodID setSprinting = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "d", "(Z)V");
	mc.env->CallBooleanMethod(getPlayer(), setSprinting, sprinting);
}

void sendChatMessage(jstring message)
{
	jmethodID sendChatMessage = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "e", "(Ljava/lang/String;)V");
	mc.env->CallVoidMethod(getPlayer(), sendChatMessage, message);
}

void playerJump()
{
	jmethodID jumpMethod = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "bF", "()V");
	mc.env->CallVoidMethod(getPlayer(), jumpMethod);
}
