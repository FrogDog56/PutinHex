#include "Main.h"

void run()
{
	boolean run = true;

	while (run)
	{
		sendChatMessage(mc.env->NewStringUTF("heck"));
		setSprinting(true);

		if (GetKeyState(VK_END))
		{
			break;
		}

		Sleep(10);
	}
}

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

jboolean isServerWorld()
{
	jfieldID isServerWorld = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "bM", "()Z");
	return mc.env->GetBooleanField(getPlayer(), isServerWorld);
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
