#pragma once

/**
 * @brief Wrapper to manage windows hooks.
*/
class Hook {
private:
	HHOOK hookHandle;

public:
	Hook(int idHook, HOOKPROC callback);
	Hook(const Hook&) = delete;
	Hook(Hook&&) = delete;
	~Hook();
};