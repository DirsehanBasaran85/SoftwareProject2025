#pragma once

class Application {

public:
	
	Application();

	void shutdown();
	bool isRunning();

private:

	bool running;


};