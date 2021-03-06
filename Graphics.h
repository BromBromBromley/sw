#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "sw.h"

namespace SouthwestEngine {
	class RenderLayer;
	class Compositor;

	class Graphics {
	private:
		Graphics(); // instance this class and i will start crying

		// compositor, stacks render layers together
		static Compositor* Compositor_;
	public:
		// SDL window pointer
		static SDL_Window* SDL_Window;
		// SDL OpenGLContext pointer
		static SDL_GLContext SDL_GLContext;

		// Time passed since previous frame in milliseconds
		// Use this to make sure the game speed is not tied to the frame rate
		static Uint32 DeltaTime;

		// initalize graphics
		// return 0 on success, 1 on failure
		static int Initialize(const char* wintitle);

		// draw the next frame
		static void Update();

		// stop graphics engine
		static void Stop();

		// ortho projection matrix for sprites
		static glm::mat4 OrthoProjection;

		// GLSL Header to maintain compatibility with old (<3.0) GLSL versions as well as GL|ES
		static std::string GLSLHeader;

		// list of render layers
		static std::vector<RenderLayer*> RenderLayers;
	};
}

#endif