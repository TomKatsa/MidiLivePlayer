#include <Windows.h>
#include <stdexcept>
#include "debugprint.h"
#include "hook.h"

Hook::Hook(int idHook, HOOKPROC callback) : hookHandle(nullptr) {
	hookHandle = SetWindowsHookEx(idHook, callback, nullptr, 0);

	if (hookHandle == nullptr) {
		throw std::runtime_error("Hook set failed");
	}

	LOG("Installed hook " << hookHandle << std::endl);
}

Hook::~Hook() {
	if (!UnhookWindowsHookEx(hookHandle)) {
		LOG("Failed to unhook" << std::endl);
	}
}
