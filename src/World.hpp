#ifndef WORLD_HPP
#define WORLD_HPP

#include "Object.hpp"

#include "OpenGL.hpp"

#include <set>

/**
 * Ensemble of Object; main entry point
 */
class World {
public:
	/**
	 * Construct a World with the given name; start every libraries
	 *
	 * @param name name of the windows to create
	 */
	World(std::string const name);

	/**
	 * Destructor which clean started libraries
	 */
	~World();

	/**
	 * Add a new Object to draw
	 *
	 * @param obj Object to add to the set of object to draw
	 */
	void add_object(Object obj);

	/**
	 * Begin the main loop to handle event
	 */
	void main_loop();

private:
	/**
	 * Set of Object to draw
	 */
	std::set<Object> objects;

	/**
	 * The windows we created
	 */
	GLFWwindow *window;

	/**
	 * Draw all the Objects
	 */
	void draw() const;

	/**
	 * React to a keydown
	 *
	 * @param window window that received the event
	 * @param key keyboard key pressed or released
	 * @param scancode scancode key
	 * @param action GLFW_PRESS, GLFW_RELEASE, GLFW_REPEAT
	 * @param mods bit field with modifier keys set
	 */
	static void key_callback(GLFWwindow* window,
				 int key, int scancode, int action, int mods);

	/**
	 * React to an error
	 *
	 * @param error error code from GLFW
	 * @param description description of the error
	 */
	static void error_callback(int error, const char* description);

};

#endif
