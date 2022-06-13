//
// Copyright (c) 2013 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#include <stdio.h>
#ifdef NANOVG_GLEW
#	include <GL/glew.h>
#endif
#ifdef __APPLE__
#	define GLFW_INCLUDE_GLCOREARB
#endif
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"
#include "demo.h"
#include "perf.h"

#ifndef NANOVG_EXAMPLE_FOLDER 
	#define NANOVG_EXAMPLE_FOLDER "../example/"
#endif	 

void errorcb(int error, const char* desc)
{
	printf("GLFW error %d: %s\n", error, desc);
}

int blowup = 0;
int screenshot = 0;
int premult = 0;

static void key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	NVG_NOTUSED(scancode);
	NVG_NOTUSED(mods);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		blowup = !blowup;
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
		screenshot = 1;
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		premult = !premult;
}

int image0=0;
	int imgw=0;
	int imgh=0;

void renderDemoX(NVGcontext* vg, float mx, float my, float width, float height,
				float t, int blowup, DemoData* data)
{

	// nvgStrokeColor(vg, nvgRGBA(0,0,0,32));
	// nvgStroke(vg);
	// return;



	//if(2<1)
	{
		nvgSave(vg);
		//nvgScissor(vg, 0,0,200,200);


		NVGpaint imgPaint = nvgImagePattern(vg, imgw, imgw, imgw,imgh, 0, image0, 1);
		nvgFillPaint(vg, imgPaint);
		//nvgRotate(vg,45);
		//nvgTranslate(vg, 0, 100);
		nvgXYUV_ADD(vg);

		nvgRestore(vg);


		return;
	}



	//if(2<1)
	{
		nvgFontFace(vg, "sans");

		nvgFontSize(vg, 112.0f);
		nvgTextAlign(vg, NVG_ALIGN_LEFT|NVG_ALIGN_TOP);
		nvgFillColor(vg, nvgRGBA(240,240,240,192));
  	    nvgText(vg, width/2,height/2, "title", NULL);
  		return;
	}

	if(2<1)
	{
		NVGpaint imgPaint = nvgImagePattern(vg, imgw, imgw, imgw,imgh, 0, image0, 1);

		nvgBeginPath(vg);

	// 	//nvgRect(vg, 0,0, width/2 ,height/2);

	// 	// nvgMoveTo(vg,100+200,100); // top left corner
	// 	// 	nvgLineTo(vg,400+200,100); // top right corner: 100 (x) + 300 (w), y remains
	// 	// 	nvgLineTo(vg,400+200,250); // bottom left corner: x remains, 100 (y) + 150 (h)
	// 	// nvgLineTo(vg,100+200,250); // bottom left corner: x remains, 100 (y) + 150 (h)
	// 	// nvgLineTo(vg,100+200-200,(250+100)/2); // bottom left corner: x remains, 100 (y) + 150 (h)
	// 	// nvgLineTo(vg,100+200,100); // back to top left

		nvgXYUVMoveTo(vg,100,100,   0,0); 
		nvgXYUV(vg,100,200, 0, 1);
		// 
		nvgXYUV(vg,200,100, 0.5, 0);
		nvgXYUV(vg,200,200, 0.5, 1);

		nvgXYUV(vg,300,100, 1, 0);
		nvgXYUV(vg,300,200, 1, 1);


		nvgFillPaint(vg, imgPaint);
	 	nvgFill(vg);
		nvgClosePath(vg);		
      return;
	}
	if (2<1)
	{
	    NVGpaint imgPaint = nvgImagePattern(vg, imgw, imgw, imgw,imgh, 0, image0, 1);

		nvgBeginPath(vg);

		//nvgMoveTo(vg,100+200,100); // top left corner
		nvgXYUVMoveTo(vg,100+200,100,1,1);
		//nvgLineTo(vg,400+200,100); // top right corner: 100 (x) + 300 (w), y remains
		nvgXYUV(vg,400+200,100,1,1);
		
		//nvgLineTo(vg,400+200,250); // bottom left corner: x remains, 100 (y) + 150 (h)
		nvgXYUV(vg,100+200,250,1,1); // bottom left corner: x remains, 100 (y) + 150 (h)
		nvgXYUV(vg,100+200,100,1,1); // back to top left

		nvgXYUV(vg,100+600,100,1,1); // top left corner
		nvgXYUV(vg,400+600,100,1,1); // top right corner: 100 (x) + 300 (w), y remains
		nvgXYUV(vg,400+600,250,1,1); // bottom left corner: x remains, 100 (y) + 150 (h)
		nvgXYUV(vg,100+600,250,1,1); // bottom left corner: x remains, 100 (y) + 150 (h)
		nvgXYUV(vg,100+600,100,1,1); // back to top left


		nvgFillColor(vg,nvgRGBA(255, 0, 255, 127));
		nvgFillPaint(vg, imgPaint);
		nvgFill(vg);

		nvgClosePath(vg);
	}
    return;
	nvgFontSize(vg, 15.0f);
	nvgFontFace(vg, "sans");
	nvgFillColor(vg, nvgRGBA(255,255,255,128));

	nvgTextAlign(vg,NVG_ALIGN_LEFT|NVG_ALIGN_MIDDLE);
	nvgText(vg, 100,100,"text", NULL);



nvgBeginPath(vg);
nvgRect(vg, 100,100, 120,30);
nvgCircle(vg, 120,120, 50);
nvgPathWinding(vg, NVG_HOLE);	// Mark circle as a hole.
nvgFillColor(vg, nvgRGBA(255,192,0,255));
nvgFill(vg);

nvgBeginPath(vg);
nvgRect(vg, 200,200, 120,30);
nvgFillColor(vg, nvgRGBA(255,192,123,255));
nvgFill(vg);

//https://openplanet.dev/docs/tutorials/nanovg-introduction

    nvgBeginPath(vg);
    nvgRect(vg,100, 100, 300, 150);
    nvgFillColor(vg,nvgRGBA(255, 0, 0, 128));
    nvgFill(vg);
    nvgClosePath(vg);

    nvgBeginPath(vg);
    nvgRoundedRect(vg,400, 400, 300, 150,32);
    nvgFillColor(vg,nvgRGBA(255, 0, 0, 128));
    nvgFill(vg);
    nvgClosePath(vg);

    nvgBeginPath(vg);

    // start point: (100, 100)
    nvgMoveTo(vg,100, 100); 

    // control point: (200, 400), end point: (300, 100)
    nvgQuadTo(vg,200, 400, 300, 100); 

    nvgStrokeColor(vg,nvgRGBA(255, 127, 0, 127));
    nvgStrokeWidth(vg,5.5); 
	nvgStroke(vg);

    nvgClosePath(vg);	

}


