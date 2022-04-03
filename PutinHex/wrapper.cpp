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

bool isOnGround() 
{
	jfieldID onGroundField = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "C", "Z");
	jboolean onGround = mc.env->GetBooleanField(getPlayer(), onGroundField);
	return onGround ? false : true;
}

void playerJump(bool checkGround) 
{
	jmethodID jumpMethod = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "bF", "()V");
	if (checkGround && !isOnGround())
		return;
	mc.env->CallVoidMethod(getPlayer(), jumpMethod);
}
