#include "Window.h"

Window* Window::window = nullptr;
Screen* Window::game = nullptr;

Window::Window()
{
	width = 1280;
	height = 720;
	title = "Flappy Bird";
}

Window::~Window()
{
	delete Window::window;
	delete game;
}

Window* Window::get()
{
    if (Window::window == nullptr)
    {
        Window::window = new Window();
    }

    return Window::window;
}

void Window::run()
{
	init();
	loop();

	glfwTerminate();
}

void Window::changeScreen(int screen)
{
	glm::mat4 projection = glm::ortho(-10.f, 10.0f, -5.625f, 5.625f, -1.0f, 1.0f);

	switch (screen) {
	case 0:
		game = new WelcomeScreen();

		for (auto shader : WelcomeScreen::shaders)
		{
			shader.second.use();
			shader.second.setMat4("projection", projection);
			shader.second.setInt("tex", 0);
			shader.second.stop();
		}

		break;
	case 1:
		game = new GameScreen();

		for (auto shader : GameScreen::shaders)
		{
			shader.second.use();
			shader.second.setMat4("projection", projection);
			shader.second.setInt("tex", 0);
			shader.second.stop();
		}

		break;
	}
}

void Window::init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow = glfwCreateWindow(width, height, "Flappy Bird", NULL, NULL);
	if (glfwWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	glfwSetKeyCallback(glfwWindow, KeyListener::keyCallback);
	glfwSetFramebufferSizeCallback(glfwWindow, framebuffer_size_callback);
	glfwMakeContextCurrent(glfwWindow);
	glfwShowWindow(glfwWindow);
	

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

	glActiveTexture(GL_TEXTURE0);

	changeScreen(0);

	Random::initialize();
}

void Window::loop()
{
	// Do obliczania delata time
	auto lastTime = std::chrono::steady_clock::now();
	double ns = 1000000000.0 / 60.0;
	double deltaTime = 0.0;

	while (!glfwWindowShouldClose(glfwWindow))
	{
		if (KeyListener::isKeyPressed(GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(glfwWindow, true);
		}

		auto now = std::chrono::steady_clock::now();
		deltaTime += (now - lastTime).count() / ns;
		lastTime = now;
		if (deltaTime >= 1.0)
		{
			glfwPollEvents();
			game->update();
			deltaTime--;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		game->render();
		int i;
		if ((i = glGetError()) != GL_NO_ERROR)
		{
			std::cout << i << std::endl;
		}

		glfwSwapBuffers(glfwWindow);
	}
}