int main()
{
	GLFWwindow* window;
	DemoData data;
	NVGcontext* vg = NULL;
	GPUtimer gpuTimer;
	PerfGraph fps, cpuGraph, gpuGraph;
	double prevt = 0, cpuTime = 0;

	if (!glfwInit()) {
		printf("Failed to init GLFW.");
		return -1;
	}

	initGraph(&fps, GRAPH_RENDER_FPS, "Frame Time");
	initGraph(&cpuGraph, GRAPH_RENDER_MS, "CPU Time");
	initGraph(&gpuGraph, GRAPH_RENDER_MS, "GPU Time");

	glfwSetErrorCallback(errorcb);
#ifndef _WIN32 // don't require this on win32, and works with more cards
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

#ifdef DEMO_MSAA
	glfwWindowHint(GLFW_SAMPLES, 4);
#endif
	window = glfwCreateWindow(1000, 600, "NanoVG", NULL, NULL);
//	window = glfwCreateWindow(1000, 600, "NanoVG", glfwGetPrimaryMonitor(), NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key);

	glfwMakeContextCurrent(window);
#ifdef NANOVG_GLEW
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		printf("Could not init glew.\n");
		return -1;
	}
	// GLEW generates GL error because it calls glGetString(GL_EXTENSIONS), we'll consume it here.
	glGetError();
#endif

#ifdef DEMO_MSAA
	vg = nvgCreateGL3(NVG_STENCIL_STROKES | NVG_DEBUG);
#else
	vg = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
#endif
	if (vg == NULL) {
		printf("Could not init nanovg.\n");
		return -1;
	}

	if (loadDemoData(vg, &data) == -1)
		return -1;

	glfwSwapInterval(0);

	initGPUTimer(&gpuTimer);

	glfwSetTime(0);
	prevt = glfwGetTime();

	image0 = nvgCreateImage(vg, NANOVG_EXAMPLE_FOLDER "images/image1.jpg", 0);
	nvgImageSize(vg, image0, &imgw, &imgh);

	while (!glfwWindowShouldClose(window))
	{
		double mx, my, t, dt;
		int winWidth, winHeight;
		int fbWidth, fbHeight;
		float pxRatio;
		float gpuTimes[3];
		int i, n;

		t = glfwGetTime();
		dt = t - prevt;
		prevt = t;

		startGPUTimer(&gpuTimer);

		glfwGetCursorPos(window, &mx, &my);
		glfwGetWindowSize(window, &winWidth, &winHeight);
		glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
		// Calculate pixel ration for hi-dpi devices.
		pxRatio = (float)fbWidth / (float)winWidth;

		// Update and render
		glViewport(0, 0, fbWidth, fbHeight);
		if (premult)
			glClearColor(0,0,0,0);
		else
			glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

		nvgBeginFrame(vg, winWidth, winHeight, pxRatio);

		renderDemoX(vg, mx,my, winWidth,winHeight, t, blowup, &data);
		//renderDemo(vg, mx,my, winWidth,winHeight, t, blowup, &data);

		// renderGraph(vg, 5,5, &fps);
		// renderGraph(vg, 5+200+5,5, &cpuGraph);
		// if (gpuTimer.supported)
		// 	renderGraph(vg, 5+200+5+200+5,5, &gpuGraph);

		nvgEndFrame(vg);

		// Measure the CPU time taken excluding swap buffers (as the swap may wait for GPU)
		cpuTime = glfwGetTime() - t;

		updateGraph(&fps, dt);
		updateGraph(&cpuGraph, cpuTime);

		// We may get multiple results.
		n = stopGPUTimer(&gpuTimer, gpuTimes, 3);
		for (i = 0; i < n; i++)
			updateGraph(&gpuGraph, gpuTimes[i]);

		if (screenshot) {
			screenshot = 0;
			saveScreenShot(fbWidth, fbHeight, premult, "dump.png");
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	freeDemoData(vg, &data);

	nvgDeleteGL3(vg);

	printf("Average Frame Time: %.2f ms\n", getGraphAverage(&fps) * 1000.0f);
	printf("          CPU Time: %.2f ms\n", getGraphAverage(&cpuGraph) * 1000.0f);
	printf("          GPU Time: %.2f ms\n", getGraphAverage(&gpuGraph) * 1000.0f);

	glfwTerminate();
	return 0;
}