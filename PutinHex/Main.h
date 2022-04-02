#pragma once
#include <windows.h>
#include <iostream>
#include <string.h>

#include "JNI/jni.h"

class Main
{
	public:
		JavaVM* vm;
		JNIEnv* env;
		JavaVMInitArgs vm_args;
} mc;

void run();

jobject getMinecraft();
jobject getPlayer();
jboolean isServerWorld();
void setSprinting(jboolean sprinting);
void sendChatMessage(jstring message);

